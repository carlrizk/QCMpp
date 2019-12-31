#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QWidget>
#include <QTableWidget>
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
    void onTakeMCQSubmit(int mcq_id);
    void onRequestMCQs();

public slots:
    void showWindow(const User & user);
    void hideWindow();
    void updateMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs);

private slots:
    void on_button_signout_clicked();
    void on_table_mcqs_itemSelectionChanged();

    void on_button_take_clicked();

private:
    Ui::UserWindow *ui;

    const User * user;
    void reset();
    void setTableCell(int row, int column, const std::string & string,  QTableWidget & table);
};
}

#endif // USERWINDOW_H
