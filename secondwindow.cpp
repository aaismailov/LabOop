#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <QMessageBox>
#include <string>
#include <stdlib.h>
#include <QStandardItem>
#include <QStandardItemModel>
#include "viewwindow.h"
#include "addnaa.h"
#include "addpaa.h"
#include <fstream>
#include <sstream>

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    this->Second.fromFile("saveProtein2.txt");
}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void saveData2(Protein Second)
{
    ofstream fout("saveProtein2.txt", std::ofstream::out | std::ofstream::trunc);
    for(int i = 0;i < Second.getSize();i++)
    {
        Second.setIteratorIndex(i+1);
        fout << Second.getIteratorValue().getName() << " " << Second.getIteratorValue().getSymbol()<< endl;
    }
    fout.close();
}

Protein getAa2(Protein p){
    ifstream file("saveAa.txt");
    string name;
    char symbol;
    string pos;
    if (file.is_open()) {
        file>>name>>pos>>symbol;
        file.close();
    }
    if (symbol == '\0'){
        NonstandardAminoAcid naa(name);
        if (pos == "Head") p.addHead(naa), cout<<"Naa: "<<pos<<endl;
        else if (pos == "Tail") p.addTail(naa), cout<<"Naa: "<<pos<<endl;
        else p.addElem(naa, atoi(pos.c_str())), cout<<"Naa: "<<pos<<endl;
        } else {
            ProteinogenicAminoAcid paa(name, symbol);
            if (!(paa.getName() == "" && paa.getSymbol() == '\0') && (paa.getSymbol()>64)&&(paa.getSymbol()<91)){
                if (pos == "Head") p.addHead(paa), cout<<"Paa: "<<pos<<endl;
                else if (pos == "Tail") p.addTail(paa), cout<<"Paa: "<<pos<<endl;
                else p.addElem(paa, atoi(pos.c_str())), cout<<"Paa: "<<pos<<endl;

            }
    }
    return p;
}

// Add paa
void SecondWindow::on_pushButton_13_clicked()
{
    AddPaa window;
    window.setModal(true);
    window.show();
    window.exec();
    this->Second = getAa2(this->Second);
}

// Add naa
void SecondWindow::on_pushButton_14_clicked()
{
    AddNaa window;
    window.setModal(true);
    window.show();
    window.exec();
    this->Second = getAa2(this->Second);
}

// Delete aa in pos
void SecondWindow::on_pushButton_4_clicked()
{
    if(this->Second.getIteratorIndex() && this->Second.getSize())
    {
        std:: string pos  = ui->lineEdit_5->text().toStdString();
        this->Second.remove(atoi(pos.c_str()));
        QMessageBox::information(this, "Delete aa", "You delete aa");
    }
    else
        QMessageBox::critical(this,"Delete aa", "There is no data to delete");
}

// Delete Protein
void SecondWindow::on_pushButton_5_clicked()
{
    if(this->Second.getIteratorIndex() && this->Second.getSize())
    {
        this->Second.clean();
        QMessageBox::information(this, "Clean", "You delete protein");
    }
    else
        QMessageBox::critical(this,"Clean", "There is no data to clean");
}

// Size
void SecondWindow::on_pushButton_6_clicked()
{
    if(this->Second.getIteratorIndex() && this->Second.getSize())
    {
        QMessageBox::information(this, "Size", "The size of the protein is " + QString::number(this->Second.getSize()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no protein");
}

// View
void SecondWindow::on_pushButton_7_clicked()
{
    if(this->Second.getIteratorIndex() && this->Second.getSize())
    {
        ViewWindow window;
        window.setModal(true);
        window.insertData(this->Second, this->Second.getSize());
        window.show();
        window.exec();
    }
    else
        QMessageBox::critical(this, "Show", "There is no data to show");
}

// Input from file
void SecondWindow::on_pushButton_8_clicked()
{
    this->Second.fromFile(ui->lineEdit_6->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

// Output to file
void SecondWindow::on_pushButton_9_clicked()
{
    if(this->Second.getIteratorIndex() && this->Second.getSize())
    {
        this->Second.toFile(ui->lineEdit_7->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no protein");
}

// Back
void SecondWindow::on_pushButton_clicked()
{
    QMessageBox::StandardButton save = QMessageBox::question(this, "Save", "Save collection?", QMessageBox::Yes | QMessageBox::No);
    if(save == QMessageBox::No)
    {
        Second.clean();
    }
    saveData2(Second);
    this->close();
}
