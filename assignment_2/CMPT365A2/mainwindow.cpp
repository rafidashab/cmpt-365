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
    quality = 1;
    rgb = true;
    enableQuant = true;
    ui->qualityDisplay->setText(QString::number(quality));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //
            QTableWidgetItem *pCell = ui->quantDisplay_chr->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                ui->quantDisplay_chr->setItem(i, j, pCell);
            }

            ui->quantDisplay_chr->item(i,j)->setText(QString::number(chr_quant[i][j]));

        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //
            QTableWidgetItem *pCell = ui->quantDisplay_lum->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                ui->quantDisplay_lum->setItem(i, j, pCell);
            }

            ui->quantDisplay_lum->item(i,j)->setText(QString::number(lum_quant[i][j]));

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
    //resize8x8(cvImg);

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
    QImage qImage;
    //std::cout<< convertedImg.type() << std::endl;

    rgb2yuv(convertedImg);


    chroma_subsample(convertedImg, subsampling[0], subsampling[1], subsampling[2]);
    cv::Mat tmp;
    runDctOnImage(convertedImg,tmp, quality, enableQuant);

    qImage = MatRGB2QImage(tmp);
    ui->imgDCT->setPixmap(QPixmap::fromImage(qImage));

    //convertedImg = runiDctOnImage(tmp, quality, enableQuant);

    rgb = false;
    cv::Mat yuv[3];
    split(convertedImg, yuv);
    qImage = MatGrayScale2QImage(yuv[0]);
    ui->imgY->setPixmap(QPixmap::fromImage(qImage));
    qImage = MatGrayScale2QImage(yuv[1]);
    ui->imgU->setPixmap(QPixmap::fromImage(qImage));
    qImage = MatGrayScale2QImage(yuv[2]);
    ui->imgV->setPixmap(QPixmap::fromImage(qImage));

    yuv2rgb(convertedImg);
    rgb = true;
    //on_convert2rgb_clicked(); // back to rg

    qImage = MatRGB2QImage(convertedImg);//output
    ui->img2->setPixmap(QPixmap::fromImage(qImage));


}

void MainWindow::on_comboBox_currentIndexChanged(int index) {
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

void MainWindow::on_qualitySlider_valueChanged(int value)
{
    std::cout << value << std::endl;
    quality = value/(double)10;
    ui->qualityDisplay->setText(QString::number(quality));

    ui->qualityDisplay->setText(QString::number(quality));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //
            QTableWidgetItem *pCell = ui->quantDisplay_chr->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                ui->quantDisplay_chr->setItem(i, j, pCell);
            }

            ui->quantDisplay_chr->item(i,j)->setText(QString::number(chr_quant[i][j]* quality));

        }
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //
            QTableWidgetItem *pCell = ui->quantDisplay_lum->item(i, j);
            if(!pCell)
            {
                pCell = new QTableWidgetItem;
                ui->quantDisplay_lum->setItem(i, j, pCell);
            }

            ui->quantDisplay_lum->item(i,j)->setText(QString::number(lum_quant[i][j] * quality));

        }
    }
    on_convert_clicked();
}

void MainWindow::on_convert2rgb_clicked()
{
    if (rgb == false) {
    yuv2rgb(convertedImg);
    QImage qImage = MatRGB2QImage(convertedImg);
    ui->img2->setPixmap(QPixmap::fromImage(qImage));
    rgb = true;
    }

}

void MainWindow::on_enableQuant_toggled(bool checked)
{
    enableQuant = checked;
    on_convert_clicked();
}
