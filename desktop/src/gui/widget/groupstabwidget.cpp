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
    ui->globalSearchLabel->setHidden(true);
}

GroupsTabWidget::~GroupsTabWidget() {
    delete ui;
}

box::CreateGroupBox *GroupsTabWidget::createGroupBox() const noexcept {
    return createGroupBox_;
}

QLabel *GroupsTabWidget::globalSearchLabel() const noexcept {
    return ui->globalSearchLabel;
}

void GroupsTabWidget::addGroupBox(box::GroupBox *groupBox) {
    auto groupId{groupBox->groupId()};
    if (!groupBoxes_.contains(groupId)) {
        ui->groupBoxesVerticalLayout->addWidget(
            groupBoxes_[groupId] = groupBox
        );
    }
}

void GroupsTabWidget::addGlobalSearchGroupBox(box::GlobalSearchGroupBox *globalSearchGroupBox) {
    auto groupId{globalSearchGroupBox->groupId()};
    if (!globalSearchGroupBoxes_.contains(groupId)) {
        ui->globalSearchGroupBoxesVerticalLayout->addWidget(
            globalSearchGroupBoxes_[groupId] = globalSearchGroupBox
        );
    }
}

void GroupsTabWidget::clearGlobalSearchGroupBoxes() {
    QLayoutItem *item;
    while ((item = ui->globalSearchGroupBoxesVerticalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    globalSearchGroupBoxes_.clear();
}

void GroupsTabWidget::removeGlobalSearchGroupBox(int groupId) {
    auto globalSearchGroupBox{globalSearchGroupBoxes_[groupId]};

    auto index{ui->globalSearchGroupBoxesVerticalLayout->indexOf(globalSearchGroupBox)};
    auto item {ui->globalSearchGroupBoxesVerticalLayout->takeAt(index)};

    delete item->widget();
    delete item;

    globalSearchGroupBoxes_.remove(groupId);
}

bool GroupsTabWidget::hasGlobalSearchGroupBox(int groupId) const {
    return globalSearchGroupBoxes_.contains(groupId);
}

box::GroupBox *GroupsTabWidget::groupBoxAt(int i) const noexcept {
    return static_cast<box::GroupBox *>(
        ui->groupBoxesVerticalLayout->itemAt(i)->widget()
    );
}

int GroupsTabWidget::groupBoxesCount() const noexcept {
    return ui->groupBoxesVerticalLayout->count();
}

int GroupsTabWidget::globalSearchGroupBoxesCount() const noexcept {
    return ui->globalSearchGroupBoxesVerticalLayout->count();
}

} // widget
