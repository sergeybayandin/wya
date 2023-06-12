#ifndef FRIENDBOX_H
#define FRIENDBOX_H

#include <QGroupBox>

namespace Ui {
class FriendBox;
}

class FriendBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit FriendBox(QWidget *parent = nullptr);
    ~FriendBox();

private:
    Ui::FriendBox *ui;
};

#endif // FRIENDBOX_H
