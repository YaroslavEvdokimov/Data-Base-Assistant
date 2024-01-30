#pragma once 
#include <QApplication>
#include <QTextEdit>
#include "ItemTable.h"
#include "ui_tree.h"

class Tree : public QWidget
{
    Q_OBJECT

public:
    Tree(QWidget *parent = nullptr);
    void setupWidget(QWidget *parent);

    void setDatabase(std::string name);

private slots:
    void updateResult(){};

private:
    Ui::Tree mTree;
    std::vector<std::unique_ptr<ItemTable>> mItemTable;
};