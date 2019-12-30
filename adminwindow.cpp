#include "adminwindow.h"
#include "ui_adminwindow.h"

#include<string>
#include<map>

namespace QCMpp {

AdminWindow::AdminWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWindow),
    requestUsers(false)
{
    ui->setupUi(this);
    ui->button_promote->hide();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::updateMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs){
    this->mcqs = &mcqs;
    for(auto & mcq : mcqs){
           this->ui->combobox_mcqs->addItem(QString::fromStdString(mcq->getTitle()));
    }
}

void QCMpp::AdminWindow::on_button_createmcq_clicked()
{
    emit onCreateMCQ();
}

void AdminWindow::on_combobox_mcqs_currentIndexChanged(int index)
{
    if(index < 0) return; //Prevents crash when clearing
    //Preparing the table
    this->ui->table->clearContents();

    insert_grades(*(*mcqs)[index]->getGrades());
}

void AdminWindow::insert_grades(const std::map<const std::string, const int> & u_g)
{
    int row = 0;
    this->ui->table->setRowCount(u_g.size());
    for(auto it(u_g.begin()); it!=u_g.end(); ++it){
        this->ui->table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(it->first)));
        this->ui->table->setItem(row, 1, new QTableWidgetItem(QString::number(it->second)));
        ++row;
    }
}

void AdminWindow::on_button_users_clicked()
{
    //Preparing Window and table
    ui->button_users->hide();
    ui->button_createmcq->hide();
    ui->button_promote->show();
    ui->button_tomcqs->show();
    this->ui->table->clearContents();
    QList<QString> labels = {"User","Rank"};
    this->ui->table->setHorizontalHeaderLabels(labels);

    emit onRequestUsers();
}

void AdminWindow::updateUsers(const std::map<std::string, std::unique_ptr<User>> & users)
{
    this->ui->table->setRowCount(users.size());
    int i =0;
    for (auto it = users.begin(); it != users.end(); ++it) {
        ui->table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(it->first)));
        ui->table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString((it->second->isAdmin()) ? "Admin" : "Student")));
        ++i;
    }

}

void QCMpp::AdminWindow::on_button_promote_clicked()
{
    QList<QTableWidgetItem *> row = ui->table->selectedItems();
    row[1]->setText("Admin");
    std::string username = row[0]->text().toStdString();
    emit onPromoteUser(username);
}

void QCMpp::AdminWindow::on_button_tomcqs_clicked()
{
    ui->button_promote->hide();
    ui->button_tomcqs->hide();
    ui->button_users->show();
    ui->button_createmcq->show();
    ui->table->clearContents();
    QList<QString> labels = {"User","Grade"};
    ui->table->setHorizontalHeaderLabels(labels);
}


void QCMpp::AdminWindow::on_button_signout_clicked()
{
    emit onSignOutSubmit();
}

void QCMpp::AdminWindow::showWindow(User * const user){
    setWindowTitle(QString::fromStdString("Logged in as "+ user->getUsername()+" (Admin)"));
    this->ui->label_username->setText(QString::fromStdString(user->getUsername()));
    show();
    emit onRequestMCQs();
}

void QCMpp::AdminWindow::hideWindow(){
    ui->combobox_mcqs->clear();
    ui->table->clearContents();
    hide();
}

}

