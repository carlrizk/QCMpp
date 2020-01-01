#include "mcqwritewindow.h"
#include "ui_mcqwritewindow.h"

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
