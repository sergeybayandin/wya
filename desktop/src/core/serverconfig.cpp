#include "core/serverconfig.h"

namespace core {

const ServerConfig &ServerConfig::config() {
    static ServerConfig config;
    return config;
}

QString ServerConfig::url() const {
    return url_;
}

} // core
