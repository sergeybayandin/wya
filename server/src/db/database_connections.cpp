#include "db/database_config.h"
#include "db/database_connections.h"

namespace db {

DatabaseConnections &DatabaseConnections::connections() {
    static DatabaseConnections connections;
    return connections;
}

pqxx::connection &DatabaseConnections::current_connection() {
    auto [it, _]{connections_.try_emplace(
        std::this_thread::get_id(),
        DatabaseConfig::config().as_string()
    )};
    return it->second;
}

void DatabaseConnections::set_count(std::size_t count) {
    connections_.reserve(count);
}

} // db
