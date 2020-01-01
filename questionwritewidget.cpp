#include "questionwritewidget.h"
#include "ui_questionwritewidget.h"


namespace QCMpp {

QuestionWriteWidget::QuestionWriteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuestionWriteWidget)
{
    ui->setupUi(this);
}

QuestionWriteWidget::~QuestionWriteWidget()
{
    delete ui;
}

Question QuestionWriteWidget::getQuestion() const
{
    Question question(ui->edit_question->toPlainText().toStdString());
    for(auto& ans : answer_widgets){
        question.addAnswer(ans->getAnswer());
    }
    return question;
}

void QuestionWriteWidget::on_button_addanswer_clicked()
{
    AnswerWriteWidget * answ_w = new AnswerWriteWidget(this);
    answer_widgets.push_back(answ_w);
    ui->body->layout()->addWidget(answ_w);
}

}
