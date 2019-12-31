#ifndef QUESTIONREADWIDGET_H
#define QUESTIONREADWIDGET_H

#include <QWidget>
#include <vector>
#include "question.h"
#include "answerreadwidget.h"

namespace Ui {
class QuestionReadWidget;
}

namespace QCMpp{
class QuestionReadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionReadWidget(const Question & question, QWidget *parent = nullptr);
    ~QuestionReadWidget();

    std::vector<bool> correct() const;

private:
    Ui::QuestionReadWidget *ui;

    const Question * question;
    std::vector<AnswerReadWidget *> answer_widgets;
};

}
#endif // QUESTIONREADWIDGET_H
