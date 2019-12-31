#include "mcqwindow.h"
#include "ui_mcqwindow.h"

#include <vector>

#include "mcqreadwidget.h"

namespace QCMpp{

MCQWindow::MCQWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MCQWindow)
{
    ui->setupUi(this);
}

MCQWindow::~MCQWindow()
{
    delete ui;
}

void MCQWindow::showWindow(const User & user, MCQ & mcq)
{
    this->user = &user;
    this->mcq = &mcq;

    setWindowTitle(QString::fromStdString(mcq.getTitle()));
    ui->label_title->setText(QString::fromStdString(mcq.getTitle()));

    mcq_widget = new MCQReadWidget(mcq, this);
    ui->body->addWidget(mcq_widget);

    show();
}

void MCQWindow::hideWindow()
{
    reset();
    hide();
}

void MCQWindow::reset()
{
    delete mcq_widget;
}

int MCQWindow::calculateGrade() const
{
    std::vector<std::vector<bool>> answers = mcq_widget->correct();
    return mcq->correct(answers);
}

void MCQWindow::on_button_cancel_clicked()
{
    emit onCancelSubmit();
}

}

void QCMpp::MCQWindow::on_button_submit_clicked()
{
    mcq->addGrade(user->getUsername(), calculateGrade());
    emit onFinishMCQSubmit();
}
