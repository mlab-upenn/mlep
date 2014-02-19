[a b c] = mlepLoadEPResults('RefBldgLargeOfficeNew2004_Chicago.csv');

fan = b(:,1)+b(:,2)+b(:,3)+b(:,4);
ch1 = b(:,5);
ch2 = b(:,6);
tow = b(:,7);
chp = b(:,8);
cnp = b(:,9);
time = 1:size(c,1);
figure;plot(time, fan, 'b', time, ch1+ch2,'r',time,tow,'m',time,chp,'c',time,cnp,'k')
legend('Fan','Chiller','Tower','Chiller Pump','Condenser Pump');



