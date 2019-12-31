#include "questionreadwidget.h"
#include "ui_questionreadwidget.h"

namespace QCMpp {

QuestionReadWidget::QuestionReadWidget(const Question & question, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionReadWidget), question(&question)
{
    ui->setupUi(this);

    ui->body->setTitle(QString::fromStdString(question.getText()));
    for(auto& answ : question.getAnswers()){
        AnswerReadWidget * answ_w = new AnswerReadWidget(*answ, this);
        answer_widgets.push_back(answ_w);
        ui->body->layout()->addWidget(answ_w);
    }
}

QuestionReadWidget::~QuestionReadWidget()
{
    delete ui;
}

std::vector<bool> QuestionReadWidget::correct() const
{
    std::vector<bool> answers;
    for(auto& answ : answer_widgets){
        answers.push_back(answ->isChecked());
    }
    return answers;
}

}
