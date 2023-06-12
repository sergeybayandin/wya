#ifndef FRIENDCHATDIALOG_H
#define FRIENDCHATDIALOG_H

#include <QDialog>

namespace Ui {
class FriendChatDialog;
}

class FriendChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FriendChatDialog(QWidget *parent = nullptr);
    ~FriendChatDialog();

private:
    Ui::FriendChatDialog *ui;
};

#endif // FRIENDCHATDIALOG_H
