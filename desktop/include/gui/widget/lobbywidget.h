#ifndef LOBBYWIDGET_H
#define LOBBYWIDGET_H

#include "gui/box/creategroupbox.h"

#include "gui/widget/friendstabwidget.h"
#include "gui/widget/groupstabwidget.h"

#include "gui/dialog/groupchatdialog.h"
#include "gui/dialog/friendchatdialog.h"

#include "core/user.h"

#include <QTimer>
#include <QWidget>

namespace Ui {
class LobbyWidget;
}

namespace gui::widget {

class LobbyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LobbyWidget(QWidget *parent = nullptr);
    ~LobbyWidget();

    [[ nodiscard ]]
    FriendsTabWidget *friendsTabWidget() const noexcept;

    [[ nodiscard ]]
    GroupsTabWidget  *groupsTabWidget()  const noexcept;

signals:
    void needToFriendsGlobalSearch(const QString &userLoginPrefix);
    void needToGroupsGlobalSearch(const QString &groupNamePrefix);
    void needToSendToGroupTextMessage(int groupId, const QString &textMessage);
    void needToJoinUserToGroup(int groupId, const QString &groupName);
    void needToAcceptIncomingInvite(int fromUserId);
    void needToRejectIncomingInvite(int fromUserId);
    void needToCancelOutgoingInvite(int toUserId);
    void needToAddUser(int userId, const QString &userLogin);
    void needToSendToFriendTextMessage(int friendId, const QString &textMessage);

public slots:
    void displayCreatedGroup(int groupId);
    void displayFriendsAndGroups();
    void displayFriendsGlobalSearchResults(
        const QVector<QPair<int, QString>> &friendsGlobalSearchResults
    );
    void displayGroupsGlobalSearchResults(
        const QVector<QPair<int, QString>> &groupsGlobalSearchResults
    );
    void displayMessageToGroup(
        int            userId,
        int            groupId,
        const QString &userLogin,
        const QString &textMessage
    );
    void displayMessageToFriend(int userId, const QString &message);
    void displayIncomingInvite(int userId);
    void displayOutgoingInvite(int userId);
    void displayFriend(int userId);
    void displayJoinedGroup(int groupId);
    void displayAcceptedFriend(int userId);
    void stopDisplayOutgoingInvite(int toUserId);
    void stopDisplayIncomingInvite(int fromUserId);

private slots:
    void on_searchLineEdit_textEdited(const QString &text);

    void _displayGroupChatDialog(int groupId);
    void _displayFriendChatDialog(int userId);
    void _displayGlobalSearchGroupChatDialog(
        int            groupId,
        const QString &groupNameText
    );

    void on_tabWidget_currentChanged(int index);

private:
    void _setTabWidgets();
    void _setGlobalSearchTimer();

    void _setConnects();

    void _doFriendsSearch(const QString &friendNamePrefixText);
    void _doGroupSearch(const QString &groupNamePrefixText);

    [[ nodiscard ]]
    box::GroupBox *_createGroupBox(int groupId);

    [[ nodiscard ]]
    box::GlobalSearchGroupBox *_createGlobalSearchGroupBox(
        int            groupId,
        const QString &groupNameText
    );

    dialog::GroupChatDialog *_createOrReturnGroupChatDialog(
        int            groupId,
        const QString &groupName
    );

    [[ nodiscard ]]
    box::FriendBox *_createFriendBox(int friendId);

    [[ nodiscard ]]
    box::IncomingInviteBox *_createIncomingInviteBox(int fromUserId);

    [[ nodiscard ]]
    box::OutgoingInviteBox *_createOutgoingInviteBox(int toUserId);

    [[ nodiscard ]]
    box::GlobalSearchFriendBox *_createGlobalSearchFriendBox(
        int            userId,
        const QString &userLoginText
    );

    dialog::FriendChatDialog *_createOrReturnFriendChatDialog(
        int            friendId,
        const QString &friendLogin
    );

private:
    Ui::LobbyWidget  *ui;
    FriendsTabWidget *friendsTabWidget_;
    GroupsTabWidget  *groupsTabWidget_;
    QTimer           *globalSearchTimer_;
    QHash<
        int,
        dialog::GroupChatDialog *
    > groupChatDialogs_;
    QHash<
        int,
        dialog::FriendChatDialog *
    > friendChatDialogs_;
};

} // widget

#endif // LOBBYWIDGET_H
