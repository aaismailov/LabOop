#include "addnaa.h"
#include "ui_addnaa.h"

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
