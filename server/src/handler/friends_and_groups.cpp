#include "handler/friends_and_groups.h"

#include "db/database_connections.h"

#include <pqxx/pqxx>

namespace {

[[ nodiscard ]]
crow::json::wvalue::list execute_friends(
    pqxx::work &transaction, const std::string &suser_id
) {
    crow::json::wvalue::list friends;

    return friends;
}

[[ nodiscard ]]
crow::json::wvalue::list execute_groups(
    pqxx::work &transaction, const std::string &suser_id
) {
    using namespace std::string_literals;

    auto squery{
        "SELECT ug.group_id, g.group_name "s + 
        "FROM users_groups ug, groups g "s +
        "WHERE  ug.user_id="s + suser_id + " AND ug.group_id=g.group_id "s +
        "UNION SELECT group_id, group_name FROM groups WHERE owner_id="s + suser_id
    };

    crow::json::wvalue::list groups;

    for (auto [group_id, group_name] : transaction.query<int, std::string>(squery)) {
        groups.push_back(crow::json::wvalue{
            {"group_id",   group_id},
            {"group_name", group_name}
        });
    }

    return groups;
}

[[ nodiscard ]]
std::pair<
    crow::json::wvalue::list,
    crow::json::wvalue::list
> friends_and_groups(int user_id) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto suser_id{std::to_string(user_id)};

    auto friends(execute_friends(transaction, suser_id));
    auto groups (execute_groups(transaction, suser_id));

    transaction.commit();

    return {std::move(friends), std::move(groups)};
}

}

namespace handler {

crow::response
FriendsAndGroups::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    auto [friends, groups]{friends_and_groups(
        rjson["user_id"].i()
    )};

    return crow::response{crow::json::wvalue{
        {"friends", std::move(friends)},
        {"groups",  std::move(groups)}
    }};
}

} // handler
