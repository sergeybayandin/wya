#include "net/online_users.h"

namespace net {

OnlineUsers &OnlineUsers::users() {
   static OnlineUsers users;
   return users;
}

crow::websocket::connection *OnlineUsers::connection(int user_id) {
    return online_users_[user_id];
}

std::pair<bool, crow::websocket::connection*>
OnlineUsers::try_connection(int user_id) {
    std::lock_guard g{mutex_};
    auto            found{online_users_.find(user_id)};

    if (found != online_users_.end()) {
        return std::pair<bool, crow::websocket::connection*>{true, found->second};
    }

    return std::pair<bool, crow::websocket::connection*>{false, nullptr};
}

void OnlineUsers::go_online(int user_id, crow::websocket::connection *connection) {
    std::lock_guard g{mutex_};
    online_users_[user_id] = connection;
}

void OnlineUsers::go_offline(int user_id) {
    std::lock_guard g{mutex_};
    online_users_.erase(user_id);
}

} // net
