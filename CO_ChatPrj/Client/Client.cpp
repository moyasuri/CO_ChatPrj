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
const string IDã�� = "01";
const string PWã�� = "02";


//const string ���� ����= "10";
const string ��й�ȣ���� = "11";
const string �̸��ϼ��� = "12";
const string ��ȭ��ȣ����="13";
const string ������ϼ��� = "14";
const string �г��Ӽ���= "15";
const string ĳ���ͼ���= "16";
const string �����溯�� = "17";

//const string ģ�� = "20";

const string ģ�����= "21";
const string ģ����û= "22";
const string ģ���˻�= "23";
const string ģ����û= "24";
//const string = "";
//const string = "";
//const string = "";

//const string ���� //ģ���˻� ���� 30
const string ������� = "31";
const string �����б�= "32";
const string ����������= "33";
const string ���������ϱ�= "34";


//���� 
//
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";
//const string = "";

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
        ss >> identify_num ;
        server_msg.push_back(identify_num);
        text = string(buf + 3);
        server_msg.push_back(text);
    }
    return server_msg;
}

void login_try() {
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
                user.setMember_ID(login_id);
                user.setMember_PW(login_pw);
                break;
            }
            else // �̻� ����
            {
                cout << "������ �߻��� �����ϰڽ��ϴ�. " << endl;
                break;
            }
        }
    }
}

const string ģ����� = "21";
const string ģ����û = "22";
const string ģ���˻� = "23";
const string ģ����û = "24";

void friend_home() {
    vector<string> friend_list;
        vector<string> friends= recv_from_server();
    if (friends[0] == ģ�����)
    {
        friends[1];
        string s;
        std::stringstream ss(friends[1]);
        while( ss >> s){
            friend_list.push_back(s);
        }

    }
    else if (friends[0] == ģ����û)
    {

    }
    else if (friends[0] == ģ���˻�)
    {

    }
    else if (friends[0] == ģ����û)
    {

    }
    else
        cout << "���� �߻�" << endl;


}
    //WSADATA wsa;
    //User user;

    //user�� ���� �Է¹ް� class User�� �����ϰ� �����ϱ�
//ȸ������,ȸ������
    void create_userInfo() {
        User user;
        string inputID;
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
    string getUserInfo(User user1) {
        string userinfo = "";
        userinfo.clear();

        userinfo = user1.getMember_ID + " " +
            user1.getEmail + " " + user1.getPhone + " " + user1.getBirth +
            user1.getNickname + " " + user1.getCha_num + " " + user1.getMember_PW + " " + user1.getJoin_room_index;
    


        return userinfo;
    }


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
            
            WSACleanup();
            return 0;
        }

