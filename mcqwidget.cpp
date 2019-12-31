#include "mcqwidget.h"
#include "ui_mcqwidget.h"

namespace QCMpp{

MCQWidget::MCQWidget(QWidget *parent):
    QWidget(parent),
    ui(new Ui::MCQWidget)
{
    ui->setupUi(this);
}

MCQWidget::~MCQWidget()
{
    delete ui;
}

void MCQWidget::showWindow(const User & user, const MCQ & mcq)
{
    this->mcq = &mcq;
    this->user = &user;
    setWindowTitle(QString::fromStdString(mcq.getTitle()));
    ui->label_title->setText(QString::fromStdString(mcq.getTitle()));
    show();
}

void MCQWidget::hideWindow()
{
    reset();
    hide();
}

void MCQWidget::reset()
{

}

void MCQWidget::on_button_cancel_clicked()
{
    emit onCancelSubmit();
}

}
