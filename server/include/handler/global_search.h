#ifndef GLOBAL_SEARCH_H
#define GLOBAL_SEARCH_H

#include "third_party/crow.h"

namespace handler {

class GroupsGlobalSearch final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:
};

class UsersGlobalSearch final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:
};

} // handler

#endif // GLOBAL_SEARCH_H
