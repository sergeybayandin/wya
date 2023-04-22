#ifndef GROUP_H
#define GROUP_H

#include <QString>

namespace core::user {

class Group final {
public:
    Group() = default;
    explicit Group(int id, const QString &name);

    [[ nodiscard ]]
    QString name() const;

    [[ nodiscard ]]
    int id() const noexcept;

private:
    int     id_;
    QString name_;
};

} // user

#endif // GROUP_H
