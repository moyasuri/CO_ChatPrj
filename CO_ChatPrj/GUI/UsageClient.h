#pragma once
#include <string>



struct Ans
{
    std::string res;  
    std::string res_r;

    void ansToeEnum(int _enum)
    {

        this->res = std::to_string(_enum) + " " + "true";
        this->res_r = std::to_string(_enum) + " " + "false";
    };
    
};

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
