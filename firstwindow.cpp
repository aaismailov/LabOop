#include "firstwindow.h"
#include "ui_firstwindow.h"
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

FirstWindow::FirstWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FirstWindow) {
    ui->setupUi(this);
    this->First.fromFile("saveProtein.txt");
}

FirstWindow::~FirstWindow() {
    delete ui;
}

void saveData(Protein First) {
    ofstream fout("saveProtein.txt", std::ofstream::out | std::ofstream::trunc);
    for(int i = 0;i < First.getSize();i++) {
        First.setIteratorIndex(i+1);
        fout <<First.getIteratorValue().getName() << " " << First.getIteratorValue().getSymbol()<< endl;
    }
    fout.close();
}

Protein getAa(Protein p) {
    ifstream file("saveAa.txt");
    string name;
    char symbol;
    string pos;
    if (file.is_open()) {
        file>>name>>pos>>symbol;
        file.close();
    }
    cout<<name<<" "<<symbol<<" "<< pos<<endl;
    if (symbol == '\0'){
        NonstandardAminoAcid naa(name);
        if (pos == "Head") p.addHead(naa);
        else if (pos == "Tail") p.addTail(naa);
        else p.addElem(naa, atoi(pos.c_str()));
    } else {
        ProteinogenicAminoAcid paa(name, symbol);
        if (!(paa.getName() == "" && paa.getSymbol() == '\0') && (paa.getSymbol()>64)&&(paa.getSymbol()<91)){
            if (pos == "Head") p.addHead(paa);
            else if (pos == "Tail") p.addTail(paa);
            else p.addElem(paa, atoi(pos.c_str()));
        }
    }
    return p;
}

// Add paa
void FirstWindow::on_pushButton_13_clicked() {
    AddPaa window;
    window.setModal(true);
    window.show();
    window.exec();
    this->First = getAa(this->First);
}

// Add naa
void FirstWindow::on_pushButton_14_clicked() {
    AddNaa window;
    window.setModal(true);
    window.show();
    window.exec();
    this->First = getAa(this->First);
}

// Delete aa in pos
void FirstWindow::on_pushButton_4_clicked() {
    if (this->First.getIteratorIndex() && this->First.getSize()) {
        std:: string pos  = ui->lineEdit_5->text().toStdString();
        this->First.remove(atoi(pos.c_str()));
        QMessageBox::information(this, "Delete aa", "You delete aa");
    }
    else
        QMessageBox::critical(this,"Delete aa", "There is no data to delete");
}

// Delete Protein
void FirstWindow::on_pushButton_5_clicked() {
    if(this->First.getIteratorIndex() && this->First.getSize()) {
        this->First.clean();
        QMessageBox::information(this, "Clean", "You delete protein");
    }
    else
        QMessageBox::critical(this,"Clean", "There is no data to clean");
}

// Size
void FirstWindow::on_pushButton_6_clicked() {
    if(this->First.getIteratorIndex() && this->First.getSize()) {
        QMessageBox::information(this, "Size", "The size of the protein is " + QString::number(this->First.getSize()));
    }
    else
        QMessageBox::critical(this,"Size", "There is no protein");
}

// View
void FirstWindow::on_pushButton_7_clicked() {
    if(this->First.getIteratorIndex() && this->First.getSize()) {
        ViewWindow window;
        window.setModal(true);
        window.insertData(this->First, this->First.getSize());
        window.show();
        window.exec();
    }
    else
        QMessageBox::critical(this, "Show", "There is no data to show");
}

// Input from file
void FirstWindow::on_pushButton_8_clicked() {
    this->First.fromFile(ui->lineEdit_6->text().toStdString());
    QMessageBox::information(this, "Input from file", "Success input from file");
}

// Output to file
void FirstWindow::on_pushButton_9_clicked() {
    if(this->First.getIteratorIndex() && this->First.getSize()) {
        this->First.toFile(ui->lineEdit_7->text().toStdString());
        QMessageBox::information(this, "Output to file", "Success output to file");
    }
    else
        QMessageBox::critical(this,"Output to file", "There is no protein");
}

// Back
void FirstWindow::on_pushButton_clicked() {
    QMessageBox::StandardButton save = QMessageBox::question(this, "Save", "Save collection?", QMessageBox::Yes | QMessageBox::No);
    if(save == QMessageBox::No) First.clean();
    saveData(First);
    this->close();
}
