#include "core/user/group.h"

namespace core::user {

Group::Group(int id, const QString &name)
    : id_{id}, name_{name}
{}

QString Group::name() const {
    return name_;
}

int Group::id() const noexcept {
    return id_;
}

} // user
