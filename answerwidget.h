#ifndef ANSWERWIDGET_H
#define ANSWERWIDGET_H

#include <QWidget>
#include <QCheckBox>

#include "answer.h"

namespace QCMpp{

class AnswerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AnswerWidget(const Answer& answer, QWidget *parent = nullptr);

    bool correct() const;

private:
    QCheckBox * checkbox;
};
}

#endif // ANSWERWIDGET_H
