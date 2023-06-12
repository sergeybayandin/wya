/********************************************************************************
** Form generated from reading UI file 'wyawidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WYAWIDGET_H
#define UI_WYAWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WyaWidget
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;

    void setupUi(QWidget *WyaWidget)
    {
        if (WyaWidget->objectName().isEmpty())
            WyaWidget->setObjectName(QString::fromUtf8("WyaWidget"));
        WyaWidget->resize(600, 600);
        WyaWidget->setMinimumSize(QSize(600, 600));
        WyaWidget->setMaximumSize(QSize(600, 600));
        gridLayout = new QGridLayout(WyaWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(WyaWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);


        retranslateUi(WyaWidget);

        QMetaObject::connectSlotsByName(WyaWidget);
    } // setupUi

    void retranslateUi(QWidget *WyaWidget)
    {
        WyaWidget->setWindowTitle(QCoreApplication::translate("WyaWidget", "Wya", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WyaWidget: public Ui_WyaWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WYAWIDGET_H
