#include "ui_globalsearchfriendbox.h"

#include "gui/box/globalsearchfriendbox.h"

namespace gui::box {

GlobalSearchFriendBox::GlobalSearchFriendBox(
    int            userId,
    const QString &userLoginText,
    QWidget       *parent
)
    : QGroupBox{parent},
      ui       {new Ui::GlobalSearchFriendBox},
      userId_  {userId}
{
    ui->setupUi(this);
    ui->userLoginLabel->setText(userLoginText);
}

GlobalSearchFriendBox::~GlobalSearchFriendBox() {
    delete ui;
}

int GlobalSearchFriendBox::userId() const noexcept {
    return userId_;
}

void GlobalSearchFriendBox::on_addUserPushButton_clicked() {
    emit userNeedToBeAdded(userId_, ui->userLoginLabel->text());
}

} // box
