#include "admin_ui.h"
#include "ui_admin_ui.h"
#include<string>

using namespace std;

Admin_ui::Admin_ui(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_ui)
{
    ui->setupUi(this);
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
    update_table(false);
}

void Admin_ui::on_mcq_alreadyCreated_currentTextChanged(const QString &arg1)
{
    string qcm = this->ui->mcq_alreadyCreated->currentText().toStdString();
    update_table(true);
}
