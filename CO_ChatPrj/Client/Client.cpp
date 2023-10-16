#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h> //Winsock ������� include. WSADATA �������.
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <vector>
// user ��� �߰�
#include "User.cpp"


//string���� ������ ��� �޾���� �ϰ� (socket�� char �������θ� ���� ������ c_str ����ؾ� �ϱ� ����) 
//������ ���� �� �������� string���� �ٽ� �޾� int��ȯ �� ó���ؼ� mysql�� �����ش�.
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
            std::stringstream ss(msg);  // ���ڿ��� ��Ʈ��ȭ
            string user;
            ss >> user; // ��Ʈ���� ����, ���ڿ��� ���� �и��� ������ �Ҵ�. ���� ����� �̸��� user�� �����.
            if (user != my_nick) cout << buf << endl; // ���� ���� �� �ƴ� ��쿡�� ����ϵ���.
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

    //user�� ���� �Է¹ް� class User�� �����ϰ� �����ϱ�
    void input_user() {
        string inputId;
        string inputEmail;
        string inputPhone;
        string inputBirth;
        string inputNickname;
        string inputPW;
        string inputCha_num;

        cout << "ID�� �Է��ϼ��� " << endl;
        cin >> inputID;
        user.setMember_ID(inputID);

        cout << "�̸����� �Է��ϼ��� " << endl;
        cin >> inputEmail;
        user.setEmail(inputEmail);

        cout << "��ȭ��ȣ�� �Է��ϼ���\n (010-0000-0000 ����) " << endl;
        cin >> inputPhone;
        user.setPhone(inputPhone);

        cout << "�ֹι�ȣ �� 6�ڸ��� �Է��ϼ���. " << endl;
        cin >> inputBirth;
        user.setBirth(inputBirth);

        cout << "�г����� �Է��ϼ��� " << endl;
        cin >> inputNickname;
        user.setNickname(inputNickname);

        cout << "��й�ȣ�� �Է��ϼ��� " << endl;
        cin >> inputPW;
        user.setMember_PW(inputPW);

        cout << "ĳ���� ��ȣ�� �Է��ϼ��� " << endl;
        cin >> inputCha_num;
        user.setCha_num(inputCha_num);


    }

    //user�� �������� �ڵ����� �����ֱ� ���� ���Ϳ� ������ �ش�.
    vector<string> getUserInfo(User user1) {
        vector <string> userinfo;
        userinfo.clear();

        userinfo.push_back(user1.getMember_ID);
        userinfo.push_back(user1.getEmail());
        userinfo.push_back(user1.getPhone());
        userinfo.push_back(user1.getBirth());
        userinfo.push_back(user1.getNickname);
        userinfo.push_back(user1.getCha_num);
        userinfo.push_back(user1.getMember_PW);
        userinfo.push_back(user1.getJoin_room_index);

        return userinfo;
    }

    void runCreateAccount() {
        int code = WSAStartup(MAKEWORD(2, 2), &wsa);

        if (!code) {
            client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 

            // ������ ���� ���� ���� �κ�
            SOCKADDR_IN client_addr = {};
            client_addr.sin_family = AF_INET;
            client_addr.sin_port = htons(7777);
            InetPton(AF_INET, TEXT("192.168.0.18"), &client_addr.sin_addr);

            while (1) {
                if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // ���� ������ ������ �ش��ϴ� server�� ����!
                    cout << "Server Connect" << endl;
                    for (auto info : getUserInfo(user))
                        send(client_sock, info.c_str(), my_nick.length(), 0); // ���ῡ �����ϸ� client �� �Է��� �г����� ������ ����
                    break;
                }

            }

            std::thread th2(chat_recv);

            while (1) {
                string text;
                std::getline(cin, text);
                const char* buffer = text.c_str(); // string���� char* Ÿ������ ��ȯ
                send(client_sock, buffer, strlen(buffer), 0);
            }
            th2.join();
            closesocket(client_sock);
        }

        WSACleanup();
    }



