#include "handler/accept_user_invite.h"

#include "db/database_connections.h"

#include "net/online_users.h"

#include <pqxx/pqxx>

namespace {

void accept_user_invite(int to_user_id, int from_user_id, const std::string &to_user_login) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto sto_user_id  {std::to_string(to_user_id)};
    auto sfrom_user_id{std::to_string(from_user_id)};

    transaction.exec0(
        "DELETE FROM invites WHERE "s +
        "from_user_id="s + sfrom_user_id + " AND to_user_id="s + sto_user_id
    );

    transaction.exec0(
        "INSERT INTO friends VALUES("s +
            sfrom_user_id + ","s + sto_user_id
        ")"s
    );

    auto [online, connection]{
        net::OnlineUsers::users().try_connection(from_user_id)
    };

    if (online) {
        connection->send_binary(crow::json::wvalue{
            {"from_user_id",  from_user_id},
            {"to_user_login", to_user_login}
        }.dump());
    }

    transaction.commit();
}

}

namespace handler {

crow::response AcceptUserInvite::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    accept_user_invite(
        rjson["to_user_id"].i(),
        rjson["from_user_id"].i(),
        static_cast<std::string>(rjson["to_user_login"].s())
    );

    return crow::response{crow::OK};
}

} // handler
