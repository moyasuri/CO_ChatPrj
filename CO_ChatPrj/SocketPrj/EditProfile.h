#pragma once
#include "MyFunction.h"
#include "enum.h"

namespace SocketPrj {

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
	public:
		EditProfile(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		EditProfile(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &EditProfile::ReceivedMsg);
		}
	private: System::Windows::Forms::Button^ btnClose;
	public:
	private: System::Windows::Forms::Button^ btnEditConfirm;
	private: System::Windows::Forms::Button^ btnPWchk;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtBoxPW_new;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txtBoxEmail;
	private: System::Windows::Forms::ComboBox^ combBoxCha;
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
	private: MyFunction^ _my;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditProfile::typeid));
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnEditConfirm = (gcnew System::Windows::Forms::Button());
			this->btnPWchk = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtBoxPW_new = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->combBoxCha = (gcnew System::Windows::Forms::ComboBox());
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
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(472, 795);
			this->btnClose->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(218, 55);
			this->btnClose->TabIndex = 66;
			this->btnClose->UseVisualStyleBackColor = false;
			// 
			// btnEditConfirm
			// 
			this->btnEditConfirm->BackColor = System::Drawing::Color::Transparent;
			this->btnEditConfirm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnEditConfirm->FlatAppearance->BorderSize = 0;
			this->btnEditConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnEditConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnEditConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEditConfirm->Location = System::Drawing::Point(131, 795);
			this->btnEditConfirm->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnEditConfirm->Name = L"btnEditConfirm";
			this->btnEditConfirm->Size = System::Drawing::Size(200, 55);
			this->btnEditConfirm->TabIndex = 65;
			this->btnEditConfirm->UseVisualStyleBackColor = false;
			// 
			// btnPWchk
			// 
			this->btnPWchk->BackColor = System::Drawing::Color::Transparent;
			this->btnPWchk->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnPWchk->FlatAppearance->BorderSize = 0;
			this->btnPWchk->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnPWchk->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnPWchk->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnPWchk->Location = System::Drawing::Point(131, 209);
			this->btnPWchk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnPWchk->Name = L"btnPWchk";
			this->btnPWchk->Size = System::Drawing::Size(158, 44);
			this->btnPWchk->TabIndex = 64;
			this->btnPWchk->UseVisualStyleBackColor = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label10->Location = System::Drawing::Point(189, 299);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(66, 24);
			this->label10->TabIndex = 63;
			this->label10->Text = L"(New)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label8->Location = System::Drawing::Point(193, 111);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(58, 24);
			this->label8->TabIndex = 62;
			this->label8->Text = L"(Old)";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label6->Location = System::Drawing::Point(129, 291);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 32);
			this->label6->TabIndex = 61;
			this->label6->Text = L"PW";
			// 
			// txtBoxPW_new
			// 
			this->txtBoxPW_new->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW_new->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW_new->Enabled = false;
			this->txtBoxPW_new->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPW_new->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW_new->Location = System::Drawing::Point(135, 341);
			this->txtBoxPW_new->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPW_new->MaxLength = 16;
			this->txtBoxPW_new->Name = L"txtBoxPW_new";
			this->txtBoxPW_new->PasswordChar = '*';
			this->txtBoxPW_new->Size = System::Drawing::Size(244, 32);
			this->txtBoxPW_new->TabIndex = 60;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label9->Location = System::Drawing::Point(440, 539);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(97, 32);
			this->label9->TabIndex = 59;
			this->label9->Text = L"E-mail";
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxEmail->Enabled = false;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(445, 587);
			this->txtBoxEmail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(244, 32);
			this->txtBoxEmail->TabIndex = 58;
			// 
			// combBoxCha
			// 
			this->combBoxCha->FormattingEnabled = true;
			this->combBoxCha->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"izuna", L"arisu" });
			this->combBoxCha->Location = System::Drawing::Point(135, 707);
			this->combBoxCha->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->combBoxCha->Name = L"combBoxCha";
			this->combBoxCha->Size = System::Drawing::Size(240, 26);
			this->combBoxCha->TabIndex = 57;
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->BackColor = System::Drawing::Color::Transparent;
			this->btnNickNameduplicateChk->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNickNameduplicateChk->FlatAppearance->BorderSize = 0;
			this->btnNickNameduplicateChk->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnNickNameduplicateChk->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnNickNameduplicateChk->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(432, 455);
			this->btnNickNameduplicateChk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(158, 44);
			this->btnNickNameduplicateChk->TabIndex = 56;
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label7->Location = System::Drawing::Point(129, 659);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(136, 32);
			this->label7->TabIndex = 55;
			this->label7->Text = L"Character";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label5->Location = System::Drawing::Point(129, 539);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 32);
			this->label5->TabIndex = 54;
			this->label5->Text = L"Phone";
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPhone->Enabled = false;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(135, 587);
			this->txtBoxPhone->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(244, 32);
			this->txtBoxPhone->TabIndex = 53;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label4->Location = System::Drawing::Point(129, 411);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 32);
			this->label4->TabIndex = 52;
			this->label4->Text = L"Nick Name";
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxNickName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxNickName->Enabled = false;
			this->txtBoxNickName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxNickName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxNickName->Location = System::Drawing::Point(135, 467);
			this->txtBoxNickName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(244, 32);
			this->txtBoxNickName->TabIndex = 51;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label3->Location = System::Drawing::Point(443, 111);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(121, 32);
			this->label3->TabIndex = 50;
			this->label3->Text = L"re-check";
			// 
			// txtBoxRechk
			// 
			this->txtBoxRechk->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxRechk->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxRechk->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxRechk->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxRechk->Location = System::Drawing::Point(446, 155);
			this->txtBoxRechk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxRechk->Name = L"txtBoxRechk";
			this->txtBoxRechk->PasswordChar = '*';
			this->txtBoxRechk->Size = System::Drawing::Size(244, 32);
			this->txtBoxRechk->TabIndex = 49;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label2->Location = System::Drawing::Point(129, 105);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 32);
			this->label2->TabIndex = 48;
			this->label2->Text = L"PW";
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPW->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW->Location = System::Drawing::Point(133, 155);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(244, 32);
			this->txtBoxPW->TabIndex = 47;
			// 
			// EditProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 957);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnEditConfirm);
			this->Controls->Add(this->btnPWchk);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->txtBoxPW_new);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->combBoxCha);
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

	private:
			bool isChkNickName = false;
	public: void SendMessageForm(int index)
	{

		switch (index)
		{
		case e_edit_PWchk:
		{
			String^ tmptxt_1 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_2 = txtBoxRechk->Text; // textBox는 해당 텍스트 상자의 이름입니다.

			
			if (String::IsNullOrEmpty(tmptxt_1) || String::IsNullOrEmpty(tmptxt_2)) {
				System::Windows::Forms::MessageBox::Show("Please input Password.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			else if (txtBoxRechk->Text != txtBoxPW->Text)
			{
				System::Windows::Forms::MessageBox::Show("Passwords do not match", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ buffer = _my->s_(e_edit_PWchk) + " " + tmptxt_1;
			_my->SendMessage(buffer);

			break;
		}

		case e_edit_NickNamechk:
		{
			String^ tmptxt_1 = txtBoxNickName->Text;


			if (String::IsNullOrEmpty(tmptxt_1))
			{
				System::Windows::Forms::MessageBox::Show("닉네임을 입력해주세요", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ buffer = _my->s_(e_edit_NickNamechk) + " " + tmptxt_1;
			_my->SendMessage(buffer);

			break;
		}

		case e_edit_Confirm:
		{
			if (!isChkNickName)
			{
				System::Windows::Forms::MessageBox::Show("Please ID duplicate check", "warming", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}


			String^ tmptxt_1 = txtBoxEmail->Text;
			String^ tmptxt_2 = txtBoxPhone->Text;
			String^ tmptxt_3 = txtBoxNickName->Text;
			String^ tmptxt_4 = combBoxCha->Text;
			String^ tmptxt_5 = txtBoxPW_new->Text;

			// ID와 PW의 문자열이 채워져있다면
			if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2) && !String::IsNullOrEmpty(tmptxt_2)\
				&& !String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_4) && !String::IsNullOrEmpty(tmptxt_5))
			{
				if (1) // 나중에 고치자
				{
					tmptxt_4 = _my->s_(e_character_izuna);
				}
				int t_index = e_signup_NickNamechk;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1 + " " + tmptxt_2 + " " + tmptxt_3 + " " + tmptxt_4;
				_my->SendMessage(buffer);
			}
			// 입력값이 없다면,
			else {
				System::Windows::Forms::MessageBox::Show("please fill the blank.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		}
	}



	private: System::Void UpdateTextBox()
	{
		txtBoxRechk->Enabled = false;
		txtBoxPW->Enabled = false;
		txtBoxEmail->Enabled = true;
		txtBoxPhone->Enabled = true;
		txtBoxPW_new->Enabled = true;
		txtBoxNickName->Enabled = true;
	}

	private: System::Void UpdateTextBoxNickname()
	{
		txtBoxNickName->Enabled = false;
	}



	private: void ReceivedMsg(String^ message)
	{
		String^ inputString = message;

		array<String^>^ subString = inputString->Split(' ');

		String^ index_s = subString[0];
		String^ isTrue = subString[1];
		int index = Int32::Parse(index_s);

		switch (index)
		{
		case e_edit_PWchk:
		{
			if (isTrue == "true")
			{
				//txtBoxNickName->Invoke(gcnew Action<String^>(this, &YourFormName::UpdateTextBox), newText);
				Invoke(gcnew Action(this, &EditProfile::UpdateTextBox));
				System::Windows::Forms::MessageBox::Show("Password matches username.", "PW check", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("Password Wrong", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}
		case e_edit_NickNamechk:
		{
			if (isTrue == "true")
			{
				Invoke(gcnew Action(this, &EditProfile::UpdateTextBoxNickname));
				System::Windows::Forms::MessageBox::Show("You can use this Nickname", "nickname check", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("The nickname already exists.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}
		case e_edit_Confirm:
		{
			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("Update Profile Success", "Edit Porofile", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}

		}

	}
	};
}
