#include "friendchatdialog.h"
#include "ui_friendchatdialog.h"

FriendChatDialog::FriendChatDialog(QWidget *parent) :
    QDialog{parent},
    ui     {new Ui::FriendChatDialog}
{
    ui->setupUi(this);
}

FriendChatDialog::~FriendChatDialog()
{
    delete ui;
}
