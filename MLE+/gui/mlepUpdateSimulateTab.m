function [handles] = mlepUpdateSimulateTab(handles)

% Variable Listbox
if ~isfield(handles.DATA,'Simulation_VariableListboxText')
    set(handles.Simulation_VariableListbox,'string','Variables');
    handles.DATA.Simulation_VariableListboxValue = 1;
    set(handles.Simulation_VariableListbox,'value', handles.DATA.Simulation_VariableListboxValue);
else
    set(handles.Simulation_VariableListbox,'string',handles.DATA.simulateListboxText);
%     handles.DATA.Simulation_VariableListboxValue
end

% Accept Time Out
if ~isfield(handles.DATA,'AcceptTimeOut')
    set(handles.timeOut,'string','Time Out');
else
    set(handles.timeOut,'string',handles.DATA.AcceptTimeOut);
end

% Axis 
cla(handles.Simulation_GraphAxes,'reset');
% cla(handles.dxfAxes,'reset');
end


