#include "loginwindow.h"
#include "ui_loginwindow.h"

#include <iostream>
#include <QString>
#include "encrypter.h"

namespace QCMpp {

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::show(bool sign_up_only)
{
    reset();
    if(sign_up_only){
        this->ui->button_signin->hide();
    }
    QWidget::show();
}

void QCMpp::LoginWindow::on_button_signin_clicked()
{
    Encrypter e;
    string username = this->ui->edit_username->text().toStdString();
    string password = this->ui->edit_password->text().toStdString();
    e.encrypt(password);

    emit onSignInSubmit(username, password);
}

void QCMpp::LoginWindow::on_button_signup_clicked()
{
    Encrypter e;
    string username = this->ui->edit_username->text().toStdString();
    string password = this->ui->edit_password->text().toStdString();
    e.encrypt(password);

    emit onSignUpSubmit(username, password);
}

void LoginWindow::reset() const
{
    this->ui->edit_password->clear();
    this->ui->edit_username->clear();
    this->ui->label_message->clear();
    this->ui->button_signin->show();
}

void LoginWindow::setMessage(const string &message)
{
    this->ui->label_message->setText(QString::fromStdString(message));
}

}
