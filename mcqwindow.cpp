#include "mcqwindow.h"
#include "ui_mcqwindow.h"

#include <QLayout>
#include <vector>

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
    this->mcq = &mcq;
    this->user = &user;
    setWindowTitle(QString::fromStdString(mcq.getTitle()));
    ui->label_title->setText(QString::fromStdString(mcq.getTitle()));

    QWidget * area = ui->scroll_area;
    QLayout * layout = area->layout();

    for(auto& quest : mcq.getQuestions()){
        QuestionWidget * q_w = new QuestionWidget(*quest, area);
        layout->addWidget(q_w);
        question_widgets.push_back(q_w);
    }

    show();
}

void MCQWindow::hideWindow()
{
    reset();
    hide();
}

void MCQWindow::reset()
{
    for(auto q_w : question_widgets){
        delete q_w;
    }
    question_widgets.clear();
}

int MCQWindow::calculateGrade() const
{
    std::vector<std::vector<bool>> answers;
    for(auto& quest : question_widgets){
        answers.push_back(quest->correct());
    }
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
