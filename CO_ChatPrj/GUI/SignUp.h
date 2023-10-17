#pragma once

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
	public:
		SignUp(void)
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

	private: System::Windows::Forms::ComboBox^ comboBox1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignUp::typeid));
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
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			this->txtBoxID->Location = System::Drawing::Point(102, 145);
			this->txtBoxID->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(195, 27);
			this->txtBoxID->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label1->Location = System::Drawing::Point(97, 106);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label2->Location = System::Drawing::Point(97, 192);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 29);
			this->label2->TabIndex = 4;
			this->label2->Text = L"PW";
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPW->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW->Location = System::Drawing::Point(102, 234);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(195, 27);
			this->txtBoxPW->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(353, 199);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"re-check";
			// 
			// txtBoxRechk
			// 
			this->txtBoxRechk->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxRechk->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxRechk->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxRechk->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxRechk->Location = System::Drawing::Point(356, 234);
			this->txtBoxRechk->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxRechk->Name = L"txtBoxRechk";
			this->txtBoxRechk->Size = System::Drawing::Size(195, 27);
			this->txtBoxRechk->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label4->Location = System::Drawing::Point(97, 279);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 29);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Nick Name";
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxNickName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxNickName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxNickName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxNickName->Location = System::Drawing::Point(102, 325);
			this->txtBoxNickName->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(195, 27);
			this->txtBoxNickName->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label5->Location = System::Drawing::Point(97, 445);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 29);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Phone";
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(102, 485);
			this->txtBoxPhone->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(195, 27);
			this->txtBoxPhone->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label6->Location = System::Drawing::Point(97, 365);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 29);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Birth";
			// 
			// txtBoxBirth
			// 
			this->txtBoxBirth->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxBirth->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxBirth->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxBirth->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxBirth->Location = System::Drawing::Point(102, 410);
			this->txtBoxBirth->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxBirth->Name = L"txtBoxBirth";
			this->txtBoxBirth->Size = System::Drawing::Size(195, 27);
			this->txtBoxBirth->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label7->Location = System::Drawing::Point(340, 445);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(117, 29);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Character";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label8->Location = System::Drawing::Point(143, 199);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(151, 20);
			this->label8->TabIndex = 15;
			this->label8->Text = L"(Max 16Character)";
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(331, 324);
			this->btnNickNameduplicateChk->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(130, 29);
			this->btnNickNameduplicateChk->TabIndex = 16;
			this->btnNickNameduplicateChk->Text = L"Duplicate Check";
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = true;
			this->btnNickNameduplicateChk->Click += gcnew System::EventHandler(this, &SignUp::btnNickNameduplicateChk_Click);
			// 
			// btnIDduplicateChk
			// 
			this->btnIDduplicateChk->Location = System::Drawing::Point(331, 144);
			this->btnIDduplicateChk->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnIDduplicateChk->Name = L"btnIDduplicateChk";
			this->btnIDduplicateChk->Size = System::Drawing::Size(130, 29);
			this->btnIDduplicateChk->TabIndex = 17;
			this->btnIDduplicateChk->Text = L"Duplicate Check";
			this->btnIDduplicateChk->UseVisualStyleBackColor = true;
			this->btnIDduplicateChk->Click += gcnew System::EventHandler(this, &SignUp::btnIDduplicateChk_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"유즈", L"아리스" });
			this->comboBox1->Location = System::Drawing::Point(345, 485);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(193, 23);
			this->comboBox1->TabIndex = 18;
			// 
			// btnSubmit
			// 
			this->btnSubmit->BackColor = System::Drawing::Color::Cornsilk;
			this->btnSubmit->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->btnSubmit->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->btnSubmit->Location = System::Drawing::Point(244, 543);
			this->btnSubmit->Name = L"btnSubmit";
			this->btnSubmit->Size = System::Drawing::Size(146, 56);
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
			this->btnCancle->Location = System::Drawing::Point(416, 543);
			this->btnCancle->Name = L"btnCancle";
			this->btnCancle->Size = System::Drawing::Size(146, 56);
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
			this->label9->Location = System::Drawing::Point(340, 364);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(85, 29);
			this->label9->TabIndex = 22;
			this->label9->Text = L"E-mail";
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(345, 409);
			this->txtBoxEmail->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(195, 27);
			this->txtBoxEmail->TabIndex = 21;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label10->Location = System::Drawing::Point(97, 30);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(76, 29);
			this->label10->TabIndex = 24;
			this->label10->Text = L"Name";
			// 
			// txtBoxName
			// 
			this->txtBoxName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxName->Location = System::Drawing::Point(102, 70);
			this->txtBoxName->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(195, 27);
			this->txtBoxName->TabIndex = 23;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(608, 633);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->txtBoxName);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->txtBoxEmail);
			this->Controls->Add(this->btnCancle);
			this->Controls->Add(this->btnSubmit);
			this->Controls->Add(this->comboBox1);
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
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		// btnsubmit  회원가입 실행버튼
		// 전화번호가 겹치거나 공백란이 있다면 오류를 반환
	private: System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {

		// 텍스트 상자에서 텍스트 가져오기
		txtBoxID->Text;
		txtBoxBirth->Text;
		txtBoxNickName->Text;
		txtBoxPhone->Text;
		txtBoxPW->Text;
		txtBoxRechk->Text;
		String^ textBoxText = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.

		if (!String::IsNullOrEmpty(textBoxText)) {
			// 텍스트 상자에 텍스트가 비어 있지 않으면 Message Box로 출력
			System::Windows::Forms::MessageBox::Show(textBoxText, "텍스트 상자 내용", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			// 텍스트 상자가 비어 있을 때 메시지를 출력할 수 있습니다.
			System::Windows::Forms::MessageBox::Show("text가 비어있습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}


	}




		   // ID 중복 확인하기버튼
	private: System::Void btnIDduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {

		// DB의 ID랑 중복되는지 확인
		// UI::MyForm::ConvertStr(txtBoxID->Text);
			

	}
		    
	private: System::Void btnNickNameduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {

		// DB의 NickName이랑 중복되는지 확인
		txtBoxNickName->Text;
	}

		   // cnacle button 홈화면으로 되돌아가기
private: System::Void btnCancle_Click(System::Object^ sender, System::EventArgs^ e) {

	this->Close();

	
}
};
}
