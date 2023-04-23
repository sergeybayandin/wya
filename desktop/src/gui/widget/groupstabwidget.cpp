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

box::GroupBox *GroupsTabWidget::groupBoxAt(int i) const noexcept {
    return static_cast<box::GroupBox*>(
        ui->groupBoxesVerticalLayout->itemAt(i)->widget()
    );
}

box::GroupBox *GroupsTabWidget::globalSearchGroupBoxAt(int i) const noexcept {
    return static_cast<box::GroupBox*>(
        ui->globalSearchGroupBoxesVerticalLayout->itemAt(i)->widget()
    );
}

QLabel *GroupsTabWidget::globalSearchLabel() const noexcept {
    return ui->globalSearchLabel;
}

int GroupsTabWidget::groupBoxesCount() const noexcept {
    return ui->groupBoxesVerticalLayout->count();
}

int GroupsTabWidget::globalSearchGroupBoxesCount() const noexcept {
    return ui->groupBoxesVerticalLayout->count();
}

void GroupsTabWidget::addGroupBox(box::GroupBox *groupBox) {
    ui->groupBoxesVerticalLayout->addWidget(groupBox);
}

void GroupsTabWidget::addGlobalSearchGroupBox(box::GlobalSearchGroupBox *globalSearchGroupBox) {
    ui->globalSearchGroupBoxesVerticalLayout->addWidget(globalSearchGroupBox);
}

void GroupsTabWidget::clearGlobalSearchGroupBoxes() {
    QLayoutItem *item;
    while ((item = ui->globalSearchGroupBoxesVerticalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
}

} // widget
