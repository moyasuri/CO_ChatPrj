#pragma once

#include <string>
#include <mysql/jdbc.h>
#include "UsageServer.h"
#include <vector>
using std::string;


const string IDENTIFIER = " ";
const string delim = " ";
const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

   


struct ROOM_INFO {
    int Room_Index = 0;
    std::vector<std::string> join_client;
};

class MySQL {
public:
   
    MySQL();

    ~MySQL();
    
    
  
    void Init_Mysql();
    void set_database(string str);
    string QuerySql(string msg, int idx);
    string getCurrentTime();
    void room_activate(int roomIndex, int index__);
    void _send_msg(const char* msg, int room_Index66);
    string room_List();
    string room_Delete(string roomidx, int idx);
    string room_myList(int index);
    bool isWorkingRoomIndexExist(int roomIndex);
private:
    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;
    sql::ResultSet* res2;



     
};


