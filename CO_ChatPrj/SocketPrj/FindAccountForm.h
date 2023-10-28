#pragma once
#include "MyFunction.h";
#include "enum.h"


namespace MyClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FindAccountForm에 대한 요약입니다.
	/// </summary>
	public ref class FindAccountForm : public System::Windows::Forms::Form
	{
	public:
		FindAccountForm(void)
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
		~FindAccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnCancle;
	protected:
	private: System::Windows::Forms::Button^ btnSubmit_PW;
	private: System::Windows::Forms::Button^ btnSubmit_ID;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ txtBoxPhone;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::TextBox^ txtBoxBirth;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txtBoxName;
	private: System::Windows::Forms::TextBox^ txtBoxEmail;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label9;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FindAccountForm::typeid));
			this->btnCancle = (gcnew System::Windows::Forms::Button());
			this->btnSubmit_PW = (gcnew System::Windows::Forms::Button());
			this->btnSubmit_ID = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txtBoxPhone = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxBirth = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txtBoxName = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxEmail = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnCancle
			// 
			this->btnCancle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnCancle->ForeColor = System::Drawing::Color::Firebrick;
			this->btnCancle->Location = System::Drawing::Point(525, 765);
			this->btnCancle->Margin = System::Windows::Forms::Padding(4);
			this->btnCancle->Name = L"btnCancle";
			this->btnCancle->Size = System::Drawing::Size(130, 36);
			this->btnCancle->TabIndex = 41;
			this->btnCancle->Text = L"Cancle";
			this->btnCancle->UseVisualStyleBackColor = true;
			// 
			// btnSubmit_PW
			// 
			this->btnSubmit_PW->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnSubmit_PW->Location = System::Drawing::Point(525, 697);
			this->btnSubmit_PW->Margin = System::Windows::Forms::Padding(4);
			this->btnSubmit_PW->Name = L"btnSubmit_PW";
			this->btnSubmit_PW->Size = System::Drawing::Size(130, 36);
			this->btnSubmit_PW->TabIndex = 40;
			this->btnSubmit_PW->Text = L"Submit";
			this->btnSubmit_PW->UseVisualStyleBackColor = true;
			// 
			// btnSubmit_ID
			// 
			this->btnSubmit_ID->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->btnSubmit_ID->Location = System::Drawing::Point(525, 314);
			this->btnSubmit_ID->Margin = System::Windows::Forms::Padding(4);
			this->btnSubmit_ID->Name = L"btnSubmit_ID";
			this->btnSubmit_ID->Size = System::Drawing::Size(130, 36);
			this->btnSubmit_ID->TabIndex = 39;
			this->btnSubmit_ID->Text = L"Submit";
			this->btnSubmit_ID->UseVisualStyleBackColor = true;
			this->btnSubmit_ID->Click += gcnew System::EventHandler(this, &FindAccountForm::btnSubmit_ID_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->txtBoxPhone);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->txtBoxID);
			this->panel2->Controls->Add(this->txtBoxBirth);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->label5);
			this->panel2->Location = System::Drawing::Point(73, 428);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(579, 239);
			this->panel2->TabIndex = 38;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Black;
			this->panel5->Location = System::Drawing::Point(0, 158);
			this->panel5->Margin = System::Windows::Forms::Padding(4);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(578, 1);
			this->panel5->TabIndex = 31;
			// 
			// txtBoxPhone
			// 
			this->txtBoxPhone->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxPhone->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxPhone->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxPhone->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPhone->Location = System::Drawing::Point(140, 178);
			this->txtBoxPhone->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxPhone->Name = L"txtBoxPhone";
			this->txtBoxPhone->Size = System::Drawing::Size(388, 39);
			this->txtBoxPhone->TabIndex = 32;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label6->Location = System::Drawing::Point(19, 182);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(81, 29);
			this->label6->TabIndex = 31;
			this->label6->Text = L"Phone";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Black;
			this->panel4->Location = System::Drawing::Point(1, 84);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(578, 1);
			this->panel4->TabIndex = 30;
			// 
			// txtBoxID
			// 
			this->txtBoxID->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxID->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxID->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxID->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxID->Location = System::Drawing::Point(140, 25);
			this->txtBoxID->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(388, 39);
			this->txtBoxID->TabIndex = 27;
			// 
			// txtBoxBirth
			// 
			this->txtBoxBirth->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxBirth->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxBirth->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxBirth->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxBirth->Location = System::Drawing::Point(140, 101);
			this->txtBoxBirth->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxBirth->Name = L"txtBoxBirth";
			this->txtBoxBirth->Size = System::Drawing::Size(388, 39);
			this->txtBoxBirth->TabIndex = 26;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label1->Location = System::Drawing::Point(19, 30);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 29);
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
			this->label5->Location = System::Drawing::Point(19, 107);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 29);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Birth";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Georgia", 16));
			this->label4->ForeColor = System::Drawing::SystemColors::Control;
			this->label4->Location = System::Drawing::Point(275, 375);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(169, 38);
			this->label4->TabIndex = 37;
			this->label4->Text = L"Forgot PW";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 16));
			this->label3->ForeColor = System::Drawing::SystemColors::Control;
			this->label3->Location = System::Drawing::Point(288, 63);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(154, 38);
			this->label3->TabIndex = 35;
			this->label3->Text = L"Forgot ID";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->txtBoxName);
			this->panel1->Controls->Add(this->txtBoxEmail);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Location = System::Drawing::Point(76, 119);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(579, 163);
			this->panel1->TabIndex = 36;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Black;
			this->panel3->Location = System::Drawing::Point(1, 84);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(578, 1);
			this->panel3->TabIndex = 30;
			// 
			// txtBoxName
			// 
			this->txtBoxName->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxName->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxName->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxName->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxName->Location = System::Drawing::Point(140, 25);
			this->txtBoxName->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxName->Name = L"txtBoxName";
			this->txtBoxName->Size = System::Drawing::Size(388, 39);
			this->txtBoxName->TabIndex = 27;
			// 
			// txtBoxEmail
			// 
			this->txtBoxEmail->BackColor = System::Drawing::Color::GhostWhite;
			this->txtBoxEmail->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtBoxEmail->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->txtBoxEmail->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxEmail->Location = System::Drawing::Point(140, 100);
			this->txtBoxEmail->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->txtBoxEmail->Name = L"txtBoxEmail";
			this->txtBoxEmail->Size = System::Drawing::Size(388, 39);
			this->txtBoxEmail->TabIndex = 26;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label2->Location = System::Drawing::Point(19, 30);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(76, 29);
			this->label2->TabIndex = 24;
			this->label2->Text = L"Name";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Font = (gcnew System::Drawing::Font(L"Georgia", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::ButtonShadow;
			this->label9->Location = System::Drawing::Point(16, 106);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(85, 29);
			this->label9->TabIndex = 24;
			this->label9->Text = L"E-mail";
			// 
			// FindAccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(759, 867);
			this->Controls->Add(this->btnCancle);
			this->Controls->Add(this->btnSubmit_PW);
			this->Controls->Add(this->btnSubmit_ID);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel1);
			this->Name = L"FindAccountForm";
			this->Text = L"FindAccountForm";
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion





















	private: System::Void btnSubmit_ID_Click(System::Object^ sender, System::EventArgs^ e) {
		btnSubmit_ID->NotifyDefault(false);
		SendMessageForm(e_id_find_ID);

	}

	public: void SendMessageForm(int index)
	{

		switch (index)
		{
			case e_id_find_ID:
			{
				String^ tmptxt_1 = txtBoxName->Text; // textBox는 해당 텍스트 상자의 이름입니다.
				String^ tmptxt_2 = txtBoxEmail->Text; // textBox는 해당 텍스트 상자의 이름입니다.

				if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2))
				{
					int t_index = e_id_find_ID;
					String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2;
					_my_Fa->SendMessage(buffer);
				}
				else 
				{
					MessageBox::Show("ID / PW 를 다시입력해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}

			case e_id_find_PW:
			{
				String^ tmptxt_1 = txtBoxID->Text;
				String^ tmptxt_2 = txtBoxBirth->Text;
				String^ tmptxt_3 = txtBoxPhone->Text;


				if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2))
				{
					int t_index = e_id_find_ID;
					String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2;
					_my_Fa->SendMessage(buffer);
				}
				else
				{
					MessageBox::Show("공백란을 입력해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}

		}

	}

	public: void SetMyFunction(MyFunction^ my)
	{
		_my_Fa = my;
		_my_Fa->MyEvent += gcnew Action<String^>(this, &FindAccountForm::MyEventHandler);
	}



	public: void MyEventHandler(String^ message)
	{
		String^ inputString = message;


		array<String^>^ subString = inputString->Split(' ');


		String^ index_s = subString[0];
		String^ isTrue = subString[1];
		int index = Int32::Parse(index_s);


		switch (index)
		{
			case e_id_find_ID:
			{
				if (isTrue == "true")
				{
					String^ msg = "ID : " + subString[2];

					System::Windows::Forms::MessageBox::Show(msg , "아이디 찾기", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("아이디랑 이메일이 일치하지 않습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				return;
			}
			case e_id_find_PW:
			{
				if (isTrue == "true")
				{
					String^ msg = "PW : " + subString[2];
					System::Windows::Forms::MessageBox::Show(msg, "비밀번호 찾기", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("내용이 일치하지 않습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				return;
			}

		}

	//
	}
	private: MyFunction^ _my_Fa;

	

};
}

