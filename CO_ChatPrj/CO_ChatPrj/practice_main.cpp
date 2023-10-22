//���� Ȯ�����ּ���! �� ������ ����
//�������� �÷��̴ּ� ������ �ʹ� ä�ù� ���� �����̶� ����κ��� 
//������ �����ؼ� �޽����� �ް� �����༭ ��� ó���� �켱 �� �� �ֵ��� ���� �κ��Դϴ�.
// add_client1�� recv_from_server �� ���Ǵ� �� �κ��Դϴ�.
//ä�ù� �� ��ü ��������� ��� ���� ���� send�� ����� �����Դϴ�. >> send�� �Լ��� recv_from_serveró�� �������� ����

#pragma comment(lib, "ws2_32.lib") //������� ���̺귯���� ��ũ. ���� ���̺귯�� ����

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
#define MAX_SIZE 1024//���� �ڽ�ũ��
#define MAX_CLIENT 3

//using namespace std;

using std::cout;
using std::cin;
using std::endl;
using std::string;

string _Index;
const time_t timer = time(NULL);
const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ

bool isNumeric(const std::string& str);

string getCurrentTime();
const std::string nowTime = getCurrentTime();


string s_(int e_num) {
    return std::to_string(e_num);
}

struct SOCKET_INFO { // ����� ���� ������ ���� Ʋ ����
    SOCKET sck;
    UserInfo user;
    Room room;
    string user_;
};

std::vector<SOCKET_INFO> sck_list; // ����� Ŭ���̾�Ʈ ���ϵ��� ������ �迭 ����.
SOCKET_INFO server_sock; // ���� ���Ͽ� ���� ������ ������ ���� ����.
int client_count = 0; // ���� ������ �ִ� Ŭ���̾�Ʈ�� count �� ���� ����.
SOCKET Client_sck; // =  sck_list[];

//�����Լ���
void server_init(); // socket �ʱ�ȭ �Լ�. socket(), bind(), listen() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void add_client(); // ���Ͽ� ������ �õ��ϴ� client�� �߰�(accept)�ϴ� �Լ�. client accept() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void send_msg(const char* msg); // send() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void recv_msg(int idx); // recv() �Լ� �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.
void del_client(int idx); // ���Ͽ� ����Ǿ� �ִ� client�� �����ϴ� �Լ�. closesocket() �����. �ڼ��� ������ �Լ� �����ο��� Ȯ��.

void recv_from_client(int idx); //����
const string IDENTIFIER = " ";
const string True = "true";
const string False = "false";




class MY_SQL {
public:
    // MySQL Connector/C++ �ʱ�ȭ
    sql::mysql::MySQL_Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
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

        // �����ͺ��̽� ����
        con->setSchema("chat");

        // db �ѱ� ������ ���� ���� 
        stmt = con->createStatement();
        //stmt->execute("set names 'utf8'");
        stmt->execute("set names euckr");
        //if (stmt) { delete stmt; stmt = nullptr; }

    }

  
         //���̵� �ߺ�Ȯ��
        string signup_IDchk(string recv_content) {

        std::stringstream ss(recv_content);
        string mysql_check_id;
        ss >> mysql_check_id;
        sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Member_ID = '" + mysql_check_id + "'");
        string result;
        if (res->next()) {
            result = s_(e_signup_IDchk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� id �ٸ� �ŷ� ������
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
                result = s_(e_signup_NickNamechk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� id �ٸ� �ŷ� ������
            }
            else
            {
                result = s_(e_signup_NickNamechk) + IDENTIFIER + True;
            }
            //try {
            //    prep_stmt = con->prepareStatement("SELECT Nickname FROM member WHERE Nickname = ?");
            //    cout << "prep_stmt = con->prepareStatement ����" << endl;
            //    prep_stmt->setString(1, mysql_check_nickname);
            //    string result;
            //    sql::ResultSet* res = prep_stmt->executeQuery();
            //    if ((res->next()))
            //        result = s_(e_signup_NickNamechk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� nickname �ٸ� �ŷ� ������
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

        //send�Լ��� ���� �������°� ���ڴ�. return string���� result�� ��ȯ�ϰ� 
        // pw �ߺ� üũ,���� üũ ���� �̻��� Ŭ���̾�Ʈ���� ó���ϰ� mysql���������⸸ ��ü������ �����Ѵ�.
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
                result = s_(e_signup_Submit) + IDENTIFIER + True; //ȸ������ ��� ��
                cout << " result = s_(e_signup_Submit) + IDENTIFIER + True; //ȸ������ ��� �� ";
            }
            else
            {
                result = s_(e_signup_Submit) + IDENTIFIER + False;//��� ����
                cout << " result = s_(e_signup_Submit) + IDENTIFIER + False; //ȸ������ ��� x ";
            }
            return result;
       
        }
   
    //�α���Ȯ���ϱ�
    string try_Signin( string recv_content, int this_idx) {
        std::stringstream ss(recv_content);
        string mysql_check_id;
        string mysql_check_pw;
        ss >> mysql_check_id >> mysql_check_pw;
        
        cout << "mysql_check_id : " << mysql_check_id << "mysql_check_pw : " << mysql_check_pw;
        prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = ? AND Member_PW = ?");
        prep_stmt->setString(1, mysql_check_id);
        prep_stmt->setString(2, mysql_check_pw);
        cout << " prep_stmt = con->prepareStatement : ����Ϸ�" << endl;
        string result;
        sql::ResultSet* res = prep_stmt->executeQuery();
            if ((res->next()))
            {
            result = s_(e_id_try_Signin) + IDENTIFIER + True;
            sck_list[this_idx].user.setID(mysql_check_id);
            sck_list[this_idx].user.setPW(mysql_check_pw);
            cout << "�α��� ���� \n";
            }
            else
            {
                result = s_(e_id_try_Signin) + IDENTIFIER + False;
                cout << "�α��� ���� \n";
            }
            string my_ID = sck_list[this_idx].user.getID();
            cout << "string my_ID = sck_list[this_idx].user.getID(); " << my_ID << endl;
        return result;
     
    }

       //���̵�ã��
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
            result = s_(e_id_find_ID) + IDENTIFIER + True+ IDENTIFIER + resid; //true false �� const string True = "True" ������ ���� �ֽ��ϴ�
        else 
            result = s_(e_id_find_ID) + IDENTIFIER + False;
       return result;
    
    }
       //��й�ȣã��
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
            cout << "  if (res->next()):" << respw<< "�ذ�" << endl;
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

    // e_edit_PWchk = 31 �����Ϸ��� ��й�ȣ �޾��� �� mysql ���� ����, ������ ���̵� ������ �־�� �� 
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
        cout << "sql::ResultSet* res = prep_stmt->executeQuery(); �Ϸ� "<< res<< endl;
        if ((res->next()))
        {
            result = s_(e_edit_PWchk) + IDENTIFIER+ True;
            cout << " ���� result : " << result << endl;
        }
        else
        {
            result = s_(e_edit_PWchk) + IDENTIFIER+ False;
            cout << " ���� result : " << result << endl;
        }
        return result;
   
    }

        //�ܼ� �ߺ� üũ
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
                result = s_(e_edit_Confirm) + IDENTIFIER + True; //���� ���� ����
            else
                result = s_(e_edit_Confirm) + IDENTIFIER + False;//���� ���� ����
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
            //����? �� ���� ���� �� �����صα�
           
           

            return result;
           
        }

        //���� ó���� ���� �޽����� �ð��� �޾ƿ´� 
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
        
        //client���� ���� ������ ���� getLine���� �����Ŷ� enter������ ��������
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
                text +=  msgLine+"\n"; //���� �� �޽��� ���븸 string���� �޾���
           
            prep_stmt = con->prepareStatement("INSERT INTO short_note VALUES (NULL,?,?,3,?,?);");
            prep_stmt->setString(1, my_ID);
            prep_stmt->setString(2, friend_ID);
            prep_stmt->setString(3, datetime);
            prep_stmt->setString(4, text);
            //datetime �������� ���� 
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
            //���� execute�� �������Ǿ� ���� ����Ǿ������� ��� result���� false�� ����
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
     

        //response 1 ���� 2 ���� 3 ������
        string friends_List(int this_idx) {
            string my_ID = sck_list[this_idx].user.getID();
            cout << "my_ID : " << my_ID << endl;
            string result;
            prep_stmt = con->prepareStatement("SELECT Distinct My_Friend_ID From friend_list WHERE My_ID = ?;");
            prep_stmt->setString(1, my_ID);
            sql::ResultSet* res = prep_stmt->executeQuery();
            cout << "sql::ResultSet* res = prep_stmt->executeQuery(); ���� �Ϸ� "  << endl;
            //���� execute�� �������Ǿ� ���� ����Ǿ������� ��� result���� false�� ����
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
            cout << "sql::ResultSet* res = prep_stmt->executeQuery(); ���� �Ϸ� " << endl;
            //���� execute�� �������Ǿ� ���� ����Ǿ������� ��� result���� false�� ����
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
        //ģ�� ��û ������, ID�� �����Ѵٸ� ��û ������ �������� �ʴ´ٸ� false��ȯ
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

        //room type (���� 1 ���� 2 ����� 3) - room_Name - room_PW(������ 0(������)) ������ �����ּ���!
        string room_Create(string recv_content, int index) {
            std::stringstream ss(recv_content);
            string result;
            string room_Type;
            int i_room_Type;
            string room_PW;
            string room_Name;
            string my_ID = sck_list[index].user.getID();
            string room_date = getCurrentTime();
            ss >> room_Type >> room_Name >> room_PW; // pw�� ���� ��쿡 0�̶� �����ֱ� ��û
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
                        cout << "���� ���� �Ϸ�";
                        result = s_(e_room_Create) + IDENTIFIER + True + IDENTIFIER + sck_list[index].user.getJoinRoomIndex();
                        cout << "result : " << result << endl;
                        return result;

                        //������ ���� ���� index (room_list�� primary key) ������
                    }
                    else {
                        cout << "����� ���� but ���� ���� ����" << endl;
                        result = s_(e_room_Create) + IDENTIFIER + False;
                        return result;
                    }
                }
                else
                {
                    cout << "����� ���� but ���� ���� ����" << endl;
                    result = s_(e_room_Create) + IDENTIFIER + False;
                    return result;
                }
            }
            else
            {
                cout << "INSERT INTO ����"<<endl;
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
                sck_list[index].room.room_init();//������ �ʱ�ȭ
                result = s_(e_room_Exit) + IDENTIFIER + True;
                sck_list[index].user.setJoinRoomIndex(NULL);
            }
            else 
                result = s_(e_room_Exit) + IDENTIFIER + False;
        }
        
        //���� �� type , �� ����, pw �޾ƿ��� �������� ��� pw =0
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
    // Internet�� Stream ������� ���� ����
   // SOCKET_INFO�� ���� ��ü�� socket �Լ� ��ȯ��(��ũ���� ����)
   // ���ͳ� �ּ�ü��, ��������, TCP �������� �� ��. 

    SOCKADDR_IN server_addr = {}; // ���� �ּ� ���� ����
    // ���ͳ� ���� �ּ�ü�� server_addr

    server_addr.sin_family = AF_INET; // ������ Internet Ÿ�� 
    server_addr.sin_port = htons(7777); // ���� ��Ʈ ����
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);  // �����̱� ������ local �����Ѵ�. 
    //Any�� ���� ȣ��Ʈ�� 127.0.0.1�� ��Ƶ� �ǰ� localhost�� ��Ƶ� �ǰ� ���� �� ����ϰ� �� �� �ֵ�. �װ��� INADDR_ANY�̴�.
    //ip �ּҸ� ������ �� server_addr.sin_addr.s_addr -- ������ ���?

    bind(server_sock.sck, (sockaddr*)&server_addr, sizeof(server_addr)); // ������ ���� ������ ���Ͽ� ���ε��Ѵ�.
    listen(server_sock.sck, SOMAXCONN); // ������ ��� ���·� ��ٸ���.
    //*
    server_sock.user_ = "server";

    cout << "Server On" << endl;
}

//void add_client() {
//    SOCKADDR_IN addr = {};
//    int addrsize = sizeof(addr);
//    char buf[MAX_SIZE] = { };
//
//    ZeroMemory(&addr, addrsize); // addr�� �޸� ������ 0���� �ʱ�ȭ
//
//    SOCKET_INFO new_client = {};
//
//    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
//    recv(new_client.sck, buf, MAX_SIZE, 0);
//    cout << "buf Ȯ�� 1 " << buf << endl;
//    // Winsock2�� recv �Լ�. client�� ���� �г����� ����.
//    new_client.user = string(buf);
//
//    string msg = "[����] " + new_client.user + " ���� �����߽��ϴ�.";
//    cout << msg << endl;
//    sck_list.push_back(new_client); // client ������ ��� sck_list �迭�� ���ο� client �߰�
//
//    std::thread th(recv_msg, client_count);
//    // �ٸ� �����κ��� ���� �޽����� ����ؼ� ���� �� �ִ� ���·� ����� �α�.
//
//    client_count++; // client �� ����.
//    cout << "[����] ���� ������ �� : " << client_count << "��" << endl;
//    send_msg(msg.c_str()); // c_str : string Ÿ���� const chqr* Ÿ������ �ٲ���.
//
//    th.join();
//}

int client_num = 0;
void add_client1() { //add_client  �����ؼ� �츮 ��Ȳ�� �°� ����ϰ� ����
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr�� �޸� ������ 0���� �ʱ�ȭ

    SOCKET_INFO new_client = {};

    new_client.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize); //���α׷��� �����Ҷ� ������ ����Ǵ� ù �κ�
    cout << "accept" << endl;
    sck_list.push_back(new_client);
   
    // �α����̳� ȸ���������� ���۵�
    string reading = string(buf);
    string msg = string(buf + 3);
    //std::thread th(recv_from_client,server_sock.sck, reading,msg);
    //���� recv_from_client �Լ��� ���Ǵ� ���ڵ��� ��� �־�����?????? ����ó�� ����� �������� �־��� �� �ִ�.?
    std::thread th(recv_from_client, client_num++);
    th.join();

}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) { // ������ �ִ� ��� client���� �޽��� ����
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}


//void recv_msg(int idx) {
//    char buf[MAX_SIZE] = { };
//    string msg = "";
//
//    //cout << sck_list[idx].user << endl;
//
//    while (1) { //  recv�� ������ ���⿡ switch �ֱ� 
//        // add client () �������� ��.
//
//
//        ZeroMemory(&buf, MAX_SIZE);
//        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // ������ �߻����� ������ recv�� ���ŵ� ����Ʈ ���� ��ȯ. 0���� ũ�ٴ� ���� �޽����� �Դٴ� ��.
//            cout << " buf 3 " << buf << endl;
//            msg = sck_list[idx].user + " : " + buf;
//            cout << msg << endl;
//            send_msg(msg.c_str());
//        }
//        else { //�׷��� ���� ��� ���忡 ���� ��ȣ�� �����Ͽ� ���� �޽��� ����
//            msg = "[����] " + sck_list[idx].user + " ���� �����߽��ϴ�.";
//            cout << msg << endl;
//            send_msg(msg.c_str());
//            del_client(idx); // Ŭ���̾�Ʈ ����
//            return;
//        }
//    }
//}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    //sck_list.erase(sck_list.begin() + idx); // �迭���� Ŭ���̾�Ʈ�� �����ϰ� �� ��� index�� �޶����鼭 ��Ÿ�� ���� �߻�....��
    client_count--;
}

void recv_from_client(int idx) {// �޼����� ������ Ÿ�� ���� �ϴ� ���� �Լ�
    char buf[MAX_SIZE] = { };
    string msg = "";
    string identifier = "";
    string recv_content = "";
    //cout << sck_list[idx].user << endl;
    int e_num = 0;
    int this_idx = idx;
    string result = "";

    while (1) { //  recv�� ������ ���⿡ switch �ֱ� 
        // add client () �������� ��.
        SOCKET Client_sck = sck_list[idx].sck;

        ZeroMemory(&buf, MAX_SIZE);
        if (recv(Client_sck, buf, MAX_SIZE, 0) > 0) {
            msg = buf;
            cout << "buf Ȯ�� 4: " << buf << endl;
            std::stringstream ss(msg);  // ���ڿ��� ��Ʈ��ȭ
            ss >> _Index;
            recv_content = string(buf + 3);



        }
        else {
            //����
            cout << "����" << endl;
            return;
        }
        //����ó�� �ʿ�
        if (isNumeric(_Index))
        {
            int _Index_Int = stoi(_Index);
            cout << "�ε���"<<_Index_Int;

            switch (_Index_Int)
            {
            case e_signup_IDchk:
                cout << " case ���� ���Դ�" << endl;
                result = mysql.signup_IDchk(recv_content);send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_signup_NickNamechk:
                cout << " e_signup_NickNamechk case ���� ���Դ�" << endl;
                result = mysql.signup_Nicknamechk(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_signup_Submit:
                result = mysql.signup_Submit(recv_content); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_id_try_Signin:
                result = mysql.try_Signin(recv_content,idx); send(Client_sck, result.c_str(), result.size(), 0); break;
            
            case e_id_find_ID:
                cout << " case�� ���� ";
                result = mysql.find_ID(recv_content); send(Client_sck, result.c_str(), result.size(), 0); break;
            case e_id_find_PW:
                result = mysql.find_PW(recv_content); send(Client_sck, result.c_str(), result.size(), 0); break;

            case e_edit_PWchk:
                cout << "e_edit_PWchk = 31 " << endl << "idx : " << idx << endl;
                result = mysql.edit_PWchk(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); cout << "send�Ϸ�" << endl; break;
            case e_edit_NickNamechk:
                cout << "  e_edit_NickNamechk :" << endl;
                result = mysql.edit_Nicknamechk(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); cout << "send �ƾ��" << endl; break;
            case e_edit_Confirm:
                cout << "    case e_edit_Confirm : " << endl;
                result = mysql.edit_Confirm(recv_content, idx); send(Client_sck, result.c_str(), result.size(), 0); cout << "send �ƾ��" << endl; break;

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
                result = mysql.friends_List(idx); send(Client_sck, result.c_str(), result.size(), 0); cout<<"send �Ϸ�";break;
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

        // Winsock�� �ʱ�ȭ�ϴ� �Լ�. MAKEWORD(2, 2)�� Winsock�� 2.2 ������ ����ϰڴٴ� �ǹ�.
        // ���࿡ �����ϸ� 0��, �����ϸ� �� �̿��� ���� ��ȯ.
        // 0�� ��ȯ�ߴٴ� ���� Winsock�� ����� �غ� �Ǿ��ٴ� �ǹ�.
        int code = WSAStartup(MAKEWORD(2, 2), &wsa);

        if (!code) {
            mysql.set_database();
            server_init();

            std::thread th1[MAX_CLIENT];
            for (int i = 0; i < MAX_CLIENT; i++) {
                // �ο� �� ��ŭ thread �����ؼ� ������ Ŭ���̾�Ʈ�� ���ÿ� ������ �� �ֵ��� ��.
                th1[i] = std::thread(add_client1);
            }
            //���� add_client1ó�� ó������ ����ڸ� �޾��ִ� �� �ƴ϶� ���� �� �����Ϸ��� ��� �ؾ��ϴ���
            // �̰� ä�ÿ����� ���̴� ���� �� ��ɾ ���� ���� ����ϴ� ����
            //std::thread th1(add_client); // �̷��� �ϸ� �ϳ��� client�� �޾���...

            while (1) { // ���� �ݺ����� ����Ͽ� *����*�� ����ؼ� Ŭ���̾�Ʈ���� ä�� ���� �� �ִ� ���¸� ����� ��. �ݺ����� ������� ������ �� ���� ���� �� ����.
                string text, msg = "";

                std::getline(cin, text);
                const char* buf = text.c_str();
                msg = server_sock.user_ + " : " + buf;
                send_msg(msg.c_str());
            }

            for (int i = 0; i < MAX_CLIENT; i++) {
                th1[i].join();
                //join : �ش��ϴ� thread ���� ������ �����ϸ� �����ϴ� �Լ�.
                //join �Լ��� ������ main �Լ��� ���� ����Ǿ thread�� �Ҹ��ϰ� ��.
                //thread �۾��� ���� ������ main �Լ��� ������ �ʵ��� ����.
            }
           /* th1.join();*/

            closesocket(server_sock.sck);
        }
    

        else {
            cout << "���α׷� ����. (Error code : " << code << ")";
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