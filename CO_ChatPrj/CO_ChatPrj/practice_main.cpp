//���� Ȯ�����ּ���! �� ������ ����
//�������� �÷��̴ּ� ������ �ʹ� ä�ù� ���� �����̶� ����κ��� 
//������ �����ؼ� �޽����� �ް� �����༭ ��� ó���� �켱 �� �� �ֵ��� ���� �κ��Դϴ�.
// add_client1�� recv_from_server �� ���Ǵ� �� �κ��Դϴ�.
//ä�ù� �� ��ü ��������� ��� ���� ���� send�� ����� �����Դϴ�. >> send�� �Լ��� recv_from_serveró�� �������� ����

#pragma comment(lib, "ws2_32.lib") //������� ���̺귯���� ��ũ. ���� ���̺귯�� ����

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <sstream>
#include <vector>
#include <mysql/jdbc.h>#include <mysql/jdbc.h>
#include "Usage.h"

#define MAX_SIZE 1024//���� �ڽ�ũ��
#define MAX_CLIENT 3

using namespace std;

const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ

using std::cout;
using std::cin;
using std::endl;
using std::string;

const string �α��νõ� = "00"; //send_id / recv_pw
const string IDã�� = "01";
const string PWã�� = "02";


//const string ���� ����= "10";
const string ��й�ȣ���� = "11";
const string �̸��ϼ��� = "12";
const string ��ȭ��ȣ���� = "13";
const string ������ϼ��� = "14";
const string �г��Ӽ��� = "15";
const string ĳ���ͼ��� = "16";
const string �����溯�� = "17";

//const string ģ�� = "20";

const string ģ�����_Ŭ = "21";
const string ģ����û_Ŭ = "22";
const string ģ���˻�_Ŭ = "23";
const string ģ����û_Ŭ = "24";
const string ģ����������_Ŭ = "25";

const string ģ�����_�� = "21";
const string ģ����û_�� = "22";
const string ģ���˻�_�� = "23";
const string ģ����û_�� = "24";
const string ģ����������_�� = "25";


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
string s_(int e_num) {
    return to_string(e_num);
}

struct SOCKET_INFO { // ����� ���� ������ ���� Ʋ ����
    SOCKET sck;
    string user;
};

std::vector<SOCKET_INFO> sck_list; // ����� Ŭ���̾�Ʈ ���ϵ��� ������ �迭 ����.
SOCKET_INFO server_sock; // ���� ���Ͽ� ���� ������ ������ ���� ����.
int client_count = 0; // ���� ������ �ִ� Ŭ���̾�Ʈ�� count �� ���� ����.
SOCKET Client_sck; // =  sck_list[];

//�����Լ���
void server_init(); // socket �ʱ�ȭ �Լ�. socket(), bind(), listen() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void add_client(); // ���Ͽ� ������ �õ��ϴ� client�� �߰�(accept)�ϴ� �Լ�. client accept() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void send_msg(const char* msg); // send() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void recv_msg(int idx); // recv() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void del_client(int idx); // ���Ͽ� ����Ǿ� �ִ� client�� �����ϴ� �Լ�. closesocket() �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.

const string IDENTIFIER = " ";
const string True = "True";
const string False = "False";

class MY_SQL {
public:
    // MySQL Connector/C++ �ʱ�ȭ
    sql::mysql::MySQL_Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;

    void set_database() {
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect(server, username, password);
        }
        catch (sql::SQLException& e) {
            cout << "Could not connect to server. Error message: " << e.what() << endl;
            exit(1);
        }

        // �����ͺ��̽� ����
        con->setSchema("practice");

        // db �ѱ� ������ ���� ���� 
        stmt = con->createStatement();
        stmt->execute("set names euckr");
        if (stmt) { delete stmt; stmt = nullptr; }
    }

    //ģ����� ������ ��������
    void send_friend_list(const char* friendList) {
        stmt->execute("select Friend_List_Index, My_Friend_ID from chat.friend_list"); // DROP

    }


    void send_login_check( string mysql_check_id, string mysql_check_pw) {
        res = stmt->executeQuery("SELECT Member_ID, Member_PW FROM member WHERE Member_ID = '" + mysql_check_id + "'");

        string resid, respw;
        string result;
        while (res->next()) {
            resid = res->getString("Member_ID");
            respw = res->getString("Member_PW");
        }
        if (resid != mysql_check_id || respw != mysql_check_pw)
        {
            result = �α��νõ� + IDENTIFIER + "False";
            
        }
        else
            result = �α��νõ� + IDENTIFIER + "True";

        
        send(Client_sck, result.c_str(), MAX_SIZE, 0);
    }


        void send_find_ID( string mysql_check_name, string mysql_check_email)
    { //������ email�� �̸��� ��ġ�ϴ� ����� Ȯ���ϰ� �ű⿡ �ùٸ� id�� �Ѱ��ش�
            string resid ="";
            string result;
        res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Email = '" + mysql_check_email + "' AND Name = '"+ mysql_check_name +"'");
        if(res->next()){
            resid = res->getString("Member_ID");
        }
        if (resid.size() !=0)
            result = IDã�� + IDENTIFIER + True + resid; //true false �� const string True = "True" ������ ���� �ֽ��ϴ�
        else 
            result = IDã�� + IDENTIFIER + False;
    }

        void send_find_PW(string mysql_check_id, string mysql_check_birth, string mysql_check_phone) 
        {

            string respw = "";
            string result = "";
            res = stmt->executeQuery("SELECT Member_PW FROM member WHERE Member_ID = '" +mysql_check_id+ "' AND Birth = '" + mysql_check_birth + "' AND Phone = '"+mysql_check_phone+ "'");
            if (res->next()) {
                respw = res->getString("Member_PW");
            }
            if (respw.size() != 0)
                result = PWã�� + IDENTIFIER + True +respw; 
            else
                result = PWã�� + IDENTIFIER + False;
            //client���� ��ȯ�Ǵ� ���� true�̸� ��й�ȣ �缳�� â���� �Ѿ�߰ڴ�.
            send(Client_sck, result.c_str(), MAX_SIZE, 0);
        }

        //���̵� ����

        string s_(int e_num) {
            return to_string(e_num);
        }

        void send_signup_IDchk(string mysql_check_id) {
            //Ŭ���̾�Ʈ���� name ���� ��ȣ�� ���� ��Ȳ
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?'");
            prep_stmt->setString(1, mysql_check_id);
            string result;
            if ((prep_stmt->execute()) == 1)
                result = s_(e_signup_IDchk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� id �ٸ� �ŷ� ������
            else
                result = s_(e_signup_IDchk) + IDENTIFIER + True;

            send(Client_sck, result.c_str(), MAX_SIZE, 0);
        }

        void send_signup_Nicknamechk(string mysql_check_nickname) {
            prep_stmt = con->prepareStatement("SELECT Nickname FROM member WHERE Nickname = '?'");
            prep_stmt->setString(1, mysql_check_nickname);
            string result;
            if ((prep_stmt->execute()) == 1)
                result = s_(e_signup_NickNamechk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� id �ٸ� �ŷ� ������
            else
                result = s_(e_signup_NickNamechk) + IDENTIFIER + True;

            send(Client_sck, result.c_str(), MAX_SIZE, 0);
        }

        //send�Լ��� ���� �������°� ���ڴ�. return string���� result�� ��ȯ�ϰ� 
        // pw �ߺ� üũ,���� üũ ���� �̻��� Ŭ���̾�Ʈ���� ó���ϰ� mysql���������⸸ ��ü������ �����Ѵ�.
        void mysql_signup(string Member_ID, string Email, string Phone, string Birth, string Nickname, int Cha_Num, string Member_PW, string Name) {
            prep_stmt = con->prepareStatement("INSERT INTO member VALUES ('?','?',NULL,'?','?','?','?','?',NULL,'?');");
            prep_stmt->setString(1, Member_ID);
            prep_stmt->setString(2, Email);
            prep_stmt->setString(3,Phone);
            prep_stmt->setString(4,Birth);
            prep_stmt->setString(5, Nickname);
            prep_stmt->setInt(6, Cha_Num);
            prep_stmt->setString(7, Member_PW);
            prep_stmt->setString(8, Name);
            string result;
            if ((prep_stmt->execute()) == 1)
                result = s_(e_signup_Submit) + IDENTIFIER + True; //ȸ������ ��� ��
            else
                result = s_(e_signup_Submit) + IDENTIFIER + True;//��� ����

            send(Client_sck, result.c_str(), MAX_SIZE, 0);
        }
   


    const string ģ�����_Ŭ = "21";
    const string ģ����û_Ŭ = "22";
    const string ģ���˻�_Ŭ = "23";
    const string ģ����û_Ŭ = "24";
    const string ģ����������_Ŭ = "25";


    void send_friend_List(string mysql_check_id){
        res = stmt->executeQuery("SELECT Friend_List_Index, My_ID, My_Friend_ID FROM friend_list  WHERE Member_ID = '" + mysql_check_id + "'");
    string result;
    if (res->next())
        result = ģ�����_�� + " " + res->getString(1);
    else
        result = ģ�����_�� ;


    send(Client_sck, result.c_str(), MAX_SIZE, 0);
}

    void send_friend_request( string mysql_check_id) {
        res = stmt->executeQuery("SELECT From_Friend_Request_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
        string result;
        if (res->next())
            result = ģ����û_�� + " " + res->getString(1);
        else
            result = ģ����û_��;


        send(Client_sck, result.c_str(), MAX_SIZE, 0);
    }

    void send_friend_search(SOCKET server_sock, string mysql_check_id) { //���ؼ� have ���� ��������Ѵ�.
        res = stmt->executeQuery("SELECT member_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
        string result;
        if (res->next())
            result = ģ���˻�_�� + " " + "have";
        else
            result = ģ���˻�_�� + " ";

        send(server_sock, result.c_str(), MAX_SIZE, 0);
    }



  
private:
};


void server_init() {
    server_sock.sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    // Internet�� Stream ������� ���� ����
   // SOCKET_INFO�� ���� ��ü�� socket �Լ� ��ȯ��(��ũ���� ����)
   // ���ͳ� �ּ�ü��, ��������, TCP �������� �� ��. 

    SOCKADDR_IN server_addr = {}; // ���� �ּ� ���� ����
    // ���ͳ� ���� �ּ�ü�� server_addr

    server_addr.sin_family = AF_INET; // ������ Internet Ÿ�� 
    server_addr.sin_port = htons(7777); // ���� ��Ʈ ����
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // �����̱� ������ local �����Ѵ�. 
    //Any�� ���� ȣ��Ʈ�� 127.0.0.1�� ��Ƶ� �ǰ� localhost�� ��Ƶ� �ǰ� ���� �� ����ϰ� �� �� �ֵ�. �װ��� INADDR_ANY�̴�.
    //ip �ּҸ� ������ �� server_addr.sin_addr.s_addr -- ������ ���?

    bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr)); // ������ ���� ������ ���Ͽ� ���ε��Ѵ�.
    listen(server_sock.sck, SOMAXCONN); // ������ ��� ���·� ��ٸ���.
    //*
    server_sock.user = "server";

    cout << "Server On" << endl;
}

void add_client() {
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr�� �޸� ������ 0���� �ʱ�ȭ

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client.sck, buf, MAX_SIZE, 0);
    // Winsock2�� recv �Լ�. client�� ���� �г����� ����.
    new_client.user = string(buf);

    string msg = "[����] " + new_client.user + " ���� �����߽��ϴ�.";
    cout << msg << endl;
    sck_list.push_back(new_client); // client ������ ��� sck_list �迭�� ���ο� client �߰�

    std::thread th(recv_msg, client_count);
    // �ٸ� �����κ��� ���� �޽����� ����ؼ� ���� �� �ִ� ���·� ����� �α�.

    client_count++; // client �� ����.
    cout << "[����] ���� ������ �� : " << client_count << "��" << endl;
    send_msg(msg.c_str()); // c_str : string Ÿ���� const chqr* Ÿ������ �ٲ���.

    th.join();
}

void add_client1() { //add_client  �����ؼ� �츮 ��Ȳ�� �°� ����ϰ� ����
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr�� �޸� ������ 0���� �ʱ�ȭ

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client.sck, buf, MAX_SIZE, 0);
    // Winsock2�� recv �Լ�. client�� ���� �г����� ����.
    string reading = string(buf);
    string msg = string(buf + 3);
    std::thread th(recv_from_client,server_sock.sck, reading,msg);
    //���� recv_from_client �Լ��� ���Ǵ� ���ڵ��� ��� �־�����??????

    th.join();

}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) { // ������ �ִ� ��� client���� �޽��� ����
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}


void recv_msg(int idx) {
    char buf[MAX_SIZE] = { };
    string msg = "";

    //cout << sck_list[idx].user << endl;

    while (1) { //  recv�� ������ ���⿡ switch �ֱ� 
        // add client () �������� ��.


        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // ������ �߻����� ������ recv�� ���ŵ� ����Ʈ ���� ��ȯ. 0���� ũ�ٴ� ���� �޽����� �Դٴ� ��.
            msg = sck_list[idx].user + " : " + buf;
            cout << msg << endl;
            send_msg(msg.c_str());
        }
        else { //�׷��� ���� ��� ���忡 ���� ��ȣ�� �����Ͽ� ���� �޽��� ����
            msg = "[����] " + sck_list[idx].user + " ���� �����߽��ϴ�.";
            cout << msg << endl;
            send_msg(msg.c_str());
            del_client(idx); // Ŭ���̾�Ʈ ����
            return;
        }
    }
}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    //sck_list.erase(sck_list.begin() + idx); // �迭���� Ŭ���̾�Ʈ�� �����ϰ� �� ��� index�� �޶����鼭 ��Ÿ�� ���� �߻�....��
    client_count--;
}

void recv_from_client(SOCKET s, string reading, string msg) {// �޼����� ������ Ÿ�� ���� �ϴ� ���� �Լ�
    class MY_SQL mysql;
    if (server_func_num(reading)== �α��νõ�)
        mysql.check_pw(s, msg);

}

string server_func_num(string reading) { //������ �������� ��ɺ��� �����ϱ� ���� buf�� �ִ� �� �޾ƿ��� ù ��° �Լ�
    string strfunc_menu;
    strfunc_menu = reading[0] + reading[1];
    return strfunc_menu;

}






int main() {
    WSADATA wsa;

    // Winsock�� �ʱ�ȭ�ϴ� �Լ�. MAKEWORD(2, 2)�� Winsock�� 2.2 ������ ����ϰڴٴ� �ǹ�.
    // ���࿡ �����ϸ� 0��, �����ϸ� �� �̿��� ���� ��ȯ.
    // 0�� ��ȯ�ߴٴ� ���� Winsock�� ����� �غ� �Ǿ��ٴ� �ǹ�.
    int code = WSAStartup(MAKEWORD(2, 2), &wsa);

    if (!code) {
        server_init();

        std::thread th1[MAX_CLIENT];
        for (int i = 0; i < MAX_CLIENT; i++) {
            // �ο� �� ��ŭ thread �����ؼ� ������ Ŭ���̾�Ʈ�� ���ÿ� ������ �� �ֵ��� ��.
            th1[i] = std::thread(add_client1);
        }
        //���� add_client1ó�� ó������ ����ڸ� �޾��ִ� �� �ƴ϶� ���� �� �����Ϸ��� ��� �ؾ��ϴ���
        // �̰� ä�ÿ����� ���̴� ���� �� ��ɾ ���� ���� ����ϴ� ����
        //std::thread th1(add_client); // �̷��� �ϸ� �ϳ��� client�� �޾���...

        while (1) { // ���� �ݺ����� ����Ͽ� *����*�� ����ؼ� Ŭ���̾�Ʈ���� ä�� ���� �� �ִ� ���¸� ����� ��. �ݺ����� ������� ������ �� ���� ���� �� ����.
            string text, msg = "";

            std::getline(cin, text);
            const char* buf = text.c_str();
            msg = server_sock.user + " : " + buf;
            send_msg(msg.c_str());
        }

        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i].join();
            //join : �ش��ϴ� thread ���� ������ �����ϸ� �����ϴ� �Լ�.
            //join �Լ��� ������ main �Լ��� ���� ����Ǿ thread�� �Ҹ��ϰ� ��.
            //thread �۾��� ���� ������ main �Լ��� ������ �ʵ��� ����.
        }
        //th1.join();

        closesocket(server_sock.sck);
    }
    else {
        cout << "���α׷� ����. (Error code : " << code << ")";
    }

    WSACleanup();

    return 0;
}


