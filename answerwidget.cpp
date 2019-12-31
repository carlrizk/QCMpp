#include "answerwidget.h"

#include <iostream>
#include <QLabel>
#include <QHBoxLayout>

namespace QCMpp{

AnswerWidget::AnswerWidget(const Answer & answer, QWidget *parent) : QWidget(parent)
{

    QHBoxLayout * layout = new QHBoxLayout(this);

    QLabel * label_answer = new QLabel(this);
    label_answer->setWordWrap(true);
    label_answer->setAlignment(Qt::AlignLeft);
    label_answer->setText(QString::fromStdString(answer.getText()));

    checkbox = new QCheckBox(this);

    layout->addWidget(checkbox);
    layout->addWidget(label_answer);

    setLayout(layout);
}

bool AnswerWidget::correct() const
{
    return checkbox->isChecked();
}

}
