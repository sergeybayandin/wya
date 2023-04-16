#ifndef WYAWIDGET_H
#define WYAWIDGET_H

#include <QWidget>

namespace Ui {
class wyaWidget;
}

class WyaWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WyaWidget(QWidget *parent = nullptr);
    ~WyaWidget();

private slots:
    void on_loginPushButton_clicked();
    void on_registerPushButton_clicked();

private:
    Ui::wyaWidget *ui;
};

#endif // WYAWIDGET_H
