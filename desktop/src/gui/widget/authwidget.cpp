#include "ui_authwidget.h"

#include "gui/widget/authwidget.h"

namespace gui::widget {

AuthWidget::AuthWidget(QWidget *parent)
    : QWidget{parent},
      ui     {new Ui::AuthWidget}
{
    ui->setupUi(this);
}

AuthWidget::~AuthWidget() {
    delete ui;
}

void AuthWidget::on_loginPushButton_clicked() {
    auto login   {ui->loginLineEdit->text()};
    auto password{ui->passwordLineEdit->text()};

    if (login.isEmpty() || password.isEmpty()) {
        return;
    }

    emit userAuthorized(login, password);
}

void AuthWidget::on_registerPushButton_clicked() {
    auto login   {ui->loginLineEdit->text()};
    auto password{ui->passwordLineEdit->text()};

    if (login.isEmpty() || password.isEmpty()) {
        return;
    }

    emit userRegistered(login, password);
}

} // widget
