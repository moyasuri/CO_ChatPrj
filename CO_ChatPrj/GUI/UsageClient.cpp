#include "UsageClient.h"
#include <sstream>
#include <msclr/marshal_cppstd.h>
std::string isTrue = "";
std::string svrMsg = "";
std::string frListPickup = "";
const std::string delim = " ";

const std::string trueStr = "true";
const std::string falseStr = "false";
const std::string elseStr = "else";
const char* __true = trueStr.c_str();
const char* __false = falseStr.c_str();




void DivStr(std::string& _Recv_str, std::string& _svrMsg)
{
	std::istringstream iss(_Recv_str);
	std::string token;
	int count = 0;

	
	while (iss >> token) {
		if (count == 0)
		{
			isTrue = token;
			count++;
			continue;
		}
		else if (count == 1)
		{
			_svrMsg = token;
			count++;
		}
		else
		{
			_svrMsg  = _svrMsg + delim + token ;
		}
	}

}

void clrisTrue()
{
	isTrue.clear();
}


void clrsvrMsg() 
{
	svrMsg.clear();
}


void IniMsg()
{
	clrisTrue();
	clrsvrMsg();
}

