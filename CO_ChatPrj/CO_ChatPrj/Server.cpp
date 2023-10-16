//������ ���� ���� ���� �ڵ����............
//���� �Ⱥ��� �Ǵ� ���Դϴ�.

#pragma comment(lib, "ws2_32.lib") //������� ���̺귯���� ��ũ. ���� ���̺귯�� ����

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <sstream>
#include <vector>
#include <mysql/jdbc.h>#include <mysql/jdbc.h>

#define MAX_SIZE 1024//���� �ڽ�ũ��
#define MAX_CLIENT 3

const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ

using namespace std;

struct SOCKET_INFO { // ����� ���� ������ ���� Ʋ ����
    SOCKET sck;//�̰� �ڽ� ����
    string user;
};

class Server {

    // MySQL Connector/C++ �ʱ�ȭ
    sql::mysql::MySQL_Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
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

    
    
    vector<string> client_msg;
    
    const string SERVER_MENU = recv_from_client()[0];

    
    void check_pw(string mysql_check_id) {
        res = stmt->executeQuery("SELECT member_PW FROM member WHERE Member_ID = '" + mysql_check_id + "'");
        string result = "00 "+ res->getString(1);

        send(sck_list[i].sck, result.c_str(), MAX_SIZE, 0);
    }

    /*if (SERVER_MENU ="00") 
        check_pw();*/


    std::vector<SOCKET_INFO> sck_list; // ����� Ŭ���̾�Ʈ ���ϵ��� ������ �迭 ����. ������ �׾Ƴ��� ����
    SOCKET_INFO server_sock; // ���� ���Ͽ� ���� ������ ������ ���� ����.
    int client_count = 0; // ���� ������ �ִ� Ŭ���̾�Ʈ�� count �� ���� ����.

    void server_init(); // socket �ʱ�ȭ �Լ�. socket(), bind(), listen() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
    void add_client(); // ���Ͽ� ������ �õ��ϴ� client�� �߰�(accept)�ϴ� �Լ�. client accept() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
    void send_msg(const char* msg); // send() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
    void recv_msg(int idx); // recv() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
    void del_client(int idx); // ���Ͽ� ����Ǿ� �ִ� client�� �����ϴ� �Լ�. closesocket() �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
    vector<string> recv_from_client(); // client�� ���� �� �޴� ��ȣ�� �޼����� �޾ƿ��� �Լ�


    delete res;
    delete stmt;
    delete con;
};