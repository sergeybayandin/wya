cmake_minimum_required(VERSION 3.22)

project(server)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
include_directories(third_party/crow/include)

set(SOURCES
    src/main.cpp
    src/handler/authorize.cpp
    src/handler/register.cpp
    src/db/database_config.cpp
    src/db/database_connections.cpp
)

add_executable(server ${SOURCES})

target_link_libraries(server pqxx pq)
