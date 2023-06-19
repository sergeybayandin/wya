#include "ui_incominginvitebox.h"

#include "gui/box/incominginvitebox.h"

#include "core/user.h"

namespace gui::box {

IncomingInviteBox::IncomingInviteBox(int fromUserId, QWidget *parent) :
    QGroupBox  {parent},
    ui         {new Ui::IncomingInviteBox},
    fromUserId_{fromUserId}
{
    ui->setupUi(this);
    _setIncomingInviteBox();
}

IncomingInviteBox::~IncomingInviteBox() {
    delete ui;
}

void IncomingInviteBox::on_acceptPushButton_clicked() {
    emit inviteAccepted(fromUserId_);
}

void IncomingInviteBox::on_rejectPushButton_clicked() {
    emit inviteRejected(fromUserId_);
}

void IncomingInviteBox::_setIncomingInviteBox() {
    ui->fromUserLoginLabel->setText(
        core::User::user().incomingInvites()[fromUserId_].fromUserLogin()
    );
}

QLabel *IncomingInviteBox::fromUserLoginLabel() const noexcept {
    return ui->fromUserLoginLabel;
}

int IncomingInviteBox::fromUserId() const noexcept {
    return fromUserId_;
}

} // box
