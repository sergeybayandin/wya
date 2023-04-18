#include "handler/handler.h"

#include "db/database_connections.h"

#include <charconv>
#include <string_view>

std::optional<short> parse_arguments(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    auto opt{parse_arguments(argc, argv)};

    if (!opt.has_value()) {
        return -1;
    }

    crow::SimpleApp app;        

    auto port{*opt};
    auto concurrency{std::thread::hardware_concurrency()};

    db::DatabaseConnections::connections().set_count(concurrency);

    CROW_ROUTE(app, "/authorize")
        .methods("POST"_method)(handler::Authorize{});

    CROW_ROUTE(app, "/register")
        .methods("POST"_method)(handler::Register{});

    CROW_ROUTE(app, "/create_group")
        .methods("POST"_method)(handler::CreateGroup{});

    app.concurrency(concurrency).port(port).run();

    return 0;
}

std::optional<short> parse_arguments(int argc, char *argv[]) {
    auto print_usage{[](const char *prog) {
        std::cerr << "Usage: " << prog << " [ port ]\n";
    }};

    if (argc != 2) {
        print_usage(argv[0]);
        return std::nullopt;
    }

    short            port{0};
    std::string_view sport{argv[1]};

    auto [ptr, ec]{std::from_chars(
        sport.data(),
        sport.data() + sport.size(),
        port
    )};

    if (ec != std::errc{}) {
        print_usage(argv[0]);
        return std::nullopt;
    }

    return port;
}
