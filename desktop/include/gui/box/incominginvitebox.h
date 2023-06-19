#ifndef INCOMINGINVITEBOX_H
#define INCOMINGINVITEBOX_H

#include <QLabel>
#include <QGroupBox>

namespace Ui {
class IncomingInviteBox;
}

namespace gui::box {

class IncomingInviteBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit IncomingInviteBox(int fromUserId, QWidget *parent = nullptr);
    ~IncomingInviteBox();

    [[ nodiscard ]]
    QLabel *fromUserLoginLabel() const noexcept;

    [[ nodiscard ]]
    int fromUserId() const noexcept;

signals:
    void inviteAccepted(int fromUserId);
    void inviteRejected(int fromUserId);

private slots:
    void on_acceptPushButton_clicked();
    void on_rejectPushButton_clicked();

private:
    void _setIncomingInviteBox();

private:
    Ui::IncomingInviteBox *ui;
    int                    fromUserId_;
};

} // box

#endif // INCOMINGINVITEBOX_H
