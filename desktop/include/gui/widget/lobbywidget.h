#ifndef LOBBYWIDGET_H
#define LOBBYWIDGET_H

#include "gui/box/creategroupbox.h"

#include "gui/widget/friendstabwidget.h"
#include "gui/widget/groupstabwidget.h"

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

    FriendsTabWidget *friendsTabWidget() const noexcept;
    GroupsTabWidget  *groupsTabWidget()  const noexcept;

signals:
    void needToGlobalSearch(const QString &prefix);

public slots:
    void displayCreatedGroup(int groupId);
    void displayFriendsAndGroups();
    void displayGlobalSearchResults(
        const QVector<QPair<int, QString>> &globalSearchResults
    );

private slots:
    void on_searchLineEdit_textEdited(const QString &text);

private:
    void _setTabWidget();
    void _setGlobalSearchTimer();

    void _setConnects();

    void _doFriendsSearch(const QString &friendNamePrefixText);
    void _doGroupSearch(const QString &groupNamePrefixText);

private:
    Ui::LobbyWidget  *ui;
    FriendsTabWidget *friendsTabWidget_;
    GroupsTabWidget  *groupsTabWidget_;
    QTimer            globalSearchTimer_;
};

} // widget

#endif // LOBBYWIDGET_H
