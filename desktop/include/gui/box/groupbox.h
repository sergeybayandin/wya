#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QGroupBox>

namespace Ui {
class GroupBox;
}

class QLabel;

namespace gui::box {

class GroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit GroupBox(int groupId, QWidget *parent = nullptr);
    ~GroupBox();

    QLabel *groupNameLabel() const noexcept;

private:
    void _setGroupBox();

private:
    Ui::GroupBox *ui;
    int           groupId_;
};

} // box

#endif // GROUPBOX_H
