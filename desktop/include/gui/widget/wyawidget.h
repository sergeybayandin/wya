#ifndef WYAWIDGET_H
#define WYAWIDGET_H

#include "gui/widget/authwidget.h"
#include "gui/widget/lobbywidget.h"

#include <QWidget>

#include <QWebSocket>
#include <QNetworkAccessManager>

namespace Ui {
class WyaWidget;
}

namespace gui::widget {

class WyaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WyaWidget(QWidget *parent = nullptr);
    ~WyaWidget();

signals:
    void needToDisplayCreatedGroup(int groupId);
    void needToDisplayFriendsAndGroups();
    void needToDisplayFriendsGlobalSearchResults(
        const QVector<QPair<int, QString>> &friendsGlobalSearchResults
    );
    void needToDisplayGroupsGlobalSearchResults(
        const QVector<QPair<int, QString>> &groupsGlobalSearchResults
    );
    void needToDisplayMessageToFriend(
        int            userId,
        const QString &textMessage
    );
    void needToDisplayMessageToGroup(
        int            userId,
        int            groupId,
        const QString &userLogin,
        const QString &textMessage
    );
    void needToDisplayIncomingInvite(int userId);
    void needToDisplayOutgoingInvite(int userId);
    void needToDisplayFriend(int userId);
    void needToDisplayJoinedGroup(int groupId);
    void needToDisplayAcceptedFriend(int fromUserId);
    void needToStopDisplayOutgoingInvite(int toUserId);
    void needToStopDisplayIncomingInvite(int fromUserId);

private slots:
    void _authorizeUser(const QString &login, const QString &password);
    void _registerUser(const QString &login, const QString &password);

    void _createGroup(const QString &groupName);

    void _friendsGlobalSearch(const QString &userLoginPrefix);
    void _groupsGlobalSearch(const QString &groupNamePrefix);

    void _handleWebSocketError(QAbstractSocket::SocketError error);
    void _handleWebSocketConnected();
    void _handleWebSocketBinaryMessageReceived(const QByteArray &binaryMessage);

    void _sendToGroupTextMessage(int groupId, const QString &textMessage);
    void _joinUserToGroup(int groupId, const QString &groupName);

    void _acceptIncomingInvite(int fromUserId);
    void _rejectIncomingInvite(int fromUserId);
    void _cancelOutgoingInvite(int toUserId);
    void _addUser(int userId, const QString &userLogin);

    void _sendToFriendTextMessage(int friendId, const QString &textMessage);

private:
    void _doFriendsAndGroups(int userId, const QString &login);
    void _doCreateGroup(int groupId, const QString &groupName);

    void _setStackedWidget();
    void _setWebSocket();
    void _setConnects();

    void _sendGoOnlineAction();
    void _sendGoOfflineAction();

private:
    Ui::WyaWidget *ui;

    AuthWidget  *authWidget_;
    LobbyWidget *lobbyWidget_;

    QWebSocket            *webSocket_;
    QNetworkAccessManager *manager_;
};

} // widget

#endif // WYAWIDGET_H
