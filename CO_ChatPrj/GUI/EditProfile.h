#pragma once

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


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label9->Location = System::Drawing::Point(432, 512);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(97, 32);
			this->label9->TabIndex = 35;
			this->label9->Text = L"E-mail";
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(439, 566);
			this->txtBoxEmail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(244, 32);
			this->txtBoxEmail->TabIndex = 34;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"유즈", L"아리스" });
			this->comboBox1->Location = System::Drawing::Point(45, 685);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(240, 26);
			this->comboBox1->TabIndex = 33;
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(442, 441);
			this->btnNickNameduplicateChk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(162, 35);
			this->btnNickNameduplicateChk->TabIndex = 32;
			this->btnNickNameduplicateChk->Text = L"Duplicate Check";
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label7->Location = System::Drawing::Point(39, 637);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(136, 32);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Character";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label5->Location = System::Drawing::Point(39, 517);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 32);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Phone";
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(45, 565);
			this->txtBoxPhone->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(244, 32);
			this->txtBoxPhone->TabIndex = 29;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label4->Location = System::Drawing::Point(39, 386);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(152, 32);
			this->label4->TabIndex = 28;
			this->label4->Text = L"Nick Name";
			// 
			// txtBoxNickName
			// 
			this->txtBoxNickName->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxNickName->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxNickName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxNickName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxNickName->Location = System::Drawing::Point(45, 441);
			this->txtBoxNickName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxNickName->Name = L"txtBoxNickName";
			this->txtBoxNickName->Size = System::Drawing::Size(244, 32);
			this->txtBoxNickName->TabIndex = 27;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(438, 84);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(105, 29);
			this->label3->TabIndex = 26;
			this->label3->Text = L"re-check";
			// 
			// txtBoxRechk
			// 
			this->txtBoxRechk->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxRechk->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxRechk->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxRechk->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxRechk->Location = System::Drawing::Point(441, 127);
			this->txtBoxRechk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxRechk->Name = L"txtBoxRechk";
			this->txtBoxRechk->Size = System::Drawing::Size(244, 32);
			this->txtBoxRechk->TabIndex = 25;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label2->Location = System::Drawing::Point(38, 76);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(58, 32);
			this->label2->TabIndex = 24;
			this->label2->Text = L"PW";
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->BackColor = System::Drawing::Color::Ivory;
			this->txtBoxPW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPW->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW->Location = System::Drawing::Point(44, 126);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(244, 32);
			this->txtBoxPW->TabIndex = 23;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label1->Location = System::Drawing::Point(439, 286);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 29);
			this->label1->TabIndex = 41;
			this->label1->Text = L"re-check";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Ivory;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(442, 328);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(244, 32);
			this->textBox1->TabIndex = 40;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label6->Location = System::Drawing::Point(39, 275);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(58, 32);
			this->label6->TabIndex = 39;
			this->label6->Text = L"PW";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Ivory;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(45, 325);
			this->textBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox2->MaxLength = 16;
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(244, 32);
			this->textBox2->TabIndex = 38;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label8->Location = System::Drawing::Point(104, 83);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(58, 24);
			this->label8->TabIndex = 42;
			this->label8->Text = L"(Old)";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->label10->Location = System::Drawing::Point(99, 282);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(66, 24);
			this->label10->TabIndex = 43;
			this->label10->Text = L"(New)";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(44, 195);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(147, 40);
			this->button3->TabIndex = 44;
			this->button3->Text = L"Confirm";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(45, 769);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(147, 43);
			this->button1->TabIndex = 45;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(444, 769);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(147, 43);
			this->button2->TabIndex = 46;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &EditProfile::button2_Click_1);
			// 
			// EditProfile
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(789, 897);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
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
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"EditProfile";
			this->Text = L"EditProfile";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
