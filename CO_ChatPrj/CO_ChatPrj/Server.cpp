//조은수 연습 파일 각기 코드들이............
//여긴 안봐도 되는 곳입니다.

#pragma comment(lib, "ws2_32.lib") //명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <sstream>
#include <vector>
#include <mysql/jdbc.h>#include <mysql/jdbc.h>

#define MAX_SIZE 1024//소켓 박스크기
#define MAX_CLIENT 3

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

using namespace std;

struct SOCKET_INFO { // 연결된 소켓 정보에 대한 틀 생성
    SOCKET sck;//이게 박스 역할
    string user;
};

class Server {

    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
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

        // 데이터베이스 선택
        con->setSchema("practice");

        // db 한글 저장을 위한 셋팅 
        stmt = con->createStatement();
        stmt->execute("set names euckr");
        if (stmt) { delete stmt; stmt = nullptr; }
    }

    //친구목록 데이터 가져오기
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


    std::vector<SOCKET_INFO> sck_list; // 연결된 클라이언트 소켓들을 저장할 배열 선언. 소켓을 쌓아놓는 역할
    SOCKET_INFO server_sock; // 서버 소켓에 대한 정보를 저장할 변수 선언.
    int client_count = 0; // 현재 접속해 있는 클라이언트를 count 할 변수 선언.

    void server_init(); // socket 초기화 함수. socket(), bind(), listen() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
    void add_client(); // 소켓에 연결을 시도하는 client를 추가(accept)하는 함수. client accept() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
    void send_msg(const char* msg); // send() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
    void recv_msg(int idx); // recv() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
    void del_client(int idx); // 소켓에 연결되어 있는 client를 제거하는 함수. closesocket() 실행됨. 자세한 내용은 함수 구현부에서 확인.
    vector<string> recv_from_client(); // client로 부터 온 메뉴 번호와 메세지를 받아오는 함수


    delete res;
    delete stmt;
    delete con;
};