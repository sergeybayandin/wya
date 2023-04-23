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

} // box
