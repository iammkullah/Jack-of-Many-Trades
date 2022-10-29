clc % Clear the command window
close all; % Close all figures (except those of imtool.)
imtool close all; % Close all of imtool figure
clear; % Erase all existing variable
workspace; % Make sure the workspace panel is showing
fontSize = 12;
%C:\Program Files\MATLAB\R2018a\toolbox\images\imdata

% Read in the image what will have another image hidden into it
baseFileName='cameraman.tif';
%baseFileName='Cameraman.tif';
folder=fullfile(matlabroot,'\toolbox\images\imdemos');
% Get the full fileName, with path prepended
fullFileName=fullfile(folder,baseFileName);
if ~exist(fullFileName,'file')
% Didn't find it there. check the search path for it
fullFileName=baseFileName;
if ~exist(fullFileName,'file')
% Still didn't find it. Alert user
errorMessage=sprintf('Error: does not exist', fullFileName);
uiwait(warndlg(errorMessage));
return;
end
end
originalImage=imread(fullFileName);

%Get the number of row and column in the original image
[visibleRows,visibleColumns,numberOfColorChannels]=size(originalImage);
if numberOfColorChannels > 1
% If it's color, extract the image
originalImage=originalImage(:,:,1);
end

% Display the original gray scale image
subplot(3,2,3)
imshow(originalImage,[]);
title('Original Grayscale Starting Image','FontSize', fontSize);
% Enlarge figure to full screen
set(gcf,'units','normalized','outerposition',[0 0 1 1]);
set(gcf,'name','Demo by ImageAnalyst','numbertitle','off')

% Read the image message you want to hide in the cover image
baseFileName='moon.tif';
%%baseFileName='moon.tif';
% Get the full FileName with path pepended.
fullFileName=fullfile(folder,baseFileName);
if ~exist(fullFileName,'file')
% Didn't find it there. check the search path for it
fullFileName=baseFileName;
if ~exist(fullFileName,'file')
% Still didn't fint it. Alert the user
errorMessage=sprintf('Error: does not exist', fullFileName);
uiwait(warndlg(errorMessage));
return;
end
end
hiddenImage=imread(fullFileName);

%Get the number of row and column in the original image
[hiddenRows,hiddenColumns,numberOfColorChannels]=size(hiddenImage);
if numberOfColorChannels > 1
% If it's color, extract the red channel
hiddenImage-hiddenImage(:,:,1);
end

%Display the image that we want to hide
subplot(3,2,1);
imshow(hiddenImage,[]);
title('Image to be Hidden','FontSize',fontSize)

% the threshold is simply to generate a binary image to be hidden.
thresholdValue = 90;
binaryImage = hiddenImage < thresholdValue; % Now we have a binary image.
% Display the binary image.
subplot(3, 2, 2);
imshow(binaryImage, []);
caption = sprintf('Hidden Image Threshold at %d',thresholdValue);
title(caption, 'FontSize',fontSize);

% Get the bit plane to hide the binary image in.
% Since it's binary it can be storen in a single bit plane.
prompt = 'Enter the bit plane you want to hide the image in (1 - 8) ';
dialogTitle = 'Enter bit plane to replace';
numberOfLines = 1;
defaultResponse = {'6'};
bitToSet = str2double(cell2mat(inputdlg(prompt, dialogTitle, numberOfLines,defaultResponse)));
% If image to be hidden is bigger than the orignal image,scale it down.
if hiddenRows > visibleRows || hiddenColumns > visibleColumns
    amountToShrink = min([visibleRows / hiddenRows, visibleColumns / hiddenColumns]);
    binaryImage = imresize(binaryImage, amountToShrink);
    % Need to update the number of rows and columns.
    [hiddenRows, hiddenColumns] = size(binaryImage);
end

% Title the hiddenimage,if it's smaller, so that it will cover the orignal image.

if hiddenRows < visibleRows || hiddenColumns <  visibleColumns
    watermark = zeros(size(originalImage), 'uint8');
    for column = 1:visibleColumns
        for row = 1:visibleRows
            watermark(row, column) = binaryImage(mod(row,hiddenRows)+1, mod(column,hiddenColumns)+1);
        end
    end
    % Crop it to the same size as the orignal image.
    watermark = watermark(1:visibleRows, 1:visibleColumns);
else
    % Watermark is the same size as the orignal image.
    watermark = binaryImage;
end
% Display the threshold binaryImage - the watermark alone.
subplot(3, 2, 4);
imshow(watermark, []);
caption = sprintf('Hidden Image\nto be inserted into Bit Plane %d', bitToSet);
title(caption, 'FontSize', fontSize);

% Set the bit of orignalImage(a copy, actual) to the value of watermark.
watermarkedImage = originalImage; %Initialize
for column = 1 : visibleColumns
    for row = 1 : visibleRows
        watermarkedImage(row, column) = bitset(originalImage(row, column), bitToSet, watermark(row, column));
    end
end
% Display the final watermarked image.
subplot(3, 2, [5,6]);
imshow(watermarkedImage, []);
caption = sprintf('Final Watermarked Image');
title(caption, 'FontSize', fontSize);