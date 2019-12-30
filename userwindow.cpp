#include "userwindow.h"
#include "ui_userwindow.h"

#include <iostream>

namespace QCMpp {

UserWindow::UserWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWindow), currentUser(nullptr)
{
    ui->setupUi(this);

    QStringList horzHeaders;
    horzHeaders << "MCQ" << "Grade";
    ui->table_mcqs->setHorizontalHeaderLabels(horzHeaders);

    reset();
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::showWindow(User * const user)
{
    currentUser = user;
    setWindowTitle(QString::fromStdString("Logged In as " + currentUser->getUsername() + " (Student)"));
    this->ui->label_username->setText(QString::fromStdString(currentUser->getUsername()));
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
        bool hasGrade = mcqs[i]->hasGrade(currentUser->getUsername());
        setTableCell(i, 1 , (hasGrade) ? std::to_string(mcqs[i]->getGrade(currentUser->getUsername())) : "", *ui->table_mcqs);
    }
}

void UserWindow::reset()
{
    currentUser = nullptr;
    ui->label_username->clear();
    ui->table_mcqs->clearContents();
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

}
