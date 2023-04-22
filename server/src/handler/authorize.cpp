#include "handler/authorize.h"

#include "db/database_connections.h"

#include <pqxx/transaction>

namespace {

[[ nodiscard ]] std::optional<int>
try_authorize_user(const std::string &login_password_hash) {
    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto opt{transaction.query01<int>(
        "SELECT user_id FROM users WHERE login_password_hash=" +
        transaction.quote(login_password_hash)
    )};

    transaction.commit();

    return opt.has_value() ? std::optional<int>{std::get<0>(*opt)}
                           : std::optional<int>{std::nullopt};
}
    
}

namespace handler {

crow::response Authorize::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    auto opt{try_authorize_user(
        static_cast<std::string>(rjson["login_password_hash"].s())
    )};
    crow::json::wvalue wjson{{"authorized", opt.has_value()}};

    if (opt.has_value()) {
        wjson["user_id"] = *opt;
    }

    return crow::response{crow::OK, wjson.dump()};
}

} // handler 
