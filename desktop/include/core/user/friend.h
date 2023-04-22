#ifndef FRIEND_H
#define FRIEND_H

#include <QString>

namespace core::user {

class Friend final {
public:
    Friend() = default;
    explicit Friend(int id, const QString &login);

    [[ nodiscard ]]
    QString login() const;

    [[ nodiscard ]]
    int id() const noexcept;

private:
    int     id_;
    QString login_;
};

} // user

#endif // FRIEND_H
