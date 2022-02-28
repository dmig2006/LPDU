#ifndef ADJUSTMENT_H
#define ADJUSTMENT_H

#include <QDialog>
#include <QKeyEvent>

#include "optwidget.h"

namespace Ui {
class Adjustment;
}

class Adjustment : public QDialog
{
    Q_OBJECT

public:
    explicit Adjustment(QWidget *parent = 0);
    ~Adjustment();
    void on_acceptButton_clicked();

    int posX,posY;

private:
    void readFileX();
    void readFileY();

    Ui::Adjustment *ui;

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_upButton_clicked();
    void on_downButton_clicked();
    void on_centerButton_clicked();
    void on_exitButton_clicked();

public slots:

signals:
    void newPosX(bool pFlag);
    void newPosY(bool pFlag);
    void newPosX_Y(int pPosX, int pPosY);

    void newLogMsg(QString pString);
};

#endif // ADJUSTMENT_H
