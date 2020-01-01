#include "mcqwritewindow.h"
#include "ui_mcqwritewindow.h"

namespace QCMpp {

MCQWriteWindow::MCQWriteWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MCQWriteWindow)
{
    ui->setupUi(this);
}

MCQWriteWindow::~MCQWriteWindow()
{
    delete ui;
}

void MCQWriteWindow::showWindow()
{
    mcq_widget = new MCQWriteWidget(this);
    ui->body->addWidget(mcq_widget);

   show();
}

void MCQWriteWindow::hideWindow()
{
    reset();
    hide();
}

void MCQWriteWindow::on_button_cancel_clicked()
{
    emit onCancelSubmit();
}

void MCQWriteWindow::on_button_submit_clicked()
{
    emit onFinishMCQSubmit(mcq_widget->getMCQ(ui->edit_name->text().toStdString()));
}

void MCQWriteWindow::reset()
{
    ui->edit_name->clear();
    delete mcq_widget;
}

}
