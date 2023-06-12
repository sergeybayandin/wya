/********************************************************************************
** Form generated from reading UI file 'globalsearchgroupbox.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GLOBALSEARCHGROUPBOX_H
#define UI_GLOBALSEARCHGROUPBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GlobalSearchGroupBox
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *groupNameLabel;

    void setupUi(QGroupBox *GlobalSearchGroupBox)
    {
        if (GlobalSearchGroupBox->objectName().isEmpty())
            GlobalSearchGroupBox->setObjectName(QString::fromUtf8("GlobalSearchGroupBox"));
        GlobalSearchGroupBox->resize(400, 300);
        verticalLayout = new QVBoxLayout(GlobalSearchGroupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupNameLabel = new QLabel(GlobalSearchGroupBox);
        groupNameLabel->setObjectName(QString::fromUtf8("groupNameLabel"));
        groupNameLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(groupNameLabel);


        retranslateUi(GlobalSearchGroupBox);

        QMetaObject::connectSlotsByName(GlobalSearchGroupBox);
    } // setupUi

    void retranslateUi(QGroupBox *GlobalSearchGroupBox)
    {
        GlobalSearchGroupBox->setWindowTitle(QCoreApplication::translate("GlobalSearchGroupBox", "GroupBox", nullptr));
        groupNameLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GlobalSearchGroupBox: public Ui_GlobalSearchGroupBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GLOBALSEARCHGROUPBOX_H
