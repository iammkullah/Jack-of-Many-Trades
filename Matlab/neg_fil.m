clc
clear all 
close all
n=7
% for i=1:n
%     amp(i)=input('enter amp')
% end
amp=[1 2 3 4 5 6 7]
fc1=3
fc2=6

amp1=amp(1,[1:fc1])
amp2=zeros(1,fc2-fc1-1)
amp3=amp(1,[fc2:n])

amp4=[amp1 amp2 amp3]
% t=1:length(amp4)
t=-6:0%just time axis is changed at the end
stem(t,amp4)