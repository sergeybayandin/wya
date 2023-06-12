#ifndef ADD_USER_H
#define ADD_USER_H

#include "third_party/crow.h"

namespace handler {

class AddUser final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:
};

} // handler

#endif // ADD_USER_H
