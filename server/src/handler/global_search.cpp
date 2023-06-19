#include "handler/global_search.h"

#include "db/database_connections.h"

#include <pqxx/pqxx>

namespace {

[[ nodiscard ]] crow::json::wvalue::list
groups_global_search(int user_id, const std::string &group_name_prefix) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto suser_id{std::to_string(user_id)};
    auto squery  {
        "SELECT group_id, group_name "s +
        "FROM groups "s +
        "WHERE owner_id != "s + suser_id + 
        " AND group_name LIKE \'"s + 
        group_name_prefix + "%\'"s +
        " AND group_id NOT IN "s + 
        "(SELECT group_id FROM users_groups WHERE user_id="s + suser_id + ")"s
    };

    crow::json::wvalue::list groups_global_search_result;

    for (auto [id, name] : transaction.query<int, std::string>(squery)) {
        groups_global_search_result.push_back(crow::json::wvalue{
            {"group_id", id}, {"group_name", name}        
        });
    }

    transaction.commit();

    return groups_global_search_result;
}

[[ nodiscard ]] crow::json::wvalue::list
users_global_search(int user_id, const std::string &user_login_prefix) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto suser_id          {std::to_string(user_id)};
    auto sinvites_sub_query{
        "SELECT COUNT(*) FROM invites "s +
        "WHERE (from_user_id="s + suser_id + " AND to_user_id=user_id)"s + " OR "s +
              "(from_user_id=user_id AND to_user_id="s + suser_id + ")"s
    };
    auto sfriends_sub_query{
        "SELECT COUNT(*) FROM invites "s +
        "WHERE (from_user_id="s + suser_id + " AND to_user_id=user_id)"s + " OR "s +
              "(from_user_id=user_id AND to_user_id="s + suser_id + ")"s
    };
    auto squery            {
        "SELECT user_id, login FROM users WHERE user_id!="s + suser_id + 
        " AND login LIKE \'"s + user_login_prefix + "%\'"s +
        " AND ("s + sfriends_sub_query + ")=0"s +
        " AND ("s + sinvites_sub_query + ")=0"s
    };

    crow::json::wvalue::list users_global_search_result;

    for (auto [id, login] : transaction.query<int, std::string>(squery)) {
        users_global_search_result.push_back(crow::json::wvalue{
            {"user_id", id}, {"user_login", login}        
        });
    }   

    transaction.commit();

    return users_global_search_result;
}

}

namespace handler {

crow::response GroupsGlobalSearch::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    auto groups_global_search_result(groups_global_search(
        rjson["user_id"].i(),
        static_cast<std::string>(rjson["group_name_prefix"].s())
    ));

    return crow::response{crow::json::wvalue{
        {"groups_global_search_result", std::move(groups_global_search_result)}
    }.dump()};
}

crow::response UsersGlobalSearch::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    auto users_global_search_result(users_global_search(
        rjson["user_id"].i(),
        static_cast<std::string>(rjson["user_login_prefix"].s())
    ));

    return crow::response{crow::json::wvalue{
        {"friends_global_search_result", std::move(users_global_search_result)}
    }.dump()};
}

} // handler
