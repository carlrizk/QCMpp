#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QWidget>
#include <string>

#include "mcq.h"

namespace Ui {
class AdminWindow;
}

namespace QCMpp {

class AdminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

public slots:

    void updateMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs);

    void updateUsers(const std::map<std::string, std::unique_ptr<User> >& users);

    void showWindow(User * const user);

    void hideWindow();

signals:
    void onRequestChangeRank(const std::string & username, bool isAdmin);

    void onRequestMCQs();

    void onRequestUsers();

    void onSignOutSubmit();

    void onCreateMCQ();


private slots:
    void on_button_createmcq_clicked();

    void on_button_users_clicked();

    void on_combobox_mcqs_currentIndexChanged(int index);

    void on_button_signout_clicked();

    void on_button_changerank_clicked();

    void on_button_tomcqs_clicked();

    void on_table_itemSelectionChanged();

private:
    Ui::AdminWindow *ui;

    User* currentUser;

    bool requestUsers;

    void insert_grades(const std::map<const std::string, const int> & u_g);

    const std::vector<std::unique_ptr<MCQ>> * mcqs;

    void setTableCell(const int row, const int column, const std::string & string);

};

}

#endif // ADMINWINDOW_H
