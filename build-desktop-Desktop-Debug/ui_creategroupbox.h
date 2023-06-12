/********************************************************************************
** Form generated from reading UI file 'creategroupbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEGROUPBOX_H
#define UI_CREATEGROUPBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateGroupBox
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *createPushButton;
    QLineEdit *groupNameLineEdit;

    void setupUi(QGroupBox *CreateGroupBox)
    {
        if (CreateGroupBox->objectName().isEmpty())
            CreateGroupBox->setObjectName(QString::fromUtf8("CreateGroupBox"));
        CreateGroupBox->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CreateGroupBox->sizePolicy().hasHeightForWidth());
        CreateGroupBox->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(CreateGroupBox);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        createPushButton = new QPushButton(CreateGroupBox);
        createPushButton->setObjectName(QString::fromUtf8("createPushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(createPushButton->sizePolicy().hasHeightForWidth());
        createPushButton->setSizePolicy(sizePolicy1);
        createPushButton->setMinimumSize(QSize(0, 0));
        createPushButton->setMaximumSize(QSize(16777215, 16777215));
        createPushButton->setFlat(true);

        horizontalLayout->addWidget(createPushButton);

        groupNameLineEdit = new QLineEdit(CreateGroupBox);
        groupNameLineEdit->setObjectName(QString::fromUtf8("groupNameLineEdit"));

        horizontalLayout->addWidget(groupNameLineEdit);


        retranslateUi(CreateGroupBox);

        QMetaObject::connectSlotsByName(CreateGroupBox);
    } // setupUi

    void retranslateUi(QGroupBox *CreateGroupBox)
    {
        CreateGroupBox->setWindowTitle(QCoreApplication::translate("CreateGroupBox", "GroupBox", nullptr));
        createPushButton->setText(QCoreApplication::translate("CreateGroupBox", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214", nullptr));
        groupNameLineEdit->setPlaceholderText(QCoreApplication::translate("CreateGroupBox", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateGroupBox: public Ui_CreateGroupBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEGROUPBOX_H
