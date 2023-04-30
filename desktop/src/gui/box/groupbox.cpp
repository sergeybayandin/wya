#include "ui_groupbox.h"

#include "core/user.h"

#include "gui/box/groupbox.h"

#include <QMouseEvent>

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

QLabel *GroupBox::groupNameLabel() const noexcept {
    return ui->groupNameLabel;
}

void GroupBox::_setGroupBox() {
    ui->groupNameLabel->setText(
        core::User::user().groups()[groupId_].name()
    );
}

void GroupBox::mousePressEvent(QMouseEvent *mouseEvent) {
    QGroupBox::mousePressEvent(mouseEvent);
}

void GroupBox::mouseReleaseEvent(QMouseEvent *mouseEvent) {
    emit groupBoxClicked(groupId_);
    QGroupBox::mouseReleaseEvent(mouseEvent);
}

int GroupBox::groupId() const noexcept {
    return groupId_;
}

} // box
