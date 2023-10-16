/*메모:
_getch함수로 입력 버튼 활성화 시킬 수 있을 것 같다
*/

#include <iostream>
#include <vector>
#include <mysql/jdbc.h>
#include <windows.h>

using namespace std;

const string server = "tcp://127.0.0.1:3306"; // 데이터베이스 주소
const string username = "codingon"; // 데이터베이스 사용자
const string password = "1q2w3e4r5t"; // 데이터베이스 접속 비밀번호




class ManageUser {
	sql::mysql::MySQL_Driver* driver; // 추후 해제하지 않아도 Connector/C++가 자동으로 해제해 줌
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	std::string strQuery = "select * from member";
	const char *Query = strQuery.c_str();


	
	
	void isSetID()
	{

		string id;
		while {
			cout << "사용하실 ID를 입력해주세요. :" << endl;
			cin >> id;
			if (id) // 쿼리에서 가져온 값 중에 있으면
			{
				cout << "이미 있는 ID 입니다.";
				continue;
			}
			else if (id) // 영문이 아닐 경우
			{
				cout << " ID는 영어 소문자로만 이루어질 수 있습니다. 다시 시도해주세요." << endl;
				continue;
			}
			else
				//쿼리에 저장하기
		}
	
	}

	isSetPW() //암호화 작업
	{
		string pw;
		string pw_check;
		while {
			cout << "사용하실 pw를 입력해주세요. :" << endl;
			cin >> pw;
			if (size(pw)<10)// 10자 이상, 숫자포함
			{
				size(pw)
				cout << "이미 있는 ID 입니다.";
				continue;
			}
			else if (id) // 영문이 아닐 경우
			{
				cout << " ID는 영어 소문자로만 이루어질 수 있습니다. 다시 시도해주세요." << endl;
				continue;
			}
			else
				//쿼리에 저장하기
		}
	}
	isSetBirth() {}
	isSetEmail() {}
	isSetName(){}
	isSetPhone() {	}
	isSetNickname(){}
	isSetChar() {}
	isFindID() {}
	isLogin() {}
	isCreateAccount() {}
	isEditAccount() {}

};