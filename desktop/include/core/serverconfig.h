#ifndef SERVERCONFIG_H
#define SERVERCONFIG_H

#include <QString>

namespace core {

class ServerConfig
{
public:
    [[ nodiscard ]]
    static const ServerConfig &config();

    [[ nodiscard ]]
    QString url() const;

private:
    QString url_;
};

} // core

#endif // SERVERCONFIG_H
