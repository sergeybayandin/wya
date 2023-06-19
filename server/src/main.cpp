#include "handler/handler.h"

#include "db/database_connections.h"

#include <charconv>
#include <string_view>

[[ nodiscard ]]
std::optional<short> parse_arguments(int argc, char *argv[]);

int main(int argc, char *argv[]) {
    auto opt{parse_arguments(argc, argv)};

    if (!opt.has_value()) {
        return -1;
    }

    crow::SimpleApp app;        

    auto port       {*opt};
    auto concurrency{std::thread::hardware_concurrency()};

    db::DatabaseConnections::connections().set_count(concurrency);

    CROW_ROUTE(app, "/authorize")
        .methods("POST"_method)(handler::Authorize{});

    CROW_ROUTE(app, "/register")
        .methods("POST"_method)(handler::Register{});

    CROW_ROUTE(app, "/create_group")
        .methods("POST"_method)(handler::CreateGroup{});

    CROW_ROUTE(app, "/friends&groups")
        .methods("POST"_method)(handler::FriendsAndGroups{});

    CROW_ROUTE(app, "/global_search/groups")
        .methods("POST"_method)(handler::GroupsGlobalSearch{});

    CROW_ROUTE(app, "/global_search/friends")
        .methods("POST"_method)(handler::UsersGlobalSearch{});

    CROW_ROUTE(app, "/join_group")
        .methods("POST"_method)(handler::JoinGroup{});

    CROW_ROUTE(app, "/send_to_group")
        .methods("POST"_method)(handler::SendToGroup{});

    CROW_ROUTE(app, "/add_user")
        .methods("POST"_method)(handler::AddUser{});

    CROW_ROUTE(app, "/accept_user_invite")
        .methods("POST"_method)(handler::AcceptUserInvite{});

    CROW_ROUTE(app, "/reject_user_invite")
        .methods("POST"_method)(handler::RejectUserInvite{});

    CROW_ROUTE(app, "/cancel_user")
        .methods("POST"_method)(handler::CancelUser{});

    CROW_ROUTE(app, "/send_to_friend")
        .methods("POST"_method)(handler::SendToFriend{});

    CROW_ROUTE(app, "/ws")
        .websocket()
        .onmessage(handler::ws::OnMessage{});

    app.concurrency(concurrency).port(port).run();

    return 0;
}

std::optional<short> parse_arguments(int argc, char *argv[]) {
    auto print_usage{[prog = argv[0]]() {
        std::cerr << "Usage: " << prog << " [ port ]\n";
    }};

    if (argc != 2) {
        print_usage();
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
        print_usage();
        return std::nullopt;
    }

    return port;
}
