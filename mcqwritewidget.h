#ifndef MCQWRITEWIDGET_H
#define MCQWRITEWIDGET_H

#include <QWidget>
#include <vector>

#include "questionwritewidget.h"
#include "mcq.h"

namespace Ui {
class MCQWriteWidget;
}

namespace QCMpp {

class MCQWriteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MCQWriteWidget(QWidget *parent = nullptr);
    ~MCQWriteWidget();

    MCQ getMCQ(const std::string title)const;

private slots:
    void on_button_addquestion_clicked();

private:
    Ui::MCQWriteWidget *ui;

    std::vector<QuestionWriteWidget* > question_widgets;

};

}

#endif // MCQWRITEWIDGET_H
