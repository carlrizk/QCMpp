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
    ui->button_changerank->hide();
    ui->table_users->hide();
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

void AdminWindow::on_button_createmcq_clicked()
{
    emit onCreateMCQ();
}

void AdminWindow::on_combobox_mcqs_currentIndexChanged(int index)
{
    if(index < 0) return; //Prevents crash when clearing
    //Preparing the table
    this->ui->table_mcqs->clearContents();

    insert_grades(mcqs->at(index)->getGrades());
}

void AdminWindow::insert_grades(const std::map<const std::string, const int> & u_g)
{
    int row = 0;
    this->ui->table_mcqs->setRowCount(u_g.size());
    for(auto it(u_g.begin()); it!=u_g.end(); ++it){
        setTableCell(ui->table_mcqs,row,0, it->first);
        setTableCell(ui->table_mcqs,row,1,std::to_string(it->second));
        ++row;
    }
}

void AdminWindow::setTableCell(QTableWidget* table,const int row, const int column, const std::string & string)
{
    table->setItem(row, column, new QTableWidgetItem(QString::fromStdString(string)));
    table->item(row,column)->setFlags(table->item(row,column)->flags() & ~Qt::ItemIsEditable);

}

void AdminWindow::on_button_users_clicked()
{
    requestUsers = !requestUsers;
    //Preparing Window and table
    ui->button_users->hide();
    ui->button_createmcq->hide();
    ui->combobox_mcqs->hide();
    ui->table_mcqs->hide();
    ui->button_tomcqs->show();
    ui->table_users->show();
}

void AdminWindow::updateUsers(const std::map<std::string, std::unique_ptr<User>> & users)
{
    this->ui->table_users->setRowCount(users.size());
    int row =0;
    for (auto it = users.begin(); it != users.end(); ++it) {
        setTableCell(ui->table_users,row,0,it->first);
        setTableCell(ui->table_users,row,1,(it->second->isAdmin()) ? "Admin" : "Student");
        ++row;
    }

}

void AdminWindow::on_table_users_itemSelectionChanged()
{
    if(requestUsers){
        ui->button_changerank->show();
        int row = ui->table_users->currentItem()->row();
        std::string username = ui->table_users->item(row,0)->text().toStdString();
        std::string rank = ui->table_users->item(row,1)->text().toStdString();
        if(username != user->getUsername()){
            ui->button_changerank->setEnabled(true);
            if(rank == "Admin"){
                ui->button_changerank->setText("Demote");
            }else{
                ui->button_changerank->setText("Promote");
            }
        }else{
            ui->button_changerank->setEnabled(false);
        }
    }

}

void AdminWindow::on_button_changerank_clicked()
{
    QList<QTableWidgetItem *> row = ui->table_users->selectedItems();
    std::string username = row[0]->text().toStdString();
    if((row[1]->text().toStdString()=="Admin") ? false:true)
        ui->button_changerank->setText("Demote");
    else
        ui->button_changerank->setText("Promote");
    emit onRequestChangeRank(username,(row[1]->text().toStdString()=="Admin") ? true:false);
}

void AdminWindow::on_button_tomcqs_clicked()
{
    requestUsers = !requestUsers;
    ui->button_changerank->hide();
    ui->button_tomcqs->hide();
    ui->button_users->show();
    ui->button_createmcq->show();
    ui->table_users->hide();
    ui->combobox_mcqs->show();
    ui->table_mcqs->show();
    insert_grades(mcqs->at(ui->combobox_mcqs->currentIndex())->getGrades());
}


void AdminWindow::on_button_signout_clicked()
{
    emit onSignOutSubmit();
}

void AdminWindow::showWindow(const User & user){
    this->user = &user;
    setWindowTitle(QString::fromStdString("Logged in as "+ user.getUsername()+" (Admin)"));
    this->ui->label_username->setText(QString::fromStdString(user.getUsername()));
    show();
    emit onRequestUsers();
    emit onRequestMCQs();
}

void AdminWindow::hideWindow(){
    ui->combobox_mcqs->clear();
    ui->table_users->clearContents();
    ui->table_mcqs->clearContents();
    hide();
}


}





