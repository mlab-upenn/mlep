function [eplus_in_curr,userdata] = controlFile(cmd,eplus_out_prev, eplus_in_prev, time, stepNumber, userdata)
% ---------------FUNCTION INPUTS---------------

% INPUTS TO ENERGYPLUS
% eplus_in_prev - Data Structure with all previous inputs
% 	eplus_in_curr.Troom = ;

% OUTPUTS FROM ENERGYPLUS
% eplus_out_prev - Data Structure with all previous outpus
% 	eplus_out_curr.Tout = ;

% OTHER INPUTS
% cmd  - MLE+ Command to distinguish init or normal step
% userdata  - user defined variable which can be changed and evolved
% time - vector with timesteps
% stepNumber - Number of Time Step in the simulation (Starts at 1)

% ---------------FUNCTION OUTPUTS---------------
% eplus_in_curr - vector with the values of the input parameters.
% This should be a 1xn vector where n is number of eplus_in parameters
% userdata - user defined variable which can be changed and evolved

if strcmp(cmd,'init')
    % ---------------WRITE YOUR CODE---------------
    % Initialization mode. This part sets the
    % input parameters for the first time step.
    eplus_in_curr.CoolTemp = 26.7;
    eplus_in_curr.HeatTemp = 15.6;
    eplus_in_curr.SatTemp = 12.8;
    eplus_in_curr.ChWTemp = 6.7;
    eplus_in_curr.LightSch = 0.05;
    
elseif strcmp(cmd,'normal')
    % ---------------WRITE YOUR CODE---------------
    % Normal mode. This part sets the input
    % parameters for the subsequent time steps.
    
    timeDay = rem(time(end),24*60*60)/60/60;
    
    % Cool
    if timeDay < 6
        coolSP = 26.7;
    elseif timeDay < 22
        coolSP = 24.0;
    else
        coolSP = 26.7;
    end
    
    % Heat
    if timeDay < 6
        heatSP = 15.6;
    elseif timeDay < 22
        heatSP = 21.0;
    else
        heatSP = 15.6;
    end
    
    % Office 1
    RoomCoolSch = coolSP;
    RoomHeatSch = heatSP;
    SatSch = 12.8;
    
    % Chiller
    if timeDay < 6
        ChWTempControl = 6.7;
    elseif timeDay < 12
        ChWTempControl = 6.7;
    elseif timeDay < 13
        ChWTempControl = 6.7;
    else
        ChWTempControl = 6.7;
    end
    
    % Light Schedule
    if timeDay < 5
        BldLightSch = 0.05;
    elseif timeDay < 7
        BldLightSch = 0.1;
    elseif timeDay < 8
        BldLightSch = 0.3;
    elseif timeDay < 17
        BldLightSch = 0.9;
    elseif timeDay < 18
        BldLightSch = 0.7;
    elseif timeDay < 20
        BldLightSch = 0.5;
    elseif timeDay < 22
        BldLightSch = 0.3;
    elseif timeDay < 23
        BldLightSch = 0.1;
    else
        BldLightSch = 0.05;
    end
    
    % Reduction
    % if time >= 12 && time <= 12
    %     ChWTempControl1 = ChWTempControl1;
    % end
    
    eplus_in_curr.CoolTemp = RoomCoolSch;
    eplus_in_curr.HeatTemp = RoomHeatSch;
    eplus_in_curr.SatTemp = SatSch;
    eplus_in_curr.ChWTemp = ChWTempControl;
    eplus_in_curr.LightSch = BldLightSch;
end
end
