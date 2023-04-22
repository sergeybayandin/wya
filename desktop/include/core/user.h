#ifndef USERINFO_H
#define USERINFO_H

#include "core/user/group.h"
#include "core/user/friend.h"

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

    [[ nodiscard ]]
    const QHash<int, user::Friend> &friends() const noexcept;

    [[ nodiscard ]]
    const QHash<int, user::Group> &groups() const noexcept;

private:
    int     id_;
    QString login_;

    QHash<int, core::user::Group>  groups_;
    QHash<int, core::user::Friend> friends_;
};

} // core

#endif // USERINFO_H
