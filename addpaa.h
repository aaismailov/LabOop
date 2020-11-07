#ifndef ADDPAA_H
#define ADDPAA_H

#include <QDialog>
#include "ProteinogenicAminoAcid.h"

namespace Ui {
class AddPaa;
}

class AddPaa : public QDialog
{
    Q_OBJECT

public:
    explicit AddPaa(QWidget *parent = nullptr);
    ~AddPaa();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
private:
    Ui::AddPaa *ui;
};

#endif // ADDPAA_H
