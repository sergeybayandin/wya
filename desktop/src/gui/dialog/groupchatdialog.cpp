#include "ui_groupchatdialog.h"

#include "gui/dialog/groupchatdialog.h"

#include "core/user.h"

#include <QDebug>
#include <QScrollBar>

namespace gui::dialog {

GroupChatDialog::GroupChatDialog(
    int            groupId,
    const QString &groupName,
    QWidget       *parent
)
    : QDialog {parent},
      ui      {new Ui::GroupChatDialog},
      groupId_{groupId}
{
    ui->setupUi(this);
    setWindowTitle(groupName);
    _setConnects();
}

GroupChatDialog::~GroupChatDialog() {
    delete ui;
}

void GroupChatDialog::addMessageBox(box::MessageBox *messageBox) {
    qDebug() << "add message box\n";
    ui->messageBoxesVerticalLayout->addWidget(messageBox);
}

void GroupChatDialog::on_messageLineEdit_returnPressed() {
    auto textMessage{ui->messageLineEdit->text()};
    if (!textMessage.isEmpty()) {
        _addSelfMessageBox();
        ui->messageLineEdit->clear();
        emit textMessageEntered(groupId_, textMessage);
    }
}

void GroupChatDialog::_addSelfMessageBox() {
    auto textMessage{ui->messageLineEdit->text()};
    auto messageBox {new box::MessageBox{
        core::User::user().id(),
        core::User::user().login(),
        textMessage
    }};
    addMessageBox(messageBox);
}

void GroupChatDialog::_setConnects() {
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

void GroupChatDialog::on_joinPushButton_clicked() {
    ui->joinPushButton->setDisabled(true);
    emit userWannaJoinToGroup(groupId_, windowTitle());
}

void GroupChatDialog::setChatPage() {
    ui->stackedWidget->setCurrentWidget(ui->chatPage);
}

void GroupChatDialog::setJoinPage() {
    ui->stackedWidget->setCurrentWidget(ui->joinPage);
}

} // dialog
