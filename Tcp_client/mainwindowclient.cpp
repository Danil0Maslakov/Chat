
#include "mainwindowclient.h"
#include "./ui_mainwindowclient.h"
#include "ClientClass.h"
#include<thread>
#include<mutex>
Tcp_client client;
std::thread session(client.init,&client);

MainWindowClient::MainWindowClient(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowClient)
{
    ui->setupUi(this);
}

MainWindowClient::~MainWindowClient()
{
    delete ui;
}

void MainWindowClient::on_Connect_clicked()
{
    session.join();
    std::mutex mut;
    std::thread Mess([&]
    {
    while(true)
    {
        // mut.lock();
        QString mess_text = client.ReceiveMessage(client.clientSocket);
        ui->textBrowser->append(mess_text);
        //mut.unlock();
    }
    });
    Mess.detach();
}


void MainWindowClient::on_Send_clicked()
{
    std::mutex mut;
    std::thread Mess([&]{
        mut.lock();
        QString mess_text = ui->Message->text();
        ui->textBrowser->append(mess_text);
        client.SendMessage(mess_text,client.clientSocket);
        ui->Message->clear();
        mut.unlock();
    });
    Mess.detach();
}

