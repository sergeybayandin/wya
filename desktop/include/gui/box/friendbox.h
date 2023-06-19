#ifndef FRIENDBOX_H
#define FRIENDBOX_H

#include <QLabel>
#include <QGroupBox>

namespace Ui {
class FriendBox;
}

namespace gui::box {

class FriendBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit FriendBox(int friendId, QWidget *parent = nullptr);
    ~FriendBox();

    [[ nodiscard ]]
    QLabel *friendLoginLabel() const noexcept;

    [[ nodiscard ]]
    int friendId() const noexcept;

signals:
    void friendBoxClicked(int friendId);

protected:
    void mousePressEvent(QMouseEvent *mouseEvent)   override;
    void mouseReleaseEvent(QMouseEvent *mouseEvent) override;

private:
    void _setFriendBox();

private:
    Ui::FriendBox *ui;
    int            friendId_;
};

} // box

#endif // FRIENDBOX_H
