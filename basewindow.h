#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BaseWindow; }
QT_END_NAMESPACE

class BaseWindow : public QMainWindow
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = nullptr);
    ~BaseWindow();

private:
    Ui::BaseWindow *ui;
};
#endif // BASEWINDOW_H
