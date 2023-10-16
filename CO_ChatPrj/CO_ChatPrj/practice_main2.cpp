#pragma comment(lib, "ws2_32.lib") //명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <mysql/jdbc.h>#include <mysql/jdbc.h>


#define MAX_SIZE 1024//소켓 박스크기
#define MAX_CLIENT 3

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

using std::cout;
using std::cin;
using std::endl;
using std::string;


std::vector<SOCKET_INFO> sck_list; // 연결된 클라이언트 소켓들을 저장할 배열 선언. 소켓을 쌓아놓는 역할
SOCKET_INFO server_sock; // 서버 소켓에 대한 정보를 저장할 변수 선언.
int client_count = 0; // 현재 접속해 있는 클라이언트를 count 할 변수 선언.

//  recv_client + func_num 은 무조건 실행하는 기본 값으로 생각

string recv_client(int idx) { // client로 부터 받은 모든 것을 우선 저장
    char buf[MAX_SIZE] = { };
    string reading;
    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0)
            reading = buf;
    }        
    return reading;
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

int main() {
    while (1) {
        int idx = 0;
        recv_client(idx);
        
    }

}

void recv_login(int func_num) {
        


}
       
void recv_msg(int idx, string read) {
    char buf[MAX_SIZE] = { }; //버퍼가 채워질 때까지 그냥 임시 메모리 공간
    string msg = "";

    //cout << sck_list[idx].user << endl;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // 오류가 발생하지 않으면 recv는 수신된 바이트 수를 반환. 0보다 크다는 것은 메시지가 왔다는 것.
            msg = sck_list[idx].user + " : " + buf; //클라이언트에서 들어온 결과값이 저장되는 곳
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

void recv_info(int idx) {
 
    char buf[MAX_SIZE] = { }; //버퍼가 채워질 때까지 그냥 임시 메모리 공간
    string msg = "";

    //cout << sck_list[idx].user << endl;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // 오류가 발생하지 않으면 recv는 수신된 바이트 수를 반환. 0보다 크다는 것은 메시지가 왔다는 것.
        }
        
}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) { // 접속해 있는 모든 client에게 메시지 전송
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    //sck_list.erase(sck_list.begin() + idx); // 배열에서 클라이언트를 삭제하게 될 경우 index가 달라지면서 런타임 오류 발생....ㅎ
    client_count--;
}


struct SOCKET_INFO { // 연결된 소켓 정보에 대한 틀 생성
    SOCKET sck;//이게 박스 역할
    string user;
};

SOCKET_INFO new_client = {};

void add_client() {
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr의 메모리 영역을 0으로 초기화

    SOCKET_INFO new_client_info = {};

    new_client_info.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client_info.sck, buf, MAX_SIZE, 0);
    // Winsock2의 recv 함수. client가 보낸 닉네임을 받음.
    new_client_info.user = string(buf);
    // 여기까지는 접속
    sck_list.push_back(new_client_info); // client 정보를 답는 sck_list 배열에 새로운 client 추가
    std::thread th(recv_msg, client_count);
    // 다른 사람들로부터 오는 메시지를 계속해서 받을 수 있는 상태로 만들어 두기.

    th.join();//이때부터 진짜 시작 위에는 스레드를 준비시킨거고 
}