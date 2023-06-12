/********************************************************************************
** Form generated from reading UI file 'friendstabwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRIENDSTABWIDGET_H
#define UI_FRIENDSTABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FriendsTabWidget
{
public:

    void setupUi(QWidget *FriendsTabWidget)
    {
        if (FriendsTabWidget->objectName().isEmpty())
            FriendsTabWidget->setObjectName(QString::fromUtf8("FriendsTabWidget"));
        FriendsTabWidget->resize(400, 300);

        retranslateUi(FriendsTabWidget);

        QMetaObject::connectSlotsByName(FriendsTabWidget);
    } // setupUi

    void retranslateUi(QWidget *FriendsTabWidget)
    {
        FriendsTabWidget->setWindowTitle(QCoreApplication::translate("FriendsTabWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FriendsTabWidget: public Ui_FriendsTabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRIENDSTABWIDGET_H
