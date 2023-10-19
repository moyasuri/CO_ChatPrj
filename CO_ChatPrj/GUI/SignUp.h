#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
#include "UsageClient.h"
extern SOCKET client_sock;
extern std::string Recv_str;


namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SignUp에 대한 요약입니다.
	/// </summary>
	public ref class SignUp : public System::Windows::Forms::Form
	{
	private: System::String^ relativePath;
	private: System::String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
	private:
		bool isChkIDDup = false;
		bool isChkNickNameDup = false;

	public:
		SignUp(void)
		{

			InitializeComponent();


	
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Scenario_Mode_Bg.png");
			this->BackgroundImage = Image::FromFile(relativePath);
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~SignUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxID;
	protected:

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBoxPW;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBoxRechk;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtBoxNickName;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtBoxPhone;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtBoxBirth;

	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ btnNickNameduplicateChk;


	private: System::Windows::Forms::Button^ btnIDduplicateChk;
	private: System::Windows::Forms::ComboBox^ combBoxCha;



	private: System::Windows::Forms::Button^ btnSubmit;
	private: System::Windows::Forms::Button^ btnCancle;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtBoxEmail;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txtBoxName;



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
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtBoxRechk = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtBoxNickName = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtBoxBirth = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->btnNickNameduplicateChk = (gcnew System::Windows::Forms::Button());
			this->btnIDduplicateChk = (gcnew System::Windows::Forms::Button());
			this->combBoxCha = (gcnew System::Windows::Forms::ComboBox());
			this->btnSubmit = (gcnew System::Windows::Forms::Button());
			this->btnCancle = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtBoxName = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// txtBoxID
			// 
			this->txtBoxID->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxID->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxID->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxID->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxID->Location = System::Drawing::Point(128, 174);
			this->txtBoxID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(244, 32);
			this->txtBoxID->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label1->Location = System::Drawing::Point(121, 127);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 32);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label2->Location = System::Drawing::Point(121, 230);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 32);
			this->label2->TabIndex = 4;
			this->label2->Text = L"PW";
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPW->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW->Location = System::Drawing::Point(128, 281);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(244, 32);
			this->txtBoxPW->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(441, 239);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 29);
			this->label3->TabIndex = 6;
			this->label3->Text = L"re-check";
			// 
			// txtBoxRechk
			// 
			this->txtBoxRechk->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxRechk->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxRechk->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxRechk->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxRechk->Location = System::Drawing::Point(445, 281);
			this->txtBoxRechk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxRechk->Name = L"txtBoxRechk";
			this->txtBoxRechk->PasswordChar = '*';
			this->txtBoxRechk->Size = System::Drawing::Size(244, 32);
			this->txtBoxRechk->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label4->Location = System::Drawing::Point(121, 335);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 32);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Nick Name";
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxNickName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxNickName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxNickName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxNickName->Location = System::Drawing::Point(128, 390);
			this->txtBoxNickName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(244, 32);
			this->txtBoxNickName->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label5->Location = System::Drawing::Point(121, 534);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 32);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Phone";
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(128, 582);
			this->txtBoxPhone->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(244, 32);
			this->txtBoxPhone->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label6->Location = System::Drawing::Point(121, 438);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(78, 32);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Birth";
			// 
			// txtBoxBirth
			// 
			this->txtBoxBirth->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxBirth->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxBirth->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxBirth->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxBirth->Location = System::Drawing::Point(128, 492);
			this->txtBoxBirth->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxBirth->Name = L"txtBoxBirth";
			this->txtBoxBirth->Size = System::Drawing::Size(244, 32);
			this->txtBoxBirth->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label7->Location = System::Drawing::Point(425, 534);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(136, 32);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Character";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label8->Location = System::Drawing::Point(179, 239);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(177, 24);
			this->label8->TabIndex = 15;
			this->label8->Text = L"(Max 16Character)";
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(414, 389);
			this->btnNickNameduplicateChk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(162, 35);
			this->btnNickNameduplicateChk->TabIndex = 16;
			this->btnNickNameduplicateChk->Text = L"Duplicate Check";
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = true;
			this->btnNickNameduplicateChk->Click += gcnew System::EventHandler(this, &SignUp::btnNickNameduplicateChk_Click);
			// 
			// btnIDduplicateChk
			// 
			this->btnIDduplicateChk->Location = System::Drawing::Point(414, 173);
			this->btnIDduplicateChk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnIDduplicateChk->Name = L"btnIDduplicateChk";
			this->btnIDduplicateChk->Size = System::Drawing::Size(162, 35);
			this->btnIDduplicateChk->TabIndex = 17;
			this->btnIDduplicateChk->Text = L"Duplicate Check";
			this->btnIDduplicateChk->UseVisualStyleBackColor = true;
			this->btnIDduplicateChk->Click += gcnew System::EventHandler(this, &SignUp::btnIDduplicateChk_Click);
			// 
			// combBoxCha
			// 
			this->combBoxCha->FormattingEnabled = true;
			this->combBoxCha->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"이즈나", L"아리스" });
			this->combBoxCha->Location = System::Drawing::Point(431, 582);
			this->combBoxCha->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->combBoxCha->Name = L"combBoxCha";
			this->combBoxCha->Size = System::Drawing::Size(240, 26);
			this->combBoxCha->TabIndex = 18;
			// 
			// btnSubmit
			// 
			this->btnSubmit->BackColor = System::Drawing::Color::Cornsilk;
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->btnSubmit->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->btnSubmit->Location = System::Drawing::Point(305, 652);
			this->btnSubmit->Margin = System::Windows::Forms::Padding(4);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(182, 67);
			this->btnSubmit->TabIndex = 19;
			this->btnSubmit->Text = L"Submit";
			this->btnSubmit->UseVisualStyleBackColor = false;
			this->btnSubmit->Click += gcnew System::EventHandler(this, &SignUp::btnSubmit_Click);
			// 
			// btnCancle
			// 
			this->btnCancle->BackColor = System::Drawing::Color::Cornsilk;
			this->btnCancle->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->btnCancle->ForeColor = System::Drawing::Color::Firebrick;
			this->btnCancle->Location = System::Drawing::Point(520, 652);
			this->btnCancle->Margin = System::Windows::Forms::Padding(4);
			this->btnCancle->Name = L"btnCancle";
			this->btnCancle->Size = System::Drawing::Size(182, 67);
			this->btnCancle->TabIndex = 20;
			this->btnCancle->Text = L"Cancle";
			this->btnCancle->UseVisualStyleBackColor = false;
			this->btnCancle->Click += gcnew System::EventHandler(this, &SignUp::btnCancle_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label9->Location = System::Drawing::Point(425, 437);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(97, 32);
			this->label9->TabIndex = 22;
			this->label9->Text = L"E-mail";
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(431, 491);
			this->txtBoxEmail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(244, 32);
			this->txtBoxEmail->TabIndex = 21;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label10->Location = System::Drawing::Point(121, 36);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 32);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Name";
			// 
			// txtBoxName
			// 
			this->txtBoxName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxName->Location = System::Drawing::Point(128, 84);
			this->txtBoxName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(244, 32);
			this->txtBoxName->TabIndex = 23;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(760, 760);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->txtBoxName);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->btnCancle);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->combBoxCha);
			this->Controls->Add(this->btnIDduplicateChk);
			this->Controls->Add(this->btnNickNameduplicateChk);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtBoxBirth);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtBoxPhone);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtBoxNickName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtBoxRechk);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxID);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		// btnsubmit  회원가입 실행버튼
		// 전화번호가 겹치거나 공백란이 있다면 오류를 반환
		private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
		////테두리 없애기
		btnSubmit->NotifyDefault(false);

		if (!isChkIDDup)
		{
			System::Windows::Forms::MessageBox::Show("ID 중복체크를 해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		if (!isChkNickNameDup)
		{
			System::Windows::Forms::MessageBox::Show("NickName 중복체크를 해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (txtBoxPW->Text != txtBoxRechk->Text)
		{
			
			System::Windows::Forms::MessageBox::Show("PW가 일치하지 않습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}


		// 텍스트 상자에서 텍스트 가져오기
		//txtBoxName->Text;
		//txtBoxID->Text;
		//txtBoxPW->Text;
		//txtBoxNickName->Text;
		//txtBoxBirth->Text;
		//txtBoxEmail->Text;
		//Name ID PW NickName Birth E-mail Phone Cha 다 줘야돼


		// 텍스트 상자에서 텍스트 가져오기
		String^ tmptxt_1 = txtBoxName->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ tmptxt_2 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ tmptxt_3 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ tmptxt_4 = txtBoxNickName->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ tmptxt_5 = txtBoxBirth->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ tmptxt_6 = txtBoxEmail->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ tmptxt_7 = txtBoxPhone->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ tmptxt_8 = combBoxCha->Text; // textBox는 해당 텍스트 상자의 이름입니다.





		// ID와 PW의 문자열이 채워져있다면
		if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2) && !String::IsNullOrEmpty(tmptxt_2)\
			&& !String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_4) && !String::IsNullOrEmpty(tmptxt_5)\
			&& !String::IsNullOrEmpty(tmptxt_6) && !String::IsNullOrEmpty(tmptxt_7) && !String::IsNullOrEmpty(tmptxt_8)) {
			
			//// Server에 ID / PW를 보내기함수
			int time_limit = 0;

			std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
			std::string tmptxt_2_ = msclr::interop::marshal_as<std::string>(tmptxt_2);
			std::string tmptxt_3_ = msclr::interop::marshal_as<std::string>(tmptxt_3);
			std::string tmptxt_4_ = msclr::interop::marshal_as<std::string>(tmptxt_4);
			std::string tmptxt_5_ = msclr::interop::marshal_as<std::string>(tmptxt_5);
			std::string tmptxt_6_ = msclr::interop::marshal_as<std::string>(tmptxt_6);
			std::string tmptxt_7_ = msclr::interop::marshal_as<std::string>(tmptxt_7);
			std::string tmptxt_8_ = msclr::interop::marshal_as<std::string>(tmptxt_8);

			std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_signup_Submit));

			std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_ + " " + tmptxt_2_ + " " + tmptxt_3_ + " " + tmptxt_4_\
				+ " " + tmptxt_5_ + " " + tmptxt_6_ + " " + tmptxt_7_ + " " + tmptxt_8_ ;
			const char* buffer = _Index_Str_Result.c_str();
			send(client_sock, buffer, strlen(buffer), 0);
			
			while (1)
			{
				if (Recv_str == "true")// server 에서 오케이받는 함수
				{
					System::Windows::Forms::MessageBox::Show("회원가입 완료", "회원가입", MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				else if (Recv_str == "false") //  server에서 다른값보내면
				{
					System::Windows::Forms::MessageBox::Show("email 또는 전화번호가 이미 있습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

						return;
				}
				else // 무한반복되는건데 시간타이밍 주면 좋을거같음
				{
					Sleep(1000);
					if (time_limit > 1)
					{
						System::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					else
					{
						time_limit++;
					}
				}
			}
		}
		// 입력값이 없다면,
		else {
			System::Windows::Forms::MessageBox::Show("정보를 입력해주세요. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}


	}

		   // ID 중복 확인하기버튼
	private: System::Void btnIDduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//테두리 없애기
		btnIDduplicateChk->NotifyDefault(false);

		// 텍스트 상자에서 텍스트 가져오기
		String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		

		// ID와 PW의 문자열이 채워져있다면
		if (!String::IsNullOrEmpty(tmptxt_1)) {



			// Server에 ID / PW를 보내기함수
			int time_limit = 0;

			std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
			std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_signup_IDchk));
			std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
			const char* buffer = _Index_Str_Result.c_str();
			send(client_sock, buffer, strlen(buffer), 0);


			while (1)
			{
				if (Recv_str == "true")// server 에서 오케이받는 함수
				{

					isChkIDDup = true;
					txtBoxID->Enabled = false;
					return;
				}
				else if (Recv_str == "false") //  server에서 다른값보내면
				{
					System::Windows::Forms::MessageBox::Show("아이디가 일치하지 않습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

					return;
				}
				else 
				{
					Sleep(1000);
					if (time_limit > 1)
					{
						System::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					else
					{
						time_limit++;
					}
				}
			}
		}
		// 입력값이 없다면,
		else {
			System::Windows::Forms::MessageBox::Show("ID / PW 를 다시입력해주세요. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		
		

			

	}
		    
		   // NIck Name 중복 확인버튼
	private: System::Void btnNickNameduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {

		//테두리 없애기
		btnNickNameduplicateChk->NotifyDefault(false);

		// 텍스트 상자에서 텍스트 가져오기
		String^ temp_txt_1 = txtBoxNickName->Text; // textBox는 해당 텍스트 상자의 이름입니다.

		// ID와 PW의 문자열이 채워져있다면
		if (!String::IsNullOrEmpty(temp_txt_1)) {



			int time_limit = 0;

			std::string temp_txt_1_ = msclr::interop::marshal_as<std::string>(temp_txt_1);
			std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_id_try_Signin));

			std::string _Index_Str_Result = _Index_Str + " " + temp_txt_1_;
			const char* buffer = _Index_Str_Result.c_str();
			send(client_sock, buffer, strlen(buffer), 0);

			while (1)
			{ 
				if (Recv_str == "true")// server 에서 오케이받는 함수
				{

					//isChkNickNameDup = true;
					txtBoxNickName->Enabled = false;
					return;
				}
				else if (Recv_str == "false") //  server에서 다른값보내면
				{
					System::Windows::Forms::MessageBox::Show("이미 있는 NickName입니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

					return;
				}
				else // 무한반복되는건데 시간타이밍 주면 좋을거같음
				{
					Sleep(1000);
					if (time_limit > 1)
					{
						System::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					else
					{
						time_limit++;
					}
				}
			}
		}
		// 입력값이 없다면,
		else {
			System::Windows::Forms::MessageBox::Show("입력값이 없습니다. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}


	}

		   // cnacle button 홈화면으로 되돌아가기
	private: System::Void btnCancle_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Close();
}
};
}
