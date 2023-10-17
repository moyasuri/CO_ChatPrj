//여기 확인해주세요! 찐 연습용 메인
//리더님이 올려주셨던 형식이 너무 채팅방 내의 형식이라 여기부분은 
//서버와 연동해서 메시지를 받고 보내줘서 기능 처리를 우선 할 수 있도록 만든 부분입니다.
// add_client1과 recv_from_server 가 사용되는 주 부분입니다.
//채팅방 내 전체 공지말고는 기능 별로 각각 send를 사용할 예정입니다. >> send용 함수가 recv_from_server처럼 존재하지 않음

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

using namespace std;

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

using std::cout;
using std::cin;
using std::endl;
using std::string;

const string 로그인시도 = "00"; //send_id / recv_pw
const string ID찾기 = "01";
const string PW찾기 = "02";


//const string 정보 변경= "10";
const string 비밀번호수정 = "11";
const string 이메일수정 = "12";
const string 전화번호수정 = "13";
const string 생년월일수정 = "14";
const string 닉네임수정 = "15";
const string 캐릭터수정 = "16";
const string 참여방변경 = "17";

//const string 친구 = "20";

const string 친구목록_클 = "21";
const string 친구요청_클 = "22";
const string 친구검색_클 = "23";
const string 친구신청_클 = "24";
const string 친구수락거절_클 = "25";

const string 친구목록_서 = "21";
const string 친구요청_서 = "22";
const string 친구검색_서 = "23";
const string 친구신청_서 = "24";
const string 친구수락거절_서 = "25";

struct SOCKET_INFO { // 연결된 소켓 정보에 대한 틀 생성
    SOCKET sck;
    string user;
};

std::vector<SOCKET_INFO> sck_list; // 연결된 클라이언트 소켓들을 저장할 배열 선언.
SOCKET_INFO server_sock; // 서버 소켓에 대한 정보를 저장할 변수 선언.
int client_count = 0; // 현재 접속해 있는 클라이언트를 count 할 변수 선언.

//기존함수들
void server_init(); // socket 초기화 함수. socket(), bind(), listen() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void add_client(); // 소켓에 연결을 시도하는 client를 추가(accept)하는 함수. client accept() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void send_msg(const char* msg); // send() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void recv_msg(int idx); // recv() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void del_client(int idx); // 소켓에 연결되어 있는 client를 제거하는 함수. closesocket() 실행됨. 자세한 내용은 함수 구현부에서 확인.

const string IDENTIFIER = " ";

class MY_SQL {
public:
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

    //login 쿼리 보내기
    void send_login_check(SOCKET server_sock, string mysql_check_id, string mysql_check_pw) {
        res = stmt->executeQuery("SELECT member_ID, member_PW FROM member WHERE Member_ID = '" + mysql_check_id + "'");

        string resid, respw;
        string result;
        while (res->next()) {
            resid = res->getInt("member_ID");
            respw = res->getString("member_PW");
        }
        if (resid != mysql_check_id || respw != mysql_check_pw)
            result = 로그인시도 ;
        else
            result = 로그인시도 + IDENTIFIER + "have";


        send(server_sock, result.c_str(), MAX_SIZE, 0);
    }

    const string 친구목록_클 = "21";
    const string 친구요청_클 = "22";
    const string 친구검색_클 = "23";
    const string 친구신청_클 = "24";
    const string 친구수락거절_클 = "25";


    void send_friend_List(SOCKET server_sock, string mysql_check_id){
        res = stmt->executeQuery("SELECT Friend_List_Index, My_ID, My_Friend_ID FROM friend_list  WHERE Member_ID = '" + mysql_check_id + "'");
    string result;
    if (res->next())
        result = 친구목록_서 + " " + res->getString(1);
    else
        result = 친구목록_서 ;


    send(server_sock, result.c_str(), MAX_SIZE, 0);
}

    void send_friend_request(SOCKET server_sock, string mysql_check_id) {
        res = stmt->executeQuery("SELECT From_Friend_Request_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
        string result;
        if (res->next())
            result = 친구요청_서 + " " + res->getString(1);
        else
            result = 친구요청_서;


        send(server_sock, result.c_str(), MAX_SIZE, 0);
    }

    void send_friend_search(SOCKET server_sock, string mysql_check_id) { //비교해서 have 값만 보내줘야한다.
        res = stmt->executeQuery("SELECT member_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
        string result;
        if (res->next())
            result = 친구검색_서 + " " + "have";
        else
            result = 친구검색_서 + " ";

        send(server_sock, result.c_str(), MAX_SIZE, 0);
    }



  
private:
};


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
    //*
    server_sock.user = "server";

    cout << "Server On" << endl;
}

void add_client() {
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr의 메모리 영역을 0으로 초기화

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client.sck, buf, MAX_SIZE, 0);
    // Winsock2의 recv 함수. client가 보낸 닉네임을 받음.
    new_client.user = string(buf);

    string msg = "[공지] " + new_client.user + " 님이 입장했습니다.";
    cout << msg << endl;
    sck_list.push_back(new_client); // client 정보를 답는 sck_list 배열에 새로운 client 추가

    std::thread th(recv_msg, client_count);
    // 다른 사람들로부터 오는 메시지를 계속해서 받을 수 있는 상태로 만들어 두기.

    client_count++; // client 수 증가.
    cout << "[공지] 현재 접속자 수 : " << client_count << "명" << endl;
    send_msg(msg.c_str()); // c_str : string 타입을 const chqr* 타입으로 바꿔줌.

    th.join();
}

void add_client1() { //add_client  변형해서 우리 상황에 맞게 사용하고 싶음
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr의 메모리 영역을 0으로 초기화

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client.sck, buf, MAX_SIZE, 0);
    // Winsock2의 recv 함수. client가 보낸 닉네임을 받음.
    string reading = string(buf);
    string msg = string(buf + 3);
    std::thread th(recv_from_client,server_sock.sck, reading,msg);
    //질문 recv_from_client 함수에 사용되는 인자들은 어떻게 넣어주지??????

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

    while (1) { //  recv한 다음에 여기에 switch 넣기 
        // add client () 수정하지 마.


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

void recv_from_client(SOCKET s, string reading, string msg) {// 메세지가 들어오면 타입 구분 하는 기초 함수
    class MY_SQL mysql;
    if (server_func_num(reading)== 로그인시도)
        mysql.check_pw(s, msg);

}

string server_func_num(string reading) { //들어오는 정보들을 기능별로 구분하기 위한 buf에 있는 값 받아오는 첫 번째 함수
    string strfunc_menu;
    strfunc_menu = reading[0] + reading[1];
    return strfunc_menu;

}






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
            th1[i] = std::thread(add_client1);
        }
        //질문 add_client1처럼 처음부터 사용자를 받아주는 게 아니라 구별 후 시작하려면 어떻게 해야하는지
        // 이게 채팅에서만 쓰이는 건지 각 명령어를 받을 때도 사용하는 건지
        //std::thread th1(add_client); // 이렇게 하면 하나의 client만 받아짐...

        while (1) { // 무한 반복문을 사용하여 *서버*가 계속해서 클라이언트에게 채팅 보낼 수 있는 상태를 만들어 줌. 반복문을 사용하지 않으면 한 번만 보낼 수 있음.
            string text, msg = "";

            std::getline(cin, text);
            const char* buf = text.c_str();
            msg = server_sock.user + " : " + buf;
            send_msg(msg.c_str());
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


