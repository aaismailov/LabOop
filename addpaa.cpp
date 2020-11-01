#include "addpaa.h"
#include "ui_addpaa.h"

AddPaa::AddPaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPaa)
{
    ui->setupUi(this);
}

AddPaa::~AddPaa()
{
    delete ui;
}
