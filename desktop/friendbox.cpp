#include "friendbox.h"
#include "ui_friendbox.h"

FriendBox::FriendBox(QWidget *parent) :
    QGroupBox{parent},
    ui       {new Ui::FriendBox}
{
    ui->setupUi(this);
}

FriendBox::~FriendBox()
{
    delete ui;
}
