#pragma comment(lib, "ws2_32.lib") //명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <mysql/jdbc.h>#include <mysql/jdbc.h>

#define MAX_SIZE 1024//소켓 박스크기
#define MAX_CLIENT 3

using namespace std;

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

using std::cout;
using std::cin;
using std::endl;
using std::string;

struct SOCKET_INFO { // 연결된 소켓 정보에 대한 틀 생성
    SOCKET sck;
    string user;
};

std::vector<SOCKET_INFO> sck_list; // 연결된 클라이언트 소켓들을 저장할 배열 선언.
SOCKET_INFO server_sock; // 서버 소켓에 대한 정보를 저장할 변수 선언.
int client_count = 0; // 현재 접속해 있는 클라이언트를 count 할 변수 선언.

void server_init(); // socket 초기화 함수. socket(), bind(), listen() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void add_client(); // 소켓에 연결을 시도하는 client를 추가(accept)하는 함수. client accept() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void send_msg(const char* msg); // send() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void recv_msg(int idx); // recv() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void del_client(int idx); // 소켓에 연결되어 있는 client를 제거하는 함수. closesocket() 실행됨. 자세한 내용은 함수 구현부에서 확인.

//내가 만든 함수
void server_main();
void mysql_login();
int func_num();



//class 나중에 정리 필요

class MY_SQL {
    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

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

    //login 쿼리 보내기
    void check_pw(string mysql_check_id) {
        stmt->execute("select member_PW from member where Member_ID =",mysql_check_id); // DROP
    }

};


int main() {
    WSADATA wsa;

    // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
    // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
    // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
    int code = WSAStartup(MAKEWORD(2, 2), &wsa);

    if (!code) {
        server_init();
        std::thread th1[MAX_CLIENT];
        for (int i = 0; i < MAX_CLIENT; i++) {
            // 인원 수 만큼 thread 생성해서 각각의 클라이언트가 동시에 소통할 수 있도록 함.
            th1[i] = std::thread(add_client);
        }

        SOCKADDR_IN addr = {};
        int addrsize = sizeof(addr);
        char buf[MAX_SIZE] = { };

        while(1){
        ZeroMemory(&addr, addrsize); // addr의 메모리 영역을 0으로 초기화

        SOCKET_INFO new_client = {};

        new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
        recv(new_client.sck, buf, MAX_SIZE, 0);
        string reading = string(buf);
        MY_SQL mysql;
        switch (func_num(reading))
        {
        case(0): //login_check pw
            mysql.check_pw();
            ; break;
        case(1):
            ; break;
        case(2):
            ; break;
        case(3):
            ; break;
        case(4):
            ; break;
        case(5):
            ; break;
        case(6):
            ; break;
        case(7):
            ; break;
        }


        for (int i = 0; i < MAX_CLIENT; i++) {
            th1[i].join();
            //join : 해당하는 thread 들이 실행을 종료하면 리턴하는 함수.
            //join 함수가 없으면 main 함수가 먼저 종료되어서 thread가 소멸하게 됨.
            //thread 작업이 끝날 때까지 main 함수가 끝나지 않도록 해줌.
        }
        //th1.join();

        closesocket(server_sock.sck);
    }

    else {
        cout << "프로그램 종료. (Error code : " << code << ")";
    }

    WSACleanup();

    return 0;
}

void server_init() {
    server_sock.sck = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    // Internet의 Stream 방식으로 소켓 생성
   // SOCKET_INFO의 소켓 객체에 socket 함수 반환값(디스크립터 저장)
   // 인터넷 주소체계, 연결지향, TCP 프로토콜 쓸 것. 

    SOCKADDR_IN server_addr = {}; // 소켓 주소 설정 변수
    // 인터넷 소켓 주소체계 server_addr

    server_addr.sin_family = AF_INET; // 소켓은 Internet 타입 
    server_addr.sin_port = htons(7777); // 서버 포트 설정
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // 서버이기 때문에 local 설정한다. 
    //Any인 경우는 호스트를 127.0.0.1로 잡아도 되고 localhost로 잡아도 되고 양쪽 다 허용하게 할 수 있따. 그것이 INADDR_ANY이다.
    //ip 주소를 저장할 땐 server_addr.sin_addr.s_addr -- 정해진 모양?

    bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr)); // 설정된 소켓 정보를 소켓에 바인딩한다.
    listen(server_sock.sck, SOMAXCONN); // 소켓을 대기 상태로 기다린다.
    *
        server_sock.user = "server";

    cout << "Server On" << endl;
}

void add_client() {

    client_count++; // client 수 증가.
    cout << "[공지] 현재 접속자 수 : " << client_count << "명" << endl;
    send_msg(msg.c_str()); // c_str : string 타입을 const chqr* 타입으로 바꿔줌.

    th.join();
}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) { // 접속해 있는 모든 client에게 메시지 전송
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}

void recv_msg(int idx) {
    char buf[MAX_SIZE] = { };
    string msg = "";

    //cout << sck_list[idx].user << endl;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // 오류가 발생하지 않으면 recv는 수신된 바이트 수를 반환. 0보다 크다는 것은 메시지가 왔다는 것.
            msg = sck_list[idx].user + " : " + buf;
            cout << msg << endl;
            send_msg(msg.c_str());
        }
        else { //그렇지 않을 경우 퇴장에 대한 신호로 생각하여 퇴장 메시지 전송
            msg = "[공지] " + sck_list[idx].user + " 님이 퇴장했습니다.";
            cout << msg << endl;
            send_msg(msg.c_str());
            del_client(idx); // 클라이언트 삭제
            return;
        }
    }
}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    //sck_list.erase(sck_list.begin() + idx); // 배열에서 클라이언트를 삭제하게 될 경우 index가 달라지면서 런타임 오류 발생....ㅎ
    client_count--;
}

void server_main() {
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr의 메모리 영역을 0으로 초기화

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client.sck, buf, MAX_SIZE, 0);
    string reading = string(buf);
}




int func_num(string reading) { //들어오는 정보들을 기능별로 구분하기 위한 buf에 있는 값 받아오는 첫 번째 함수
    string strfunc_menu;
    strfunc_menu = reading[0] + reading[1];

    if (strfunc_menu == "00")
        return 0;
    if (strfunc_menu == "01")
        return 1;
    if (strfunc_menu == "02")
        return 2;
    if (strfunc_menu == "03")
        return 3;
    if (strfunc_menu == "04")
        return 4;
    if (strfunc_menu == "05")
        return 5;
    if (strfunc_menu == "06")
        return 6;
    if (strfunc_menu == "07")
        return 7;
}