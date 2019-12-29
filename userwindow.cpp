#include "userwindow.h"
#include "ui_userwindow.h"

#include <iostream>

namespace QCMpp {

UserWindow::UserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow), currentUser(nullptr)
{
    ui->setupUi(this);

    QStringList horzHeaders;
    horzHeaders << "MCQ" << "Grade";
    ui->table_mcqs->setHorizontalHeaderLabels(horzHeaders);

    reset();
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::showWindow(User * const user)
{
    if(user->isAdmin()) return;
    currentUser = user;
    setWindowTitle(QString::fromStdString("Logged In as " + currentUser->getUsername() + " (Student)"));
    this->ui->label_username->setText(QString::fromStdString(currentUser->getUsername()));
    emit onRequestMCQs();
    show();
}

void UserWindow::hideWindow()
{
    reset();
    hide();
}

void UserWindow::updateMCQs(const std::vector<std::unique_ptr<MCQ> > &mcqs)
{
    ui->table_mcqs->clearContents();

}

void UserWindow::reset()
{
    currentUser = nullptr;
    ui->label_username->clear();
    ui->table_mcqs->clearContents();
}

void QCMpp::UserWindow::on_button_signout_clicked()
{
    emit onSignOutSubmit();
}

}
