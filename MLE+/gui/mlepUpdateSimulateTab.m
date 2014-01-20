function [handles] = mlepUpdateSimulateTab(handles)

% Variable Listbox
if ~isfield(handles.DATA,'Simulation_VariableListbox')
    set(handles.Simulation_VariableListbox,'string','Variables');
else
    set(handles.Simulation_VariableListbox,'string',handles.DATA.simulateListboxText);
end

% Axis 
cla(handles.Simulation_GraphAxes,'reset');
% cla(handles.dxfAxes,'reset');
end


