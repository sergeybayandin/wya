#ifndef FRIENDS_AND_GROUPS_H
#define FRIENDS_AND_GROUPS_H

#include "third_party/crow.h"

namespace handler {

class FriendsAndGroups final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:

};

} // handler

#endif // FRIENDS_AND_GROUPS_H
