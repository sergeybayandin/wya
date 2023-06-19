#ifndef INCOMINGINVITE_H
#define INCOMINGINVITE_H

#include <QString>

namespace core::user {

class IncomingInvite final
{
public:
    IncomingInvite() = default;
    explicit IncomingInvite(int fromUserId, const QString &fromUserLogin);

    [[ nodiscard ]]
    QString fromUserLogin() const;

    [[ nodiscard ]]
    int fromUserId() const noexcept;

private:
    int     fromUserId_;
    QString fromUserLogin_;
};

} // user

#endif // INCOMINGINVITE_H
