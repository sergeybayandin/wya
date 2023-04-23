#ifndef GLOBALSEARCHGROUPBOX_H
#define GLOBALSEARCHGROUPBOX_H

#include <QGroupBox>

namespace Ui {
class GlobalSearchGroupBox;
}

namespace gui::box {

class GlobalSearchGroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit GlobalSearchGroupBox(
        int            groupId,
        const QString &groupNameText,
        QWidget       *parent = nullptr
    );
    ~GlobalSearchGroupBox();

private:
    Ui::GlobalSearchGroupBox *ui;
    int                       groupId_;
};

} // box

#endif // GLOBALSEARCHGROUPBOX_H
