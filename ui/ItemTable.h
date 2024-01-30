#pragma once 
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "ui_ItemTable.h"

class ItemTable : public QWidget, private Ui::ItemTable
{
    Q_OBJECT

public:
    explicit ItemTable(QWidget *parent = nullptr);

private slots:
    //void on_btn_clicked();
signals:
    //void signal();
public:
    //QPushButton* getButton();

};