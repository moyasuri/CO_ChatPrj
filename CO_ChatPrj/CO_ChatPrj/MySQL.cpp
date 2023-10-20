#pragma comment(lib, "ws2_32.lib") //명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include "MySQL.h"
#include "main.h"
#include <mysql/jdbc.h>
#include <string>
#include <sstream>
#include <vector>
#include "UsageServer.h"
#include "UserInfo.h"

using std::cout;
using std::endl;
using std::string;



extern std::vector<SOCKET_INFO> sck_list;

// #define MAX_SIZE 1024//소켓 박스크기


MySQL::MySQL() {
    // 생성자에서 초기화
    driver = sql::mysql::get_mysql_driver_instance();
    con = nullptr;
    stmt = nullptr;
    pstmt = nullptr;
    prep_stmt = nullptr;
    res = nullptr;
}

MySQL::~MySQL() {
    // 소멸자에서 메모리 정리
    delete pstmt;
    delete con;
}


void MySQL::Init_Mysql() {
    try {
        // MySQL에 연결
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect(server, username, password);
    }
    catch (sql::SQLException& e) {
        std::cout << "Could not connect to server. Error message: " << e.what() << std::endl;
        exit(1);
    }
}


void MySQL::set_database(string str) {

    // 데이터베이스 선택
    con->setSchema(str);
    // db 한글 저장을 위한 셋팅 
    stmt = con->createStatement();
    stmt->execute("set names 'utf8'");
    if (stmt) { delete stmt; stmt = nullptr; }
}

string MySQL::QuerySql(string msg, int idx) {
    string _Index, _ret;

    std::stringstream ss(msg);

    ss >> _Index;

    int _Index_Int = stoi(_Index);

    switch (_Index_Int)
    {

        // Sign in
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

        // Sign up
        case e_signup_IDchk:
        {
            string _id;
            ss >> _id;
            sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Member_ID = '" + _id + "'");

            // Database에 이미 있는아이디 = true;
            if (res->next()) {
                _ret = falseStr;
                break;
            }
            else
            {
                _ret = trueStr;
                break;
            }
        }

        case e_signup_NickNamechk:
        {
            string _nickname;
            ss >> _nickname;
            sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Nickname = '" + _nickname + "'");

            // Database에 이미 있는 Nickname =  false;
            if (res->next()) {
                _ret = falseStr;
                break;
            }
            else
            {
                _ret = trueStr;
                break;
            }
        }

        case e_signup_Submit:
        {
            prep_stmt = con->prepareStatement("INSERT INTO member VALUES (?,?,NULL,?,?,?,?,?,NULL,?);");
            string data;
            // ss >> _id >> _email >> _phone >> _birth >> _nickname >> _cha_num >> _pw >> _name;

            int cnt = 1;
            while (ss >> data)
            {
                prep_stmt->setString(cnt, data);
                cnt++;
            }

            if (prep_stmt->executeUpdate())
            {
                _ret = trueStr; //회원가입 등록 완
                break;
            }
            else
            {
                _ret = falseStr;
                break;
            }
        }

        // editinfo
        case e_edit_PWchk:
        {
            string _id = sck_list[idx]._user.getID(), _pw;
            ss >> _pw;
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = ? AND Member_PW = ?");
            prep_stmt->setString(1, _id);
            prep_stmt->setString(2, _pw);
            sql::ResultSet* res = prep_stmt->executeQuery();
            if ((res->next()))
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
        case e_edit_NickNamechk:
        {
            string _id,_nickname;
            _id = sck_list[idx]._user.getID();
            ss >> _nickname;
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Nickname = ?");
            prep_stmt->setString(1, _nickname);
            cout << "prep_stmt = con->prepareStatement : " << _id << " " << _nickname << endl;
            sql::ResultSet* res = prep_stmt->executeQuery();
            if ((res->next()))
            {
                _ret = falseStr;
                break;
            }
            else
            {
                _ret = trueStr;
                break;
            }
        }
        case e_edit_Confirm:
        {
            string _id = sck_list[idx]._user.getID();
            // 순서 Email; Phone; Nickname; Cha_Num; Member_PW;        

            string _email, _phone, _nickname, _cha_num, _pw;


            prep_stmt = con->prepareStatement("update member set Email = ?, Phone =?, Nickname = ?,Cha_Num = ?,Member_PW=? WHERE  Member_ID = ?");
       
            prep_stmt->setString(1, _email);
            prep_stmt->setString(2, _phone);
            prep_stmt->setString(3, _nickname);
            prep_stmt->setString(4, _cha_num);
            prep_stmt->setString(5, _pw);
            prep_stmt->setString(6, _id);

            if (prep_stmt->executeUpdate())
            {

                // 이거 필요함? 음...
                sck_list[idx]._user.setChaNum(_cha_num);
                sck_list[idx]._user.setEmail(_email);
                sck_list[idx]._user.setNickName(_nickname);
                sck_list[idx]._user.setPhone(_phone);
                sck_list[idx]._user.setPW(_pw);
                _ret = trueStr;
                break;
            }
            else
            {
                _ret = falseStr;
                break;
            }
        }
        case e_friends_List:
        {
            string _id = sck_list[idx]._user.getID();
            prep_stmt = con->prepareStatement("SELECT Distinct My_Friend_ID From friend_list WHERE My_ID = ?;");
            prep_stmt->setString(1, _id);
            sql::ResultSet* res = prep_stmt->executeQuery();

            
            string friendIDs = "";
            while (res->next()) {
                string friendID = res->getString("My_Friend_ID");
                friendIDs += friendID + delim;
            }

            if (!friendIDs.empty()) {
                // 적어도 하나의 친구 아이디를 찾았을 때
                _ret = trueStr + delim + friendIDs;
            }
            else {
                // 친구 아이디를 찾지 못했을 때
                _ret = falseStr;
            }
        }
    }

    return _ret;
}
