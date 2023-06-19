#ifndef REJECT_USER_INVITE_H
#define REJECT_USER_INVITE_H

#include "third_party/crow.h"

namespace handler {

class RejectUserInvite final {
public:
    crow::response operator()(const crow::request &request) const;

private:
};

} // handler

#endif // REJECT_USER_INVITE_H
