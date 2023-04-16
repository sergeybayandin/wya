#include "wyawidget.h"
#include "ui_wyawidget.h"

#include <QNetworkAccessManager>
#include <QCryptographicHash>

WyaWidget::WyaWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wyaWidget)
{
    ui->setupUi(this);
}

WyaWidget::~WyaWidget()
{
    delete ui;
}

void WyaWidget::on_loginPushButton_clicked()
{
    auto login   {ui->loginLineEdit->text()};
    auto password{ui->passwordLineEdit->text()};

    if (login.isEmpty() || password.isEmpty()) {
        return;
    }

    auto loginPasswordHash{QCryptographicHash::hash(
        (login + password).toLocal8Bit(), QCryptographicHash::Sha256
    )};
}


void WyaWidget::on_registerPushButton_clicked()
{

}

