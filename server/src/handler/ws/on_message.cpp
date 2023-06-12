#include "handler/ws/on_message.h"

#include "net/online_users.h"

#include "types/action.h"

namespace handler::ws {

void OnMessage::operator()(
    crow::websocket::connection &connection,
    const std::string           &json,
    bool
) const {
    auto rjson{crow::json::load(json)};

    if (rjson.error()) {
        return;
    }

    auto action{static_cast<types::Action>(
        rjson["action"].i()
    )};

    switch (action) {
    case types::GoOnline    :
        net::OnlineUsers::users().go_online(rjson["user_id"].i(), &connection);
        break;

    case types::GoOffline :
        net::OnlineUsers::users().go_offline(rjson["user_id"].i());
        break;

    default :
        // ???
        break;
    }
}

} // ws
