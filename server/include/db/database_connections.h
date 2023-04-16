#ifndef DATABASE_CONNECTIONS_H
#define DATABASE_CONNECTIONS_H

#include <thread>
#include <unordered_map>

#include <pqxx/connection>

namespace db {

class DatabaseConnections final {
public:
    [[ nodiscard ]]
    static DatabaseConnections &connections();

    [[ nodiscard ]]
    pqxx::connection &current_connection();

    void set_count(std::size_t count);

private:
    std::unordered_map<
        std::thread::id,
        pqxx::connection
    > connections_;
};

} // db

#endif // DATABASE_CONNECTIONS_H
