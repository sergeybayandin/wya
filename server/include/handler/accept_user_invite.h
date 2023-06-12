#ifndef ACCEPT_USER_INVITE_H
#define ACCEPT_USER_INVITE_H

#include "third_party/crow.h"

namespace handler {

class AcceptUserInvite final {
public:
    crow::response operator()(const crow::request &request) const;

private:

};

} // handler

#endif // ACCEPT_USER_INVITE_H
