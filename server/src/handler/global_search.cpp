#include "handler/global_search.h"

#include "db/database_connections.h"

#include <pqxx/pqxx>

namespace {

[[ nodiscard ]] crow::json::wvalue::list
global_search(int user_id, const std::string &group_name_prefix) {
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

    crow::json::wvalue::list global_search_result;

    for (auto [group_id, group_name] : transaction.query<int, std::string>(squery)) {
        global_search_result.push_back(crow::json::wvalue{
            {"group_id", group_id}, {"group_name", group_name}        
        });
    }

    transaction.commit();

    return global_search_result;
}

}

namespace handler {

crow::response GlobalSearch::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    auto global_search_result(global_search(
        rjson["user_id"].i(),
        static_cast<std::string>(rjson["group_name_prefix"].s())
    ));

    return crow::response{crow::json::wvalue{
        {"global_search_result", std::move(global_search_result)}
    }.dump()};
}

} // handler
