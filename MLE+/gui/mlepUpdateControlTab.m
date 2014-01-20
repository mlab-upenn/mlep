function [handles] = mlepUpdateControlTab(handles)


%% EXISTENCE
% Input Listbox
if ~isfield(handles.DATA, 'Control_InputListbox')
    handles.DATA.Control_InputListbox = [];
    handles.DATA.Control_InputCommentEdit = [];
    set(handles.Control_InputListbox, 'String', handles.DATA.Control_InputListbox);
    set(handles.Control_InputCommentEdit, 'String', handles.DATA.Control_InputCommentEdit);
end

% Output Listbox
if ~isfield(handles.DATA, 'Control_OutputListbox')
    handles.DATA.Control_OutputListbox = [];
    handles.DATA.Control_OutputCommentEdit = [];
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
end

% Workspace Vars
if ~isfield(handles.DATA,'workVars')
	handles.DATA.workVars = [];
end

%% SIZE
% if size(handles.DATA.Control_InputListbox,1)
%     % Input Variables
%     set(handles.Control_InputCommentEdit, 'String', handles.DATA.Control_InputTable{handles.DATA.Control_ListInputIndex,5}, 'Enable', 'on');
%     set(handles.Control_InputListbox, 'Value', handles.DATA.Control_ListInputIndex);
%     set(handles.Control_InputListbox, 'String', handles.DATA.Control_InputTable(:,5), 'Enable', 'on');
% else
%     % Inactive
%     set(handles.Control_InputCommentEdit, 'String', [], 'Enable', 'off');
%     set(handles.Control_InputListbox, 'String', [], 'Enable', 'off');
% end

% if isfield(handles.DATA,'listOutputExt2')
%     if size(handles.DATA.listOutputExt2,1)
%         % OUTput Variables
%         set(handles.controlOutComment, 'String',handles.DATA.listOutputExt2{handles.DATA.controlListOutputIndex,5}, 'Enable', 'on');
%         set(handles.controlOutListbox, 'Value', handles.DATA.controlListOutputIndex);
%         set(handles.controlOutListbox, 'String', handles.DATA.listOutputExt2(:,6), 'Enable', 'on');
%     else
%         % Inactive
%         set(handles.controlOutComment, 'String', [], 'Enable', 'off');
%         set(handles.controlOutListbox, 'String', [], 'Enable', 'off');
%     end
% end

% Update Controller Type
% User Defined
% Control File used
% set(handles.controlFeedbackLoadEdit,'string',handles.DATA.controlFileName);
% Update UserData workspace
% if isempty(handles.DATA.workVars)
%     set(handles.controlPopupUserdata,'String','Select User DATA');
%     set(handles.controlPopupUserdata,'Enable','off');
%     return;
% else
%     set(handles.controlPopupUserdata,'String',handles.DATA.workVars,'Enable','on');
% end
% 
% % Update Controller Selected
% if isfield(handles.DATA,'controlLoaded')
%     if handles.DATA.controlLoaded == 1
%         set(handles.controlFeedbackLoadEdit, 'Background', 'c');
%         set(handles.controlFeedbackCreateEdit, 'Background', 'white');
%     end
% end
% if isfield(handles.DATA,'controlCreated')
%     if handles.DATA.controlCreated == 1
%         set(handles.controlFeedbackLoadEdit, 'Background', 'white');
%         set(handles.controlFeedbackCreateEdit, 'Background', 'c');
%     end
% end
%%

end