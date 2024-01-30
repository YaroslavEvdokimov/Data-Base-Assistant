#pragma once 
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include "ui_ItemTable.h"

class ItemTable : public QWidget, private Ui::ItemTable
{
    Q_OBJECT

public:
    explicit ItemTable(QWidget *parent, int position, std::string name);

private slots:
    //void on_btn_clicked();
signals:
    //void signal();
public:
    //QPushButton* getButton();

};