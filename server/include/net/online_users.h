#ifndef ONLINE_USERS_H
#define ONLINE_USERS_H

#include <mutex>
#include <unordered_map>

#include "third_party/crow.h"

namespace net {

class OnlineUsers final {
public:
    static OnlineUsers &users();

    [[ nodiscard ]]
    crow::websocket::connection *connection(int user_id);

    [[ nodiscard ]]
    std::pair<bool, crow::websocket::connection*> try_connection(int user_id);

    void go_online(int user_id, crow::websocket::connection *connection);
    void go_offline(int user_id);

private:
    std::unordered_map<
        int,
        crow::websocket::connection *
    > online_users_;

    std::mutex mutex_;
};

} // net

#endif // ONLINE_USERS_H
