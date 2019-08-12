#pragma once

#ifndef IMAGEUTILS_H 
#define IMAGEUTILS_H

#include <iostream>
#include <vector>
#include <math.h>

#include <curl/curl.h>  // has to go before opencv headers

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


namespace dawn {
	bool preprocess(cv::Mat, int, int, std::vector<double>, std::vector<double>, cv::Mat&);
	bool download(const char* img_url, cv::Mat& output, int timeout=10);
}


#endif
