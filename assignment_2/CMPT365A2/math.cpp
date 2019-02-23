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

    cv::Vec3d yuv;

    //yuv[0]  = pixel.ddot(dWeights_rgb2yuv.row(0).t());
    //yuv[1]  = pixel.ddot(dWeights_rgb2yuv.row(1).t());
    //yuv[2]  = pixel.ddot(dWeights_rgb2yuv.row(2).t());
    yuv = dWeights_rgb2yuv* (cv::Vec3d)pixel;
    //clamps values to byte range
    for(int i=0; i<3; i++){
        if (yuv[i]<0) yuv[i]=0;
        else if(yuv[i]>255) yuv[i] = 255;
    }
    return (cv::Vec3b)yuv;
}

void rgb2yuv(cv::Mat &img){

    for(int i=0; i<img.rows; i++){
        for (int j=0; j<img.cols; j++) {
            img.at<cv::Vec3b>(i,j) = rgb2yuv(img.at<cv::Vec3b>(i,j));
        }
    }

    return ;
}

cv::Vec3b yuv2rgb(cv::Vec3b pixel){

    cv::Vec3d rgb;

//    rgb[0]  = pixel.cross(dWeights_yuv2rgb.row(0).t());
//    rgb[1]  = pixel.ddot(dWeights_yuv2rgb.row(1).t());
//    rgb[2]  = pixel.ddot(dWeights_yuv2rgb.row(2).t());
    rgb = dWeights_yuv2rgb * (cv::Vec3d)pixel; // * is matric multiplication and .mul() is element multiplication
    //clamps values to byte range
    for(int i=0; i<3; i++){
        if (rgb[i]<0) rgb[i]=0;
        else if(rgb[i]>255) rgb[i] = 255;
    }
    return (cv::Vec3b)rgb;
}

void yuv2rgb(cv::Mat &img){

    for(int i=0; i<img.rows; i++){
        for (int j=0; j<img.cols; j++) {
            img.at<cv::Vec3b>(i,j) = yuv2rgb(img.at<cv::Vec3b>(i,j));
        }
    }
    return;
}


void chroma_subsample(cv::Mat &img, int a, int b, int c) {

    int even_smpl_w = a/b;
    int odd_smpl_w = 0;
    if(c != 0){
      odd_smpl_w = a/c;
    }

    for(int i=0; i<img.rows; i++){
        if(i%2 == 0) { //even lines
            for (int j=0; j<img.cols; j+=even_smpl_w) {
                for(int k = 1; k<even_smpl_w; k++){
                    //make smpl with pixels the same by coping the first wone to the
                    //next width-1 pixels
                    if(j+k !=img.cols ) {
                        img.at<cv::Vec3b>(i,j+k)[1] = img.at<cv::Vec3b>(i,j)[1];
                        img.at<cv::Vec3b>(i,j+k)[2] = img.at<cv::Vec3b>(i,j)[2];
                    }
                }
            }
        } else { //odd lines
            if(odd_smpl_w == 0) {
                for (int j=0; j<img.cols; j++) {
                    //copy croma of pixel above
                    img.at<cv::Vec3b>(i,j)[1] = img.at<cv::Vec3b>(i-1,j)[1];
                    img.at<cv::Vec3b>(i,j)[2] = img.at<cv::Vec3b>(i-1,j)[2];
                }
            } else {
                for (int j=0; j<img.cols; j+=odd_smpl_w) {
                    for(int k = 1; k<odd_smpl_w; k++){
                        //make smpl with pixels the same by coping the first wone to the
                        //next width-1 pixels
                        if(j+k !=img.cols ) {
                            img.at<cv::Vec3b>(i,j+k)[1] = img.at<cv::Vec3b>(i,j)[1];
                            img.at<cv::Vec3b>(i,j+k)[2] = img.at<cv::Vec3b>(i,j)[2];
                        }
                    }
                }
            }
        }
    }
}
