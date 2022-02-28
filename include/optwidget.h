#ifndef OPTWIDGET_H
#define OPTWIDGET_H

#define CENTRPOSX 683
#define CENTRPOSY 384

#define FILEDIR_X "/home/user/justX.txt"
#define FILEDIR_Y "/home/user/justY.txt"

#include <QWidget>
#include <QPainter>

#include <QFile>
#include <QTextStream>
#include <QString>

namespace Ui {
    class OptWidget;
}

struct Graphics {
    QImage pixmapCross;
    QImage pixmapOpt;
    QImage pixmapCrossTg;
    QImage pixmapRect;
    QImage pixmapOptRange;
    QImage pixmapPicture_1;
    QImage pixmapPicture_2;
    QImage logo;
    QImage pricel_black;
    QImage pricel_green;
    QImage pricel_red;
    QImage pricel_white;
};

class OptWidget : public QWidget
{
    Q_OBJECT

    bool need_to_show_pixmap_opt;

public:
    explicit OptWidget(QWidget *parent = 0);
    ~OptWidget();
    void inversia_picture(bool pFlagInversia);
    void pricel(int i);
    void zoomIRZ(int pZoom, bool pFlag);

    int setPosX,setPosY;

protected:
    void paintEvent(QPaintEvent *);

private:
    void writeFileX(int pAdd);
    void writeFileY(int pAdd);

    Ui::OptWidget *ui;
    Graphics mGraphicsBlack,mGraphicsWhite,mGraphics;
    QImage pixmapPicture;

    int mPosX, mPosY; //изменяемые переменные
    int addX4,addY4; // Переменные от x4
    int addX2,addY2; //Переменные от х2
    int addXN,addYN; //Переменные от Norma
    int mZoom;
    bool flagZoom;

public slots:
    void adjustmentX(bool pFlag);
    void adjustmentY(bool pFlag);
    void setPosCross(int pPosX, int pPosY);


private slots:

signals:
    void newLog(QString pStr);
    void newPosX_Y(int pPosX, int pPosY);

};

#endif // OPTWIDGET_H
