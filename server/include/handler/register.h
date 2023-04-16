#ifndef REGISTER_H
#define REGISTER_H

#include "third_party/crow.h"

namespace handler {

class Register final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:

};

} // handler

#endif // REGISTER_H
