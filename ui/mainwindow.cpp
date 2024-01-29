#include "mainwindow.h"
#include "../handler/DataBaseHandler.h"

MainScreen::MainScreen(QMainWindow *parent)
    : QWidget(parent)
{
    Handler::DataBaseHandler::init();

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

    std::string database = Handler::DataBaseHandler::get()->open(filename.toStdString());
    mTree.setDatabase(filename.toStdString());

}