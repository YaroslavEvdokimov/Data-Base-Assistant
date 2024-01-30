#include "ItemTable.h"
#include <iostream>
ItemTable::ItemTable(QWidget *parent, int position, std::string name)
    : QWidget(parent)
{
    setParent(parent);
    setupUi(parent);

    // btn->setText(QCoreApplication::translate("Item", name.c_str(), nullptr));

    // setGeometry(QRect(0, position, 260, 30));
    // btn->setGeometry(QRect(0, position, 260, 30));

    // connect(Item::btn, &QPushButton::clicked, this, qOverload<>(&Item::on_btn_clicked));
}

// void Item::on_btn_clicked()
// {
//     if (btn->text() == "Открыть базу данных")
//     {
//         std::cout << "Открыть базу данных" << std::endl;
//         emit signal();
//     }
// }


// QPushButton* Item::getButton()
// {
//     return btn;
// }