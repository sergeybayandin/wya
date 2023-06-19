#ifndef FRIENDCHATDIALOG_H
#define FRIENDCHATDIALOG_H

#include "gui/box/messagebox.h"

#include <QDialog>

namespace Ui {
class FriendChatDialog;
}

namespace gui::dialog {

class FriendChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FriendChatDialog(
        int            friendId,
        const QString &friendLogin,
        QWidget       *parent = nullptr
    );
    ~FriendChatDialog();

    void addMessageBox(box::MessageBox *messageBox);

signals:
    void textMessageEntered(int groupId, const QString &messageText);

private slots:
    void on_messageLineEdit_returnPressed();
    void on_sendPushButton_clicked();

private:
    void _addSelfMessageBox();
    void _setConnects();

private:
    Ui::FriendChatDialog *ui;
    int                   friendId_;
};

} // dialog

#endif // FRIENDCHATDIALOG_H
