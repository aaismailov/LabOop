#ifndef ADDNAA_H
#define ADDNAA_H

#include <QDialog>

namespace Ui {
class AddNaa;
}

class AddNaa : public QDialog
{
    Q_OBJECT

public:
    explicit AddNaa(QWidget *parent = nullptr);
    ~AddNaa();

private:
    Ui::AddNaa *ui;
};

#endif // ADDNAA_H
