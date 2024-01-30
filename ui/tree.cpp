#include "tree.h"
#include "ItemTable.h"

Tree::Tree(QWidget *parent)
    : QWidget(parent)
{
    //QPixmap icon_database("img_database.png");
    //mTree.icon->setPixmap(icon_database);
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