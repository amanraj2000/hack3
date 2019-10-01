close all;
clear all;
clc
pkg load image;
CIm=imread('aman_jee.jpg'); % To read image
f=rgb2gray(CIm);    % To convert RGB to Grayimage
figure,imshow(f);
title('Original Image');

% Noise addition with original image
NIm=imnoise(f,'gaussian');   % Adding Gaussian noise to image
figure,imshow(NIm);
title('Noisy Image(Gaussian Noise)');   