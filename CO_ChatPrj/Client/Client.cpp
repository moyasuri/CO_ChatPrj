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

using namespace std;

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

const string �α��νõ� = "00";

int chat_recv() {
    char buf[MAX_SIZE] = { };
    string msg;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
            msg = buf;
            std::stringstream ss(msg);  // ���ڿ��� ��Ʈ��ȭ
            string identity_num;
            string text;
            ss >> identity_num >> text; // ��Ʈ���� ����, ���ڿ��� ���� �и��� ������ �Ҵ�. ���� ����� �̸��� user�� �����
        }
        else {
            cout << "Server Off" << endl;
            return -1;
        }
    }
}

vector<string> recv_from_server() {
    char buf[MAX_SIZE] = { };
    string msg;
    vector<string> server_msg;
    server_msg.clear();
    string identify_num;
    string text;

    ZeroMemory(&buf, MAX_SIZE);
    if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
        msg = buf;
        std::stringstream ss(msg);  // ���ڿ��� ��Ʈ��ȭ
        ss >> identify_num >> text;
        server_msg.push_back(identify_num);
        server_msg.push_back(text);
    }
    return server_msg;
}
    
        



class User login_try() {
    while (1) {
        User user;
        string login_id = "";
        string login_pw = "";
        cout << "id�� �Է��ϼ��� : " << endl;
        cin >> login_id;
        cout << "pw�� �Է��ϼ��� : " << endl;
        cin >> login_pw;

        string send_login_id = "00 " + login_id;

        send(client_sock, send_login_id.c_str(), send_login_id.length(), 0);

        vector<string> server_msg = recv_from_server();


        if (server_msg[0] == �α��νõ�) //
        {
            if (server_msg.size() == 1) //id�� �������� �ʾ� server���� 00�� ���۵� ���
            {
                cout << "ID�� �������� �ʽ��ϴ�. "<<endl;
                continue; //������ clear �ϰ� �ٽ� ������ (gui�ƴ� ���)
            }
            else if (server_msg[1] != login_pw) //id�� ���� pw ����ġ
            {
                cout << "��й�ȣ�� ��ġ���� �ʽ��ϴ�. " << endl;
                continue;
            }
            else if (server_msg[1] == login_pw) //�α��� ����
            {
                cout << "�α��ο� �����߽��ϴ�. "<<endl; //�˾����� �߰���?
                user.setMember_ID = login_id;
                user.setMember_PW = login_pw;
                break;
            }
            else // �̻� ����
            {
                cout << "������ �߻��� �����ϰڽ��ϴ�. " << endl;
                break;
            }
        }

        return user;
    }
}


class Client
{
    WSADATA wsa;
    User user;

    //user�� ���� �Է¹ް� class User�� �����ϰ� �����ϱ�
    void correct_userInfo() {
        string inputId;
        string inputEmail;
        string inputPhone;
        string inputBirth;
        string inputNickname;
        string inputPW;
        string inputCha_num;


        cout << "ID�� �Է��ϼ��� " << endl;
        cin >> inputID;
        user.setMember_ID(inputId);

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

            // ������ ���� ���� ���� �κ�
            SOCKADDR_IN client_addr = {};
            client_addr.sin_family = AF_INET;
            client_addr.sin_port = htons(7777);
            InetPton(AF_INET, TEXT("192.168.0.18"), &client_addr.sin_addr);

            while (1) {
                if (!connect(client_info_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // ���� ������ ������ �ش��ϴ� server�� ����!
                    cout << "Server Connect" << endl;
                    for (auto info : getUserInfo(user))
                    {
                        send(client_info_sock, info.c_str(), info.length(), 0); // ���ῡ �����ϸ� client �� �Է��� �г����� ������ ����
                        send(client_info_sock, " ", 1, 0);
                    }
                    break;
                }

                std::thread th2(chat_recv);

                while (1) {
                    string text;
                    std::getline(cin, text);
                    const char* buffer = text.c_str(); // string���� char* Ÿ������ ��ȯ
                    send(client_info_sock, buffer, strlen(buffer), 0);
                }
                th2.join();
                closesocket(client_info_sock);
            }

            WSACleanup();
        }

    }

    
};

        int main() {
            WSADATA wsa;

            // Winsock�� �ʱ�ȭ�ϴ� �Լ�. MAKEWORD(2, 2)�� Winsock�� 2.2 ������ ����ϰڴٴ� �ǹ�.
            // ���࿡ �����ϸ� 0��, �����ϸ� �� �̿��� ���� ��ȯ.
            // 0�� ��ȯ�ߴٴ� ���� Winsock�� ����� �غ� �Ǿ��ٴ� �ǹ�.
            int code = WSAStartup(MAKEWORD(2, 2), &wsa);
            int iclient_menu = 0;

            if (!code) {

                client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); 
                SOCKADDR_IN client_addr = {};
                client_addr.sin_family = AF_INET;
                client_addr.sin_port = htons(7777);
                InetPton(AF_INET, TEXT("127.0.0.1"), &client_addr.sin_addr);



                while (1) {
                    if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // ���� ������ ������ �ش��ϴ� server�� ����!
                        cout << "Server Connect" << endl;
                    }

                    switch (client_func_num(recv_from_server)) {
                    case 1:
                        ;
                        break;
                    case (2):

                    
                    
                    }

                        send(client_sock, my_nick.c_str(), my_nick.length(), 0); // ���ῡ �����ϸ� client �� �Է��� �г����� ������ ����
                        break;
                    }
                    cout << "Connecting..." << endl;
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
            return 0;
        }

