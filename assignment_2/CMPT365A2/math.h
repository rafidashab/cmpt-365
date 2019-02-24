#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#define pi 3.142857
//########
//UNTESTED
//########

//prefroms dct on a n x m matric returns an nx m matric of ints that are the dct fourm
cv::Mat1d dct(cv::Mat1b &block);

//reverses the dct matrix returns in unsigned char
cv::Mat1b idct(cv::Mat1d &block);

//########
//HALF TESTED
//########
//converts a 3 byte rgb pixel to yub
cv::Vec3b rgb2yuv(cv::Vec3b pixel);

//converts a cv image from rgb to yuv
void rgb2yuv(cv::Mat3b &img);

//converta a yub pixel to rgb
cv::Vec3b yuv2rgb(cv::Vec3b pixel);

//converts a yuv cv img to rgb
void yuv2rgb(cv::Mat &img);

void chroma_subsample(cv::Mat &img, int a=4, int b=2, int c=0);

//######
//TESTED
//######
