#pragma once
#include <mysql/jdbc.h>
#include <string>
#include <sstream>
#include <vector>
#include "UsageServer.h"





using std::cout;
using std::endl;
using std::string;
const string IDENTIFIER = " ";
const string trueStr = "true";
const string falseStr = "false";
const string delim = " ";

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호



// #define MAX_SIZE 1024//소켓 박스크기





class MySQL {
public:

    MySQL()
    {        
       
    }
    ~MySQL()
    {
        delete pstmt;
        delete con;
    }
    
    
    void Init_Mysql()
    {
        try {
            driver = sql::mysql::get_mysql_driver_instance();
            con = driver->connect(server, username, password);
        }
        catch (sql::SQLException& e) {
            cout << "Could not connect to server. Error message: " << e.what() << endl;
            exit(1);
        }
    }


    void set_database(string str) {

        // 데이터베이스 선택
        con->setSchema(str);
        // db 한글 저장을 위한 셋팅 
        stmt = con->createStatement();
        stmt->execute("set names 'utf8'");
        if (stmt) { delete stmt; stmt = nullptr; }
    }

    //친구목록 데이터 가져오기
    //void send_friend_list(const char* friendList) {
    //    stmt->execute("select Friend_List_Index, My_Friend_ID from chat.friend_list"); // DROP

    //}


    string QuerySql(string msg) {
        string _Index, _ret;
        
        std::stringstream ss(msg);
        
        ss >> _Index;
        
        int _Index_Int = stoi(_Index);

        switch (_Index_Int)
        {
            case e_id_try_Signin:
            {
                string _id, _pw;
                ss >> _id >> _pw;
                prep_stmt = con->prepareStatement("SELECT Member_ID FROM practice WHERE Member_ID = ? AND Member_PW = ?");
                prep_stmt->setString(1, _id);
                prep_stmt->setString(2, _pw);
                cout << "prep_stmt->execute() : " << prep_stmt->execute() << endl;

                if (prep_stmt->execute())
                {
                    _ret = trueStr;
                    break;
                }
                else
                {
                    _ret = falseStr;
                    break;
                }
            }
            case e_id_find_ID:
            {
                string _name, _email, _id; 
                ss >> _name >> _email;
                res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Email = '" + _id + "' AND Name = '" \
                    + _name + "'");
                if (res->next()) {
                    _ret = trueStr + delim + res->getString("Member_ID");
                    break;
                }
                else
                {
                    _ret = falseStr;
                    break;
                }
            }
            case e_id_find_PW:
            {
                string _id, _birth, _phone;

                ss >> _id >> _birth >> _phone;
                string respw = "";
                string result = "";
                res = stmt->executeQuery("SELECT Member_PW FROM member WHERE Member_ID = '" + _id + \
                    "' AND Birth = '" + _birth + "' AND Phone = '" + _phone + "'");
                if (res->next()) {
                    _ret = trueStr + delim + res->getString("Member_PW");
                    break;
                }
                else
                {
                    _ret = falseStr;
                    break;
                }
            }
            case 
        }
                
        return _ret;
    }

    ////보내진 email과 이름이 일치하는 멤버를 확인하고 거기에 올바른 id를 넘겨준다
    //void send_find_ID(string recv_content) {
    //    std::stringstream ss(recv_content);
    //    string mysql_check_name;
    //    string mysql_check_email;
    //    ss >> mysql_check_name >> mysql_check_email;

    //    string resid = "";
    //    string result;
    //    res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Email = '" + mysql_check_email + "' AND Name = '" + mysql_check_name + "'");
    //    if (res->next()) {
    //        resid = res->getString("Member_ID");
    //    }
    //    if (resid.size() != 0)
    //        result = ID찾기 + IDENTIFIER + True + resid; //true false 는 const string True = "True" 등으로 위에 있습니다
    //    else
    //        result = ID찾기 + IDENTIFIER + False;
    //}

    //void send_find_PW(string recv_content) {
    //    std::stringstream ss(recv_content);
    //    string mysql_check_id;
    //    string mysql_check_birth;
    //    string mysql_check_phone;
    //    ss >> mysql_check_id >> mysql_check_birth >> mysql_check_phone;

    //    string respw = "";
    //    string result = "";
    //    res = stmt->executeQuery("SELECT Member_PW FROM member WHERE Member_ID = '" + mysql_check_id + "' AND Birth = '" + mysql_check_birth + "' AND Phone = '" + mysql_check_phone + "'");
    //    if (res->next()) {
    //        respw = res->getString("Member_PW");
    //    }
    //    if (respw.size() != 0)
    //        result = PW찾기 + IDENTIFIER + True + respw;
    //    else
    //        result = PW찾기 + IDENTIFIER + False;
    //    //client에서 반환되는 값이 true이면 비밀번호 재설정 창으로 넘어가야겠다.
    //    send(Client_sck, result.c_str(), MAX_SIZE, 0);
    //}

 

    //void send_signup_IDchk(string recv_content) {
    //    std::stringstream ss(recv_content);
    //    string mysql_check_id;
    //    ss >> mysql_check_id;
    //    prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?'");
    //    prep_stmt->setString(1, mysql_check_id);
    //    string result;
    //    if ((prep_stmt->execute()) == 1)
    //        result = s_(e_signup_IDchk) + IDENTIFIER + False; //이미 존재하는 값이니 id 다른 거로 설정해
    //    else
    //        result = s_(e_signup_IDchk) + IDENTIFIER + True;

    //    send(Client_sck, result.c_str(), MAX_SIZE, 0);
    //}

    //void send_signup_Nicknamechk(string recv_content) {
    //    std::stringstream ss(recv_content);
    //    string mysql_check_nickname;
    //    ss >> mysql_check_nickname;
    //    prep_stmt = con->prepareStatement("SELECT Nickname FROM member WHERE Nickname = '?'");
    //    prep_stmt->setString(1, mysql_check_nickname);
    //    string result;
    //    if ((prep_stmt->execute()) == 1)
    //        result = s_(e_signup_NickNamechk) + IDENTIFIER + False; //이미 존재하는 값이니 id 다른 거로 설정해
    //    else
    //        result = s_(e_signup_NickNamechk) + IDENTIFIER + True;

    //    send(Client_sck, result.c_str(), MAX_SIZE, 0);
    //}

    ////send함수만 따로 만들어놓는게 좋겠다. return string으로 result를 반환하고 
    //// pw 중복 체크,생일 체크 등은 이상값을 클라이언트에서 처리하고 mysql쿼리보내기만 전체적으로 실행한다.
    //void send_signup_Submit(string recv_content) {
    //    std::stringstream ss(recv_content);
    //    string Member_ID;
    //    string Email;
    //    string Phone;
    //    string Birth;
    //    string Nickname;
    //    int Cha_Num;
    //    string Member_PW;
    //    string Name;

    //    ss >> Member_ID >> Email >> Phone >> Birth >> Nickname >> Cha_Num >> Member_PW >> Name;

    //    prep_stmt = con->prepareStatement("INSERT INTO member VALUES ('?','?',NULL,'?','?','?','?','?',NULL,'?');");
    //    prep_stmt->setString(1, Member_ID);
    //    prep_stmt->setString(2, Email);
    //    prep_stmt->setString(3, Phone);
    //    prep_stmt->setString(4, Birth);
    //    prep_stmt->setString(5, Nickname);
    //    prep_stmt->setInt(6, Cha_Num);
    //    prep_stmt->setString(7, Member_PW);
    //    prep_stmt->setString(8, Name);
    //    string result;
    //    if ((prep_stmt->execute()) == 1)
    //        result = s_(e_signup_Submit) + IDENTIFIER + True; //회원가입 등록 완
    //    else
    //        result = s_(e_signup_Submit) + IDENTIFIER + False;//등록 실패

    //    send(Client_sck, result.c_str(), MAX_SIZE, 0);
    //}


    //void send_friend_List(string mysql_check_id) {
    //    res = stmt->executeQuery("SELECT Friend_List_Index, My_ID, My_Friend_ID FROM friend_list  WHERE Member_ID = '" + mysql_check_id + "'");
    //    string result;
    //    if (res->next())
    //        result = 친구목록_서 + " " + res->getString(1);
    //    else
    //        result = 친구목록_서;


    //    send(Client_sck, result.c_str(), MAX_SIZE, 0);
    //}

    //void send_friend_request(string mysql_check_id) {
    //    res = stmt->executeQuery("SELECT From_Friend_Request_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
    //    string result;
    //    if (res->next())
    //        result = 친구요청_서 + " " + res->getString(1);
    //    else
    //        result = 친구요청_서;


    //    send(Client_sck, result.c_str(), MAX_SIZE, 0);
    //}

    //void send_friend_search(SOCKET server_sock, string mysql_check_id) { //비교해서 have 값만 보내줘야한다.
    //    res = stmt->executeQuery("SELECT member_ID, Request_Msg WHERE  Response=3 and To_Friend_Request_Id = '" + mysql_check_id + "'");
    //    string result;
    //    if (res->next())
    //        result = 친구검색_서 + " " + "have";
    //    else
    //        result = 친구검색_서 + " ";

    //    send(server_sock, result.c_str(), MAX_SIZE, 0);
    //}




private:

    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
     
   
};