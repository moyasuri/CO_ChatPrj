/*
send 와 receive는 무조건 짝꿍
*/
#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h> //Winsock 헤더파일 include. WSADATA 들어있음.
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <vector>
// user 헤더 추가
#include "Usage.h"



using namespace std;



//string으로 정보를 모두 받아줘야 하고 (socket에 char 형식으로만 전달 가능해 c_str 사용해야 하기 때문) 
//서버에 전달 후 서버에서 string으로 다시 받아 int변환 등 처리해서 mysql로 보내준다.
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
            // 스트림을 통해, 문자열을 공백 분리해 변수에 할당. 보낸 사람의 이름만 user에 저장됨
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

string want_exit() { //메뉴 닫기 while문에서 사용해준다.
    char answer;
    cout << "이 화면을 닫기를 원합니까? (Y/N) " << endl;
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
            cout << "잘못 입력하셨습니다. 다시 시도해 주세요 .";
    }
}

void send_to_server_const(const string buffer)
{
    send(client_sock, buffer.c_str(), strlen(buffer.c_str()), 0);
}

void send_to_server(string buffer) 
//신호만 보내는 경우 buffer에 const값만 적어주면 된다.
//내용도 보내는 경우 buffer를 수정해 줘야한다.
{
    send(client_sock, buffer.c_str(), strlen(buffer.c_str()), 0);
}

const string 로그인시도 = "00"; //send_id / recv_pw

void login_try() {
    while (1) {
        want_exit();
        
        string login_id = "";
        string login_pw = "";
        cout << "id를 입력하세요 : " << endl;
        cin >> login_id;
        cout << "pw를 입력하세요 : " << endl;
        cin >> login_pw;

        string send_try_login = 로그인시도 +" "+ login_id + " " + login_pw;
        send_to_server(send_try_login);

        vector<string> server_msg = recv_from_server();
        if (server_msg[0] == 로그인시도) //
        {
            if (server_msg[1] == False) 
            {
                cout << "ID나 PW가 틀렸습니다. "<<endl;
                continue; //원래는 clear 하고 다시 보여줌 (gui아닐 경우)
            }
            
            else if (server_msg[1] == True) //로그인 가능
            {
                cout << "로그인에 성공했습니다. "<<endl; //팝업으로 뜨겠죠?
                break;
            }
           
            else // 이상 오류
            {
                cout << "오류가 발생해 종료하겠습니다. " << endl;
                break;
            }
        }
    }
}




/*se
    친구 목록은 항상 보여짐
   친구요청버튼을 누르면 요청온 친구 목록이 보이고 수락 거절을 할수있음
   친구추가버튼을 누르면 완전한 아이디를 검색해서 친구 요청을 보낼 수 있음 
   모든 화면에는 닫기 버튼이 존재함
*/

void friend_home() {
    while (1) {
        vector<string> friend_home;
        vector<string> friend_list; // 친구 테이블 받아와서 값을 각각 저장하는 벡터
        friend_home.clear();
        friend_list.clear();
        vector<string> friend_request;
        vector<string> friend_request_list; //나에게 온 친구 요청 리스트
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
                        //친구목록은 기본페이지에 들어와있다
                             //테이블처럼 보이게 다시 바꿔줘야 한다 -_-
                        string friend_num = ""; //사용자의 선택
                        cout << "친구 홈에서 하고 싶은 메뉴 선택 " << endl;
                        cin >> friend_num;

                        if (friend_num == "친구요청_클")
                        {

                            send_to_server("친구요청_클" );
                            friend_request = recv_from_server();
                            if (friend_request[0] == "친구요청_서")
                            {



                            }
                        }


                        else if (friend_num == "친구검색_클")
                        {
                            while (1) {
                                want_exit();
                                string search_friend_id = "";
                                char add_answer;
                                cout << "검색할 아이디 입력" << endl;
                                cin >> search_friend_id;
                                send_to_server("친구검색_클" + search_friend_id);
                                vector<string> search_friend = recv_from_server();
                                if (recv_friend_home_num == "친구검색_클")
                                {
                                    if (search_friend[0] != "have")
                                        cout << "ID가 확인되지 않습니다. 다시 시도해주세요. " << endl;

                                    while (search_friend[0] == "have") //존재하는지 확인해주는 내용 받음
                                    {
                                        cout << search_friend_id << "는 존재합니다. \n 친구로 추가하시겠습니까? (Y/N)" << endl;//추가버튼 보여줌
                                        if (add_answer == 'Y')
                                        {
                                            ;
                                            friend_num == "친구신청_클";
                                            string msg = "친구신청_클"  + search_friend_id;
                                            send_to_server(msg);
                                            recv_from_server();
                                        }
                                        else if (add_answer == 'N')
                                            break;
                                        else
                                        {
                                            cout << "잘못 입력하셨습니다. 다시 시도해주세요.";
                                            continue;
                                        }
                                    }


                                }
                            }
                        }

                        else
                            cout << "오류 발생" << endl;
                    }
                }
            }
        }
    }
}

    //WSADATA wsa;
    //User user;

    //user의 정보 입력받고 class User에 안전하게 저장하기
//회원가입,회원수정
    //void create_userInfo() {
    //    User user;
    //    string inputID;
    //    string inputEmail;
    //    string inputPhone;
    //    string inputBirth;
    //    string inputNickname;
    //    string inputPW;
    //    string inputCha_num;


    //    cout << "ID를 입력하세요 " << endl;
    //    cin >> inputID;
    //    user.setMember_ID(inputID);

    //    cout << "이메일을 입력하세요 " << endl;
    //    cin >> inputEmail;
    //    user.setEmail(inputEmail);

    //    cout << "전화번호를 입력하세요\n (010-0000-0000 형식) " << endl;
    //    cin >> inputPhone;
    //    user.setPhone(inputPhone);

    //    cout << "주민번호 앞 6자리를 입력하세요. " << endl;
    //    cin >> inputBirth;
    //    user.setBirth(inputBirth);

    //    cout << "닉네임을 입력하세요 " << endl;
    //    cin >> inputNickname;
    //    user.setNickname(inputNickname);

    //    cout << "비밀번호를 입력하세요 " << endl;
    //    cin >> inputPW;
    //    user.setMember_PW(inputPW);

    //    cout << "캐릭터 번호를 입력하세요 " << endl;
    //    cin >> inputCha_num;
    //    user.setCha_num(inputCha_num);


    //}

    //user의 정보들을 자동으로 돌려주기 위해 벡터에 저장해 준다.

    string send_UserInfo() {
        string userinfo = "";
        userinfo.clear();
        string id;
        userinfo = id;
        return userinfo;
    }


    int main() {
        WSADATA wsa;

        // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
        // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
        // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
        int code = WSAStartup(MAKEWORD(2, 2), &wsa);

        if (!code) {
            
            client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 

            // 연결할 서버 정보 설정 부분
            SOCKADDR_IN client_addr = {};
            client_addr.sin_family = AF_INET;
            client_addr.sin_port = htons(7777);
            InetPton(AF_INET, TEXT("192.168.200.137"), &client_addr.sin_addr);

            while (1) {
                if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // 위에 설정한 정보에 해당하는 server로 연결!
                    cout << "Server Connect" << endl;
                    //send(client_sock, my_nick.c_str(), my_nick.length(), 0); // 연결에 성공하면 client 가 입력한 닉네임을 서버로 전송
                    break;
                }
                cout << "Connecting..." << endl;
            }

            std::thread th2(chat_recv);
            

            while (1) {
                string text;
                std::getline(cin, text);
                const char* buffer = text.c_str(); // string형을 char* 타입으로 변환
                
                send(client_sock, buffer, strlen(buffer), 0);
            }
            th2.join();
            closesocket(client_sock);
        }

        WSACleanup();
        return 0;
    }