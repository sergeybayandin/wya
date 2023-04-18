#ifndef CREATE_GROUP_H
#define CREATE_GROUP_H

#include "third_party/crow.h"

namespace handler {

class CreateGroup final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:
};

} // handler

#endif // CREATE_GROUP_H
