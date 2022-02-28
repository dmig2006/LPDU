#include "optwidget.h"
#include "ui_optwidget.h"

OptWidget::OptWidget(QWidget *parent) :
    QWidget(parent), ui(new Ui::OptWidget)
{
    ui -> setupUi(this);
/*    QPixmap curPix;
    curPix.load(":/cross.png");
    QCursor cur(curPix);
    setCursor(cur);
*/
    mGraphicsBlack.pixmapCross.load(":/res/images/picture_black/cros.png");
    mGraphicsBlack.pixmapCrossTg.load(":/res/images/picture_black/cross.png");

    mGraphicsBlack.pixmapRect.load(":/res/images/picture_black/ramka.png");
    mGraphicsBlack.pixmapOpt.load(":/res/images/picture_black/opt.png");
    mGraphicsBlack.pixmapOptRange.load(":/res/images/picture_black/opt_range.png");
    mGraphicsBlack.logo.load(":/logo.png");

    mGraphicsBlack.pricel_black.load(":/res/images/crossBlack.png");
    mGraphicsBlack.pricel_green.load(":/res/images/crossGreen.png");
    mGraphicsBlack.pricel_red.load(":/res/images/crossRed.png");
    mGraphicsBlack.pricel_white.load(":/res/images/crossWhite.png");

    mGraphicsWhite.pixmapCross.load(":/res/images/picture_white/cros.png");
    mGraphicsWhite.pixmapCrossTg.load(":/res/images/picture_white/cross.png");
    mGraphicsWhite.pixmapRect.load(":/res/images/picture_white/ramka.png");
    mGraphicsWhite.pixmapOpt.load(":/res/images/picture_white/opt.png");
    mGraphicsWhite.pixmapOptRange.load(":/res/images/picture_white/opt_range.png");
    mGraphicsWhite.logo.load(":/logo.png");

    mGraphics = mGraphicsBlack;

    mGraphics.pixmapCrossTg = mGraphicsBlack.pricel_black;
    mZoom = 4;
}

OptWidget::~OptWidget()
{
    delete ui;
}

void OptWidget::inversia_picture(bool pFlagInversia)
{
    if (pFlagInversia)
        mGraphics = mGraphicsWhite;
    else
        mGraphics = mGraphicsBlack;
}

void OptWidget::pricel(int i)
{
    update();
    switch (i)
    {
        case 0:
            mGraphics.pixmapCrossTg = mGraphicsBlack.pricel_black;
        break;

        case 1:
            mGraphics.pixmapCrossTg = mGraphicsBlack.pricel_green;
        break;

        case 2:
            mGraphics.pixmapCrossTg = mGraphicsBlack.pricel_red;
        break;

        case 3:
            mGraphics.pixmapCrossTg = mGraphicsBlack.pricel_white;
        break;
    }
}

void OptWidget::zoomIRZ(int pZoom, bool pFlag)
{
    float x,y;
    x = 0.0f;
    y = 0.0f;
    mZoom = pZoom;
    switch (pZoom)
    {
        case 1:
            if (pFlag)
            {
                x = 2*addX2-CENTRPOSX+26;
                y = 2*addY2-CENTRPOSY+26;
                addXN = x;
                addYN = y;
            }
            else
            {
                x = addXN;
                y = addYN;
            }

        break;

        case 2:
            if (pFlag)
            {
                x = 2*addX4-CENTRPOSX+26;
                y = 2*addY4-CENTRPOSY+26;
                addX2 = x;
                addY2 = y;
            }
            else
            {
                  x = (addXN+CENTRPOSX-26) / 2;
                  y = (addYN+CENTRPOSY-26) / 2;
            }

        break;

        case 4:
            if (pFlag)
            {
                x = addX4;
                y = addY4;
            }
            else
            {
                x = (addX2+CENTRPOSX-26) / 2;
                y = (addY2+CENTRPOSY-26) / 2;
            }
        break;
    }

    mPosX = x;
    mPosY = y;

    writeFileX(mPosX);
    writeFileY(mPosY);

    update();

    emit newPosX_Y(mPosX,mPosY);
/*
    QString str;
    str = "ox"+QString::number(mPosX)+"oy"+QString::number(mPosY)+"Schet";
    emit newLog(str);
*/}

void OptWidget::paintEvent(QPaintEvent *)
{
    //update();
    QPainter painter(this);
//    painter.drawImage(20,           20,         mGraphics.pixmapCross);
//    painter.drawImage(200,          300,        mGraphics.pixmapOpt);
//    painter.drawImage(350,          250,        mGraphics.pixmapRect);
//    painter.drawImage(683 - 25 + mPosX,  384 - 25 + mPosY,mGraphics.pixmapCrossTg);
    painter.drawImage(mPosX/*+addX*/,mPosY/*+addY*/,mGraphics.pixmapCrossTg);
    painter.drawImage(10,           10,         mGraphics.logo);
    painter.end();
}

void OptWidget::writeFileX(int pAdd)
{
    QString str;
    str = QString::number(pAdd);
    QString filename = FILEDIR_X;
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out<<str<<endl;
    file.close();
}

void OptWidget::writeFileY(int pAdd)
{
    QString str;
    str = QString::number(pAdd);
    QString filename = FILEDIR_Y;
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out(&file);
    out<<str<<endl;
    file.close();
}

void OptWidget::adjustmentX(bool pFlag)
{
    if (pFlag) mPosX += 1;
    else       mPosX -= 1;

    switch (mZoom)
    {
        case 1:
            addXN = mPosX;
        break;

        case 2:
            addX2 = mPosX;
        break;

        case 4:
            addX4 = mPosX;
        break;
    }
    writeFileX(mPosX);
/*
    QString str;
    str = "ox"+QString::number(mPosX);
    emit newLog(str);
*/
    update();
}

void OptWidget::adjustmentY(bool pFlag)
{

    if (pFlag) mPosY -= 1;
    else       mPosY += 1;

    switch (mZoom)
    {
        case 1:
            addYN = mPosY;
        break;

        case 2:
            addY2 = mPosY;
        break;

        case 4:
            addY4 = mPosY;
        break;
    }
    writeFileY(mPosY);
/*
    QString str;
    str = "oy"+QString::number(mPosY);
    emit newLog(str);
*/
    update();
}

void OptWidget::setPosCross(int pPosX, int pPosY)
{
    switch (mZoom)
    {
        case 1:
            addXN = pPosX;
            addYN = pPosY;
        break;

        case 2:
            addX2 = pPosX;
            addY2 = pPosY;
        break;

        case 4:
            addX4 = pPosX;
            addY4 = pPosY;
        break;
    }

    mPosX = pPosX;
    mPosY = pPosY;
    writeFileX(pPosX);
    writeFileY(pPosY);

    emit newPosX_Y(mPosX,mPosY);

    QString str;
    str = "ox"+QString::number(mPosX)+"oy"+QString::number(mPosY)+"Zoom"+QString::number(mZoom);
    emit newLog(str);

    update();
}

