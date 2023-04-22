#ifndef WYAWIDGET_H
#define WYAWIDGET_H

#include "gui/widget/authwidget.h"
#include "gui/widget/lobbywidget.h"

#include <QWidget>
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

private slots:
    void _authorizeUser(const QString &login, const QString &password);
    void _registerUser(const QString &login, const QString &password);

    void _createGroup(const QString &groupName);

private:
    void _doLobby(int userId);
    void _doCreateGroup(int groupId, const QString &groupName);

    void _setStackedWidget();
    void _setConnects();

private:
    Ui::WyaWidget *ui;

    AuthWidget  *authWidget_;
    LobbyWidget *lobbyWidget_;

    QNetworkAccessManager *manager_;
};

} // widget

#endif // WYAWIDGET_H
