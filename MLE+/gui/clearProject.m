function [result] = clearProject(handles)
% CLEAR PROJECT - This function clears all fields in the current MLE+
% project. 
% Usage: [result] = clearProject(handles)
% Inputs:
% handles - Contains the object handle for the GUI.
%
% Outputs:
% result - Returns 0 or 1 whether the function was successful or not. 
%
% (C) 2013 by Willy Bernal (willyg@seas.upenn.edu)

% HISTORY:
%   2013-08-05 Started.
%
% Get all fielnames
names = fieldnames(handles.DATA);
 
% For each field
for i = 1:size(names,1)
%     if strcmp(class(handles.DATA.(names{i})),'struct')
%         handles.DATA = setfield(handles.DATA,names{i},struct());
%     elseif strcmp(class(handles.DATA.(names{i})),'cell')
%         handles.DATA = rmfield(handles.DATA,names{i},{});
%     else
%         handles.DATA = rmfield(handles.DATA,names{i},[]);
%     end        
handles.DATA = rmfield(handles.DATA, names{i});
end

% Update presentation tab
[handles] = mlepUpdateStartTab(handles);
% Update variable tab
[handles] = mlepUpdateVariableTab(handles);
% Update variable tab
[handles] = mlepUpdateSysIDTab(handles);
% Update control tab
[handles] = mlepUpdateControlTab(handles);
% Update simulate tab
[handles] = mlepUpdateSimulateTab(handles);

result = 1;

