#include "mainwindowserver.h"
#include "./ui_mainwindowserver.h"
#include "ServerClass.h"
#include<thread>
Tcp_server server(1);
std::thread session(server.init,&server,1);
MainWindowserver::MainWindowserver(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowserver)
{
    ui->setupUi(this);
}

MainWindowserver::~MainWindowserver()
{
    delete ui;
}






void acc(Tcp_server& server){
    session.join();
    server.acceptSocket = accept(server.serverSocket,NULL,NULL);
    if (server.acceptSocket == INVALID_SOCKET) {
        std::cout << "accept() failed, ERROR# " << WSAGetLastError() << std::endl;
        WSACleanup();
        exit(-1);
    }
}




void MainWindowserver::on_Connect_clicked()
{
    std::thread t(acc, std::ref(server));
    t.detach();
}


std::mutex mut;

void MainWindowserver::on_Send_clicked()
{
    std::thread Mess([&]{
        mut.lock();
        QString rec_text = server.ReceiveMessage(server.acceptSocket);
        ui->textBrowser->append(rec_text);
        mut.unlock();
    });
    Mess.detach();
    QString mess_text = ui->Message->text();
    ui->textBrowser->append(mess_text);
    server.SendMessage(mess_text,server.getaccSocket());
    ui->Message->clear();
}

