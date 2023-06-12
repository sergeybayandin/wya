/********************************************************************************
** Form generated from reading UI file 'messagebox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEBOX_H
#define UI_MESSAGEBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MessageBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *userLoginLabel;
    QLabel *messageLabel;

    void setupUi(QGroupBox *MessageBox)
    {
        if (MessageBox->objectName().isEmpty())
            MessageBox->setObjectName(QString::fromUtf8("MessageBox"));
        MessageBox->resize(400, 300);
        verticalLayout = new QVBoxLayout(MessageBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        userLoginLabel = new QLabel(MessageBox);
        userLoginLabel->setObjectName(QString::fromUtf8("userLoginLabel"));

        verticalLayout->addWidget(userLoginLabel);

        messageLabel = new QLabel(MessageBox);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));

        verticalLayout->addWidget(messageLabel);


        retranslateUi(MessageBox);

        QMetaObject::connectSlotsByName(MessageBox);
    } // setupUi

    void retranslateUi(QGroupBox *MessageBox)
    {
        MessageBox->setWindowTitle(QCoreApplication::translate("MessageBox", "GroupBox", nullptr));
        userLoginLabel->setText(QString());
        messageLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MessageBox: public Ui_MessageBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEBOX_H
