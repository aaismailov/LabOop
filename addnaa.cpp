#include "addnaa.h"
#include "ui_addnaa.h"
#include "Protein.h"
#include "NonstandardAminoAcid.h"
#include <fstream>
#include <QMessageBox>

AddNaa::AddNaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNaa)
{
    ui->setupUi(this);
}

AddNaa::~AddNaa()
{
    delete ui;
}

void saveNaa(string name, string pos){
    ofstream fout("saveAa.txt", std::ofstream::out | std::ofstream::trunc);
    fout << name << " " << pos << endl;
    fout.close();
}

// Add naa to pos
void AddNaa::on_pushButton_clicked()
{
    std:: string name  = ui->lineEdit_4->text().toStdString();
    std:: string pos  = ui->lineEdit_3->text().toStdString();
    if (name == "") {
        QMessageBox::critical(this,"Add naa", "Name is empty");
    } else {
        saveNaa(name, pos);
    }
}

// Add naa to Head
void AddNaa::on_pushButton_2_clicked()
{
    std:: string name  = ui->lineEdit_4->text().toStdString();
    string pos = "Head";
    if (name == "") {
        QMessageBox::critical(this,"Add naa", "Name is empty");
    } else {
        saveNaa(name, pos);
    }
}

// Add naa to Tail
void AddNaa::on_pushButton_3_clicked()
{
    std:: string name  = ui->lineEdit_4->text().toStdString();
    string pos = "Tail";
    if (name == ""){
        QMessageBox::critical(this,"Add naa", "Namee is empty");
    } else {
        saveNaa(name, pos);
    }
}

void AddNaa::on_pushButton_4_clicked()
{
    this->close();
}
