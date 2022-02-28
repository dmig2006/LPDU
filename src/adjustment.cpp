#include "adjustment.h"
#include "ui_adjustment.h"

Adjustment::Adjustment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adjustment)
{
    ui -> setupUi(this);
    move(1280,170);

    posX = 0;
    posY = 0;

    readFileX();
    readFileY();

}

Adjustment::~Adjustment()
{
    delete ui;
}

void Adjustment::readFileX()
{
    QString filename1 = FILEDIR_X;
    QFile file(filename1);

    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QString str1 = in.readLine();
    posX = str1.toInt();
    file.close();
}

void Adjustment::readFileY()
{
    QString filename = FILEDIR_Y;
    QFile file(filename);
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextStream in(&file);
    QString str1 = in.readLine();
    posY = str1.toInt();
    file.close();
}

void Adjustment::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
        case Qt::Key_W:
            on_upButton_clicked();
        break;

        case Qt::Key_S:
            on_downButton_clicked();
        break;

        case Qt::Key_A:
            on_leftButton_clicked();
        break;

        case Qt::Key_D:
            on_rightButton_clicked();
        break;

        case Qt::Key_C:
            on_centerButton_clicked();
        break;

        case Qt::Key_Return:
            on_acceptButton_clicked();
        break;

        case Qt::Key_Escape:
            on_exitButton_clicked();
        break;
    }
}

void Adjustment::on_leftButton_clicked()
{
//    emit newLogMsg("влево");
    emit newPosX(false);
}

void Adjustment::on_rightButton_clicked()
{
//    emit newLogMsg("вправо");
    emit newPosX(true);
}

void Adjustment::on_upButton_clicked()
{
//    emit newLogMsg("вверх");
    emit newPosY(true);
}

void Adjustment::on_downButton_clicked()
{
//    emit newLogMsg("вниз");
    emit newPosY(false);
}

void Adjustment::on_centerButton_clicked()
{
//    emit newLogMsg("Centr");
    emit newPosX_Y(CENTRPOSX,CENTRPOSY);
}

void Adjustment::on_acceptButton_clicked()
{
//    emit newLogMsg("принять");
    readFileX();
    readFileY();
    emit newPosX_Y(posX, posY);
    close();
}

void Adjustment::on_exitButton_clicked()
{
//    emit newLogMsg("выход");
    close();
}


