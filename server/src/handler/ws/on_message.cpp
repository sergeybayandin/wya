#include "handler/ws/on_message.h"

#include "net/online_users.h"

#include "types/action.h"

#include "db/database_connections.h"

#include <pqxx/pqxx>

namespace {

void go_online(int user_id, crow::websocket::connection &connection) {
    net::OnlineUsers::users().go_online(user_id, &connection);
}

void send_to_user(
    int                from_user_id,
    int                to_user_id,
    const std::string &from_user_login,
    const std::string &message
) {
    // TODO:
    // connections[to_user_id] -> connection
    // connection->send(json);
}

void send_to_group(
    int                user_id,
    int                group_id,
    const std::string &user_login,
    const std::string &message
) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto suser_id {std::to_string(user_id)};
    auto sgroup_id{std::to_string(group_id)};
    auto squery{
        "SELECT user_id "s +
        "FROM users_groups "s +
        "WHERE user_id!="s + suser_id + " AND group_id="s + sgroup_id +
        "UNION "s +
        "SELECT owner_id "s +
        "FROM groups "s +
        "WHERE owner_id!="s + suser_id + " AND group_id="s + sgroup_id
    };
    auto json{crow::json::wvalue{
        {"action",     types::SendToGroup},
        {"user_id",    user_id},
        {"group_id",   group_id},
        {"user_login", user_login},
        {"message",    message}
    }.dump()};

    for (auto [id] : transaction.query<int>(squery)) {
        auto [online, connection]{
            net::OnlineUsers::users().try_connection(id)
        };
        if (online) {
            connection->send_binary(json);
        }
    }

    transaction.commit();
}

void go_offline(int user_id) {
    net::OnlineUsers::users().go_offline(user_id);
}

}

namespace handler::ws {

void OnMessage::operator()(
    crow::websocket::connection &connection,
    const std::string           &json,
    bool
) const {
    auto rjson{crow::json::load(json)};

    if (rjson.error()) {
        return;
    }

    auto action{static_cast<types::Action>(
        rjson["action"].i()
    )};

    switch (action) {
    case types::GoOnline    :
        go_online(rjson["user_id"].i(), connection);
        break;

    case types::SendToUser  :
        send_to_user(
            rjson["from_user_id"].i(),
            rjson["to_user_id"].i(),
            static_cast<std::string>(rjson["from_user_login"].s()),
            static_cast<std::string>(rjson["message"].s())
        );
        break;

    case types::SendToGroup :
        send_to_group(
            rjson["user_id"].i(),
            rjson["group_id"].i(),
            static_cast<std::string>(rjson["user_login"].s()),
            static_cast<std::string>(rjson["message"].s())
        );
        break;

    case types::GoOffline :
        go_offline(rjson["user_id"].i());
        break;

    default :
        // ???
        break;
    }
}

} // ws
