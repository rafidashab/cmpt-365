#include "math.h"

static cv::Matx33d dWeights_rgb2yuv(
            0.299,      0.587,      0.114,
            -0.14713,   -0.28886,   0.436,
            0.615,      -0.51499,   -0.10001
        );

static cv::Matx33d dWeights_yuv2rgb(
            1,  0,          1.13983,
            1,  -0.39465,   -0.58060,
            1,  2.03211,    0
        );



cv::Vec3b rgb2yuv(cv::Vec3b pixel){

    cv::Vec3b yuv;

    yuv[0]  = pixel.dot(dWeights_rgb2yuv.row(0).t());
    yuv[1]  = pixel.dot(dWeights_rgb2yuv.row(2).t());
    yuv[2]  = pixel.dot(dWeights_rgb2yuv.row(3).t());

    return yuv;
}

cv::Mat rgb2yuv(cv::Mat img){
    cv::Mat out;
    out.create(img.size(), CV_8U);

    for(int i=0; i<img.rows; i++){
        for (int j=0; j<img.cols; j++) {
            out.at<cv::Vec3b>(i,j) = rgb2yuv(img.at<cv::Vec3b>(i,j));
        }
    }

    return out;
}

cv::Vec3b yuv2rgb(cv::Vec3b pixel){

    cv::Vec3b rgb;

    rgb[0]  = pixel.dot(dWeights_yuv2rgb.row(0).t());
    rgb[1]  = pixel.dot(dWeights_yuv2rgb.row(2).t());
    rgb[2]  = pixel.dot(dWeights_yuv2rgb.row(3).t());

    return rgb;
}

cv::Mat yuv2rgb(cv::Mat img){
    cv::Mat out;
    out.create(img.size(), CV_8U);

    for(int i=0; i<img.rows; i++){
        for (int j=0; j<img.cols; j++) {
            out.at<cv::Vec3b>(i,j) = yuv2rgb(img.at<cv::Vec3b>(i,j));
        }
    }
    return out;
}
