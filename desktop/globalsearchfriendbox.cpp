#include "globalsearchfriendbox.h"
#include "ui_globalsearchfriendbox.h"

GlobalSearchFriendBox::GlobalSearchFriendBox(QWidget *parent) :
    QGroupBox{parent},
    ui       {new Ui::GlobalSearchFriendBox}
{
    ui->setupUi(this);
}

GlobalSearchFriendBox::~GlobalSearchFriendBox()
{
    delete ui;
}
