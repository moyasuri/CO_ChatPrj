#pragma once


#include <WinSock2.h>
#include <string>
#include "UserInfo.h"

using std::string;

struct SOCKET_INFO { // 연결된 소켓 정보에 대한 틀 생성
    SOCKET sck;
    string user;
    UserInfo _user;
};