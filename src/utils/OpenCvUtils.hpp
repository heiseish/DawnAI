#pragma once

#ifndef OPENCVUTILS_H 
#define OPENCVUTILS_H

#include <iostream>
#include <vector>
#include <math.h>

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>


cv::Mat preprocess(cv::Mat, int, int, std::vector<double>, std::vector<double>);

#endif
