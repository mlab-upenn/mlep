function [handles] = mlepUpdateVariableTab(handles)

% Input Table
if ~isfield(handles.DATA,'variableInput')
    handles.DATA.variableInput = [];
end
% List Input
if ~isfield(handles.DATA,'listInput')
    handles.DATA.listInput = [];
end
% Output Table
if ~isfield(handles.DATA,'variableOutput')
    handles.DATA.variableOutput = [];
end
% List Output
if ~isfield(handles.DATA,'listOutput')
    handles.DATA.listOutput = [];
end
% Ext1 
if ~isfield(handles.DATA,'listInputExt1')
    handles.DATA.listInputExt1 = [];
end
% Input Comment 
if ~isfield(handles.DATA,'listInputComment')
    handles.DATA.listInputComment = [];
end	

% Output Comment 
if ~isfield(handles.DATA,'listOutputComment')
    handles.DATA.listOutputComment = [];
end	

% SET 
% set(handles.inputTable, 'Data', handles.DATA.variableInput);
% set(handles.variableInputListbox, 'String', handles.DATA.listInput);
% set(handles.outputTable, 'Data', handles.DATA.variableOutput);
% set(handles.variableOutputListbox, 'String', handles.DATA.listOutput);

% Input
handles.DATA.listInputIndex = 1;
% set(handles.variableInputListbox,'String',handles.DATA.listInput);
% if size(handles.DATA.listInputExt1,1) == 0
%     comment = [];
% else 
%     comment = handles.DATA.listInputExt1{handles.DATA.listInputIndex,6};
% end
% set(handles.variableInputComment,'String', comment);

% Output
handles.data.listOutputIndex = 1;
% set(handles.variableOutputListbox, 'String', handles.DATA.listOutput);
% if size(handles.DATA.listOutputComment,1) == 0
%     comment = [];
% else 
%     comment = handles.DATA.listOutputExt1{handles.DATA.listOutputIndex,5};
% end
% set(handles.variableOutputComment,'String', comment);
% end