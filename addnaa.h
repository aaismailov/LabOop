#ifndef ADDNAA_H
#define ADDNAA_H

#include <QDialog>
#include "NonstandardAminoAcid.h"

namespace Ui {
class AddNaa;
}

class AddNaa : public QDialog
{
    Q_OBJECT

public:
    explicit AddNaa(QWidget *parent = nullptr);
    ~AddNaa();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::AddNaa *ui;
};

#endif // ADDNAA_H
