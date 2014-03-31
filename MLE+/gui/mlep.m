function varargout = mlep(varargin)
% MLEP MATLAB code for mlep.fig
%      MLEP, by itself, creates a new MLEP or raises the existing
%      singleton*.
%
%      H = MLEP returns the handle to a new MLEP or the handle to
%      the existing singleton*.
%
%      MLEP('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in MLEP.M with the given input arguments.
%
%      MLEP('Property','Value',...) creates a new MLEP or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before mlep_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to mlep_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help mlep

% Last Modified by GUIDE v2.5 28-Mar-2014 18:32:23

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
    'gui_Singleton',  gui_Singleton, ...
    'gui_OpeningFcn', @mlep_OpeningFcn, ...
    'gui_OutputFcn',  @mlep_OutputFcn, ...
    'gui_LayoutFcn',  [] , ...
    'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before mlep is made visible.
function mlep_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to mlep (see VARARGIN)

% Data
handles.DATA = struct;

% Version
handles.DATA.version1 = 2;
handles.DATA.version2 = 0;

% Get Path to MLE+ Folder
temp = mfilename('fullpath');
[dirPath, ~, ~] = fileparts(temp);
handles.mlep_home = [dirPath filesep '..'];

% Get MLEP Settings
temp = load([handles.mlep_home filesep 'MLEPSETTINGS.mat']);
handles.DATA.MLEPSETTINGS = temp.MLEPSETTINGS;
handles.eplusDir = handles.DATA.MLEPSETTINGS.eplusDir;
handles.javaDir = handles.DATA.MLEPSETTINGS.javaDir;

% Tab Handles
handles.tabHandles = [handles.Start_PanelMain
    handles.SystemID_PanelMain
    handles.Control_PanelMain
    handles.Simulation_PanelMain
    handles.Start
    handles.SystemID
    handles.Control
    handles.Simulation]';
% Select Start Tab
tabHandler(handles.tabHandles,1);

% Tab Handles Sys ID
handles.tabHandlesSysID = [handles.uipanel29
    handles.uipanel30
    handles.pushbutton48
    handles.pushbutton49]';
% Select Start Tab
tabHandlerSysID(handles.tabHandlesSysID,1);
set(handles.pushbutton48, 'Background', 'g');

% Load Workflow Image
[ima, map] = imread([handles.mlep_home filesep 'gui' filesep 'figs' filesep 'workflow.png']);

handles.DATA.variableInput = {};
handles.DATA.variableOutput = {};

% Resize
if exist('imresize')
    ima = imresize(ima, 0.54);
else
    ima = imageresize(ima, 0.54, 0.54);
end

% Display Image
set(handles.Start_Diagram, 'CDATA', ima);

% Choose default command line output for mlep
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes mlep wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = mlep_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in Start.
function Start_Callback(hObject, eventdata, handles)
% hObject    handle to Start (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tabHandler(handles.tabHandles,1);

% --- Executes on button press in SystemID.
function SystemID_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tabHandler(handles.tabHandles,2);

% --- Executes on button press in Control.
function Control_Callback(hObject, eventdata, handles)
% hObject    handle to Control (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tabHandler(handles.tabHandles,3);

% --- Executes on button press in Simulation.
function Simulation_Callback(hObject, eventdata, handles)
% hObject    handle to Simulation (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
tabHandler(handles.tabHandles,4);

% --- Executes on button press in Settings_Load.
function Settings_Load_Callback(hObject, eventdata, handles)
% hObject    handle to Settings_Load (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Select Project.prj file
[FileName,PathName] = uigetfile('*.prj','Select project file (.prj)' );

% If not picked any File
if (~ischar(FileName) || ~ischar(PathName))
    return;
else
    % Load Project.prj
    DATA = importdata([PathName FileName]);
    handles.DATA = DATA;

    % Set Project Path
    handles.DATA.projectPath = [PathName];
    % Set IDF Full Path
    if isfield(handles.DATA,'idfFile')
        handles.DATA.idfFullPath = [PathName handles.DATA.idfFile];
    end
    % Set Control Full Path
    if isfield(handles.DATA,'ControlFileName')
        handles.DATA.ControlFullPath = [PathName handles.DATA.ControlFileName];
        handles.DATA.ControlFileDir = PathName;
    end
    % SEet Control File Dir
    
    % CD to Project Path
    cd (handles.DATA.projectPath);
    % Update project Path
    %[mlep] = updateProjectPath(mlep);
    
    % Upload Variables Data
    if isfield(handles.DATA,'variableData')
        set(handles.Control_InputListbox, 'UserData',handles.DATA.variableData)
    end
    
    % Callback for Writing cfg file
    if isfield(handles.DATA,'variableInput') && isfield(handles.DATA,'variableOutput')
        % create variable.cfg
        result = writeConfigFile(handles.DATA.variableInput,handles.DATA.variableOutput,handles.DATA.projectPath);
    end
    
    % Update presentation tab
    [handles] = mlepUpdateStartTab(handles);
    % Update system ID  tab
    [handles] = mlepUpdateSysIDTab(handles);
    % Update variable tab
    [handles] = mlepUpdateVariableTab(handles);
    % Update control tab
    [handles] = mlepUpdateControlTab(handles);
    % Update simulate tab
    [handles] = mlepUpdateSimulateTab(handles);
end

%% INITIALIZE NECESSARY VARIABLES
% mlepInit;
% mlep.data.MLEPSETTINGS = MLEPSETTINGS;
% mlep.data.MLEPSETTINGS = MLEPSETTINGS;
% mlep.data.MLEPSETTINGS.path = mlep.data.MLEPSETTINGS.env;

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Settings_Clear.
function Settings_Clear_Callback(hObject, eventdata, handles)
% hObject    handle to Settings_Clear (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% clearProject
clearProject(handles);

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Settings_Save.
function Settings_Save_Callback(hObject, eventdata, handles)
% hObject    handle to Settings_Save (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
DATA = handles.DATA;
% Select where to store and name file
if isfield(handles.DATA, 'projectPath')
    temp = handles.DATA.projectPath;
else
    temp = '.';
end
[FileName,PathName] = uiputfile('mlepProject.prj','Save file name',[temp]);
% If no File Picked
if (~ischar(FileName) || ~ischar(PathName))
    return;
else
    save([PathName FileName], 'DATA');
    disp(['Saved Project File ' PathName FileName] );
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Settings_Exit.
function Settings_Exit_Callback(hObject, eventdata, handles)
% hObject    handle to Settings_Exit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
delete(handles.figure1);

% --- Executes on button press in Settings_Help.
function Settings_Help_Callback(hObject, eventdata, handles)
% hObject    handle to Settings_Help (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Start_SelectFile.
function Start_SelectFile_Callback(hObject, eventdata, handles)
% hObject    handle to Start_SelectFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Select idf file
[FileName,PathName] = uigetfile('*.idf','Select IDF-file');
if ischar(FileName) && ischar(PathName)
    % Open Dialog to select file
    handles.DATA.idfFile = FileName;
    handles.DATA.idfFullPath = [PathName FileName];
    handles.DATA.projectPath = PathName;
    
    % Update text box
    set(handles.Start_FilenameEdit,'string',handles.DATA.idfFullPath);
    
    % Get TimeStep and RunPeriod
    idfStruct = readIDF(handles.DATA.idfFullPath,{'Timestep','RunPeriod'});
    
    % Save IDF Info
    handles.DATA.timeStep = str2double(char(idfStruct(1).fields{1}));
    handles.DATA.runPeriod.BeginMonth = str2double(char(idfStruct(2).fields{1}(2)));
    handles.DATA.runPeriod.BeginDay = str2double(char(idfStruct(2).fields{1}(3)));
    handles.DATA.runPeriod.EndMonth = str2double(char(idfStruct(2).fields{1}(4)));
    handles.DATA.runPeriod.EndDay = str2double(char(idfStruct(2).fields{1}(5)));
    
    % Display Values
    set(handles.Start_BeginMonthEdit, 'String', handles.DATA.runPeriod.BeginMonth);
    set(handles.Start_BeginDayEdit, 'String', handles.DATA.runPeriod.BeginDay);
    set(handles.Start_EndMonthEdit, 'String', handles.DATA.runPeriod.EndMonth);
    set(handles.Start_EndDayEdit, 'String', handles.DATA.runPeriod.EndDay);
    set(handles.Start_TimeStepEdit, 'String', handles.DATA.timeStep);
else
    MSG = 'Double check the EnergyPlus File.';
    errordlg(MSG,'EnergyPlus File Error');
end

% Update handles structure
guidata(hObject, handles);

function Start_FilenameEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Start_FilenameEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Start_FilenameEdit as text
%        str2double(get(hObject,'String')) returns contents of Start_FilenameEdit as a double
% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function Start_FilenameEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Start_FilenameEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end
% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in Start_SelectWeather.
function Start_SelectWeather_Callback(hObject, eventdata, handles)
% hObject    handle to Start_SelectWeather (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
weatherDir = [handles.eplusDir filesep 'WeatherData'];
[FileName,PathName] = uigetfile('*.epw','Select Weather file', weatherDir);
if ischar(FileName) && ischar(PathName)
    [~, name, ~] = fileparts(FileName);
    handles.DATA.Weather =  name;
    set(handles.Start_WeatherEdit,'string',handles.DATA.Weather);
else
    MSG = 'Not a valid Weather File.';
    errordlg(MSG,'Weather File Error');
end

% Update handles structure
guidata(hObject, handles);

function Start_WeatherEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Start_WeatherEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Start_WeatherEdit as text
%        str2double(get(hObject,'String')) returns contents of Start_WeatherEdit as a double


% --- Executes during object creation, after setting all properties.
function Start_WeatherEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Start_WeatherEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Start_UpdateChanges.
function Start_UpdateChanges_Callback(hObject, eventdata, handles)
% hObject    handle to Start_UpdateChanges (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function Start_BeginMonthEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Start_BeginMonthEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Start_BeginMonthEdit as text
%        str2double(get(hObject,'String')) returns contents of Start_BeginMonthEdit as a double
% handles.DATA.temp.timeStep = str2double(get(handles.Start_TimeStep,'String'));
handles.DATA.runPeriod_BeginMonth = str2double(get(handles.Start_BeginMonthEdit,'String'));

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function Start_BeginMonthEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Start_BeginMonthEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Start_EndMonthEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Start_EndMonthEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get Data from Box
handles.DATA.runPeriod_EndMonth = str2double(get(handles.Start_EndMonthEdit,'String'));

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function Start_EndMonthEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Start_EndMonthEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Start_BeginDayEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Start_BeginDayEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get Data from Box
handles.DATA.runPeriod_BeginDay = str2double(get(handles.Start_BeginDayEdit,'String'));
% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function Start_BeginDayEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Start_BeginDayEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Start_EndDayEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Start_EndDayEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get Data from Box
handles.DATA.runPeriod_EndDay = str2double(get(handles.Start_EndDayEdit,'String'));

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function Start_EndDayEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Start_EndDayEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Start_TimeStepEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Start_TimeStepEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get Data from Box
handles.DATA.timeStep = str2double(get(handles.Start_TimeStepEdit,'String'));

% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function Start_TimeStepEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Start_TimeStepEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Start_EditFile.
function Start_EditFile_Callback(hObject, eventdata, handles)
% hObject    handle to Start_EditFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Open IDF file
if isfield(handles.DATA, 'idfFullPath') && ~isempty(handles.DATA.idfFullPath)
    edit(handles.DATA.idfFullPath);
else
    MSG = '.IDF File does not exist or not selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in Start_MainHelp.
function Start_MainHelp_Callback(hObject, eventdata, handles)
% hObject    handle to Start_MainHelp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
file = [handles.mlep_home filesep 'mlepHelp' filesep 'index.html']
web(file);

% --- Executes on button press in pushbutton16.
function pushbutton16_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
web('http://mlab.seas.upenn.edu/mlep/');

% --- Executes on button press in pushbutton17.
function pushbutton17_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton17 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Start_Diagram.
function Start_Diagram_Callback(hObject, eventdata, handles)
% hObject    handle to Start_Diagram (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Control_VariableButton.
function Control_VariableButton_Callback(hObject, eventdata, handles)
% hObject    handle to Control_VariableButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Check if IDF selected
if isfield(handles.DATA, 'idfFullPath')
    % Launch GUI
    handles.handlesVar = setConfigurationFile('filename',handles.DATA.idfFullPath, 'mainHandles', handles);
else
    MSG = '.IDF File does not exist or has not been selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Control_OpenEnergyPlusFile.
function Control_OpenEnergyPlusFile_Callback(hObject, eventdata, handles)
% hObject    handle to Control_OpenEnergyPlusFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Open IDF file
if isfield(handles.DATA, 'idfFullPath') && ~isempty(handles.DATA.idfFullPath)
    edit(handles.DATA.idfFullPath);
else
    MSG = '.IDF File does not exist or not selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);


% --- Executes on button press in pushbutton21.
function pushbutton21_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton21 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton22.
function pushbutton22_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton22 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in Control_InputListbox.
function Control_InputListbox_Callback(hObject, eventdata, handles)
% hObject    handle to Control_InputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Update Variable Data
[handles] = updateVariable(handles);

% Display Comment
index = get(handles.Control_InputListbox, 'Value');
set(handles.Control_InputCommentEdit, 'String', handles.DATA.variableInput(index,4));

% Update handles structure 
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function Control_InputListbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Control_InputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in Control_OutputListbox.
function Control_OutputListbox_Callback(hObject, eventdata, handles)
% hObject    handle to Control_OutputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% % Update Variable Data
% [handles] = updateVariable(handles);

% Display Comment
index = get(handles.Control_OutputListbox, 'Value');
set(handles.Control_OutputCommentEdit, 'String', handles.DATA.variableOutput(index,4));

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function Control_OutputListbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Control_OutputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in Simulation_VariableListbox.
function Simulation_VariableListbox_Callback(hObject, eventdata, handles)
% hObject    handle to Simulation_VariableListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns Simulation_VariableListbox contents as cell array
%        contents{get(hObject,'Value')} returns selected item from Simulation_VariableListbox


% --- Executes during object creation, after setting all properties.
function Simulation_VariableListbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Simulation_VariableListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Simulation_RunSimulation.
function Simulation_RunSimulation_Callback(hObject, eventdata, handles)
% hObject    handle to Simulation_RunSimulation (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Change Button color
set(handles.Simulation_RunSimulation, 'BackgroundColor', [0.8 0.8 0.8]);
set(handles.Simulation_VariableListbox,'string','');

% Run Simulation
temp = get(handles.timeOut,'string');
if ~isempty(temp)
    acceptTimeOut = str2num(temp);
else
    acceptTimeOut = 8000;
end
handles.DATA.AcceptTimeOut = acceptTimeOut;
handles.DATA.runPeriodLength = (handles.DATA.runPeriod(1).EndMonth - handles.DATA.runPeriod(1).BeginMonth)*31 + ...
    (handles.DATA.runPeriod(1).EndDay - handles.DATA.runPeriod(1).BeginDay+1);

% UserData
if ~isfield(handles.DATA,'UserData')
    handles.DATA.UserData = [];
end

% Update variableData
handles = updateVariable(handles);

% idfFilePath, controlFilePath, weatherFile, timeStep, runPeriod, timeOut, inputTable, outputTable
[result] = mlepRunTemplate(handles.DATA.idfFullPath, handles.DATA.ControlFileName, ...
    handles.DATA.Weather, handles.DATA.timeStep, handles.DATA.runPeriodLength, ...
    handles.DATA.AcceptTimeOut, handles.DATA.variableInput, handles.DATA.variableOutput, ...
    handles.DATA.UserData);

% Change Button color
set(handles.Simulation_RunSimulation, 'BackgroundColor', 'g');

% Check Whether csv got written
filePath = regexprep(handles.DATA.idfFile, 'idf', 'csv');
pathOutput = [handles.DATA.projectPath 'Output' filesep filePath];

% Small Pause to let files get written 
for count = 1:10
    pause(0.5);
    if exist(pathOutput,'file')
        break;
    end
end

% Check Directory for CSV File
if exist(pathOutput,'file')
    % Load CSV Results
    [handles.DATA.vars, handles.DATA.varsData, ts] = mlepLoadEPResults(pathOutput);
    
    % Get Names of Variables NAMES OF VARIABLES
    handles.DATA.simulateListboxText = {};
    for i = 1:size(handles.DATA.vars,1)
        handles.DATA.simulateListboxText{i} = [handles.DATA.vars(i).object '-' handles.DATA.vars(i).name];
    end
    
    % Last Entry
    last = i;
    % Add Input
    for i = 1:size(handles.DATA.inputFieldNames,2)
        handles.DATA.simulateListboxText{i+last} = handles.DATA.inputFieldNames{i};
        handles.DATA.varsData(:,i+last) = handles.DATA.mlepIn.(handles.DATA.inputFieldNames{i})(1:size(handles.DATA.varsData,1))';
        handles.DATA.vars(i+last).object = handles.DATA.inputFieldNames(i);
    end 
%     
%     if isempty(i)
%         i = 0;
%     end
%     
%     last = i+last;
%     handles.DATA.outputFieldNames = fieldnames(handles.DATA.mlepOut);
%     % Add Output
%     for i = 1:size(handles.DATA.outputFieldNames,1)
%         handles.DATA.simulateListboxText{i+last} = handles.DATA.outputFieldNames{i};
%         handles.DATA.varsData(:,i+last) = handles.DATA.mlepOut.(handles.DATA.outputFieldNames{i})(1:size(handles.DATA.varsData,1))';
%         handles.DATA.vars(i+last).object = handles.DATA.outputFieldNames(i);
%     end
    
    
    if size(handles.DATA.simulateListboxText,2)
        set(handles.Simulation_VariableListbox,'value',1);
    end
    set(handles.Simulation_VariableListbox,'string',handles.DATA.simulateListboxText);
 
    
else
    disp(['Project Folder' handles.DATA.projectPath])
    mlepError = 'not Output File Generated';
    errordlg(mlepError,'Check the .err file for details on the problem.')
    return;
end

%[mlep] = mlepDisplayDxf(mlep);

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Simulation_SaveAll.
function Simulation_SaveAll_Callback(hObject, eventdata, handles)
% hObject    handle to Simulation_SaveAll (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Select where to store and name file
[FileName,PathName] = uiputfile('mlepResult.mat','Save Results',[handles.DATA.projectPath]);
% If not picked any File
if (~ischar(FileName) || ~ischar(PathName))
    return;
else
    DATA = struct();
    DATA.result = handles.DATA.varsData(:,:);
    DATA.name = handles.DATA.vars(:);
    save([PathName FileName], 'DATA');
    disp(['Saved All Result in ' PathName FileName] );
end
% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Simulation_SaveSelected.
function Simulation_SaveSelected_Callback(hObject, eventdata, handles)
% hObject    handle to Simulation_SaveSelected (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Save Selected
handles.DATA.simulateListboxIndex = get(handles.Simulation_VariableListbox,'Value');
% Select where to store and name file
[FileName,PathName] = uiputfile('mlepResult.mat','Save Results',[handles.DATA.projectPath]);
% If not picked any File
if (~ischar(FileName) || ~ischar(PathName))
    return;
else
    DATA = struct();
    DATA.result = handles.DATA.varsData(:,handles.DATA.simulateListboxIndex);
    DATA.name = handles.DATA.vars(handles.DATA.simulateListboxIndex);
    save([PathName FileName], 'DATA');
    disp(['Saved Result in ' PathName FileName] );
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Control_CreateControl.
function Control_CreateControl_Callback(hObject, eventdata, handles)
% hObject    handle to Control_CreateControl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

if isfield(handles.DATA, 'idfFullPath') && ~isempty(handles.DATA.idfFullPath)
    handles.DATA.ControlFileName = 'ControlFile.m';
    set(handles.Control_LoadControlFileEdit, 'Background', 'white');
    set(handles.Control_CreateControlFileEdit, 'Background', 'c');
    handles.DATA.ControlFileCreated = 1;
    handles.DATA.ControlFileDir = handles.DATA.projectPath;
    
%     % Update Variable Data
%     [handles] = updateVariable(handles);
%     
    % Create Control File
    result = mlepCreateControlFile(handles.DATA.projectPath, handles.DATA.ControlFileName, handles.DATA.variableInput, handles.DATA.variableOutput);
else
    MSG = '.IDF File does not exist or not selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Control_LoadControlFile.
function Control_LoadControlFile_Callback(hObject, eventdata, handles)
% hObject    handle to Control_LoadControlFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% % Update Variable Data
% [handles] = updateVariable(handles);

% Check if Selected IDF
if isfield(handles.DATA, 'idfFullPath') && ~isempty(handles.DATA.idfFullPath)
    % Select Control File
    [FileName,PathName] = uigetfile('*.m','Select Control m-file', handles.DATA.projectPath);
    
    % Check File
    if ischar(FileName) && ischar(PathName)
        % Open Dialog to select file
        handles.DATA.ControlFileName = FileName;
        handles.DATA.ControlFullPath = [PathName FileName];
        handles.DATA.projectPath = PathName;
        
        % Display Values
        set(handles.Control_LoadControlFileEdit, 'String', handles.DATA.ControlFileName);
    else
        MSG = 'Control File Selected does not exist or is not valid.';
        errordlg(MSG,'Control File Error');
    end
    
    set(handles.Control_LoadControlFileEdit, 'Background', 'c');
    set(handles.Control_CreateControlFileEdit, 'Background', 'white');
    handles.DATA.ControlFileCreated = 0;
    handles.DATA.ControlFileDir = handles.DATA.projectPath;
    
else
    MSG = '.IDF File does not exist or not selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Control_EditControlFile.
function Control_EditControlFile_Callback(hObject, eventdata, handles)
% hObject    handle to Control_EditControlFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Check whether Control File is valid
if isfield(handles.DATA, 'ControlFileName');
    % Open Control File
    edit([handles.DATA.ControlFileDir filesep handles.DATA.ControlFileName]);
else
    MSG = 'Control File Not Selected or Not Valid';
    errordlg(MSG,'Control File Error');
end
% Update handles structure
guidata(hObject, handles);

function Control_CreateControlFileEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Control_CreateControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Control_CreateControlFileEdit as text
%        str2double(get(hObject,'String')) returns contents of Control_CreateControlFileEdit as a double


% --- Executes during object creation, after setting all properties.
function Control_CreateControlFileEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Control_CreateControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function Control_LoadControlFileEdit_Callback(hObject, eventdata, handles)
% hObject    handle to Control_LoadControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of Control_LoadControlFileEdit as text
%        str2double(get(hObject,'String')) returns contents of Control_LoadControlFileEdit as a double


% --- Executes during object creation, after setting all properties.
function Control_LoadControlFileEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Control_LoadControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in Control_SelectUserData.
function Control_SelectUserData_Callback(hObject, eventdata, handles)
% hObject    handle to Control_SelectUserData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Select UserData variable
handles.DATA.workVars = evalin('base','who');

if isempty(handles.DATA.workVars)
    MSG = 'No available workspace variable.';
    errordlg(MSG,'Workspace');
else
    set(handles.Control_UserDataPopUp, 'String', handles.DATA.workVars);
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on selection change in Control_UserDataPopUp.
function Control_UserDataPopUp_Callback(hObject, eventdata, handles)
% hObject    handle to Control_UserDataPopUp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if isempty(handles.DATA.workVars)
    MSG = 'No available workspace variable.';
    errordlg(MSG,'Workspace');
else
    handles.DATA.UserDataValue = get(handles.Control_UserDataPopUp, 'Value');
    handles.DATA.UserData = evalin('base',handles.DATA.workVars{handles.DATA.UserDataValue});
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Simulation_GridToggle.
function Simulation_GridToggle_Callback(hObject, eventdata, handles)
% Get Status
handles.Simulation_GridStatus = get(handles.Simulation_GridToggle,'Value');

% Change Grid Status
if handles.Simulation_GridStatus
    set(handles.Simulation_GraphAxes, 'XGrid', 'on', 'YGrid', 'on');
else
    set(handles.Simulation_GraphAxes, 'XGrid', 'off', 'YGrid', 'off');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in SystemID_VariableButton.
function SystemID_VariableButton_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_VariableButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Check if IDF selected
if isfield(handles.DATA, 'idfFullPath')
    % Launch GUI
    handles.handlesVar = setConfigurationFile('filename',handles.DATA.idfFullPath, 'mainHandles', handles);
else
    MSG = '.IDF File does not exist or has not been selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in SystemID_OpenEnergyPlusFile.
function SystemID_OpenEnergyPlusFile_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_OpenEnergyPlusFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Open IDF file
if isfield(handles.DATA, 'idfFullPath') && ~isempty(handles.DATA.idfFullPath)
    edit(handles.DATA.idfFullPath);
else
    MSG = '.IDF File does not exist or not selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in pushbutton38.
function pushbutton38_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton38 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton39.
function pushbutton39_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton39 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in SystemID_InputListbox.
function SystemID_InputListbox_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_InputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Update Variable Data
[handles] = updateVariable(handles);

% Display Comment
index = get(handles.SystemID_InputListbox, 'Value');
set(handles.SystemID_InputCommentEdit, 'String', handles.DATA.variableInput(index,4));

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function SystemID_InputListbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_InputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in SystemID_OutputListbox.
function SystemID_OutputListbox_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_OutputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Update Variable Data
[handles] = updateVariable(handles);

% Display Comment
index = get(handles.SystemID_OutputListbox, 'Value');
set(handles.SystemID_OutputCommentEdit, 'String', handles.DATA.variableOutput(index,4));

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function SystemID_OutputListbox_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_OutputListbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton48.
function pushbutton48_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton48 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Select Start Tab
tabHandlerSysID(handles.tabHandlesSysID,1);

% Color
set(handles.pushbutton48, 'Background', 'g');
set(handles.pushbutton49, 'Background', get(0,'defaultUicontrolBackgroundColor'));

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in pushbutton49.
function pushbutton49_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton49 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Select Start Tab
tabHandlerSysID(handles.tabHandlesSysID,2);

% Color
set(handles.pushbutton48, 'Background', get(0,'defaultUicontrolBackgroundColor'));
set(handles.pushbutton49, 'Background', 'green');

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in pushbutton40.
function pushbutton40_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton40 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton41.
function pushbutton41_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton41 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton42.
function pushbutton42_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton42 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton43.
function pushbutton43_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton43 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function pushbutton48_CreateFcn(hObject, eventdata, handles)
% hObject    handle to pushbutton48 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on selection change in SystemID_ListboxPackage.
function SystemID_ListboxPackage_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_ListboxPackage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Get Selection
handles.DATA.SystemID_ListboxPackageIndex = get(handles.SystemID_ListboxPackage,'Value');

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function SystemID_ListboxPackage_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_ListboxPackage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in SystemID_InputListboxPackage.
function SystemID_InputListboxPackage_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_InputListboxPackage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Get Selection
handles.DATA.SystemID_InputListboxPackageIndex = get(handles.SystemID_InputListboxPackage,'Value');

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function SystemID_InputListboxPackage_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_InputListboxPackage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in SystemID_OutputListboxPackage.
function SystemID_OutputListboxPackage_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_OutputListboxPackage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Get Selection
handles.DATA.SystemID_OutputListboxPackageIndex = get(handles.SystemID_OutputListboxPackage,'Value');

% Update handles structure
guidata(hObject, handles);

% --- Executes during object creation, after setting all properties.
function SystemID_OutputListboxPackage_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_OutputListboxPackage (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in SystemID_AddInput.
function SystemID_AddInput_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_AddInput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Input Listbox Exist
if ~isfield(handles.DATA,'SystemID_InputListboxPackageText')
    handles.DATA.SystemID_InputListboxPackageText = {};
    handles.DATA.SystemID_InputListboxPackageData = [];
end

% Add Variable
num_selected = length(handles.DATA.SystemID_ListboxPackageIndex);
if num_selected
    handles.DATA.SystemID_InputListboxPackageText(end+1:end+num_selected) = handles.DATA.SystemID_ListboxPackageText(handles.DATA.SystemID_ListboxPackageIndex);
    handles.DATA.SystemID_InputListboxPackageData(:,end+1:end+num_selected) = handles.DATA.varsData(:,handles.DATA.SystemID_ListboxPackageIndex);
end
set(handles.SystemID_InputListboxPackage,'String',handles.DATA.SystemID_InputListboxPackageText');

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in pushbutton50.
function pushbutton50_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton50 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function edit14_Callback(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit14 as text
%        str2double(get(hObject,'String')) returns contents of edit14 as a double


% --- Executes during object creation, after setting all properties.
function edit14_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit14 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in SystemID_RunSimulation.
function SystemID_RunSimulation_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_RunSimulation (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.Simulation_RunSimulation, 'BackgroundColor', [0.8 0.8 0.8]);
set(handles.SystemID_RunSimulation, 'BackgroundColor', [0.8 0.8 0.8]);
set(handles.Simulation_VariableListbox,'string','');

% Run Simulation
temp = get(handles.timeOut,'string');
if ~isempty(temp) && ~strcmp(temp,'Time Out')
    acceptTimeOut = str2num(temp);
else
    acceptTimeOut = 8000;
end
handles.DATA.AcceptTimeOut = acceptTimeOut;
handles.DATA.runPeriodLength = (handles.DATA.runPeriod(1).EndMonth - handles.DATA.runPeriod(1).BeginMonth)*31 + ...
    (handles.DATA.runPeriod(1).EndDay - handles.DATA.runPeriod(1).BeginDay+1);

% UserData
if ~isfield(handles.DATA,'UserData')
    handles.DATA.UserData = [];
end

% Update variableData
handles = updateVariable(handles);

% idfFilePath, controlFilePath, weatherFile, timeStep, runPeriod, timeOut, inputTable, outputTable
[time, logInput, logOutput] = mlepRunTemplate(handles.DATA.idfFullPath, handles.DATA.ControlFileName, ...
    handles.DATA.Weather, handles.DATA.timeStep, handles.DATA.runPeriodLength, ...
    handles.DATA.AcceptTimeOut, handles.DATA.variableInput, handles.DATA.variableOutput, ...
    handles.DATA.UserData);

% Save inputs
handles.DATA.logInput = logInput;
handles.DATA.logOutput = logOutput;

% Change Button color
set(handles.Simulation_RunSimulation, 'BackgroundColor', 'g');
set(handles.SystemID_RunSimulation, 'BackgroundColor', 'g');

% Check Whether csv got written
filePath = regexprep(handles.DATA.idfFile, 'idf', 'csv');
pathOutput = [handles.DATA.projectPath 'Output' filesep filePath];

% Small Pause to let files get written 
for count = 1:10
    pause(0.5);
    if exist(pathOutput,'file')
        break;
    end
end

% Check Directory for CSV File
if exist(pathOutput,'file')
    % Load CSV Results
    [handles.DATA.vars, handles.DATA.varsData, ts] = mlepLoadEPResults(pathOutput);
    
    % Get Names of Variables NAMES OF VARIABLES
    handles.DATA.simulateListboxText = {};
    for i = 1:size(handles.DATA.vars,1)
        handles.DATA.simulateListboxText{i} = [handles.DATA.vars(i).object '-' handles.DATA.vars(i).name];
    end
    
    % Last Entry
    last = i;
    % Add Input
    for i = 1:size(handles.DATA.variableInput,1)
        handles.DATA.simulateListboxText{i+last} = handles.DATA.variableInput{i,5};
        handles.DATA.varsData(:,i+last) = handles.DATA.logInput(:,i); % handles.DATA.mlepIn.(handles.DATA.inputFieldNames{i})(1:size(handles.DATA.varsData,1))'
        handles.DATA.vars(i+last).object = handles.DATA.variableInput{i,4};
        handles.DATA.vars(i+last).name = handles.DATA.variableInput{i,4};
    end 
    
    if size(handles.DATA.simulateListboxText,2)
        set(handles.Simulation_VariableListbox,'value',1);
    end
    set(handles.Simulation_VariableListbox,'string',handles.DATA.simulateListboxText);
 
    % Load Variables
    handles.DATA.SystemID_ListboxPackageText = handles.DATA.simulateListboxText;
    set(handles.SystemID_ListboxPackage,'string',handles.DATA.SystemID_ListboxPackageText);
   
else
    disp(['Project Folder' handles.DATA.projectPath])
    mlepError = 'not Output File Generated';
    errordlg(mlepError,'Check the .err file for details on the problem.')
    return;
end

%[mlep] = mlepDisplayDxf(mlep);

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in SystemID_GenIDDATA.
function SystemID_GenIDDATA_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_GenIDDATA (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Package data
% Set Y = OUTPUTS
y = handles.DATA.SystemID_OutputListboxPackageData;
% Set U = INPUTS
u = handles.DATA.SystemID_InputListboxPackageData;
% Set Time in Seconds
Ts = 60/handles.DATA.timeStep;

% SET PROPERTIES
% INPUT NAME
handles.DATA.SystemID_InputName = {};
handles.DATA.SystemID_InputUnit = {};
handles.DATA.SystemID_OutputName = {};
handles.DATA.SystemID_OutputUnit = {};
% for i = 1:size(mlep.data.sysIDInputDataSelected,2)
%     mlep.data.inputName = [mlep.data.inputName [mlep.data.sysIDInputPropertySelected(i).object ' ' mlep.data.sysIDInputPropertySelected(i).name]];
%     mlep.data.inputUnit = [mlep.data.inputUnit mlep.data.sysIDInputPropertySelected(i).unit];
% end
% % OUTPUT NAME
% mlep.data.outputName = {};
% mlep.data.outputUnit = {};
% for i = 1:size(mlep.data.sysIDOutputDataSelected,2)
%     mlep.data.outputName = [mlep.data.outputName [mlep.data.sysIDOutputPropertySelected(i).object ' ' mlep.data.sysIDOutputPropertySelected(i).name]];
%     mlep.data.outputUnit = [mlep.data.outputUnit mlep.data.sysIDOutputPropertySelected(i).unit];
% end

handles.DATA.SystemID_TimeUnit = 'minutes';
 
% IDDATA
handles.DATA.SystemID_estData = iddata(y, u, Ts,...
    'Name', 'Estimated data disturbance',...
    'InputName',handles.DATA.SystemID_InputName,...%    'InputUnit', mlep.data.inputUnit,...
    'OutputName', handles.DATA.SystemID_InputName,... %    'OutputUnit', mlep.data.outputUnit,...
    'TimeUnit', handles.DATA.SystemID_TimeUnit,...
    'Tstart', 0,...
    'Notes', 'Estimation data');

% Rename
estData = handles.DATA.SystemID_estData;
% Select where to store and name file
[FileName,PathName] = uiputfile('EstData.mat','Save file name',[handles.DATA.projectPath]);
save([PathName FileName], 'estData');
disp(['Saved Estimated Data File ' PathName FileName] );


% --- Executes on button press in SystemID_launchIdent.
function SystemID_launchIdent_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_launchIdent (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
ident;

% --- Executes on button press in pushbutton59.
function pushbutton59_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton59 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in SystemID_AddOutput.
function SystemID_AddOutput_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_AddOutput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Input Listbox Exist
if ~isfield(handles.DATA,'SystemID_OutputListboxText')
    handles.DATA.SystemID_OutputListboxPackageText = {};
    handles.DATA.SystemID_OutputListboxPackageData = [];
end

% Add Variable
num_selected = length(handles.DATA.SystemID_ListboxPackageIndex);
if num_selected
    handles.DATA.SystemID_OutputListboxPackageText(end+1:end+num_selected) = handles.DATA.SystemID_ListboxPackageText(handles.DATA.SystemID_ListboxPackageIndex);
    handles.DATA.SystemID_OutputListboxPackageData(:,end+1:end+num_selected) = handles.DATA.varsData(:,handles.DATA.SystemID_ListboxPackageIndex);
end
set(handles.SystemID_OutputListboxPackage,'String',handles.DATA.SystemID_OutputListboxPackageText');

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in SystemID_DeleteInput.
function SystemID_DeleteInput_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_DeleteInput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Delete Input
num_selected = length(handles.DATA.SystemID_InputListboxPackageIndex);
if num_selected
    handles.DATA.SystemID_InputListboxPackageText(handles.DATA.SystemID_InputListboxPackageIndex) = [];
    handles.DATA.SystemID_InputListboxPackageData(:,handles.DATA.SystemID_InputListboxPackageIndex) = [];
end
set(handles.SystemID_InputListboxPackage,'Value',1);
set(handles.SystemID_InputListboxPackage,'String',handles.DATA.SystemID_InputListboxPackageText);

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in SystemID_DeleteOutput.
function SystemID_DeleteOutput_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_DeleteOutput (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Delete Input
num_selected = length(handles.DATA.SystemID_OutputListboxPackageIndex);
if num_selected
    handles.DATA.SystemID_OutputListboxPackageText(handles.DATA.SystemID_OutputListboxPackageIndex) = [];
    handles.DATA.SystemID_OutputListboxPackageData(:,handles.DATA.SystemID_OutputListboxPackageIndex) = [];
end
set(handles.SystemID_OutputListboxPackage,'Value',1);
set(handles.SystemID_OutputListboxPackage,'String',handles.DATA.SystemID_OutputListboxPackageText);

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in pushbutton63.
function pushbutton63_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton63 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton64.
function pushbutton64_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton64 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton65.
function pushbutton65_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton65 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function edit15_Callback(hObject, eventdata, handles)
% hObject    handle to edit15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit15 as text
%        str2double(get(hObject,'String')) returns contents of edit15 as a double


% --- Executes during object creation, after setting all properties.
function edit15_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit15 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit16_Callback(hObject, eventdata, handles)
% hObject    handle to edit16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit16 as text
%        str2double(get(hObject,'String')) returns contents of edit16 as a double


% --- Executes during object creation, after setting all properties.
function edit16_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit16 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in SystemID_CreateControl.
function SystemID_CreateControl_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_CreateControl (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if isfield(handles.DATA, 'idfFullPath') && ~isempty(handles.DATA.idfFullPath)
    handles.DATA.ControlFileName = 'ControlFile.m';
    set(handles.SystemID_LoadControlFileEdit, 'Background', 'white');
    set(handles.SystemID_CreateControlFileEdit, 'Background', 'c');
    set(handles.Control_LoadControlFileEdit, 'Background', 'white');
    set(handles.Control_CreateControlFileEdit, 'Background', 'c');
    handles.DATA.ControlFileCreated = 1;
    handles.DATA.ControlFileDir = handles.DATA.projectPath;
    
%     % Update Variable Data
%     [handles] = updateVariable(handles);
%     
    % Create Control File
    result = mlepCreateControlFile(handles.DATA.projectPath, handles.DATA.ControlFileName, handles.DATA.variableInput, handles.DATA.variableOutput);
else
    MSG = '.IDF File does not exist or not selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in SystemID_LoadControlFile.
function SystemID_LoadControlFile_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_LoadControlFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Check if Selected IDF
if isfield(handles.DATA, 'idfFullPath') && ~isempty(handles.DATA.idfFullPath)
    % Select Control File
    [FileName,PathName] = uigetfile('*.m','Select Control m-file', handles.DATA.projectPath);
    
    % Check File
    if ischar(FileName) && ischar(PathName)
        % Open Dialog to select file
        handles.DATA.ControlFileName = FileName;
        handles.DATA.ControlFullPath = [PathName FileName];
        handles.DATA.projectPath = PathName;
        
        % Display Values
        set(handles.SystemID_LoadControlFileEdit, 'String', handles.DATA.ControlFileName);
        set(handles.Control_LoadControlFileEdit, 'String', handles.DATA.ControlFileName);
    else
        MSG = 'Control File Selected does not exist or is not valid.';
        errordlg(MSG,'Control File Error');
    end
    
    set(handles.SystemID_LoadControlFileEdit, 'Background', 'c');
    set(handles.SystemID_CreateControlFileEdit, 'Background', 'white');
    set(handles.Control_LoadControlFileEdit, 'Background', 'c');
    set(handles.Control_CreateControlFileEdit, 'Background', 'white');
    handles.DATA.ControlFileCreated = 0;
    handles.DATA.ControlFileDir = handles.DATA.projectPath;
    
else
    MSG = '.IDF File does not exist or not selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in SystemID_EditControlFile.
function SystemID_EditControlFile_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_EditControlFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if isfield(handles.DATA, 'ControlFileName');
    % Open Control File
    edit([handles.DATA.ControlFileDir filesep handles.DATA.ControlFileName]);
else
    MSG = 'Control File Not Selected or Not Valid';
    errordlg(MSG,'Control File Error');
end
% Update handles structure
guidata(hObject, handles);


function SystemID_CreateControlFileEdit_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_CreateControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of SystemID_CreateControlFileEdit as text
%        str2double(get(hObject,'String')) returns contents of SystemID_CreateControlFileEdit as a double


% --- Executes during object creation, after setting all properties.
function SystemID_CreateControlFileEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_CreateControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function SystemID_LoadControlFileEdit_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_LoadControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of SystemID_LoadControlFileEdit as text
%        str2double(get(hObject,'String')) returns contents of SystemID_LoadControlFileEdit as a double


% --- Executes during object creation, after setting all properties.
function SystemID_LoadControlFileEdit_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_LoadControlFileEdit (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in SystemID_SelectUserData.
function SystemID_SelectUserData_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_SelectUserData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
handles.DATA.workVars = evalin('base','who');

if isempty(handles.DATA.workVars)
    MSG = 'No available workspace variable.';
    errordlg(MSG,'Workspace');
else
    set(handles.Control_UserDataPopUp, 'String', handles.DATA.workVars);
end

% Update handles structure
guidata(hObject, handles);


% --------------------------------------------------------------------
function Untitled_1_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in Simulation_PlotVariableButton.
function Simulation_PlotVariableButton_Callback(hObject, eventdata, handles)
% Get Selection Index
if ~isfield(handles,'Simulation_VariableListbox')
    mlepError = 'emptyArray';
    %mlepThrowError(mlepError);
    return;
end
handles.simulateListboxIndex = get(handles.Simulation_VariableListbox,'Value');

handles.DATA.Simulation_VariableListboxText = get(handles.Simulation_VariableListbox,'String');
graphTitle = handles.DATA.Simulation_VariableListboxText(handles.simulateListboxIndex);

% GET CURRENT AXES
set(gcf,'CurrentAxes', handles.Simulation_GraphAxes);
set(handles.Simulation_GraphAxes, 'HandleVisibility', 'callback');
%get(mlep.graph, 'HandleVisibility')
plot(handles.DATA.varsData(:,handles.simulateListboxIndex)); % CHECK THIS melp.graph,

title(handles.Simulation_GraphAxes,graphTitle);
if size(handles.DATA.vars,1) >= handles.simulateListboxIndex
    if size(handles.simulateListboxIndex,2) == 1
        xlabel(handles.Simulation_GraphAxes,handles.DATA.vars(handles.simulateListboxIndex).sampling);
        ylabel(handles.Simulation_GraphAxes,[handles.DATA.vars(handles.simulateListboxIndex).name ' ' handles.DATA.vars(handles.simulateListboxIndex).unit]);
    end
    legend(handles.DATA.vars(handles.simulateListboxIndex).name);
end
%[mlep] = gridToggle(mlep);

% Get Status
handles.Simulation_GridStatus = get(handles.Simulation_GridToggle,'Value');

% Change Grid Status
if handles.Simulation_GridStatus
    set(handles.Simulation_GraphAxes, 'XGrid', 'on', 'YGrid', 'on');
else
    set(handles.Simulation_GraphAxes, 'XGrid', 'off', 'YGrid', 'off');
end

% Update handles structure
guidata(hObject, handles);



function timeOut_Callback(hObject, eventdata, handles)
% hObject    handle to timeOut (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of timeOut as text
%        str2double(get(hObject,'String')) returns contents of timeOut as a double


% --- Executes during object creation, after setting all properties.
function timeOut_CreateFcn(hObject, eventdata, handles)
% hObject    handle to timeOut (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on key press with focus on SystemID_SelectUserData and none of its controls.
function SystemID_SelectUserData_KeyPressFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_SelectUserData (see GCBO)
% eventdata  structure with the following fields (see UICONTROL)
%	Key: name of the key that was pressed, in lower case
%	Character: character interpretation of the key(s) that was pressed
%	Modifier: name(s) of the modifier key(s) (i.e., control, shift) pressed
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in SystemID_UserDataPopUp.
function SystemID_UserDataPopUp_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_UserDataPopUp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
if isempty(handles.DATA.workVars)
    MSG = 'No available workspace variable.';
    errordlg(MSG,'Workspace');
else
    handles.DATA.UserDataValue = get(handles.Control_UserDataPopUp, 'Value');
    handles.DATA.UserData = evalin('base',handles.DATA.workVars{handles.DATA.UserDataValue});
end

% Update handles structure
guidata(hObject, handles);


% --- Executes during object creation, after setting all properties.
function SystemID_UserDataPopUp_CreateFcn(hObject, eventdata, handles)
% hObject    handle to SystemID_UserDataPopUp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes during object creation, after setting all properties.
function Control_UserDataPopUp_CreateFcn(hObject, eventdata, handles)
% hObject    handle to Control_UserDataPopUp (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton70.
function pushbutton70_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton70 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
