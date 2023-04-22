#ifndef AUTHWIDGET_H
#define AUTHWIDGET_H

#include <QWidget>

namespace Ui {
class AuthWidget;
}

namespace gui::widget {

class AuthWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AuthWidget(QWidget *parent = nullptr);
    ~AuthWidget();

signals:
    void userAuthorized(const QString &login, const QString &password);
    void userRegistered(const QString &login, const QString &password);

private slots:
    void on_loginPushButton_clicked();
    void on_registerPushButton_clicked();

private:
    Ui::AuthWidget *ui;
};

} // widget

#endif // AUTHWIDGET_H
