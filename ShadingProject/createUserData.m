function createUserData
% CREATEUSERDATA - This function creates userdata.mat file that you need to
% upload to the MLE+ shading project. 
% 
% Usage: createUserData
%
% (C) 2013 by Willy Bernal (willyg@seas.upenn.edu)

% HISTORY:
%   2013-08-07 Checks ExternalInterface Object.
%

% Create userdata structure. 
% Please refer to EnergyPlus Documentation for Shading Actuator. 
userdata = struct;
userdata.Shade_Status_None = - 1;
userdata.Shade_Status_Off = 0.0;
userdata.Shade_Status_Interior_Shade_On = 1.0;
userdata.Shade_Status_Switchable_Dark = 2.0;
userdata.Shade_Status_Exterior_Shade_On = 3.0;
userdata.Shade_Status_Interior_Blind_On = 6.0;
userdata.Shade_Status_Exterior_Blind_On = 6.0;
userdata.Shade_Status_Between_Glass_Shade_On = 8.0;
userdata.Shade_Status_Between_Glass_Blind_On = 9.0;

% Save userdata
save('userData.mat', 'userdata');
end
