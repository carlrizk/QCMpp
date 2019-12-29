#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include "user.h"
#include "mcq.h"

namespace Ui {
class UserWindow;
}

namespace QCMpp {

class UserWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

signals:
    void onSignOutSubmit();
    void onRequestMCQs();

public slots:
    void showWindow(User * const user);
    void hideWindow();
    void updateMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs);

private slots:
    void on_button_signout_clicked();

private:
    Ui::UserWindow *ui;

    User* currentUser;
    void reset();
};
}

#endif // USERWINDOW_H
