#include "userwindow.h"
#include "ui_userwindow.h"

namespace QCMpp {

UserWindow::UserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);

    ui->table_mcqs->setHorizontalHeaderItem(0, new QTableWidgetItem("MCQ"));
    ui->table_mcqs->setHorizontalHeaderItem(1, new QTableWidgetItem("Grade"));
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::showWindow(User * const user)
{
    if(user->isAdmin()) return;
    setWindowTitle(QString::fromStdString("Logged In as " + user->getUsername() + " (Student)"));
    this->ui->label_username->setText(QString::fromStdString(user->getUsername()));
    show();
}

void UserWindow::hideWindow()
{
    reset();
    hide();
}

void UserWindow::reset() const
{
    ui->table_mcqs->clear();
}

void QCMpp::UserWindow::on_button_signout_clicked()
{
    emit onSignOutSubmit();
}

}
