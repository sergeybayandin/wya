#ifndef GROUPSTAB_H
#define GROUPSTAB_H

#include "gui/box/creategroupbox.h"
#include "gui/box/groupbox.h"

#include <QWidget>

namespace Ui {
class GroupsTabWidget;
}

namespace gui::widget {

class GroupsTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GroupsTabWidget(QWidget *parent = nullptr);
    ~GroupsTabWidget();

    box::CreateGroupBox *createGroupBox() const noexcept;

    void addGroup(box::GroupBox *groupBox);

private:
    Ui::GroupsTabWidget *ui;
    box::CreateGroupBox *createGroupBox_;
};

} // widget

#endif // GROUPSTAB_H
