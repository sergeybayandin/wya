#include "ui_lobbywidget.h"

#include "gui/widget/lobbywidget.h"

#include "gui/box/groupbox.h"
#include "gui/box/globalsearchgroupbox.h"

#include "core/user.h"

#include <QLabel>
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
    _setGlobalSearchTimer();

    _setConnects();
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
    auto groupNamePrefix{ui->searchLineEdit->text()};
    auto groupBox       {new box::GroupBox{groupId}};
    auto groupNameText  {groupBox->groupNameLabel()->text()};

    groupBox->setHidden(!groupNameText.startsWith(groupNamePrefix));

    groupsTabWidget_->addGroupBox(groupBox);
}

void LobbyWidget::displayFriendsAndGroups() {
    //auto friends{core::User::user().friends()};
    auto groups {core::User::user().groups()};

    for (const auto &g : groups) {
        groupsTabWidget_->addGroupBox(new gui::box::GroupBox{g.id()});
    }
}

void LobbyWidget::displayGlobalSearchResults(
    const QVector<QPair<int, QString>> &globalSearchResults
) {
    groupsTabWidget_->globalSearchLabel()->setHidden(
        globalSearchResults.isEmpty()
    );

    for (const auto &[groupId, groupName] : globalSearchResults) {
        groupsTabWidget_->addGlobalSearchGroupBox(
            new box::GlobalSearchGroupBox{groupId, groupName}
        );
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

void LobbyWidget::_setGlobalSearchTimer() {
    globalSearchTimer_.setSingleShot(true);
}

void LobbyWidget::_setConnects() {
    connect(&globalSearchTimer_, &QTimer::timeout, this, [this]() {
        emit needToGlobalSearch(
            ui->searchLineEdit->text()
        );
    });
}

void LobbyWidget::on_searchLineEdit_textEdited(
    const QString &prefixText
) {
    if (ui->tabWidget->currentWidget() == friendsTabWidget_) {
        _doFriendsSearch(prefixText);
    } else {
        _doGroupSearch(prefixText);
    }
}

void LobbyWidget::_doFriendsSearch(const QString &friendNamePrefixText) {
    Q_UNUSED(friendNamePrefixText);
}

void LobbyWidget::_doGroupSearch(const QString &groupNamePrefixText) {
    auto count{groupsTabWidget_->groupBoxesCount()};

    for (int i{0}; i < count; ++i) {
        auto groupBox     {groupsTabWidget_->groupBoxAt(i)};
        auto groupNameText{groupBox->groupNameLabel()->text()};
        auto startsWith   {groupNameText.startsWith(groupNamePrefixText)};

        groupBox->setHidden(!startsWith);
    }

    if (globalSearchTimer_.isActive()) {
        globalSearchTimer_.stop();
    }

    groupsTabWidget_->clearGlobalSearchGroupBoxes();
    groupsTabWidget_->globalSearchLabel()->setHidden(true);

    if (!groupNamePrefixText.isEmpty()) {
        globalSearchTimer_.start(4500);
    }
}

} // widget
