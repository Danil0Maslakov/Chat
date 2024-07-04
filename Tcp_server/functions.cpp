#include "ServerClass.h"

using namespace std;
Tcp_server::Tcp_server(int amount_of_connections) :amount_of_connections{ amount_of_connections } {


}


void Tcp_server::HandleConnection(SOCKET s, int amount_of_connections) {

    ReceiveMessage(acceptSocket);
    //SendMessage(acceptSocket);
}

void Tcp_server::SendMessage(QString str,SOCKET acceptSocket){

    QByteArray arr;
    arr.clear();
    arr = str.toLocal8Bit();

    char* buf = arr.data();


    if(acceptSocket == AF_UNSPEC)std::cout<<"Not socket...\n";

    int BytesCount = send(acceptSocket, buf, arr.size(), 0);
    if (BytesCount == SOCKET_ERROR) {
        printf("Server sent error %ld", WSAGetLastError());
        exit(-1);
    }
    else {
        printf("Server sent %ld bytes\n", BytesCount);
    }

}

QString Tcp_server::ReceiveMessage(SOCKET s) {
    char receive_buffer[200];
    char out_buffer[200];
    int byteCount = recv(s, receive_buffer, 200, 0);
    if(byteCount==5)byteCount--;
    if (byteCount < 0) {
        printf("recv() failed, ERROR #%dl occured...", WSAGetLastError());
        exit(-1);
    }
    else {
        for(int i=0;i<byteCount;i++){out_buffer[i]=receive_buffer[i];}
        QString out = QString::fromLocal8Bit(out_buffer);
        return out;
    }
}

SOCKET Tcp_server::getaccSocket() {
    return this->acceptSocket;
}

int Tcp_server::get_amount_of_connections() {
    return amount_of_connections;
}

void Tcp_server::lisacc(){}

void Tcp_server::init(int amount_of_connections){
    int wsaerr;
    std::mutex mut;
    WORD wVersionRequired = MAKEWORD(2, 2);
    wsaerr = WSAStartup(wVersionRequired, &wsaData);

    if (wsaerr != 0) {
        std::cout << WSAGetLastError() << std::endl;
    }
    std::cout << "The winsock dll is found!" << std::endl;
    std::cout << "The status: " << wsaData.szSystemStatus << std::endl;




    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cout << "socket() failed, Error #" << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
    }
    std::cout << "socket() is OK!" << std::endl;





    std::string m_address = "192.168.0.103";

    service.sin_family = AF_INET;
    inet_pton(AF_INET, m_address.c_str(), &service.sin_addr.s_addr);
    service.sin_port = htons(8080);
    u_long iMode = 1;
    int iResult = ioctlsocket(acceptSocket, FIONBIO,&iMode);

    if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR)
    {
        std::cout << "bind() failed, Error #" << WSAGetLastError() << std::endl;
        closesocket(serverSocket);
        WSACleanup();
    }
    std::cout << "bind() is OK!" << std::endl;


    //const std::lock_guard<std::mutex>l(mut);
    if (listen(serverSocket, amount_of_connections) == SOCKET_ERROR) {
        std::cout << "Listening error# " << WSAGetLastError() << std::endl;
    }

    else {
        std::cout << "listen() is OK, waiting for connections..." << std::endl;
    }


    printf("Gyatt");
}
