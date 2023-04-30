#include "handler/join_group.h"

#include "db/database_connections.h"

#include <pqxx/pqxx>

namespace {

void join_group(int user_id, int group_id) {
    using namespace std::string_literals;

    pqxx::work transaction{
        db::DatabaseConnections::connections().current_connection()
    };

    transaction.exec0(
        "INSERT INTO users_groups VALUES("s +
            std::to_string(user_id) + ","s +
            std::to_string(group_id) +
         ")"s
    );

    transaction.commit();
}

}

namespace handler {

crow::response JoinGroup::operator()(const crow::request &request) const {
    auto rjson{crow::json::load(request.body)};

    if (rjson.error()) {
        return crow::response{crow::BAD_REQUEST};
    }

    join_group(rjson["user_id"].i(), rjson["group_id"].i());

    return crow::response{crow::OK};
}

} // handler
