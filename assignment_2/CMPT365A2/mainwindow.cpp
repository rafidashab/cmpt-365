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

    init_dct();

    subsampling = cv::Vec3i(4,2,0);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //
            QTableWidgetItem *pCell = ui->quantDisplay->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                ui->quantDisplay->setItem(i, j, pCell);
            }

            ui->quantDisplay->item(i,j)->setText(QString::number(lum_quant[i][j]));

        }
    }

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

    //resize the loaded image to have column and row that are multiple of 8;
    resize8x8(cvImg);

    QImage qImage = MatRGB2QImage(cvImg);
    ui->img1->setPixmap(QPixmap::fromImage(qImage));
    //ui->img1->resize(cvImg.cols, cvImg.rows);
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

    cv::Mat yuv[3];
    split(convertedImg, yuv);

    chroma_subsample(convertedImg, subsampling[0], subsampling[1], subsampling[2]);

    convertedImg = runDctOnImage(convertedImg);

    yuv2rgb(convertedImg);
    QImage qImage = MatRGB2QImage(convertedImg);
    ui->img2->setPixmap(QPixmap::fromImage(qImage));

    //ui->quantDisplay->setItem(2,2,)

}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        subsampling = cv::Vec3i(4,2,0);
        break;
    case 1:
        subsampling = cv::Vec3i(4,2,2);
        break;
    case 2:
        subsampling = cv::Vec3i(4,4,4);
        break;
    }

    on_convert_clicked();
}

void MainWindow::on_dct_clicked()
{
    if (cvImg.empty()) {
            return;
    }

    convertedImg.create(cvImg.size(), CV_8UC3);
    cvImg.copyTo(convertedImg);

    convertedImg = runDctOnImage(convertedImg);

    QImage qImage = MatRGB2QImage(convertedImg);
    ui->img2->setPixmap(QPixmap::fromImage(qImage));

    //    cv::Mat test;
    //    test.create()

    //    for (int i = 0; i < 8; i++) {
    //        for (int j = 0; j < 8; j++) {
    //            //
    //            QTableWidgetItem *pCell = ui->quantDisplay->item(i, j);
    //            if(!pCell)
    //            {
    //                pCell = new QTableWidgetItem;
    //                ui->quantDisplay->setItem(i, j, pCell);
    //            }

    //            ui->quantDisplay->item(i,j)->setText(QString::number(lum_quant[i][j]));

//    //        }

//    }

}

void MainWindow::on_ybutton_clicked()
{
    cvImg.copyTo(convertedImg);
    rgb2yuv(convertedImg);
    cv::Mat yuv[3];
    split(convertedImg, yuv);

    QImage qImage = MatGrayScale2QImage(yuv[0]);
    ui->img2->setPixmap(QPixmap::fromImage(qImage));

}

void MainWindow::on_ubutton_clicked()
{
    cvImg.copyTo(convertedImg);
    rgb2yuv(convertedImg);
    cv::Mat yuv[3];
    split(convertedImg, yuv);

    QImage qImage = MatGrayScale2QImage(yuv[1]);
    ui->img2->setPixmap(QPixmap::fromImage(qImage));
}



void MainWindow::on_vbutton_clicked()
{
    cvImg.copyTo(convertedImg);
    rgb2yuv(convertedImg);
    cv::Mat yuv[3];
    split(convertedImg, yuv);

    QImage qImage = MatGrayScale2QImage(yuv[2]);
    ui->img2->setPixmap(QPixmap::fromImage(qImage));
}
