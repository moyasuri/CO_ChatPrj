#include <iostream>
#include <string>
#include <mysql/jdbc.h>
#include "UsageServer.h"

using std::cout;
using std::endl;
using std::string;

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호

int main()
{
    // MySQL Connector/C++ 초기화
    sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* pstmt;

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
    stmt->execute("set names 'utf8'");
    if (stmt) { delete stmt; stmt = nullptr; }

    // 데이터베이스 쿼리 실행
    stmt = con->createStatement();
    stmt->execute("DROP TABLE IF EXISTS inventory"); // DROP
    cout << "Finished dropping table (if existed)" << endl;
    stmt->execute("CREATE TABLE inventory (id serial PRIMARY KEY, name VARCHAR(50), quantity INTEGER);"); // CREATE
    cout << "Finished creating table" << endl;
    delete stmt;

    pstmt = con->prepareStatement("INSERT INTO inventory(name, quantity) VALUES(?,?)"); // INSERT

    pstmt->setString(1, "banana");
    pstmt->setInt(2, 150);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "orange");
    pstmt->setInt(2, 154);
    pstmt->execute();
    cout << "One row inserted." << endl;

    pstmt->setString(1, "사과");
    pstmt->setInt(2, 100);
    pstmt->execute();
    cout << "One row inserted." << endl;

    // MySQL Connector/C++ 정리
    delete pstmt;
    delete con;

    return 0;
}