#ifndef REGISTER_H
#define REGISTER_H

#include "third_party/crow.h"

namespace handler {

class Register final {
public:
    Register()                 = default;
    Register(const Register &) = default;
    Register(Register      &&) = default;

    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:

};

} // handler

#endif // REGISTER_H
