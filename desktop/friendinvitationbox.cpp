#include "friendinvitationbox.h"
#include "ui_friendinvitationbox.h"

FriendInvitationBox::FriendInvitationBox(QWidget *parent) :
    QGroupBox{parent},
    ui       {new Ui::FriendInvitationBox}
{
    ui->setupUi(this);
}

FriendInvitationBox::~FriendInvitationBox()
{
    delete ui;
}
