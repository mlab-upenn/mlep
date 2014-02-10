function [eplus_in_curr,userdata] = controlFile(cmd,eplus_out_prev, eplus_in_prev, time, stepNumber, userdata) 
% ---------------FUNCTION INPUTS---------------

% INPUTS TO ENERGYPLUS
% eplus_in_prev - Data Structure with all previous inputs
% 	eplus_in_curr.Troom = ; 

% OUTPUTS FROM ENERGYPLUS 
% eplus_out_prev - Data Structure with all previous outpus
% 	eplus_out_curr.Tout = ; 

% OTHER INPUTS
% cmd  - MLE+ Command to distinguish init or normal step
% userdata  - user defined variable which can be changed and evolved
% time - vector with timesteps
% stepNumber - Number of Time Step in the simulation (Starts at 1)

% ---------------FUNCTION OUTPUTS---------------
% eplus_in_curr - vector with the values of the input parameters.
% This should be a 1xn vector where n is number of eplus_in parameters
% userdata - user defined variable which can be changed and evolved

if strcmp(cmd,'init')
	% ---------------WRITE YOUR CODE---------------
	% Initialization mode. This part sets the
	% input parameters for the first time step.
	 eplus_in_curr.CoolTemp = 22; 
	 eplus_in_curr.HeatTemp = 20; 
	 eplus_in_curr.SatTemp = 12.8; 
	 eplus_in_curr.ChWTemp = 6.7; 
elseif strcmp(cmd,'normal') 
	% ---------------WRITE YOUR CODE---------------
	% Normal mode. This part sets the input 
	% parameters for the subsequent time steps.
	 eplus_in_curr.CoolTemp = 22; 
	 eplus_in_curr.HeatTemp = 20; 
	 eplus_in_curr.SatTemp = 12.8; 
	 eplus_in_curr.ChWTemp = 6.7; 
end
end
