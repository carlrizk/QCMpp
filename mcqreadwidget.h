#ifndef MCQREADWIDGET_H
#define MCQREADWIDGET_H

#include <QWidget>
#include <vector>

#include "mcq.h"
#include "questionreadwidget.h"
#include <vector>

namespace Ui {
class MCQReadWidget;
}

namespace QCMpp {

class MCQReadWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MCQReadWidget(const MCQ & mcq, QWidget *parent = nullptr);
    ~MCQReadWidget();

    std::vector<std::vector<bool>> correct() const;

private:
    Ui::MCQReadWidget *ui;

    std::vector<QuestionReadWidget *> question_widgets;
};

}

#endif // MCQREADWIDGET_H
