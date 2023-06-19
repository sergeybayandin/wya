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
        SIGNAL(needToFriendsGlobalSearch(const QString&)),
        this,
        SLOT(_friendsGlobalSearch(const QString&))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToGroupsGlobalSearch(const QString&)),
        this,
        SLOT(_groupsGlobalSearch(const QString&))
    );
    connect(
        this,
        SIGNAL(needToDisplayFriendsGlobalSearchResults(const QVector<QPair<int, QString>>&)),
        lobbyWidget_,
        SLOT(displayFriendsGlobalSearchResults(const QVector<QPair<int, QString>>&))
    );
    connect(
        this,
        SIGNAL(needToDisplayGroupsGlobalSearchResults(const QVector<QPair<int, QString>>&)),
        lobbyWidget_,
        SLOT(displayGroupsGlobalSearchResults(const QVector<QPair<int, QString>>&))
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
        SIGNAL(needToDisplayMessageToGroup(int, int, const QString&, const QString&)),
        lobbyWidget_,
        SLOT(displayMessageToGroup(int, int, const QString&, const QString&))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToJoinUserToGroup(int, const QString &)),
        this,
        SLOT(_joinUserToGroup(int, const QString &))
    );
    connect(
        this,
        SIGNAL(needToDisplayJoinedGroup(int)),
        lobbyWidget_,
        SLOT(displayJoinedGroup(int))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToAddUser(int, const QString&)),
        this,
        SLOT(_addUser(int, const QString&))
    );
    connect(
        this,
        SIGNAL(needToDisplayOutgoingInvite(int)),
        lobbyWidget_,
        SLOT(displayOutgoingInvite(int))
    );
    connect(
        this,
        SIGNAL(needToDisplayIncomingInvite(int)),
        lobbyWidget_,
        SLOT(displayIncomingInvite(int))
    );
    connect(
        this,
        SIGNAL(needToDisplayFriend(int)),
        lobbyWidget_,
        SLOT(displayFriend(int))
    );
    connect(
        this,
        SIGNAL(needToDisplayMessageToFriend(int, const QString&)),
        lobbyWidget_,
        SLOT(displayMessageToFriend(int, const QString&))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToAcceptIncomingInvite(int)),
        this,
        SLOT(_acceptIncomingInvite(int))
    );
    connect(
        this,
        SIGNAL(needToDisplayAcceptedFriend(int)),
        lobbyWidget_,
        SLOT(displayAcceptedFriend(int))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToCancelOutgoingInvite(int)),
        this,
        SLOT(_cancelOutgoingInvite(int))
    );
    connect(
        this,
        SIGNAL(needToStopDisplayOutgoingInvite(int)),
        lobbyWidget_,
        SLOT(stopDisplayOutgoingInvite(int))
    );
    connect(
        this,
        SIGNAL(needToStopDisplayIncomingInvite(int)),
        lobbyWidget_,
        SLOT(stopDisplayIncomingInvite(int))
    );
    connect(
        lobbyWidget_,
        SIGNAL(needToSendToFriendTextMessage(int, const QString&)),
        this,
        SLOT(_sendToFriendTextMessage(int, const QString&))
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

            qDebug() << doc << '\n';

            auto friends(doc["friends"].toArray());           
            auto groups (doc["groups"].toArray());

            auto incomingInvites(doc["invites"]["incoming"].toArray());
            auto outgoingInvites(doc["invites"]["outgoing"].toArray());

            core::User::user().setId(userId);
            core::User::user().setLogin(login);

            for (const auto &jsonValue : friends) {
                auto obj{jsonValue.toObject()};
                core::User::user().addFriend(
                    core::user::Friend{
                        obj["friend_id"].toInt(),
                        obj["friend_login"].toString()
                    }
                );
            }

            for (const auto &jsonValue : incomingInvites) {
                auto obj{jsonValue.toObject()};
                core::User::user().addIncomingInvite(
                    core::user::IncomingInvite{
                        obj["user_id"].toInt(),
                        obj["user_login"].toString()
                    }
                );
            }

            for (const auto &jsonValue : outgoingInvites) {
                auto obj{jsonValue.toObject()};
                core::User::user().addOutgoingInvite(
                    core::user::OutgoingInvite{
                        obj["user_id"].toInt(),
                        obj["user_login"].toString()
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

void WyaWidget::_friendsGlobalSearch(const QString &userLoginPrefix) {
    QJsonObject obj{
        {"user_id",          core::User::user().id()},
        {"user_login_prefix", userLoginPrefix}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/global_search/friends"
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
            qDebug() << "/global_search/friends: " << reply->errorString() << '\n';
        } else {
            auto doc                                {QJsonDocument::fromJson(reply->readAll())};
            auto friendsGlobalSearchResultsArray(doc["friends_global_search_result"].toArray());

            QVector<QPair<int, QString>> friendsGlobalSearchResults;

            friendsGlobalSearchResults.reserve(
                friendsGlobalSearchResultsArray.size()
            );

            for (const auto &jsonValue : friendsGlobalSearchResultsArray) {
                auto obj{jsonValue.toObject()};
                friendsGlobalSearchResults += QPair{
                    obj["user_id"].toInt(),
                    obj["user_login"].toString()
                };
            }

            emit needToDisplayFriendsGlobalSearchResults(friendsGlobalSearchResults);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_groupsGlobalSearch(const QString &groupNamePrefix) {
    QJsonObject obj{
        {"user_id",           core::User::user().id()},
        {"group_name_prefix", groupNamePrefix}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/global_search/groups"
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
            qDebug() << "/global_search/groups: " << reply->errorString() << '\n';
        } else {
            auto doc                           {QJsonDocument::fromJson(reply->readAll())};
            auto groupsGlobalSearchResultsArray(doc["groups_global_search_result"].toArray());

            QVector<QPair<int, QString>> groupsGlobalSearchResults;

            groupsGlobalSearchResults.reserve(
                groupsGlobalSearchResultsArray.size()
            );

            for (const auto &jsonValue : groupsGlobalSearchResultsArray) {
                auto obj{jsonValue.toObject()};
                groupsGlobalSearchResults += QPair{
                    obj["group_id"].toInt(),
                    obj["group_name"].toString()
                };
            }

            emit needToDisplayGroupsGlobalSearchResults(groupsGlobalSearchResults);
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
    auto action{static_cast<core::types::ServerAction>(
        doc["action"].toInt()
    )};

    switch (action) {
    case core::types::SendToUser       :
        emit needToDisplayMessageToFriend(
            doc["user_id"].toInt(),
            doc["message"].toString()
        );
        break;

    case core::types::SendToGroup      :
        emit needToDisplayMessageToGroup(
            doc["user_id"].toInt(),
            doc["group_id"].toInt(),
            doc["user_login"].toString(),
            doc["message"].toString()
        );
        break;

    case core::types::AddUser          : {
        auto userId   {doc["user_id"].toInt()};
        auto userLogin{doc["user_login"].toString()};
        core::User::user().addIncomingInvite(
            core::user::IncomingInvite{userId, userLogin}
        );
        emit needToDisplayIncomingInvite(userId);
        break;
    }
    case core::types::AcceptUserInvite : {
        auto userId{doc["user_id"].toInt()};
        auto userLogin{core::User::user().outgoingInvites()[userId].toUserLogin()};
        core::User::user().removeOutgoingInvite(userId);
        core::User::user().addFriend(core::user::Friend{userId, userLogin});
        emit needToDisplayFriend(userId);
        break;
    }
    case core::types::RejectUserInvite :

        break;

    case core::types::CancelUser       : {
        auto userId{doc["user_id"].toInt()};
        core::User::user().removeIncomingInvite(userId);
        emit needToStopDisplayIncomingInvite(userId);
        break;
    }
    default                            :
        // ???
        break;
    }
}

void WyaWidget::_sendToGroupTextMessage(int groupId, const QString &messageText) {
    QJsonObject obj{
        {"user_id",    core::User::user().id()},
        {"user_login", core::User::user().login()},
        {"group_id",   groupId},
        {"message",    messageText}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/send_to_group"
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
            qDebug() << "send_to_group failed: " << reply->errorString() << '\n';
        } else {
            qDebug() << "send_to_group succeed\n";
        }
        reply->deleteLater();
    });
}

void WyaWidget::_joinUserToGroup(int groupId, const QString &groupName) {
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

void WyaWidget::_acceptIncomingInvite(int fromUserId) {
    QJsonObject obj{
        {"to_user_id",   core::User::user().id()},
        {"from_user_id", fromUserId}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/accept_user_invite"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply,  &QNetworkReply::finished, this, [reply, this, fromUserId]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/accept_user_invite: " << reply->errorString() << '\n';
        } else {
            auto userLogin{core::User::user().incomingInvites()[fromUserId].fromUserLogin()};
            core::User::user().removeIncomingInvite(fromUserId);
            core::User::user().addFriend(core::user::Friend{fromUserId, userLogin});
            emit needToDisplayAcceptedFriend(fromUserId);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_rejectIncomingInvite(int fromUserId) {
    QJsonObject obj{
        {"to_user_id",   core::User::user().id()},
        {"from_user_id", fromUserId}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/rejecet_user_invite"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply,  &QNetworkReply::finished, this, [reply, this, fromUserId]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/reject_user_invite: " << reply->errorString() << '\n';
        } else {
            core::User::user().removeIncomingInvite(fromUserId);
            emit needToStopDisplayIncomingInvite(fromUserId);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_cancelOutgoingInvite(int toUserId) {
    QJsonObject obj{
        {"to_user_id",   toUserId},
        {"from_user_id", core::User::user().id()}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/cancel_user"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply,  &QNetworkReply::finished, this, [reply, this, toUserId]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/cancel_user: " << reply->errorString() << '\n';
        } else {
            core::User::user().removeOutgoingInvite(toUserId);
            emit needToStopDisplayOutgoingInvite(toUserId);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_addUser(int userId, const QString &userLogin) {
    QJsonObject obj{
        {"from_user_id",    core::User::user().id()},
        {"from_user_login", core::User::user().login()},
        {"to_user_id",      userId}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/add_user"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply,  &QNetworkReply::finished, this, [reply, this, userId, userLogin]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/add_user: " << reply->errorString() << '\n';
        } else {
            core::User::user().addOutgoingInvite(
                core::user::OutgoingInvite{userId, userLogin}
            );
            emit needToDisplayOutgoingInvite(userId);
        }
        reply->deleteLater();
    });
}

void WyaWidget::_sendToFriendTextMessage(int friendId, const QString &textMessage) {
    QJsonObject obj{
        {"from_user_id", core::User::user().id()},
        {"to_user_id",   friendId},
        {"message",      textMessage}
    };

    QNetworkRequest request{
        core::ServerConfig::config().url() + "/send_to_friend"
    };

    request.setHeader(
        QNetworkRequest::ContentTypeHeader,
        "application/json"
    );

    auto reply{manager_->post(
        request,
        QJsonDocument{obj}.toJson()
    )};

    connect(reply,  &QNetworkReply::finished, this, [reply]() {
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << "/send_to_friend: " << reply->errorString() << '\n';
        } else {
            qDebug() << "/send_to_friend succeed\n";
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
