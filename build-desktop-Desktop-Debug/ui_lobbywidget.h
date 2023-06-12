/********************************************************************************
** Form generated from reading UI file 'lobbywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBYWIDGET_H
#define UI_LOBBYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LobbyWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLineEdit *searchLineEdit;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *LobbyWidget)
    {
        if (LobbyWidget->objectName().isEmpty())
            LobbyWidget->setObjectName(QString::fromUtf8("LobbyWidget"));
        LobbyWidget->resize(445, 379);
        verticalLayout_2 = new QVBoxLayout(LobbyWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchLineEdit = new QLineEdit(LobbyWidget);
        searchLineEdit->setObjectName(QString::fromUtf8("searchLineEdit"));
        searchLineEdit->setFocusPolicy(Qt::ClickFocus);

        verticalLayout->addWidget(searchLineEdit);

        verticalSpacer = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout->addItem(verticalSpacer);

        tabWidget = new QTabWidget(LobbyWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);

        verticalLayout->addWidget(tabWidget);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(LobbyWidget);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(LobbyWidget);
    } // setupUi

    void retranslateUi(QWidget *LobbyWidget)
    {
        LobbyWidget->setWindowTitle(QCoreApplication::translate("LobbyWidget", "Form", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("LobbyWidget", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LobbyWidget: public Ui_LobbyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBYWIDGET_H
