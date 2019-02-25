#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

//########
//UNTESTED
//########
static int lum_quant[8][8] = {
        {16, 11, 10, 16, 24, 40, 51, 61},
        {12, 12, 14, 19, 26, 58, 60, 55},
        {14, 13, 16, 24, 40, 57, 69, 56},
        {14, 17, 22, 29, 51, 87, 80, 62},
        {18, 22, 37, 56, 68,109,103, 77},
        {24, 35, 55, 64, 81,104,113, 92},
        {49, 64, 78, 87,103,121,120,101},
        {72, 92, 95, 98,112,100,103, 99}
        };

static int chr_quant[8][8] = {
        {17,18,24,47,99,99,99,99},
        {18,21,26,66,99,99,99,99},
        {24,26,56,99,99,99,99,99},
        {47,99,99,99,99,99,99,99},
        {99,99,99,99,99,99,99,99},
        {99,99,99,99,99,99,99,99},
        {99,99,99,99,99,99,99,99},
        {99,99,99,99,99,99,99,99}
        };

//prefroms dct on a n x m matric returns an nx m matric of ints that are the dct fourm
cv::Mat1d dct(cv::Mat1b &block);

//reverses the dct matrix returns in unsigned char
cv::Mat1b idct(cv::Mat1d &block);

void quant(cv::Mat block, int q[8][8], double scale );
void iquant(cv::Mat block, int q[8][8], double scale );
//########
//HALF TESTED
//########
//converts a 3 byte rgb pixel to yub
cv::Vec3b rgb2yuv(cv::Vec3b pixel);

//converts a cv image from rgb to yuv //this cant be an mat3b or 3s leave it as mat took me an hour to find this bug lol
void rgb2yuv(cv::Mat &img);

//converta a yub pixel to rgb //has to be unsigned
cv::Vec3b yuv2rgb(cv::Vec3b pixel);

//converts a yuv cv img to rgb
void yuv2rgb(cv::Mat &img);

void chroma_subsample(cv::Mat &img, int a=4, int b=2, int c=0);

//######
//TESTED
//######
