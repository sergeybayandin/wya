#include "handler/send_to_group.h"

#include "net/online_users.h"

#include "db/database_connections.h"

#include "types/action.h"

#include <pqxx/pqxx>

namespace {

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

}

namespace handler {

crow::response SendToGroup::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    send_to_group(
        rjson["user_id"].i(),
        rjson["group_id"].i(),
        static_cast<std::string>(rjson["user_login"].s()),
        static_cast<std::string>(rjson["message"].s())
    );

    return crow::response{crow::OK};
}

} // handler
