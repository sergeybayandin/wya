#include "handler/register.h"

#include "db/database_connections.h"

#include <pqxx/transaction>

namespace {

[[ nodiscard ]] bool
try_register_user(
    const std::string &login_password_hash,
    const std::string &login
) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto [exists]{transaction.query1<bool>(
        "SELECT EXISTS(SELECT 1 FROM auth WHERE login="s +
        transaction.quote(login) +
        ")"s
    )};

    if (!exists) {
        transaction.exec(
            "INSERT INTO auth (login_password_hash, login) "s +
            "VALUES ("s +
                transaction.quote(login_password_hash) + ","s +
                transaction.quote(login) +
            ")"s
        );
    }

    transaction.commit();

    return !exists;
}

}

namespace handler {

crow::response Register::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }
    
    auto registered{try_register_user(
        static_cast<std::string>(rjson["login_password_hash"].s()),
        static_cast<std::string>(rjson["login"].s())
    )};

    return crow::response{crow::json::wvalue{
        {"registered", registered}
    }.dump()};
}

} // handler
