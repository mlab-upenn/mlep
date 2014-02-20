% Description
% Regular Campus Operation
close all;

%% Load Input Files 
ChillerInput = load('ChillerInput.mat');
ChillerOutput = load('ChillerOutput.mat');
Office1Input = load('Office1Input.mat');
Office1Output = load('Office1Output.mat');
HospitalInput = load('HospitalInput.mat');
HospitalOutput = load('HospitalOutput.mat');
Office2Input = load('Office2Input.mat');
Office2Output = load('Office2Output.mat');
TotalPower = load('TotalPower.mat');
Setpoint = load('Setpoint.mat');

% Assign 
time =  ChillerOutput.ans.Time; 

%% Power
tOut = ChillerOutput.ans.Data(:,1);

chi1Power = ChillerOutput.ans.Data(:,2);
chi2Power = ChillerOutput.ans.Data(:,3);

chiPumpPower = ChillerOutput.ans.Data(:,11);
cndPumpPower = ChillerOutput.ans.Data(:,12);
towPower = ChillerOutput.ans.Data(:,13);

totPower = TotalPower.ans.Data(:,1);
hvacPower = TotalPower.ans.Data(:,2);
nonhvacPower = TotalPower.ans.Data(:,3);

off1Power = TotalPower.ans.Data(:,4);
hospPower = TotalPower.ans.Data(:,5);
off2Power = TotalPower.ans.Data(:,6);

hvacOff1 = Office1Output.ans.Data(:,2);
nonHvacOff1 = Office1Output.ans.Data(:,1);
hvacHosp = HospitalOutput.ans.Data(:,2);
nonHvacHosp = HospitalOutput.ans.Data(:,1);
hvacOff2 = Office2Output.ans.Data(:,2);
nonHvacOff2 = Office2Output.ans.Data(:,1);

figure;plot(time,totPower,'r',time,hvacPower,'b',time,nonhvacPower,'k');
grid on;
title('Campus Power');
legend('Total Power [W]','HVAC Power [W]','Non-HVAC Power [W]');

figure;plot(time,off1Power,'r',time,hospPower,'b',time,off2Power,'m');
grid on;
title('Buildings Power');
legend('Office 1 Power [W]','Hospital Power [W]','Office 2Power [W]');

figure;plot(time,chi1Power+chi2Power,'r',time,chiPumpPower,'b',time,cndPumpPower,'m',time,towPower,'k',time,hvacOff1+hvacHosp+hvacOff2,'c'); % ,time,hvacOff1,'k',time,hvacHosp,'k',time,hvacOff2,'k' 
grid on;
title('HVAC Power');
legend('Chiller [W]','Chilled Water Pump [W]','Condenser Water Pump [W]','Condenser Water Pump [W]','Fan [W]');

figure;plot(time,hvacOff1,'r',time,nonHvacOff1,'r-',time,hvacHosp,'b',time,nonHvacHosp,'b--',time,hvacOff2,'m',time,nonHvacOff2,'m-');
grid on;
title('Building Loads');
legend('Office 1 HVAC [W]','Office 1 non-HVAC [W]','Hospital HVAC [W]','Hospital non-HVAC [W]','Office 2 HVAC [W]','Office 2 non-HVAC [[W]');

%% SP 
RoomCool1 = reshape(Setpoint.ans.Data(:,1,:),1,length(time));
Sat1 = reshape(Setpoint.ans.Data(:,3,:),1,length(time));
RoomCool2 = reshape(Setpoint.ans.Data(:,4,:),1,length(time));
Sat2 = reshape(Setpoint.ans.Data(:,6,:),1,length(time));
ChWTemp1 = reshape(Setpoint.ans.Data(:,7,:),1,length(time));

figure;plot(time,RoomCool1,'r',time,Sat1,'b',time,ChWTemp1,'m');
legend('Room Cool SP [C]','SAT SP [C]','Chilled Water SP [C]');
grid on;


%% PPD TEMP
TempOff1 = Office1Output.ans.Data(:,13);
TempOff2 = Office2Output.ans.Data(:,13);
PPDOff1 = Office1Output.ans.Data(:,7);
PPDOff2 = Office2Output.ans.Data(:,7);

figure;plot(time,TempOff1,'r',time,TempOff2,'b',time,PPDOff1,'r--',time,PPDOff2,'b--');
legend('Ave. Temp. Office 1 [2]','Ave. Temp. Office 2 [C]','PPD Office 1 [%]','PPD Office 2 [%]');
grid on;

%% SP 






