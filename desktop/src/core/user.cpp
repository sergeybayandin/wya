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

user::IncomingInvite &User::addIncomingInvite(const user::IncomingInvite &incomingInvite) {
    return *incomingInvites_.insert(incomingInvite.fromUserId(), incomingInvite);
}

user::OutgoingInvite &User::addOutgoingInvite(const user::OutgoingInvite &outgoingInvite) {
    return *outgoingInvites_.insert(outgoingInvite.toUserId(), outgoingInvite);
}

const QHash<int, user::Group> &User::groups() const noexcept {
    return groups_;
}

const QHash<int, user::Friend> &User::friends() const noexcept {
    return friends_;
}

const QHash<int, user::IncomingInvite> &User::incomingInvites() const noexcept {
    return incomingInvites_;
}

const QHash<int, user::OutgoingInvite> &User::outgoingInvites() const noexcept {
    return outgoingInvites_;
}

void User::removeOutgoingInvite(int userId) {
    outgoingInvites_.remove(userId);
}

void User::removeIncomingInvite(int userId) {
    incomingInvites_.remove(userId);
}

} // core
