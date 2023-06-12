#include "handler/add_user.h"

#include "db/database_connections.h"

#include "net/online_users.h"

#include <pqxx/pqxx>

namespace {

void add_user(
    int                from_user_id,
    int                to_user_id,
    const std::string &from_user_login
) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    transaction.exec0(
        "INSERT INTO invites VALUES("s +
            std::to_string(from_user_id) + ","s +
            std::to_string(to_user_id)
	")"s
    );

    auto [online, connection]{
        net::OnlineUsers::users().try_connection(to_user_id)
    };

    if (online) {
        connection->send_binary(crow::json::wvalue{
            {"from_user_id",    from_user_id},
            {"from_user_login", from_user_login}    
	}.dump());
    }

    transaction.commit();
}

}

namespace handler {

crow::response AddUser::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    add_user(
        rjson["from_user_id"].i(),
        rjson["to_user_id"].i(),
        static_cast<std::string>(rjson["from_user_login"].s())
    );

    return crow::response{crow::OK};
}

} // handler
