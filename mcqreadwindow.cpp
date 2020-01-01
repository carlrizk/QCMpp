#include "mcqreadwindow.h"
#include "ui_mcqreadwindow.h"

#include <vector>

#include "mcqreadwidget.h"

namespace QCMpp{

MCQReadWindow::MCQReadWindow(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MCQReadWindow)
{
    ui->setupUi(this);
}

MCQReadWindow::~MCQReadWindow()
{
    delete ui;
}

void MCQReadWindow::showWindow(const User & user, MCQ & mcq)
{
    this->user = &user;
    this->mcq = &mcq;

    setWindowTitle(QString::fromStdString(mcq.getTitle()));
    ui->label_title->setText(QString::fromStdString(mcq.getTitle()));

    mcq_widget = new MCQReadWidget(mcq, this);
    ui->body->addWidget(mcq_widget);

    show();
}

void MCQReadWindow::hideWindow()
{
    reset();
    hide();
}

void MCQReadWindow::reset()
{
    delete mcq_widget;
}

int MCQReadWindow::calculateGrade() const
{
    std::vector<std::vector<bool>> answers = mcq_widget->correct();
    return mcq->correct(answers);
}

void MCQReadWindow::on_button_cancel_clicked()
{
    emit onCancelSubmit();
}

void MCQReadWindow::on_button_submit_clicked()
{
    mcq->addGrade(user->getUsername(), calculateGrade());
    emit onFinishMCQSubmit();
}

}
