#include "handler/create_group.h"

#include "db/database_connections.h"

#include <pqxx/transaction>

namespace {

[[ nodiscard ]]
int create_group(const std::string &group_name, int owner_id) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    auto [group_id]{transaction.query1<int>(
        "INSERT INTO groups (group_id, group_name, owner_id) VALUES ("s +
            "DEFAULT,"s +
            transaction.quote(group_name) + ","s  +
            std::to_string(owner_id) +
        ") RETURNING group_id"s
    )};

    transaction.commit();

    return group_id;
}

}

namespace handler {

crow::response CreateGroup::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    auto group_id{create_group(
        static_cast<std::string>(rjson["group_name"].s()),
        rjson["owner_id"].i()
    )};

    return crow::response{crow::json::wvalue{
        {"group_id", group_id}
    }.dump()};
}

} // handler
