#include "tree.h"

Tree::Tree(QWidget *parent)
    : QWidget(parent)
{

}

void Tree::setupWidget(QWidget *parent)
{
    setParent(parent);
    mTree.setupUi(parent);
    mTree.database->setGeometry(QRect(0, 22, 360, 1008));
    mTree.lbl_data->setText(QCoreApplication::translate("Tree", "DATABASE", nullptr));
}

void Tree::setDatabase(std::string name)
{
    mTree.lbl_database->setText(QCoreApplication::translate("Tree", name.c_str() , nullptr));
}