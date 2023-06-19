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

    _setTabWidgets();
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
    auto friends{core::User::user().friends()};
    auto groups {core::User::user().groups()};

    auto incomingInvites{core::User::user().incomingInvites()};
    auto outgoingInvites{core::User::user().outgoingInvites()};

    friendsTabWidget_->incomingInvitesLabel()->setHidden(incomingInvites.isEmpty());
    friendsTabWidget_->outgoingInvitesLabel()->setHidden(outgoingInvites.isEmpty());

    for (const auto &f : friends) {
        friendsTabWidget_->addFriendBox(_createFriendBox(f.id()));
    }

    for (const auto &incomingInvite : incomingInvites) {
        friendsTabWidget_->addIncomingInviteBox(
            _createIncomingInviteBox(incomingInvite.fromUserId())
        );
    }

    for (const auto &outgoingInvite : outgoingInvites) {
        friendsTabWidget_->addOutgoingInviteBox(
            _createOutgoingInviteBox(outgoingInvite.toUserId())
        );
    }

    for (const auto &g : groups) {
        groupsTabWidget_->addGroupBox(_createGroupBox(g.id()));
    }
}

void LobbyWidget::displayFriendsGlobalSearchResults(
    const QVector<QPair<int, QString>> &friendsGlobalSearchResults
) {
    friendsTabWidget_->globalSearchLabel()->setHidden(
        friendsGlobalSearchResults.isEmpty()
    );

    for (const auto &[userId, userLogin] : friendsGlobalSearchResults) {
        friendsTabWidget_->addGlobalSearchFriendBox(
            _createGlobalSearchFriendBox(userId, userLogin)
        );
    }
}

void LobbyWidget::displayGroupsGlobalSearchResults(
    const QVector<QPair<int, QString>> &groupsGlobalSearchResults
) {
    groupsTabWidget_->globalSearchLabel()->setHidden(
        groupsGlobalSearchResults.isEmpty()
    );

    for (const auto &[groupId, groupName] : groupsGlobalSearchResults) {
        groupsTabWidget_->addGlobalSearchGroupBox(
            _createGlobalSearchGroupBox(groupId, groupName)
        );
    }
}

void LobbyWidget::displayMessageToFriend(int userId, const QString &textMessage) {
    auto userLogin{core::User::user().friends()[userId].login()};
    auto messageBox{new box::MessageBox{
        userId, userLogin, textMessage
    }};
    auto friendChatDialog{_createOrReturnFriendChatDialog(userId, userLogin)};
    friendChatDialog->addMessageBox(messageBox);
}

void LobbyWidget::displayIncomingInvite(int userId) {
    friendsTabWidget_->incomingInvitesLabel()->setHidden(false);
    friendsTabWidget_->addIncomingInviteBox(_createIncomingInviteBox(userId));
}

void LobbyWidget::displayOutgoingInvite(int userId) {
    friendsTabWidget_->outgoingInvitesLabel()->setHidden(false);
    friendsTabWidget_->addOutgoingInviteBox(_createOutgoingInviteBox(userId));
}

void LobbyWidget::displayFriend(int userId) {
    friendsTabWidget_->removeOutgoingInviteBox(userId);
    friendsTabWidget_->addFriendBox(_createFriendBox(userId));
    friendsTabWidget_->outgoingInvitesLabel()->setHidden(
        friendsTabWidget_->outgoingInviteBoxesCount() == 0
    );
}

void LobbyWidget::displayMessageToGroup(
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

void LobbyWidget::displayAcceptedFriend(int userId) {
    friendsTabWidget_->removeIncomingInviteBox(userId);
    friendsTabWidget_->addFriendBox(_createFriendBox(userId));
    friendsTabWidget_->incomingInvitesLabel()->setHidden(
        friendsTabWidget_->incomingInviteBoxesCount() == 0
    );
}

void LobbyWidget::stopDisplayOutgoingInvite(int toUserId) {
    friendsTabWidget_->removeOutgoingInviteBox(toUserId);
    friendsTabWidget_->outgoingInvitesLabel()->setHidden(
        friendsTabWidget_->outgoingInviteBoxesCount() == 0
    );
}

void LobbyWidget::stopDisplayIncomingInvite(int fromUserId) {
    friendsTabWidget_->removeIncomingInviteBox(fromUserId);
    friendsTabWidget_->incomingInvitesLabel()->setHidden(
        friendsTabWidget_->incomingInviteBoxesCount() == 0
    );
}

void LobbyWidget::_setTabWidgets() {
    auto friendsTabScrollArea{new QScrollArea};
    auto groupsTabScrollArea {new QScrollArea};

    friendsTabScrollArea->setWidgetResizable(true);
    groupsTabScrollArea->setWidgetResizable(true);

    friendsTabWidget_->globalSearchLabel()->setHidden(true);
    groupsTabWidget_->globalSearchLabel()->setHidden(true);

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
        if (ui->tabWidget->currentIndex() == 0) {
            emit needToFriendsGlobalSearch(ui->searchLineEdit->text());
        } else {
            emit needToGroupsGlobalSearch(ui->searchLineEdit->text());
        }
    });
}

void LobbyWidget::on_searchLineEdit_textEdited(
    const QString &prefixText
) {
    if (ui->tabWidget->currentIndex() == 0) {
        _doFriendsSearch(prefixText);
    } else {
        _doGroupSearch(prefixText);
    }

    if (globalSearchTimer_->isActive()) {
        globalSearchTimer_->stop();
    }

    if (!prefixText.isEmpty()) {
        globalSearchTimer_->start(4500);
    }
}

void LobbyWidget::_displayGroupChatDialog(int groupId) {
    auto groupChatDialog{_createOrReturnGroupChatDialog(
        groupId,
        core::User::user().groups()[groupId].name()
    )};
    groupChatDialog->show();
}

void LobbyWidget::_displayFriendChatDialog(int userId) {
    auto friendChatDialog{_createOrReturnFriendChatDialog(
        userId,
        core::User::user().friends()[userId].login()
    )};
    friendChatDialog->show();
}

void LobbyWidget::_displayGlobalSearchGroupChatDialog(int groupId, const QString &groupNameText) {
    auto groupChatDialog{_createOrReturnGroupChatDialog(groupId, groupNameText)};
    groupChatDialog->show();
}

void LobbyWidget::_doFriendsSearch(const QString &loginPrefixText) {
    auto count{friendsTabWidget_->friendBoxesCount()};

    bool outgoingLabelHidden{true};
    bool incomingLabelHidden{true};

    for (int i{0}; i < count; ++i) {
        auto friendBox      {friendsTabWidget_->friendBoxAt(i)};
        auto friendLoginText{friendBox->friendLoginLabel()->text()};
        auto startsWith     {friendLoginText.startsWith(loginPrefixText)};

        friendBox->setHidden(!startsWith);
    }

    count = friendsTabWidget_->incomingInviteBoxesCount();

    for (int i{0}; i < count; ++i) {
        auto incomingInviteBox{friendsTabWidget_->incomingInviteBoxAt(i)};
        auto fromUserLoginText{incomingInviteBox->fromUserLoginLabel()->text()};
        auto startsWith       {fromUserLoginText.startsWith(loginPrefixText)};

        incomingInviteBox->setHidden(!startsWith);

        if (!incomingInviteBox->isHidden() && incomingLabelHidden) {
            incomingLabelHidden = false;
        }
    }

    count = friendsTabWidget_->outgoingInviteBoxesCount();

    for (int i{0}; i < count; ++i) {
        auto outgoingInviteBox{friendsTabWidget_->outgoingInviteBoxAt(i)};
        auto toUserLoginText  {outgoingInviteBox->toUserLoginLabel()->text()};
        auto startsWith       {toUserLoginText.startsWith(loginPrefixText)};

        outgoingInviteBox->setHidden(!startsWith);

        if (!outgoingInviteBox->isHidden() && outgoingLabelHidden) {
            outgoingLabelHidden = false;
        }
    }

    friendsTabWidget_->incomingInvitesLabel()->setHidden(incomingLabelHidden);
    friendsTabWidget_->outgoingInvitesLabel()->setHidden(outgoingLabelHidden);

    friendsTabWidget_->clearGlobalSearchFriendBoxes();
    friendsTabWidget_->globalSearchLabel()->setHidden(true);
}

void LobbyWidget::_doGroupSearch(const QString &groupNamePrefixText) {
    auto count{groupsTabWidget_->groupBoxesCount()};

    for (int i{0}; i < count; ++i) {
        auto groupBox     {groupsTabWidget_->groupBoxAt(i)};
        auto groupNameText{groupBox->groupNameLabel()->text()};
        auto startsWith   {groupNameText.startsWith(groupNamePrefixText)};

        groupBox->setHidden(!startsWith);
    }

    groupsTabWidget_->clearGlobalSearchGroupBoxes();
    groupsTabWidget_->globalSearchLabel()->setHidden(true);
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

box::FriendBox *LobbyWidget::_createFriendBox(int friendId) {
    auto friendBox{new box::FriendBox{friendId}};
    connect(
        friendBox,
        SIGNAL(friendBoxClicked(int)),
        this,
        SLOT(_displayFriendChatDialog(int))
    );
    return friendBox;
}

box::IncomingInviteBox *LobbyWidget::_createIncomingInviteBox(int fromUserId) {
    auto incomingInviteBox{new box::IncomingInviteBox{fromUserId}};
    connect(incomingInviteBox, &box::IncomingInviteBox::inviteAccepted, this, [this](int fromUserId) {
        emit needToAcceptIncomingInvite(fromUserId);
    });
    connect(incomingInviteBox, &box::IncomingInviteBox::inviteRejected, this, [this](int fromUserId) {
        emit needToRejectIncomingInvite(fromUserId);
    });
    return incomingInviteBox;
}

box::OutgoingInviteBox *LobbyWidget::_createOutgoingInviteBox(int toUserId) {
    auto outgoingInviteBox{new box::OutgoingInviteBox{toUserId}};
    connect(outgoingInviteBox, &box::OutgoingInviteBox::inviteCanceled, this, [this](int toUserId) {
        emit needToCancelOutgoingInvite(toUserId);
    });
    return outgoingInviteBox;
}

box::GlobalSearchFriendBox *LobbyWidget::_createGlobalSearchFriendBox(
    int            userId,
    const QString &userLoginText
) {
    auto globalSearchFriendBox{new box::GlobalSearchFriendBox{userId, userLoginText}};
    connect(globalSearchFriendBox, &box::GlobalSearchFriendBox::userNeedToBeAdded, this, [this](int userId, const QString &userLogin) {
        emit needToAddUser(userId, userLogin);
    });
    return globalSearchFriendBox;
}

void LobbyWidget::on_tabWidget_currentChanged(int index) {
    if (globalSearchTimer_->isActive()) {
        globalSearchTimer_->stop();
    }
    auto searchText{ui->searchLineEdit->text()};
    if (!searchText.isEmpty()) {
        on_searchLineEdit_textEdited(searchText);
    }
}

dialog::FriendChatDialog *LobbyWidget::_createOrReturnFriendChatDialog(
    int            groupId,
    const QString &groupName
) {
    auto found{friendChatDialogs_.find(groupId)};

    if (found != friendChatDialogs_.end()) {
        return *found;
    }

    auto friendChatDialog{new dialog::FriendChatDialog{groupId, groupName, this}};

    connect(
        friendChatDialog,
        &dialog::FriendChatDialog::textMessageEntered,
        this,
        [this](int groupId, const QString &textMessage) {
            emit needToSendToFriendTextMessage(groupId, textMessage);
        }
    );

    return (friendChatDialogs_[groupId] = friendChatDialog);
}

} // widget
