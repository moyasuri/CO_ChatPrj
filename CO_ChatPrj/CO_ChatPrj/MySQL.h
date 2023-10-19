/*prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?'");
prep_stmt->setString(1, "mysql_check_id");*/
//stmt = con->createStatement();//�ʼ� set�ϰ� ���������� ����Ҷ� �ٽ� �������� �Ѵ�. 
//������ ���߿� �ϴ°ŷ� �ٲ�

#pragma once
#include <mysql/jdbc.h>
#include <string>
#include <sstream>
#include <vector>
#include "UsageServer.h"
#include "UserInfo.h"





using std::cout;
using std::endl;
using std::string;
const string IDENTIFIER = " ";
const string trueStr = "true";
const string falseStr = "false";


const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ



// #define MAX_SIZE 1024//���� �ڽ�ũ��

const string True = "True";
const string False = "False";



class MySQL {
public:
    
    string s_(int e_num) {
        return std::to_string(e_num);
    }

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

        // �����ͺ��̽� ����
        con->setSchema(str);
        // db �ѱ� ������ ���� ���� 
        stmt = con->createStatement();
        stmt->execute("set names 'utf8'");
        // �� �Լ��� ���� ������� if (stmt) { delete stmt; stmt = nullptr; }
    }

    //ģ����� ������ ��������
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
            string _my_id, _my_pw;
            ss >> _my_id >> _my_pw;
            prep_stmt = con->prepareStatement("SELECT Member_ID FROM practice WHERE Member_ID = ? AND Member_PW = ?");
            prep_stmt->setString(1, _my_id);
            prep_stmt->setString(2, _my_pw);
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

        }

        return _ret;
    }

    string signup_IDchk(string recv_content) {

        std::stringstream ss(recv_content);
        string mysql_check_id;
        ss >> mysql_check_id;
        sql::ResultSet* res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Member_ID = '" + mysql_check_id + "'");
        cout << "sql::ResultSet* res = stmt->executeQuery" << endl;
        string result;
        if (res->next()) {
            result = s_(e_signup_IDchk) + IDENTIFIER + False; //�̹� �����ϴ� ���̴� id �ٸ� �ŷ� ������
        }
        else
        {
            result = s_(e_signup_IDchk) + IDENTIFIER + True;
        }
        return result;
        if (stmt) { delete stmt; stmt = nullptr; }
    }

    string try_Signin(string recv_content, int this_idx) {
        cout << " string send_login_check �Լ� �� " << endl;
        std::stringstream ss(recv_content);
        string mysql_check_id;
        string mysql_check_pw;
        ss >> mysql_check_id >> mysql_check_pw;
        cout << "mysql_check_id : " << mysql_check_id << "mysql_check_pw : " << mysql_check_pw;
        prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?' AND Member_PW = '?'");
        prep_stmt->setString(1, mysql_check_id);
        prep_stmt->setString(2, mysql_check_pw);
        cout << " prep_stmt = con->prepareStatement : ����Ϸ�" << endl;
        string result;

        if ((prep_stmt->execute()) == 1)
        {
            result = s_(e_id_try_Signin) + IDENTIFIER + "True";
            sck_list[this_idx].user.setID(mysql_check_id);
            sck_list[this_idx].user.setPW(mysql_check_id);
        }
        else
            result = s_(e_id_try_Signin) + IDENTIFIER + "False";
        return result;

    }

    string find_ID(string recv_content) {
        // cout << " string send_find_ID(string recv_content) {" << endl;
        std::stringstream ss(recv_content);
        string mysql_check_name;
        string mysql_check_email;
        ss >> mysql_check_name >> mysql_check_email;
        //cout << "  mysql_check_name >> mysql_check_email : " << mysql_check_name <<endl<< mysql_check_email << endl;
        string resid = "";
        string result;
        res = stmt->executeQuery("SELECT Member_ID FROM member WHERE Email = '" + mysql_check_email + "' AND Name = '" + mysql_check_name + "'");
        //cout << " res = stmt->executeQuery" << endl;
        if (res->next()) {
            resid = res->getString("Member_ID");
        }
        if (resid.size() != 0)
            result = s_(e_id_find_ID) + IDENTIFIER + True + resid; //true false �� const string True = "True" ������ ���� �ֽ��ϴ�
        else
            result = s_(e_id_find_ID) + IDENTIFIER + False;
        return result;
    }

    string find_PW(string recv_content) {
        std::stringstream ss(recv_content);
        string mysql_check_id;
        string mysql_check_birth;
        string mysql_check_phone;
        ss >> mysql_check_id >> mysql_check_birth >> mysql_check_phone;
        string respw = "";
        string result = "";
        res = stmt->executeQuery("SELECT Member_PW FROM member WHERE Member_ID = '" + mysql_check_id + "' AND Birth = '" + mysql_check_birth + "' AND Phone = '" + mysql_check_phone + "'");
        if (res->next()) {
            respw = res->getString("Member_PW");
        }
        cout << "  if (res->next()):" << respw << "�ذ�" << endl;
        if (respw.size() != 0)
        {
            result = s_(e_id_find_PW) + IDENTIFIER + True + respw;
        }
        else
        {
            result = s_(e_id_find_PW) + IDENTIFIER + False;
        }
        return result;
        if (stmt) { delete stmt; stmt = nullptr; }
    }



    string edit_PWchk(string recv_content, int this_idx) {
        std::stringstream ss(recv_content);
        string my_ID = sck_list[this_idx].user.getID();
        string mysql_check_pw;
        string result;
        ss >> mysql_check_pw;
        prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?' AND Member_PW = '?'");
        prep_stmt->setString(1, my_ID);
        prep_stmt->setString(2, mysql_check_pw);
        if (prep_stmt->execute())
        {
            result = s_(e_edit_PWchk) + True;
        }
        else
        {
            result = s_(e_edit_PWchk) + False;
        }
        return result;
    }

    string edit_Nicknamechk(string recv_content, int this_idx) {
        string my_ID = sck_list[this_idx].user.getID();
        string check_nickname;
        string result;
        std::stringstream ss(recv_content);
        ss >> check_nickname;
        prep_stmt = con->prepareStatement("SELECT Member_ID FROM member WHERE Member_ID = '?' AND Nickname = '?'");
        prep_stmt->setString(1, my_ID);
        prep_stmt->setString(2, check_nickname);
        if (prep_stmt->execute())
        {
            result = s_(e_edit_PWchk) + True;
        }
        else
        {
            result = s_(e_edit_PWchk) + False;
        }
        return result;
    }

    string edit_Confirm(string recv_content, int this_idx) {
        string my_ID = sck_list[this_idx].user.getID();
        std::stringstream ss(recv_content);
        string Email;
        string Phone;
        string Birth;
        string Nickname;
        string Cha_Num;
        string Member_PW;
        string Name;

        string result;

        ss >> Email >> Phone >> Birth >> Nickname >> Cha_Num >> Member_PW >> Name;

        prep_stmt = con->prepareStatement("update member set Email = '?', Phone ='?', Birth = '?' ,Nickname = '?',Cha_Num = '?',Member_PW='?',Name='?' WHERE  Member_ID = '?'");

        prep_stmt->setString(1, Email);
        prep_stmt->setString(2, Phone);
        prep_stmt->setString(3, Birth);
        prep_stmt->setString(4, Nickname);
        prep_stmt->setInt(5, std::stoi(Cha_Num));
        prep_stmt->setString(6, Member_PW);
        prep_stmt->setString(7, Name);
        prep_stmt->setString(8, my_ID);

        if ((prep_stmt->execute()) == 1)
            result = s_(e_signup_Submit) + IDENTIFIER + True; //���� ���� ����
        else
            result = s_(e_signup_Submit) + IDENTIFIER + False;//���� ���� ����

        return result;
        sck_list[this_idx].user.setBirth(Birth);
        sck_list[this_idx].user.setChaNum(std::stoi(Cha_Num));
        sck_list[this_idx].user.setEmail(Email);
        sck_list[this_idx].user.setName(Name);
        sck_list[this_idx].user.setNickName(Nickname);
        sck_list[this_idx].user.setPhone(Phone);
        sck_list[this_idx].user.setPW(Member_PW);

    }







private:

    // MySQL Connector/C++ �ʱ�ȭ
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;


};