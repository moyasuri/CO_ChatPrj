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
string _from_nickname;
string _date;
string _id;
extern int client_count;
extern bool multimsg;
// #define MAX_SIZE 1024//소켓 박스크기
#define MAX_SIZE 1024//소켓 박스크기

string s_(int e_num) {
    return std::to_string(e_num);
}




void MySQL::_send_msg(const char* msg, int room_Index66) {
    for (int i = 0; i < client_count; i++) { // 이 방에 접속해 있는 모든 client에게 메시지 전송
        if (stoi(sck_list[i]._user.getJoinRoomIndex()) == room_Index66) {// UserInfo 객체 생성시 초기화 반드시 진행, JoinRoomIndex ="0"으로
            send(sck_list[i].sck, msg, MAX_SIZE, 0);
        }
        else
            break;
        //join_client 멤버들의 소켓으로 보내줘야 됨
    }
}


//void MySQL::room_activate(int roomIndex_, int index__) {
//    string _my_ID62 = sck_list[index__]._user.getID();
//    if (isWorkingRoomIndexExist(roomIndex_) == false) {
//        workingRoom_list[roomIndex_].Room_Index = roomIndex_;
//    }
//    workingRoom_list[roomIndex_].join_client[index__] = (_my_ID62);
//}





string MySQL::room_Delete(string roomidx, int idx) {
    string room_Index_;
    string my_ID = sck_list[idx]._user.getID();
    string result;
    int i_room_Index = stoi(roomidx);
    prep_stmt = con->prepareStatement("DELETE FROM room_list WHERE Room_Master = ? AND Room_Index = ?;");
    prep_stmt->setString(1, my_ID);
    prep_stmt->setInt(2, i_room_Index);
    int rowUpdate = prep_stmt->executeUpdate();

    if (rowUpdate > 0)
        result = trueStr;
    else
        result = falseStr;
    cout << "result : " << result << endl;
    return result;

}



void MySQL::room_activate(int roomIndex, int index__) {
    string _my_ID62 = sck_list[index__]._user.getID();
    if (isWorkingRoomIndexExist(roomIndex) == false) {
        workingRoom_list[roomIndex].Room_Index = roomIndex;
    }
    workingRoom_list[roomIndex].join_client.push_back(_my_ID62);
}



bool MySQL::isWorkingRoomIndexExist(int roomIndex) {
    for (auto roomInfo : workingRoom_list) {
        if (roomInfo.Room_Index == roomIndex) {
            return true;
        }
    }
    return false;
}

string MySQL::room_myList(int index) {
    string rm_result;
    int Room_Index;
    string Room_Title;
    int Room_Type;
    string Room_Date;
    string rl_line = "";
    string my_ID = sck_list[index]._user.getID();
    prep_stmt = con->prepareStatement("SELECT Room_Index, Room_Type, Room_Title, Room_Date FROM room_list WHERE Room_Master = ?;");
    prep_stmt->setString(1, my_ID);
    sql::ResultSet* res = prep_stmt->executeQuery();

    while (res->next())
    {
        Room_Index = res->getInt(1);
        Room_Type = res->getInt(2);
        Room_Title = res->getString(3);
        Room_Date = res->getString(4);
        rl_line = rl_line + "\n" + s_(Room_Index) + delim + s_(Room_Type) + delim + "*/"+ Room_Title +"*/" + delim + Room_Date;
    }
    if (rl_line.size() > 0)
        rm_result = trueStr + rl_line;
    else
        rm_result = falseStr;
    return rm_result;
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



//Room_Index, Room_Type, Room_Title 반환해줌  >> date 추가하기
string MySQL::room_List() {
    int room_Index;
    string room_Title;
    int room_Type;
    string room_Date;
    string line = "";
    string _rlresult = "";
    sql::ResultSet* res = stmt->executeQuery("SELECT Room_Index, Room_Type, Room_Title, Room_Date FROM room_list WHERE (Room_Index>1) ;");

    while (res->next())
    {
        room_Index = res->getInt(1);
        room_Type = res->getInt(2);
        room_Title = res->getString(3);
        room_Date = res->getString(4);
        line = line + "\n" + s_(room_Index) + delim + s_(room_Type) + delim + "*/" + room_Title + "*/" + delim + room_Date;

    }
    if (line.size() > 0)
    {
        _rlresult = trueStr + line;
    }
    else
    {
        _rlresult = falseStr;
    }

    return _rlresult;
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


     _from_nickname ="";
     _date ="";
     _id ="";





    ss >> _Index;
    int _Index_Int = stoi(_Index);
    //multimsg = true; // 여러번 보내야할때 잠깐 false로바뀜
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
                stmt->execute("UPDATE member SET Join_Room_Index = NULL WHERE Member_ID = '" + _id + "';");// 추가열
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
                _ret = s_(e_id_find_ID) + delim + trueStr + delim + res->getString("Member_ID");
                break;
            }
            else
            {
                _ret = s_(e_id_find_ID) + delim +falseStr;
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
                _ret = s_(e_id_find_PW) +delim + trueStr + delim + res->getString("Member_PW");
                break;
            }
            else
            {
                _ret = s_(e_id_find_PW) + delim + falseStr;
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
                _ret = s_(e_signup_IDchk) + delim + falseStr;
                break;
            }
            else
            {
                _ret = s_(e_signup_IDchk) + delim + trueStr;
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
                _ret = s_(e_signup_NickNamechk) + delim + falseStr;
                break;
            }
            else
            {
                _ret = s_(e_signup_NickNamechk) + delim + trueStr;
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
                _ret = s_(e_signup_Submit) + delim + trueStr; //회원가입 등록 완
                break;
            }
            else
            {
                _ret = s_(e_signup_Submit) + delim + falseStr;
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
                _ret = s_(e_edit_PWchk) + delim + trueStr;
                break;
            }
            else
            {
                _ret = s_(e_edit_PWchk) + delim + falseStr;
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
                _ret = s_(e_edit_NickNamechk) + delim + falseStr;
                break;
            }
            else
            {
                _ret = s_(e_edit_NickNamechk) + delim + trueStr;
                break;
            }
        }
        case e_edit_Confirm:
        {
            string _id = sck_list[idx]._user.getID();
            // 순서 Email; Phone; Nickname; Cha_Num; Member_PW;        

            string _email, _phone, _nickname, _cha_num, _pw;

            ss >> _email >> _phone >> _nickname >> _cha_num >> _pw;
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
                _ret = s_(e_edit_Confirm) + trueStr;
                break;
            }
            else
            {
                _ret = s_(e_edit_Confirm) + falseStr;
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

        case e_message_Cnt:
        {

            string _id = sck_list[idx]._user.getID();
            string _to_nickname, _msg;


            std::stringstream ss_id, ss_date;
            prep_stmt = con->prepareStatement("SELECT * FROM short_note WHERE To_Short_Note_ID = ? AND (Respond_Short_Note = 0 OR Respond_Short_Note = 4);");
            prep_stmt->setString(1, _id);
            res = prep_stmt->executeQuery();

            int cntUnreadMsg = 0;
            while (res->next()) {

                cntUnreadMsg++;
                // 결과 처리
            }
            result = s_(cntUnreadMsg);

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
        case e_message_Sent_list: // 보낸 메세지
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname, _msg;


            /*string query = "SELECT Member_ID FROM member WHERE Nickname = '" + _to_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);*/

            std::stringstream ss_id_from, ss_date_from, ss_status;
            prep_stmt = con->prepareStatement("SELECT * FROM short_note WHERE From_Short_Note_ID = ? AND (Respond_Short_Note = 0 OR Respond_Short_Note = 1 OR Respond_Short_Note = 2 OR Respond_Short_Note = 3);");
            prep_stmt->setString(1, _id);

            res = prep_stmt->executeQuery();

            // 이거는 엔터가 들어간 메세지를 구분해야하는 다른곳에서도 쓰일수 있어.
            while (res->next()) {

                ss_id_from << res->getString("To_Short_Note_ID") + delim; // 결과 값을 스트림에 추가
                ss_status << res->getString("Respond_Short_Note") + delim;
                ss_date_from << res->getString("Short_Note_Datetime") + "\n";
                
                // 결과 처리
            }
            _id_from = "", _nick_from = "", _msg = "";
            _id_temp = "", _msg_temp = "", result = "";
            string _date_from;

            while (ss_id_from >> _id_temp)
            {
                if(ss_status >> _msg_temp)
                {
                    if(getline(ss_date_from, _date_from))
                    {

                        string query = "SELECT Nickname FROM Member WHERE Member_ID =  '" + _id_temp + "'";
                        stmt = con->createStatement();
                        res = stmt->executeQuery(query);
                        if (res->next()) {
                            _nick_from = "*/" + res->getString("Nickname");
                            result += _nick_from + delim + _msg_temp + delim + _date_from + "\n";
                        }
                    }
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
        case e_message_Sent_msg_delete: // 보낸메세지 메세지 보기
        {
            string _id = sck_list[idx]._user.getID();
            string _to_nickname, _msg, _date;
            result = "";
            
            ss >> _to_nickname;
            getline(ss, _date);
            string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _to_nickname + "'";
            cout << "_to_nickname :  " << _to_nickname << endl;
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            if (res->next()) {
                _id_temp = res->getString("Member_ID");
                string query = "SELECT Short_Note_Text, Respond_Short_Note FROM short_note WHERE To_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                stmt = con->createStatement();
                res2 = stmt->executeQuery(query);
                if (res2->next()) {
                    int respondValue = res2->getInt("Respond_Short_Note");
                    string updateQuery;
                    string deleteQuery;
                    stmt = con->createStatement();
                    if (respondValue == 0) {
                        updateQuery = "UPDATE short_note SET Respond_Short_Note = 4 WHERE To_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                        if (rowsAffected > 0) {
                            // 업데이트 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                            // 업데이트 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else if (respondValue == 1) {
                        updateQuery = "UPDATE short_note SET Respond_Short_Note = 5 WHERE To_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                        if (rowsAffected > 0) {
                            // 업데이트 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                            // 업데이트 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else if ((respondValue == 2 || respondValue == 3)){
                        deleteQuery = "DELETE FROM short_note WHERE To_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsDeleted = stmt->executeUpdate(deleteQuery); // 삭제 쿼리 실행
                        if (rowsDeleted > 0) {
                            // 삭제 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                            // 삭제 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }
            
                }
            }
            break;
        }
        case e_message_UGiven_list: // 받은 메세지 보기
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
        case e_message_UGiven_msg_delete: // 안읽은 메세지 삭제
        {

            std::stringstream ssa(msg);
            string index_temp;
            string _id = sck_list[idx]._user.getID();
            result = "";
            ss >> _from_nickname;
            getline(ss, _date);
            string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            if (res->next()) {
                _id_temp = res->getString("Member_ID");
                string query = "SELECT Short_Note_Text, Respond_Short_Note FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                stmt = con->createStatement();
                res2 = stmt->executeQuery(query);
                if (res2->next()) {
                    int respondValue = res2->getInt("Respond_Short_Note");
                    string updateQuery;
                    string deleteQuery;
                    stmt = con->createStatement();
                    if (respondValue == 0) {
                        updateQuery = "UPDATE short_note SET Respond_Short_Note = 2 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                        if (rowsAffected > 0) {
                            // 업데이트 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                            // 업데이트 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else if (respondValue == 4) {
                        deleteQuery = "DELETE FROM short_note WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" +_date + "'";
                        int rowsDeleted = stmt->executeUpdate(deleteQuery); // 삭제 쿼리 실행
                        if (rowsDeleted > 0) {
                            // 삭제 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                            // 삭제 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }

                }
            }
        }
        case e_message_RGiven_list: // 받은 메세지 보기
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
        case e_message_UGiven_msg: // 읽지않은 받은 메세지 보기 *
        {
            string _id = sck_list[idx]._user.getID();
            _from_nickname, _msg, _date;
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
     
        case e_message_UGiven_Read: // 읽기
        {
            string _id = sck_list[idx]._user.getID();
            
            result = "";
            ss >> _from_nickname;
            getline(ss,_date);
            string query = "SELECT Member_ID FROM Member WHERE Nickname =  '" + _from_nickname + "'";
            stmt = con->createStatement();
            res = stmt->executeQuery(query);

            if (res->next()) {
                _id_temp = res->getString("Member_ID");
                string query = "SELECT Respond_Short_Note FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                stmt = con->createStatement();
                res2 = stmt->executeQuery(query);
                if (res2->next()) {
                    int respondValue = res2->getInt("Respond_Short_Note");
                    string updateQuery;
                    string deleteQuery;
                    stmt = con->createStatement();
                    if (respondValue == 0) {
                        updateQuery = "UPDATE short_note SET Respond_Short_Note = 1 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                        if (rowsAffected > 0) {
                             //업데이트 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                             //업데이트 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    if (respondValue == 4) {
                        updateQuery = "UPDATE short_note SET Respond_Short_Note = 5 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                        if (rowsAffected > 0) {
                             //업데이트 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                             //업데이트 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }

                }
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
        case e_message_RGiven_msg_delete: // 읽은 메세지 삭제
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
                string query = "SELECT Short_Note_Text, Respond_Short_Note FROM short_note WHERE From_Short_Note_ID =  '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                stmt = con->createStatement();
                res2 = stmt->executeQuery(query);
                if (res2->next()) {
                    int respondValue = res2->getInt("Respond_Short_Note");
                    string updateQuery;
                    string deleteQuery;
                    stmt = con->createStatement();
                    if (respondValue == 1) {
                        updateQuery = "UPDATE short_note SET Respond_Short_Note = 3 WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsAffected = stmt->executeUpdate(updateQuery); // 업데이트 쿼리 실행
                        if (rowsAffected > 0) {
                            // 업데이트 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                            // 업데이트 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else if (respondValue == 5) {
                        deleteQuery = "DELETE FROM short_note WHERE From_Short_Note_ID = '" + _id_temp + "' AND Short_Note_Datetime = '" + _date + "'";
                        int rowsDeleted = stmt->executeUpdate(deleteQuery); // 삭제 쿼리 실행
                        if (rowsDeleted > 0) {
                            // 삭제 성공
                            _ret = trueStr;
                            break;
                        }
                        else {
                            // 삭제 실패
                            _ret = falseStr;
                            break;
                        }
                    }
                    else
                    {
                        break;
                    }

                }
            }
        }

        ////room type (서버 1 공개 2 비공개 3)  - room_PW(없으면 0(공개방))- room_Name 순으로 보내주세요! room_name 에 띄어쓰기 포함 가능해서 뒤로 빼주세요
        //// 방을 만들경우 바로 해당 방으로 입장됨( 해당 방 index가 내가 속한 방 index가 됨
        ////반환값 e_num + IDENTIFIER + True/False + IDETIFIER + 내가 속한 방 index
        ////클라이언트 :같은 방 타입에서 방 이름 중복되면 못들어오게 처리 추가해야됨

        //room list
        case e_room_Create:
        {
            // roomtype + (0 비번없을때)pw(not null) + name
            // roomtype은 1이들어갈수없다.
            // name = "abc cdf"
            // std::stringstream ss(recv_content); //  없어도돼
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

        // enum값만 주면된다.
        case e_room_Exit:
        {  
            string my_ID = sck_list[idx]._user.getID();
            string result;
            string str_room_Index;
            int count = 0;
            int i_room_Index;
            int join_client_num = 0;
            prep_stmt = con->prepareStatement("UPDATE member set Join_Room_Index = NULL WHERE member_ID = ? ;");
            prep_stmt->setString(1, my_ID);
            int rowUpdate = prep_stmt->executeUpdate();
            cout << "int rows_affected = prep_stmt->executeUpdate(); " << rowUpdate << endl;
            if (rowUpdate > 0) {
            sck_list[idx].room.room_init();//방정보 초기화
            result = s_(e_room_Exit) + IDENTIFIER + trueStr;
            cout << "result = s_(e_room_Exit) + IDENTIFIER + True; :" << result << endl;
            str_room_Index = sck_list[idx]._user.getJoinRoomIndex();
            i_room_Index = stoi(str_room_Index);
            for (auto id : workingRoom_list[i_room_Index].join_client)
            {
                if (id == my_ID)
                {
                    join_client_num = count;
                    break;
                }
                count++;
            }
            workingRoom_list[i_room_Index].join_client.erase(workingRoom_list[i_room_Index].join_client.begin() + join_client_num);//내 이름 활성화된 방에서 삭제
            sck_list[idx]._user.setJoinRoomIndex("0");// 방에 안들어간 상태를 0 이라고 두어도 문제 없나?
            result = s_(e_room_Exit) + IDENTIFIER + trueStr;
            }
            else
                result = s_(e_room_Exit) + IDENTIFIER + trueStr;
            return result;
            }

        // 방의 인덱스 + 타입 + 패스워드(없으면안보내도 됨)
        case e_room_Enter:
        {
            string my_ID62 = sck_list[idx]._user.getID();
            string result62;
            string room_Type62;
            string room_Title62;
            string room_PW62;
            string room_Index62;
            //std::stringstream ss(recv_content);
            ss >> room_Index62 >> room_Type62 >> room_PW62;
          
            cout << room_Index62 << IDENTIFIER << room_Type62 << IDENTIFIER << room_PW62 << endl;
            int i_room_Type = std::stoi(room_Type62);
            int i_room_Index = std::stoi(room_Index62);

            if (i_room_Type == 3)
            {
                prep_stmt = con->prepareStatement("SELECT* from room_list WHERE Room_Index =? AND Room_PW =?;");
                cout << "SELECT* from room_list WHERE Room_Index =? " << endl;
                prep_stmt->setInt(1, i_room_Index);
                prep_stmt->setString(2, room_PW62);
                sql::ResultSet* res = prep_stmt->executeQuery();

                if (res->next())
                    cout << "성공";
                else
                {
                    result = falseStr;
                    cout << "index 와 pw가 맞지 않습니다" << endl;
                    return result;
                }
            }
            cout << "first if -else exit" << endl;
            prep_stmt = con->prepareStatement("UPDATE member set Join_Room_Index = ? WHERE Member_ID=?;");
            prep_stmt->setInt(1, std::stoi(room_Index62));
            prep_stmt->setString(2, my_ID62);
            int rowUpdate = prep_stmt->executeUpdate();
            if (rowUpdate > 0)
                cout << "rowUpdate >0 " << endl;
            else
            {
                result = falseStr;
                return result;
            }

            if (rowUpdate > 0)
            {
                prep_stmt = con->prepareStatement("SELECT* from room_list WHERE Room_Index =?;");
                cout << "SELECT* from room_list WHERE Room_Index =? " << endl;
                prep_stmt->setInt(1, i_room_Index);
                sql::ResultSet* res = prep_stmt->executeQuery();

                if (res->next())
                {
                    cout << "  if (prep_stmt->execute()) : " << endl;
                    sck_list[idx].room.setRoom_Index(res->getInt(1));
                    sck_list[idx].room.setRoom_Type(res->getInt(2));
                    sck_list[idx].room.setRoom_Title(res->getString(3));
                    if (i_room_Type != 1)// 서버방은 방장이 없으니 예외 처리
                        sck_list[idx].room.setRoom_Master(res->getString(4));
                    sck_list[idx].room.setRoom_Date(res->getString(5));
                    if (i_room_Type == 3)// 비밀방만 비밀번호 받으므로 예외 처리
                        sck_list[idx].room.setRoom_PW(res->getString(6));
                    sck_list[idx]._user.setJoinRoomIndex(room_Index62);
                    room_activate(stoi(room_Index62), idx);
                    result = trueStr;
                    cout << "result : " << result << endl;
                    return result;
                }

                else
                {
                    cout << "등록은 성공 but 클래스 객체에 정보 저장 실패" << endl; 
                    result = falseStr;
                    return result;
                }
            }
            else
            {
                result = falseStr;
                return result;
            }
        }
        case e_room_show_whole_Text:
        {
            multimsg = true;
            string row;
            string all_Text = "";
            string result;
            string nickname, chat, chat_Data = "";
            int room_index = stoi(sck_list[idx]._user.getJoinRoomIndex());
            prep_stmt = con->prepareStatement("select member.Nickname, room_chat.Chat, Chat_Date FROM room_chat left join member on room_chat.Member_ID = member.member_ID WHERE Room_Index= ?");
            prep_stmt->setInt(1, room_index);
            sql::ResultSet* res = prep_stmt->executeQuery();
            while (res->next())
            {
                nickname = res->getString(1);
                chat = res->getString(2);
                chat_Data = res->getString(3);
                row = nickname + " : " + chat + "  " + chat_Data + "\n";
                all_Text += row;
            }
            all_Text += "-------------------------------------이전내역-----------------------------------------\n";
            send(sck_list[idx].sck, all_Text.c_str(), all_Text.size(), 0);
            break;
        }
        //case e_room_show_whole_Text:
        //{
        //    multimsg = true;
        //    string row;
        //    string all_Text = "";
        //    string result;
        //    string nickname, chat, chat_Data = "";
        //    int room_index = stoi(sck_list[idx]._user.getJoinRoomIndex());
        //    prep_stmt = con->prepareStatement("SELECT Member_ID, Chat, Chat_Date FROM room_chat WHERE Room_Index=?");
        //    prep_stmt->setInt(1, room_index);
        //    sql::ResultSet* res = prep_stmt->executeQuery();
        //    while (res->next())
        //    {
        //        nickname = res->getString(1);
        //        chat = res->getString(2);
        //        chat_Data = res->getString(3);
        //        row = nickname + " : " + chat + "  " + chat_Data + "\n";
        //        send(sck_list[idx].sck, row.c_str(), row.size(), 0);
        //    }
        //    row = trueStr + IDENTIFIER + "-------------------------------------이전내역-----------------------------------------\n";
        //    send(sck_list[idx].sck, row.c_str(), row.size(), 0);
        //}
        
        case e_room_Chat:
        {   multimsg = true;
            std::string modifiedString = msg.substr(3);
            string msg_chat = "";
            string result = "";
            int room_Type;
            string room_Date;
            string my_Nickname66;
            string date66 = getCurrentTime();
            cout << msg_chat << endl;
            string my_ID66 = sck_list[idx]._user.getID();
            prep_stmt = con->prepareStatement("SELECT Nickname from member WHERE Member_ID = ?");
            prep_stmt->setString(1, my_ID66);
            sql::ResultSet* res = prep_stmt->executeQuery();
            if (res->next())
                my_Nickname66 = res->getString(1);
            int room_Index66 = stoi(sck_list[idx]._user.getJoinRoomIndex());
            prep_stmt = con->prepareStatement("INSERT INTO room_chat VALUES (NULL,?,?,?,?)");
            prep_stmt->setString(1, my_ID66);
            prep_stmt->setString(2, modifiedString);
            prep_stmt->setString(3, date66);
            prep_stmt->setInt(4, room_Index66);
            int rowUpdate = prep_stmt->executeUpdate();
            cout << "rowUpdate : " << rowUpdate << endl;
            if (rowUpdate > 0)
            {
                msg_chat = my_Nickname66 + " : " + modifiedString;
                _send_msg(msg_chat.c_str(), room_Index66);// 방에 참여한 모든 사람에게 메시지를 보내는 함수
                cout << "if (res->next()) " << endl;
            }
            return _ret;
        }

        case e_room_List:
        {
            _ret = room_List();
            break;
        }
        case e_room_myList:
        {
            _ret = room_myList(idx);
            break;
        }
        case e_room_Delete:
        {
            std::string temp_63;
            ss >> temp_63;
            _ret = room_Delete(temp_63, idx);
            break;
        }

        




        default:
            break;
    }

    return _ret;
}
