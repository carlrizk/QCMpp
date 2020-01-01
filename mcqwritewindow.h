#ifndef MCQWRITEWINDOW_H
#define MCQWRITEWINDOW_H

#include <QWidget>

namespace Ui {
class MCQWriteWindow;
}

class MCQWriteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MCQWriteWindow(QWidget *parent = nullptr);
    ~MCQWriteWindow();

private:
    Ui::MCQWriteWindow *ui;
};

#endif // MCQWRITEWINDOW_H
