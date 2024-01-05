#pragma once 
#include <QApplication>
#include <QTextEdit>
#include "Item.h"
#include "ui_status_bar_button.h"

class SatausBarButton : public QWidget, private Ui::StatusBarButton
{
    Q_OBJECT

public:
    explicit SatausBarButton(QWidget *parent = nullptr);

    void setTextButton(std::string text);
    void addParameter(std::string param);

private slots:
    void on_StatusButton_clicked();
    void on_Param_clicked();
signals:
    void signal();

private:
    bool mActive = false;
    int mHeight = 30;

    std::map<std::string, std::unique_ptr<Item>> mParam;
};