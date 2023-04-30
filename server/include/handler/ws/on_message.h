#ifndef ON_MESSAGE_H
#define ON_MESSAGE_H

#include "third_party/crow.h"

namespace handler::ws {

class OnMessage final {
public:
    void operator()(
        crow::websocket::connection &connection,
        const std::string           &json,
        bool /* always binary */
    ) const;

private:
};

} // ws

#endif // ON_MESSAGE_H
