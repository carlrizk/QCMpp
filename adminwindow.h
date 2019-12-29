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

    //void setMcq(int index);

signals:
    void Promote_u(const std::string & username);

    void Create_mcq(const QCMpp::MCQ& mcq);


private slots:
//    void on_create_mcq_clicked();

//    void on_users_clicked();

//    void on_hide_users_clicked();

//    void on_mcq_alreadyCreated_currentIndexChanged(int index);

private:
    Ui::AdminWindow *ui;

    void insert_grades(std::map<const std::string,const int> u_g);

    void create_mcq();

    void insert_users(std::map<const std::string,bool> u_r);
};

}

#endif // ADMINWINDOW_H
