#ifndef OUTGOINGINVITEBOX_H
#define OUTGOINGINVITEBOX_H

#include <QLabel>
#include <QGroupBox>

namespace Ui {
class OutgoingInviteBox;
}

namespace gui::box {

class OutgoingInviteBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit OutgoingInviteBox(int toUserId, QWidget *parent = nullptr);
    ~OutgoingInviteBox();

    [[ nodiscard ]]
    QLabel *toUserLoginLabel() const noexcept;

    [[ nodiscard ]]
    int toUserId() const noexcept;

signals:
    void inviteCanceled(int toUserId);

private slots:
    void on_cancelPushButton_clicked();

private:
    void _setOutgoingInviteBox();

private:
    Ui::OutgoingInviteBox *ui;
    int                    toUserId_;
};

} // box

#endif // OUTGOINGINVITEBOX_H
