#ifndef ADMIN_UI_H
#define ADMIN_UI_H

#include <QWidget>

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

private:
    Ui::Admin_ui *ui;

    void update_table(const bool with_grades = true);

    void create_mcq();
};

#endif // ADMIN_UI_H
