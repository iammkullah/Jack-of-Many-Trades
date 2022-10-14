clc;clear all;
close all;
[x,fs]=audioread('C:\Users\iwill\Desktop\github\5_DSP audio DA\Denoising-via-Filter\input-audio.wav'); %reading the audio signal

t = [1/fs:1/fs:length(x)/fs];
figure(1)
stem(t,x)
title('Original Signal');
ylabel('Signal');
xlabel('Time');

OrigSize = size(x,1);
df = fs / OrigSize;
w = (-(OrigSize/2):(OrigSize/2)-1)*df;
x1 = fft(x(:,1), OrigSize) / OrigSize; % For normalizing, but not needed for our analysis
x2 = fftshift(x1);
figure(2);
plot(w,abs(x2));
title('Original Frequency Response');
ylabel('Signal');
xlabel('Frequency Hz ');

figure(10);
freqz(x,fs);
title({'Original','Magnitude & Phase'})
 
%-------------------------------------------------------------------------%

%StopBand1%
n = 1;%7
beginFreq = 1600 / (fs/2);
endFreq = 3500 / (fs/2);
[b a] = butter(n, [beginFreq, endFreq], 'stop');
fOut = filter(b, a, x);
x3 = fft(fOut(:,1), OrigSize) / OrigSize;
x4 = fftshift(x3);
figure(3);
subplot(2,1,1);
plot(w,abs(x2));
title('After First Band-Stop Filter');
ylabel('Signal');
xlabel('Frequency Hz ');

subplot(2,1,2);
plot(w,abs(x4));
ylabel('Signal');
xlabel('Frequency Hz ');


figure(4);
freqz(b,a);
title({'First Band-Stop Filter','Magnitude & Phase'})

%StopBand2%
n2 = 4;%3
beginFreq2 = 600 / (fs/2);%600
endFreq2 = 1000 / (fs/2);%900
[b2 a2] = butter(n2, [beginFreq2, endFreq2], 'stop');
fOut2 = filter(b2, a2, fOut);
x5 = fft(fOut2(:,1), OrigSize) / OrigSize;
x6 = fftshift(x5);

figure(5);
subplot(2,1,1);
plot(w,abs(x4));
title('After Second Band-Stop Filter');
ylabel('Signal');
xlabel('Frequency Hz ');
subplot(2,1,2);
plot(w,abs(x6))
ylabel('Signal');
xlabel('Frequency Hz ');


figure(6);
freqz(b2,a2)
title({'Second Band-Stop Filter','Magnitude & Phase'})

%HighPass Filter%

Fe2 = fs;
F = [0.0 0.28 0.3 0.5 0.52 1];
M = [0 0 1 1 0 0];
B2 = fir2(30, F,M);
[H2,W2] = freqz(B2,1,100,Fe2);

n3 = 2;
beginFreq3 = 250 / (fs/2);
[b3 a3] = butter(n3, beginFreq3, 'high');
fOut3 = filter(b3, a3, fOut2);
x7 = fft(fOut3(:,1)*100, OrigSize) / OrigSize;
x8 = fftshift(x7);

figure(7);
plot(w,abs(x8));
title('After High Pass Filter');
ylabel('Signal');
xlabel('Frequency Hz ');

figure(8);
freqz(b3,a3)
title({'High Pass Filter','Magnitude & Phase'})


t=[1/fs:1/fs:length(fOut3)/fs];
figure(9);
subplot(2,1,1);
stem(t,x)
title('Original Output');
ylabel('Signal');
xlabel('Time');
subplot(2,1,2);
stem(t,fOut3)
title('Final Output');
ylabel('Signal');
xlabel('Time');

p = audioplayer(fOut3, fs);%Playing the output audio 
play(p);

%In order to stop the audio ">>stop(p)" on to the command window