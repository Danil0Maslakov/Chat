#ifndef MAINWINDOWCLIENT_H
#define MAINWINDOWCLIENT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowClient;
}
QT_END_NAMESPACE

class MainWindowClient : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowClient(QWidget *parent = nullptr);
    ~MainWindowClient();

private slots:
    void on_Connect_clicked();

    void on_Send_clicked();

private:
    Ui::MainWindowClient *ui;
};
#endif // MAINWINDOWCLIENT_H
