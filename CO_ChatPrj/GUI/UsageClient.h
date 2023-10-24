#pragma once
#include <string>

extern const std::string trueStr;
extern const std::string falseStr;
extern const std::string elseStr;
extern std::string isTrue;
extern std::string svrMsg;
extern const char* __true;
extern const char* __false;
extern const std::string delim;
extern std::string frListPickup;

void clrisTrue(); // true false 초기화
void clrsvrMsg(); // contents 초기화
void IniMsg(); 
void DivStr(std::string& _Recv_str, std::string& _svrMsg);
void DivStrMsg(std::string& _Recv_str, std::string& _svrMsg);



enum SignUp
{
    e_signup_IDchk = 11,
    e_signup_NickNamechk,
    e_signup_Submit,
};


enum ID
{
    e_id_try_Signin = 21,
    e_id_find_ID,
    e_id_find_PW,

};

enum EditInfo
{
    e_edit_PWchk = 31,
    e_edit_NickNamechk,
    e_edit_Confirm,

};


enum ShortMessage
{
    e_message_List = 410,
    e_message_Read,
    e_message_Send,
    e_message_Delete,
    e_message_Sent_list,
    e_message_Sent_msg,
    e_message_Sent_msg_delete,
    e_message_UGiven_list,
    e_message_UGiven_msg,
    e_message_UGiven_msg_delete,
    e_message_UGiven_Read,
    e_message_RGiven_list,
    e_message_RGiven_msg,
    e_message_RGiven_msg_delete,
    



};

enum Friends
{

    e_friends_List = 510,
    e_friends_Delete , 
    e_friends_search , 
    e_friends_Request_Send ,
    e_friends_Request_List ,
    e_friends_Request_Accept,
    e_friends_Request_Decline,
    e_friends_Request,
    e_friends_Response_List,
    e_friends_Accept,
    

};




enum Imoji
{
     e_imoji_k = 61,
     e_imoji_kk,
     e_imoji_kkk,



};

enum Character
{
    e_character_izuna = 71,
    e_character_alice,
};


enum RoomList
{
    e_room_Create = 60,
    e_room_Exit,
    e_room_Enter,
    e_room_Delete,
    e_room_List,
    e_room_myList,
    e_room_Chat,
    e_room_show_whole_Text
};

