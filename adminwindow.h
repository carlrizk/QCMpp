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

    void set_mcqs(const std::vector<std::unique_ptr<MCQ>>& mcqs);

    void updateUsers(std::map<std::string, std::unique_ptr<User>> users);

public slots:

    void updateMCQs(const std::vector<std::unique_ptr<MCQ>> & mcqs);
    //void updateUsers(const std::)

signals:
    void onPromoteUser(const std::string & username);

    void onRequestMCQs();

    void onRequestUsers();

    void onSignOutSubmit();


private slots:
//    void on_create_mcq_clicked();

    void on_users_clicked();

//    void on_hide_users_clicked();

    void on_mcq_alreadyCreated_currentIndexChanged(int index);

    void on_sign_out_clicked();

private:
    Ui::AdminWindow *ui;

    void insert_grades(std::map<const std::string,const int> u_g);

    void create_mcq();

    void insert_users(std::map<const std::string,bool> u_r);

    const std::vector<std::unique_ptr<MCQ>> * mcqs;
};

}

#endif // ADMINWINDOW_H
