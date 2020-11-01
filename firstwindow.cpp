#include "firstwindow.h"
#include "ui_firstwindow.h"

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
}

FirstWindow::~FirstWindow()
{
    delete ui;
}
