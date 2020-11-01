#include "basewindow.h"
#include "ui_basewindow.h"

BaseWindow::BaseWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BaseWindow)
{
    ui->setupUi(this);
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

