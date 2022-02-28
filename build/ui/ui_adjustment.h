/********************************************************************************
** Form generated from reading UI file 'adjustment.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADJUSTMENT_H
#define UI_ADJUSTMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Adjustment
{
public:
    QPushButton *centerButton;
    QFrame *line_3;
    QFrame *line_2;
    QPushButton *downButton;
    QPushButton *upButton;
    QFrame *line_4;
    QPushButton *acceptButton;
    QFrame *line;
    QPushButton *leftButton;
    QPushButton *rightButton;
    QPushButton *exitButton;

    void setupUi(QDialog *Adjustment)
    {
        if (Adjustment->objectName().isEmpty())
            Adjustment->setObjectName(QStringLiteral("Adjustment"));
        Adjustment->resize(508, 192);
        centerButton = new QPushButton(Adjustment);
        centerButton->setObjectName(QStringLiteral("centerButton"));
        centerButton->setGeometry(QRect(130, 70, 90, 30));
        line_3 = new QFrame(Adjustment);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(175, 45, 3, 20));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Adjustment);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(105, 85, 20, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        downButton = new QPushButton(Adjustment);
        downButton->setObjectName(QStringLiteral("downButton"));
        downButton->setGeometry(QRect(130, 130, 90, 30));
        QFont font;
        font.setPointSize(18);
        font.setBold(false);
        font.setWeight(50);
        downButton->setFont(font);
        upButton = new QPushButton(Adjustment);
        upButton->setObjectName(QStringLiteral("upButton"));
        upButton->setGeometry(QRect(130, 10, 90, 30));
        QFont font1;
        font1.setPointSize(18);
        upButton->setFont(font1);
        line_4 = new QFrame(Adjustment);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(175, 105, 3, 20));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        acceptButton = new QPushButton(Adjustment);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));
        acceptButton->setGeometry(QRect(380, 10, 111, 30));
        line = new QFrame(Adjustment);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(225, 85, 20, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        leftButton = new QPushButton(Adjustment);
        leftButton->setObjectName(QStringLiteral("leftButton"));
        leftButton->setGeometry(QRect(10, 70, 90, 30));
        leftButton->setFont(font1);
        rightButton = new QPushButton(Adjustment);
        rightButton->setObjectName(QStringLiteral("rightButton"));
        rightButton->setGeometry(QRect(250, 70, 90, 30));
        rightButton->setFont(font1);
        exitButton = new QPushButton(Adjustment);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(380, 146, 111, 30));

        retranslateUi(Adjustment);

        QMetaObject::connectSlotsByName(Adjustment);
    } // setupUi

    void retranslateUi(QDialog *Adjustment)
    {
        Adjustment->setWindowTitle(QApplication::translate("Adjustment", "Dialog", Q_NULLPTR));
        centerButton->setText(QApplication::translate("Adjustment", "\320\246\320\265\320\275\321\202\321\200", Q_NULLPTR));
        downButton->setText(QApplication::translate("Adjustment", "\342\206\223", Q_NULLPTR));
        upButton->setText(QApplication::translate("Adjustment", "\342\206\221", Q_NULLPTR));
        acceptButton->setText(QApplication::translate("Adjustment", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", Q_NULLPTR));
        leftButton->setText(QApplication::translate("Adjustment", "\342\206\220", Q_NULLPTR));
        rightButton->setText(QApplication::translate("Adjustment", "\342\206\222", Q_NULLPTR));
        exitButton->setText(QApplication::translate("Adjustment", "\320\222\321\213\321\205\320\276\320\264", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Adjustment: public Ui_Adjustment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADJUSTMENT_H
