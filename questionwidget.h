#ifndef QUESTIONWIDGET_H
#define QUESTIONWIDGET_H

#include <QWidget>
#include <vector>

#include "question.h"
#include "answerwidget.h"

namespace QCMpp{

class QuestionWidget : public QWidget
{
    Q_OBJECT
public:
    explicit QuestionWidget(const Question & question, QWidget *parent = nullptr);

    std::vector<bool> correct() const;

private:
    std::vector<AnswerWidget *> answer_widgets;

};

}

#endif // QUESTIONWIDGET_H