/********************************************************************************
** Form generated from reading UI file 'groupchatdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATDIALOG_H
#define UI_GROUPCHATDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupChatDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *joinPage;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *joinPushButton;
    QSpacerItem *horizontalSpacer_2;
    QWidget *chatPage;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *messageBoxesVerticalLayout;
    QLineEdit *messageLineEdit;

    void setupUi(QDialog *GroupChatDialog)
    {
        if (GroupChatDialog->objectName().isEmpty())
            GroupChatDialog->setObjectName(QString::fromUtf8("GroupChatDialog"));
        GroupChatDialog->resize(456, 374);
        verticalLayout_2 = new QVBoxLayout(GroupChatDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        stackedWidget = new QStackedWidget(GroupChatDialog);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        joinPage = new QWidget();
        joinPage->setObjectName(QString::fromUtf8("joinPage"));
        verticalLayout_3 = new QVBoxLayout(joinPage);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        joinPushButton = new QPushButton(joinPage);
        joinPushButton->setObjectName(QString::fromUtf8("joinPushButton"));

        horizontalLayout->addWidget(joinPushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        stackedWidget->addWidget(joinPage);
        chatPage = new QWidget();
        chatPage->setObjectName(QString::fromUtf8("chatPage"));
        verticalLayout = new QVBoxLayout(chatPage);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scrollArea = new QScrollArea(chatPage);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 420, 307));
        messageBoxesVerticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        messageBoxesVerticalLayout->setObjectName(QString::fromUtf8("messageBoxesVerticalLayout"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        messageLineEdit = new QLineEdit(chatPage);
        messageLineEdit->setObjectName(QString::fromUtf8("messageLineEdit"));

        verticalLayout->addWidget(messageLineEdit);

        stackedWidget->addWidget(chatPage);

        verticalLayout_2->addWidget(stackedWidget);


        retranslateUi(GroupChatDialog);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(GroupChatDialog);
    } // setupUi

    void retranslateUi(QDialog *GroupChatDialog)
    {
        GroupChatDialog->setWindowTitle(QCoreApplication::translate("GroupChatDialog", "Dialog", nullptr));
        joinPushButton->setText(QCoreApplication::translate("GroupChatDialog", "\320\237\321\200\320\270\321\201\320\276\320\265\320\264\320\270\320\275\320\270\321\202\321\214\321\201\321\217", nullptr));
        messageLineEdit->setPlaceholderText(QCoreApplication::translate("GroupChatDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupChatDialog: public Ui_GroupChatDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATDIALOG_H
