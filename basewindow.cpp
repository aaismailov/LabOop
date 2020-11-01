#include "basewindow.h"
#include "ui_basewindow.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "viewwindow.h"
#include "firstwindow.h"
#include "secondwindow.h"
#include "addnaa.h"
#include "addpaa.h"

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
void BaseWindow::on_pushFirstProteinButton_clicked()
{
    FirstWindow window;
    window.setModal(true);
    window.exec();
}

void BaseWindow::on_pushSecondProteinButton_clicked()
{
    SecondWindow window;
    window.setModal(true);
    window.exec();
}
