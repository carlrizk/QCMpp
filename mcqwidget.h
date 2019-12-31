#ifndef MCQWIDGET_H
#define MCQWIDGET_H

#include <QWidget>
#include <mcq.h>

namespace Ui {
class MCQWidget;
}

namespace QCMpp {

class MCQWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MCQWidget(QWidget *parent = nullptr);
    ~MCQWidget();

signals:
    void onCancelSubmit();

public slots:
    void showWindow(const User & user, const MCQ & mcq);
    void hideWindow();

private slots:
    void on_button_cancel_clicked();

private:
    Ui::MCQWidget *ui;

    const MCQ * mcq;
    const User * user;

    void reset();
};

}

#endif // MCQWIDGET_H
