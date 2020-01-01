#include "answerwritewidget.h"
#include "ui_answerwritewidget.h"

namespace QCMpp {

AnswerWriteWidget::AnswerWriteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnswerWriteWidget)
{
    ui->setupUi(this);
}

AnswerWriteWidget::~AnswerWriteWidget()
{
    delete ui;
}

Answer AnswerWriteWidget::getAnswer() const
{
    return Answer(ui->edit->toPlainText().toStdString() ,ui->checkbox->isChecked());
}

}
