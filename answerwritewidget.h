#ifndef ANSWERWRITEWIDGET_H
#define ANSWERWRITEWIDGET_H

#include <QWidget>
#include <answer.h>

namespace Ui {
class AnswerWriteWidget;
}

namespace QCMpp {

class AnswerWriteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AnswerWriteWidget(QWidget *parent = nullptr);
    ~AnswerWriteWidget();

    Answer getAnswer()const ;

private:
    Ui::AnswerWriteWidget *ui;
};

}

#endif // ANSWERWRITEWIDGET_H
