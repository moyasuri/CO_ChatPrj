#include <iostream>
#include <string>
#include <vector>
#include <mysql/jdbc.h>
using namespace std;

const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ



vector <string> mainHome_menu = { "1. ȸ������","2. �α���","3. ����" };
int inputMainHome_menu = 0;
int inputLogin_menu = 0;
string newid;
string inputId;
int yes_no;





int main() {
	// MySQL Connector/C++ �ʱ�ȭ
	sql::mysql::MySQL_Driver* driver; // ���� �������� �ʾƵ� Connector/C++�� �ڵ����� ������ ��
	sql::Connection* con;
	sql::Statement* stmt;
	sql::PreparedStatement* pstmt;

	// �����ͺ��̽� ����
	con->setSchema("chat");
	sql::Connection* con;
	sql::Statement* stmt;

	// db �ѱ� ������ ���� ���� 
	stmt = con->createStatement();
	stmt->execute("set names euckr");
	if (stmt) { delete stmt; stmt = nullptr; }


	while (1) {
		cout << "�޴��� �����ϼ���. " << endl; //�켱 ��ư �����ų� �޾��ִ� ���� ��� �Է��ϴ� �ŷ� �޾���
		cin >> inputMainHome_menu;


		if (inputMainHome_menu == 1 || inputMainHome_menu == 2 || inputMainHome_menu == 3)
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. ";
			continue;
		}
		//	#1
		else if (inputMainHome_menu == 1)
		{
			//ȸ������ db�� ����
		}

		//	#2
		else if (inputMainHome_menu == 2)
		{
			//�α��� �޴��� ��
			cin >> inputId;

			//mysql member���̺��� member_Id ���Ϳ� �޾ƿ���
			find

		}
		//	#3
		else if (inputMainHome_menu == 3)
		{
			cin >> yes_no;
			if (yes_no == 0) // �ƴϿ�
				continue;
			else if (yes_no == 1)
				break;
		}
		//������� main_Home


			//login_menu
		while (1) {
			cout << "�޴��� �����ϼ���. " << endl; //�켱 ��ư �����ų� �޾��ִ� ���� ��� �Է��ϴ� �ŷ� �޾���
			cin >> inputLogin_menu;
			//2-1
			//db���� ���� id_pw �� �����;ߵ�
			cout << "ID�� �Է��ϼ���. " << endl;
			cin >> inputId;



		}

	}
}