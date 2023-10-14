#include <iostream>
#include <QApplication>
#include <QTextEdit>

//#include "App.h"

//#include "./MainWindow.h"
#include "ui_MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
   // App *gui = new App;
   // gui->show();
    QMainWindow widget;
    Ui::MainWindow ui;
    ui.setupUi(&widget);

    widget.show();


    return app.exec();
}