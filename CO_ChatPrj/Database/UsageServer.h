#pragma once
//#include <string>
//using std::string;
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
    e_message_List = 41,
    e_message_Read,
    e_message_Send,
    e_message_Delete,

};

enum Friends
{
    e_friends_Request= 51,
    e_friends_List,
    e_friends_Delete,
    e_friends_Response_List,
    e_friends_Accept,
    
};
