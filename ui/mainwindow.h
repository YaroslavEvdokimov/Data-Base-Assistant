#pragma once 
#include <QApplication>
#include <QTextEdit>
#include <QFileDialog>
#include <QPushButton>

#include "ui_mainwindow.h"
#include "tree.h"
#include "status_bar_button.h"

class MainScreen : public QWidget
{
    Q_OBJECT

public:
    explicit MainScreen(QMainWindow *parent = nullptr);

private slots:
    void openFileForm();


private:
    QWidget *getScreen();
private:

    Ui::MainWindow mScreen;
    Tree mTree;
    SatausBarButton* mStatusBtn;
};