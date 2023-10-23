#pragma comment(lib, "ws2_32.lib") //명시적인 라이브러리의 링크. 윈속 라이브러리 참조

#include "MySQL.h"
#include "main.h"
#include <mysql/jdbc.h>
#include <string>
#include <sstream>
#include <vector>
#include "UsageServer.h"
//#include "UserInfo.h"
#include "Room.h"

using std::cout;
using std::endl;
using std::string;

extern const char nullChar;

std::vector<ROOM_INFO> workingRoom_list(100);
extern std::vector<SOCKET_INFO> sck_list;
extern std::string _id_from, _nick_from, _msg;
extern std::string _id_temp, _msg_temp,  result;

// #define MAX_SIZE 1024//소켓 박스크기

string s_(int e_num) {
    return std::to_string(e_num);
}




void MySQL::room_activate(int roomIndex, int index) {
    string my_ID = sck_list[index]._user.getID();
    if (isWorkingRoomIndexExist(roomIndex) == false) {
        workingRoom_list[roomIndex].Room_Index = roomIndex;
    }
    workingRoom_list[roomIndex].join_client[index] = (my_ID);
}

void MySQL::room_deactivate(int index) {
    string my_ID = sck_list[index]._user.getID(); //내가 속한 방을 확인하기 위해
    string my_room = sck_list[index]._user.getJoinRoomIndex();
    int i_my_room = stoi(my_room);
    if (i_my_room != 1) {
        if (workingRoom_list[i_my_room].join_client.size() == 0)
            workingRoom_list.erase(workingRoom_list.begin() + i_my_room);
    }
}


bool MySQL::isWorkingRoomIndexExist(int roomIndex) {
    for (auto roomInfo : workingRoom_list) {
        if (roomInfo.Room_Index == roomIndex) {
            return true;
        }
    }
    return false;
}




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
        //stmt->execute("set names 'utf8'");
        // if (stmt) { delete stmt; stmt = nullptr; }
    }
    catch (sql::SQLException& e) {
        // 예외 처리
        std::cerr << "Error setting database schema: " << e.what() << std::endl;
        // 예외 처리 후 필요한 작업을 수행
    }
}






string MySQL::getCurrentTime() {
    std::time_t now = std::time(nullptr);
    struct tm timeInfo;
    localtime_s(&timeInfo, &now);

    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", &timeInfo);
    return buffer;
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
                result = "";
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
            result = "";
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

            result = "";

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
            string _to_nickname="";
            _msg = "";
            ss >> _to_nickname >> std::ws;;
            getline(ss,_msg,'\0');

            string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);


            if (res->next()) {
                string b_id = res->getString("Member_ID");

                string query = "SELECT My_ID FROM friend_list WHERE My_Friend_ID = '" + b_id + "'";
                stmt = con->createStatement();
                res = stmt->executeQuery(query);
                if (res->next())
                {
                    // 입력한 회원 닉네임이 잘못된 경우
                    _ret = elseStr;
                    break;
                }
                // Friend_Request 테이블 업데이트
                // PreparedStatement를 사용하여 쿼리 준비
                sql::PreparedStatement* insertFriendRequestStmt;
                insertFriendRequestStmt = con->prepareStatement("INSERT INTO friend_request (From_Friend_Request_ID, To_Friend_Request_ID, Request_Msg) "
                    "SELECT ?, ?, ? WHERE NOT EXISTS (SELECT 1 FROM friend_request WHERE (From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?) OR (From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?))");
                insertFriendRequestStmt->setString(1, _id);
                insertFriendRequestStmt->setString(2, b_id);
                insertFriendRequestStmt->setString(3, _msg);
                insertFriendRequestStmt->setString(4, _id);
                insertFriendRequestStmt->setString(5, b_id);
                insertFriendRequestStmt->setString(6, b_id);
                insertFriendRequestStmt->setString(7, _id);


                int updateCount = insertFriendRequestStmt->executeUpdate();

                if (updateCount > 0) {
                    _ret = trueStr;
                    break;
                }
                else {
                    _ret = elseStr;
                    break;
                }

            }
            else
            {
                _ret = falseStr;
                break;

            }


        }

        case e_friends_Response_List:
        {
            string _id = sck_list[idx]._user.getID();

            string query = "SELECT From_Friend_Request_ID, Request_Msg FROM friend_request WHERE To_Friend_Request_ID =  '" + _id + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            std::stringstream ss_id_from, ss_msg_from;
            
            while (res->next()) {
                ss_id_from << res->getString("From_Friend_Request_ID") + delim; // 결과 값을 스트림에 추가
                ss_msg_from << res->getString("Request_Msg") + "\n";
            }

            _id_from = "";
            _nick_from = "";
            _msg = "";
            _id_temp = "";
            _msg_temp = "";
            result = "";

            while (ss_id_from >> _id_temp)
            {
                string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
                stmt = con->createStatement();
                res = stmt->executeQuery(query);
                if (res->next()) {
                    _nick_from = "*/" + res->getString("Nickname");
                    getline(ss_msg_from, _msg_temp);
                    result += _nick_from + delim+ _msg_temp + delim;
                }
;           }

            if (!result.empty())
            {
                 _ret = trueStr + delim +  result;
                 break;

            }
            else
            {
                 _ret = falseStr;
                 break;
            }
        }

        case e_friends_Accept:
        {
            string _id = sck_list[idx]._user.getID();
            _nick_from="";
            ss >> _nick_from;

            string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _nick_from + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);
            
            if (res->next()) {

                string b_id = res->getString("Member_ID");
                sql::PreparedStatement* Acc_Stmt;
                Acc_Stmt = con->prepareStatement("SELECT From_Friend_Request_ID, To_Friend_Request_ID FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
                Acc_Stmt->setString(1, b_id);
                Acc_Stmt->setString(2, _id);
         

                 res = Acc_Stmt->executeQuery();

                if (res->next()) {

                    Acc_Stmt = con->prepareStatement("DELETE FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
                    Acc_Stmt->setString(1, b_id);
                    Acc_Stmt->setString(2, _id);

                    int deleteCount = Acc_Stmt->executeUpdate();

                    if (deleteCount > 0) {

                        Acc_Stmt = con->prepareStatement("INSERT INTO friend_list (My_ID, My_Friend_ID) VALUES (?, ?)"); 
                        Acc_Stmt->setString(1, b_id);
                        Acc_Stmt->setString(2, _id);
                        Acc_Stmt->executeUpdate();
                        Acc_Stmt->setString(1, _id);
                        Acc_Stmt->setString(2, b_id);
                        Acc_Stmt->executeUpdate();

                        // 요청이 성공적으로 삭제되었음을 나타내는 처리
                        _ret = trueStr;
                        break;
                    }
                }
            }
            else
            {
                _ret = falseStr;
                break;
            }
        }

        case e_friends_Request_Decline:
        {
            string _id = sck_list[idx]._user.getID();
            _nick_from = "";
            ss >> _nick_from;

            string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _nick_from + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            if (res->next()) {

                string b_id = res->getString("Member_ID");
                sql::PreparedStatement* Acc_Stmt;
                // friend request list에서 그 애를 지워야 해.
                Acc_Stmt = con->prepareStatement("SELECT From_Friend_Request_ID, To_Friend_Request_ID FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
                Acc_Stmt->setString(1, b_id);
                Acc_Stmt->setString(2, _id);


                res = Acc_Stmt->executeQuery();

                if (res->next()) {

                    Acc_Stmt = con->prepareStatement("DELETE FROM friend_request WHERE From_Friend_Request_ID = ? AND To_Friend_Request_ID = ?");
                    Acc_Stmt->setString(1, b_id);
                    Acc_Stmt->setString(2, _id);
                    Acc_Stmt->executeUpdate();

                    _ret = trueStr;
                    break;
                }
            }
            else // database에 있는 아이니까 이럴일은 없겠지만.
            {
                _ret = falseStr;
                break;
            }
        }
        case e_message_Send: // 매새지 보내기
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname;

            ss >> _to_nickname >> std::ws;;
            getline(ss, _msg,'\0');

            string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);



            if (res->next()) {

                string b_id = res->getString("Member_ID");



                cout << getCurrentTime()<<endl;

                prep_stmt = con->prepareStatement("INSERT INTO short_note(From_Short_Note_ID, To_Short_Note_ID, Respond_Short_Note, Short_Note_Datetime, Short_Note_Text) VALUES(?, ? , 0, ?, ? );");

                
                prep_stmt->setString(1, _id);
                prep_stmt->setString(2, b_id);
                prep_stmt->setString(3, getCurrentTime());
                prep_stmt->setString(4, _msg);
                //datetime 서버에서 설정 
                int rows_affected = prep_stmt->executeUpdate();
                if (rows_affected > 0)
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
        }
        //case e_message_Sent: //이건 엔터가 들어간 메세지 관련 쓸꺼야 지우지마
        //{
        //    string _id = sck_list[idx]._user.getID();
        //    string _to_nickname, _msg;


        //    /*string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
        //    stmt = con->createStatement();
        //    res = stmt->executeQuery(query);*/

        //    std::stringstream ss_id_from, ss_msg_from;
        //    prep_stmt = con->prepareStatement("SELECT * FROM short_note WHERE From_Short_Note_ID = ? AND (Respond_Short_Note = 1 OR Respond_Short_Note = 2 OR Respond_Short_Note = 3 OR Respond_Short_Note = 4);");
        //    prep_stmt->setString(1, _id);

        //    res = prep_stmt->executeQuery();
        //    
        //    _msg_temp = "";
        //    // 이거는 엔터가 들어간 메세지를 구분해야하는 다른곳에서도 쓰일수 있어.
        //    while (res->next()) {

        //        ss_id_from << res->getString("To_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
        //        _msg_temp = res->getString("Short_Note_Text") + "\0";
        //        ss_msg_from << _msg_temp.append(&nullChar, 1);

        //        // 결과 처리
        //    }
        //    _id_from = "", _nick_from = "", _msg = "";
        //    _id_temp = "", _msg_temp = "", result = "";

        //    while (ss_id_from >> _id_temp)
        //    {
        //        string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
        //        stmt = con->createStatement();
        //        res = stmt->executeQuery(query);
        //        if (res->next()) {
        //            getline(ss_msg_from, _msg_temp, '\0');
        //            if (ss_msg_from.peek() == '\0') {
        //                // 다음 문자가 '\0'이면 마지막 '\0'이므로 추가하지 않음
        //                continue;
        //            }
        //            _nick_from = "*/" + res->getString("Nickname");
        //            result += _nick_from + delim + _msg_temp + delim;
        //            
        //        }
        //    }

        //    if (!result.empty())
        //    {
        //        _ret = trueStr + delim + result;
        //        break;

        //    }
        //    else
        //    {
        //        _ret = falseStr;
        //        break;
        //    }

        //}
        case e_message_Sent: // 보낸 메세지
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname, _msg;


            /*string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);*/

            std::stringstream ss_id_from, ss_date_from;
            prep_stmt = con->prepareStatement("SELECT * FROM short_note WHERE From_Short_Note_ID = ? AND (Respond_Short_Note = 0 OR Respond_Short_Note = 1 OR Respond_Short_Note = 2 OR Respond_Short_Note = 3);");
            prep_stmt->setString(1, _id);

            res = prep_stmt->executeQuery();

            _msg_temp = "";
            // 이거는 엔터가 들어간 메세지를 구분해야하는 다른곳에서도 쓰일수 있어.
            while (res->next()) {

                ss_id_from << res->getString("To_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
                _msg_temp = res->getString("Short_Note_Datetime") + "\0";
                ss_date_from << _msg_temp.append(&nullChar, 1);

                // 결과 처리
            }
            _id_from = "", _nick_from = "", _msg = "";
            _id_temp = "", _msg_temp = "", result = "";

            while (ss_id_from >> _id_temp)
            {
                string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
                stmt = con->createStatement();
                res = stmt->executeQuery(query);
                if (res->next()) {
                    getline(ss_date_from, _msg_temp, '\0');
                    if (ss_date_from.peek() == '\0') {
                        // 다음 문자가 '\0'이면 마지막 '\0'이므로 추가하지 않음
                        continue;
                    }
                    _nick_from = "*/" + res->getString("Nickname");
                    result += _nick_from + delim + _msg_temp + delim;

                }
            }

            if (!result.empty())
            {
                _ret = trueStr + delim + result;
                break;

            }
            else
            {
                _ret = falseStr;
                break;
            }

        }
        case e_message_Sent_msg: // 보낸메세지 메세지 보기
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname, _msg, _date;
            result = "";

            /*string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);*/
            ss >> _to_nickname;
            getline(ss,_date);
            string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _to_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);
            
            if (res->next()) {
                _id_temp = res->getString("Member_ID");
                string query = "SELECT Short_Note_Text FROM short_note WHERE To_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                stmt = con->createStatement();
                res2 = stmt->executeQuery(query);
                if (res2->next()) {
                    _msg_temp = res2->getString("Short_Note_Text");
                    cout << "_msg_temp = " << _msg_temp << endl;
                    result += _msg_temp;
                }
                
            }

            if (!result.empty())
            {
                _ret = trueStr + delim + result;
                break;

            }
            else
            {
                _ret = falseStr;
                break;
            }
        }
        case e_message_UGiven: // 받은 메세지 보기
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname, _msg;

            
            std::stringstream ss_id, ss_date;
            prep_stmt = con->prepareStatement("SELECT * FROM short_note WHERE To_Short_Note_ID = ? AND (Respond_Short_Note = 0 OR Respond_Short_Note = 4);");
            prep_stmt->setString(1, _id);
            res = prep_stmt->executeQuery();

            while (res->next()) {

                ss_id << res->getString("From_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
                ss_date << res->getString("Short_Note_Datetime") + "\n";

                // 결과 처리
            }
            _id_from = "", _nick_from = "", _msg = "";
            _id_temp = "", _msg_temp = "", result = "";

            while (ss_id >> _id_temp)
            {
                string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
                stmt = con->createStatement();
                res = stmt->executeQuery(query);
                if (res->next()) {
                    getline(ss_date, _msg_temp, '\n');
                    _nick_from = "*/" + res->getString("Nickname");
                    result += _nick_from + delim + _msg_temp + "\n";

                }
            }

            if (!result.empty())
            {
                _ret = trueStr + delim + result;
                break;

            }
            else
            {
                _ret = falseStr;
                break;
            }

        }

        case e_message_RGiven: // 받은 메세지 보기
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname, _msg;


            std::stringstream ss_id, ss_date;
            prep_stmt = con->prepareStatement("SELECT * FROM short_note WHERE To_Short_Note_ID = ? AND (Respond_Short_Note = 1 OR Respond_Short_Note = 5);");
            prep_stmt->setString(1, _id);
            res = prep_stmt->executeQuery();

            while (res->next()) {

                ss_id << res->getString("From_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
                ss_date << res->getString("Short_Note_Datetime") + "\n";

                // 결과 처리
            }
            _id_from = "", _nick_from = "", _msg = "";
            _id_temp = "", _msg_temp = "", result = "";

            while (ss_id >> _id_temp)
            {
                string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
                stmt = con->createStatement();
                res = stmt->executeQuery(query);
                if (res->next()) {
                    getline(ss_date, _msg_temp, '\n');
                    _nick_from = "*/" + res->getString("Nickname");
                    result += _nick_from + delim + _msg_temp + "\n";

                }
            }

            if (!result.empty())
            {
                _ret = trueStr + delim + result;
                break;

            }
            else
            {
                _ret = falseStr;
                break;
            }

        }
        case e_message_UGiven_msg : // 읽지않은 받은 메세지 보기 *
        {
            string _id = sck_list[idx]._user.getID();
            string _from_nickname, _msg, _date;
            result = "";

            ss >> _from_nickname;
            getline(ss, _date);
            string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            if (res->next()) {
                _id_temp = res->getString("Member_ID");
                string query = "SELECT Short_Note_Text FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                stmt = con->createStatement();
                res2 = stmt->executeQuery(query);
                if (res2->next()) {
                    _msg_temp = res2->getString("Short_Note_Text");
                    cout << "_msg_temp = " << _msg_temp << endl;
                    result += _msg_temp;
                }

            }

            if (!result.empty())
            {
                _ret = trueStr + delim + result;
                break;

            }
            else
            {
                _ret = falseStr;
                break;
            }
        }
        case e_message_RGiven_msg: // 읽지않은 받은 메세지 보기 *
        {
            string _id = sck_list[idx]._user.getID();
            string _from_nickname, _msg, _date;
            result = "";

            ss >> _from_nickname;
            getline(ss, _date);
            string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            if (res->next()) {
                _id_temp = res->getString("Member_ID");
                string query = "SELECT Short_Note_Text FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                stmt = con->createStatement();
                res2 = stmt->executeQuery(query);
                if (res2->next()) {
                    _msg_temp = res2->getString("Short_Note_Text");
                    cout << "_msg_temp = " << _msg_temp << endl;
                    result += _msg_temp;
                }

            }

            if (!result.empty())
            {
                _ret = trueStr + delim + result;
                break;

            }
            else
            {
                _ret = falseStr;
                break;
            }
        }


        //room type (서버 1 공개 2 비공개 3)  - room_PW(없으면 0(공개방))- room_Name 순으로 보내주세요! room_name 에 띄어쓰기 포함 가능해서 뒤로 빼주세요
        // 방을 만들경우 바로 해당 방으로 입장됨( 해당 방 index가 내가 속한 방 index가 됨
        //반환값 e_num + IDENTIFIER + True/False + IDETIFIER + 내가 속한 방 index
        //클라이언트 :같은 방 타입에서 방 이름 중복되면 못들어오게 처리 추가해야됨

        //room list
        case e_room_Create:
        {
            // roomtype + pw(not null) + name
            // roomtype은 1이들어갈수없다.
            // name = "abc cdf"
            // std::stringstream ss(recv_content); //  없어도돼
            string A = "2 0 나랏말싸미";
            std::stringstream ss(A);
            string s;
            string result = "";
            string room_Type = "";
            int i_room_Type;
            string room_PW = "";
            string room_Name = "";
            int room_Index;
            string my_ID = sck_list[idx]._user.getID();
            string room_date = getCurrentTime();
            std::vector<string> dis_content;
            string line;
            int count = 0;
            dis_content.clear();
            while (ss >> s) {
                dis_content.push_back(s);
            }
            room_Type = dis_content[0];
            dis_content.erase(dis_content.begin());
            room_PW = dis_content[0];// PW가 없어도 0 보내주기
            dis_content.erase(dis_content.begin());
            for (auto text : dis_content)
                room_Name = room_Name + text + IDENTIFIER;
            cout << room_Type << IDENTIFIER << room_Name << IDENTIFIER << room_PW << endl;
            i_room_Type = std::stoi(room_Type);
            cout << "i_room_Type : " << i_room_Type << endl;
            if ((i_room_Type == 2) || (i_room_Type == 3))
            {
                if (i_room_Type == 2)
                    prep_stmt = con->prepareStatement("INSERT INTO room_list (Room_Type, Room_Title, Room_Master, Room_Date) VALUES (?,?,?,?);");
                if (i_room_Type == 3)
                {
                    prep_stmt = con->prepareStatement("INSERT INTO room_list (Room_Type, Room_Title, Room_Master, Room_Date, Room_PW) VALUES (?,?,?,?,?);");
                    prep_stmt->setString(5, room_PW);
                }
                prep_stmt->setInt(1, i_room_Type);
                prep_stmt->setString(2, room_Name);
                prep_stmt->setString(3, my_ID); // << 내가 룸마스터다 
                prep_stmt->setString(4, room_date);
                int t_or_f = prep_stmt->executeUpdate();
                cout << "t_or_f :" << t_or_f << endl;
                if (t_or_f > 0)
                {
                    prep_stmt = con->prepareStatement("SELECT* from room_list WHERE Room_Type =? AND Room_Title = ?;");
                    prep_stmt->setInt(1, i_room_Type);
                    prep_stmt->setString(2, room_Name);

                    cout << "prep_stmt = con->prepareStatement);" << endl;
                    sql::ResultSet* res = prep_stmt->executeQuery();
                    cout << "prep_stmt = con->prepareStatement);" << endl;
                    if ((res->next()))
                    {
                        room_Index = res->getInt(1);
                        sck_list[idx].room.setRoom_Index(res->getInt(1));
                        sck_list[idx].room.setRoom_Index(room_Index);
                        sck_list[idx].room.setRoom_Type(res->getInt(2));
                        sck_list[idx].room.setRoom_Title(res->getString(3));
                        sck_list[idx].room.setRoom_Master(res->getString(4));
                        sck_list[idx].room.setRoom_Date(res->getString(5));
                        if (i_room_Type == 3)
                        {
                            sck_list[idx].room.setRoom_PW(res->getString(6));
                        }
                        sck_list[idx]._user.setJoinRoomIndex(s_(sck_list[idx].room.getRoom_Index()));
                        cout << " 내가 들어간 방 : " << sck_list[idx]._user.getJoinRoomIndex() << endl;
                        cout << "방 정보 저장 완료" << endl;
                        prep_stmt = con->prepareStatement("UPDATE member set Join_Room_Index = ? WHERE member_ID = ? ");
                        prep_stmt->setInt(1, std::stoi(sck_list[idx]._user.getJoinRoomIndex()));
                        prep_stmt->setString(2, my_ID);
                        int rowUpdate = prep_stmt->executeUpdate();
                        cout << "update member query 완료;" << endl;
                        room_activate(room_Index, idx); // 방 활성화 해주기
                        result = s_(e_room_Create) + IDENTIFIER + trueStr + IDENTIFIER + sck_list[idx]._user.getJoinRoomIndex(); // **** 내가 몇번방에들어갔는지 알 수 있다.
                        cout << "result : " << result << endl;
                        return result;

                        //성공시 들어가는 방의 index (room_list의 primary key) 보내줌
                    }
                    else {
                        cout << "등록은 성공 but 정보 저장 실패" << endl;
                        result = s_(e_room_Create) + IDENTIFIER + falseStr;
                        return result;
                    }
                }
                else
                {
                    cout << "등록은 성공 but 정보 저장 실패" << endl;
                    result = s_(e_room_Create) + IDENTIFIER + falseStr;
                    return result;
                }
            }
            else
            {
                cout << "INSERT INTO 실패" << endl;
                result = s_(e_room_Create) + IDENTIFIER + falseStr;
                return result;
            }
        }

        //// enum값만 주면된다.
        //case e_room_Exit:
        //{
        //    string my_ID = sck_list[idx].user.getID();
        //    string result;
        //    string str_room_Index;
        //    int i_room_Index;
        //    prep_stmt = con->prepareStatement("UPDATE member set Join_Room_Index = NULL WHERE member_ID = ? ;");
        //    prep_stmt->setString(1, my_ID);
        //    int rowUpdate = prep_stmt->executeUpdate();
        //    cout << "int rows_affected = prep_stmt->executeUpdate(); " << rowUpdate << endl;
        //    if (rowUpdate > 0) {
        //        sck_list[idx].room.room_init();//방정보 초기화
        //        result = s_(e_room_Exit) + IDENTIFIER + True;
        //        cout << "result = s_(e_room_Exit) + IDENTIFIER + True; :" << result << endl;
        //        str_room_Index = sck_list[idx]._user.getJoinRoomIndex();
        //        i_room_Index = stoi(str_room_Index);
        //        workingRoom_list[i_room_Index].join_client.erase(workingRoom_list[i_room_Index].join_client.begin() + idx);//내 이름 활성화된 방에서 삭제
        //        room_deactivate(idx);
        //        sck_list[idx].user.setJoinRoomIndex("");
        //    }
        //    else
        //        result = s_(e_room_Exit) + IDENTIFIER + False;
        //    return result;
        //}

        //// 방의 인덱스 + 타입 + 패스워드(없으면안보내도 됨)
        //case e_room_Enter:
        //{
        //    string my_ID = sck_list[idx]._user.getID();
        //    string result;
        //    string room_Type;
        //    string room_Title;
        //    string room_PW;
        //    string room_Index;
        //    std::stringstream ss(recv_content);
        //    ss >> room_Index >> room_Type >> room_PW;
        //    cout << room_Index << IDENTIFIER << room_Type << IDENTIFIER << room_PW << endl;
        //    int i_room_Type = std::stoi(room_Type);
        //    int i_room_Index = std::stoi(room_Index);

        //    if (i_room_Type == 3)
        //    {
        //        prep_stmt = con->prepareStatement("SELECT* from room_list WHERE Room_Index =? AND Room_PW =?;");
        //        cout << "SELECT* from room_list WHERE Room_Index =? " << endl;
        //        prep_stmt->setInt(1, i_room_Index);
        //        prep_stmt->setString(2, room_PW);
        //        sql::ResultSet* res = prep_stmt->executeQuery();

        //        if (res->next())
        //            cout << "성공";
        //        else
        //        {
        //            result = s_(e_room_Enter) + IDENTIFIER + False;
        //            cout << "index 와 pw가 맞지 않습니다" << endl;
        //            return result;
        //        }
        //    }
        //    cout << "first if -else exit" << endl;
        //    prep_stmt = con->prepareStatement("UPDATE member set Join_Room_Index = ? WHERE Member_ID=?;");
        //    prep_stmt->setInt(1, std::stoi(room_Index));
        //    prep_stmt->setString(2, my_ID);
        //    int rowUpdate = prep_stmt->executeUpdate();
        //    if (rowUpdate > 0)
        //        cout << "rowUpdate >0 " << endl;
        //    else
        //    {
        //        result = s_(e_room_Enter) + IDENTIFIER + False;
        //        return result;
        //    }

        //    if (rowUpdate > 0)
        //    {
        //        prep_stmt = con->prepareStatement("SELECT* from room_list WHERE Room_Index =?;");
        //        cout << "SELECT* from room_list WHERE Room_Index =? " << endl;
        //        prep_stmt->setInt(1, i_room_Index);
        //        sql::ResultSet* res = prep_stmt->executeQuery();

        //        if (res->next())
        //        {
        //            cout << "  if (prep_stmt->execute()) : " << endl;
        //            sck_list[idx].room.setRoom_Index(res->getInt(1));
        //            sck_list[idx].room.setRoom_Type(res->getInt(2));
        //            sck_list[idx].room.setRoom_Title(res->getString(3));
        //            if (i_room_Type != 1)// 서버방은 방장이 없으니 예외 처리
        //                sck_list[idx].room.setRoom_Master(res->getString(4));
        //            sck_list[idx].room.setRoom_Date(res->getString(5));
        //            if (i_room_Type == 3)// 비밀방만 비밀번호 받으므로 예외 처리
        //                sck_list[idx].room.setRoom_PW(res->getString(6));
        //            sck_list[idx]._user.setJoinRoomIndex(room_Index);
        //            room_activate(stoi(room_Index), idx);
        //            result = s_(e_room_Enter) + IDENTIFIER + True + IDENTIFIER + sck_list[idx]._user.getJoinRoomIndex();
        //            cout << "result : " << result << endl;
        //            return result;
        //        }

        //        else
        //        {
        //            cout << "등록은 성공 but 클래스 객체에 정보 저장 실패" << endl;
        //            result = s_(e_room_Enter) + IDENTIFIER + False;
        //            return result;
        //        }
        //    }
        //    else
        //    {
        //        result = s_(e_room_Enter) + IDENTIFIER + False;
        //        return result;
        //    }
        //}
        ////채팅방에 들어오는 사람들한테 이전 내용 전부 보여주기
        //void room_show_whole_Text(int index) {
        //    string row = "------------------------------------------------------------------------------\n";
        //    string all_Text = "";
        //    string result;
        //    string nickname, chat, chat_Data = "";
        //    int room_index = stoi(sck_list[index].user.getJoinRoomIndex());
        //    prep_stmt = con->prepareStatement("SELECT Nickname, Chat, Chat_Date FROM room_chat WHERE Room_Index=?");
        //    prep_stmt->setInt(1, room_index);
        //    sql::ResultSet* res = prep_stmt->executeQuery();
        //    while (res->next())
        //    {
        //        nickname = res->getString(1);
        //        chat = res->getString(2);
        //        chat_Data = res->getString(3);
        //        row = nickname + " : " + chat + "  " + chat_Data;
        //        result = s_(e_room_show_whole_Text) + IDENTIFIER + True + IDENTIFIER + row;
        //        send(Client_sck, result.c_str(), result.size(), 0);
        //        return;
        //    }
        //    
        //    
        //}

    




        default:
            break;
    }
    return _ret;
}
