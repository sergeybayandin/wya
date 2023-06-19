#ifndef GLOBALSEARCHFRIENDBOX_H
#define GLOBALSEARCHFRIENDBOX_H

#include <QGroupBox>

namespace Ui {
class GlobalSearchFriendBox;
}

namespace gui::box {

class GlobalSearchFriendBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit GlobalSearchFriendBox(
        int            userId,
        const QString &userLoginText,
        QWidget       *parent = nullptr
    );
    ~GlobalSearchFriendBox();

    [[ nodiscard ]]
    int userId() const noexcept;

signals:
    void userNeedToBeAdded(int userId, const QString &userLogin);

private slots:
    void on_addUserPushButton_clicked();

private:
    Ui::GlobalSearchFriendBox *ui;
    int                        userId_;
};

} // box

#endif // GLOBALSEARCHFRIENDBOX_H
