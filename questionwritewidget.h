#ifndef QUESTIONWRITEWIDGET_H
#define QUESTIONWRITEWIDGET_H

#include <QWidget>
#include <vector>

#include "answerwritewidget.h"
#include "question.h"

namespace Ui {
class QuestionWriteWidget;
}

namespace QCMpp {

class QuestionWriteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit QuestionWriteWidget(QWidget *parent = nullptr);
    ~QuestionWriteWidget();

    Question getQuestion()const;

private slots:
    void on_button_addanswer_clicked();

private:
    Ui::QuestionWriteWidget *ui;
    std::vector<AnswerWriteWidget *> answer_widgets;
};

}

#endif // QUESTIONWRITEWIDGET_H
