#pragma once
#include <string>

class UserInfo {
public:
    // Getter 함수
    std::string getName() const {
        return name;
    }

    std::string getID() const {
        return id;
    }

    std::string getPW() const {
        return pw;
    }

    std::string getPhone() const {
        return phone;
    }

    std::string getBirth() const {
        return birth;
    }

    std::string getNickName() const {
        return nickName;
    }

    int getChaNum() const {
        return chaNum;
    }

    std::string getJoinRoomIndex() const {
        return joinRoomIndex;
    }

    std::string getEmail() const {
        return email;
    }


    // Setter 함수
    void setName(const std::string& newName) {
        name = newName;
    }

    void setID(const std::string& newID) {
        id = newID;
    }

    void setPW(const std::string& newPW) {
        pw = newPW;
    }

    void setPhone(const std::string& newPhone) {
        phone = newPhone;
    }

    void setBirth(const std::string& newBirth) {
        birth = newBirth;
    }

    void setNickName(const std::string& newNickName) {
        nickName = newNickName;
    }

    void setChaNum(const int& newChaNum) {
        chaNum = newChaNum;
    }

    void setJoinRoomIndex(const std::string& newJoinRoomIndex) {
        joinRoomIndex = newJoinRoomIndex;
    }
    void setEmail(const std::string& newEmail) {
        email = newEmail;
    }

private:
    std::string name;
    std::string id;
    std::string pw;
    std::string phone;
    std::string birth;
    std::string nickName;
    int chaNum;
    std::string joinRoomIndex;
    std::string email;
};