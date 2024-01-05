#include <iostream>
#include <QApplication>
#include <QTextEdit>

// #include "ui_mainwindow.h"
#include "ui/mainwindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QMainWindow src;
    MainScreen main_scr(&src);

    src.show();


    return app.exec();
}