#ifndef SEND_TO_FRIEND_H
#define SEND_TO_FRIEND_H

#include "third_party/crow.h"

namespace handler {

class SendToFriend final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:
};

} // handler

#endif // SEND_TO_FRIEND_H
