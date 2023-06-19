#ifndef FRIENDSTAB_H
#define FRIENDSTAB_H

#include "gui/box/friendbox.h"
#include "gui/box/incominginvitebox.h"
#include "gui/box/outgoinginvitebox.h"
#include "gui/box/globalsearchfriendbox.h"

#include <QLabel>
#include <QWidget>

namespace Ui {
class FriendsTabWidget;
}

namespace gui::widget {

class FriendsTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FriendsTabWidget(QWidget *parent = nullptr);
    ~FriendsTabWidget();

    [[ nodiscard ]]
    int friendBoxesCount() const noexcept;

    [[ nodiscard ]]
    int incomingInviteBoxesCount() const noexcept;

    [[ nodiscard ]]
    int outgoingInviteBoxesCount() const noexcept;

    [[ nodiscard ]]
    box::FriendBox *friendBoxAt(int i) const noexcept;

    [[ nodiscard ]]
    box::IncomingInviteBox *incomingInviteBoxAt(int i) const noexcept;

    [[ nodiscard ]]
    box::OutgoingInviteBox *outgoingInviteBoxAt(int i) const noexcept;

    void addFriendBox(box::FriendBox *friendBox);

    void addIncomingInviteBox(box::IncomingInviteBox *incomingInviteBox);
    void addOutgoingInviteBox(box::OutgoingInviteBox *outgoingInviteBox);

    void addGlobalSearchFriendBox(box::GlobalSearchFriendBox *globalSearchFriendBox);

    [[ nodiscard ]]
    QLabel *incomingInvitesLabel() const noexcept;

    [[ nodiscard ]]
    QLabel *outgoingInvitesLabel() const noexcept;

    [[ nodiscard ]]
    QLabel *globalSearchLabel() const noexcept;

    void clearGlobalSearchFriendBoxes();

    void removeIncomingInviteBox(int userId);
    void removeOutgoingInviteBox(int userId);

private:
    Ui::FriendsTabWidget *ui;

    QHash<int, box::IncomingInviteBox *> incomingInviteBoxes_;
    QHash<int, box::OutgoingInviteBox *> outgoingInviteBoxes_;

    QHash<int, box::FriendBox *>             friendBoxes_;
    QHash<int, box::GlobalSearchFriendBox *> globalSearchFriendBoxes_;
};

} // widget

#endif // FRIENDSTAB_H
