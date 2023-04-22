#include "ui_lobbywidget.h"

#include "gui/widget/lobbywidget.h"

#include "gui/box/groupbox.h"

#include "core/user.h"

#include <QTabBar>
#include <QScrollArea>

namespace gui::widget {

LobbyWidget::LobbyWidget(QWidget *parent)
    : QWidget          {parent},
      ui               {new Ui::LobbyWidget},
      friendsTabWidget_{new FriendsTabWidget},
      groupsTabWidget_ {new GroupsTabWidget}
{
    ui->setupUi(this);
    _setTabWidget();
}

LobbyWidget::~LobbyWidget() {
    delete ui;
}

FriendsTabWidget *LobbyWidget::friendsTabWidget() const noexcept {
    return friendsTabWidget_;
}

GroupsTabWidget *LobbyWidget::groupsTabWidget() const noexcept {
    return groupsTabWidget_;
}

void LobbyWidget::displayCreatedGroup(int groupId) {
    groupsTabWidget_->addGroup(new box::GroupBox{groupId});
}

void LobbyWidget::displayFriendsAndGroups() {
    //auto friends{core::User::user().friends()};
    auto groups {core::User::user().groups()};

    for (const auto &g : groups) {
        groupsTabWidget_->addGroup(new gui::box::GroupBox{g.id()});
    }
}

void LobbyWidget::_setTabWidget() {
    auto friendsTabScrollArea{new QScrollArea};
    auto groupsTabScrollArea {new QScrollArea};

    friendsTabScrollArea->setWidgetResizable(true);
    groupsTabScrollArea->setWidgetResizable(true);

    friendsTabScrollArea->setWidget(friendsTabWidget_);
    groupsTabScrollArea->setWidget(groupsTabWidget_);

    friendsTabScrollArea->setStyleSheet("QScrollArea{ border: 0px; }");
    groupsTabScrollArea->setStyleSheet("QScrollArea{ border: 0px; }");

    ui->tabWidget->addTab(friendsTabScrollArea, "Друзья");
    ui->tabWidget->addTab(groupsTabScrollArea,  "Группы");

    ui->tabWidget->tabBar()->setDocumentMode(true);
    ui->tabWidget->tabBar()->setExpanding(true);
}

} // widget
