#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QDialog>
#include "Protein.h"

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewWindow(QWidget *parent = nullptr);
    void insertData(Protein* collection, int size) const;
    ~ViewWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ViewWindow *ui;
};

#endif // VIEWWINDOW_H
