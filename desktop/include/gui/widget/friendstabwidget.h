#ifndef FRIENDSTAB_H
#define FRIENDSTAB_H

#include <QWidget>

namespace Ui {
class FriendsTabWidget;
}

namespace gui::widget {

class FriendsTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FriendsTabWidget(QWidget *parent = nullptr);
    ~FriendsTabWidget();

private:
    Ui::FriendsTabWidget *ui;
};

} // widget

#endif // FRIENDSTAB_H
