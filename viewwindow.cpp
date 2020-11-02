#include "viewwindow.h"
#include "ui_viewwindow.h"
#include "Protein.h"
#include <QStandardItem>
#include <QStandardItemModel>

ViewWindow::ViewWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewWindow)
{
    ui->setupUi(this);
}

ViewWindow::~ViewWindow()
{
    delete ui;
}

void ViewWindow::on_pushButton_clicked()
{
    hide();
}

void ViewWindow::insertData(Protein collection, int size) const
{
    QStandardItemModel *model = new QStandardItemModel;
    QStandardItem *item;
    for (int i = 0; i < size;i++)
    {
        item = new QStandardItem(QString("#" + QString::number(i+1)));
        collection.setIteratorIndex(i+1);
        model->appendRow(item);
        item = new QStandardItem(QString(QString::fromStdString(collection.getIteratorValue().getName())));
        model->appendRow(item);
        if (collection.getIteratorValue().getSymbol()=='\0'){
            item = new QStandardItem(QString("   "));
            model->appendRow(item);
        } else {
            item = new QStandardItem(QString(QString::fromStdString(std::string(1, collection.getIteratorValue().getSymbol()))));
            model->appendRow(item);
            item = new QStandardItem(QString("   "));
            model->appendRow(item);
        }
    }
    ui->listView->setModel(model);
}
