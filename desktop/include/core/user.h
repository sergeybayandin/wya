#ifndef USERINFO_H
#define USERINFO_H

#include "core/user/group.h"
#include "core/user/friend.h"
#include "core/user/incominginvite.h"
#include "core/user/outgoinginvite.h"

#include <QHash>
#include <QString>

namespace core {

class User final
{
public:
    [[ nodiscard ]]
    static User &user();

    [[ nodiscard ]]
    int id() const noexcept;

    [[ nodiscard ]]
    QString login() const;

    void setId(int id) noexcept;
    void setLogin(const QString &login);

    user::Group  &addGroup(const user::Group   &g);
    user::Friend &addFriend(const user::Friend &f);

    user::IncomingInvite &addIncomingInvite(const user::IncomingInvite &incomingInvite);
    user::OutgoingInvite &addOutgoingInvite(const user::OutgoingInvite &outgoingInvite);

    [[ nodiscard ]]
    const QHash<int, user::Friend> &friends() const noexcept;

    [[ nodiscard ]]
    const QHash<int, user::Group> &groups() const noexcept;

    [[ nodiscard ]]
    const QHash<int, user::IncomingInvite> &incomingInvites() const noexcept;

    [[ nodiscard ]]
    const QHash<int, user::OutgoingInvite> &outgoingInvites() const noexcept;

    void removeOutgoingInvite(int userId);
    void removeIncomingInvite(int userId);

private:
    int     id_;
    QString login_;

    QHash<int, core::user::Group>          groups_;
    QHash<int, core::user::Friend>         friends_;
    QHash<int, core::user::IncomingInvite> incomingInvites_;
    QHash<int, core::user::OutgoingInvite> outgoingInvites_;
};

} // core

#endif // USERINFO_H
