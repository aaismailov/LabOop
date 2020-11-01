#ifndef ADDPAA_H
#define ADDPAA_H

#include <QDialog>

namespace Ui {
class AddPaa;
}

class AddPaa : public QDialog
{
    Q_OBJECT

public:
    explicit AddPaa(QWidget *parent = nullptr);
    ~AddPaa();

private:
    Ui::AddPaa *ui;
};

#endif // ADDPAA_H
