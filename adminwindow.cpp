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
        ui->table->item(row,0)->setFlags(ui->table->item(row,0)->flags() & Qt::ItemIsEditable);
        this->ui->table->setItem(row, 1, new QTableWidgetItem(QString::number(it->second)));
        ui->table->item(row,1)->setFlags(ui->table->item(row,1)->flags() & Qt::ItemIsEditable);
        ++row;
    }
}

void AdminWindow::on_button_users_clicked()
{
    requestUsers = !requestUsers;
    //Preparing Window and table
    ui->button_users->hide();
    ui->button_createmcq->hide();
    ui->combobox_mcqs->hide();
    ui->button_tomcqs->show();
    this->ui->table->clearContents();
    QList<QString> labels = {"User","Rank"};
    this->ui->table->setHorizontalHeaderLabels(labels);

    emit onRequestUsers();
}

void AdminWindow::updateUsers(const std::map<std::string, std::unique_ptr<User>> & users)
{
    this->ui->table->setRowCount(users.size());
    int row =0;
    for (auto it = users.begin(); it != users.end(); ++it) {
        ui->table->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(it->first)));
        //ui->table->item(row,0)->setFlags(ui->table->item(row,0)->flags() & Qt::ItemIsEditable);
        ui->table->setItem(row, 1, new QTableWidgetItem(QString::fromStdString((it->second->isAdmin()) ? "Admin" : "Student")));
        //ui->table->item(row,1)->setFlags(ui->table->item(row,1)->flags() & Qt::ItemIsEditable);
        ++row;
    }

}

void QCMpp::AdminWindow::on_table_itemSelectionChanged()
{
    if(requestUsers){
        int row = ui->table->currentItem()->row();
        ui->button_changerank->show();
        std::string username = ui->table->item(row,0)->text().toStdString();
        std::string rank = ui->table->item(row,1)->text().toStdString();
        if(rank == "Admin"){
            ui->button_changerank->setText("Demote");
        }else{
            ui->button_changerank->setText("Promote");
        }
    }

}



void QCMpp::AdminWindow::on_button_changerank_clicked()
{
    QList<QTableWidgetItem *> row = ui->table->selectedItems();
    std::string username = row[0]->text().toStdString();
    emit onPromoteUser(username);
    ui->button_changerank->hide();
}

void QCMpp::AdminWindow::on_button_tomcqs_clicked()
{
    requestUsers = !requestUsers;
    ui->button_changerank->hide();
    ui->button_tomcqs->hide();
    ui->button_users->show();
    ui->button_createmcq->show();
    ui->table->clearContents();
    ui->combobox_mcqs->show();
    QList<QString> labels = {"User","Grade"};
    ui->table->setHorizontalHeaderLabels(labels);
    insert_grades(*(*mcqs)[ui->combobox_mcqs->currentIndex()]->getGrades());
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




