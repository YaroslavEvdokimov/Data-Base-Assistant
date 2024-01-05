#pragma once 
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include "ui_Item.h"

class Item : public QWidget, private Ui::Item
{
    Q_OBJECT

public:
    explicit Item(QWidget *parent, int position, std::string name);

private slots:
    void on_btn_clicked();
signals:
    void signal();
public:
    QPushButton* getButton();

};