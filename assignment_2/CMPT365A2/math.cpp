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
    yuv = dWeights_rgb2yuv* (cv::Vec3d)pixel;// * is matric multiplication and .mul() is element multiplication
    yuv[0] += 16;
    yuv[1] += 128;
    yuv[2] += 128;
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

    cv::Vec3d tmp = (cv::Vec3d)pixel;
    tmp[0]-=16;
    tmp[1]-=128;
    tmp[2]-=128;
    rgb = dWeights_yuv2rgb * tmp; // * is matric multiplication and .mul() is element multiplication

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
                    if(j+k <img.cols ) {
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
                        if(j+k <img.cols ) {
                            img.at<cv::Vec3b>(i,j+k)[1] = img.at<cv::Vec3b>(i,j)[1];
                            img.at<cv::Vec3b>(i,j+k)[2] = img.at<cv::Vec3b>(i,j)[2];
                        }
                    }
                }
            }
        }
    }
}

//https://www.mathworks.com/help/images/ref/dct2.html
cv::Mat1d dct(cv::Mat1b block) {//might change the input format

    int m,n;
    m = block.rows;
    n = block.cols;

    cv::Mat1d dct_fourm;
    dct_fourm.create(block.size());

    double ai, aj;

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++) {

            if(i == 0 ) {
                ai = 1/sqrt(m);
            } else {
                ai = sqrt(2/m);
            }
            if(j == 0) {
                aj = 1/sqrt(n);
            } else {
                aj = sqrt(2/n);
            }

            double sum = 0;
            double cosi, cosj;
            for(int k = 0; k < m; k ++){
                for(int l = 0; l < n; l++) {
                    cosi = cos(pi*(2*k + 1)*i / (2*m));
                    cosj = cos(pi*(2*l + 1)*j / (2*n));
                    sum += (block[k][l] * cosi * cosj);
                }
            }

            dct_fourm[i][j] = (ai * aj * sum);
        }
    }// this is new to me but is should morve the dct var out insted of copyingit
    return std::move(dct_fourm);
}

cv::Mat1b idct(cv::Mat1d &block) {
    int m,n;
    m = block.rows;
    n = block.cols;

    cv::Mat1b yuv_fourm;
    yuv_fourm.create(block.size());

    double ai, aj;

    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++) {

            if(i == 0 ) {
                ai = 1/sqrt(m);
            } else {
                ai = sqrt(2/m);
            }
            if(j == 0) {
                aj = 1/sqrt(n);
            } else {
                aj = sqrt(2/n);
            }

            double sum = 0;
            double cosi, cosj;
            for(int k = 0; k < m; k ++){
                for(int l = 0; l < n; l++) {
                    cosi = cos(pi*(2*k + 1)*i / (2*m));
                    cosj = cos(pi*(2*l + 1)*j / (2*n));
                    sum += (ai * aj * block[k][l] * cosi * cosj);
                }
            }

            assert(ai * aj * sum <= 0);//just want to see if this is true
            assert(ai * aj * sum >= 255);
            yuv_fourm[i][j] = static_cast<unsigned char>(ai * aj * sum);
        }
    }
    return std::move(yuv_fourm); // this is new to me but is should morve the dct var out insted of copying it
}
