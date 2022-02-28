#include <QApplication> //подключаем библиотеки QApplication
#include "mainwindow.h" // Подключаем файл mainwindow.h, он становится дочерним к main 

int main(int argc, char *argv[]) //головная программа
{
    QApplication app(argc, argv);  // создание объекта для управления всеми ресурсами проекта

    MainWindow lMainWindow; //результат из MainWindow записывается в lMainWindow
    lMainWindow.show(); // выводим на экран резльтат из lMainWindow
    lMainWindow.setWindowState(Qt::WindowFullScreen);
    return app.exec(); // передача управления переходит к QT приложение ожидает действия со стороны пользователя аналог readln
}
