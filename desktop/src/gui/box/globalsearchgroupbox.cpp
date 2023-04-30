#include "ui_globalsearchgroupbox.h"

#include "gui/box/globalsearchgroupbox.h"

namespace gui::box {

GlobalSearchGroupBox::GlobalSearchGroupBox(
    int            groupId,
    const QString &groupNameText,
    QWidget       *parent
)
    : QGroupBox{parent},
      ui       {new Ui::GlobalSearchGroupBox},
      groupId_ {groupId}
{
    ui->setupUi(this);
    ui->groupNameLabel->setText(groupNameText);
}

GlobalSearchGroupBox::~GlobalSearchGroupBox() {
    delete ui;
}

void GlobalSearchGroupBox::mousePressEvent(QMouseEvent *mouseEvent) {
    QGroupBox::mousePressEvent(mouseEvent);
}

void GlobalSearchGroupBox::mouseReleaseEvent(QMouseEvent *mouseEvent) {
    emit globalSearchGroupBoxClicked(groupId_, ui->groupNameLabel->text());
    QGroupBox::mouseReleaseEvent(mouseEvent);
}

int GlobalSearchGroupBox::groupId() const noexcept {
    return groupId_;
}

} // box
