#include "ui_wyawidget.h"

#include "gui/wyawidget.h"

#include "core/serverconfig.h"

#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <QCryptographicHash>

namespace gui {

WyaWidget::WyaWidget(QWidget *parent) :
    QWidget {parent},
    ui      {new Ui::wyaWidget},
    manager_{new QNetworkAccessManager{this}}
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

    auto loginPasswordHash{QString{QCryptographicHash::hash(
        (login + password).toLocal8Bit(), QCryptographicHash::Sha256
    )}};

    QJsonObject obj{
        {"login_password_hash", loginPasswordHash}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/" + "authorize"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply, &QNetworkReply::finished, this, [reply, this]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << reply->errorString() << '\n';
        } else {
            auto doc{QJsonDocument::fromJson(reply->readAll())};
            auto authorized{doc["authorized"].toBool()};

            if (authorized) {
                auto userId{doc["user_id"].toInt()};
                qDebug() << "Authorized! Your user id is " << userId << '\n';
                ui->stackedWidget->setCurrentIndex(1);
            } else {
                qDebug() << "Not authorized\n";
            }
        }
        reply->deleteLater();
    });
}

void WyaWidget::on_registerPushButton_clicked()
{
    auto login   {ui->loginLineEdit->text()};
    auto password{ui->passwordLineEdit->text()};

    if (login.isEmpty() || password.isEmpty()) {
        return;
    }

    auto loginPasswordHash{QString{QCryptographicHash::hash(
        (login + password).toLocal8Bit(), QCryptographicHash::Sha256
    )}};

    QJsonObject obj{
        {"login_password_hash", loginPasswordHash},
        {"login",               login}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/" + "register"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply, &QNetworkReply::finished, this, [reply]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << reply->errorString() << '\n';
        } else {
            auto doc{QJsonDocument::fromJson(reply->readAll())};
            auto registered{doc["registered"].toBool()};

            if (registered) {
                qDebug() << "You are registered!\n";
            } else {
                qDebug() << "You aren`t registered!\n";
            }
        }
        reply->deleteLater();
    });
}

} // gui
