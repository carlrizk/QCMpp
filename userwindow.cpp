#include "userwindow.h"
#include "ui_userwindow.h"

#include <iostream>

namespace QCMpp {

UserWindow::UserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);

    reset();
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::showWindow(const User & user)
{
    this->user = &user;
    setWindowTitle(QString::fromStdString("Logged In as " + user.getUsername() + " (Student)"));
    this->ui->label_username->setText(QString::fromStdString(user.getUsername()));
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
        setTableCell(i, 0 , mcqs[i]->getTitle(), *ui->table_mcqs);
        bool hasGrade = mcqs[i]->hasGrade(user->getUsername());
        setTableCell(i, 1 , (hasGrade) ? std::to_string(mcqs[i]->getGrade(user->getUsername())) : "", *ui->table_mcqs);
    }
}

void UserWindow::reset()
{
    user = nullptr;
    ui->label_username->clear();
    ui->table_mcqs->clearContents();
    ui->button_take->setEnabled(false);
}

void UserWindow::setTableCell(int row, int column, const std::string &string, QTableWidget &table)
{
    auto cell = new QTableWidgetItem(QString::fromStdString(string));
    cell->setFlags(cell->flags() &  ~Qt::ItemIsEditable);
    table.setItem(row, column, cell );
}

void QCMpp::UserWindow::on_button_signout_clicked()
{
    emit onSignOutSubmit();
}

void QCMpp::UserWindow::on_table_mcqs_itemSelectionChanged()
{
    auto selected = ui->table_mcqs->selectedItems();
    if(selected.isEmpty()) return;
    if(!selected[1]->text().isEmpty()){
        ui->button_take->setEnabled(false);
    }else{
        ui->button_take->setEnabled(true);
    }
}

void QCMpp::UserWindow::on_button_take_clicked()
{
    emit onTakeMCQSubmit(ui->table_mcqs->currentRow());
}

}
