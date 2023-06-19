#include "core/user/incominginvite.h"

namespace core::user {

IncomingInvite::IncomingInvite(int fromUserId, const QString &fromUserLogin)
    : fromUserId_{fromUserId}, fromUserLogin_{fromUserLogin}
{}

QString IncomingInvite::fromUserLogin() const {
    return fromUserLogin_;
}

int IncomingInvite::fromUserId() const noexcept {
    return fromUserId_;
}

} // user
