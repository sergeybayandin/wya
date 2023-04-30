#ifndef ADD_FRIEND_H
#define ADD_FRIEND_H

#include "third_party/crow.h"

namespace handler {

class AddFriend final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:
};

} // handler

#endif // ADD_FRIEND_H
