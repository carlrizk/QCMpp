#include "admin_ui.h"
#include "ui_admin_ui.h"
#include<string>
#include<map>

using namespace std;

Admin_ui::Admin_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_ui)
{
    ui->setupUi(this);
    ui->hide_users->hide();
}

Admin_ui::~Admin_ui()
{
    delete ui;
}

void Admin_ui::on_create_mcq_clicked()
{

}

void Admin_ui::on_users_clicked()
{
    string qcm = this->ui->mcq_alreadyCreated->currentText().toStdString();

}

void Admin_ui::on_hide_users_clicked()
{

}

void Admin_ui::on_mcq_alreadyCreated_currentTextChanged(const QString &arg1)
{
    string qcm = arg1.toStdString();
}

void Admin_ui::insert_grades(std::map<const std::string,const int> u_g)
{
    string qcm = this->ui->mcq_alreadyCreated->currentText().toStdString();
    this->ui->table->clearContents();
    this->ui->table->removeColumn(1);
    this->ui->table->insertColumn(1);
    QList<QString> labels = {"User","Grade"};
    this->ui->table->setHorizontalHeaderLabels(labels);
    int row = 1;
    for(map<const std::string,const int>::iterator it(u_g.begin());it!=u_g.end();++it){
        if (row > this->ui->table->rowCount()){
            this->ui->table->insertRow(row);
        }
        this->ui->table->setCurrentCell(row,0);
        QTableWidgetItem user_it(QString::fromStdString(it->first));
        this->ui->table->setCurrentItem(&user_it);
        this->ui->table->setCurrentCell(row,1);
        QTableWidgetItem grade_it(it->second);
        this->ui->table->setCurrentItem(&grade_it);
        ++row;
    }
    while(row < this->ui->table->rowCount()){
        this->ui->table->removeRow(row);
    }
}

void Admin_ui::create_mcq()
{
    this->ui->table->hide();
    this->ui->label->hide();
    this->ui->create_mcq->hide();
    this->ui->users->hide();

}

void Admin_ui::insert_users(std::map<const std::string,bool> u_r)
{
    ui->create_mcq->hide();             //New window
    ui->hide_users->show();             //To return to main window
    this->ui->table->clearContents();
    this->ui->table->removeColumn(1);   //Remove the grades column
    this->ui->table->insertColumn(1);   //Adding the rank column
    QList<QString> labels = {"User","Rank"};
    this->ui->table->setHorizontalHeaderLabels(labels); //Labeling columns
    int row = 1;
    for(map<const std::string,bool>::iterator it(u_r.begin()); it != u_r.end(); ++it){
        if (row > this->ui->table->rowCount()){
            this->ui->table->insertRow(row);
        }
        this->ui->table->setCurrentCell(row,0);
        QTableWidgetItem user_it(QString::fromStdString(it->first));
        this->ui->table->setCurrentItem(&user_it);
        this->ui->table->setCurrentCell(row,1);
        if (it->second == true){
            QTableWidgetItem rank_it(QString::fromStdString("Admin"));
            this->ui->table->setCurrentItem(&rank_it);
        }else{
            QTableWidgetItem rank_it(QString::fromStdString("Student"));
            this->ui->table->setCurrentItem(&rank_it);
        }
        ++row;
    }
    while(row < this->ui->table->rowCount()){
        this->ui->table->removeRow(row);
    }
}

