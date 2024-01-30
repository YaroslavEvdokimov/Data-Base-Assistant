#include "ItemTable.h"

ItemTable::ItemTable(QWidget *parent)
    : QWidget(parent)
{
    setParent(parent);
    setupUi(parent);

    //table_name->setText(QCoreApplication::translate("Item", "123213123", nullptr));

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