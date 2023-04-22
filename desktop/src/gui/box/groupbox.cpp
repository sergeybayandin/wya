#include "ui_groupbox.h"

#include "core/user.h"

#include "gui/box/groupbox.h"

namespace gui::box {

GroupBox::GroupBox(int groupId, QWidget *parent)
    : QGroupBox{parent},
      ui       {new Ui::GroupBox},
      groupId_ {groupId}
{
    ui->setupUi(this);
    _setGroupBox();
}

GroupBox::~GroupBox() {
    delete ui;
}

void GroupBox::_setGroupBox() {
    const auto &g{core::User::user().groups()[groupId_]};
    ui->groupNameLabel->setText(g.name());
}

} // box
