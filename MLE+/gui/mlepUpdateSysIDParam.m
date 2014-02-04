function [handles] = mlepUpdateSysIDParam(handles)

% Update parameters to index
if isfield(handles.DATA,'sysIDinputIndex')
    index = handles.DATA.sysIDinputIndex;
    if isfield(handles.DATA,'sysIDinputParam')
        if ~isempty(handles.DATA.sysIDinputParam)
            set(handles.sysIDeditConrolStep,'String',num2str(handles.DATA.sysIDinputParam{index,1}));
            %if isempty(handles.DATA.sysIDinputParam{index,2})
            %handles.DATA.sysIDinputParam{index,2} = 1;
            %end
            set(handles.sysIDpopupType,'Value',handles.DATA.sysIDinputParam{index,2});
            set(handles.sysIDeditWlow,'String',num2str(handles.DATA.sysIDinputParam{index,3}));
            set(handles.sysIDeditWhigh,'String',num2str(handles.DATA.sysIDinputParam{index,4}));
            set(handles.sysIDeditMinu,'String',num2str(handles.DATA.sysIDinputParam{index,5}));
            set(handles.sysIDeditManu,'String',num2str(handles.DATA.sysIDinputParam{index,6}));
            set(handles.sysIDeditScale,'String',num2str(handles.DATA.sysIDinputParam{index,7}));
%             set(handles.sysIDselectSignal,'String',num2str(handles.DATA.sysIDinputParam{index,8}));
%             set(handles.sysIDcheck,'Value',handles.DATA.sysIDinputParam{index,9});
%             
        end
    end
end
end