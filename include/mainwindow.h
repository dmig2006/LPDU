#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QLabel>
#include <QKeyEvent>

#include "videowidget.h"
#include "optwidget.h"
#include "controllermanager.h"
#include "adjustment.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private: 
    void seeVideo(bool pFlag, int pInd);
    void inversia(bool pFlag);
    void paintNormal();
    void paintInversia();
    void exposition();

    Ui::MainWindow *ui;
    VideoWidget *mVideoWidget;
    OptWidget *mOptWidget;
    QPalette palette;
    ControllerManager *mControllerManager;
    Adjustment *mAdjustment;

    bool in_ctrl, in_s, in_t;
    bool flagInversia;
    bool flagHelp, flagShag;
    int i;
    int plusInt, minusDec, shag;
    int  mPosX, mPosY;

    bool flagZoom;

private slots:
    void on_button_on_power_clicked();
    void on_button_test_power_clicked();
    void on_button_exit_clicked();
    void on_button_adjustment_clicked();
    void on_button_Ak_74_clicked();
    void on_button_Ak_103_clicked();
    void on_button_Ak_12_clicked();
    void on_button_PKT_clicked();
    void on_button_SVD_clicked();

    void setPosX_Y(int pPosX, int pPosY);
};

#endif // MAINWINDOW_H
