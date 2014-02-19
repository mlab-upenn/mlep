% Description
% Regular Campus Operation

% Load Input Files 
ChillerInput = load('ChillerInput.mat');
ChillerOutput = load('ChillerOutput.mat');
Office1Input = load('Office1Input.mat');
Office1Output = load('Office1Output.mat');
HospitalInput = load('HospitalInput.mat');
HospitalOutput = load('HospitalOutput.mat');
Office2Input = load('Office2Input.mat');
Office2Output = load('Office2Output.mat');
TotalPower = load('TotalPower.mat');

% Assign 
time =  ChillerOutput.ans.Time; 

% Power
figure(1);plot(time,ChillerOutput.ans.Data(:,2),'r');
grid on;
figure(2);plot(time,TotalPower.ans.Data(:,1),'r',time,TotalPower.ans.Data(:,2),'b',time,TotalPower.ans.Data(:,3),'k');
grid on;
figure(3);plot(time,TotalPower.ans.Data(:,4),'r',time,TotalPower.ans.Data(:,5),'b',time,TotalPower.ans.Data(:,6),'m');
grid on;

% PPD TEMP
figure(4);plot(time,Office1Output.ans.Data(:,13),'r',time,Office2Output.ans.Data(:,13),'b',time,Office1Output.ans.Data(:,7),'r--',time,Office2Output.ans.Data(:,7),'b--');
grid on;


% SP 






