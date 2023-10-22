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
#include <mysql/jdbc.h>
#include "UsageServer.h"
#include "UserInfo.h"
#include "Room.h"
#define MAX_SIZE 1024//소켓 박스크기
#define MAX_CLIENT 3

//using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::string;

string _Index;
const time_t timer = time(NULL);
const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

bool isNumeric(const std::string& str);

string getCurrentTime();
const std::string nowTime = getCurrentTime();


string s_(int e_num) {
    return std::to_string(e_num);
}

struct SOCKET_INFO { // 연결된 소켓 정보에 대한 틀 생성
    SOCKET sck;
    UserInfo user;
    Room room;
    string user_;
};

std::vector<SOCKET_INFO> sck_list; // 연결된 클라이언트 소켓들을 저장할 배열 선언.
SOCKET_INFO server_sock; // 서버 소켓에 대한 정보를 저장할 변수 선언.
int client_count = 0; // 현재 접속해 있는 클라이언트를 count 할 변수 선언.
SOCKET Client_sck; // =  sck_list[];

//기존함수들
void server_init(); // socket 초기화 함수. socket(), bind(), listen() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void add_client(); // 소켓에 연결을 시도하는 client를 추가(accept)하는 함수. client accept() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void send_msg(const char* msg); // send() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void recv_msg(int idx); // recv() 함수 실행됨. 자세한 내용은 함수 구현부에서 확인.
void del_client(int idx); // 소켓에 연결되어 있는 client를 제거하는 함수. closesocket() 실행됨. 자세한 내용은 함수 구현부에서 확인.

void recv_from_client(int idx); //선언
const string IDENTIFIER = " ";
const string True = "true";
const string False = "false";




class MY_SQL {
public:
    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
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

        // 데이터베이스 선택
        con->setSchema("chat");

        // db 한글 저장을 위한 셋팅 
        stmt = con->createStatement();
        //stmt->execute("set names 'utf8'");
        stmt->execute("set names euckr");
        //if (stmt) { delete stmt; stmt = nullptr; }

    }

  
         //아이디 중복확인
        string signup_IDchk(string recv_content) {

        std::stringstream ss(recv_content);
        string mysql_check_id;
        ss >> mysql_check_id;
        sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Member_ID = '" + mysql_check_id + "'");
        string result;
        if (res->next()) {
            result = s_(e_signup_IDchk) + IDENTIFIER + False; //이미 존재하는 값이니 id 다른 거로 설정해
        }
        else
        {
            result = s_(e_signup_IDchk) + IDENTIFIER + True;
        }
        
        cout << " result : " << result;
        send(Client_sck, result.c_str(), result.size(), 0);
        cout << "send(Client_sck, result.c_str(), result.size(), 0);";
        return result;
       
    }

        string signup_Nicknamechk(string recv_content, int this_idx) {
            cout << " string send_signup_Nicknamechk(string recv_content) " << endl;
            std::stringstream ss(recv_content);
            string mysql_check_nickname;
            ss >> mysql_check_nickname;
            
            sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Nickname = '" + mysql_check_nickname + "'");            
            string result;
            if (res->next()) {
                result = s_(e_signup_NickNamechk) + IDENTIFIER + False; //이미 존재하는 값이니 id 다른 거로 설정해
            }
            else
            {
                result = s_(e_signup_NickNamechk) + IDENTIFIER + True;
            }
            //try {
            //    prep_stmt = con->prepareStatement("SELECT Nickname FROM member WHERE Nickname = ?");
            //    cout << "prep_stmt = con->prepareStatement 실행" << endl;
            //    prep_stmt->setString(1, mysql_check_nickname);
            //    string result;
            //    sql::ResultSet* res = prep_stmt->executeQuery();
            //    if ((res->next()))
            //        result = s_(e_signup_NickNamechk) + IDENTIFIER + False; //이미 존재하는 값이니 nickname 다른 거로 설정해
            //    else
            //        result = s_(e_signup_NickNamechk) + IDENTIFIER + True;
            //    cout << "result " << result << endl;;
            //    return result;
            //} catch (sql::SQLException& e) {
            //    cout << "#\t SQL Exception: " << e.what();
            //    cout << " (MySQL error code: " << e.getErrorCode();
            //    cout << ", SQLState: " << e.getSQLState() << " )" << endl;
            //    return "";
            //}
            return result;
            send(Client_sck, result.c_str(), result.size(), 0);
        }

        //send함수만 따로 만들어놓는게 좋겠다. return string으로 result를 반환하고 
        // pw 중복 체크,생일 체크 등은 이상값을 클라이언트에서 처리하고 mysql쿼리보내기만 전체적으로 실행한다.
        string signup_Submit(string recv_content) {
            std::stringstream ss(recv_content);
            string Member_ID;
            string Email;
            string Phone;
            string Birth;
            string Nickname;
            string Cha_Num;
            string Member_PW;
            string Name;
         
            ss >> Member_ID>> Email >>Phone >> Birth>> Nickname>> Cha_Num >> Member_PW >>Name;
            cout << Member_ID << Email << Phone << Birth << Nickname << Cha_Num << Member_PW << Name << endl;;
            prep_stmt = con->prepareStatement("INSERT INTO member VALUES (?,?,NULL,?,?,?,?,?,NULL,?);");
            prep_stmt->setString(1, Member_ID);
            prep_stmt->setString(2, Email);
            prep_stmt->setString(3,Phone);
            prep_stmt->setString(4,Birth);
            prep_stmt->setString(5, Nickname);
            prep_stmt->setString(6, Cha_Num);
            prep_stmt->setString(7, Member_PW);
            prep_stmt->setString(8, Name);
            string result;
            int rows_affected = prep_stmt->executeUpdate();
            cout << "rows_affected : " << rows_affected << endl;
            if (rows_affected > 0)
            {
                result = s_(e_signup_Submit) + IDENTIFIER + True; //회원가입 등록 완
                cout << " result = s_(e_signup_Submit) + IDENTIFIER + True; //회원가입 등록 완 ";
            }
            else
            {
                result = s_(e_signup_Submit) + IDENTIFIER + False;//등록 실패
                cout << " result = s_(e_signup_Submit) + IDENTIFIER + False; //회원가입 등록 x ";
            }
            return result;
       
        }
   
    //로그인확인하기
    string try_Signin( string recv_content, int this_idx) {
        std::stringstream ss(recv_content);
        string mysql_check_id;
        string mysql_check_pw;
        ss >> mysql_check_id >> mysql_check_pw;
        
        cout << "mysql_check_id : " << mysql_check_id << "mysql_check_pw : " << mysql_check_pw;
        prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = ? AND Member_PW = ?");
        prep_stmt->setString(1, mysql_check_id);
        prep_stmt->setString(2, mysql_check_pw);
        cout << " prep_stmt = con->prepareStatement : 실행완료" << endl;
        string result;
        sql::ResultSet* res = prep_stmt->executeQuery();
            if ((res->next()))
            {
            result = s_(e_id_try_Signin) + IDENTIFIER + True;
            sck_list[this_idx].user.setID(mysql_check_id);
            sck_list[this_idx].user.setPW(mysql_check_pw);
            cout << "로그인 성공 \n";
            }
            else
            {
                result = s_(e_id_try_Signin) + IDENTIFIER + False;
                cout << "로그인 실패 \n";
            }
            string my_ID = sck_list[this_idx].user.getID();
            cout << "string my_ID = sck_list[this_idx].user.getID(); " << my_ID << endl;
        return result;
     
    }

       //아이디찾기
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
            result = s_(e_id_find_ID) + IDENTIFIER + True+ IDENTIFIER + resid; //true false 는 const string True = "True" 등으로 위에 있습니다
        else 
            result = s_(e_id_find_ID) + IDENTIFIER + False;
       return result;
    
    }
       //비밀번호찾기
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
            cout << "  if (res->next()):" << respw<< "해결" << endl;
            if (respw.size() != 0)
            {
                result = s_(e_id_find_PW) + IDENTIFIER + True + IDENTIFIER + respw;
            }
            else
            {
                result = s_(e_id_find_PW) + IDENTIFIER + False;
            }
            return result;
         
            
        }

    // e_edit_PWchk = 31 수정하려는 비밀번호 받았을 때 mysql 쿼리 변경, 유저의 아이디 가지고 있어야 함 
        string edit_PWchk(string recv_content, int this_idx) {
            std::stringstream ss(recv_content);
            string my_ID = sck_list[this_idx].user.getID();
            string mysql_check_pw;
            string result;
            ss >> mysql_check_pw;
            cout << endl<<"ss >> mysql_check_pw; "<< mysql_check_pw << endl;
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = ? AND Member_PW = ?");
        prep_stmt->setString(1, my_ID);
        prep_stmt->setString(2, mysql_check_pw);
        sql::ResultSet* res = prep_stmt->executeQuery();
        cout << "sql::ResultSet* res = prep_stmt->executeQuery(); 완료 "<< res<< endl;
        if ((res->next()))
        {
            result = s_(e_edit_PWchk) + IDENTIFIER+ True;
            cout << " 성공 result : " << result << endl;
        }
        else
        {
            result = s_(e_edit_PWchk) + IDENTIFIER+ False;
            cout << " 실패 result : " << result << endl;
        }
        return result;
   
    }

        //단순 중복 체크
        string edit_Nicknamechk(string recv_content, int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            string check_nickname;
            string result;
            std::stringstream ss(recv_content);
            ss >> check_nickname;
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Nickname = ?");
            prep_stmt->setString(1, check_nickname);
            cout << "prep_stmt = con->prepareStatement : " << my_ID << " " << check_nickname << endl;
            sql::ResultSet* res = prep_stmt->executeQuery();
            if ((res->next()))
            {
                result = s_(e_edit_NickNamechk) + IDENTIFIER+ False;
            }
            else
            {
                result = s_(e_edit_NickNamechk) + IDENTIFIER+ True;
            }
            cout << "result : " << result << endl;
            return result;
            
        }

        string edit_Confirm(string recv_content, int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            std::stringstream ss(recv_content);
            string Email;
            string Phone;
            string Nickname;
            string Cha_Num;
            string Member_PW;
         

            string result;

            ss >> Email >> Phone  >> Nickname >> Cha_Num >> Member_PW ;

            prep_stmt = con->prepareStatement("update member set Email = ?, Phone =?, Nickname = ?,Cha_Num = ?,Member_PW=? WHERE  Member_ID = ?");
            
            prep_stmt->setString(1, Email);
            prep_stmt->setString(2, Phone);
            prep_stmt->setString(3, Nickname);
            prep_stmt->setString(4, Cha_Num);
            prep_stmt->setString(5, Member_PW);
            prep_stmt->setString(6, my_ID);

            int rows_affected = prep_stmt->executeUpdate();
            cout << "rows_affected : " << rows_affected << endl;
            if (rows_affected > 0)
                result = s_(e_edit_Confirm) + IDENTIFIER + True; //정보 수정 성공
            else
                result = s_(e_edit_Confirm) + IDENTIFIER + False;//정보 수정 실패
            cout << "result : " << result << endl;
        
            sck_list[this_idx].user.setChaNum(std::stoi(Cha_Num));
            sck_list[this_idx].user.setEmail(Email);
            sck_list[this_idx].user.setNickName(Nickname);
            sck_list[this_idx].user.setPhone(Phone);
            sck_list[this_idx].user.setPW(Member_PW);

            return result;
         
        }


 /*       string edit_Confirm(string recv_content) {
            res = stmt->executeQuery("update member set name = "" where id = "john123";");

        }*/

        string message_unread_List(int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            string result;
            string from_ID;
            string datetime;
            string text;
            sql::ResultSet* res = stmt->executeQuery("SELECT From_Short_Note_ID, Short_Note_Datetime, Short_Note_text FROM short_note WHERE To_Short_Note_ID = '" + my_ID + "' AND Respond_Short_Note = 3;");
            string value = "";
            
            while (res->next())
            {
                value = value + IDENTIFIER + res->getString(1) + IDENTIFIER + res->getString(2) + IDENTIFIER + res->getString(3);
            }
            if (value.size()>0)
                result = s_(e_message_unread_List) + IDENTIFIER + value;
            else 
                result = s_(e_message_unread_List) + IDENTIFIER + False;

            cout << "result : " << result;
            //주의? 한 열씩 가는 거 인지해두기
           
           

            return result;
           
        }

        //읽음 처리를 위해 메시지의 시간을 받아온다 
        string message_Read(string recv_content, int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            string from_ID;
            string date;
            string time;
            std::stringstream ss(recv_content);
            ss >> from_ID>> date >> time;
            string datetime = date + IDENTIFIER + time;
            cout << "from_ID : " << from_ID << endl << "datetime ; " << datetime << endl;
            cout << "datetime : "<< datetime<<endl;
            cout << "from_ID: " << from_ID << endl;
            string result;
            prep_stmt = con->prepareStatement("update short_note set Respond_Short_Note = 1 WHERE  To_Short_Note_ID = ? AND Short_Note_Datetime =? AND From_Short_Note_ID = ? And Respond_Short_Note = 3;");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, datetime );
            prep_stmt->setString(3, from_ID);
            int rows_affected = prep_stmt->executeUpdate();
            cout << "rows_affected : " << rows_affected << endl;
            if (rows_affected > 0) 
            {
                result = s_(e_message_Read) + IDENTIFIER + True;
                cout << "result = s_(e_message_Read) + IDENTIFIER + True;" << endl;
                
            }
            else
            {
                result = s_(e_message_Read) + IDENTIFIER + False;
                cout << "result = s_(e_message_Read) + IDENTIFIER + False;" << endl;
            }
            return result;
           
        }
        
        //client에서 내용 받을때 주의 getLine으로 받을거라 enter값으로 보내지기
        string message_Send(string recv_content, int this_idx) {
            std::stringstream ss(recv_content);
            std::vector<string> dis_content;
            string line;
            string friend_ID;
            string text="";
            string datetime = getCurrentTime();
            string my_ID = sck_list[this_idx].user.getID();
            string result;
            int count = 0;
            dis_content.clear();
            while (std::getline(ss, line)) {
                dis_content[count] = line;
                count++;
            }
            friend_ID = dis_content[0];
            dis_content.erase(dis_content.begin());
            for (auto msgLine : dis_content)
                text +=  msgLine+"\n"; //정보 뺀 메시지 내용만 string으로 받아줌
           
            prep_stmt = con->prepareStatement("INSERT INTO short_note VALUES (NULL,?,?,3,?,?);");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, friend_ID);
            prep_stmt->setString(3, datetime);
            prep_stmt->setString(4, text);
            //datetime 서버에서 설정 
            int rows_affected = prep_stmt->executeUpdate();
            cout << "rows_affected : " << rows_affected << endl;
            if (rows_affected > 0)
                result = s_(e_message_Send) + IDENTIFIER + True;
            else
                result = s_(e_message_Send) + IDENTIFIER + False;
            return result;
        }

        string message_Delete(string recv_content, int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            string from_ID;
            string date;
            string time;
            std::stringstream ss(recv_content);
            ss >> from_ID >> date >> time;
            string datetime = date + IDENTIFIER + time;
            cout << "datetime : " << datetime << endl;
            cout << "from_ID: " << from_ID << endl;
            string result;
            prep_stmt = con->prepareStatement("DELETE FROM short_note WHERE  To_Short_Note_ID = ? AND Short_Note_Datetime =? AND From_Short_Note_ID = ? ;");

            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, datetime);
            prep_stmt->setString(3, from_ID);
            cout << "prep_stmt->setString(2, from_ID); : good" << endl;
            /*bool res = prep_stmt->execute();
            cout << " res:  " << res << endl;*/
            //질문 execute도 정상수행되어 값이 변경되었음에도 계속 result값이 false로 나옴
            int rows_affected = prep_stmt->executeUpdate();
            cout << "rows_affected : " << rows_affected << endl;
            if (rows_affected > 0)
            {
                result = s_(e_message_unread_Delete) + IDENTIFIER + True;
                cout << "result = s_(e_message_) + IDENTIFIER + True;" << endl;
            }
            else
            {
                result = s_(e_message_unread_Delete) + IDENTIFIER + False;
                cout << "result = s_(e_message_Read) + IDENTIFIER + False;" << endl;
            }


            return result;
            send(Client_sck, result.c_str(), result.size(), 0);
        }
     

        //response 1 수락 2 거절 3 무응답
        string friends_List(int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            cout << "my_ID : " << my_ID << endl;
            string result;
            prep_stmt = con->prepareStatement("SELECT Distinct My_Friend_ID From friend_list WHERE My_ID = ?;");
            prep_stmt->setString(1, my_ID);
            sql::ResultSet* res = prep_stmt->executeQuery();
            cout << "sql::ResultSet* res = prep_stmt->executeQuery(); 수행 완료 "  << endl;
            //질문 execute도 정상수행되어 값이 변경되었음에도 계속 result값이 false로 나옴
            string value = "";
            while (res->next())
            {
                value = value + IDENTIFIER + res->getString(1);
            }
            if (value.size() > 0)
                result = s_(e_friends_List)+ value;
            else
                result = s_(e_friends_List) + IDENTIFIER + False;
            

            cout << result << endl;
  
            return result;
           
        }

        string friends_request_List(int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            cout << "my_ID : " << my_ID << endl;
            string result;
            prep_stmt = con->prepareStatement("SELECT Distinct From_Friend_Request_ID, Request_Msg From friend_request WHERE To_Friend_Request_ID = ? AND response =3;");
            prep_stmt->setString(1, my_ID);
            sql::ResultSet* res = prep_stmt->executeQuery();
            cout << "sql::ResultSet* res = prep_stmt->executeQuery(); 수행 완료 " << endl;
            //질문 execute도 정상수행되어 값이 변경되었음에도 계속 result값이 false로 나옴
            string value = "";
            while (res->next())
            {
                value = value + IDENTIFIER + res->getString(1)+ IDENTIFIER + res->getString(2);
            }
            cout << value << endl;
            
            if (value.size() > 0)
                result = s_(e_friends_List) + value;
            else
                result = s_(e_friends_List) + IDENTIFIER + False;


            cout << result << endl;

            return result;
        }

        string friends_Delete(string recv_content, int this_idx) {
            cout<<"" <<""<< endl;
            std::stringstream ss(recv_content);
            string friend_ID = "";
            ss >> friend_ID;
            string my_ID = sck_list[this_idx].user.getID();
            string result;
            cout << "string my_ID = sck_list[this_idx].user.getID(); " << my_ID<< endl;
            prep_stmt = con->prepareStatement("DELETE From friend_list WHERE My_ID = ? AND My_Friend_ID = ?;");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, friend_ID);
            int rows_affected = prep_stmt->executeUpdate();
            prep_stmt = con->prepareStatement("DELETE From friend_list WHERE My_ID = ? AND My_Friend_ID = ?;");
            prep_stmt->setString(1,friend_ID );
            prep_stmt->setString(2, my_ID);
            int rows_affected2 = prep_stmt->executeUpdate();
            cout << "rows_affected : " << rows_affected << endl;
            if (rows_affected2 > 0){
                result = s_(e_friends_Delete) + IDENTIFIER + True;
                cout << " result = s_(e_friends_Delete) + IDENTIFIER + True; " << result << endl;
            }
            else
            {
                result = s_(e_friends_Delete) + IDENTIFIER + False;
                cout << " result = s_(e_friends_Delete) + IDENTIFIER + True; " << result << endl;
            }
            cout << " return result; " << result << endl;
            return result;
            send(Client_sck, result.c_str(), result.size(), 0);
        }
        //친구 요청 보내기, ID가 존재한다면 요청 보내고 존재하지 않는다면 false반환
        string friends_Request(string recv_content, int this_idx) {
            std::stringstream ss(recv_content);
            std::vector<string> id_msg;
            id_msg.clear();
            string s;
            string friend_ID = "";
            string request_msg = "";
            while (ss >> s)
                id_msg.push_back(s);
            id_msg[0] = friend_ID;
            id_msg.erase(id_msg.begin());
            for (auto line : id_msg)
                request_msg = request_msg + line +IDENTIFIER;
            string my_ID = sck_list[this_idx].user.getID();
            string result;
            cout << request_msg << endl;
            prep_stmt = con->prepareStatement("SELECT Member_ID  FROM member WHERE member_ID = ?");
            prep_stmt->setString(1, friend_ID);
            sql::ResultSet*res = prep_stmt->executeQuery();
            if (res != NULL)
            {
                prep_stmt = con->prepareStatement("INSERT INTO friend_request VALUES()");
            }


        }

        string friends_Request_Decline(string recv_content, int this_idx) {
            std::stringstream ss(recv_content);
            string friend_ID = "";
            ss >> friend_ID;
            string my_ID = sck_list[this_idx].user.getID();
            string result;
            prep_stmt = con->prepareStatement("DELETE FROM friend_request WHERE To_Friend_Request_ID = ? AND From_Friend_Request_ID= ? AND Response =3;");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, friend_ID);
            int rows_affected = prep_stmt->executeUpdate();
            cout << "rows_affected : " << rows_affected << endl;
            if (rows_affected > 0)
            {
                result = s_(e_friends_Request_Decline) + IDENTIFIER + True;
            }
            else {
            result = s_(e_friends_Request_Decline) + IDENTIFIER + False;
              }
            return result;
            send(Client_sck, result.c_str(), result.size(), 0);
        }

        string friends_Request_Accept(string recv_content, int this_idx) {
            std::stringstream ss(recv_content);
            string friend_ID = "";
            ss >> friend_ID;
            string my_ID = sck_list[this_idx].user.getID();
            string result;
            prep_stmt = con->prepareStatement("UPDATE friend_request set Response = 1 WHERE To_Friend_Request_ID = ? AND From_Friend_Request_ID= ? AND Response =3;");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, friend_ID);
            int rows_affected = prep_stmt->executeUpdate();
            prep_stmt = con->prepareStatement("INSERT INTO friend_list (My_ID  ,My_Friend_ID) VALUES (?,?);");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, friend_ID);
            int rows_affected2 = prep_stmt->executeUpdate();
            prep_stmt = con->prepareStatement("INSERT INTO friend_list (My_ID  ,My_Friend_ID) VALUES (?,?);");
            prep_stmt->setString(1, friend_ID);
            prep_stmt->setString(2, my_ID);
            int rows_affected3 = prep_stmt->executeUpdate();
            int sum = rows_affected + rows_affected2 + rows_affected3;
            cout << "rows_affected sum : " << sum << endl;
            if (sum > 2)
            {
                result = s_(e_friends_Request_Decline) + IDENTIFIER + True;
                prep_stmt = con->prepareStatement("INSERT INTO friend_list VALUES(NULL,?,?);");
                prep_stmt->setString(1, my_ID);
                prep_stmt->setString(2, friend_ID);
                prep_stmt = con->prepareStatement("INSERT INTO friend_list VALUES(NULL,?,?);");
                prep_stmt->setString(2, my_ID);
                prep_stmt->setString(1, friend_ID);
                sql::ResultSet* res = prep_stmt->executeQuery();
            }
            else {
                result = s_(e_friends_Request_Decline) + IDENTIFIER + False;
            }
            return result;
            send(Client_sck, result.c_str(), result.size(), 0);
        }

        //room type (서버 1 공개 2 비공개 3) - room_Name - room_PW(없으면 0(공개방)) 순으로 보내주세요!
        string room_Create(string recv_content, int index) {
            std::stringstream ss(recv_content);
            string result;
            string room_Type;
            int i_room_Type;
            string room_PW;
            string room_Name;
            string my_ID = sck_list[index].user.getID();
            string room_date = getCurrentTime();
            ss >> room_Type >> room_Name >> room_PW; // pw가 없는 경우에 0이라도 보내주길 요청
            cout << room_Type << IDENTIFIER << room_Name << IDENTIFIER << room_PW << endl;
            i_room_Type = std::stoi(room_Type);
            if (i_room_Type == (2 || 3))
            {
                prep_stmt = con->prepareStatement("INSERT INTO room_list (Room_Type,Room_Title,Room_Master,Room_Date,Room_PW) VALUES (?,?,?,?,?);");
                prep_stmt->setInt(1, i_room_Type);
                prep_stmt->setString(2, room_Name);
                prep_stmt->setString(3, my_ID);
                prep_stmt->setString(4, room_date);
                prep_stmt->setString(5, room_PW);
                bool t_or_f = prep_stmt->execute();
                cout << "t_or_f :" << t_or_f << endl;
                if (t_or_f == 1)
                {
                    prep_stmt = con->prepareStatement("SELECT* from room_list WHERE room_Type =? AND room_Name = ?;");
                    prep_stmt->setInt(1, i_room_Type);
                    prep_stmt->setString(2, room_Name);
                    sql::ResultSet* res = prep_stmt->executeQuery();
                    if (res->next())
                    {
                        sck_list[index].room.setRoom_Index(res->getInt(1));
                        sck_list[index].room.setRoom_Type(res->getInt(2));
                        sck_list[index].room.setRoom_Title(res->getString(3));
                        sck_list[index].room.setRoom_Master(res->getString(4));
                        sck_list[index].room.setRoom_Date(res->getString(5));
                        sck_list[index].room.setRoom_PW(res->getString(6));
                        sck_list[index].user.setJoinRoomIndex(s_(sck_list[index].room.getRoom_Index()));
                        cout << "정보 저장 완료";
                        result = s_(e_room_Create) + IDENTIFIER + True + IDENTIFIER + sck_list[index].user.getJoinRoomIndex();
                        cout << "result : " << result << endl;
                        return result;

                        //성공시 들어가는 방의 index (room_list의 primary key) 보내줌
                    }
                    else {
                        cout << "등록은 성공 but 정보 저장 실패" << endl;
                        result = s_(e_room_Create) + IDENTIFIER + False;
                        return result;
                    }
                }
                else
                {
                    cout << "등록은 성공 but 정보 저장 실패" << endl;
                    result = s_(e_room_Create) + IDENTIFIER + False;
                    return result;
                }
            }
            else
            {
                cout << "INSERT INTO 실패"<<endl;
                result = s_(e_room_Create) + IDENTIFIER + False;
                return result;
            }
        }

        string room_Exit(int index) {
            string my_ID = sck_list[index].user.getID();
            string result;
            prep_stmt = con->prepareStatement("UPDATE member set Join_Room_Index = NULL member_ID = ? ;");
            prep_stmt->setString(1, my_ID);          
            int rows_affected = prep_stmt->executeUpdate();
            cout << "int rows_affected = prep_stmt->executeUpdate(); " << rows_affected << endl;
            if (rows_affected > 0) {
                sck_list[index].room.room_init();//방정보 초기화
                result = s_(e_room_Exit) + IDENTIFIER + True;
                sck_list[index].user.setJoinRoomIndex(NULL);
            }
            else 
                result = s_(e_room_Exit) + IDENTIFIER + False;
        }
        
        //들어가는 방 type , 방 제목, pw 받아오기 공개방의 경우 pw =0
        string room_Enter(string recv_content, int index) {
            string my_ID = sck_list[index].user.getID();
            string result;
            string room_Type;
            string room_Name;
            string room_PW;
            int i_room_Type = std::stoi(room_Type);
            std::stringstream ss(recv_content);
            ss >> room_Type >> room_Name >> room_PW;
            prep_stmt = con->prepareStatement("UPDATE member set Join_Room_Index = ? member_ID = ? ;");
            prep_stmt->setString(1, my_ID);
        }
  
private:
};

MY_SQL mysql;

void user_info_state() {


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
    //*
    server_sock.user_ = "server";

    cout << "Server On" << endl;
}

//void add_client() {
//    SOCKADDR_IN addr = {};
//    int addrsize = sizeof(addr);
//    char buf[MAX_SIZE] = { };
//
//    ZeroMemory(&addr, addrsize); // addr의 메모리 영역을 0으로 초기화
//
//    SOCKET_INFO new_client = {};
//
//    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
//    recv(new_client.sck, buf, MAX_SIZE, 0);
//    cout << "buf 확인 1 " << buf << endl;
//    // Winsock2의 recv 함수. client가 보낸 닉네임을 받음.
//    new_client.user = string(buf);
//
//    string msg = "[공지] " + new_client.user + " 님이 입장했습니다.";
//    cout << msg << endl;
//    sck_list.push_back(new_client); // client 정보를 답는 sck_list 배열에 새로운 client 추가
//
//    std::thread th(recv_msg, client_count);
//    // 다른 사람들로부터 오는 메시지를 계속해서 받을 수 있는 상태로 만들어 두기.
//
//    client_count++; // client 수 증가.
//    cout << "[공지] 현재 접속자 수 : " << client_count << "명" << endl;
//    send_msg(msg.c_str()); // c_str : string 타입을 const chqr* 타입으로 바꿔줌.
//
//    th.join();
//}

int client_num = 0;
void add_client1() { //add_client  변형해서 우리 상황에 맞게 사용하고 싶음
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr의 메모리 영역을 0으로 초기화

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize); //프로그램을 실행할때 무조건 연결되는 첫 부분
    cout << "accept" << endl;
    sck_list.push_back(new_client);
   
    // 로그인이나 회원가입으로 시작됨
    string reading = string(buf);
    string msg = string(buf + 3);
    //std::thread th(recv_from_client,server_sock.sck, reading,msg);
    //질문 recv_from_client 함수에 사용되는 인자들은 어떻게 넣어주지?????? 위에처럼 사용할 변수들을 넣어줄 수 있다.?
    std::thread th(recv_from_client, client_num++);
    th.join();

}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) { // 접속해 있는 모든 client에게 메시지 전송
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}


//void recv_msg(int idx) {
//    char buf[MAX_SIZE] = { };
//    string msg = "";
//
//    //cout << sck_list[idx].user << endl;
//
//    while (1) { //  recv한 다음에 여기에 switch 넣기 
//        // add client () 수정하지 마.
//
//
//        ZeroMemory(&buf, MAX_SIZE);
//        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // 오류가 발생하지 않으면 recv는 수신된 바이트 수를 반환. 0보다 크다는 것은 메시지가 왔다는 것.
//            cout << " buf 3 " << buf << endl;
//            msg = sck_list[idx].user + " : " + buf;
//            cout << msg << endl;
//            send_msg(msg.c_str());
//        }
//        else { //그렇지 않을 경우 퇴장에 대한 신호로 생각하여 퇴장 메시지 전송
//            msg = "[공지] " + sck_list[idx].user + " 님이 퇴장했습니다.";
//            cout << msg << endl;
//            send_msg(msg.c_str());
//            del_client(idx); // 클라이언트 삭제
//            return;
//        }
//    }
//}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    //sck_list.erase(sck_list.begin() + idx); // 배열에서 클라이언트를 삭제하게 될 경우 index가 달라지면서 런타임 오류 발생....ㅎ
    client_count--;
}

void recv_from_client(int idx) {// 메세지가 들어오면 타입 구분 하는 기초 함수
    char buf[MAX_SIZE] = { };
    string msg = "";
    string identifier = "";
    string recv_content = "";
    //cout << sck_list[idx].user << endl;
    int e_num = 0;
    int this_idx = idx;
    string result = "";

    while (1) { //  recv한 다음에 여기에 switch 넣기 
        // add client () 수정하지 마.
        SOCKET Client_sck = sck_list[idx].sck;

        ZeroMemory(&buf, MAX_SIZE);
        if (recv(Client_sck, buf, MAX_SIZE, 0) > 0) {
            msg = buf;
            cout << "buf 확인 4: " << buf << endl;
            std::stringstream ss(msg);  // 문자열을 스트림화
            ss >> _Index;
            recv_content = string(buf + 3);



        }
        else {
            //종료
            cout << "종료" << endl;
            return;
        }
        //예외처리 필요
        if (isNumeric(_Index))
        {
            int _Index_Int = stoi(_Index);
            cout << "인덱스"<<_Index_Int;

            switch (_Index_Int)
            {
            case e_signup_IDchk:
                cout << " case 문에 들어왔다" << endl;
                result = mysql.signup_IDchk(recv_content);send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_signup_NickNamechk:
                cout << " e_signup_NickNamechk case 문에 들어왔다" << endl;
                result = mysql.signup_Nicknamechk(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_signup_Submit:
                result = mysql.signup_Submit(recv_content); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_id_try_Signin:
                result = mysql.try_Signin(recv_content,idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            
            case e_id_find_ID:
                cout << " case문 들어옴 ";
                result = mysql.find_ID(recv_content); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_id_find_PW:
                result = mysql.find_PW(recv_content); send(Client_sck, result.c_str(), result.size(), 0); break;

            case e_edit_PWchk:
                cout << "e_edit_PWchk = 31 " << endl << "idx : " << idx << endl;
                result = mysql.edit_PWchk(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); cout << "send완료" << endl; break;
            case e_edit_NickNamechk:
                cout << "  e_edit_NickNamechk :" << endl;
                result = mysql.edit_Nicknamechk(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); cout << "send 됐어요" << endl; break;
            case e_edit_Confirm:
                cout << "    case e_edit_Confirm : " << endl;
                result = mysql.edit_Confirm(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); cout << "send 됐어요" << endl; break;

            case e_message_unread_List:
                cout << "  " << endl;
                result = mysql.message_unread_List(idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_message_Read:
                result = mysql.message_Read(recv_content,idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_message_Send:
                result = mysql.message_Send(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_message_unread_Delete:
                cout << "  " << endl;
                result = mysql.message_Delete(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_friends_List:
                cout << " case e_friends_List: " << endl;
                result = mysql.friends_List(idx); send(Client_sck, result.c_str(), result.size(), 0); cout<<"send 완료";break;
            case e_friends_Delete:
                cout << " case e_friends_Delete: " << endl;
                result =mysql.friends_Delete(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); 
                break;
            case e_friends_Request:
                cout << "  " << endl;
                break;
            case e_friends_Request_List:
                cout << " case e_friends_Request_List: " << endl;
                result = mysql.friends_request_List(idx); send(Client_sck, result.c_str(), result.size(), 0);
                break;
            case e_friends_Request_Accept:
                 break;
            case e_friends_Request_Decline:
                break;
            
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


            //closesocket(server_sock.sck);
        }
        else {
            cout << "else" << endl;
        }
    }
}

    int main() {
        WSADATA wsa;

        // Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
        // 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
        // 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
        int code = WSAStartup(MAKEWORD(2, 2), &wsa);

        if (!code) {
            mysql.set_database();
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
                msg = server_sock.user_ + " : " + buf;
                send_msg(msg.c_str());
            }

            for (int i = 0; i < MAX_CLIENT; i++) {
                th1[i].join();
                //join : 해당하는 thread 들이 실행을 종료하면 리턴하는 함수.
                //join 함수가 없으면 main 함수가 먼저 종료되어서 thread가 소멸하게 됨.
                //thread 작업이 끝날 때까지 main 함수가 끝나지 않도록 해줌.
            }
           /* th1.join();*/

            closesocket(server_sock.sck);
        }
    

        else {
            cout << "프로그램 종료. (Error code : " << code << ")";
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

    string getCurrentTime() {
        std::time_t now = std::time(nullptr);
        struct tm timeInfo;
        localtime_s(&timeInfo, &now);

        char buffer[80];
        std::strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", &timeInfo);
        return buffer;
    }