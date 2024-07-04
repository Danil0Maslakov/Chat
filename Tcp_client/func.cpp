#include "ClientClass.h"

void Tcp_client::SendMessage(QString str, SOCKET clientSocket){
    QByteArray arr = str.toLocal8Bit();
    const char* buf = arr.data();
    int BytesCount = send(clientSocket, buf, arr.size(), 0);
    if (BytesCount == SOCKET_ERROR) {
        printf("Server sent error %ld", WSAGetLastError());
        exit(-1);
    }
    else {
        printf("Client sent %ld bytes\n", BytesCount);
    }
}


QString Tcp_client::ReceiveMessage(SOCKET s) {
    char receive_buffer[200];
    int byteCount = recv(s, receive_buffer, 200, 0);
    if (byteCount < 0) {
        printf("recv() failed, ERROR #%dl occured...", WSAGetLastError());
        exit(-1);
    }
    else {
        QString out = QString::fromLocal8Bit(receive_buffer);
        return out;
    }
}

void Tcp_client::init(){
    WORD wVersionRequested = MAKEWORD(2, 2);
    int wsaerr;
    wsaerr = WSAStartup(wVersionRequested, &wsData);
    if (wsaerr != 0) {
        std::cout << "WSAStartup() error" << std::endl;
        exit(-1);
    }

    clientSocket = INVALID_SOCKET;
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        std::cout << "socket initialisation error " << WSAGetLastError()<<std::endl;
        exit(-1);
    }
    std::string m_address = "192.168.0.103";
    clientService.sin_family = AF_INET;
    inet_pton(AF_INET, m_address.c_str(), &clientService.sin_addr.s_addr);
    clientService.sin_port = htons(8080);
    if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
        std::cout << "connect() failed, Error #" << WSAGetLastError() << std::endl;
        exit(-1);
    }
    else {
        std::cout << "client: connect is OK." << std::endl;
        std::cout << "client: can start sending and receiving data..." << std::endl;
    }
}
