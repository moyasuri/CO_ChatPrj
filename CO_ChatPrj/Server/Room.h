#pragma once
#include <string>

class Room {
public:
	void room_init() {
	}
	int getRoom_Index() const {
		return Room_Index;
	}
	int getRoom_Type() const {
		return Room_Type;
	}
	std::string getRoom_Title() const {
		return Room_Title;
	}
	std::string getRoom_Master() const {
		return Room_Master;
	}
	std::string getRoom_Date() const {
		return Room_Date;
	}
	std::string getRoom_PW() const {
		return Room_PW;
	}

	void setRoom_Index(const int& Room_Index) {
		this->Room_Index = Room_Index;
	}
	void setRoom_Type(const int& Room_Type) {
		this->Room_Type = Room_Type;
	}
	void setRoom_Title(const std::string& Room_Title) {
		this->Room_Master = Room_Title;
	}
	void setRoom_Master(const std::string& Room_Master) {
		this->Room_Master = Room_Master;
	}
	void setRoom_Date(const std::string& Room_Date) {
		this->Room_Date = Room_Date;
	}

	void setRoom_PW(const std::string& Room_PW)
	{
		this->Room_PW = Room_PW;
	}







private:
	int Room_Index;
	int Room_Type;
	std::string Room_Title;
	std::string Room_Master;
	std::string Room_Date;
	std::string Room_PW;
	
};