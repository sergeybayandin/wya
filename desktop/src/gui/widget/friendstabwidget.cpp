#include "ui_friendstabwidget.h"

#include "gui/widget/friendstabwidget.h"

namespace gui::widget {

FriendsTabWidget::FriendsTabWidget(QWidget *parent)
    : QWidget{parent},
      ui     {new Ui::FriendsTabWidget}
{
    ui->setupUi(this);
}

FriendsTabWidget::~FriendsTabWidget() {
    delete ui;
}

} // widget
