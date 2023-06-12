#ifndef ACTION_H
#define ACTION_H

namespace types {

enum ClientAction {
    GoOnline,
    GoOffline
};

enum ServerAction {
    SendToGroup,
    SendToFriend,
    AddUser,
    AcceptUserInvite
};

} // types

#endif // ACTION_H
