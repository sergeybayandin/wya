#include "ui_wyawidget.h"

#include "gui/widget/wyawidget.h"

#include "core/user.h"
#include "core/serverconfig.h"
#include "core/types/action.h"

#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <QCryptographicHash>

namespace gui::widget {

WyaWidget::WyaWidget(QWidget *parent)
    : QWidget     {parent},
      ui          {new Ui::WyaWidget},
      authWidget_ {new AuthWidget},
      lobbyWidget_{new LobbyWidget},
      webSocket_  {new QWebSocket},
      manager_    {new QNetworkAccessManager}
{
    ui->setupUi(this);

    _setStackedWidget();
    _setWebSocket();
    _setConnects();
}

WyaWidget::~WyaWidget() {
    if (webSocket_->isValid()) {
        _sendGoOfflineAction();
    }

    webSocket_->deleteLater();
    manager_->deleteLater();

    delete ui;
}

void WyaWidget::_setStackedWidget() {
    ui->stackedWidget->addWidget(authWidget_);
    ui->stackedWidget->addWidget(lobbyWidget_);
}

void WyaWidget::_setWebSocket() {
    webSocket_->setParent(this);
}

void WyaWidget::_setConnects() {
    connect(
        authWidget_,
        SIGNAL(userAuthorized(const QString&, const QString&)),
        this,
        SLOT(_authorizeUser(const QString&, const QString&))
    );
    connect(
        authWidget_,
        SIGNAL(userRegistered(const QString&, const QString&)),
        this,
        SLOT(_registerUser(const QString&, const QString&))
    );
    connect(
        lobbyWidget_->groupsTabWidget()->createGroupBox(),
        SIGNAL(groupCreated(const QString&)),
        this,
        SLOT(_createGroup(const QString&))
    );
    connect(
        this,
        SIGNAL(needToDisplayCreatedGroup(int)),
        lobbyWidget_,
        SLOT(displayCreatedGroup(int))
    );
    connect(
        this,
        SIGNAL(needToDisplayFriendsAndGroups()),
        lobbyWidget_,
        SLOT(displayFriendsAndGroups())
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToGlobalSearch(const QString&)),
        this,
        SLOT(_globalSearch(const QString&))
    );
    connect(
        this,
        SIGNAL(needToDisplayGlobalSearchResults(const QVector<QPair<int, QString>>&)),
        lobbyWidget_,
        SLOT(displayGlobalSearchResults(const QVector<QPair<int, QString>>&))
    );
    connect(
        webSocket_,
        SIGNAL(error(QAbstractSocket::SocketError)),
        this,
        SLOT(_handleWebSocketError(QAbstractSocket::SocketError))
    );
    connect(
        webSocket_,
        SIGNAL(connected()),
        this,
        SLOT(_handleWebSocketConnected())
    );
    connect(
        webSocket_,
        SIGNAL(binaryMessageReceived(const QByteArray&)),
        this,
        SLOT(_handleWebSocketBinaryMessageReceived(const QByteArray&))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToSendToGroupTextMessage(int, const QString&)),
        this,
        SLOT(_sendToGroupTextMessage(int, const QString&))
    );
    connect(
        this,
        SIGNAL(needToDisplayReceivedMessageToGroup(int, int, const QString&, const QString&)),
        lobbyWidget_,
        SLOT(displayReceivedMessageToGroup(int, int, const QString&, const QString&))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToJoinUserToGroup(int, const QString &)),
        this,
        SLOT(_sendJoinUserToGroup(int, const QString &))
    );
    connect(
        this,
        SIGNAL(needToDisplayJoinedGroup(int)),
        lobbyWidget_,
        SLOT(displayJoinedGroup(int))
    );
}

void WyaWidget::_authorizeUser(const QString &login, const QString &password) {
    auto loginPasswordHash{QString{QCryptographicHash::hash(
        (login + password).toLocal8Bit(), QCryptographicHash::Sha256
    )}};

    QJsonObject obj{
        {"login_password_hash", loginPasswordHash}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/authorize"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply, &QNetworkReply::finished, this, [reply, login, this]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/authorize: " << reply->errorString() << '\n';
        } else {
            auto doc{QJsonDocument::fromJson(reply->readAll())};
            auto authorized{doc["authorized"].toBool()};

            if (authorized) {
                _doFriendsAndGroups(doc["user_id"].toInt(), login);
            } else {
                qDebug() << "Not authorized\n";
            }
        }
        reply->deleteLater();
    });
}

void WyaWidget::_registerUser(const QString &login, const QString &password) {
    auto loginPasswordHash{QString{QCryptographicHash::hash(
        (login + password).toLocal8Bit(), QCryptographicHash::Sha256
    )}};

    QJsonObject obj{
        {"login_password_hash", loginPasswordHash},
        {"login",               login}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/register"
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
            qDebug() << "/register: " << reply->errorString() << '\n';
        } else {
            auto doc       {QJsonDocument::fromJson(reply->readAll())};
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

void WyaWidget::_createGroup(const QString &groupName) {
    QJsonObject obj{
        {"group_name", groupName},
        {"owner_id",   core::User::user().id()},
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/create_group"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply, &QNetworkReply::finished, this, [reply, groupName, this]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/create_group: " << reply->errorString() << '\n';
        } else {
            auto doc{QJsonDocument::fromJson(reply->readAll())};
            _doCreateGroup(doc["group_id"].toInt(), groupName);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_doFriendsAndGroups(int userId, const QString &login) {
    qDebug() << "You are authorized!! Your id " << userId << '\n';
    qDebug() << "Preparing lobby...\n";

    QJsonObject     obj{{"user_id", userId}};
    QNetworkRequest request{
        core::ServerConfig::config().url() + "/friends&groups"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson())
    };

    connect(reply, &QNetworkReply::finished, this, [reply, userId, login, this]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/friends&groups: " << reply->errorString() << '\n';
        } else {
            auto doc{QJsonDocument::fromJson(reply->readAll())};

            auto friends(doc["friends"].toArray());
            auto groups (doc["groups"].toArray());

            core::User::user().setId(userId);
            core::User::user().setLogin(login);

            for (const auto &jsonValue : friends) {
                auto obj{jsonValue.toObject()};
                core::User::user().addFriend(
                    core::user::Friend{
                        obj["friend_id"].toInt(),
                        obj["friend_name"].toString()
                    }
                );
            }

            for (const auto &jsonValue : groups) {
                auto obj{jsonValue.toObject()};
                core::User::user().addGroup(
                    core::user::Group{
                        obj["group_id"].toInt(),
                        obj["group_name"].toString()
                    }
                );
            }
            webSocket_->open(core::ServerConfig::config().webSocketUrl() + "/ws");
        }
        reply->deleteLater();
    });
}

void WyaWidget::_doCreateGroup(int groupId, const QString &groupName) {
    qDebug() << "Group \'" << groupName << "\' created!! Group id " << groupId << '\n';
    core::User::user().addGroup(core::user::Group{groupId, groupName});
    emit needToDisplayCreatedGroup(groupId);
}

void WyaWidget::_globalSearch(const QString &groupNamePrefix) {
    QJsonObject obj{
        {"user_id",           core::User::user().id()},
        {"group_name_prefix", groupNamePrefix}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/global_search"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request, QJsonDocument{obj}.toJson()
    )};

    connect(reply, &QNetworkReply::finished, this, [reply, this]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/global_search: " << reply->errorString() << '\n';
        } else {
            auto doc                     {QJsonDocument::fromJson(reply->readAll())};
            auto globalSearchResultsArray(doc["global_search_result"].toArray());

            QVector<QPair<int, QString>> globalSearchResults;

            globalSearchResults.reserve(
                globalSearchResultsArray.size()
            );

            for (const auto &jsonValue : globalSearchResultsArray) {
                auto obj{jsonValue.toObject()};
                globalSearchResults += QPair{
                    obj["group_id"].toInt(),
                    obj["group_name"].toString()
                };
            }

            emit needToDisplayGlobalSearchResults(globalSearchResults);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_handleWebSocketError(QAbstractSocket::SocketError) {
    qDebug() << "Web socket error: " << webSocket_->errorString() << '\n';
}

void WyaWidget::_handleWebSocketConnected() {
    qDebug() << "Web socket connected!\n";

    _sendGoOnlineAction();

    emit needToDisplayFriendsAndGroups();

    ui->stackedWidget->setCurrentWidget(lobbyWidget_);
}

void WyaWidget::_handleWebSocketBinaryMessageReceived(const QByteArray &binaryMessage) {
    auto doc   {QJsonDocument::fromJson(binaryMessage)};
    auto action{static_cast<core::types::Action>(
        doc["action"].toInt()
    )};

    switch (action) {
    case core::types::SendToUser  :
        // TODO
        break;

    case core::types::SendToGroup :
        emit needToDisplayReceivedMessageToGroup(
            doc["user_id"].toInt(),
            doc["group_id"].toInt(),
            doc["user_login"].toString(),
            doc["message"].toString()
        );
        break;

    default                       :
        // ???
        break;
    }
}

void WyaWidget::_sendToGroupTextMessage(int groupId, const QString &messageText) {
    QJsonObject obj{
        {"action",     core::types::SendToGroup},
        {"user_id",    core::User::user().id()},
        {"user_login", core::User::user().login()},
        {"group_id",   groupId},
        {"message",    messageText}
    };
    webSocket_->sendBinaryMessage(QJsonDocument{obj}.toJson());
}

void WyaWidget::_sendJoinUserToGroup(int groupId, const QString &groupName) {
    QJsonObject obj{
        {"user_id", core::User::user().id()},
        {"group_id", groupId}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/join_group"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply,  &QNetworkReply::finished, this, [reply, groupId, groupName, this]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/join_group: " << reply->errorString() << '\n';
        } else {
            core::User::user().addGroup(core::user::Group{
                groupId,
                groupName
            });
            emit needToDisplayJoinedGroup(groupId);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_sendGoOnlineAction() {
    QJsonObject obj{
        {"action",  core::types::GoOnline},
        {"user_id", core::User::user().id()}
    };
    webSocket_->sendBinaryMessage(QJsonDocument{obj}.toJson());
}

void WyaWidget::_sendGoOfflineAction() {
    QJsonObject obj{
        {"action",  core::types::GoOffline},
        {"user_id", core::User::user().id()}
    };
    webSocket_->sendBinaryMessage(QJsonDocument{obj}.toJson());
}

} // widget
