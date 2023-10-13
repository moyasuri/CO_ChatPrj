#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h> //Winsock 헤더파일 include. WSADATA 들어있음.
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>


#include "MyForm.h"
#include "MainForm.h"


#define MAX_SIZE 1024
using namespace System;
using namespace System::Windows::Forms;



using std::cout;
using std::cin;
using std::endl;
using std::string;


int chat_recv() {
    char buf[MAX_SIZE] = { };
    string msg;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
            msg = buf;
            std::stringstream ss(msg);  // 문자열을 스트림화
            string user;
            ss >> user; // 스트림을 통해, 문자열을 공백 분리해 변수에 할당. 보낸 사람의 이름만 user에 저장됨.
            if (user != my_nick) cout << buf << endl; // 내가 보낸 게 아닐 경우에만 출력하도록.
        }
        else {
            cout << "Server Off" << endl;
            return -1;
        }
    }
}

void CommunicateWithServer() {
    // WinSock 초기화
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        std::cout << "Failed to initialize WinSock" << std::endl;
        return;
    }

    // 소켓 생성 및 설정
    client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKADDR_IN client_addr = {};
    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(7777);
    InetPton(AF_INET, TEXT("192.168.67.227"), &client_addr.sin_addr);

    // 서버에 연결

    // myform에서 닉네임을 설정하도록
    while (1)
    {
        if (my_nick != "")
        {
            break;
        }

        // 데이터 송수신 로직
        while (1) {
            if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // 위에 설정한 정보에 해당하는 server로 연결!
                cout << "Server Connect" << endl;
                send(client_sock, my_nick.c_str(), my_nick.length(), 0); // 연결에 성공하면 client 가 입력한 닉네임을 서버로 전송
                break;
            }

            // cout << "Connecting..." << endl;
        }

        std::thread th2(chat_recv);

        while (1) {
            string text;
            std::getline(cin, text);
            const char* buffer = text.c_str(); // string형을 char* 타입으로 변환
            send(client_sock, buffer, strlen(buffer), 0);
        }
        th2.join();


        closesocket(client_sock);
        // 연결 종료



        // WinSock 정리
        WSACleanup();
    }
}



[STAThread]


void main(array<String^>^ args) {
			
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUI::MyForm form;

    // 통신 작업을 처리할 스레드 생성 및 실행
    std::thread communicationThread(CommunicateWithServer);
    communicationThread.detach();  // 메인 스레드와 분리하여 실행

	Application::Run(% form);





}