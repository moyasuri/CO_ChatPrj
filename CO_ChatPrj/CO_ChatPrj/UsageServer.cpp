#include "UsageServer.h"
#include <string>


std::string isTrue = "";
std::string svrMsg = "";
std::string sqlMsg = "";

const std::string trueStr = "true";
const std::string falseStr = "false";
const std::string elseStr = "else";
const char* __true = trueStr.c_str();
const char* __false = falseStr.c_str();
bool multimsg = false;

std::string _id_from = "", _nick_from = "", _msg = "";
std::string _id_temp = "", _msg_temp = "", result = "";

const char nullChar = '\0';

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

void IniMsg()
{
	clrisTrue();
	clrsvrMsg();
	clrsqlMsg();
}