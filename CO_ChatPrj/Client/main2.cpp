#include "stdafx.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "ws2_32.lib")

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        return 1;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create client socket" << std::endl;
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // 서버의 포트 번호
    InetPton(AF_INET, L"127.0.0.1", &serverAddr.sin_addr); // 서버의 IP 주소

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Failed to connect to the server" << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Connected to the server. Type 'exit' to quit." << std::endl;

    char buffer[1024];
    std::string message;

    while (true) {
        std::getline(std::cin, message);
        if (message == "exit") {
            break;
        }

        send(clientSocket, message.c_str(), message.length(), 0);

        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesReceived == 0) {
            std::cerr << "Server disconnected" << std::endl;
            break;
        }
        else if (bytesReceived == SOCKET_ERROR) {
            std::cerr << "Error in recv" << std::endl;
            break;
        }

        buffer[bytesReceived] = '\0';
        std::cout << "Server says: " << buffer << std::endl;
    }

    closesocket(clientSocket);
    WSACleanup();

    return 0;
}