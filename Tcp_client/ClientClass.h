#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H

#endif // CLIENTCLASS_H

#include<iostream>
#include<WS2tcpip.h>
#include<Windows.h>
#include<string>
#include<QString>
#pragma comment(lib, "Ws2_32.lib")

class Tcp_client{
    WSADATA wsData;
    sockaddr_in clientService;
public:
    SOCKET clientSocket;
    void init();
    void SendMessage(QString str, SOCKET acceptSocket);
    QString ReceiveMessage(SOCKET s);
};
