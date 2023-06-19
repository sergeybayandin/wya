#ifndef CANCEL_USER_H
#define CANCEL_USER_H

#include "third_party/crow.h"

namespace handler {

class CancelUser final {
public:
    crow::response operator()(const crow::request &request) const;

private:
};

} // handler

#endif // CANCEL_USER_H
