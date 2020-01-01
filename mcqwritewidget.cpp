#include "mcqwritewidget.h"
#include "ui_mcqwritewidget.h"

namespace QCMpp{

MCQWriteWidget::MCQWriteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MCQWriteWidget)
{
    ui->setupUi(this);
}

MCQWriteWidget::~MCQWriteWidget()
{
    delete ui;
}

MCQ MCQWriteWidget::getMCQ(const std::string title) const
{
    MCQ mcq(title);
    for(auto& quest : question_widgets){
        mcq.addQuestion(quest->getQuestion());
    }
    return mcq;
}

void MCQWriteWidget::on_button_addquestion_clicked()
{
    QuestionWriteWidget * quest_w = new QuestionWriteWidget(this);
    ui->body->addWidget(quest_w);
    question_widgets.push_back(quest_w);
}

}
