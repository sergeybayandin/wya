#include "ui_friendbox.h"

#include "gui/box/friendbox.h"

#include "core/user.h"

namespace gui::box {

FriendBox::FriendBox(int friendId, QWidget *parent) :
    QGroupBox{parent},
    ui       {new Ui::FriendBox},
    friendId_{friendId}
{
    ui->setupUi(this);
    _setFriendBox();
}

FriendBox::~FriendBox() {
    delete ui;
}

QLabel *FriendBox::friendLoginLabel() const noexcept {
    return ui->friendLoginLabel;
}

int FriendBox::friendId() const noexcept {
    return friendId_;
}

void FriendBox::_setFriendBox() {
    ui->friendLoginLabel->setText(
        core::User::user().friends()[friendId_].login()
    );
}

void FriendBox::mousePressEvent(QMouseEvent *mouseEvent) {
    QGroupBox::mousePressEvent(mouseEvent);
}

void FriendBox::mouseReleaseEvent(QMouseEvent *mouseEvent) {
    emit friendBoxClicked(friendId_);
    QGroupBox::mouseReleaseEvent(mouseEvent);
}

} // box
