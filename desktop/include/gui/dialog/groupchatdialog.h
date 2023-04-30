#ifndef GROUPCHATDIALOG_H
#define GROUPCHATDIALOG_H

#include "gui/box/messagebox.h"

#include <QDialog>

namespace Ui {
class GroupChatDialog;
}

namespace gui::dialog {

class GroupChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupChatDialog(
        int            groupId,
        const QString &groupName,
        QWidget       *parent = nullptr
    );
    ~GroupChatDialog();

    void addMessageBox(box::MessageBox *messageBox);

    void setChatPage();
    void setJoinPage();

signals:
    void textMessageEntered(int groupId, const QString &messageText);
    void userWannaJoinToGroup(int grouId, const QString &groupName);

private slots:
    void on_messageLineEdit_returnPressed();
    void on_joinPushButton_clicked();

private:
    void _addSelfMessageBox();
    void _setConnects();

private:
    Ui::GroupChatDialog *ui;
    int                  groupId_;
};

} // dialog

#endif // GROUPCHATDIALOG_H
