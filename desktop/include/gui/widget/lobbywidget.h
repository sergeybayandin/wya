#ifndef LOBBYWIDGET_H
#define LOBBYWIDGET_H

#include "gui/box/creategroupbox.h"

#include "gui/widget/friendstabwidget.h"
#include "gui/widget/groupstabwidget.h"

#include "gui/dialog/groupchatdialog.h"

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
    void needToGlobalSearch(const QString &prefix);
    void needToSendToGroupTextMessage(int groupId, const QString &textMessage);
    void needToJoinUserToGroup(int groupId, const QString &groupName);

public slots:
    void displayCreatedGroup(int groupId);
    void displayFriendsAndGroups();
    void displayGlobalSearchResults(
        const QVector<QPair<int, QString>> &globalSearchResults
    );
    void displayReceivedMessageToGroup(
        int            userId,
        int            groupId,
        const QString &userLogin,
        const QString &textMessage
    );
    void displayJoinedGroup(int groupId);

private slots:
    void on_searchLineEdit_textEdited(const QString &text);

    void _displayGroupChatDialog(int groupId);
    void _displayGlobalSearchGroupChatDialog(
        int            groupId,
        const QString &groupNameText
    );

private:
    void _setTabWidget();
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

private:
    Ui::LobbyWidget  *ui;
    FriendsTabWidget *friendsTabWidget_;
    GroupsTabWidget  *groupsTabWidget_;
    QTimer           *globalSearchTimer_;
    QHash<
        int,
        dialog::GroupChatDialog *
    > groupChatDialogs_;
};

} // widget

#endif // LOBBYWIDGET_H
