#pragma once
//#include <string>
//using std::string;
enum SignUp
{
    e_signup_IDchk = 11,
    e_signup_NickNamechk=12,
    e_signup_Submit=13,
};


enum ID
{
    e_id_try_Signin = 21,
    e_id_find_ID = 22,
    e_id_find_PW= 23,

};

enum EditInfo
{
    e_edit_PWchk = 31,
    e_edit_NickNamechk= 32,
    e_edit_Confirm=33
    
};


enum ShortMessage
{
    e_message_unread_List = 41,
    e_message_read_List=42,
    e_message_unread_Delete=43,
    e_message_read_Delete = 44,
    e_message_Read= 45,
    e_message_Send= 46,
    e_message_Delete
    

};

enum Friends
{
    
    e_friends_List= 510,
    e_friends_Delete,
    // 검색 따로 아니고 있으면 바로 보내기
    e_friends_Request,
    e_friends_Request_List,
    e_friends_Request_Accept,
    e_friends_Request_Decline,
    

};

enum RoomList
{
    e_room_Create = 60,
    e_room_Exit,
    e_room_Enter,
    e_room_Delete,
    e_room_List,
    e_room_myList
};

enum Character
{
    e_character_izuna = 71,
    e_character_alice,
};