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
    ui->button_promote->hide();
//    emit onRequestMCQs();
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

void AdminWindow::updateMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs){
    this->mcqs = &mcqs;
//    QStringList titles;
//    for(auto & mcq : mcqs){
//       this->ui->combobox_mcqs->addItem(QString::fromStdString(mcq->getTitle()));
//    }
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
    ui->button_promote->hide();
    ui->button_users->show();
    this->ui->table->clearContents();
//    this->ui->table->removeColumn(1);
//    this->ui->table->insertColumn(1);
    QList<QString> labels = {"User","Grade"};
    this->ui->table->setHorizontalHeaderLabels(labels);

    insert_grades(*(*mcqs)[index]->getGrades());
}

void AdminWindow::insert_grades(const std::map<const std::string, const int> & u_g)
{
    int row = 0;
    this->ui->table->setRowCount(u_g.size());
//    for(std::map<const std::string,const int>::iterator it(u_g.begin());it!=u_g.end();++it){
//        this->ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(it->first)));
//        this->ui->table->setItem(row,1,new QTableWidgetItem(it->second));
//        ++row;
//    }
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
    ui->button_promote->show();
    this->ui->table->clearContents();
//    this->ui->table->removeColumn(1);
//    this->ui->table->insertColumn(1);
    QList<QString> labels = {"User","Rank"};
    this->ui->table->setHorizontalHeaderLabels(labels);

    emit onRequestUsers();
}

void AdminWindow::updateUsers(const std::map<std::string, std::unique_ptr<User>> & users)
{
//    std::map<const std::string, bool> u_r;
//    for (auto it = users.begin(); it != users.end(); ++it) {
//        u_r.insert({it->first, it->second->isAdmin()});
//    }
    //insert_users(u_r);
    this->ui->table->setRowCount(users.size());
    int i =0;
    for (auto it = users.begin(); it != users.end(); ++it) {
        ui->table->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(it->first)));
        ui->table->setItem(i, 1, new QTableWidgetItem(QString::fromStdString((it->second->isAdmin()) ? "Admin" : "Student")));
        ++i;
    }

}

//void AdminWindow::insert_users(std::map<const std::string,bool> u_r)
//{
//    int row = 0;
//    for(std::map<const std::string,bool>::iterator it(u_r.begin()); it != u_r.end(); ++it){
//        if (row > this->ui->table->rowCount()){
//            this->ui->table->insertRow(row);
//        }
//        this->ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(it->first)));
//        if (it->second == true){
//            this->ui->table->setItem(row,1,new QTableWidgetItem("Admin"));
//        }else{
//            this->ui->table->setItem(row,1,new QTableWidgetItem("Student"));
//        }
//        ++row;
//    }
//    this->ui->table->setRowCount(row);
//}

void QCMpp::AdminWindow::on_button_promote_clicked()
{
    QList<QTableWidgetItem *> row = ui->table->selectedItems();
    std::string username = row[0]->text().toStdString();
    emit onPromoteUser(username);
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
