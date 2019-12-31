#include "answerreadwidget.h"
#include "ui_answerreadwidget.h"

namespace QCMpp{

AnswerReadWidget::AnswerReadWidget(const Answer & answer, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnswerReadWidget), answer(&answer)
{
    ui->setupUi(this);

    ui->text->setText(QString::fromStdString(answer.getText()));
}

AnswerReadWidget::~AnswerReadWidget()
{
    delete ui;
}

bool AnswerReadWidget::isChecked() const
{
    return ui->checkBox->isChecked();
}

}
