#ifndef MCQWIDGET_H
#define MCQWIDGET_H

#include <QWidget>
#include <vector>

#include "questionwidget.h"
#include "mcq.h"

namespace Ui {
class MCQWindow;
}

namespace QCMpp {

class MCQWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MCQWindow(QWidget *parent = nullptr);
    ~MCQWindow();

signals:
    void onCancelSubmit();
    void onFinishMCQSubmit();

public slots:
    void showWindow(const User & user, MCQ & mcq);
    void hideWindow();

private slots:
    void on_button_cancel_clicked();

    void on_button_submit_clicked();

private:
    Ui::MCQWindow *ui;

    MCQ * mcq;
    const User * user;

    std::vector<QuestionWidget *> question_widgets;

    void reset();
    int calculateGrade() const;
};

}

#endif // MCQWIDGET_H
