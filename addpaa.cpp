#include "addpaa.h"
#include "ui_addpaa.h"
#include "Protein.h"
#include "ProteinogenicAminoAcid.h"
#include <fstream>
#include <QMessageBox>

AddPaa::AddPaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPaa) {
    ui->setupUi(this);
}

AddPaa::~AddPaa() {
    delete ui;
}

void savePaa(string name, string pos, string symbol) {
    ofstream fout("saveAa.txt", std::ofstream::out | std::ofstream::trunc);
    fout << name << " " << pos << " " << symbol << endl;
    fout.close();
}

// Add paa to pos
void AddPaa::on_pushButton_clicked() {
    std:: string name  = ui->lineEdit->text().toStdString();
    std:: string symbol  = ui->lineEdit_2->text().toStdString();
    std:: string pos  = ui->lineEdit_3->text().toStdString();
    if (name == "")
        QMessageBox::critical(this, "Add paa", "Name is empty");
    else if (symbol == "")
        QMessageBox::critical(this, "Add paa", "Symbol is empty");
    else if ((symbol[0]<65)||(symbol[0]>90))
        QMessageBox::critical(this, "Add paa", "The symbol must be a capital latin letter");
    else if (pos == "")
        QMessageBox::critical(this, "Add paa", "Position is empty");
    else savePaa(name, pos, symbol), this->close();
}

// Add paa to Head
void AddPaa::on_pushButton_2_clicked() {
    std:: string name  = ui->lineEdit->text().toStdString();
    std:: string symbol  = ui->lineEdit_2->text().toStdString();
    string pos = "Head";
    if (name == "")
        QMessageBox::critical(this,"Add paa", "Name is empty");
    else if (symbol == "")
        QMessageBox::critical(this,"Add paa", "Symbol is empty");
    else if ((symbol[0]<65)||(symbol[0]>90))
        QMessageBox::critical(this,"Add paa", "The symbol must be a capital latin letter");
    else savePaa(name, pos, symbol), this->close();
}

// Add paa to Tail
void AddPaa::on_pushButton_3_clicked() {
    std:: string name  = ui->lineEdit->text().toStdString();
    std:: string symbol  = ui->lineEdit_2->text().toStdString();
    string pos = "Tail";
    if (name == "")
        QMessageBox::critical(this,"Add paa", "Name is empty");
    else if (symbol == "")
        QMessageBox::critical(this,"Add paa", "Symbol is empty");
    else if ((symbol[0]<65)||(symbol[0]>90))
        QMessageBox::critical(this,"Add paa", "The symbol must be a capital latin letter");
    else savePaa(name, pos, symbol), this->close();
}

void AddPaa::on_pushButton_4_clicked() {
    this->close();
}
