#include "questionwidget.h"

#include <QLabel>
#include <QVBoxLayout>

namespace QCMpp {

QuestionWidget::QuestionWidget(const Question & question, QWidget *parent) :
    QWidget(parent){

    QVBoxLayout * layout = new QVBoxLayout(this);

    QLabel * label_question = new QLabel(this);
    label_question->setWordWrap(true);
    label_question->setText(QString::fromStdString(question.getText()));
    layout->addWidget(label_question);

    for(auto& ans : question.getAnswers()){
        AnswerReadWidget * a_w = new AnswerReadWidget(*ans, this);
        layout->addWidget(a_w);
        answer_widgets.push_back(a_w);
    }
    setLayout(layout);
}

std::vector<bool> QuestionWidget::correct() const
{
    std::vector<bool> answers;
    for(auto& answ : answer_widgets){
        answers.push_back(answ->isChecked());
    }
    return answers;
};

}
