#include "ImageUtils.hpp"

#include <curl/curl.h> // has to go before opencv headers

#include <iostream>
#include <vector>
#include <math.h>



#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

namespace dawn {
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
bool preprocess(cv::Mat image, int newHeight, int newWidth, 
	std::vector<double> mean, std::vector<double> std, cv::Mat& output) {
	// Clone
	output = image.clone();
	// Convert from BGR to RGB
	cv::cvtColor(output, output, cv::COLOR_BGR2RGB);
	// Resize image
	output = __resize_to_a_size(output, newHeight, newWidth);	
	// Convert image to float
	output.convertTo(output, CV_32FC3);
	// 3. Normalize to [0, 1]
	output = output / 255.0;
	// 4. Subtract mean and divide by std
	output = __normalize_mean_std(output, mean, std);

	return true;
}

//curl writefunction to be passed as a parameter
// we can't ever expect to get the whole image in one piece,
// every router / hub is entitled to fragment it into parts
// (like 1-8k at a time),
// so insert the part at the end of our stream.
size_t write_data(char *ptr, size_t size, size_t nmemb, void *userdata) {
    std::vector<char> *stream = (std::vector<char>*)userdata;
    size_t count = size * nmemb;
    stream->insert(stream->end(), ptr, ptr + count);
    return count;
}

//function to retrieve the image as cv::Mat data type
bool download(const char *img_url, cv::Mat& output, int timeout) {
    std::vector<char> stream;
    CURL *curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, img_url); //the img url
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // pass the writefunction
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &stream); // pass the stream ptr to the writefunction
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, timeout); // timeout if curl_easy hangs, 
    CURLcode res = curl_easy_perform(curl); // start curl
	if (res != CURLE_OK) {
		return false;
	}
    curl_easy_cleanup(curl); // cleanup
    output =  cv::imdecode(stream, 1); // 'keep-as-is'
	// curl_global_cleanup();
	return !output.empty();
}

}

