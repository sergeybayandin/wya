#ifndef GROUPSTAB_H
#define GROUPSTAB_H

#include "gui/box/creategroupbox.h"
#include "gui/box/groupbox.h"
#include "gui/box/globalsearchgroupbox.h"

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

    [[ nodiscard ]]
    box::CreateGroupBox *createGroupBox() const noexcept;

    [[ nodiscard ]]
    box::GroupBox *groupBoxAt(int i) const noexcept;

    [[ nodiscard ]]
    box::GroupBox *globalSearchGroupBoxAt(int i) const noexcept;

    [[ nodiscard ]]
    QLabel *globalSearchLabel() const noexcept;

    [[ nodiscard ]]
    int groupBoxesCount() const noexcept;

    [[ nodiscard ]]
    int globalSearchGroupBoxesCount() const noexcept;

    void addGroupBox(box::GroupBox *groupBox);
    void addGlobalSearchGroupBox(box::GlobalSearchGroupBox *globalSearchGroupBox);

    void clearGlobalSearchGroupBoxes();

private:
    Ui::GroupsTabWidget *ui;
    box::CreateGroupBox *createGroupBox_;
};

} // widget

#endif // GROUPSTAB_H
