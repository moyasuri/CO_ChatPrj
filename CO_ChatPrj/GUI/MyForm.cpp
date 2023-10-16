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
            temp_socket = msg;
            // std::stringstream ss(msg);  // 문자열을 스트림화
            string user;
            // ss >> user; // 스트림을 통해, 문자열을 공백 분리해 변수에 할당. 보낸 사람의 이름만 user에 저장됨.
            // if (user != my_nick) cout << buf << endl; // 내가 보낸 게 아닐 경우에만 출력하도록.
        }
        else {
            cout << "Server Off" << endl;
            return -1;
        }
    }
}

void CommunicateWithServer() {
    WSADATA wsa;
    my_nick = "abc";

    // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
    // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
    // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
    int code = WSAStartup(MAKEWORD(2, 2), &wsa);

    if (!code) {
        cout << "사용할 닉네임 입력 >> ";
        cin >> my_nick;

        // PF_INET : 프로토콜 familiy IPv4 인터넷 프로토콜을 사용
        // SOCK_STREAM: 소켓 유형(socket type)을 나타냅니다. 
        // SOCK_STREAM은 TCP(Transmission Control Protocol) 기반의 연결 지향형 소켓을 생성함을 의미합니다.
        // TCP는 신뢰성 있는 데이터 전송을 제공하며, 연결 지향형으로 동작하여 데이터가 순서대로 전달됩니다.
        // IPPROTO_TCP: 프로토콜(protocol)을 나타냅니다. IPPROTO_TCP는 TCP 프로토콜을 사용함을 의미합니다.
        client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 

        // 연결할 서버 정보 설정 부분
        SOCKADDR_IN client_addr = {};
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(7777);
        InetPton(AF_INET, TEXT("127.0.0.1"), &client_addr.sin_addr);

        // AF_INTE 과 PF_INET은 정확히 동일한 의미

        while (1) {
            if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // 위에 설정한 정보에 해당하는 server로 연결!
                cout << "Server Connect" << endl;
                send(client_sock, my_nick.c_str(), my_nick.length(), 0); // 연결에 성공하면 client 가 입력한 닉네임을 서버로 전송
                break;
            }
            cout << "Connecting..." << endl;
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
    }
    WSACleanup();
}





[STAThread]


void main(array<String^>^ args) {
			
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUI::MyForm form;

    // 통신 작업을 처리할 스레드 생성 및 실행
    std::thread communicationThread(CommunicateWithServer);
    // communicationThread.detach();  // 메인 스레드와 분리하여 실행

	Application::Run(% form);

    Sleep(1000);


}