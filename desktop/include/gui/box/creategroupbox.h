#ifndef CREATEGROUPBOX_H
#define CREATEGROUPBOX_H

#include <QGroupBox>

namespace Ui {
class CreateGroupBox;
}

namespace gui::box {

class CreateGroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit CreateGroupBox(QWidget *parent = nullptr);
    ~CreateGroupBox();

signals:
    void groupCreated(const QString &groupName);

private slots:
    void on_createPushButton_clicked();
    void on_groupNameLineEdit_returnPressed();

private:
    Ui::CreateGroupBox *ui;
};

} // box

#endif // CREATEGROUPBOX_H
