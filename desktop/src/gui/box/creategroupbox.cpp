#include "ui_creategroupbox.h"

#include "gui/box/creategroupbox.h"

namespace gui::box {

CreateGroupBox::CreateGroupBox(QWidget *parent) :
    QGroupBox{parent},
    ui       {new Ui::CreateGroupBox}
{
    ui->setupUi(this);
    ui->groupNameLineEdit->setHidden(true);
}

CreateGroupBox::~CreateGroupBox() {
    delete ui;
}

void CreateGroupBox::on_createPushButton_clicked() {
    ui->createPushButton->setHidden(true);
    ui->groupNameLineEdit->setHidden(false);
    ui->groupNameLineEdit->setFocus();
}

void CreateGroupBox::on_groupNameLineEdit_returnPressed() {
    auto groupName{ui->groupNameLineEdit->text()};

    ui->createPushButton->setHidden(false);
    ui->groupNameLineEdit->setHidden(true);

    ui->groupNameLineEdit->clear();

    if (!groupName.isEmpty()) {
        emit groupCreated(groupName);
    }
}

} // box
