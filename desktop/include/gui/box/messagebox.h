#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <QGroupBox>

namespace Ui {
class MessageBox;
}

namespace gui::box {

class MessageBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit MessageBox(
        int            userId,
        const QString &userLogin,
        const QString &textMessage,
        QWidget *parent = nullptr
    );
    ~MessageBox();

private:
    void _setMessageBox(
        const QString &userLoginText,
        const QString &textMessageText
    );

private:
    Ui::MessageBox *ui;
    int             userId_;
};

} // box

#endif // MESSAGEBOX_H
