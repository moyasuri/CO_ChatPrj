#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FindAccount에 대한 요약입니다.
	/// </summary>
	public ref class FindAccount : public System::Windows::Forms::Form
	{
	public:
		FindAccount(void)
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
		~FindAccount()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:









	private: System::Windows::Forms::Label^ label9;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ btnSubmit_ID;
	private: System::Windows::Forms::Button^ btnSubmit_PW;
	private: System::Windows::Forms::Button^ btnCancle;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FindAccount::typeid));
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btnSubmit_ID = (gcnew System::Windows::Forms::Button());
			this->btnSubmit_PW = (gcnew System::Windows::Forms::Button());
			this->btnCancle = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label9->Location = System::Drawing::Point(13, 88);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(70, 24);
			this->label9->TabIndex = 24;
			this->label9->Text = L"E-mail";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Location = System::Drawing::Point(71, 77);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(463, 136);
			this->panel1->TabIndex = 27;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Black;
			this->panel3->Location = System::Drawing::Point(1, 70);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(462, 1);
			this->panel3->TabIndex = 30;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(112, 21);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(311, 34);
			this->textBox2->TabIndex = 27;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(112, 83);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(311, 34);
			this->textBox1->TabIndex = 26;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label2->Location = System::Drawing::Point(15, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 24);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 16));
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(241, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 31);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Forgot ID";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 16));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(230, 290);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(143, 31);
			this->label4->TabIndex = 29;
			this->label4->Text = L"Forgot PW";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->textBox5);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Location = System::Drawing::Point(69, 334);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(463, 199);
			this->panel2->TabIndex = 31;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Black;
			this->panel5->Location = System::Drawing::Point(0, 132);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(462, 1);
			this->panel5->TabIndex = 31;
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox5->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox5->Location = System::Drawing::Point(112, 148);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(311, 34);
			this->textBox5->TabIndex = 32;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label6->Location = System::Drawing::Point(15, 152);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(67, 24);
			this->label6->TabIndex = 31;
			this->label6->Text = L"Phone";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Black;
			this->panel4->Location = System::Drawing::Point(1, 70);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(462, 1);
			this->panel4->TabIndex = 30;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox3->Location = System::Drawing::Point(112, 21);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(311, 34);
			this->textBox3->TabIndex = 27;
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::GhostWhite;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox4->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox4->Location = System::Drawing::Point(112, 84);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(311, 34);
			this->textBox4->TabIndex = 26;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label1->Location = System::Drawing::Point(15, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 24);
			this->label1->TabIndex = 24;
			this->label1->Text = L"ID";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label5->Location = System::Drawing::Point(15, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 24);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Birth";
			// 
			// btnSubmit_ID
			// 
			this->btnSubmit_ID->Font = (gcnew System::Drawing::Font(L"나눔고딕", 10));
			this->btnSubmit_ID->Location = System::Drawing::Point(430, 239);
			this->btnSubmit_ID->Name = L"btnSubmit_ID";
			this->btnSubmit_ID->Size = System::Drawing::Size(104, 30);
			this->btnSubmit_ID->TabIndex = 32;
			this->btnSubmit_ID->Text = L"Submit";
			this->btnSubmit_ID->UseVisualStyleBackColor = true;
			this->btnSubmit_ID->Click += gcnew System::EventHandler(this, &FindAccount::btnSubmit_ID_Click);
			// 
			// btnSubmit_PW
			// 
			this->btnSubmit_PW->Font = (gcnew System::Drawing::Font(L"나눔고딕", 10));
			this->btnSubmit_PW->Location = System::Drawing::Point(430, 558);
			this->btnSubmit_PW->Name = L"btnSubmit_PW";
			this->btnSubmit_PW->Size = System::Drawing::Size(104, 30);
			this->btnSubmit_PW->TabIndex = 33;
			this->btnSubmit_PW->Text = L"Submit";
			this->btnSubmit_PW->UseVisualStyleBackColor = true;
			this->btnSubmit_PW->Click += gcnew System::EventHandler(this, &FindAccount::btnSubmit_PW_Click);
			// 
			// btnCancle
			// 
			this->btnCancle->Font = (gcnew System::Drawing::Font(L"나눔고딕", 10));
			this->btnCancle->ForeColor = System::Drawing::Color::Firebrick;
			this->btnCancle->Location = System::Drawing::Point(430, 615);
			this->btnCancle->Name = L"btnCancle";
			this->btnCancle->Size = System::Drawing::Size(104, 30);
			this->btnCancle->TabIndex = 34;
			this->btnCancle->Text = L"Cancle";
			this->btnCancle->UseVisualStyleBackColor = true;
			this->btnCancle->Click += gcnew System::EventHandler(this, &FindAccount::btnCancle_Click);
			// 
			// FindAccount
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(600, 666);
			this->Controls->Add(this->btnCancle);
			this->Controls->Add(this->btnSubmit_PW);
			this->Controls->Add(this->btnSubmit_ID);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Name = L"FindAccount";
			this->Text = L"FindAccount";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		
private: System::Void btnSubmit_ID_Click(System::Object^ sender, System::EventArgs^ e) {

	// DB ->  이름과 email 일치하는지 확인하고 알려주기
}
private: System::Void btnSubmit_PW_Click(System::Object^ sender, System::EventArgs^ e) {
	// DB ->  아이디와 생년월일 폰번호  일치하는지 확인하고 알려주기
}
private: System::Void btnCancle_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
