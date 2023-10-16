#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h> //Winsock 헤더파일 include. WSADATA 들어있음.
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <vector>
// user 헤더 추가
#include "User.cpp"

using namespace std;

//string으로 정보를 모두 받아줘야 하고 (socket에 char 형식으로만 전달 가능해 c_str 사용해야 하기 때문) 
//서버에 전달 후 서버에서 string으로 다시 받아 int변환 등 처리해서 mysql로 보내준다.
#define MAX_SIZE 1024

using std::cout;
using std::cin;
using std::endl;
using std::string;

SOCKET client_sock;
SOCKET client_info_sock;
string my_nick;

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



class Client
{
    WSADATA wsa;
    User user;

    //user의 정보 입력받고 class User에 안전하게 저장하기
    void input_user() {
        string inputId;
        string inputEmail;
        string inputPhone;
        string inputBirth;
        string inputNickname;
        string inputPW;
        string inputCha_num;
   

        cout << "ID를 입력하세요 " << endl;
        cin >> inputID;
        user.setMember_ID(inputID);

        cout << "이메일을 입력하세요 " << endl;
        cin >> inputEmail;
        user.setEmail(inputEmail);

        cout << "전화번호를 입력하세요\n (010-0000-0000 형식) " << endl;
        cin >> inputPhone;
        user.setPhone(inputPhone);

        cout << "주민번호 앞 6자리를 입력하세요. " << endl;
        cin >> inputBirth;
        user.setBirth(inputBirth);

        cout << "닉네임을 입력하세요 " << endl;
        cin >> inputNickname;
        user.setNickname(inputNickname);

        cout << "비밀번호를 입력하세요 " << endl;
        cin >> inputPW;
        user.setMember_PW(inputPW);

        cout << "캐릭터 번호를 입력하세요 " << endl;
        cin >> inputCha_num;
        user.setCha_num(inputCha_num);


    }

    //user의 정보들을 자동으로 돌려주기 위해 벡터에 저장해 준다.
    vector<string> getUserInfo(User user1) {
        vector <string> userinfo;
        userinfo.clear();

        userinfo.push_back(user1.getMember_ID());
        userinfo.push_back(user1.getEmail());
        userinfo.push_back(user1.getPhone());
        userinfo.push_back(user1.getBirth());
        userinfo.push_back(user1.getNickname());
        userinfo.push_back(user1.getCha_num());
        userinfo.push_back(user1.getMember_PW());
        userinfo.push_back(user1.getJoin_room_index());

        return userinfo;
    }

    void runCreateAccount() {
        int code = WSAStartup(MAKEWORD(2, 2), &wsa);

        if (!code) {
            client_info_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 

            // 연결할 서버 정보 설정 부분
            SOCKADDR_IN client_addr = {};
            client_addr.sin_family = AF_INET;
            client_addr.sin_port = htons(7777);
            InetPton(AF_INET, TEXT("192.168.0.18"), &client_addr.sin_addr);

            while (1) {
                if (!connect(client_info_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // 위에 설정한 정보에 해당하는 server로 연결!
                    cout << "Server Connect" << endl;
                    for (auto info : getUserInfo(user))
                    {
                        send(client_info_sock, info.c_str(), info.length(), 0); // 연결에 성공하면 client 가 입력한 닉네임을 서버로 전송
                        send(client_info_sock, " ", 1, 0);
                    }
                    break;
            }

            std::thread th2(chat_recv);

            while (1) {
                string text;
                std::getline(cin, text);
                const char* buffer = text.c_str(); // string형을 char* 타입으로 변환
                send(client_info_sock, buffer, strlen(buffer), 0);
            }
            th2.join();
            closesocket(client_info_sock);
        }

        WSACleanup();
    }

        void login() {
            string login_id;
            string login_pw;
            cout << "id를 입력하세요 : " << endl;

        }

        int main() {
            WSADATA wsa;

            // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
            // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
            // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
            int code = WSAStartup(MAKEWORD(2, 2), &wsa);

            if (!code) {
                cout << "사용할 닉네임 입력 >> ";
                cin >> my_nick;

                client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 

                // 연결할 서버 정보 설정 부분
                SOCKADDR_IN client_addr = {};
                client_addr.sin_family = AF_INET;
                client_addr.sin_port = htons(7777);
                InetPton(AF_INET, TEXT("127.0.0.1"), &client_addr.sin_addr);

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
            return 0;
        }

