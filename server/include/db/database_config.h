#ifndef DATABASE_CONFIG_H
#define DATABASE_CONFIG_H

#include <string>

namespace db {

class DatabaseConfig final {
public:
    [[ nodiscard ]]
    static const DatabaseConfig &config();

    [[ nodiscard ]]
    std::string_view username() const noexcept;

    [[ nodiscard ]]
    std::string_view password() const noexcept;

    [[ nodiscard ]]
    std::string_view database_name() const noexcept;

    [[ nodiscard ]]
    std::string as_string() const;

private:
    std::string username_;
    std::string password_;
    std::string database_name_;
};

} // db

#endif // DATABASE_CONFIG_H
