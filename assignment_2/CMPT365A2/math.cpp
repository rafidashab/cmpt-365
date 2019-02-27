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


static const double pi = 3.142857;

cv::Vec3b rgb2yuv(cv::Vec3b pixel){

    cv::Vec3d yuv;
    yuv = dWeights_rgb2yuv * (cv::Vec3d)pixel;// * is matric multiplication and .mul() is element multiplication
    yuv[0] += 16;
    yuv[1] += 128;
    yuv[2] += 128;
    //clamps values to byte range
    for(int i=0; i<3; i++){
        if (yuv[i]<0) yuv[i]=0;
        else if(yuv[i]>255) yuv[i] = 255;
    }
    return static_cast<cv::Vec3b>(yuv);
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

    cv::Vec3d tmp = static_cast<cv::Vec3d>(pixel);
    tmp[0]-=16;
    tmp[1]-=128;
    tmp[2]-=128;
    rgb = dWeights_yuv2rgb * tmp; // * is matric multiplication and .mul() is element multiplication

    //clamps values to byte range
    for(int i=0; i<3; i++){
        if (rgb[i]<0) rgb[i]=0;
        else if(rgb[i]>255) rgb[i] = 255;
    }
    return static_cast<cv::Vec3s>(rgb);
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
//dont use this garbage
cv::Mat1d block_dct(cv::Mat1b block) {//might change the input format

    int m,n;
    m = block.rows;
    n = block.cols;

    cv::Mat1d dct_form;
    dct_form.create(block.size());

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

            dct_form[i][j] = (ai * aj * sum);
        }
    }// this is new to me but is should morve the dct var out insted of copyingit
    return (dct_form);
}

cv::Mat idct(cv::Mat &block) {
    int m,n;
    m = block.rows;
    n = block.cols;

    cv::Mat yuv_form;
    yuv_form.create(block.size(), CV_64F);

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
                    sum += (ai * aj * block.at<double>(k,l) * cosi * cosj);
                }
            }

            //assert(sum <= 0);//just want to see if this is true
            //assert(sum >= 255);
            //yuv_form[i][j] = static_cast<unsigned char>(sum);
            yuv_form.at<double>(i,j) = sum;
        }
    }
    return (yuv_form); // this is new to me but is should morve the dct var out insted of copying it
}

void quant(cv::Matx<double,8,8> &block, int q[8][8], double scale ) {
    assert(block.cols == 8 && block.rows == 8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //double tmp = block(i,j);
            block(i,j) = block(i,j)/(static_cast<double>(q[i][j]) * scale);
            block(i,j) = round(block(i,j));
//            assert(block(i,j) != tmp);
           //std::cout << block(i,j) << " :blk tmp: "<< tmp << std::endl;

        }
    }
}
void iquant(cv::Matx<double,8,8> &block, int q[8][8], double scale ) {
    assert(block.cols == 8 && block.rows == 8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            block(i,j) = block(i,j)*(static_cast<double>(q[i][j]) * scale);
        }
    }
}


void resize8x8(cv::Mat &img) {

    int newRows = img.rows - (img.rows % 8);
    int newCols = img.cols - (img.cols % 8); //this will cause any image less than 8x8 to be lost though so padding is better i think

//    std::cout << img.rows << std::endl;
//    std::cout << img.cols << std::endl;


//    cv::Size size(newCols,newRows);
//    if(size != img.size()){
//        std::cout << "Im a bad size" << std::endl;
//    } else {
//        std::cout << "Im a good size" << std::endl;
//        return;
//    }

//    resize(img , img, size); //Resize the image to be have rows and coloums that are multiple of 8

    cv::Rect crop(0,0,newCols,newRows);

    std::cout << "width : " << newCols << std::endl;
    std::cout << "Height :" << newRows << std::endl;

    if (newRows == img.rows && newCols == img.cols) {
        std::cout << "Im a good size" << std::endl;
        return;
    }
    std::cout << "Im a bad size" << std::endl;
    cv::Mat test;
    test = img(crop);
    test.copyTo(img);

}

void runDctOnImage(cv::Mat &img, cv::Mat &dct, double quality, bool should_quant) {

    //copy the imput image to a new matrix
    cv::Mat dctmat;
    cv::Mat result;
    img.copyTo(dctmat);

    resize8x8(dctmat);

    //seperate the 3 RGB channels
    cv::Mat yuv[3];
    split(dctmat, yuv);


    cv::Mat dctret[3];
    split(dctmat, dctret);
    //temp DCT of image

    cv::Matx<double,8,8> smalldctmat;
    //cv::Matx<double,8,8> smallidctmat;

    //crop image in 8*8 block to be passed to dct
    cv::Matx<double,8,8> small;


    for (int ch=0; ch<3; ch++)
    {
        for (int i=0; i<yuv[ch].cols; i=i+8)
        {

            for (int j=0; j<yuv[ch].rows; j=j+8)
            {

               cv::Rect Rec(i,j,8,8);
               small = (yuv[ch](Rec));


               smalldctmat = dct88(small);

               if(should_quant){
                   if (ch == 0) {
                       quant(smalldctmat, lum_quant, quality );
                       iquant(smalldctmat, lum_quant, quality );
                   }

                   else {
                       quant(smalldctmat, chr_quant, quality );
                       iquant(smalldctmat, lum_quant, quality );
                   }
               }
                cv::Mat(smalldctmat).copyTo(dctret[ch](Rec));


                smalldctmat = idct88(smalldctmat);

              //smalldctmat = idct88(smalldctmat);
              //Store the DCT on the image block

               cv::Mat(smalldctmat).copyTo(yuv[ch](Rec));

            }
        }
    }

    merge(yuv, 3, img);
    //result.copyTo(img);
    merge(dctret, 3, dct);
    //result.copyTo(dct);
    return;
}


void init_dct() {
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){
            if(i == 0 ) {
                dctMatrix(i,j) = 0.5/sqrt(2);
            } else {
                dctMatrix(i,j) = 0.5*cos((2*j+1)*i*M_PI / 16);
            }
        }
    }
}

cv::Matx<double,8,8> dct88(cv::Matx<double,8,8> f) {
    return dctMatrix * f * dctMatrix.t();
}

cv::Matx<double,8,8> idct88(cv::Matx<double,8,8> F) {
    return dctMatrix.t() * F * dctMatrix;
}
