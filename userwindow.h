#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include "user.h"

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

public slots:
    void showWindow(User * const user);
    void hideWindow();

private slots:
    void on_button_signout_clicked();

private:
    Ui::UserWindow *ui;

    void reset() const;
};
}

#endif // USERWINDOW_H
