#pragma comment(lib, "ws2_32.lib") //������� ���̺귯���� ��ũ. ���� ���̺귯�� ����

#include <WinSock2.h>
#include <string>
#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <mysql/jdbc.h>#include <mysql/jdbc.h>


#define MAX_SIZE 1024//���� �ڽ�ũ��
#define MAX_CLIENT 3

const string server = "tcp://127.0.0.1:3306"; // �����ͺ��̽� �ּ�
const string username = "codingon"; // �����ͺ��̽� �����
const string password = "1q2w3e4r5t"; // �����ͺ��̽� ���� ��й�ȣ

using std::cout;
using std::cin;
using std::endl;
using std::string;


std::vector<SOCKET_INFO> sck_list; // ����� Ŭ���̾�Ʈ ���ϵ��� ������ �迭 ����. ������ �׾Ƴ��� ����
SOCKET_INFO server_sock; // ���� ���Ͽ� ���� ������ ������ ���� ����.
int client_count = 0; // ���� ������ �ִ� Ŭ���̾�Ʈ�� count �� ���� ����.

//  recv_client + func_num �� ������ �����ϴ� �⺻ ������ ����

string recv_client(int idx) { // client�� ���� ���� ��� ���� �켱 ����
    char buf[MAX_SIZE] = { };
    string reading;
    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0)
            reading = buf;
    }        
    return reading;
}

int func_num(string reading) { //������ �������� ��ɺ��� �����ϱ� ���� buf�� �ִ� �� �޾ƿ��� ù ��° �Լ�
    string strfunc_menu;
     strfunc_menu = reading[0] + reading[1];
            
     if (strfunc_menu == "00")
         return 0;
     if (strfunc_menu == "01")
         return 1;
     if (strfunc_menu == "02")
         return 2;
     if (strfunc_menu == "03")
         return 3;
     if (strfunc_menu == "04")
         return 4;
     if (strfunc_menu == "05")
         return 5;
     if (strfunc_menu == "06")
         return 6;
     if (strfunc_menu == "07")
         return 7;
}

int main() {
    while (1) {
        int idx = 0;
        recv_client(idx);
        
    }

}

void recv_login(int func_num) {
        


}
       
void recv_msg(int idx, string read) {
    char buf[MAX_SIZE] = { }; //���۰� ä���� ������ �׳� �ӽ� �޸� ����
    string msg = "";

    //cout << sck_list[idx].user << endl;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // ������ �߻����� ������ recv�� ���ŵ� ����Ʈ ���� ��ȯ. 0���� ũ�ٴ� ���� �޽����� �Դٴ� ��.
            msg = sck_list[idx].user + " : " + buf; //Ŭ���̾�Ʈ���� ���� ������� ����Ǵ� ��
            cout << msg << endl;
            send_msg(msg.c_str());
        }
        else { //�׷��� ���� ��� ���忡 ���� ��ȣ�� �����Ͽ� ���� �޽��� ����
            msg = "[����] " + sck_list[idx].user + " ���� �����߽��ϴ�.";
            cout << msg << endl;
            send_msg(msg.c_str());
            del_client(idx); // Ŭ���̾�Ʈ ����
            return;
        }
    }
}

void recv_info(int idx) {
 
    char buf[MAX_SIZE] = { }; //���۰� ä���� ������ �׳� �ӽ� �޸� ����
    string msg = "";

    //cout << sck_list[idx].user << endl;

    while (1) {
        ZeroMemory(&buf, MAX_SIZE);
        if (recv(sck_list[idx].sck, buf, MAX_SIZE, 0) > 0) { // ������ �߻����� ������ recv�� ���ŵ� ����Ʈ ���� ��ȯ. 0���� ũ�ٴ� ���� �޽����� �Դٴ� ��.
        }
        
}

void send_msg(const char* msg) {
    for (int i = 0; i < client_count; i++) { // ������ �ִ� ��� client���� �޽��� ����
        send(sck_list[i].sck, msg, MAX_SIZE, 0);
    }
}

void del_client(int idx) {
    closesocket(sck_list[idx].sck);
    //sck_list.erase(sck_list.begin() + idx); // �迭���� Ŭ���̾�Ʈ�� �����ϰ� �� ��� index�� �޶����鼭 ��Ÿ�� ���� �߻�....��
    client_count--;
}


struct SOCKET_INFO { // ����� ���� ������ ���� Ʋ ����
    SOCKET sck;//�̰� �ڽ� ����
    string user;
};

SOCKET_INFO new_client = {};

void add_client() {
    SOCKADDR_IN addr = {};
    int addrsize = sizeof(addr);
    char buf[MAX_SIZE] = { };

    ZeroMemory(&addr, addrsize); // addr�� �޸� ������ 0���� �ʱ�ȭ

    SOCKET_INFO new_client_info = {};

    new_client_info.sck = accept(server_sock.sck, (sockaddr*)&addr, &addrsize);
    recv(new_client_info.sck, buf, MAX_SIZE, 0);
    // Winsock2�� recv �Լ�. client�� ���� �г����� ����.
    new_client_info.user = string(buf);
    // ��������� ����
    sck_list.push_back(new_client_info); // client ������ ��� sck_list �迭�� ���ο� client �߰�
    std::thread th(recv_msg, client_count);
    // �ٸ� �����κ��� ���� �޽����� ����ؼ� ���� �� �ִ� ���·� ����� �α�.

    th.join();//�̶����� ��¥ ���� ������ �����带 �غ��Ų�Ű� 
}