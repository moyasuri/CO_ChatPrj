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
	/// EditProfile에 대한 요약입니다.
	/// </summary>
	public ref class EditProfile : public System::Windows::Forms::Form
	{
	private:
		bool isChkNickName = false;
	public:
		EditProfile(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~EditProfile()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label9;
	protected:
	private: System::Windows::Forms::TextBox^ txtBoxEmail;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ btnNickNameduplicateChk;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ txtBoxPhone;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtBoxNickName;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBoxRechk;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtBoxPW;





	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtBoxPW_new;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ btnPWchk;
	private: System::Windows::Forms::Button^ btnEditConfirm;




	private: System::Windows::Forms::Button^ btnClose;


	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->btnNickNameduplicateChk = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtBoxNickName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtBoxRechk = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPW_new = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->btnPWchk = (gcnew System::Windows::Forms::Button());
			this->btnEditConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label9->Location = System::Drawing::Point(346, 427);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(85, 29);
			this->label9->TabIndex = 35;
			this->label9->Text = L"E-mail";
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxEmail->Enabled = false;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(351, 472);
			this->txtBoxEmail->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(195, 27);
			this->txtBoxEmail->TabIndex = 34;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"유즈", L"아리스" });
			this->comboBox1->Location = System::Drawing::Point(36, 571);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(193, 23);
			this->comboBox1->TabIndex = 33;
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(273, 367);
			this->btnNickNameduplicateChk->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(130, 29);
			this->btnNickNameduplicateChk->TabIndex = 32;
			this->btnNickNameduplicateChk->Text = L"Duplicate Check";
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = true;
			this->btnNickNameduplicateChk->Click += gcnew System::EventHandler(this, &EditProfile::btnNickNameduplicateChk_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label7->Location = System::Drawing::Point(31, 531);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(117, 29);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Character";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label5->Location = System::Drawing::Point(31, 431);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 29);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Phone";
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPhone->Enabled = false;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(36, 471);
			this->txtBoxPhone->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(195, 27);
			this->txtBoxPhone->TabIndex = 29;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label4->Location = System::Drawing::Point(31, 323);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 29);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Nick Name";
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxNickName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxNickName->Enabled = false;
			this->txtBoxNickName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxNickName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxNickName->Location = System::Drawing::Point(36, 369);
			this->txtBoxNickName->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(195, 27);
			this->txtBoxNickName->TabIndex = 27;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(350, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 24);
			this->label3->TabIndex = 26;
			this->label3->Text = L"re-check";
			// 
			// txtBoxRechk
			// 
			this->txtBoxRechk->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxRechk->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxRechk->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxRechk->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxRechk->Location = System::Drawing::Point(353, 106);
			this->txtBoxRechk->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxRechk->Name = L"txtBoxRechk";
			this->txtBoxRechk->PasswordChar = '*';
			this->txtBoxRechk->Size = System::Drawing::Size(195, 27);
			this->txtBoxRechk->TabIndex = 25;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label2->Location = System::Drawing::Point(30, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 29);
			this->label2->TabIndex = 24;
			this->label2->Text = L"PW";
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPW->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW->Location = System::Drawing::Point(35, 105);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(195, 27);
			this->txtBoxPW->TabIndex = 23;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label6->Location = System::Drawing::Point(31, 229);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(51, 29);
			this->label6->TabIndex = 39;
			this->label6->Text = L"PW";
			// 
			// txtBoxPW_new
			// 
			this->txtBoxPW_new->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW_new->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW_new->Enabled = false;
			this->txtBoxPW_new->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPW_new->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW_new->Location = System::Drawing::Point(36, 271);
			this->txtBoxPW_new->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxPW_new->MaxLength = 16;
			this->txtBoxPW_new->Name = L"txtBoxPW_new";
			this->txtBoxPW_new->PasswordChar = '*';
			this->txtBoxPW_new->Size = System::Drawing::Size(195, 27);
			this->txtBoxPW_new->TabIndex = 38;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label8->Location = System::Drawing::Point(83, 69);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(49, 20);
			this->label8->TabIndex = 42;
			this->label8->Text = L"(Old)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label10->Location = System::Drawing::Point(79, 235);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(55, 20);
			this->label10->TabIndex = 43;
			this->label10->Text = L"(New)";
			// 
			// btnPWchk
			// 
			this->btnPWchk->Location = System::Drawing::Point(35, 162);
			this->btnPWchk->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnPWchk->Name = L"btnPWchk";
			this->btnPWchk->Size = System::Drawing::Size(118, 33);
			this->btnPWchk->TabIndex = 44;
			this->btnPWchk->Text = L"Check";
			this->btnPWchk->UseVisualStyleBackColor = true;
			this->btnPWchk->Click += gcnew System::EventHandler(this, &EditProfile::btnPWchk_Click);
			// 
			// btnEditConfirm
			// 
			this->btnEditConfirm->Location = System::Drawing::Point(36, 641);
			this->btnEditConfirm->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnEditConfirm->Name = L"btnEditConfirm";
			this->btnEditConfirm->Size = System::Drawing::Size(118, 36);
			this->btnEditConfirm->TabIndex = 45;
			this->btnEditConfirm->Text = L"Confirm";
			this->btnEditConfirm->UseVisualStyleBackColor = true;
			this->btnEditConfirm->Click += gcnew System::EventHandler(this, &EditProfile::btnEditConfirm_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(355, 641);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(118, 36);
			this->btnClose->TabIndex = 46;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &EditProfile::btnClose_Click);
			// 
			// EditProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(631, 748);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnEditConfirm);
			this->Controls->Add(this->btnPWchk);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtBoxPW_new);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->btnNickNameduplicateChk);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtBoxPhone);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtBoxNickName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->txtBoxRechk);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxPW);
			this->Name = L"EditProfile";
			this->Text = L"EditProfile";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void btnPWchk_Click(System::Object^ sender, System::EventArgs^ e) {
	btnPWchk->NotifyDefault(false);
	
	int time_limit = 0;

	String^ tmptxt_1 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
	String^ tmptxt_2 = txtBoxRechk->Text; // textBox는 해당 텍스트 상자의 이름입니다.

	if (!String::IsNullOrEmpty(tmptxt_1)|| !String::IsNullOrEmpty(tmptxt_2)) {
		System::Windows::Forms::MessageBox::Show("비밀번호를 입력해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (txtBoxRechk->Text != txtBoxPW->Text)
	{
		System::Windows::Forms::MessageBox::Show("비밀번호가 일치하지 않습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	

	std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_edit_Confirm));

	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_ ;
	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);


	if(Recv_str == "true")
	{
		System::Windows::Forms::MessageBox::Show("확인되었습니다.", "PW 확인", MessageBoxButtons::OK, MessageBoxIcon::Information);
		txtBoxRechk->Enabled = false;
		txtBoxPW-> Enabled = false;
		txtBoxEmail -> Enabled = true;
		txtBoxPhone -> Enabled = true;
		txtBoxPW_new -> Enabled = true;
		txtBoxNickName	-> Enabled = true;
						
	}
	else if (Recv_str == "false") //  server에서 다른값보내면
	{
		System::Windows::Forms::MessageBox::Show("email 혹은 전화번호가 이미 있습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

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
private: System::Void btnNickNameduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {

	btnNickNameduplicateChk->NotifyDefault(false);
	int time_limit = 0;
	
	String^ tmptxt_1 = txtBoxNickName->Text; // textBox는 해당 텍스트 상자의 이름입니다.
	
	if (!String::IsNullOrEmpty(tmptxt_1))
	{
		System::Windows::Forms::MessageBox::Show("닉네임을 입력해주세요", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_edit_NickNamechk));

	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);


	if (Recv_str == "true")
	{
		System::Windows::Forms::MessageBox::Show("사용 가능한 닉네임입니다.", "닉네임 확인", MessageBoxButtons::OK, MessageBoxIcon::Information);
		isChkNickName =true;

	}
	else if (Recv_str == "false") //  server에서 다른값보내면
	{
		System::Windows::Forms::MessageBox::Show("이미 존재하는 닉네임입니다.", "닉네임 확인", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void btnEditConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!isChkNickName)
	{
		System::Windows::Forms::MessageBox::Show(" 닉네임 중복확인을 해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	String^ tmptxt_1 = txtBoxEmail->Text;
	String^ tmptxt_2 = txtBoxPhone->Text;
	String^ tmptxt_3 = txtBoxPW_new->Text;
	String^ tmptxt_4 = txtBoxNickName -> Text;

	if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2) && !String::IsNullOrEmpty(tmptxt_2)\
		&& !String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_4))
	{	//// Server에 ID / PW를 보내기함수
		int time_limit = 0;
		std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
		std::string tmptxt_2_ = msclr::interop::marshal_as<std::string>(tmptxt_2);
		std::string tmptxt_3_ = msclr::interop::marshal_as<std::string>(tmptxt_3);
		std::string tmptxt_4_ = msclr::interop::marshal_as<std::string>(tmptxt_4);
		std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_signup_Submit));

		std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_ + " " + tmptxt_2_ + " " + tmptxt_3_ + " " + tmptxt_4_;
		const char* buffer = _Index_Str_Result.c_str();
		send(client_sock, buffer, strlen(buffer), 0);

		while (1)
		{
			if (Recv_str == "true")// server 에서 오케이받는 함수
			{
				System::Windows::Forms::MessageBox::Show("회원정보 수정완료", "회원정보 수정", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	else
	{
		System::Windows::Forms::MessageBox::Show("입력값이 없습니다. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}

}
};
}
