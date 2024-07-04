#ifndef SERVERCLASS_H
#define SERVERCLASS_H

#endif // SERVERCLASS_H
#pragma once

#include<iostream>
#include<WS2tcpip.h>
#include<Windows.h>
#include<string>
#include<QString>
#include<mutex>
#include<thread>
class Tcp_server {
    WSADATA wsaData;

    int amount_of_connections;
    sockaddr_in service;

public:
    SOCKET serverSocket, acceptSocket;
    Tcp_server(int amount_of_connections);
    void SendMessage(QString str, SOCKET acceptSocket);
    QString ReceiveMessage(SOCKET s);
    void HandleConnection(SOCKET s, int amount_of_connections);
    SOCKET getaccSocket();
    int get_amount_of_connections();
    void init(int amount_of_connections);
    void lisacc();
};
