#include "mainwindow.h"
#include "ui_mainwindow.h"   

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    this -> setWindowFlags(Qt::FramelessWindowHint);

    mVideoWidget = new VideoWidget(this);
//    mVideoWidget ->setGeometry(160,0,1206,768);
//    mVideoWidget -> setGeometry(0,0,1920,1080);

    mOptWidget = new OptWidget(this);
//    mOptWidget -> setGeometry(160,0,1206,768);
//    mOptWidget -> setGeometry(0,0,1920,1080);

    mControllerManager = new ControllerManager();

    mAdjustment = new Adjustment();

    in_ctrl = false;
    in_s = false;
    in_t = false;

    flagShag = true;
    shag = 0;

    i = 0;

    plusInt = 0;
    minusDec = 2;


    flagInversia = true;
    flagHelp = true;

    connect(mAdjustment, SIGNAL(newLogMsg(QString)), mVideoWidget, SLOT(logText(QString)));
    connect(mOptWidget, SIGNAL(newLog(QString)), mVideoWidget, SLOT(logText(QString)));

    connect(mAdjustment, SIGNAL(newPosX(bool)), mOptWidget, SLOT(adjustmentX(bool)));
    connect(mAdjustment, SIGNAL(newPosY(bool)), mOptWidget, SLOT(adjustmentY(bool)));
    connect(mAdjustment, SIGNAL(newPosX_Y(int,int)), mOptWidget, SLOT(setPosCross(int,int)));
    connect(mOptWidget, SIGNAL(newPosX_Y(int,int)), this, SLOT(setPosX_Y(int,int)));

    mPosX = mAdjustment -> posX;
    mPosY = mAdjustment -> posY;

    mOptWidget -> setPosCross(mPosX, mPosY);
    seeVideo(true,1);

    paintNormal();
    exposition();

    ui -> centralWidget ->setFocus();
}

MainWindow::~MainWindow()
{
    delete mAdjustment;
    delete mControllerManager;
    delete mOptWidget;
    delete mVideoWidget;
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event -> modifiers() == Qt::ControlModifier)
        {
            in_ctrl = true;
            if (in_s && in_t)
               on_button_exit_clicked();
        }
        else
        {
            in_ctrl = false;
        }

        switch (event->key())
        {
            case Qt::Key_S:
                in_s = true;
                if (in_s && in_t)
                    on_button_exit_clicked();
            break;

            case Qt::Key_T:
                in_t = true;
                if(in_s && in_t)
                    on_button_exit_clicked();
            break;

            case Qt::Key_F3:
                if (flagInversia)
                {
                    flagInversia = false;
                    inversia(true);
                }
                else
                {
                    flagInversia = true;
                    inversia(false);
                }
            break;

            case Qt::Key_Escape:
                on_button_exit_clicked();
            break;

            case Qt::Key_Q:
                on_button_adjustment_clicked();
//                logText("on");
            break;
///640x480**************************************************************************

            case Qt::Key_Minus:
                mAdjustment -> on_acceptButton_clicked();  //Посмотреть как оптимизировать
                ++shag;
                if (shag > 2)
                {
                    shag = 2;
                    break;
                }
                    switch(shag)
                    {
                        case 0:
                            mOptWidget -> zoomIRZ(1, false);
                            mVideoWidget -> camZoomNorma();
                        break;

                        case 1:
                            mOptWidget -> zoomIRZ(2, false);
                            mVideoWidget -> camZoomX2();
                        break;

                        case 2:
                            mOptWidget -> zoomIRZ(4, false);
                            mVideoWidget -> camZoomX4();
                        break;
                    }
            break;

            case Qt::Key_Equal:
                mAdjustment -> on_acceptButton_clicked();     //Посмотреть как оптимизировать
                --shag;
                if (shag < 0)
                {
                    shag = 0;
                    break;
                }
                switch(shag)
                {
                    case 2:
                        mOptWidget -> zoomIRZ(4, true);
                        mVideoWidget -> camZoomX4();
                    break;

                    case 1:
                        if (((mPosX >= 330) && (mPosX<=985)) && ((mPosY >= 180) && (mPosY <= 535)))
                        {
                            mOptWidget -> zoomIRZ(2, true);
                            mVideoWidget -> camZoomX2();
//                            mVideoWidget ->logText("x2");
                        }
                        else
                        {
                            mVideoWidget -> helpList("Вне зоны действия");
                            ++shag;
                        }

                    break;

                    case 0:
                        if (((mPosX >= 330) && (mPosX<=985)) && ((mPosY >= 180) && (mPosY <= 535)))
                        {
                            mOptWidget -> zoomIRZ(1, true);
                            mVideoWidget -> camZoomNorma();
//                            mVideoWidget -> logText("norma");
                        }
                        else
                        {
                            mVideoWidget -> helpList("Вне зоны действия");
                            ++shag;
                        }
                    break;
                }
            break;

///**************************************************************************

///800x600*******************************************************************
/*
//Уменьшение масштаба
            case Qt::Key_Minus:
                mAdjustment -> on_acceptButton_clicked();
                ++shag;
                if(shag > 1)
                {
                    shag = 1;
                    break;
                }
                switch (shag)
                {
                    case 1:
                        mVideoWidget -> logText("x2");
                        mVideoWidget -> camZoomX2();
                        mOptWidget -> zoomIRZ(2,false);
                    break;

                    case 0:
                        mVideoWidget->camZoomNorma();
                        mVideoWidget -> logText("norma");
                        mOptWidget -> zoomIRZ(1,false);
                    break;
                }
            break;

// Увелечение масштаба
            case Qt::Key_Equal:
                mAdjustment -> on_acceptButton_clicked();
                --shag;
                if (shag<0)
                {
                    shag = 0;
                    break;
                }
                switch (shag)
                {
                    case 0:
                        if (((mPosX >= 250) && (mPosX<=734)) && ((mPosY >= 180) && (mPosY <= 535)))
                        {
                            mVideoWidget -> camZoomNorma();
                            mOptWidget -> zoomIRZ(1,true);
                            mVideoWidget ->logText("norma");
                        }
                        else
                        {
                            mVideoWidget -> logText("Вне зоны действия");
                            ++shag;
                        }
                    break;

                    case 1:
                        mVideoWidget -> camZoomX2();
                        mOptWidget -> zoomIRZ(2,true);
                        mVideoWidget -> logText("x2");
                    break;
                }

            break;
*/
///**************************************************************************
/*
///1024 x 768

//Уменьшение масштаба
            case Qt::Key_Minus:
                mAdjustment -> on_acceptButton_clicked();
                ++shag;
                if(shag > 1)
                {
                    shag = 1;
                    break;
                }
                switch (shag)
                {
                    case 1:
                        mVideoWidget -> logText("x2");
                        mVideoWidget -> camZoomX2();
                        mOptWidget -> zoomIRZ(2,false);
                    break;

                    case 0:
                        mVideoWidget->camZoomNorma();
                        mVideoWidget -> logText("norma");
                        mOptWidget -> zoomIRZ(1,false);
                    break;
                }
            break;

// Увелечение масштаба
            case Qt::Key_Equal:
                mAdjustment -> on_acceptButton_clicked();
                --shag;
                if (shag<0)
                {
                    shag = 0;
                    break;
                }

                switch (shag)
                {
                    case 0:
                        if (((mPosX >= 250) && (mPosX<=734)) && ((mPosY >= 180) && (mPosY <= 535)))
                        {
                            mVideoWidget -> camZoomNorma();
                            mOptWidget -> zoomIRZ(1,true);
                            mVideoWidget ->logText("norma");
                        }
                        else
                        {
                            mVideoWidget -> logText("Вне зоны действия");
                            ++shag;
                        }
                    break;

                    case 1:
                        mVideoWidget -> camZoomX2();
                        mOptWidget -> zoomIRZ(2,true);
                        mVideoWidget -> logText("x2");
                    break;
                }
            break;
*/
///**************************************************************************

///1280 x 1024
/*
//Уменьшение масштаба
            case Qt::Key_Minus:
                mAdjustment -> on_acceptButton_clicked();
                ++shag;
                if(shag > 1)
                {
                    shag = 1;
                    break;
                }
                switch (shag)
                {
                    case 1:
                        mVideoWidget -> logText("x2");
                        mVideoWidget -> camZoomX2();
                        mOptWidget -> zoomIRZ(2,false);
                    break;

                    case 0:
                        mVideoWidget->camZoomNorma();
                        mVideoWidget -> logText("norma");
                        mOptWidget -> zoomIRZ(1,false);
                    break;
                }
            break;

// Увелечение масштаба
            case Qt::Key_Equal:
                mAdjustment -> on_acceptButton_clicked();
                --shag;
                if (shag<0)
                {
                    shag = 0;
                    break;
                }
                switch (shag)
                {
                    case 0:
                        if (((mPosX >= 250) && (mPosX<=734)) && ((mPosY >= 180) && (mPosY <= 535)))
                        {
                            mVideoWidget -> camZoomNorma();
                            mOptWidget -> zoomIRZ(1,true);
                            mVideoWidget ->logText("norma");
                        }
                        else
                        {
                            mVideoWidget -> logText("Вне зоны видимости");
                            ++shag;
                        }
                    break;

                    case 1:
                        mVideoWidget -> camZoomX2();
                        mOptWidget -> zoomIRZ(2,true);
                        mVideoWidget -> logText("x2");
                    break;
                }
            break;
*/
///**************************************************************************




            case Qt::Key_1:
                seeVideo(false,1);
//                mVideoWidget -> logText("640x480");
            break;
/*
            case Qt::Key_2:
//                mVideoWidget -> camZoomX2();
                seeVideo(false,2);
//                mVideoWidget -> logText("800x600");
            break;

            case Qt::Key_3:
//                mVideoWidget -> camZoomNorma();
                seeVideo(false,3);
//                mVideoWidget -> logText("1024x768");
            break;

            case Qt::Key_4:
//                mVideoWidget -> camZoomNorma();
                seeVideo(false,4);
//                mVideoWidget -> logText("1280x1024");
            break;

            case Qt::Key_5:
                seeVideo(false,5);
//                mVideoWidget -> logText("1920x1080");
            break;
*/
            case Qt::Key_0:
            if (++i > 3) i = 0;
                switch (i)
                {
                    case 0:
//                        mVideoWidget -> logText("0");
                        mOptWidget -> pricel(0);
                    break;

                    case 1:
//                        mVideoWidget -> logText("1");
                        mOptWidget -> pricel(1);
                    break;

                    case 2:
//                        mVideoWidget ->logText("2");
                        mOptWidget -> pricel(2);
                    break;

                    case 3:
//                        mVideoWidget->logText("3");
                        mOptWidget -> pricel(3);
                    break;
                }

            break;

            case Qt::Key_F1:
                if (flagHelp)
                {
                    mVideoWidget -> ofOnListLog(true);
                    flagHelp = false;
                }
                else
                {
                    mVideoWidget -> ofOnListLog(false);
                    flagHelp = true;
                }
            break;
        }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event -> modifiers() != Qt::ControlModifier)
        in_ctrl = false;
    switch (event -> key())
    {
        case Qt::Key_S:
            in_s = false;
        break;

        case Qt::Key_T:
            in_t = false;
        break;

        default:
            QWidget::keyReleaseEvent(event);
        break;
    }
}

void MainWindow::seeVideo(bool pFlag, int pInd)
{
    switch (pInd)
    {
        case 1:
            mVideoWidget -> setGeometry(0,0,1366,768);
            mOptWidget -> setGeometry(0,0,1366,768);
            shag = 2;

 /*           mVideoWidget -> setGeometry(160,0,1206,768);
            mOptWidget -> setGeometry(160,0,1206,768);
            shag = 1;
*/            mVideoWidget -> camZoomX4();
            mVideoWidget -> picture_640x480();
        break;

        case 2:
            mVideoWidget -> setGeometry(160,0,1206,768);
            mOptWidget -> setGeometry(160,0,1206,768);
            shag = 1;
            mVideoWidget -> camZoomX2();
            mVideoWidget -> picture_800x600();
        break;

        case 3:
            mVideoWidget -> setGeometry(160,0,1206,768);
            mOptWidget -> setGeometry(160,0,1206,768);
            shag = 1;
            mVideoWidget -> camZoomX2();
            mVideoWidget -> picture_1024x768();
        break;

        case 4:
            mVideoWidget -> setGeometry(0,0,1366,768);
            mOptWidget -> setGeometry(0,0,1366,768);
            shag = 1;
            mVideoWidget -> camZoomX2();
            mVideoWidget -> picture_1280x1024();
        break;

        case 5:
            shag = 0;
            mVideoWidget -> camZoomNorma();
            mVideoWidget -> picture_1920x1080();
        break;
    }

    if (pFlag) mVideoWidget -> camOperationMode();
}

void MainWindow::inversia(bool pFlag)
{
    if (pFlag)
    {
        paintInversia();
        mOptWidget -> inversia_picture(true);
    }
    else
    {
        paintNormal();
        mOptWidget -> inversia_picture(false);
    }
}

void MainWindow::paintNormal()
{
//    logText("Нормальный режим");

    ui -> centralWidget -> setStyleSheet(COLOR_FON_NORMA);

    ui -> button_exit -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_adjustment -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_on_power -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_test_power -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_Ak_74 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_Ak_103 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_Ak_12 -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_PKT -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);
    ui -> button_SVD -> setStyleSheet(COLOR_BUTTON_NORMA_ACTIVATE);

    ui -> list_log -> setStyleSheet(COLOR_LOG_NORMA);
}

void MainWindow::paintInversia()
{
//    logText("Инверсия режима");

    ui -> centralWidget -> setStyleSheet(COLOR_FON_INVERSIA);

    ui -> button_exit -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_adjustment -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_on_power -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_test_power -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_Ak_74 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_Ak_103 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_Ak_12 -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_PKT -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);
    ui -> button_SVD -> setStyleSheet(COLOR_BUTTON_INVERSIA_ACTIVATE);

    ui -> list_log -> setStyleSheet(COLOR_LOG_INVERSIA);
}

void MainWindow::exposition()
{
    ui -> button_exit -> hide();
    ui -> button_adjustment -> hide();
    ui -> button_on_power -> hide();
    ui -> button_test_power -> hide();
    ui -> button_Ak_74 -> hide();
    ui -> button_Ak_103 -> hide();
    ui -> button_Ak_12 -> hide();
    ui -> button_PKT -> hide();
    ui -> button_SVD -> hide();
//    ui -> list_log -> hide();
}
void MainWindow::on_button_exit_clicked()
{
    QApplication::exit(149);
}

/*Включение Юстировки*/
void MainWindow::on_button_adjustment_clicked()
{
    mAdjustment -> setFocus();
    mAdjustment -> show();
}

/*Рабочий режим*/
void MainWindow::on_button_on_power_clicked()
{
    mVideoWidget -> camOperationMode();
}

/*Дежурный режим*/
void MainWindow::on_button_test_power_clicked()
{
    mVideoWidget -> camTestMode();
}

/*Выбор оружия АК-74*/
void MainWindow::on_button_Ak_74_clicked()
{
}

void MainWindow::on_button_Ak_103_clicked()
{
}

void MainWindow::on_button_Ak_12_clicked()
{
}

void MainWindow::on_button_PKT_clicked()
{
}

void MainWindow::on_button_SVD_clicked()
{
}

void MainWindow::setPosX_Y(int pPosX, int pPosY)
{
    mPosX = pPosX;
    mPosY = pPosY;
}
