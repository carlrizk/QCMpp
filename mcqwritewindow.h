#ifndef MCQWRITEWINDOW_H
#define MCQWRITEWINDOW_H

#include <QWidget>

#include "mcq.h"
#include "mcqwritewidget.h"

namespace Ui {
class MCQWriteWindow;
}

namespace QCMpp {

class MCQWriteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MCQWriteWindow(QWidget *parent = nullptr);
    ~MCQWriteWindow();

signals:
    void onCancelSubmit();
    void onFinishMCQSubmit(const MCQ & mcq);

public slots:
    void showWindow();
    void hideWindow();

private slots:
    void on_button_cancel_clicked();

    void on_button_submit_clicked();

private:
    Ui::MCQWriteWindow *ui;

    MCQWriteWidget * mcq_widget;

    void reset();
};

}

#endif // MCQWRITEWINDOW_H
