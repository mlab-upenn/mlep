% INSTALLMLEP code to install MLE+
%      Run this script before using MLE+.
%
%      Use: installMlep
%
%      In installMlep you need to specify whether you want to use the GUI
%      mode or the Manual mode. Set manualInstall = 0 if you do not want to
%      use the GUI for installation.
%      GUI (manualInstall = 1): A installation screen will pop up according
%      to your operating system (PC or UNIX)
%      MANUAL (manualInstall = 0): You need to specify the E+ and Java
%      directory for Windows machines and only the E+ directory for UNIX
%      systems.
%
%      if ispc
%           % Windows
%           eplusPath = 'C:\EnergyPlusV8-0-0';
%           javaPath = 'C:\Program Files\Java\jre7\bin\';
%      else
%           % Unix
%           eplusPath = '/Applications/EnergyPlus-8-0-0';
%      end

% Last Modified by Willy Bernal willyg@seas.upenn.edu 30-Jul-2013 16:29:59

%% MODIFY
% 1 = Install Manually
% 0 = Install through GUI
manualInstall = 1;

% Paths
if ispc
    % Windows
    eplusPath = 'C:\EnergyPlusV8-0-1';
    javaPath = 'C:\Program Files (x86)\Java\jre7\bin';
else
    % Unix
    eplusPath = '/Applications/EnergyPlus-8-0-0';
end

%% DO NOT MODIFY
% Extract MLE+ Main Path
filename = mfilename('fullpath');
[mlepPath, ~, ~] = fileparts(filename);

% Add main/core/gui/bcvtb Path
addpath(mlepPath);
addpath([mlepPath filesep 'core']);
addpath([mlepPath filesep 'gui']);
addpath([mlepPath filesep 'bcvtb']);
addpath([mlepPath filesep 'install']);
%addpath([mlepPath filesep 'settings']);
addpath([mlepPath filesep 'version']);
addpath([mlepPath filesep 'mlepHelp']);
bcvtbPath = [mlepPath filesep 'bcvtb'];

% Installation Dialog
if ~manualInstall
    if ispc
        % WIN
        installationWin;
    else
        % UNIX
        installationUnix;
    end
else
    % Manual Install
    if ispc
        % Rename RunEPlus.bat to RunEPlus_orig.bat
        [status1,message,messageid] = copyfile([eplusPath filesep 'RunEPlus.bat'] ,[eplusPath filesep 'RunEPlus_orig.bat'], 'f');
        
        % Copy RunEPlus.bat
        [status2,message,messageid] = copyfile([mlepPath filesep 'settings' filesep 'RunEPlus.bat'] ,[eplusPath filesep 'RunEPlus.bat'], 'f');
        
        % Check Whether Replacing RunEPlus was successfull
        status = status1 && status2;
        if ~status
            disp('ERROR: CHECK E+ PATHS AND JAVA PATHS');
            disp(message);
            disp(messageid);
        else
            disp('INSTALLATION COMPLETED!');
        end
    end
    
    % Java Path
    if ~ispc
        javaPath = '';
    end
    mlepSaveSettings(mlepPath, eplusPath, javaPath, bcvtbPath);
end

% Save Paths
savepath;


