#include "mainwindow.h"

MainScreen::MainScreen(QMainWindow *parent)
    : QWidget(parent)
{
    mScreen.setupUi(parent);
    mTree.setupWidget(getScreen());
    mStatusBtn = new SatausBarButton(getScreen()); 

    mStatusBtn->addParameter("Открыть базу данных");
    mStatusBtn->addParameter("Сохранить базу данных");
    mStatusBtn->addParameter("Сохранить как...");

    mStatusBtn->setTextButton("Файл");

    connect(mStatusBtn, &SatausBarButton::signal , this, &MainScreen::openFileForm);
}

QWidget *MainScreen::getScreen()
{
    return mScreen.centralwidget;
}

void MainScreen::openFileForm()
{
    QString filename = QFileDialog::getOpenFileName(this, "Отркыть", QDir::currentPath());

    mTree.setDatabase(filename.toStdString());

}