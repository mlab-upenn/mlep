function [handles] = mlepUpdateStartTab(handles)
% EnergyPlus edit
if ~isfield(handles.DATA,'idfFile')
    set(handles.Start_FilenameEdit,'string','EnergyPlus File');
else
    set(handles.Start_FilenameEdit,'string',handles.DATA.idfFile);
end
% Weather edit
if ~isfield(handles.DATA,'Weather')
    set(handles.Start_WeatherEdit,'string','Weather File');
else
    set(handles.Start_WeatherEdit,'string',handles.DATA.Weather);
end

% RunPeriod
% Begin Month
if ~isfield(handles.DATA,'Start_BeginMonthEdit')
    set(handles.Start_BeginMonthEdit,'string','');
else
    set(handles.Start_BeginMonthEdit,'string',handles.DATA.temp.runPeriod.BeginMonth);
end
% End Month
if ~isfield(handles.DATA,'Start_EndMonthEdit')
    set(handles.Start_EndMonthEdit,'string','');
else
    set(handles.Start_EndMonthEdit,'string',handles.DATA.temp.runPeriod.EndMonth);
end
% Begin Day
if ~isfield(handles.DATA,'Start_BeginDayEdit')
    set(handles.Start_BeginDayEdit,'string','');
else
    set(handles.Start_BeginDayEdit,'string',handles.DATA.temp.runPeriod.BeginDay);
end
% End Day 
if ~isfield(handles.DATA,'Start_EndDayEdit')
    set(handles.Start_EndDayEdit,'string','');
else
    set(handles.Start_EndDayEdit,'string',handles.DATA.temp.runPeriod.EndDay);
end

% Time Step
if ~isfield(handles.DATA,'Start_EndDayEdit')
    set(handles.Start_TimeStepEdit,'string','');
else
    set(handles.Start_TimeStepEdit,'string',handles.DATA.temp.timeStep);
end

end




