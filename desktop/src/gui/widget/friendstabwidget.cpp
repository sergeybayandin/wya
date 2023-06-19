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

int FriendsTabWidget::friendBoxesCount() const noexcept {
    return ui->friendBoxesVerticalLayout->count();
}


int FriendsTabWidget::incomingInviteBoxesCount() const noexcept {
    return ui->incomingInviteBoxesVerticalLayout->count();
}

int FriendsTabWidget::outgoingInviteBoxesCount() const noexcept {
    return ui->outgoingInviteBoxesVerticalLayout->count();
}

box::FriendBox *FriendsTabWidget::friendBoxAt(int i) const noexcept {
    return static_cast<box::FriendBox *>(
        ui->friendBoxesVerticalLayout->itemAt(i)->widget()
    );
}

box::IncomingInviteBox *FriendsTabWidget::incomingInviteBoxAt(int i) const noexcept {
    return static_cast<box::IncomingInviteBox *>(
        ui->incomingInviteBoxesVerticalLayout->itemAt(i)->widget()
    );
}

box::OutgoingInviteBox *FriendsTabWidget::outgoingInviteBoxAt(int i) const noexcept {
    return static_cast<box::OutgoingInviteBox *>(
        ui->outgoingInviteBoxesVerticalLayout->itemAt(i)->widget()
    );
}

QLabel *FriendsTabWidget::incomingInvitesLabel() const noexcept {
    return ui->incomingInvitesLabel;
}

QLabel *FriendsTabWidget::outgoingInvitesLabel() const noexcept {
    return ui->outgoingInvitesLabel;
}

QLabel *FriendsTabWidget::globalSearchLabel() const noexcept {
    return ui->globalSearchLabel;
}

void FriendsTabWidget::clearGlobalSearchFriendBoxes() {
    QLayoutItem *item;
    while ((item = ui->globalSearchFriendBoxesVerticalLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }
    globalSearchFriendBoxes_.clear();
}

void FriendsTabWidget::removeIncomingInviteBox(int userId) {
    auto incomingInviteBox{incomingInviteBoxes_[userId]};

    auto index{ui->incomingInviteBoxesVerticalLayout->indexOf(incomingInviteBox)};
    auto item {ui->incomingInviteBoxesVerticalLayout->takeAt(index)};

    delete item->widget();
    delete item;

    incomingInviteBoxes_.remove(userId);
}

void FriendsTabWidget::removeOutgoingInviteBox(int userId) {
    auto outgoingInviteBox{outgoingInviteBoxes_[userId]};

    auto index{ui->outgoingInviteBoxesVerticalLayout->indexOf(outgoingInviteBox)};
    auto item {ui->outgoingInviteBoxesVerticalLayout->takeAt(index)};

    delete item->widget();
    delete item;

    outgoingInviteBoxes_.remove(userId);
}

void FriendsTabWidget::addFriendBox(box::FriendBox *friendBox) {
    auto friendId{friendBox->friendId()};
    if (!friendBoxes_.contains(friendId)) {
        ui->friendBoxesVerticalLayout->addWidget(
            friendBoxes_[friendId] = friendBox
        );
    }
}

void FriendsTabWidget::addIncomingInviteBox(box::IncomingInviteBox *incomingInviteBox) {
    auto userId{incomingInviteBox->fromUserId()};
    if (!incomingInviteBoxes_.contains(userId)) {
        ui->incomingInviteBoxesVerticalLayout->addWidget(
            incomingInviteBoxes_[userId] = incomingInviteBox
        );
    }
}

void FriendsTabWidget::addOutgoingInviteBox(box::OutgoingInviteBox *outgoingInviteBox) {
    auto userId{outgoingInviteBox->toUserId()};
    if (!incomingInviteBoxes_.contains(userId)) {
        ui->outgoingInviteBoxesVerticalLayout->addWidget(
           outgoingInviteBoxes_[userId] = outgoingInviteBox
        );
    }
}

void FriendsTabWidget::addGlobalSearchFriendBox(box::GlobalSearchFriendBox *globalSearchFriendBox) {
    auto userId{globalSearchFriendBox->userId()};
    if (!globalSearchFriendBoxes_.contains(userId)) {
        ui->globalSearchFriendBoxesVerticalLayout->addWidget(
            globalSearchFriendBoxes_[userId] = globalSearchFriendBox
        );
    }
}

} // widget
