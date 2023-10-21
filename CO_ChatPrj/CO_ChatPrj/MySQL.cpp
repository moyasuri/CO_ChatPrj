#pragma comment(lib, "ws2_32.lib") //명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include "MySQL.h"
#include "main.h"
#include <mysql/jdbc.h>
#include <string>
#include <sstream>
#include <vector>
#include "UsageServer.h"

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
    res2 = nullptr;
}

MySQL::~MySQL() {
    // 소멸자에서 메모리 정리
    delete pstmt;
    delete prep_stmt;
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

    try {
        // 데이터베이스 선택
        con->setSchema(str);
        // db 한글 저장을 위한 셋팅 
        stmt = con->createStatement();
        stmt->execute("set names euckr");
        // if (stmt) { delete stmt; stmt = nullptr; }
    }
    catch (sql::SQLException& e) {
        // 예외 처리
        std::cerr << "Error setting database schema: " << e.what() << std::endl;
        // 예외 처리 후 필요한 작업을 수행
    }
}

string MySQL::QuerySql(string msg, int idx) {

    // indxe retrun값 선언
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
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = ? AND Member_PW = ?");
            prep_stmt->setString(1, _id);
            prep_stmt->setString(2, _pw);
            sql::ResultSet* res = prep_stmt->executeQuery();
            
            

            if(res->next())
            {
                
                sck_list[idx]._user.setID(_id);
                
                std::string query = "SELECT Nickname FROM member WHERE Member_ID = '" + _id + "'";
                std::string result = "";
                res = stmt->executeQuery(query);


                while (res->next()) {
                    sck_list[idx]._user.setNickName(res->getString("Nickname"));
                }

                cout << sck_list[idx]._user.getNickName();
                cout << sck_list[idx]._user.getID();
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
            string _name, _email;
            ss >> _name >> _email;
            
            res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Email = '" + _email + "' AND Name = '" + _name + "'");
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
            string query = "SELECT m.Nickname FROM friend_list f INNER JOIN member m ON f.My_Friend_ID\
 = m.Member_ID WHERE f.My_ID = '" + _id + "'";
            res = stmt->executeQuery(query);

            string result = "";

            while (res->next()) {
                result += res->getString("Nickname") + delim;
            }
            
 
            if (!result.empty()) {
                _ret = trueStr + delim + result;
                break;
            }
            else {
                // 친구 아이디를 찾지 못했을 때
                _ret = falseStr;
                break;
            }
        }
        case e_friends_Request:
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname,msg;
            ss >> _to_nickname >>msg;

    
            string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            if (res->next()) {
                string b_id = res->getString("Member_ID");

                // Friend_Request 테이블 업데이트
                // PreparedStatement를 사용하여 쿼리 준비
                sql::PreparedStatement* insertFriendRequestStmt;
                insertFriendRequestStmt = con->prepareStatement("INSERT INTO friend_request (From_Friend_Request_ID, To_Friend_Request_ID, Response, Request_Msg) "
                    "SELECT ?, ?, 1, ? WHERE NOT EXISTS (SELECT 1 FROM friend_request WHERE (From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?) OR (From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?))");
                insertFriendRequestStmt->setString(1, _id);
                insertFriendRequestStmt->setString(2, b_id);
                insertFriendRequestStmt->setString(3, msg);
                insertFriendRequestStmt->setString(4, _id);
                insertFriendRequestStmt->setString(5, b_id);
                insertFriendRequestStmt->setString(6, b_id);
                insertFriendRequestStmt->setString(7, _id);


                int updateCount = insertFriendRequestStmt->executeUpdate();

                if (updateCount > 0) {
                    _ret = trueStr;
                }
                else {
                    _ret = falseStr + delim + "친구수락을 받아주세요.";
                }

            }
            else
            {
                _ret = falseStr;
                break;

            }


        }
        default:
            break;
    }
    return _ret;
}
