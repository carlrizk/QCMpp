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
    this->ui->edit_password->clear();
    this->ui->edit_username->clear();
    this->ui->label_message->clear();
    if(sign_up_only){
        this->ui->button_signin->hide();
    }else{
        this->ui->button_signin->show();
    }
    QWidget::show();
}

void QCMpp::LoginWindow::on_button_signin_clicked()
{
    submit();
}

void QCMpp::LoginWindow::on_button_signup_clicked()
{
    submit(true);
}

void LoginWindow::setMessage(const string &message)
{
    this->ui->label_message->setText(QString::fromStdString(message));
}

void LoginWindow::submit(bool sign_up)
{
    Encrypter e;
    string username = this->ui->edit_username->text().toStdString();
    string password = this->ui->edit_password->text().toStdString();
    e.encrypt(password);

    emit onSubmit(username, password, sign_up);
}

}
