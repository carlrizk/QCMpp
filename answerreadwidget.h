#ifndef ANSWERREADWIDGET_H
#define ANSWERREADWIDGET_H

#include <QWidget>
#include <string>
#include "answer.h"

namespace Ui {
class AnswerReadWidget;
}
namespace QCMpp {

class AnswerReadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AnswerReadWidget(const Answer & answer, QWidget *parent = nullptr);
    ~AnswerReadWidget();

    bool isChecked()const;
private:
    Ui::AnswerReadWidget *ui;

    const Answer * answer;
};

}

#endif // ANSWERREADWIDGET_H
