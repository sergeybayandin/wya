#include "ui_messagebox.h"

#include "gui/box/messagebox.h"

namespace gui::box {

MessageBox::MessageBox(
    int            userId,
    const QString &userLogin,
    const QString &textMessage,
    QWidget       *parent
)
    : QGroupBox{parent},
      ui       {new Ui::MessageBox},
      userId_  {userId}
{
    ui->setupUi(this);

    _setMessageBox(userLogin, textMessage);
}

MessageBox::~MessageBox() {
    delete ui;
}

void MessageBox::_setMessageBox(
    const QString &userLoginText,
    const QString &textMessageText
) {
    ui->userLoginLabel->setText(userLoginText);
    ui->messageLabel->setText(textMessageText);
}

} // box
