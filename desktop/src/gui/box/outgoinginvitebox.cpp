#include "ui_outgoinginvitebox.h"

#include "gui/box/outgoinginvitebox.h"

#include "core/user.h"

namespace gui::box {

OutgoingInviteBox::OutgoingInviteBox(int toUserId, QWidget *parent) :
    QGroupBox{parent},
    ui       {new Ui::OutgoingInviteBox},
    toUserId_{toUserId}
{
    ui->setupUi(this);
    _setOutgoingInviteBox();
}

OutgoingInviteBox::~OutgoingInviteBox() {
    delete ui;
}

void OutgoingInviteBox::on_cancelPushButton_clicked() {
    emit inviteCanceled(toUserId_);
}

QLabel *OutgoingInviteBox::toUserLoginLabel() const noexcept {
    return ui->toUserLoginLabel;
}

int OutgoingInviteBox::toUserId() const noexcept {
    return toUserId_;
}

void OutgoingInviteBox::_setOutgoingInviteBox() {
    ui->toUserLoginLabel->setText(
        core::User::user().outgoingInvites()[toUserId_].toUserLogin()
    );
}

} // box
