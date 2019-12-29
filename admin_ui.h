#ifndef ADMIN_UI_H
#define ADMIN_UI_H

#include <QWidget>
#include <string>

namespace Ui {
class Admin_ui;
}

class Admin_ui : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_ui(QWidget *parent = nullptr);
    ~Admin_ui();

private slots:
    void on_create_mcq_clicked();

    void on_users_clicked();

    void on_mcq_alreadyCreated_currentTextChanged(const QString &arg1);

    void on_hide_users_clicked();

private:
    Ui::Admin_ui *ui;

    void insert_grades(std::map<const std::string,const int> u_g);

    void create_mcq();

    void insert_users(std::map<const std::string,bool> u_r);

    void insert_rank();
};

#endif // ADMIN_UI_H
