function [handles] = mlepUpdateControlTab(handles)



%% EXISTENCE
% Variable Input
if isfield(handles.DATA, 'variableInput') && ~isempty(handles.DATA.variableInput) && ~isfield(handles.DATA, 'Control_InputListbox')
    handles.DATA.Control_InputListbox = handles.DATA.variableInput(:,5);
    handles.DATA.Control_InputCommentEdit = handles.DATA.variableInput(:,4);
end

% Variable Output
if isfield(handles.DATA, 'variableOutput') && ~isempty(handles.DATA.variableOutput) && ~isfield(handles.DATA, 'Control_OutputListbox')
    handles.DATA.Control_OutputListbox = handles.DATA.variableInput(:,5);
    handles.DATA.Control_OutputCommentEdit = handles.DATA.variableOutput(:,4);
end

% Input Listbox
if ~isfield(handles.DATA, 'Control_InputListbox')
    handles.DATA.Control_InputListbox = [];
    handles.DATA.Control_InputCommentEdit = [];
    set(handles.Control_InputListbox, 'String', handles.DATA.Control_InputListbox);
    set(handles.Control_InputCommentEdit, 'String', handles.DATA.Control_InputCommentEdit);
else
    set(handles.Control_InputListbox, 'String', handles.DATA.Control_InputListbox);
    set(handles.Control_InputCommentEdit, 'String', handles.DATA.Control_InputCommentEdit);
end

% Output Listbox
if ~isfield(handles.DATA, 'Control_OutputListbox')
    handles.DATA.Control_OutputListbox = [];
    handles.DATA.Control_OutputCommentEdit = [];
    set(handles.Control_OutputListbox, 'String', handles.DATA.Control_OutputListbox);
    set(handles.Control_OutputCommentEdit, 'String', handles.DATA.Control_OutputCommentEdit);
else
    set(handles.Control_OutputListbox, 'String', handles.DATA.Control_OutputListbox);
    set(handles.Control_OutputCommentEdit, 'String', handles.DATA.Control_OutputCommentEdit);
end

% Control File
if ~isfield(handles.DATA,'ControlFileName')
    handles.DATA.ControlFileName = [];
    set(handles.Control_LoadControlFileEdit, 'String', 'Control File');
    set(handles.Control_CreateControlFileEdit, 'String', 'ControlFile.m');
    set(handles.Control_LoadControlFileEdit, 'Background', 'white');
    set(handles.Control_CreateControlFileEdit, 'Background', 'white');
else
    if isfield(handles.DATA,'ControlFileCreated')
        if handles.DATA.ControlFileCreated == 1
            set(handles.Control_CreateControlFileEdit, 'String', handles.DATA.ControlFileName);
            set(handles.Control_CreateControlFileEdit, 'Background', 'c');
            set(handles.Control_LoadControlFileEdit, 'Background', 'white');
        else
            set(handles.Control_LoadControlFileEdit, 'String', handles.DATA.ControlFileName);
            set(handles.Control_LoadControlFileEdit, 'Background', 'c');
            set(handles.Control_CreateControlFileEdit, 'Background', 'white');
        end
    end
end

% Workspace Vars
if ~isfield(handles.DATA,'workVars')
    handles.DATA.workVars = [];
end

end