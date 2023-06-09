cmake_minimum_required(VERSION 3.22)

project(server)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(third_party/crow/include)

set(SOURCES
    src/main.cpp

    src/handler/authorize.cpp
    src/handler/register.cpp
    src/handler/create_group.cpp
    src/handler/friends_and_groups.cpp
    src/handler/global_search.cpp
    src/handler/join_group.cpp
    src/handler/send_to_group.cpp
    src/handler/send_to_friend.cpp
    src/handler/add_user.cpp
    src/handler/accept_user_invite.cpp
    src/handler/reject_user_invite.cpp
    src/handler/cancel_user.cpp

    src/handler/ws/on_message.cpp

    src/db/database_config.cpp
    src/db/database_connections.cpp

    src/net/online_users.cpp
)

add_executable(server ${SOURCES})

target_link_libraries(server pqxx pq)
