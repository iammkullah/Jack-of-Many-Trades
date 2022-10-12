<h1>Denoising Audio Signals Using Filters</h1>
<p>Importance of noise reduction in real time audio signals is said to be having high significance in communication. Noise weakens the signal quality. A well-established method is filtering of the signal in the frequency domain or in the simplest way which is analysing the signal using different filter techniques like low pass, high pass and bandpass filters.<br><br>
A Fourier transform of a signal gives us the frequency composition of the audio signal. Here, through this challenging experiment I’ll be laying out the procedure I followed to denoise an audio signal which is a commentary during a football match having noise in the background.
</p>

```matlab
%StopBand1%

n = 1;%7
beginFreq = 1600 / (fs/2);
endFreq = 3500 / (fs/2);
[b a] = butter(n, [beginFreq, endFreq], 'stop');
fOut = filter(b, a, x);
x3 = fft(fOut(:,1), OrigSize) / OrigSize;
x4 = fftshift(x3);

```

<p><b>Using Bandstop filter again for another range of frequency as was observed from the frequency plot of the original audio signal</b></p>

```matlab
%StopBand2%

n2 = 4;%3
beginFreq2 = 600 / (fs/2);%600
endFreq2 = 1000 / (fs/2);%900
[b2 a2] = butter(n2, [beginFreq2, endFreq2], 'stop');
fOut2 = filter(b2, a2, fOut);
x5 = fft(fOut2(:,1), OrigSize) / OrigSize;
x6 = fftshift(x5);

```

<p><b>Using High pass filter for attenuating low frequencies</b></p>

```matlab
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

```

<h2>Problems Faced and Yet to be Rectified</h2>
<ol>
  <li>Even after using stop band and high pass filter, I was still getting some amount of noise in my output signal</li>
  <li>It was really easy yet difficult at the same time to know which range of frequency to be altered. Though I still think if the frequencies are still altered, I could achieve much better results.</li>
  <li>The selection of audio signal played a vital role since initially I went for my own audio signal but due to some reason, I wasn’t able to rectify the following error</li>
</ol>
<br>
<p><b><i>:star: Feel free to contribute to the repository with your own version of audio processing techniques</i></b><p>
