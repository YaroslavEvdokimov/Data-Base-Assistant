#include "status_bar_button.h"

#include <QPushButton>
#include <iostream>

SatausBarButton::SatausBarButton(QWidget *parent)
    : QWidget(parent)
{
    setParent(parent);
    setupUi(parent);
    ButtonSide->hide();

    connect(SatausBarButton::StatusButton, &QPushButton::clicked, this,  qOverload<>(&SatausBarButton::on_StatusButton_clicked));
}

void SatausBarButton::setTextButton(std::string text)
{
    StatusButton->setText(QCoreApplication::translate("StatusBarButton", text.c_str(), nullptr));
}

void SatausBarButton::addParameter(std::string param)
{
    if (mParam.empty())
    {
        mParam.emplace(param, std::make_unique<Item>(ButtonSide, 0, param));
    }else 
    {
        ButtonSide->setFixedHeight(mHeight+ 30);
        mParam.emplace(param, std::make_unique<Item>(ButtonSide, mHeight, param));
        mHeight = mHeight + 30;
    }

    connect(mParam[param].get(), &Item::signal, this,  &SatausBarButton::on_Param_clicked);
    ButtonSide->setStyleSheet("border: 1px solid rgb(77, 76, 76); background-color: rgb(33, 33, 34);");
    
 
}
void SatausBarButton::on_Param_clicked()
{
    emit signal();
}

void SatausBarButton::on_StatusButton_clicked()
{
    if (mActive == true)
    {
        mActive = false;
        ButtonSide->hide();
        StatusButton->setStyleSheet("background-color: rgb(60, 60, 61); border: 0px solid rgb(77, 76, 76)");
    }else 
    {
        mActive = true;
        StatusButton->setStyleSheet("background-color: rgb(47, 47, 48); border: 0px solid rgb(77, 76, 76)");
        ButtonSide->show();
    }
}


