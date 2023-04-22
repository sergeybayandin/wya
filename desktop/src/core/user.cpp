#include "core/user.h"

namespace core {

User &User::user() {
    static User user;
    return user;
}

int User::id() const noexcept {
    return id_;
}

QString User::login() const {
    return login_;
}

void User::setId(int id) noexcept {
    id_ = id;
}

void User::setLogin(const QString &login) {
    login_ = login;
}

user::Group &User::addGroup(const core::user::Group &g) {
    return *groups_.insert(g.id(), g);
}

user::Friend &User::addFriend(const core::user::Friend &f) {
    return *friends_.insert(f.id(), f);
}

const QHash<int, user::Group> &User::groups() const noexcept {
    return groups_;
}

const QHash<int, user::Friend> &User::friends() const noexcept {
    return friends_;
}

} // core
