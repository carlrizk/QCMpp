#ifndef MCQREADWINDOW_H
#define MCQREADWINDOW_H

#include <QWidget>
#include <vector>

#include "mcqreadwidget.h"
#include "mcq.h"

namespace Ui {
class MCQReadWindow;
}

namespace QCMpp {

class MCQReadWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MCQReadWindow(QWidget *parent = nullptr);
    ~MCQReadWindow();

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
    Ui::MCQReadWindow *ui;
    const User * user;
    MCQ * mcq;

    MCQReadWidget * mcq_widget;

    void reset();
    int calculateGrade() const;
};

}

#endif // MCQREADWINDOW_H
