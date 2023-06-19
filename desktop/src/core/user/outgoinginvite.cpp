#include "core/user/outgoinginvite.h"

namespace core::user {

OutgoingInvite::OutgoingInvite(int toUserId, const QString &toUserLogin)
    : toUserId_{toUserId}, toUserLogin_{toUserLogin}
{}

QString OutgoingInvite::toUserLogin() const {
    return toUserLogin_;
}

int OutgoingInvite::toUserId() const noexcept {
    return toUserId_;
}

} // user
