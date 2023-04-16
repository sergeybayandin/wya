#ifndef AUTHORIZE_H
#define AUTHORIZE_H

#include "third_party/crow.h"

namespace handler {

class Authorize final {
public:
    [[ nodiscard ]]
    crow::response operator()(const crow::request &request) const;

private:

};

} // handler

#endif // AUTHORIZE_H
