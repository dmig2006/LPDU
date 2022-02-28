/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actionStand_by_mode;
    QAction *actionOperation_mode;
    QAction *actionBurst_length;
    QAction *actionAmmunition;
    QAction *actionClose;
    QAction *actionSound_signal;
    QAction *actionAdjustment;
    QAction *action_2;
    QAction *actionNormal_mode;
    QAction *actionPicture_in_picture;
    QAction *actionSmall_picture_in_picture;
    QAction *actionHorizontal_line;
    QAction *actionVertical_line;
    QAction *actionDigital_stabilization;
    QAction *actionPID;
    QWidget *centralWidget;
    QListWidget *list_log;
    QPushButton *button_SVD;
    QPushButton *button_PKT;
    QPushButton *button_Ak_12;
    QPushButton *button_Ak_103;
    QPushButton *button_Ak_74;
    QPushButton *button_test_power;
    QPushButton *button_on_power;
    QPushButton *button_adjustment;
    QPushButton *button_exit;
    QLabel *label_sensors;
    QLabel *label_voltage;
    QLabel *label_ammunition;
    QLabel *label_mode_voltage;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setWindowModality(Qt::WindowModal);
        MainWindow->setEnabled(true);
        MainWindow->resize(1366, 768);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        MainWindow->setAcceptDrops(false);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QLatin1String("QWidget#widget{\n"
"     border-style: solid;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"	 border-color: rgb(0,0,0);\n"
"     padding: 6px;\n"
" }\n"
"QGroupBox {\n"
"     border-style: solid;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"	 border-color: rgb(205, 205, 205);\n"
"     padding: 6px;\n"
" }\n"
"QListView{\n"
"     border-style: solid;\n"
"     border-width: 1px;\n"
"     border-radius: 10px;\n"
"	 border-color: rgb(205, 205, 205);\n"
"     padding: 6px;\n"
" }"));
        MainWindow->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        MainWindow->setAnimated(false);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Triangular);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        action->setEnabled(false);
        actionStand_by_mode = new QAction(MainWindow);
        actionStand_by_mode->setObjectName(QStringLiteral("actionStand_by_mode"));
        actionStand_by_mode->setCheckable(true);
        actionStand_by_mode->setChecked(false);
        actionStand_by_mode->setEnabled(true);
        actionStand_by_mode->setAutoRepeat(false);
        actionOperation_mode = new QAction(MainWindow);
        actionOperation_mode->setObjectName(QStringLiteral("actionOperation_mode"));
        actionOperation_mode->setCheckable(true);
        actionOperation_mode->setChecked(true);
        actionOperation_mode->setEnabled(true);
        actionOperation_mode->setAutoRepeat(false);
        actionBurst_length = new QAction(MainWindow);
        actionBurst_length->setObjectName(QStringLiteral("actionBurst_length"));
        actionAmmunition = new QAction(MainWindow);
        actionAmmunition->setObjectName(QStringLiteral("actionAmmunition"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionSound_signal = new QAction(MainWindow);
        actionSound_signal->setObjectName(QStringLiteral("actionSound_signal"));
        actionAdjustment = new QAction(MainWindow);
        actionAdjustment->setObjectName(QStringLiteral("actionAdjustment"));
        action_2 = new QAction(MainWindow);
        action_2->setObjectName(QStringLiteral("action_2"));
        action_2->setEnabled(false);
        actionNormal_mode = new QAction(MainWindow);
        actionNormal_mode->setObjectName(QStringLiteral("actionNormal_mode"));
        actionNormal_mode->setEnabled(true);
        actionNormal_mode->setAutoRepeat(true);
        actionPicture_in_picture = new QAction(MainWindow);
        actionPicture_in_picture->setObjectName(QStringLiteral("actionPicture_in_picture"));
        actionSmall_picture_in_picture = new QAction(MainWindow);
        actionSmall_picture_in_picture->setObjectName(QStringLiteral("actionSmall_picture_in_picture"));
        actionHorizontal_line = new QAction(MainWindow);
        actionHorizontal_line->setObjectName(QStringLiteral("actionHorizontal_line"));
        actionVertical_line = new QAction(MainWindow);
        actionVertical_line->setObjectName(QStringLiteral("actionVertical_line"));
        actionDigital_stabilization = new QAction(MainWindow);
        actionDigital_stabilization->setObjectName(QStringLiteral("actionDigital_stabilization"));
        actionPID = new QAction(MainWindow);
        actionPID->setObjectName(QStringLiteral("actionPID"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        list_log = new QListWidget(centralWidget);
        list_log->setObjectName(QStringLiteral("list_log"));
        list_log->setGeometry(QRect(800, 470, 141, 141));
        button_SVD = new QPushButton(centralWidget);
        button_SVD->setObjectName(QStringLiteral("button_SVD"));
        button_SVD->setGeometry(QRect(805, 427, 131, 31));
        button_PKT = new QPushButton(centralWidget);
        button_PKT->setObjectName(QStringLiteral("button_PKT"));
        button_PKT->setGeometry(QRect(805, 377, 131, 31));
        button_Ak_12 = new QPushButton(centralWidget);
        button_Ak_12->setObjectName(QStringLiteral("button_Ak_12"));
        button_Ak_12->setGeometry(QRect(805, 327, 131, 31));
        button_Ak_103 = new QPushButton(centralWidget);
        button_Ak_103->setObjectName(QStringLiteral("button_Ak_103"));
        button_Ak_103->setGeometry(QRect(805, 277, 131, 31));
        button_Ak_74 = new QPushButton(centralWidget);
        button_Ak_74->setObjectName(QStringLiteral("button_Ak_74"));
        button_Ak_74->setGeometry(QRect(805, 227, 131, 31));
        button_test_power = new QPushButton(centralWidget);
        button_test_power->setObjectName(QStringLiteral("button_test_power"));
        button_test_power->setGeometry(QRect(805, 177, 131, 31));
        button_on_power = new QPushButton(centralWidget);
        button_on_power->setObjectName(QStringLiteral("button_on_power"));
        button_on_power->setGeometry(QRect(805, 127, 131, 31));
        button_adjustment = new QPushButton(centralWidget);
        button_adjustment->setObjectName(QStringLiteral("button_adjustment"));
        button_adjustment->setGeometry(QRect(805, 77, 131, 31));
        button_exit = new QPushButton(centralWidget);
        button_exit->setObjectName(QStringLiteral("button_exit"));
        button_exit->setGeometry(QRect(805, 27, 131, 31));
        QPalette palette;
        button_exit->setPalette(palette);
        label_sensors = new QLabel(centralWidget);
        label_sensors->setObjectName(QStringLiteral("label_sensors"));
        label_sensors->setGeometry(QRect(10, 10, 701, 17));
        label_voltage = new QLabel(centralWidget);
        label_voltage->setObjectName(QStringLiteral("label_voltage"));
        label_voltage->setGeometry(QRect(10, 30, 701, 17));
        label_ammunition = new QLabel(centralWidget);
        label_ammunition->setObjectName(QStringLiteral("label_ammunition"));
        label_ammunition->setGeometry(QRect(10, 50, 701, 17));
        label_mode_voltage = new QLabel(centralWidget);
        label_mode_voltage->setObjectName(QStringLiteral("label_mode_voltage"));
        label_mode_voltage->setGeometry(QRect(570, 90, 221, 20));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(action, SIGNAL(changed()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "lmbdu", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        MainWindow->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        action->setText(QApplication::translate("MainWindow", "Adjustment", Q_NULLPTR));
        actionStand_by_mode->setText(QApplication::translate("MainWindow", "Stand-by mode", Q_NULLPTR));
        actionOperation_mode->setText(QApplication::translate("MainWindow", "Operation mode", Q_NULLPTR));
        actionBurst_length->setText(QApplication::translate("MainWindow", "Set Burst length", Q_NULLPTR));
        actionAmmunition->setText(QApplication::translate("MainWindow", "Set Ammunition", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "Turn off", Q_NULLPTR));
        actionSound_signal->setText(QApplication::translate("MainWindow", "Sound signal", Q_NULLPTR));
        actionAdjustment->setText(QApplication::translate("MainWindow", "Adjustment", Q_NULLPTR));
        action_2->setText(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        actionNormal_mode->setText(QApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        actionPicture_in_picture->setText(QApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\320\270\320\275\320\272\320\260 \320\262 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265", Q_NULLPTR));
        actionSmall_picture_in_picture->setText(QApplication::translate("MainWindow", "\320\234\320\260\320\273\320\260\321\217 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\260 \320\262 \320\272\320\260\321\200\321\202\320\270\320\275\320\272\320\265", Q_NULLPTR));
        actionHorizontal_line->setText(QApplication::translate("MainWindow", "\320\223\320\276\321\200\320\270\320\267\320\276\320\275\321\202\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        actionVertical_line->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\265 \321\200\320\260\320\267\320\264\320\265\320\273\320\265\320\275\320\270\320\265", Q_NULLPTR));
        actionDigital_stabilization->setText(QApplication::translate("MainWindow", "\320\246\320\270\321\204\321\200\320\276\320\262\320\260\321\217 \321\201\321\202\320\260\320\261\320\270\320\273\320\270\320\267\320\260\321\206\320\270\321\217", Q_NULLPTR));
        actionPID->setText(QApplication::translate("MainWindow", "PID", Q_NULLPTR));
        button_SVD->setText(QApplication::translate("MainWindow", "\320\241\320\222\320\224", Q_NULLPTR));
        button_PKT->setText(QApplication::translate("MainWindow", "\320\237\320\232\320\242", Q_NULLPTR));
        button_Ak_12->setText(QApplication::translate("MainWindow", "\320\220\320\232-12", Q_NULLPTR));
        button_Ak_103->setText(QApplication::translate("MainWindow", "\320\220\320\232-103", Q_NULLPTR));
        button_Ak_74->setText(QApplication::translate("MainWindow", "\320\220\320\232-74", Q_NULLPTR));
        button_test_power->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\266\321\203\321\200\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        button_on_power->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\261\320\276\321\207\320\270\320\271 \321\200\320\265\320\266\320\270\320\274", Q_NULLPTR));
        button_adjustment->setText(QApplication::translate("MainWindow", "\320\256\321\201\321\202\320\270\321\200\320\276\320\262\320\272\320\260", Q_NULLPTR));
        button_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        label_sensors->setText(QString());
        label_voltage->setText(QString());
        label_ammunition->setText(QString());
        label_mode_voltage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
