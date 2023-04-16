#include "db/database_config.h"

namespace db {

const DatabaseConfig &DatabaseConfig::config() {
    static const DatabaseConfig config;
    return config;
}

std::string_view DatabaseConfig::username() const noexcept {
    return username_;
}

std::string_view DatabaseConfig::password() const noexcept {
    return password_;
}

std::string_view DatabaseConfig::database_name() const noexcept {
    return database_name_;
}

std::string DatabaseConfig::as_string() const {
    using namespace std::string_literals;
    return "dbname="s   + database_name_ + " "s +
           "user="s     + username_      + " "s +
           "password="s + password_;
}

} // db
