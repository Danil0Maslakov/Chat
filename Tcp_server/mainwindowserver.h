#ifndef MAINWINDOWSERVER_H
#define MAINWINDOWSERVER_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowserver;
}
QT_END_NAMESPACE

class MainWindowserver : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowserver(QWidget *parent = nullptr);
    ~MainWindowserver();

private slots:
    void on_Connect_clicked();

    void on_Send_clicked();

private:
    Ui::MainWindowserver *ui;
};
#endif // MAINWINDOWSERVER_H
