#include "handler/authorize.h"

namespace handler {

crow::response Authorize::operator()(const crow::request &request) const {
    auto json{crow::json::load(request.body)};

    if (json.error()) {
        return crow::BAD_REQUEST;
    }



    return crow::response{};
}

} // routine
