#include "adminwindow.h"
#include "ui_adminwindow.h"

#include<string>
#include<map>

namespace QCMpp {

AdminWindow::AdminWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
    ui->hide_users->hide();
    emit onRequestMCQs();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}



void AdminWindow::updateMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs){
    this->mcqs = &mcqs;
    QStringList titles;
    for(auto & mcq : mcqs){
       //this->ui->mcq_alreadyCreated->addItem(QString::fromStdString(mcq->getTitle()));
    }
}



//void AdminWindow::on_create_mcq_clicked()
//{

//}




//void AdminWindow::on_hide_users_clicked()
//{
//    ui->hide_users->hide();
//    ui->mcq_alreadyCreated->show();
//    ui->create_mcq->show();
//    ui->table->clearContents();
//    //insert_grades()

//}

void AdminWindow::on_mcq_alreadyCreated_currentIndexChanged(int index)
{
    //Preparing the table
    this->ui->table->clearContents();
    this->ui->table->removeColumn(1);
    this->ui->table->insertColumn(1);
    QList<QString> labels = {"User","Grade"};
    this->ui->table->setHorizontalHeaderLabels(labels);

    //insert_grades((*mcqs)[index]->getGrades());
}

void AdminWindow::insert_grades(std::map<const std::string,const int> u_g)
{
    int row = 1;
    for(std::map<const std::string,const int>::iterator it(u_g.begin());it!=u_g.end();++it){
        if (row > this->ui->table->rowCount()){
            this->ui->table->setRowCount(this->ui->table->rowCount()+1);
        }
        this->ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(it->first)));
        this->ui->table->setItem(row,0,new QTableWidgetItem(it->second));
        ++row;
    }
    this->ui->table->setRowCount(row);
}

void AdminWindow::on_users_clicked()
{
    //Preparing Window and table
    ui->users->hide();
    ui->create_mcq->hide();
    ui->hide_users->show();
    ui->create_mcq->hide();
    this->ui->table->clearContents();
    this->ui->table->removeColumn(1);
    this->ui->table->insertColumn(1);
    QList<QString> labels = {"User","Rank"};
    this->ui->table->setHorizontalHeaderLabels(labels);

    emit onRequestUsers();

}

void AdminWindow::updateUsers(std::map<std::string, std::unique_ptr<User> > users)
{
    std::map<const std::string, bool> u_r;
    for (std::map<std::string, std::unique_ptr<User>>::iterator it(users.begin()); it != users.end(); ++it) {
        u_r.insert({it->first, it->second->isAdmin()});
    }
    insert_users(u_r);
}

void AdminWindow::insert_users(std::map<const std::string,bool> u_r)
{
    int row = 1;
    for(std::map<const std::string,bool>::iterator it(u_r.begin()); it != u_r.end(); ++it){
        if (row > this->ui->table->rowCount()){
            this->ui->table->insertRow(row);
        }
        this->ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(it->first)));
        if (it->second == true){
            this->ui->table->setItem(row,0,new QTableWidgetItem("Admin"));
        }else{
            this->ui->table->setItem(row,0,new QTableWidgetItem("Student"));
        }
        ++row;
    }
    this->ui->table->setRowCount(row);
}


void QCMpp::AdminWindow::on_sign_out_clicked()
{
    emit onSignOutSubmit();
}


}


void QCMpp::AdminWindow::on_promote_clicked()
{
    QList<QTableWidgetItem *> row = ui->table->selectedItems();
    std::string username = row[0]->text().toStdString();
    emit onPromoteUser(username);
}
