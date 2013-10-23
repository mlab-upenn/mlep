function [result] = mlepRunTemplate(projectPath, idfFullPath, Weather, controlFileName, timeStep, runPeriod, inputs, outputs, acceptTimeOut, userData)
% [result] = mlepRunSimulation(handles.DATA.projectPath, handles.DATA.idfFullPath, handles.DATA.Weather, handles.DATA.ControlFileName);

% See also: OTHER_FUNCTIONNAME1,  OTHER_FUNCTIONNAME2

% Author: WILLY BERNAL
% UNIVERSITY OF PENNSYLVANIA
% email address: willyg@seas.upenn.edu
% Website: http://mlab.seas.upenn.edu/
% May 2013; 

%------------- BEGIN CODE --------------

%% Create a mlepProcess instance and configure it
ep = mlepProcess; 

% Get IDF names and paths
[idfPath, idfName, idfExtension] = fileparts(idfFullPath);
[weatherPath, weatherName, weatherExtension] = fileparts(Weather);

% Change to Project Path
cd(projectPath);
ep.arguments = {idfName, weatherName};

% Set Time Out
ep.acceptTimeout = AcceptTimeOut; %800000
VERNUMBER = 2;  % version number of communication protocol (2 for >= E+ 6.0.0)

%% Start EnergyPlus cosimulation
[status, msg] = ep.start;
if status ~= 0
    error('Could not start EnergyPlus: %s.', msg);
end

% Create Time Variables
deltaT = 60*TimeStep;   % turn it into seconds
kStep = 1;  % current simulation step
MAXSTEPS = (RunPeriod+1)*24*60/TimeStep;  % max simulation time = 4 days

% Log Inputs and Outputs
numOutputs = size(Outputs,1);
numInputs = size(Inputs,1);
logOut = zeros(MAXSTEPS, numOutputs);
logIn = zeros(MAXSTEPS, numInputs);

%% Iterate 
cmd = 'init';
while kStep <= MAXSTEPS
    % Read a data packet from E+
    packet = ep.read;
    if isempty(packet)
        error('Could not read outputs from E+.');
    end
     
    % Parse it to obtain building outputs
    [flag, eptime, outputs] = mlepDecodePacket(packet);
    if flag ~= 0
        %flag
        break;
    end
    
    % Output
    if numOutputs
        % Save to logdata
        logOut(kStep, :) = outputs;
        for i = 1:numOutputs
            outVector.(mlep.data.outputTableData{i,end})(kStep) = outputs(i);
        end
    end
     
    % Define Previous Output Variables
    if size(mlep.data.outputTableData,1)
        for i = 1:size(mlep.data.outputTableData,1)
            mlepOut.(mlep.data.outputTableData{i,end}) = mlepOutputVector.(mlep.data.outputTableData{i,end})(1:kStep);
        end
    else
        % No Outputs Specified    
        mlepOut  = struct();
    end
    
    % Obtain Input Values from Control File (SIM vs. SYSID)
    if (mlep.data.sysID == 1)
        [inputStruct, mlep] = feval(mlep.data.funcHandle,cmd,mlepOut, mlepIn, time(1:kStep), kStep, mlep); % NEED TO CHANGE,eplusOutPrev, eplusInPrev, time, userdata
        cmd = 'normal';
    else 
        try
        [inputStruct, mlep.data.userdata] = feval(mlep.data.funcHandle, cmd, mlepOut, mlepIn, time(1:kStep), kStep, mlep.data.userdata); %.data.userdata NEED TO CHANGE,eplusOutPrev, eplusInPrev, time, userdata
        catch err
            if (strcmp(err.identifier,'MATLAB:unassignedOutputs'))
                if isempty(mlep.data.inputTableData)
                    mlep.data.noInput = 1;
                    inputs = ones(1,0);
                end
            else
                rethrow(err);
            end
        end
        cmd = 'normal';
    end
    
    %% INPUTS EXIST
    if ~mlep.data.noInput
        % Set input in struct
        [inputs, mlep] = setInput2vector(mlep,inputStruct);
        if (mlep.data.stopSimulation)
            return;
        end
        
        % Define Previous Input Variables
        if size(mlep.data.inputTableData,1)
            for i = 1:size(mlep.data.inputTableData,1)
                mlepInputVector.(mlep.data.inputTableData{i,end})(kStep) = inputs(i);
                mlepIn.(mlep.data.inputTableData{i,end}) =  mlepInputVector.(mlep.data.inputTableData{i,end})(1:kStep);
            end
        else
            % No inputs Specified
            mlepIn = struct();
        end
       
    end
    ep.write(mlepEncodeRealData(VERNUMBER, 0, (kStep-1)*deltaT, inputs));
    % Save to loginput
    loginput(kStep, :) = inputs;

    
    kStep = kStep + 1;
end

% Stop EnergyPlus
ep.stop;

% Remove unused entries in logdata
kStep = kStep - 1;
if kStep < MAXSTEPS
    logOut((kStep+1):end,:) = [];
    logIn((kStep+1):end,:) = [];
end

% Time 
time = 0:(kStep-1)'*deltaT/3600;

% Set Inputs & Outputs
result.time = time;
result.Input = logIn;
result.Output = logOut;
end

