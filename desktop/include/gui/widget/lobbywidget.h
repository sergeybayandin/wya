#ifndef LOBBYWIDGET_H
#define LOBBYWIDGET_H

#include "gui/box/creategroupbox.h"

#include "gui/widget/friendstabwidget.h"
#include "gui/widget/groupstabwidget.h"

#include "core/user.h"

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

    FriendsTabWidget *friendsTabWidget() const noexcept;
    GroupsTabWidget  *groupsTabWidget()  const noexcept;

public slots:
    void displayCreatedGroup(int groupId);
    void displayFriendsAndGroups();

private:
    void _setTabWidget();

private:
    Ui::LobbyWidget  *ui;
    FriendsTabWidget *friendsTabWidget_;
    GroupsTabWidget  *groupsTabWidget_;
};

} // widget

#endif // LOBBYWIDGET_H
