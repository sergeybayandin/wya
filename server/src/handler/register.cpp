#include "handler/register.h"

namespace handler {

crow::response Register::operator()(const crow::request &request) const {
    return crow::response{};
}

} // routine
