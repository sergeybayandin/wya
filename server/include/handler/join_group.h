#ifndef JOIN_GROUP_H
#define JOIN_GROUP_H

#include "third_party/crow.h"

namespace handler {

class JoinGroup final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:

};

} // handler

#endif // JOIN_GROUP_H
