#include "core/serverconfig.h"

namespace core {

const ServerConfig &ServerConfig::config() {
    static ServerConfig config;
    return config;
}

QString ServerConfig::url() const {
    return url_;
}

QString ServerConfig::webSocketUrl() const {
    return webSocketUrl_;
}

} // core
