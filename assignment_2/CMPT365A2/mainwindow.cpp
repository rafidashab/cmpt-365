#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    this->setFixedSize(700, 300);

    // title
    setWindowTitle(tr("Image Converter"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


// convert a opencv Mat containing RGB data to QImage
QImage MainWindow::MatRGB2QImage(const cv::Mat3b &src) {
        QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
        for (int y = 0; y < src.rows; ++y)
        {
                const cv::Vec3b *srcrow = src[y];
                QRgb *destrow = (QRgb*)dest.scanLine(y);
                for (int x = 0; x < src.cols; ++x)
                {
                        destrow[x] = qRgba(srcrow[x][2], srcrow[x][1], srcrow[x][0], 255);
                }
        }
        return dest;
}

// convert a opencv Mat containing grayscale data to QImage
QImage MainWindow::MatGrayScale2QImage(const cv::Mat_<double> &src)
{
        double scale = 255.0;
        QImage dest(src.cols, src.rows, QImage::Format_ARGB32);
        for (int y = 0; y < src.rows; ++y)
        {
                const double *srcrow = src[y];
                QRgb *destrow = (QRgb*)dest.scanLine(y);
                for (int x = 0; x < src.cols; ++x)
                {
                        unsigned int color = srcrow[x] * scale;
                        destrow[x] = qRgba(color, color, color, 255);
                }
        }
        return dest;
}




void MainWindow::on_load_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Load Image"), "",
        tr("All Files (*)"));
    cvImg = cv::imread(fileName.toStdString(), IMREAD_COLOR);
    QImage qImage = MatRGB2QImage(cvImg);
    ui->img1->setPixmap(QPixmap::fromImage(qImage));
}

void MainWindow::on_convert_clicked()
{
    if (cvImg.empty()) {
            return;
    }
    convertedImg.create(cvImg.size(), CV_8UC3);
    cvImg.copyTo(convertedImg);
    std::cout<< convertedImg.type() << std::endl;
    rgb2yuv(convertedImg);
    chroma_subsample(convertedImg);
    yuv2rgb(convertedImg);
    QImage qImage = MatRGB2QImage(convertedImg);
    ui->img2->setPixmap(QPixmap::fromImage(qImage));
}
