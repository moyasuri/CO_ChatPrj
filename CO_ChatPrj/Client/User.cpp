#include <iostream>
#include <vector>

using namespace std;



class User {

	string getMember_ID() {
		return member_ID;
	}
	string getEmail() {
		return email;
	}
	string getPhone() {
		return phone;
	}
	 string getBirth() {
		return birth;
	}
	string getNickname() {
		return nickname;
	}
	string getCha_num() {
		return member_ID;
	}
	string getMember_PW() {
		return member_ID;
	}
	string getJoin_room_index() {
		return member_ID;
	}

	string setMember_ID(string member_ID) {
		this->member_ID = member_ID;
	}
	string setEmail(string email) {
		this->email = email;
	}
	string setPhone(string phone) {
		this->phone = phone;
	}
	string setBirth(string birth) {
		this->birth = birth;
	}
	string setNickname(string nickname) {
		this->nickname = nickname;
	}
	string setCha_num(string cha_num) {
		this->cha_num = cha_num;
	}
	string setMember_PW(string pw) {
		this->member_PW = member_PW;
	}
	string setJoin_room_index(string join_room_index) {
		this->join_room_index = join_room_index;
	}

private:
	string member_ID="";
	string email="";
	string phone="";
	string birth="";
	string nickname="";
	string cha_num="";
	string member_PW="";
	string join_room_index="";



};

