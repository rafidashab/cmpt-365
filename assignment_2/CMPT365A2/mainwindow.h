#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLayout>
#include <QScrollArea>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QStandardPaths>
#include <QImageReader>
#include <QImageWriter>
#include <QMessageBox>
#include <QPixmap>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/opencv.hpp>

#include "math.h"

using namespace cv;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_load_clicked();

    void on_convert_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_ybutton_clicked();

    void on_ubutton_clicked();

    void on_vbutton_clicked();

    void on_qualitySlider_valueChanged(int value);

    void on_convert2rgb_clicked();

    void on_enableQuant_toggled(bool checked);

private:
    QImage MatRGB2QImage(const cv::Mat3b &src);
    QImage MatGrayScale2QImage(const cv::Mat_<double> &src);

    Ui::MainWindow *ui;

    Mat cvImg, convertedImg;
    cv::Vec3i subsampling;
    double quality;
    bool rgb;
    bool enableQuant;

};

#endif // MAINWINDOW_H
