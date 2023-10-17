#pragma comment(lib, "ws2_32.lib")

#include <WinSock2.h> //Winsock 헤더파일 include. WSADATA 들어있음.
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <vector>
// user 헤더 추가
#include "User.cpp"

using namespace std;

//string으로 정보를 모두 받아줘야 하고 (socket에 char 형식으로만 전달 가능해 c_str 사용해야 하기 때문) 
//서버에 전달 후 서버에서 string으로 다시 받아 int변환 등 처리해서 mysql로 보내준다.
#define MAX_SIZE 1024

using std::cout;
using std::cin;
using std::endl;
using std::string;

SOCKET client_sock;
SOCKET client_info_sock;
string my_nick;


const string 로그인시도 = "00";
const string ID찾기 = "01";
const string PW찾기 = "02";


//const string 정보 변경= "10";
const string 비밀번호수정 = "11";
const string 이메일수정 = "12";
const string 전화번호수정="13";
const string 생년월일수정 = "14";
const string 닉네임수정= "15";
const string 캐릭터수정= "16";
const string 참여방변경 = "17";

//const string 친구 = "20";

const string 친구목록= "21";
const string 친구요청= "22";
const string 친구검색= "23";
const string 친구신청= "24";
//const string = "";
//const string = "";
//const string = "";

//const string 쪽지 //친구검색 쓰임 30
const string 쪽지목록 = "31";
const string 쪽지읽기= "32";
const string 쪽지보내기= "33";
const string 쪽지삭제하기= "34";


//쪽지 
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

int chat_recv() {
    char buf[MAX_SIZE] = { };
    string msg;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
            msg = buf;
            std::stringstream ss(msg);  // 문자열을 스트림화
            string identity_num;
            string text;
            ss >> identity_num >> text; // 스트림을 통해, 문자열을 공백 분리해 변수에 할당. 보낸 사람의 이름만 user에 저장됨
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
        std::stringstream ss(msg);  // 문자열을 스트림화
        ss >> identify_num ;
        server_msg.push_back(identify_num);
        text = string(buf + 3);
        server_msg.push_back(text);
    }
    return server_msg;
}

void login_try() {
    while (1) {
        User user;
        string login_id = "";
        string login_pw = "";
        cout << "id를 입력하세요 : " << endl;
        cin >> login_id;
        cout << "pw를 입력하세요 : " << endl;
        cin >> login_pw;

        string send_login_id = "00 " + login_id;

        send(client_sock, send_login_id.c_str(), send_login_id.length(), 0);

        vector<string> server_msg = recv_from_server();


        if (server_msg[0] == 로그인시도) //
        {
            if (server_msg.size() == 1) //id가 존재하지 않아 server에서 00만 전송된 경우
            {
                cout << "ID가 존재하지 않습니다. "<<endl;
                continue; //원래는 clear 하고 다시 보여줌 (gui아닐 경우)
            }
            else if (server_msg[1] != login_pw) //id에 따른 pw 불일치
            {
                cout << "비밀번호가 일치하지 않습니다. " << endl;
                continue;
            }
            else if (server_msg[1] == login_pw) //로그인 가능
            {
                cout << "로그인에 성공했습니다. "<<endl; //팝업으로 뜨겠죠?
                user.setMember_ID(login_id);
                user.setMember_PW(login_pw);
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

const string 친구목록 = "21";
const string 친구요청 = "22";
const string 친구검색 = "23";
const string 친구신청 = "24";

void friend_home() {
    vector<string> friend_list;
        vector<string> friends= recv_from_server();
    if (friends[0] == 친구목록)
    {
        friends[1];
        string s;
        std::stringstream ss(friends[1]);
        while( ss >> s){
            friend_list.push_back(s);
        }

    }
    else if (friends[0] == 친구요청)
    {

    }
    else if (friends[0] == 친구검색)
    {

    }
    else if (friends[0] == 친구신청)
    {

    }
    else
        cout << "오류 발생" << endl;


}
    //WSADATA wsa;
    //User user;

    //user의 정보 입력받고 class User에 안전하게 저장하기
//회원가입,회원수정
    void create_userInfo() {
        User user;
        string inputID;
        string inputEmail;
        string inputPhone;
        string inputBirth;
        string inputNickname;
        string inputPW;
        string inputCha_num;


        cout << "ID를 입력하세요 " << endl;
        cin >> inputID;
        user.setMember_ID(inputID);

        cout << "이메일을 입력하세요 " << endl;
        cin >> inputEmail;
        user.setEmail(inputEmail);

        cout << "전화번호를 입력하세요\n (010-0000-0000 형식) " << endl;
        cin >> inputPhone;
        user.setPhone(inputPhone);

        cout << "주민번호 앞 6자리를 입력하세요. " << endl;
        cin >> inputBirth;
        user.setBirth(inputBirth);

        cout << "닉네임을 입력하세요 " << endl;
        cin >> inputNickname;
        user.setNickname(inputNickname);

        cout << "비밀번호를 입력하세요 " << endl;
        cin >> inputPW;
        user.setMember_PW(inputPW);

        cout << "캐릭터 번호를 입력하세요 " << endl;
        cin >> inputCha_num;
        user.setCha_num(inputCha_num);


    }

    //user의 정보들을 자동으로 돌려주기 위해 벡터에 저장해 준다.
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

            // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
            // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
            // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
            int code = WSAStartup(MAKEWORD(2, 2), &wsa);
            int iclient_menu = 0;

            if (!code) {

                client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); 
                SOCKADDR_IN client_addr = {};
                client_addr.sin_family = AF_INET;
                client_addr.sin_port = htons(7777);
                InetPton(AF_INET, TEXT("127.0.0.1"), &client_addr.sin_addr);



                while (1) {
                    if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // 위에 설정한 정보에 해당하는 server로 연결!
                        cout << "Server Connect" << endl;
                    }

                    switch (client_func_num(recv_from_server)) {
                    case 1:
                        ;
                        break;
                    case (2):

                    
                    
                    }

                        send(client_sock, my_nick.c_str(), my_nick.length(), 0); // 연결에 성공하면 client 가 입력한 닉네임을 서버로 전송
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
            
            WSACleanup();
            return 0;
        }

