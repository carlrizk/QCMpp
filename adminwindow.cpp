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

    //ui->mcq_alreadyCreated->addItem()
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

//void AdminWindow::on_create_mcq_clicked()
//{

//}


//void AdminWindow::on_users_clicked()
//{
//    ui->users->hide();
//    ui->create_mcq->hide();
//    ui->hide_users->show();
//    //int index = ui->mcq_alreadyCreated->currentIndex();


//}

//void AdminWindow::on_hide_users_clicked()
//{
//    ui->hide_users->hide();
//    ui->mcq_alreadyCreated->show();
//    ui->create_mcq->show();
//    ui->table->clearContents();
//    //insert_grades()

//}


void AdminWindow::insert_grades(std::map<const std::string,const int> u_g)
{
    using namespace std;
    string qcm = this->ui->mcq_alreadyCreated->currentText().toStdString();
    this->ui->table->clearContents();
    this->ui->table->removeColumn(1);
    this->ui->table->insertColumn(1);
    QList<QString> labels = {"User","Grade"};
    this->ui->table->setHorizontalHeaderLabels(labels);
    int row = 1;
    for(map<const std::string,const int>::iterator it(u_g.begin());it!=u_g.end();++it){
        if (row > this->ui->table->rowCount()){
            this->ui->table->setRowCount(this->ui->table->rowCount()+1);
        }
        this->ui->table->setItem(row,0,new QTableWidgetItem(QString::fromStdString(it->first)));
        this->ui->table->setItem(row,0,new QTableWidgetItem(it->second));
        ++row;
    }
    this->ui->table->setRowCount(row);
}

void AdminWindow::create_mcq()
{
    //Removing items from interface
    this->ui->table->clearContents();
    this->ui->table->hide();
    this->ui->label->hide();
    this->ui->create_mcq->hide();
    this->ui->users->hide();

    //Adding items to interface


}

void AdminWindow::insert_users(std::map<const std::string,bool> u_r)
{
    ui->create_mcq->hide();             //New window
    ui->hide_users->show();             //To return to main window
    this->ui->table->clearContents();
    this->ui->table->removeColumn(1);   //Remove the grades column
    this->ui->table->insertColumn(1);   //Adding the rank column
    QList<QString> labels = {"User","Rank"};
    this->ui->table->setHorizontalHeaderLabels(labels); //Labeling columns
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


//void AdminWindow::on_mcq_alreadyCreated_currentIndexChanged(int index)
//{

//}

}
