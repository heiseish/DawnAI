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

/**
 * @brief contain some basic image processing functions
 */ 
class ImageUtil {
public:
    static bool Preprocess(
        cv::Mat& preprocessedImage, 
        cv::Mat image, 
        int imageHeight = 224, 
        int imageWidth = 224, 
        std::vector<double> mean={0.485, 0.456, 0.406}, 
        std::vector<double> std={0.229, 0.224, 0.225}
    );
	static bool Download(cv::Mat& output, const char* img_url, int timeout=10);
private:
    ImageUtil() { } // prevent instantiate
};
	
}


#endif
