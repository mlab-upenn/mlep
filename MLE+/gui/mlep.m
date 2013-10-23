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

% Last Modified by GUIDE v2.5 23-Oct-2013 14:36:52

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
    ima = imresize(ima, 0.45);
else
    ima = imageresize(ima, 0.45, 0.45);
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
end
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
handles.DATA.temp.runPeriod.BeginMonth = str2double(get(handles.Start_BeginMonthEdit,'String'));
% handles.DATA.temp.runPeriod.BeginDay = str2double(get(handles.Start_BeginDayEdit,'String'));
% handles.DATA.temp.runPeriod.EndMonth = str2double(get(handles.Start_EndMonthEdit,'String'));
% handles.DATA.temp.runPeriod.EndDay = str2double(get(handles.Start_EndDayEdit,'String'));

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
handles.DATA.temp.runPeriod.EndMonth = str2double(get(handles.Start_EndMonthEdit,'String'));

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
handles.DATA.temp.runPeriod.BeginDay = str2double(get(handles.Start_BeginDayEdit,'String'));
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
handles.DATA.temp.runPeriod.EndDay = str2double(get(handles.Start_EndDayEdit,'String'));

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
handles.DATA.temp.timeStep = str2double(get(handles.Start_TimeStepEdit,'String'));

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
    setConfigurationFile('filename',handles.DATA.idfFullPath, 'mainHandles', handles);
else
    MSG = '.IDF File does not exist or has not been selected.';
    errordlg(MSG,'IDF Problem');
end

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in Control_OpenFile.
function Control_OpenFile_Callback(hObject, eventdata, handles)
% hObject    handle to Control_OpenFile (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


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
set(handles.Control_InputCommentEdit, 'String', handles.DATA.variableInput{1}(index,4));

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

% Update Variable Data
[handles] = updateVariable(handles);

% Display Comment
index = get(handles.Control_OutputListbox, 'Value');
set(handles.Control_OutputCommentEdit, 'String', handles.DATA.variableOutput{1}(index,4));

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
[result] = mlepRunTemplate(handles.DATA.projectPath, handles.DATA.idfFullPath, handles.DATA.Weather, handles.DATA.ControlFileName);

% Change Button color
set(handles.Simulation_RunSimulation, 'BackgroundColor', 'g');

% Update handles structure
guidata(hObject, handles);

% --- Executes on button press in pushbutton24.
function pushbutton24_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton24 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton25.
function pushbutton25_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton25 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton26.
function pushbutton26_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton26 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


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
    
    % Update Variable Data
    [handles] = updateVariable(handles);
    
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
% Update Variable Data
[handles] = updateVariable(handles);

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


% --- Executes on button press in Simulation_GridToggle.
function Simulation_GridToggle_Callback(hObject, eventdata, handles)
% hObject    handle to Simulation_GridToggle (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of Simulation_GridToggle


% --- Executes on button press in SystemID_VariableButton.
function SystemID_VariableButton_Callback(hObject, eventdata, handles)
% hObject    handle to SystemID_VariableButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% Check if IDF selected
if isfield(handles.DATA, 'idfFullPath')
    % Launch GUI
    setConfigurationFile('filename',handles.DATA.idfFullPath, 'mainHandles', handles);
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
% Open EnergyPlus File
Start_EditFile_Callback(hObject, eventdata, handles);

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
set(handles.SystemID_InputCommentEdit, 'String', handles.DATA.variableInput{1}(index,4));

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
index = get(handles.SystemID_InputListbox, 'Value');
set(handles.SystemID_InputCommentEdit, 'String', handles.DATA.variableInput{1}(index,4));

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


% --- Executes on selection change in listbox6.
function listbox6_Callback(hObject, eventdata, handles)
% hObject    handle to listbox6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listbox6 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listbox6


% --- Executes during object creation, after setting all properties.
function listbox6_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox6 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in listbox7.
function listbox7_Callback(hObject, eventdata, handles)
% hObject    handle to listbox7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listbox7 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listbox7


% --- Executes during object creation, after setting all properties.
function listbox7_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox7 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on selection change in listbox8.
function listbox8_Callback(hObject, eventdata, handles)
% hObject    handle to listbox8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns listbox8 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from listbox8


% --- Executes during object creation, after setting all properties.
function listbox8_CreateFcn(hObject, eventdata, handles)
% hObject    handle to listbox8 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: listbox controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton52.
function pushbutton52_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton52 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


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


% --- Executes on button press in pushbutton51.
function pushbutton51_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton51 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton54.
function pushbutton54_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton54 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton58.
function pushbutton58_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton58 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton59.
function pushbutton59_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton59 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton60.
function pushbutton60_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton60 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton61.
function pushbutton61_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton61 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton62.
function pushbutton62_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton62 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


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


% --- Executes on button press in pushbutton67.
function pushbutton67_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton67 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton68.
function pushbutton68_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton68 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on button press in pushbutton69.
function pushbutton69_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton69 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



function edit17_Callback(hObject, eventdata, handles)
% hObject    handle to edit17 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit17 as text
%        str2double(get(hObject,'String')) returns contents of edit17 as a double


% --- Executes during object creation, after setting all properties.
function edit17_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit17 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit18_Callback(hObject, eventdata, handles)
% hObject    handle to edit18 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit18 as text
%        str2double(get(hObject,'String')) returns contents of edit18 as a double


% --- Executes during object creation, after setting all properties.
function edit18_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit18 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton66.
function pushbutton66_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton66 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes on selection change in popupmenu2.
function popupmenu2_Callback(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: contents = cellstr(get(hObject,'String')) returns popupmenu2 contents as cell array
%        contents{get(hObject,'Value')} returns selected item from popupmenu2


% --- Executes during object creation, after setting all properties.
function popupmenu2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to popupmenu2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: popupmenu controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --------------------------------------------------------------------
function Untitled_1_Callback(hObject, eventdata, handles)
% hObject    handle to Untitled_1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
