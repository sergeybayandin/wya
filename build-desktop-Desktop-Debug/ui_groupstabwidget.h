/********************************************************************************
** Form generated from reading UI file 'groupstabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSTABWIDGET_H
#define UI_GROUPSTABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupsTabWidget
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *groupBoxesVerticalLayout;
    QLabel *globalSearchLabel;
    QVBoxLayout *globalSearchGroupBoxesVerticalLayout;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *GroupsTabWidget)
    {
        if (GroupsTabWidget->objectName().isEmpty())
            GroupsTabWidget->setObjectName(QString::fromUtf8("GroupsTabWidget"));
        GroupsTabWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(GroupsTabWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBoxesVerticalLayout = new QVBoxLayout();
        groupBoxesVerticalLayout->setObjectName(QString::fromUtf8("groupBoxesVerticalLayout"));

        verticalLayout->addLayout(groupBoxesVerticalLayout);

        globalSearchLabel = new QLabel(GroupsTabWidget);
        globalSearchLabel->setObjectName(QString::fromUtf8("globalSearchLabel"));

        verticalLayout->addWidget(globalSearchLabel);

        globalSearchGroupBoxesVerticalLayout = new QVBoxLayout();
        globalSearchGroupBoxesVerticalLayout->setObjectName(QString::fromUtf8("globalSearchGroupBoxesVerticalLayout"));

        verticalLayout->addLayout(globalSearchGroupBoxesVerticalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(GroupsTabWidget);

        QMetaObject::connectSlotsByName(GroupsTabWidget);
    } // setupUi

    void retranslateUi(QWidget *GroupsTabWidget)
    {
        GroupsTabWidget->setWindowTitle(QCoreApplication::translate("GroupsTabWidget", "Form", nullptr));
        globalSearchLabel->setText(QCoreApplication::translate("GroupsTabWidget", "\320\223\320\273\320\276\320\261\320\260\320\273\321\214\320\275\321\213\320\271 \320\277\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupsTabWidget: public Ui_GroupsTabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSTABWIDGET_H
