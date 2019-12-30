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
    ui->table_mcqs->setRowCount(mcqs.size());
    for(size_t i = 0; i < mcqs.size(); ++i){
        ui->table_mcqs->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(mcqs[i]->getTitle())));
        if(mcqs[i]->hasGrade(currentUser->getUsername())){
            ui->table_mcqs->setItem(i, 1, new QTableWidgetItem(QString::number(mcqs[i]->getGrade(currentUser->getUsername()))));
        }
    }
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
