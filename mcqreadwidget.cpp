#include "mcqreadwidget.h"
#include "ui_mcqreadwidget.h"

namespace QCMpp{

MCQReadWidget::MCQReadWidget(const MCQ & mcq, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MCQReadWidget)
{
    ui->setupUi(this);

    for(auto& quest : mcq.getQuestions()){
        QuestionReadWidget* quest_w = new QuestionReadWidget(*quest, this);
        ui->body->addWidget(quest_w);
        question_widgets.push_back(quest_w);
    }
}

MCQReadWidget::~MCQReadWidget()
{
    delete ui;
}

std::vector<std::vector<bool> > MCQReadWidget::correct() const
{
    std::vector<std::vector<bool> > answers;
    for(auto& answ : question_widgets){
        answers.push_back(answ->correct());
    }
    return answers;
}

}
