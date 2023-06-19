#include "ui_friendchatdialog.h"

#include "gui/dialog/friendchatdialog.h"

#include "core/user.h"

#include <QDebug>
#include <QScrollBar>

namespace gui::dialog {

FriendChatDialog::FriendChatDialog(
    int            friendId,
    const QString &friendLogin,
    QWidget       *parent
) :
    QDialog  {parent},
    ui       {new Ui::FriendChatDialog},
    friendId_{friendId}
{
    ui->setupUi(this);
    setWindowTitle(friendLogin);
    _setConnects();
}

FriendChatDialog::~FriendChatDialog() {
    delete ui;
}

void FriendChatDialog::on_messageLineEdit_returnPressed() {
    ui->sendPushButton->click();
}

void FriendChatDialog::addMessageBox(box::MessageBox *messageBox) {
    qDebug() << "add message box\n";
    ui->messageBoxesVerticalLayout->addWidget(messageBox);
}

void FriendChatDialog::_addSelfMessageBox() {
    auto textMessage{ui->messageLineEdit->text()};
    auto messageBox {new box::MessageBox{
        core::User::user().id(),
        core::User::user().login(),
        textMessage
    }};
    addMessageBox(messageBox);
}

void FriendChatDialog::_setConnects() {
    connect(
        ui->scrollArea->verticalScrollBar(),
        &QScrollBar::rangeChanged,
        this,
        [this](int _, int max) {
            Q_UNUSED(_);
            ui->scrollArea->verticalScrollBar()->setValue(max);
        }
    );
}

void FriendChatDialog::on_sendPushButton_clicked() {
    auto textMessage{ui->messageLineEdit->text()};
    if (!textMessage.isEmpty()) {
        _addSelfMessageBox();
        ui->messageLineEdit->clear();
        emit textMessageEntered(friendId_, textMessage);
    }
}

} // dialog
