/*�޸�:
_getch�Լ��� �Է� ��ư Ȱ��ȭ ��ų �� ���� �� ����
*/

#include <iostream>
#include <vector>
#include <mysql/jdbc.h>
#include <windows.h>

using namespace std;

const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ




class ManageUser {
	sql::mysql::MySQL_Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;
	std::string strQuery = "select * from member";
	const char *Query = strQuery.c_str();


	
	
	void isSetID()
	{

		string id;
		while {
			cout << "����Ͻ� ID�� �Է����ּ���. :" << endl;
			cin >> id;
			if (id) // �������� ������ �� �߿� ������
			{
				cout << "�̹� �ִ� ID �Դϴ�.";
				continue;
			}
			else if (id) // ������ �ƴ� ���
			{
				cout << " ID�� ���� �ҹ��ڷθ� �̷���� �� �ֽ��ϴ�. �ٽ� �õ����ּ���." << endl;
				continue;
			}
			else
				//������ �����ϱ�
		}
	
	}

	isSetPW() //��ȣȭ �۾�
	{
		string pw;
		string pw_check;
		while {
			cout << "����Ͻ� pw�� �Է����ּ���. :" << endl;
			cin >> pw;
			if (size(pw)<10)// 10�� �̻�, ��������
			{
				size(pw)
				cout << "�̹� �ִ� ID �Դϴ�.";
				continue;
			}
			else if (id) // ������ �ƴ� ���
			{
				cout << " ID�� ���� �ҹ��ڷθ� �̷���� �� �ֽ��ϴ�. �ٽ� �õ����ּ���." << endl;
				continue;
			}
			else
				//������ �����ϱ�
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