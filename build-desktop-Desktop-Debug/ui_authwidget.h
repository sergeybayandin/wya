/********************************************************************************
** Form generated from reading UI file 'authwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHWIDGET_H
#define UI_AUTHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *loginPushButton;
    QPushButton *registerPushButton;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *AuthWidget)
    {
        if (AuthWidget->objectName().isEmpty())
            AuthWidget->setObjectName(QString::fromUtf8("AuthWidget"));
        AuthWidget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(AuthWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 86, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        loginLineEdit = new QLineEdit(AuthWidget);
        loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));

        verticalLayout->addWidget(loginLineEdit);

        passwordLineEdit = new QLineEdit(AuthWidget);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setEchoMode(QLineEdit::Password);

        verticalLayout->addWidget(passwordLineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        loginPushButton = new QPushButton(AuthWidget);
        loginPushButton->setObjectName(QString::fromUtf8("loginPushButton"));

        horizontalLayout->addWidget(loginPushButton);

        registerPushButton = new QPushButton(AuthWidget);
        registerPushButton->setObjectName(QString::fromUtf8("registerPushButton"));

        horizontalLayout->addWidget(registerPushButton);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 85, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);


        retranslateUi(AuthWidget);

        QMetaObject::connectSlotsByName(AuthWidget);
    } // setupUi

    void retranslateUi(QWidget *AuthWidget)
    {
        AuthWidget->setWindowTitle(QCoreApplication::translate("AuthWidget", "Form", nullptr));
        loginLineEdit->setPlaceholderText(QCoreApplication::translate("AuthWidget", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        passwordLineEdit->setPlaceholderText(QCoreApplication::translate("AuthWidget", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        loginPushButton->setText(QCoreApplication::translate("AuthWidget", "\320\222\320\276\320\271\321\202\320\270", nullptr));
#if QT_CONFIG(shortcut)
        loginPushButton->setShortcut(QCoreApplication::translate("AuthWidget", "Return", nullptr));
#endif // QT_CONFIG(shortcut)
        registerPushButton->setText(QCoreApplication::translate("AuthWidget", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214\321\201\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AuthWidget: public Ui_AuthWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHWIDGET_H
