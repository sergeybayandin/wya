#include "handler/reject_user_invite.h"

#include "db/database_connections.h"

#include "net/online_users.h"

#include "types/action.h"

#include <pqxx/pqxx>

namespace {

void reject_user_invite(int from_user_id, int to_user_id) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto squery{
        "DELETE FROM invites WHERE from_user_id="s + 
         std::to_string(from_user_id) + " AND to_user_id="s + std::to_string(to_user_id)
    };

    transaction.exec0(squery);

    auto [online, connection]{net::OnlineUsers::users().try_connection(from_user_id)};

    if (online) {
        connection->send_binary(crow::json::wvalue{
            {"action",  types::RejectUserInvite},
            {"user_id", to_user_id}
        }.dump());
    }

    transaction.commit();
}

}

namespace handler {

crow::response RejectUserInvite::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    reject_user_invite(rjson["from_user_id"].i(), rjson["to_user_id"].i());

    return crow::response{crow::OK};;
}

} // handler
