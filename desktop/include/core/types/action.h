#ifndef ACTION_H
#define ACTION_H

namespace core::types {

enum ClientAction {
    GoOnline,
    GoOffline
};

enum ServerAction {
    SendToGroup,
    SendToUser,
    AddUser,
    AcceptUserInvite,
    RejectUserInvite,
    CancelUser
};

} // types

#endif // ACTION_H
