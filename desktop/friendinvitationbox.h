#ifndef FRIENDINVITATIONBOX_H
#define FRIENDINVITATIONBOX_H

#include <QGroupBox>

namespace Ui {
class FriendInvitationBox;
}

class FriendInvitationBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit FriendInvitationBox(QWidget *parent = nullptr);
    ~FriendInvitationBox();

private:
    Ui::FriendInvitationBox *ui;
};

#endif // FRIENDINVITATIONBOX_H
