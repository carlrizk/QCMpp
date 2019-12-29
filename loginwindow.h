#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

#include "string"

namespace Ui {
class LoginWindow;
}

namespace QCMpp{

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();


signals:
    void onSignInSubmit(const std::string & username, const std::string & password);
    void onSignUpSubmit(const std::string & username, const std::string & password);

public slots:
    void show(bool sign_up_only = false);
    void setMessage(const std::string & message);

private slots:
    void on_button_signin_clicked();
    void on_button_signup_clicked();

private:
    Ui::LoginWindow *ui;

    void reset() const;
};
}
#endif // LOGINWINDOW_H
