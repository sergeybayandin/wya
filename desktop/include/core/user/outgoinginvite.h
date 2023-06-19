#ifndef OUTGOINGINVITE_H
#define OUTGOINGINVITE_H

#include <QString>

namespace core::user {

class OutgoingInvite final
{
public:
    OutgoingInvite() = default;
    explicit OutgoingInvite(int toUserId, const QString &toUserLogin);

    [[ nodiscard ]]
    QString toUserLogin() const;

    [[ nodiscard ]]
    int toUserId() const noexcept;

private:
    int     toUserId_;
    QString toUserLogin_;
};

} // user

#endif // OUTGOINGINVITE_H
