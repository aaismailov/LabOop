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
    this->First.fromFile("saveProtein.txt");
    this->Second.fromFile("saveProtein2.txt");
}

BaseWindow::~BaseWindow()
{
    delete ui;
}

// Protein 1
void BaseWindow::on_pushFirstProteinButton_clicked()
{
    FirstWindow window;
    window.setModal(true);
    window.exec();
    this->First.fromFile("saveProtein.txt");
}

// Protein 2
void BaseWindow::on_pushSecondProteinButton_clicked()
{
    SecondWindow window;
    window.setModal(true);
    window.exec();
    this->Second.fromFile("saveProtein2.txt");
}

// Сложение белков
void BaseWindow::on_pushButton_clicked()
{
    if (this->First.getSize() == 0 && this->Second.getSize() == 0)
        QMessageBox::critical(this,"Protein addition", "There is no Proteins");
    else if (this->First.getSize() == 0)
        QMessageBox::critical(this,"Protein addition", "There is no Protein 1");
    else if (this->Second.getSize() == 0)
        QMessageBox::critical(this,"Protein addition", "There is no Protein 2");
    else if (this->First.getIteratorIndex() && this->First.getSize() && this->Second.getIteratorIndex() && this->Second.getSize())
    {
        Protein SumProtein;
        if ((this->First+this->Second).getSize() <= (this->Second+this->First).getSize())
            SumProtein = this->First + this->Second;
        else SumProtein = this->Second + this->First;
        ViewWindow window;
        window.setModal(true);
        window.insertData(SumProtein, SumProtein.getSize());
        window.show();
        window.exec();
    }
}
