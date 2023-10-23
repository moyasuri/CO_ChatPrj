/*
send �� receive�� ������ ¦��
*/
#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h> //Winsock ������� include. WSADATA �������.
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <vector>
// user ��� �߰�
#include "Usage.h"



using namespace std;



//string���� ������ ��� �޾���� �ϰ� (socket�� char �������θ� ���� ������ c_str ����ؾ� �ϱ� ����) 
//������ ���� �� �������� string���� �ٽ� �޾� int��ȯ �� ó���ؼ� mysql�� �����ش�.
#define MAX_SIZE 1024

using std::cout;
using std::cin;
using std::endl;
using std::string;

SOCKET client_sock;
;
string my_nick;

string send_UserInfo();

const string True = "True";
const string False = "False";



int chat_recv() {
    char buf[MAX_SIZE] = { };
    string msg;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
            msg = string(buf+3);
            // ��Ʈ���� ����, ���ڿ��� ���� �и��� ������ �Ҵ�. ���� ����� �̸��� user�� �����
            cout << msg<<endl;
        }
        else {
            cout << "Server Off" << endl;
            return -1;
        }
    }
}


vector<string> recv_from_server() {
    char buf[MAX_SIZE] = { };
    string _Contents = buf;
    string _Index;
    string TF;
    vector<string> server_msg;
    server_msg.clear();
    string msg;
    std::stringstream ss(msg);
    ss >> _Index>>TF>>_Contents;
    server_msg.push_back(_Index);
    server_msg.push_back(_Contents);
    int _Index_I = stoi(_Index);
    //switch (_Index_I)
    //{
    //case e_try_Signin:
    //{
    //    if (e_find_ID)
    //    {
    //    }
    //}
    //break;
    //case e_find_ID:
    //{
    //}
    //break;
    //}}

    return server_msg;
}

vector<string> recv_list(string recv_text) {
    string s;
    vector<string> recv_list;
        std::stringstream ss(recv_text);
        while (ss >> s)
            recv_list.push_back(s);
        return recv_list;

}

void show_vector_list(vector<string> vector) {

    

}

string want_exit() { //�޴� �ݱ� while������ ������ش�.
    char answer;
    cout << "�� ȭ���� �ݱ⸦ ���մϱ�? (Y/N) " << endl;
    while (1) {
        cin >> answer;
        if (answer == 'Y')
        {
            return "break;";
            break;
        }
        else if (answer == 'N')
            break;
        else
            cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �õ��� �ּ��� .";
    }
}

void send_to_server_const(const string buffer)
{
    send(client_sock, buffer.c_str(), strlen(buffer.c_str()), 0);
}

void send_to_server(string buffer) 
//��ȣ�� ������ ��� buffer�� const���� �����ָ� �ȴ�.
//���뵵 ������ ��� buffer�� ������ ����Ѵ�.
{
    send(client_sock, buffer.c_str(), strlen(buffer.c_str()), 0);
}

const string �α��νõ� = "00"; //send_id / recv_pw

void login_try() {
    while (1) {
        want_exit();
        
        string login_id = "";
        string login_pw = "";
        cout << "id�� �Է��ϼ��� : " << endl;
        cin >> login_id;
        cout << "pw�� �Է��ϼ��� : " << endl;
        cin >> login_pw;

        string send_try_login = �α��νõ� +" "+ login_id + " " + login_pw;
        send_to_server(send_try_login);

        vector<string> server_msg = recv_from_server();
        if (server_msg[0] == �α��νõ�) //
        {
            if (server_msg[1] == False) 
            {
                cout << "ID�� PW�� Ʋ�Ƚ��ϴ�. "<<endl;
                continue; //������ clear �ϰ� �ٽ� ������ (gui�ƴ� ���)
            }
            
            else if (server_msg[1] == True) //�α��� ����
            {
                cout << "�α��ο� �����߽��ϴ�. "<<endl; //�˾����� �߰���?
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




/*se
    ģ�� ����� �׻� ������
   ģ����û��ư�� ������ ��û�� ģ�� ����� ���̰� ���� ������ �Ҽ�����
   ģ���߰���ư�� ������ ������ ���̵� �˻��ؼ� ģ�� ��û�� ���� �� ���� 
   ��� ȭ�鿡�� �ݱ� ��ư�� ������
*/

void friend_home() {
    while (1) {
        vector<string> friend_home;
        vector<string> friend_list; // ģ�� ���̺� �޾ƿͼ� ���� ���� �����ϴ� ����
        friend_home.clear();
        friend_list.clear();
        vector<string> friend_request;
        vector<string> friend_request_list; //������ �� ģ�� ��û ����Ʈ
        friend_request_list.clear();
        friend_request.clear();
        vector<string>;

        send_to_server(" ");
        friend_home = recv_from_server();
        string recv_friend_home_num = friend_home[0];
        string recv_friend_home_text = friend_home[1];


        if (recv_friend_home_num == "")
        {
            if (recv_friend_home_num =="") {
                while (1) {
                    while (1) {
                        friend_list = recv_list(recv_friend_home_text);
                        show_vector_list(friend_list);
                        //ģ������� �⺻�������� �����ִ�
                             //���̺�ó�� ���̰� �ٽ� �ٲ���� �Ѵ� -_-
                        string friend_num = ""; //������� ����
                        cout << "ģ�� Ȩ���� �ϰ� ���� �޴� ���� " << endl;
                        cin >> friend_num;

                        if (friend_num == "ģ����û_Ŭ")
                        {

                            send_to_server("ģ����û_Ŭ" );
                            friend_request = recv_from_server();
                            if (friend_request[0] == "ģ����û_��")
                            {



                            }
                        }


                        else if (friend_num == "ģ���˻�_Ŭ")
                        {
                            while (1) {
                                want_exit();
                                string search_friend_id = "";
                                char add_answer;
                                cout << "�˻��� ���̵� �Է�" << endl;
                                cin >> search_friend_id;
                                send_to_server("ģ���˻�_Ŭ" + search_friend_id);
                                vector<string> search_friend = recv_from_server();
                                if (recv_friend_home_num == "ģ���˻�_Ŭ")
                                {
                                    if (search_friend[0] != "have")
                                        cout << "ID�� Ȯ�ε��� �ʽ��ϴ�. �ٽ� �õ����ּ���. " << endl;

                                    while (search_friend[0] == "have") //�����ϴ��� Ȯ�����ִ� ���� ����
                                    {
                                        cout << search_friend_id << "�� �����մϴ�. \n ģ���� �߰��Ͻðڽ��ϱ�? (Y/N)" << endl;//�߰���ư ������
                                        if (add_answer == 'Y')
                                        {
                                            ;
                                            friend_num == "ģ����û_Ŭ";
                                            string msg = "ģ����û_Ŭ"  + search_friend_id;
                                            send_to_server(msg);
                                            recv_from_server();
                                        }
                                        else if (add_answer == 'N')
                                            break;
                                        else
                                        {
                                            cout << "�߸� �Է��ϼ̽��ϴ�. �ٽ� �õ����ּ���.";
                                            continue;
                                        }
                                    }


                                }
                            }
                        }

                        else
                            cout << "���� �߻�" << endl;
                    }
                }
            }
        }
    }
}

    //WSADATA wsa;
    //User user;

    //user�� ���� �Է¹ް� class User�� �����ϰ� �����ϱ�
//ȸ������,ȸ������
    //void create_userInfo() {
    //    User user;
    //    string inputID;
    //    string inputEmail;
    //    string inputPhone;
    //    string inputBirth;
    //    string inputNickname;
    //    string inputPW;
    //    string inputCha_num;


    //    cout << "ID�� �Է��ϼ��� " << endl;
    //    cin >> inputID;
    //    user.setMember_ID(inputID);

    //    cout << "�̸����� �Է��ϼ��� " << endl;
    //    cin >> inputEmail;
    //    user.setEmail(inputEmail);

    //    cout << "��ȭ��ȣ�� �Է��ϼ���\n (010-0000-0000 ����) " << endl;
    //    cin >> inputPhone;
    //    user.setPhone(inputPhone);

    //    cout << "�ֹι�ȣ �� 6�ڸ��� �Է��ϼ���. " << endl;
    //    cin >> inputBirth;
    //    user.setBirth(inputBirth);

    //    cout << "�г����� �Է��ϼ��� " << endl;
    //    cin >> inputNickname;
    //    user.setNickname(inputNickname);

    //    cout << "��й�ȣ�� �Է��ϼ��� " << endl;
    //    cin >> inputPW;
    //    user.setMember_PW(inputPW);

    //    cout << "ĳ���� ��ȣ�� �Է��ϼ��� " << endl;
    //    cin >> inputCha_num;
    //    user.setCha_num(inputCha_num);


    //}

    //user�� �������� �ڵ����� �����ֱ� ���� ���Ϳ� ������ �ش�.

    string send_UserInfo() {
        string userinfo = "";
        userinfo.clear();
        string id;
        userinfo = id;
        return userinfo;
    }


    int main() {
        WSADATA wsa;

        // Winsock�� �ʱ�ȭ�ϴ� �Լ�. MAKEWORD(2, 2)�� Winsock�� 2.2 ������ ����ϰڴٴ� �ǹ�.
        // ���࿡ �����ϸ� 0��, �����ϸ� �� �̿��� ���� ��ȯ.
        // 0�� ��ȯ�ߴٴ� ���� Winsock�� ����� �غ� �Ǿ��ٴ� �ǹ�.
        int code = WSAStartup(MAKEWORD(2, 2), &wsa);

        if (!code) {
            
            client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 

            // ������ ���� ���� ���� �κ�
            SOCKADDR_IN client_addr = {};
            client_addr.sin_family = AF_INET;
            client_addr.sin_port = htons(7777);
            InetPton(AF_INET, TEXT("192.168.200.137"), &client_addr.sin_addr);

            while (1) {
                if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // ���� ������ ������ �ش��ϴ� server�� ����!
                    cout << "Server Connect" << endl;
                    //send(client_sock, my_nick.c_str(), my_nick.length(), 0); // ���ῡ �����ϸ� client �� �Է��� �г����� ������ ����
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