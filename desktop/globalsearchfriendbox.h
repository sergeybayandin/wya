#ifndef GLOBALSEARCHFRIENDBOX_H
#define GLOBALSEARCHFRIENDBOX_H

#include <QGroupBox>

namespace Ui {
class GlobalSearchFriendBox;
}

class GlobalSearchFriendBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit GlobalSearchFriendBox(QWidget *parent = nullptr);
    ~GlobalSearchFriendBox();

private:
    Ui::GlobalSearchFriendBox *ui;
};

#endif // GLOBALSEARCHFRIENDBOX_H
