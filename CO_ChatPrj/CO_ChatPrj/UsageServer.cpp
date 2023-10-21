#include "UsageServer.h"
#include <string>


std::string isTrue = "";
std::string svrMsg = "";
std::string sqlMsg = "";

const std::string trueStr = "true";
const std::string falseStr = "false";
const char* __true = trueStr.c_str();
const char* __false = falseStr.c_str();



void clrisTrue()
{
	isTrue.clear();
}


void clrsvrMsg()
{

	svrMsg.clear();
}

void clrsqlMsg()
{

	sqlMsg.clear();
}