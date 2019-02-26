/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QPushButton *convert2rgb;
    QGridLayout *gridLayout;
    QPushButton *convert;
    QLineEdit *qualityDisplay;
    QLabel *subsampling_label;
    QLabel *label;
    QPushButton *load;
    QComboBox *comboBox;
    QRadioButton *enableQuant;
    QSlider *qualitySlider;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QTableWidget *quantDisplay_lum;
    QWidget *tab_2;
    QTableWidget *quantDisplay_chr;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QTabWidget *displayTabs;
    QWidget *original;
    QScrollArea *scrollArea_tabs;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_5;
    QLabel *img1;
    QWidget *tabY;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_4;
    QLabel *imgY;
    QWidget *tabU;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_6;
    QGridLayout *gridLayout_10;
    QLabel *imgU;
    QWidget *tabV;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_7;
    QGridLayout *gridLayout_11;
    QLabel *imgV;
    QWidget *dct;
    QScrollArea *scrollArea_tabs_3;
    QWidget *scrollAreaWidgetContents_8;
    QGridLayout *gridLayout_12;
    QLabel *imgDCT;
    QWidget *output;
    QScrollArea *scrollArea_tabs_2;
    QWidget *scrollAreaWidgetContents_5;
    QGridLayout *gridLayout_9;
    QLabel *img2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1208, 624);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        convert2rgb = new QPushButton(centralWidget);
        convert2rgb->setObjectName(QStringLiteral("convert2rgb"));

        verticalLayout->addWidget(convert2rgb);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        convert = new QPushButton(centralWidget);
        convert->setObjectName(QStringLiteral("convert"));

        gridLayout->addWidget(convert, 3, 5, 1, 1);

        qualityDisplay = new QLineEdit(centralWidget);
        qualityDisplay->setObjectName(QStringLiteral("qualityDisplay"));
        qualityDisplay->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qualityDisplay->sizePolicy().hasHeightForWidth());
        qualityDisplay->setSizePolicy(sizePolicy1);
        qualityDisplay->setReadOnly(true);

        gridLayout->addWidget(qualityDisplay, 6, 5, 1, 1);

        subsampling_label = new QLabel(centralWidget);
        subsampling_label->setObjectName(QStringLiteral("subsampling_label"));

        gridLayout->addWidget(subsampling_label, 5, 4, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 6, 4, 1, 1);

        load = new QPushButton(centralWidget);
        load->setObjectName(QStringLiteral("load"));

        gridLayout->addWidget(load, 3, 4, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(comboBox, 5, 5, 1, 1);

        enableQuant = new QRadioButton(centralWidget);
        enableQuant->setObjectName(QStringLiteral("enableQuant"));
        enableQuant->setChecked(true);

        gridLayout->addWidget(enableQuant, 7, 4, 1, 1);

        qualitySlider = new QSlider(centralWidget);
        qualitySlider->setObjectName(QStringLiteral("qualitySlider"));
        sizePolicy1.setHeightForWidth(qualitySlider->sizePolicy().hasHeightForWidth());
        qualitySlider->setSizePolicy(sizePolicy1);
        qualitySlider->setMinimum(1);
        qualitySlider->setMaximum(100);
        qualitySlider->setPageStep(10);
        qualitySlider->setSliderPosition(50);
        qualitySlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(qualitySlider, 7, 5, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(325, 352));
        tab_1 = new QWidget();
        tab_1->setObjectName(QStringLiteral("tab_1"));
        quantDisplay_lum = new QTableWidget(tab_1);
        if (quantDisplay_lum->columnCount() < 8)
            quantDisplay_lum->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        quantDisplay_lum->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (quantDisplay_lum->rowCount() < 8)
            quantDisplay_lum->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        quantDisplay_lum->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QFont font;
        font.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font);
        quantDisplay_lum->setItem(0, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        quantDisplay_lum->setItem(1, 0, __qtablewidgetitem17);
        quantDisplay_lum->setObjectName(QStringLiteral("quantDisplay_lum"));
        quantDisplay_lum->setGeometry(QRect(0, 0, 322, 322));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(quantDisplay_lum->sizePolicy().hasHeightForWidth());
        quantDisplay_lum->setSizePolicy(sizePolicy3);
        quantDisplay_lum->setMinimumSize(QSize(322, 322));
        quantDisplay_lum->setMaximumSize(QSize(322, 322));
        quantDisplay_lum->setIconSize(QSize(46, 46));
        quantDisplay_lum->horizontalHeader()->setVisible(false);
        quantDisplay_lum->horizontalHeader()->setDefaultSectionSize(40);
        quantDisplay_lum->horizontalHeader()->setHighlightSections(false);
        quantDisplay_lum->horizontalHeader()->setMinimumSectionSize(40);
        quantDisplay_lum->verticalHeader()->setVisible(false);
        quantDisplay_lum->verticalHeader()->setDefaultSectionSize(40);
        quantDisplay_lum->verticalHeader()->setMinimumSectionSize(40);
        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        quantDisplay_chr = new QTableWidget(tab_2);
        if (quantDisplay_chr->columnCount() < 8)
            quantDisplay_chr->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(5, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(6, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        quantDisplay_chr->setHorizontalHeaderItem(7, __qtablewidgetitem25);
        if (quantDisplay_chr->rowCount() < 8)
            quantDisplay_chr->setRowCount(8);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(5, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(6, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        quantDisplay_chr->setVerticalHeaderItem(7, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font);
        quantDisplay_chr->setItem(0, 0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        quantDisplay_chr->setItem(1, 0, __qtablewidgetitem35);
        quantDisplay_chr->setObjectName(QStringLiteral("quantDisplay_chr"));
        quantDisplay_chr->setGeometry(QRect(0, 0, 322, 322));
        sizePolicy3.setHeightForWidth(quantDisplay_chr->sizePolicy().hasHeightForWidth());
        quantDisplay_chr->setSizePolicy(sizePolicy3);
        quantDisplay_chr->setMinimumSize(QSize(322, 322));
        quantDisplay_chr->setMaximumSize(QSize(322, 322));
        quantDisplay_chr->setIconSize(QSize(46, 46));
        quantDisplay_chr->horizontalHeader()->setVisible(false);
        quantDisplay_chr->horizontalHeader()->setDefaultSectionSize(40);
        quantDisplay_chr->horizontalHeader()->setHighlightSections(false);
        quantDisplay_chr->horizontalHeader()->setMinimumSectionSize(40);
        quantDisplay_chr->verticalHeader()->setVisible(false);
        quantDisplay_chr->verticalHeader()->setDefaultSectionSize(40);
        quantDisplay_chr->verticalHeader()->setMinimumSectionSize(40);
        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout_2->addLayout(verticalLayout, 1, 0, 1, 1);

        displayTabs = new QTabWidget(centralWidget);
        displayTabs->setObjectName(QStringLiteral("displayTabs"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(displayTabs->sizePolicy().hasHeightForWidth());
        displayTabs->setSizePolicy(sizePolicy4);
        displayTabs->setMinimumSize(QSize(0, 300));
        original = new QWidget();
        original->setObjectName(QStringLiteral("original"));
        scrollArea_tabs = new QScrollArea(original);
        scrollArea_tabs->setObjectName(QStringLiteral("scrollArea_tabs"));
        scrollArea_tabs->setGeometry(QRect(0, 0, 581, 511));
        scrollArea_tabs->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_tabs->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_tabs->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 565, 495));
        gridLayout_5 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        img1 = new QLabel(scrollAreaWidgetContents_2);
        img1->setObjectName(QStringLiteral("img1"));
        img1->setScaledContents(true);

        gridLayout_5->addWidget(img1, 0, 0, 1, 1);

        scrollArea_tabs->setWidget(scrollAreaWidgetContents_2);
        displayTabs->addTab(original, QString());
        tabY = new QWidget();
        tabY->setObjectName(QStringLiteral("tabY"));
        gridLayout_3 = new QGridLayout(tabY);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        scrollArea = new QScrollArea(tabY);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 554, 480));
        gridLayout_4 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        imgY = new QLabel(scrollAreaWidgetContents);
        imgY->setObjectName(QStringLiteral("imgY"));
        imgY->setScaledContents(true);

        gridLayout_4->addWidget(imgY, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 0, 0, 1, 1);

        displayTabs->addTab(tabY, QString());
        tabU = new QWidget();
        tabU->setObjectName(QStringLiteral("tabU"));
        scrollArea_2 = new QScrollArea(tabU);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(0, 0, 570, 496));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QStringLiteral("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 554, 480));
        gridLayout_10 = new QGridLayout(scrollAreaWidgetContents_6);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        imgU = new QLabel(scrollAreaWidgetContents_6);
        imgU->setObjectName(QStringLiteral("imgU"));
        imgU->setScaledContents(true);

        gridLayout_10->addWidget(imgU, 0, 0, 1, 1);

        scrollArea_2->setWidget(scrollAreaWidgetContents_6);
        displayTabs->addTab(tabU, QString());
        tabV = new QWidget();
        tabV->setObjectName(QStringLiteral("tabV"));
        scrollArea_5 = new QScrollArea(tabV);
        scrollArea_5->setObjectName(QStringLiteral("scrollArea_5"));
        scrollArea_5->setGeometry(QRect(0, 0, 570, 496));
        scrollArea_5->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_5->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QStringLiteral("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 554, 480));
        gridLayout_11 = new QGridLayout(scrollAreaWidgetContents_7);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        imgV = new QLabel(scrollAreaWidgetContents_7);
        imgV->setObjectName(QStringLiteral("imgV"));
        imgV->setScaledContents(true);

        gridLayout_11->addWidget(imgV, 0, 0, 1, 1);

        scrollArea_5->setWidget(scrollAreaWidgetContents_7);
        displayTabs->addTab(tabV, QString());
        dct = new QWidget();
        dct->setObjectName(QStringLiteral("dct"));
        scrollArea_tabs_3 = new QScrollArea(dct);
        scrollArea_tabs_3->setObjectName(QStringLiteral("scrollArea_tabs_3"));
        scrollArea_tabs_3->setGeometry(QRect(0, 0, 581, 511));
        scrollArea_tabs_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_tabs_3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_tabs_3->setWidgetResizable(true);
        scrollAreaWidgetContents_8 = new QWidget();
        scrollAreaWidgetContents_8->setObjectName(QStringLiteral("scrollAreaWidgetContents_8"));
        scrollAreaWidgetContents_8->setGeometry(QRect(0, 0, 565, 495));
        gridLayout_12 = new QGridLayout(scrollAreaWidgetContents_8);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        imgDCT = new QLabel(scrollAreaWidgetContents_8);
        imgDCT->setObjectName(QStringLiteral("imgDCT"));
        imgDCT->setScaledContents(true);

        gridLayout_12->addWidget(imgDCT, 0, 0, 1, 1);

        scrollArea_tabs_3->setWidget(scrollAreaWidgetContents_8);
        displayTabs->addTab(dct, QString());
        output = new QWidget();
        output->setObjectName(QStringLiteral("output"));
        scrollArea_tabs_2 = new QScrollArea(output);
        scrollArea_tabs_2->setObjectName(QStringLiteral("scrollArea_tabs_2"));
        scrollArea_tabs_2->setGeometry(QRect(0, 0, 581, 511));
        scrollArea_tabs_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_tabs_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_tabs_2->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QStringLiteral("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 565, 495));
        gridLayout_9 = new QGridLayout(scrollAreaWidgetContents_5);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        img2 = new QLabel(scrollAreaWidgetContents_5);
        img2->setObjectName(QStringLiteral("img2"));
        img2->setScaledContents(true);

        gridLayout_9->addWidget(img2, 0, 0, 1, 1);

        scrollArea_tabs_2->setWidget(scrollAreaWidgetContents_5);
        displayTabs->addTab(output, QString());

        gridLayout_2->addWidget(displayTabs, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1208, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(0);
        displayTabs->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
        convert2rgb->setText(QApplication::translate("MainWindow", "Conver to RGB", nullptr));
        convert->setText(QApplication::translate("MainWindow", "Convert", nullptr));
        subsampling_label->setText(QApplication::translate("MainWindow", "Croma Subsampling", nullptr));
        label->setText(QApplication::translate("MainWindow", "Quality (Quantization scale):", nullptr));
        load->setText(QApplication::translate("MainWindow", "Load", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", "4:2:0", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", "4:2:2", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", "4:4:4", nullptr));

        enableQuant->setText(QApplication::translate("MainWindow", "Enable Qunatization", nullptr));
        QTableWidgetItem *___qtablewidgetitem = quantDisplay_lum->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = quantDisplay_lum->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = quantDisplay_lum->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = quantDisplay_lum->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = quantDisplay_lum->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = quantDisplay_lum->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = quantDisplay_lum->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = quantDisplay_lum->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = quantDisplay_lum->verticalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = quantDisplay_lum->verticalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = quantDisplay_lum->verticalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = quantDisplay_lum->verticalHeaderItem(3);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = quantDisplay_lum->verticalHeaderItem(4);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = quantDisplay_lum->verticalHeaderItem(5);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = quantDisplay_lum->verticalHeaderItem(6);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = quantDisplay_lum->verticalHeaderItem(7);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "7", nullptr));

        const bool __sortingEnabled = quantDisplay_lum->isSortingEnabled();
        quantDisplay_lum->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem16 = quantDisplay_lum->item(0, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "123", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = quantDisplay_lum->item(1, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "21", nullptr));
        quantDisplay_lum->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("MainWindow", "Y Qunatization", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = quantDisplay_chr->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = quantDisplay_chr->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = quantDisplay_chr->horizontalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = quantDisplay_chr->horizontalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = quantDisplay_chr->horizontalHeaderItem(4);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = quantDisplay_chr->horizontalHeaderItem(5);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = quantDisplay_chr->horizontalHeaderItem(6);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = quantDisplay_chr->horizontalHeaderItem(7);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "7", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = quantDisplay_chr->verticalHeaderItem(0);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = quantDisplay_chr->verticalHeaderItem(1);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = quantDisplay_chr->verticalHeaderItem(2);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = quantDisplay_chr->verticalHeaderItem(3);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = quantDisplay_chr->verticalHeaderItem(4);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = quantDisplay_chr->verticalHeaderItem(5);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = quantDisplay_chr->verticalHeaderItem(6);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = quantDisplay_chr->verticalHeaderItem(7);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "7", nullptr));

        const bool __sortingEnabled1 = quantDisplay_chr->isSortingEnabled();
        quantDisplay_chr->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem34 = quantDisplay_chr->item(0, 0);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "123", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = quantDisplay_chr->item(1, 0);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "21", nullptr));
        quantDisplay_chr->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "UV Qunatization", nullptr));
        img1->setText(QApplication::translate("MainWindow", "Y", nullptr));
        displayTabs->setTabText(displayTabs->indexOf(original), QApplication::translate("MainWindow", "Original", nullptr));
        imgY->setText(QApplication::translate("MainWindow", "Y", nullptr));
        displayTabs->setTabText(displayTabs->indexOf(tabY), QApplication::translate("MainWindow", "Y", nullptr));
        imgU->setText(QApplication::translate("MainWindow", "U", nullptr));
        displayTabs->setTabText(displayTabs->indexOf(tabU), QApplication::translate("MainWindow", "U", nullptr));
        imgV->setText(QApplication::translate("MainWindow", "V", nullptr));
        displayTabs->setTabText(displayTabs->indexOf(tabV), QApplication::translate("MainWindow", "V", nullptr));
        imgDCT->setText(QApplication::translate("MainWindow", "DCT", nullptr));
        displayTabs->setTabText(displayTabs->indexOf(dct), QApplication::translate("MainWindow", "DCT", nullptr));
        img2->setText(QApplication::translate("MainWindow", "Y", nullptr));
        displayTabs->setTabText(displayTabs->indexOf(output), QApplication::translate("MainWindow", "Output", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
