#include "ui_groupstabwidget.h"

#include "gui/widget/groupstabwidget.h"

namespace gui::widget {

GroupsTabWidget::GroupsTabWidget(QWidget *parent)
    : QWidget        {parent},
      ui             {new Ui::GroupsTabWidget},
      createGroupBox_{new box::CreateGroupBox}
{
    ui->setupUi(this);
    ui->verticalLayout->insertWidget(0, createGroupBox_);
}

GroupsTabWidget::~GroupsTabWidget() {
    delete ui;
}

box::CreateGroupBox *GroupsTabWidget::createGroupBox() const noexcept {
    return createGroupBox_;
}

void GroupsTabWidget::addGroup(box::GroupBox *groupBox) {
    ui->verticalLayout->insertWidget(1, groupBox);
}

} // widget
