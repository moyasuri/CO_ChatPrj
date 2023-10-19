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
#include <mysql/jdbc.h>
#include "UsageServer.h"
#include "UserInfo.h"

#define MAX_SIZE 1024//���� �ڽ�ũ��
#define MAX_CLIENT 3

//using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::string;

string _Index;

const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ

bool isNumeric(const std::string& str);

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
    return std::to_string(e_num);
}

struct SOCKET_INFO { // ����� ���� ������ ���� Ʋ ����
    SOCKET sck;
    UserInfo user;
    string user_;
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

void recv_from_client(int idx); //����
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

    string s_(int e_num) {
        return std::to_string(e_num);
    }

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
        con->setSchema("chat");

        // db �ѱ� ������ ���� ���� 
        stmt = con->createStatement();
        stmt->execute("set names euckr");
        //if (stmt) { delete stmt; stmt = nullptr; }

    }

    //ģ����� ������ ��������
    void send_friend_list(const char* friendList) {
        stmt->execute("select Friend_List_Index, My_Friend_ID from chat.friend_list"); // DROP

    }
         //���̵� �ߺ�Ȯ��
        string signup_IDchk(string recv_content) {

        std::stringstream ss(recv_content);
        string mysql_check_id;
        ss >> mysql_check_id;
        sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Member_ID = '" + mysql_check_id + "'");
        string result;
        if (res->next()) {
            result = s_(e_signup_IDchk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� id �ٸ� �ŷ� ������
        }
        else
        {
            result = s_(e_signup_IDchk) + IDENTIFIER + True;
        }
        return result;
        if (stmt) { delete stmt; stmt = nullptr; }
    }

        string signup_Nicknamechk(string recv_content, int this_idx) {
            cout << " string send_signup_Nicknamechk(string recv_content) " << endl;
            std::stringstream ss(recv_content);
            string mysql_check_nickname;
            ss >> mysql_check_nickname;
            try {
                prep_stmt = con->prepareStatement("SELECT Nickname FROM member WHERE Nickname = ?");
                cout << "prep_stmt = con->prepareStatement ����" << endl;
                prep_stmt->setString(1, mysql_check_nickname);
                string result;
                sql::ResultSet* res = prep_stmt->executeQuery();
                if ((res->next()))
                    result = s_(e_signup_NickNamechk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� nickname �ٸ� �ŷ� ������
                else
                    result = s_(e_signup_NickNamechk) + IDENTIFIER + True;
                cout << "result " << result << endl;;
                return result;
            } catch (sql::SQLException& e) {
                cout << "#\t SQL Exception: " << e.what();
                cout << " (MySQL error code: " << e.getErrorCode();
                cout << ", SQLState: " << e.getSQLState() << " )" << endl;
                return "";
            }
        }

        //send�Լ��� ���� �������°� ���ڴ�. return string���� result�� ��ȯ�ϰ� 
        // pw �ߺ� üũ,���� üũ ���� �̻��� Ŭ���̾�Ʈ���� ó���ϰ� mysql���������⸸ ��ü������ �����Ѵ�.
        void signup_Submit(string recv_content) {
            std::stringstream ss(recv_content);
            string Member_ID;
            string Email;
            string Phone;
            string Birth;
            string Nickname;
            int Cha_Num;
            string Member_PW;
            string Name;

            ss >> Member_ID>> Email >>Phone >> Birth>> Nickname>> Cha_Num >> Member_PW >>Name;

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
                result = s_(e_signup_Submit) + IDENTIFIER + False;//��� ����

        }
   
    //�α���Ȯ���ϱ�
    string try_Signin( string recv_content, int this_idx) {
        cout << " string send_login_check �Լ� �� " << endl;
        std::stringstream ss(recv_content);
        string mysql_check_id;
        string mysql_check_pw;
        ss >> mysql_check_id >> mysql_check_pw;
        cout << "mysql_check_id : " << mysql_check_id << "mysql_check_pw : " << mysql_check_pw;
        prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?' AND Member_PW = '?'");
        prep_stmt->setString(1, mysql_check_id);
        prep_stmt->setString(2, mysql_check_pw);
        cout << " prep_stmt = con->prepareStatement : ����Ϸ�" << endl;
        string result;
    
        if ((prep_stmt->execute()) == 1)
        {
            result = s_(e_id_try_Signin) + IDENTIFIER + "True";
            sck_list[this_idx].user.setID(mysql_check_id);
            sck_list[this_idx].user.setPW(mysql_check_id);
        }
        else
            result = s_(e_id_try_Signin) + IDENTIFIER + "False";
        return result;
        
    }

       //���̵�ã��
       string find_ID(string recv_content) {
          // cout << " string send_find_ID(string recv_content) {" << endl;
            std::stringstream ss(recv_content);
            string mysql_check_name;
            string mysql_check_email;
            ss >> mysql_check_name >> mysql_check_email;
            //cout << "  mysql_check_name >> mysql_check_email : " << mysql_check_name <<endl<< mysql_check_email << endl;
            string resid ="";
            string result;
        res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Email = '" + mysql_check_email + "' AND Name = '"+ mysql_check_name +"'");
        //cout << " res = stmt->executeQuery" << endl;
        if(res->next()){
            resid = res->getString("Member_ID");
        }
        if (resid.size() !=0)
            result = s_(e_id_find_ID) + IDENTIFIER + True + resid; //true false �� const string True = "True" ������ ���� �ֽ��ϴ�
        else 
            result = s_(e_id_find_ID) + IDENTIFIER + False;
       return result;
    }
       //��й�ȣã��
        string find_PW(string recv_content) {
            std::stringstream ss(recv_content);
            string mysql_check_id;
            string mysql_check_birth;
            string mysql_check_phone;
            ss >> mysql_check_id>>mysql_check_birth>>mysql_check_phone;
            string respw = "";
            string result = "";
            res = stmt->executeQuery("SELECT Member_PW FROM member WHERE Member_ID = '" +mysql_check_id+ "' AND Birth = '" + mysql_check_birth + "' AND Phone = '"+mysql_check_phone+ "'");
            if (res->next()) {
                respw = res->getString("Member_PW");
            }
            cout << "  if (res->next()):" << respw<< "�ذ�" << endl;
            if (respw.size() != 0)
            {
                result = s_(e_id_find_PW) + IDENTIFIER + True + respw;
            }
            else
            {
                result = s_(e_id_find_PW) + IDENTIFIER + False;
            }
            return result;
            if (stmt) { delete stmt; stmt = nullptr; }
        }

    // e_edit_PWchk = 31 �����Ϸ��� ��й�ȣ �޾��� �� mysql ���� ����, ������ ���̵� ������ �־�� �� 
        string edit_PWchk(string recv_content, int this_idx) {
            std::stringstream ss(recv_content);
            string my_ID = sck_list[this_idx].user.getID();
            string mysql_check_pw;
            string result;
            ss >> mysql_check_pw;
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?' AND Member_PW = '?'");
        prep_stmt->setString(1, my_ID);
        prep_stmt->setString(2, mysql_check_pw);
        if (prep_stmt->execute())
        {
            result = s_(e_edit_PWchk) + True;
        }
        else
        {
            result = s_(e_edit_PWchk) + False;
        }
        return result;
    }

        string edit_Nicknamechk(string recv_content, int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            string check_nickname;
            string result;
            std::stringstream ss(recv_content);
            ss >> check_nickname;
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?' AND Nickname = '?'");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, check_nickname);
            if (prep_stmt->execute())
            {
                result = s_(e_edit_PWchk) + True;
            }
            else
            {
                result = s_(e_edit_PWchk) + False;
            }
            return result;
        }

        string edit_Confirm(string recv_content, int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            std::stringstream ss(recv_content);
            string Email;
            string Phone;
            string Birth;
            string Nickname;
            string Cha_Num;
            string Member_PW;
            string Name;

            string result;

            ss >> Email >> Phone >> Birth >> Nickname >> Cha_Num >> Member_PW >> Name;

            prep_stmt = con->prepareStatement("update member set Email = ?, Phone =?, Birth = ? ,Nickname = '?',Cha_Num = '?',Member_PW='?',Name='?' WHERE  Member_ID = '?'");
            
            prep_stmt->setString(1, Email);
            prep_stmt->setString(2, Phone);
            prep_stmt->setString(3, Birth);
            prep_stmt->setString(4, Nickname);
            prep_stmt->setInt(5, std::stoi(Cha_Num));
            prep_stmt->setString(6, Member_PW);
            prep_stmt->setString(7, Name);
            prep_stmt->setString(8, my_ID);

            if ((prep_stmt->execute()) == 1)
                result = s_(e_signup_Submit) + IDENTIFIER + True; //���� ���� ����
            else
                result = s_(e_signup_Submit) + IDENTIFIER + False;//���� ���� ����

            return result;
            sck_list[this_idx].user.setBirth(Birth);
            sck_list[this_idx].user.setChaNum(std::stoi(Cha_Num));
            sck_list[this_idx].user.setEmail(Email);
            sck_list[this_idx].user.setName(Name);
            sck_list[this_idx].user.setNickName(Nickname);
            sck_list[this_idx].user.setPhone(Phone);
            sck_list[this_idx].user.setPW(Member_PW);

        }


 /*       string edit_Confirm(string recv_content) {
            res = stmt->executeQuery("update member set name = "" where id = "john123";");

        }*/

        string message_List( int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            string result;
            string from_ID;
            string datetime;
            string text;
            sql::ResultSet* res = stmt->executeQuery("SELECT From_Short_Note_ID, Short_Note_Datetime, Short_Note_text FROM short_note WHERE To_Short_Note_ID = '"+my_ID+"' AND Respond_Short_Note = 3");
            
            if (res->next())
            result = s_(e_message_List) + " " + res->getString(1) + res->getString(2) + res->getString(3);
            
        }
    void send_friend_List(string mysql_check_id){
        res = stmt->executeQuery("SELECT Friend_List_Index, My_ID, My_Friend_ID FROM friend_list  WHERE Member_ID = '" + mysql_check_id + "'");
    string result;
    if (res->next())
        result = s_(e_friends_List) + " " + res->getString(1);
    else
        result = s_(e_friends_List);


    send(Client_sck, result.c_str(), MAX_SIZE, 0);
}

    void send_friend_request( string mysql_check_id) {
        res = stmt->executeQuery("SELECT From_Friend_Request_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
        string result;
        if (res->next())
            result = s_(e_friends_Request) + " " + res->getString(1);
        else
            result = s_ (e_friends_Request);


        send(Client_sck, result.c_str(), MAX_SIZE, 0);
    }

    void send_friend_search(SOCKET server_sock, string mysql_check_id) { //���ؼ� have ���� ��������Ѵ�.
        res = stmt->executeQuery("SELECT member_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
        string result;
        if (res->next())
            result = s_(e_friends_search) + " " + "have";
        else
            result = s_(e_friends_search) + " ";

        send(server_sock, result.c_str(), MAX_SIZE, 0);
    }



  
private:
};

MY_SQL mysql;

void user_info_state() {


}

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
    server_sock.user_ = "server";

    cout << "Server On" << endl;
}

//void add_client() {
//    SOCKADDR_IN addr = {};
//    int addrsize = sizeof(addr);
//    char buf[MAX_SIZE] = { };
//
//    ZeroMemory(&addr, addrsize); // addr�� �޸� ������ 0���� �ʱ�ȭ
//
//    SOCKET_INFO new_client = {};
//
//    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
//    recv(new_client.sck, buf, MAX_SIZE, 0);
//    cout << "buf Ȯ�� 1 " << buf << endl;
//    // Winsock2�� recv �Լ�. client�� ���� �г����� ����.
//    new_client.user = string(buf);
//
//    string msg = "[����] " + new_client.user + " ���� �����߽��ϴ�.";
//    cout << msg << endl;
//    sck_list.push_back(new_client); // client ������ ��� sck_list �迭�� ���ο� client �߰�
//
//    std::thread th(recv_msg, client_count);
//    // �ٸ� �����κ��� ���� �޽����� ����ؼ� ���� �� �ִ� ���·� ����� �α�.
//
//    client_count++; // client �� ����.
//    cout << "[����] ���� ������ �� : " << client_count << "��" << endl;
//    send_msg(msg.c_str()); // c_str : string Ÿ���� const chqr* Ÿ������ �ٲ���.
//
//    th.join();
//}

int client_num = 0;
void add_client1() { //add_client  �����ؼ� �츮 ��Ȳ�� �°� ����ϰ� ����
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr�� �޸� ������ 0���� �ʱ�ȭ

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize); //���α׷��� �����Ҷ� ������ ����Ǵ� ù �κ�
    sck_list.push_back(new_client);
   
    // �α����̳� ȸ���������� ���۵�
    string reading = string(buf);
    string msg = string(buf + 3);
    //std::thread th(recv_from_client,server_sock.sck, reading,msg);
    //���� recv_from_client �Լ��� ���Ǵ� ���ڵ��� ��� �־�����?????? ����ó�� ����� �������� �־��� �� �ִ�.?
    std::thread th(recv_from_client, client_num);
    th.join();

}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) { // ������ �ִ� ��� client���� �޽��� ����
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}


//void recv_msg(int idx) {
//    char buf[MAX_SIZE] = { };
//    string msg = "";
//
//    //cout << sck_list[idx].user << endl;
//
//    while (1) { //  recv�� ������ ���⿡ switch �ֱ� 
//        // add client () �������� ��.
//
//
//        ZeroMemory(&buf, MAX_SIZE);
//        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // ������ �߻����� ������ recv�� ���ŵ� ����Ʈ ���� ��ȯ. 0���� ũ�ٴ� ���� �޽����� �Դٴ� ��.
//            cout << " buf 3 " << buf << endl;
//            msg = sck_list[idx].user + " : " + buf;
//            cout << msg << endl;
//            send_msg(msg.c_str());
//        }
//        else { //�׷��� ���� ��� ���忡 ���� ��ȣ�� �����Ͽ� ���� �޽��� ����
//            msg = "[����] " + sck_list[idx].user + " ���� �����߽��ϴ�.";
//            cout << msg << endl;
//            send_msg(msg.c_str());
//            del_client(idx); // Ŭ���̾�Ʈ ����
//            return;
//        }
//    }
//}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    //sck_list.erase(sck_list.begin() + idx); // �迭���� Ŭ���̾�Ʈ�� �����ϰ� �� ��� index�� �޶����鼭 ��Ÿ�� ���� �߻�....��
    client_count--;
}

void recv_from_client(int idx) {// �޼����� ������ Ÿ�� ���� �ϴ� ���� �Լ�
    char buf[MAX_SIZE] = { };
    string msg = "";
    string identifier = "";
    string recv_content = "";
    //cout << sck_list[idx].user << endl;
    int e_num = 0;
    int this_idx = idx;
    

    while (1) { //  recv�� ������ ���⿡ switch �ֱ� 
        // add client () �������� ��.
        SOCKET Client_sck = sck_list[idx].sck;

        ZeroMemory(&buf, MAX_SIZE);
        if (recv(Client_sck, buf, MAX_SIZE, 0) > 0) {
            msg = buf;
            cout << "buf Ȯ�� 4: " << buf << endl;
            std::stringstream ss(msg);  // ���ڿ��� ��Ʈ��ȭ
            ss >> _Index;
            recv_content = string(buf + 3);



        }
        //����ó�� �ʿ�
        if (isNumeric(_Index))
        {
            int _Index_Int = stoi(_Index);
            cout << "�ε���"<<_Index_Int;

            switch (_Index_Int)
            {
            case e_signup_IDchk:
                cout << " case ���� ���Դ�" << endl;
                mysql.signup_IDchk(recv_content); break;
            case e_signup_NickNamechk:
                cout << " e_signup_NickNamechk case ���� ���Դ�" << endl;
                mysql.signup_Nicknamechk(recv_content, idx); break;
            case e_signup_Submit:
                mysql.signup_Submit(recv_content); break;
            case e_id_try_Signin:
                mysql.try_Signin(recv_content,idx); break;
            
            case e_id_find_ID:
                cout << " case�� ���� ";
                mysql.find_ID(recv_content); break;
            case e_id_find_PW:
                mysql.find_PW(recv_content); break;
         /*   case e_edit_PWchk:
                cout << "e_edit_PWchk = 31 " << endl;
                mysql.(recv_content); break;
            case e_edit_NickNamechk:
                cout << "e_edit_NickNamechk " << endl;
                mysql.(recv_content); break;
            case e_edit_Confirm:
                cout << "e_edit_Confirm " << endl;
                mysql.(recv_content); break;*/
           /* case e_message_List:
                cout << " " << endl;
                mysql.e_message_List(recv_content); break;
            case e_message_Read:
                cout << " " << endl;
                mysql.e_message_Read(recv_content); break;
            case e_message_Send:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;
            case:
                cout << " " << endl;
                mysql.(recv_content); break;*/

            }



        }
    }
}

    int main() {
        WSADATA wsa;

        // Winsock�� �ʱ�ȭ�ϴ� �Լ�. MAKEWORD(2, 2)�� Winsock�� 2.2 ������ ����ϰڴٴ� �ǹ�.
        // ���࿡ �����ϸ� 0��, �����ϸ� �� �̿��� ���� ��ȯ.
        // 0�� ��ȯ�ߴٴ� ���� Winsock�� ����� �غ� �Ǿ��ٴ� �ǹ�.
        int code = WSAStartup(MAKEWORD(2, 2), &wsa);

        if (!code) {
            mysql.set_database();
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
                msg = server_sock.user_ + " : " + buf;
                send_msg(msg.c_str());
            }

            for (int i = 0; i < MAX_CLIENT; i++) {
                th1[i].join();
                //join : �ش��ϴ� thread ���� ������ �����ϸ� �����ϴ� �Լ�.
                //join �Լ��� ������ main �Լ��� ���� ����Ǿ thread�� �Ҹ��ϰ� ��.
                //thread �۾��� ���� ������ main �Լ��� ������ �ʵ��� ����.
            }
           /* th1.join();*/

            closesocket(server_sock.sck);
        }
    

        else {
            cout << "���α׷� ����. (Error code : " << code << ")";
        }

        WSACleanup();

        return 0;
    }

    bool isNumeric(const std::string& str) {
        for (char c : str) {
            if (!std::isdigit(c)) {
                return false;
            }
        }
        return true;
    }