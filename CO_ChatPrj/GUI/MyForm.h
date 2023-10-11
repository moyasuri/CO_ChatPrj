﻿#pragma once
#include "SignUp.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
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




			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btn_signup = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 24));
			this->label1->Location = System::Drawing::Point(88, 390);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(115, 38);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->button1->Location = System::Drawing::Point(466, 427);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(150, 33);
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
			this->label2->Location = System::Drawing::Point(238, 403);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(238, 457);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Password";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::MintCream;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->textBox1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox1->Location = System::Drawing::Point(242, 431);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(176, 19);
			this->textBox1->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::MintCream;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->textBox2->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(242, 484);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(176, 19);
			this->textBox2->TabIndex = 10;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->button2->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->button2->Location = System::Drawing::Point(466, 474);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(150, 33);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btn_signup
			// 
			this->btn_signup->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btn_signup->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btn_signup->Location = System::Drawing::Point(736, 427);
			this->btn_signup->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btn_signup->Name = L"btn_signup";
			this->btn_signup->Size = System::Drawing::Size(150, 33);
			this->btn_signup->TabIndex = 12;
			this->btn_signup->Text = L"Sign up";
			this->btn_signup->UseVisualStyleBackColor = true;
			this->btn_signup->Click += gcnew System::EventHandler(this, &MyForm::btn_signup_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(970, 517);
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

};
}
