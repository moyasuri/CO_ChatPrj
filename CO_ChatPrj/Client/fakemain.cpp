#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int mainHome_num = 0;
	int mainLogin_num = 0;
	while (1) //정말 큰 mainHOME
	{
		cout << "메인 화면 메뉴 골라"<< endl;
		cin >> mainHome_num;
		while (mainHome_num == 1) {
			//회원가입
		}

		while (mainHome_num == 2) {
			//로그인
			//if 로그인 성공 쭉쭉 내려가
			//if 로그인 실패 continue;
			
			//로그인 했을 때 홈
			while (1) {
				cout << "로그인 성공 후 화면 메뉴 골라" << endl;
				cin >> mainLogin_num;

				while (mainLogin_num =1 ) 
				{
					break;
				}
				continue;
				while (mainLogin_num =2 ) 
				{
					break;
				}
				continue;
				while (mainLogin_num =3 ) 
				{
					break;
				}
				continue;
				while (mainLogin_num =4 ) 
				{
					break;
				}
				continue;
				while (mainLogin_num = 5)
				{
					break;

				}
				break;
			}
			
			continue;

		}

		while (mainHome_num == 3) {
			//종료
		}
	}

}