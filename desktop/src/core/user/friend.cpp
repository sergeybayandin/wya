#include "core/user/friend.h"

namespace core::user {

Friend::Friend(int id, const QString &login)
    : id_{id}, login_{login}
{}

QString Friend::login() const {
    return login_;
}

int Friend::id() const noexcept {
    return id_;
}

} // user
