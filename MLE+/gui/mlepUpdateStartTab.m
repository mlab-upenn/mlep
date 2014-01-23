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
if isfield(handles.DATA,'runPeriod')
    % Begin Month
    if ~isfield(handles.DATA.runPeriod,'BeginMonth')
        set(handles.Start_BeginMonthEdit,'string','');
    else
        set(handles.Start_BeginMonthEdit,'string',handles.DATA.runPeriod.BeginMonth);
    end
    
    % End Month
    if ~isfield(handles.DATA.runPeriod,'EndMonth')
        set(handles.Start_EndMonthEdit,'string','');
    else
        set(handles.Start_EndMonthEdit,'string',handles.DATA.runPeriod.EndMonth);
    end
    
    % Begin Day
    if ~isfield(handles.DATA.runPeriod,'BeginDay')
        set(handles.Start_BeginDayEdit,'string','');
    else
        set(handles.Start_BeginDayEdit,'string',handles.DATA.runPeriod.BeginDay);
    end
    
    % End Day
    if ~isfield(handles.DATA.runPeriod,'EndDay')
        set(handles.Start_EndDayEdit,'string','');
    else
        set(handles.Start_EndDayEdit,'string',handles.DATA.runPeriod.EndDay);
    end
end

% Time Step
if ~isfield(handles.DATA,'timeStep')
    set(handles.Start_TimeStepEdit,'string','');
else
    set(handles.Start_TimeStepEdit,'string',handles.DATA.timeStep);
end

end




