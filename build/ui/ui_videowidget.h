/********************************************************************************
** Form generated from reading UI file 'videowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWIDGET_H
#define UI_VIDEOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VideoWidget
{
public:
    QLabel *picture;
    QTextEdit *helpEdit;
    QListWidget *list_log;
    QListWidget *listHelp;

    void setupUi(QWidget *VideoWidget)
    {
        if (VideoWidget->objectName().isEmpty())
            VideoWidget->setObjectName(QStringLiteral("VideoWidget"));
        VideoWidget->resize(1366, 768);
        picture = new QLabel(VideoWidget);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(0, 0, 1366, 768));
        helpEdit = new QTextEdit(VideoWidget);
        helpEdit->setObjectName(QStringLiteral("helpEdit"));
        helpEdit->setGeometry(QRect(1070, 600, 291, 161));
        helpEdit->setFocusPolicy(Qt::NoFocus);
        list_log = new QListWidget(VideoWidget);
        list_log->setObjectName(QStringLiteral("list_log"));
        list_log->setGeometry(QRect(790, 530, 271, 231));
        listHelp = new QListWidget(VideoWidget);
        listHelp->setObjectName(QStringLiteral("listHelp"));
        listHelp->setGeometry(QRect(1075, 530, 281, 61));

        retranslateUi(VideoWidget);

        QMetaObject::connectSlotsByName(VideoWidget);
    } // setupUi

    void retranslateUi(QWidget *VideoWidget)
    {
        VideoWidget->setWindowTitle(QApplication::translate("VideoWidget", "Form", Q_NULLPTR));
        picture->setText(QString());
        helpEdit->setHtml(QApplication::translate("VideoWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 'F1' - \320\241\320\277\321\200\320\260\320\262\320\272\320\260</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 'Q' - \320\256\321\201\321\202\320\270\321\200\320\276\320\262\320\272\320\260</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 '"
                        "1' - 640x480</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 '-' - \320\243\320\274\320\265\320\275\321\214\321\210\320\265\320\275\320\270\320\265 Zoom</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 '+' - \320\243\320\262\320\265\320\273\320\265\321\207\320\265\320\275\320\270\320\265 Zoom</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\264\320\260\320\262\320\270\321\210\320\260 'O' - \320\241\320\274\320\265\320\275\320\260 \320\277\321\200\320\270\321\206\320\265\320\273\320\260</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\232\320\273\320\260\320\262\320\270"
                        "\321\210\320\260 'Esc' - \320\222\321\213\321\205\320\276\320\264</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 '2' - 800x600</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 '3' - 1024x768</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#ffffff;\">\320\232\320\273\320\260\320\262\320\270\321\210\320\260 '4' - 1920x1020</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; color:#000000;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VideoWidget: public Ui_VideoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWIDGET_H
