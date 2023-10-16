#include <iostream>
#include <string>
#include <vector>
#include <mysql/jdbc.h>
using namespace std;

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호



vector <string> mainHome_menu = { "1. 회원가입","2. 로그인","3. 종료" };
int inputMainHome_menu = 0;
int inputLogin_menu = 0;
string newid;
string inputId;
int yes_no;





int main() {
	// MySQL Connector/C++ 초기화
	sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;

	// 데이터베이스 선택
	con->setSchema("chat");
	sql::Connection* con;
	sql::Statement* stmt;

	// db 한글 저장을 위한 셋팅 
	stmt = con->createStatement();
	stmt->execute("set names euckr");
	if (stmt) { delete stmt; stmt = nullptr; }


	while (1) {
		cout << "메뉴를 선택하세요. " << endl; //우선 버튼 누르거나 받아주는 값이 없어서 입력하는 거로 받아줌
		cin >> inputMainHome_menu;


		if (inputMainHome_menu == 1 || inputMainHome_menu == 2 || inputMainHome_menu == 3)
		{
			cout << "잘못 입력하셨습니다. ";
			continue;
		}
		//	#1
		else if (inputMainHome_menu == 1)
		{
			//회원가입 db로 저장
		}

		//	#2
		else if (inputMainHome_menu == 2)
		{
			//로그인 메뉴로 감
			cin >> inputId;

			//mysql member테이블에서 member_Id 벡터에 받아오기
			find

		}
		//	#3
		else if (inputMainHome_menu == 3)
		{
			cin >> yes_no;
			if (yes_no == 0) // 아니오
				continue;
			else if (yes_no == 1)
				break;
		}
		//여기까지 main_Home


			//login_menu
		while (1) {
			cout << "메뉴를 선택하세요. " << endl; //우선 버튼 누르거나 받아주는 값이 없어서 입력하는 거로 받아줌
			cin >> inputLogin_menu;
			//2-1
			//db에서 기존 id_pw 쌍 가져와야됨
			cout << "ID를 입력하세요. " << endl;
			cin >> inputId;



		}

	}
}