#pragma once
#include "SignUp.h"

#include <WinSock2.h> //Winsock 헤더파일 include. WSADATA 들어있음.
#include <WS2tcpip.h>
#include <string>
#include <sstream>
#include <iostream>
#include <thread>
#include <msclr/marshal_cppstd.h>

#define MAX_SIZE 1024



namespace GUI {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	SOCKET client_sock;
	string my_nick;



	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{


	private: System::Windows::Forms::TextBox^ textBox; // 텍스트 상자를 멤버 변수로 추가
	private: System::Windows::Forms::TextBox^ textBox2; // 텍스트 상자를 멤버 변수로 추가
	private: System::Windows::Forms::Form^ newForm;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
						// sound 추가해보기
			SoundPlayer^ sound = gcnew SoundPlayer;
			sound->SoundLocation = "C:\\Data\\02.Code\\CO_ChatPrj\\CO_ChatPrj\\Media\\shootingstar.wav";
			sound->Load();
			sound->Play();









		}
	private:
		int chat_recv(void) {
			char buf[MAX_SIZE] = { };
			string msg;

			while (1) {
				ZeroMemory(&buf, MAX_SIZE);
				if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {
					msg = buf;
					std::stringstream ss(msg);  // 문자열을 스트림화
					string user;
					ss >> user; // 스트림을 통해, 문자열을 공백 분리해 변수에 할당. 보낸 사람의 이름만 user에 저장됨.
					if (user != my_nick) cout << buf << endl; // 내가 보낸 게 아닐 경우에만 출력하도록.
				}
				else {
					cout << "Server Off" << endl;
					return -1;
				}
			}
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;



	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ btn_signup;
	private: System::Windows::Forms::Button^ button3;







	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btn_signup = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 24));
			this->label1->Location = System::Drawing::Point(101, 488);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->button1->Location = System::Drawing::Point(527, 527);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(171, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Sign in";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label2->Location = System::Drawing::Point(272, 500);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(272, 567);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::MintCream;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(277, 535);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(201, 23);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::MintCream;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(277, 601);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(201, 23);
			this->textBox2->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->button2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->button2->Location = System::Drawing::Point(527, 592);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(171, 41);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btn_signup
			// 
			this->btn_signup->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btn_signup->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btn_signup->Location = System::Drawing::Point(888, 529);
			this->btn_signup->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_signup->Name = L"btn_signup";
			this->btn_signup->Size = System::Drawing::Size(171, 41);
			this->btn_signup->TabIndex = 12;
			this->btn_signup->Text = L"Sign up";
			this->btn_signup->UseVisualStyleBackColor = true;
			this->btn_signup->Click += gcnew System::EventHandler(this, &MyForm::btn_signup_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(550, 218);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(338, 112);
			this->button3->TabIndex = 13;
			this->button3->Text = L"test";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1109, 646);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btn_signup);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btn_signup_Click(System::Object^ sender, System::EventArgs^ e) {
		SignUp^ signupForm = gcnew SignUp;
		signupForm->Show();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}





	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		


		// 새로운 폼 생성
		newForm = gcnew Form();
		newForm->Text = "새로운 폼";

		// 텍스트 상자 생성 및 초기화
		textBox = gcnew System::Windows::Forms::TextBox();
		textBox->Location = System::Drawing::Point(10, 10);
		textBox->Size = System::Drawing::Size(200, 20);
		newForm->Controls->Add(textBox);

		// 확인 버튼 생성
		Button^ confirmButton = gcnew Button();
		confirmButton->Location = System::Drawing::Point(10, 40);
		confirmButton->Size = System::Drawing::Size(75, 23);
		confirmButton->Text = "확인";
		confirmButton->Click += gcnew System::EventHandler(this, &MyForm::confirmButton_Click);
		newForm->Controls->Add(confirmButton);

		// 새로운 폼을 표시
		newForm->Show();




		WSADATA wsa;



		// Winsock를 초기화하는 함수. MAKEWORD(2, 2)는 Winsock의 2.2 버전을 사용하겠다는 의미.
		// 실행에 성공하면 0을, 실패하면 그 이외의 값을 반환.
		// 0을 반환했다는 것은 Winsock을 사용할 준비가 되었다는 의미.
		int code = WSAStartup(MAKEWORD(2, 2), &wsa);
		if (!code) {




			//cout << "사용할 닉네임 입력 >> ";
			//cin >> my_nick;

			// PF_INET : 프로토콜 familiy IPv4 인터넷 프로토콜을 사용
			// SOCK_STREAM: 소켓 유형(socket type)을 나타냅니다. 
			// SOCK_STREAM은 TCP(Transmission Control Protocol) 기반의 연결 지향형 소켓을 생성함을 의미합니다.
			// TCP는 신뢰성 있는 데이터 전송을 제공하며, 연결 지향형으로 동작하여 데이터가 순서대로 전달됩니다.
			// IPPROTO_TCP: 프로토콜(protocol)을 나타냅니다. IPPROTO_TCP는 TCP 프로토콜을 사용함을 의미합니다.
			client_sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // 

			// 연결할 서버 정보 설정 부분
			SOCKADDR_IN client_addr = {};
			client_addr.sin_family = AF_INET;
			client_addr.sin_port = htons(7777);
			InetPton(AF_INET, TEXT("192.168.0.6"), &client_addr.sin_addr);

			// AF_INTE 과 PF_INET은 정확히 동일한 의미

			while (1) {
				if (!connect(client_sock, (SOCKADDR*)&client_addr, sizeof(client_addr))) { // 위에 설정한 정보에 해당하는 server로 연결!
					cout << "Server Connect" << endl;
					send(client_sock, my_nick.c_str(), my_nick.length(), 0); // 연결에 성공하면 client 가 입력한 닉네임을 서버로 전송
					break;
				}
				cout << "Connecting..." << endl;
			}

			//thread th2(chat_recv);

			while (1) {
				string text;
				std::getline(cin, text);
				const char* buffer = text.c_str(); // string형을 char* 타입으로 변환
				send(client_sock, buffer, strlen(buffer), 0);
			}
			//th2.join();
			closesocket(client_sock);
		}

		WSACleanup();


	}

	private: System::Void confirmButton_Click(System::Object^ sender, System::EventArgs^ e) {


		String^ inputText = textBox->Text;
		// 이곳에서 inputText를 사용하거나 저장할 수 있습니다.

		// 새로운 폼 종료
		newForm->Close();
	}
	};
}
