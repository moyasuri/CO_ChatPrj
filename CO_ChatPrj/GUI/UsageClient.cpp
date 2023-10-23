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


void DivStrMsg(std::string& _Recv_str, std::string& _svrMsg)
{
	std::istringstream iss(_Recv_str);
	std::string line;
	std::string result;
	iss >> isTrue;


	while (std::getline(iss, line)) {
		_svrMsg += line + '\n'; // 개행 문자를 유지한 채로 추가
	}


	//개행 문자 재삽입:

	// 문자열을 분할할 때 개행 문자를 유지하기 어렵거나 개행 문자가 이미 제거된 경우, 데이터를 사용하기 전에 _svrMsg에 개행 문자를 다시 추가할 수 있습니다.
	//개행 문자가 유지되도록 적절한 방법을 선택하여 코드를 수정하면 됩니다.

	//while (std::getline(iss, token)) {
	//	if (count == 0) {
	//		isTrue = token;
	//		count++;
	//		continue;
	//	}
	//	else {
	//		if (!_svrMsg.empty()) {
	//			_svrMsg += '\n';  // 개행 문자 추가
	//		}
	//		_svrMsg += token;
	//	}
	//}
	//

}



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

