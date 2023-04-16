#include "handler/authorize.h"
#include "handler/register.h"

int main() {
    crow::SimpleApp app;        

    CROW_ROUTE(app, "/authorize")
        .methods("POST"_method)(handler::Authorize{});

    CROW_ROUTE(app, "/register")
        .methods("POST"_method)(handler::Register{});

    return 0;
}
