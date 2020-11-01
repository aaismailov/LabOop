#include "firstwindow.h"
#include "ui_firstwindow.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "viewwindow.h"
#include "firstwindow.h"
#include "addnaa.h"
#include "addpaa.h"
#include <fstream>

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow) {
    ui->setupUi(this);
    this->First.fromFile("saveProtein.txt");
}

FirstWindow::~FirstWindow() {
    delete ui;
}

void saveData(Protein First)
{
    ofstream fout("saveProtein.txt");
    for(int i = 0;i < First.getSize();i++)
    {
        First.setIteratorIndex(i);
        fout <<First.getIteratorValue().getName() << " " << First.getIteratorValue().getSymbol()<< endl;
    }
    fout.close();
}

void FirstWindow::on_pushButton_13_clicked()
{
    AddPaa window;
    window.setModal(true);
    window.show();
    window.exec();
}

void FirstWindow::on_pushButton_14_clicked()
{
    AddNaa window;
    window.setModal(true);
    window.show();
    window.exec();
}

void FirstWindow::on_pushButton_4_clicked()
{
    if(this->First.getIteratorIndex() && this->First.getSize())
    {
        std:: string pos  = ui->lineEdit_5->text().toStdString();
        this->First.remove(atoi(pos.c_str()));
        QMessageBox::information(this, "Delete aa", "You delete aa");
    }
    else
        QMessageBox::critical(this,"Delete aa", "There is no data to delete");
}

void FirstWindow::on_pushButton_5_clicked()
{
    if(this->First.getIteratorIndex() && this->First.getSize())
    {
        this->First.clean();
        QMessageBox::information(this, "Clean", "You delete protein 1");
    }
    else
        QMessageBox::critical(this,"Clear", "There is no data to clean");
}

void FirstWindow::on_pushButton_6_clicked()
{
    if(this->First.getIteratorIndex() && this->First.getSize())
    {
        QMessageBox::information(this, "Size", "The size of the protein 1 is " + QString::number(this->First.getSize()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no protein 1");
}

void FirstWindow::on_pushButton_7_clicked()
{

    if(this->First.getIteratorIndex() && this->First.getSize())
    {
        ViewWindow window;
        window.setModal(true);
        window.insertData(&this->First, this->First.getSize());
        window.exec();
    }
    else
        QMessageBox::critical(this, "Show", "There is no data to show");
}

void FirstWindow::on_pushButton_8_clicked()
{
    this->First.fromFile(ui->lineEdit_6->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

void FirstWindow::on_pushButton_9_clicked()
{
    if(this->First.getIteratorIndex() && this->First.getSize())
    {
        this->First.toFile(ui->lineEdit_7->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no protein");
}

void FirstWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton save = QMessageBox::question(this, "Save", "Save collection?", QMessageBox::Yes | QMessageBox::No);
    if(save == QMessageBox::No)
    {
        First.clean();
    }
    saveData(First);
    this->close();
}
