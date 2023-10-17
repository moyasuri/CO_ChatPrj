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
#include "User.cpp"

using namespace std;

class User {
public:
    string getMember_ID() {
        return member_ID;
    }
    string getEmail() {
        return email;
    }
    string getPhone() {
        return phone;
    }
    string getBirth() {
        return birth;
    }
    string getNickname() {
        return nickname;
    }
    string getCha_num() {
        return member_ID;
    }
    string getMember_PW() {
        return member_ID;
    }
    string getJoin_room_index() {
        return member_ID;
    }

    string setMember_ID(string member_ID) {
        this->member_ID = member_ID;
    }
    string setEmail(string email) {
        this->email = email;
    }
    string setPhone(string phone) {
        this->phone = phone;
    }
    string setBirth(string birth) {
        this->birth = birth;
    }
    string setNickname(string nickname) {
        this->nickname = nickname;
    }
    string setCha_num(string cha_num) {
        this->cha_num = cha_num;
    }
    string setMember_PW(string pw) {
        this->member_PW = member_PW;
    }
    string setJoin_room_index(string join_room_index) {
        this->join_room_index = join_room_index;
    }

private:
    string member_ID = "";
    string member_PW = "";
    string email = "";
    string phone = "";
    string birth = "";
    string nickname = "";
    string cha_num = "";
    string join_room_index = "";



};

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


const string �α��νõ� = "00"; //send_id / recv_pw
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
User user;

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

string recv_from_server_text() 
{
    vector<string> text;
    return text[1];
}

string recv_from_server_num()
{
    vector<string> num;
    return num[0];

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
        
        string login_id = "";
        string login_pw = "";
        cout << "id�� �Է��ϼ��� : " << endl;
        cin >> login_id;
        cout << "pw�� �Է��ϼ��� : " << endl;
        cin >> login_pw;

        string send_login_id = �α��νõ� + login_id;
        send_to_server(send_login_id);

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
const string IDã�� = "01";
const string PWã�� = "02";

const string ģ�����_Ŭ = "21";
const string ģ����û_Ŭ = "22";
const string ģ���˻�_Ŭ = "23";
const string ģ����û_Ŭ = "24";

const string ģ�����_�� = "21";
const string ģ����û_�� = "22";
const string ģ���˻�_�� = "23";
const string ģ����û_�� = "24";

/*
    ģ�� ����� �׻� ������
   ģ����û��ư�� ������ ��û�� ģ�� ����� ���̰� ���� ������ �Ҽ�����
   ģ���߰���ư�� ������ ������ ���̵� �˻��ؼ� ģ�� ��û�� ���� �� ���� 
   ��� ȭ�鿡�� �ݱ� ��ư�� ������
*/

void friend_home() {
    while (1) {
        
        vector<string> friend_list; // ģ�� ���̺� �޾ƿͼ� ���� ���� �����ϴ� ����
        send_to_server(ģ�����_Ŭ);
        recv_from_server();
        string recv_friend_home_num = recv_from_server_num();
        string recv_friend_home_text = recv_from_server_text();
        if (recv_friend_home_num == ģ�����_��)
        {
        string s;
        std::stringstream ss(recv_friend_home_text);
        while (ss >> s) {
            friend_list.push_back(s);
        }
        //���̺�ó�� ���̰� �ٽ� �ٲ���� �Ѵ� -_-
        if (recv_friend_home_num == ģ�����_Ŭ) {
            while (1) {
                //ģ������� �⺻�������� �����ִ�
                string friend_num=""; //������� ����
                cout << "ģ�� Ȩ���� �ϰ� ���� �޴� ����" << endl;
                cin >> friend_num;

                    if (friend_num == ģ����û_Ŭ)
                    {
                        send_to_server(ģ����û_Ŭ);
                        recv_from_server();
                        if (recv_friend_home_num == ģ����û_��)
                            recv_from_server_text();
                    }

                    
                    else if (friend_num == ģ���˻�_Ŭ)
                    {
                        while (1) {
                            want_exit();
                            string search_friend_id = "";
                            char add_answer;
                            cout << "�˻��� ���̵� �Է�" << endl;
                            cin >> search_friend_id;
                            send_to_server(ģ���˻�_Ŭ + search_friend_id);
                            recv_from_server();
                            if (recv_friend_home_num == ģ���˻�_Ŭ)
                            {
                                if (recv_from_server_text() != "have")                   
                                    cout << "ID�� Ȯ�ε��� �ʽ��ϴ�. �ٽ� �õ����ּ���. " << endl;
                               
                                while(recv_from_server_text() == "have") //�����ϴ��� Ȯ�����ִ� ���� ����
                                {
                                    cout << search_friend_id << "�� �����մϴ�. \n ģ���� �߰��Ͻðڽ��ϱ�? (Y/N)" << endl;//�߰���ư ������
                                    if (add_answer == 'Y')
                                    {
                                        ;
                                        friend_num == ģ����û_Ŭ;
                                        send_to_server(ģ����û_Ŭ + search_friend_id);
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

