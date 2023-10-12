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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label7;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SignUp::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Ivory;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(101, 80);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(195, 27);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label1->Location = System::Drawing::Point(96, 41);
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
			this->label2->Location = System::Drawing::Point(96, 124);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 29);
			this->label2->TabIndex = 4;
			this->label2->Text = L"PW";
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Ivory;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(101, 166);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox2->MaxLength = 16;
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(195, 27);
			this->textBox2->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(342, 131);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"re-check";
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Ivory;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox3->Location = System::Drawing::Point(345, 166);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox3->MaxLength = 16;
			this->textBox3->Name = L"textBox3";
			this->textBox3->PasswordChar = '*';
			this->textBox3->Size = System::Drawing::Size(195, 27);
			this->textBox3->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label4->Location = System::Drawing::Point(96, 214);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(131, 29);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Nick Name";
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Ivory;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox4->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox4->Location = System::Drawing::Point(101, 260);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(195, 27);
			this->textBox4->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label5->Location = System::Drawing::Point(96, 380);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 29);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Phone";
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::Ivory;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox5->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox5->Location = System::Drawing::Point(101, 420);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(195, 27);
			this->textBox5->TabIndex = 9;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label6->Location = System::Drawing::Point(96, 299);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 29);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Birth";
			// 
			// textBox6
			// 
			this->textBox6->BackColor = System::Drawing::Color::Ivory;
			this->textBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox6->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->textBox6->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox6->Location = System::Drawing::Point(101, 344);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(195, 27);
			this->textBox6->TabIndex = 11;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->label7->Location = System::Drawing::Point(329, 380);
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
			this->label8->Location = System::Drawing::Point(142, 131);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(151, 20);
			this->label8->TabIndex = 15;
			this->label8->Text = L"(Max 16Character)";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(320, 259);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(130, 29);
			this->button2->TabIndex = 16;
			this->button2->Text = L"Duplicate Check";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(320, 79);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 29);
			this->button1->TabIndex = 17;
			this->button1->Text = L"Duplicate Check";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"유즈", L"아리스" });
			this->comboBox1->Location = System::Drawing::Point(334, 420);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(193, 23);
			this->comboBox1->TabIndex = 18;
			// 
			// SignUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(581, 610);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"SignUp";
			this->Text = L"SignUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion




};
}
