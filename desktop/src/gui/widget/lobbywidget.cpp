#include "ui_lobbywidget.h"

#include "gui/widget/lobbywidget.h"

#include "gui/box/groupbox.h"
#include "gui/box/messagebox.h"
#include "gui/box/globalsearchgroupbox.h"

#include "core/user.h"

#include <QDebug>
#include <QLabel>
#include <QTabBar>
#include <QScrollArea>

namespace gui::widget {

LobbyWidget::LobbyWidget(QWidget *parent)
    : QWidget           {parent},
      ui                {new Ui::LobbyWidget},
      friendsTabWidget_ {new FriendsTabWidget},
      groupsTabWidget_  {new GroupsTabWidget},
      globalSearchTimer_{new QTimer{this}}
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
    auto groupBox       {_createGroupBox(groupId)};
    auto groupNameText  {groupBox->groupNameLabel()->text()};

    groupBox->setHidden(!groupNameText.startsWith(groupNamePrefix));

    groupsTabWidget_->addGroupBox(groupBox);
}

void LobbyWidget::displayFriendsAndGroups() {
    //auto friends{core::User::user().friends()};
    auto groups {core::User::user().groups()};

    for (const auto &g : groups) {
        groupsTabWidget_->addGroupBox(_createGroupBox(g.id()));
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
            _createGlobalSearchGroupBox(groupId, groupName)
        );
    }
}

void LobbyWidget::displayReceivedMessageToGroup(
    int            userId,
    int            groupId,
    const QString &userLogin,
    const QString &textMessage
) {
    auto messageBox{new box::MessageBox{
        userId, userLogin, textMessage
    }};
    auto groupChatDialog{_createOrReturnGroupChatDialog(
        groupId,
        core::User::user().groups()[groupId].name()
    )};
    groupChatDialog->addMessageBox(messageBox);
}

void LobbyWidget::displayJoinedGroup(int groupId) {
    auto groupChatDialog{_createOrReturnGroupChatDialog(
        groupId,
        core::User::user().groups()[groupId].name()
    )};

    if (groupsTabWidget_->hasGlobalSearchGroupBox(groupId)) {
        groupsTabWidget_->removeGlobalSearchGroupBox(groupId);
        groupsTabWidget_->globalSearchLabel()->setHidden(
            groupsTabWidget_->globalSearchGroupBoxesCount() == 0
        );
    }

    groupChatDialog->setChatPage();

    displayCreatedGroup(groupId);
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
    globalSearchTimer_->setSingleShot(true);
}

void LobbyWidget::_setConnects() {
    connect(globalSearchTimer_, &QTimer::timeout, this, [this]() {
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

void LobbyWidget::_displayGroupChatDialog(int groupId) {
    auto groupChatDialog{_createOrReturnGroupChatDialog(
        groupId,
        core::User::user().groups()[groupId].name()
    )};
    groupChatDialog->show();
}

void LobbyWidget::_displayGlobalSearchGroupChatDialog(int groupId, const QString &groupNameText) {
    auto groupChatDialog{_createOrReturnGroupChatDialog(groupId, groupNameText)};
    groupChatDialog->show();
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

    if (globalSearchTimer_->isActive()) {
        globalSearchTimer_->stop();
    }

    groupsTabWidget_->clearGlobalSearchGroupBoxes();
    groupsTabWidget_->globalSearchLabel()->setHidden(true);

    if (!groupNamePrefixText.isEmpty()) {
        globalSearchTimer_->start(4500);
    }
}

box::GroupBox *LobbyWidget::_createGroupBox(int groupId) {
    auto groupBox{new box::GroupBox{groupId}};
    connect(
        groupBox,
        SIGNAL(groupBoxClicked(int)),
        this,
        SLOT(_displayGroupChatDialog(int))
    );
    return groupBox;
}

box::GlobalSearchGroupBox *
LobbyWidget::_createGlobalSearchGroupBox(int groupId, const QString &groupNameText) {
    auto globalSearchGroupBox{new box::GlobalSearchGroupBox{groupId, groupNameText}};
    connect(
        globalSearchGroupBox,
        SIGNAL(globalSearchGroupBoxClicked(int, const QString&)),
        this,
        SLOT(_displayGlobalSearchGroupChatDialog(int, const QString&))
    );
    return globalSearchGroupBox;
}

dialog::GroupChatDialog *LobbyWidget::_createOrReturnGroupChatDialog(
    int            groupId,
    const QString &groupName
) {
    auto found{groupChatDialogs_.find(groupId)};

    if (found != groupChatDialogs_.end()) {
        return *found;
    }

    auto groupChatDialog{new dialog::GroupChatDialog{groupId, groupName, this}};

    groupChatDialog->setModal(true);

    connect(
        groupChatDialog,
        &dialog::GroupChatDialog::textMessageEntered,
        this,
        [this](int groupId, const QString &textMessage) {
            emit needToSendToGroupTextMessage(groupId, textMessage);
        }
    );
    connect(
        groupChatDialog,
        &dialog::GroupChatDialog::userWannaJoinToGroup,
        this,
        [this](int groupId, const QString &groupName) {
            emit needToJoinUserToGroup(groupId, groupName);
        }
    );

    if (core::User::user().groups().contains(groupId)) {
        groupChatDialog->setChatPage();
    } else {
        groupChatDialog->setJoinPage();
    }

    return (groupChatDialogs_[groupId] = groupChatDialog);
}

} // widget
