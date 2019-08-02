#include "OpenCvUtils.hpp"

#include <iostream>
#include <vector>
#include <math.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

// Resize an image to a given size to
cv::Mat __resize_to_a_size(cv::Mat image, int newHeight, int newWidth) {
  	// get original image size
	int orgImageHeight = image.rows;
	int orgImageWidth = image.cols;
  	// get image area and resized image area
	float imgArea = float(orgImageHeight * orgImageWidth);
	float newArea = float(newHeight * newWidth);
  	// resize
	cv::Mat image_scaled;
	cv::Size scale(newWidth, newHeight);
	if (newArea >= imgArea) {
		cv::resize(image, image_scaled, scale, 0, 0, cv::INTER_LANCZOS4);
	} else {
		cv::resize(image, image_scaled, scale, 0, 0, cv::INTER_AREA);
	}
	return image_scaled;
}

// Normalize an image by subtracting mean and dividing by standard deviation
cv::Mat __normalize_mean_std(cv::Mat image, std::vector<double> mean, std::vector<double> std) {
  	// clone
	cv::Mat imageNormalized = image.clone();
  	// convert to float
	imageNormalized.convertTo(imageNormalized, CV_32FC3);
  	// subtract mean
	cv::subtract(imageNormalized, mean, imageNormalized);
  	// divide by standard deviation
	std::vector<cv::Mat> imgChannel(3);
	cv::split(imageNormalized, imgChannel);

	imgChannel[0] = imgChannel[0] / std[0];
	imgChannel[1] = imgChannel[1] / std[1];
	imgChannel[2] = imgChannel[2] / std[2];
	cv::merge(imgChannel, imageNormalized);
	return imageNormalized;  
}

// 1. Preprocess
cv::Mat preprocess(cv::Mat image, int newHeight, int newWidth, 
	std::vector<double> mean, std::vector<double> std) {
  	// Clone
	cv::Mat imageProc = image.clone();
  	// Convert from BGR to RGB
	cv::cvtColor(imageProc, imageProc, cv::COLOR_BGR2RGB);
  	// Resize image
	imageProc = __resize_to_a_size(imageProc, newHeight, newWidth);	
  	// Convert image to float
	imageProc.convertTo(imageProc, CV_32FC3);
  	// 3. Normalize to [0, 1]
	imageProc = imageProc / 255.0;
  	// 4. Subtract mean and divide by std
	imageProc = __normalize_mean_std(imageProc, mean, std);
	return imageProc;
}
