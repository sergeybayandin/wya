#include "handler/send_to_friend.h"

#include "db/database_connections.h"

#include "net/online_users.h"

#include <pqxx/pqxx>

namespace {

void send_to_friend(int from_user_id, int to_user_id, const std::string &message) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    /*
     *
     * save message
     *
     */

    auto [online, connection]{
        net::OnlineUsers::users().try_connection(to_user_id)
    };

    if (online) {
        connection->send_binary(crow::json::wvalue{
            {"from_user_id", from_user_id},
            {"message",      message}	    
        }.dump());
    }

    transaction.commit();
}

}

namespace handler {

crow::response SendToFriend::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    send_to_friend(
        rjson["from_user_id"].i(),
        rjson["to_user_id"].i(),
        static_cast<std::string>(rjson["message"].s())
    );

    return crow::response{crow::OK};
}

} // handler
