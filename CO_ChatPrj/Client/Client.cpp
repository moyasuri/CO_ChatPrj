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


const string 로그인시도 = "00"; //send_id / recv_pw
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
User user;

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
//신호만 보내는 경우 buffer에 const값만 적어주면 된다.
//내용도 보내는 경우 buffer를 수정해 줘야한다.
{
    send(client_sock, buffer.c_str(), strlen(buffer.c_str()), 0);
}

const string 로그인시도 = "00"; //send_id / recv_pw

void login_try() {
    while (1) {
        
        string login_id = "";
        string login_pw = "";
        cout << "id를 입력하세요 : " << endl;
        cin >> login_id;
        cout << "pw를 입력하세요 : " << endl;
        cin >> login_pw;

        string send_login_id = 로그인시도 + login_id;
        send_to_server(send_login_id);

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
const string ID찾기 = "01";
const string PW찾기 = "02";

const string 친구목록_클 = "21";
const string 친구요청_클 = "22";
const string 친구검색_클 = "23";
const string 친구신청_클 = "24";

const string 친구목록_서 = "21";
const string 친구요청_서 = "22";
const string 친구검색_서 = "23";
const string 친구신청_서 = "24";

/*
    친구 목록은 항상 보여짐
   친구요청버튼을 누르면 요청온 친구 목록이 보이고 수락 거절을 할수있음
   친구추가버튼을 누르면 완전한 아이디를 검색해서 친구 요청을 보낼 수 있음 
   모든 화면에는 닫기 버튼이 존재함
*/

void friend_home() {
    while (1) {
        
        vector<string> friend_list; // 친구 테이블 받아와서 값을 각각 저장하는 벡터
        send_to_server(친구목록_클);
        recv_from_server();
        string recv_friend_home_num = recv_from_server_num();
        string recv_friend_home_text = recv_from_server_text();
        if (recv_friend_home_num == 친구목록_서)
        {
        string s;
        std::stringstream ss(recv_friend_home_text);
        while (ss >> s) {
            friend_list.push_back(s);
        }
        //테이블처럼 보이게 다시 바꿔줘야 한다 -_-
        if (recv_friend_home_num == 친구목록_클) {
            while (1) {
                //친구목록은 기본페이지에 들어와있다
                string friend_num=""; //사용자의 선택
                cout << "친구 홈에서 하고 싶은 메뉴 선택" << endl;
                cin >> friend_num;

                    if (friend_num == 친구요청_클)
                    {
                        send_to_server(친구요청_클);
                        recv_from_server();
                        if (recv_friend_home_num == 친구요청_서)
                            recv_from_server_text();
                    }

                    
                    else if (friend_num == 친구검색_클)
                    {
                        while (1) {
                            want_exit();
                            string search_friend_id = "";
                            char add_answer;
                            cout << "검색할 아이디 입력" << endl;
                            cin >> search_friend_id;
                            send_to_server(친구검색_클 + search_friend_id);
                            recv_from_server();
                            if (recv_friend_home_num == 친구검색_클)
                            {
                                if (recv_from_server_text() != "have")                   
                                    cout << "ID가 확인되지 않습니다. 다시 시도해주세요. " << endl;
                               
                                while(recv_from_server_text() == "have") //존재하는지 확인해주는 내용 받음
                                {
                                    cout << search_friend_id << "는 존재합니다. \n 친구로 추가하시겠습니까? (Y/N)" << endl;//추가버튼 보여줌
                                    if (add_answer == 'Y')
                                    {
                                        ;
                                        friend_num == 친구신청_클;
                                        send_to_server(친구신청_클 + search_friend_id);
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

