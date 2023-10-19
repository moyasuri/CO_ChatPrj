#pragma once
#include "FriendList.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// NewMessage에 대한 요약입니다.
	/// </summary>
	public ref class NewMessage : public System::Windows::Forms::Form
	{
	private:
		FriendList^ friendlistForm = nullptr;
	public:
		NewMessage(void)
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
		~NewMessage()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ btnFriends;

	private: System::Windows::Forms::TextBox^ textBox2;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnSend;

	private: System::Windows::Forms::Button^ btnClose;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewMessage::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->btnFriends = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(111, 83);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(232, 28);
			this->textBox1->TabIndex = 1;
			// 
			// btnFriends
			// 
			this->btnFriends->BackColor = System::Drawing::Color::Transparent;
			this->btnFriends->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnFriends.BackgroundImage")));
			this->btnFriends->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnFriends->FlatAppearance->BorderSize = 0;
			this->btnFriends->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFriends->Location = System::Drawing::Point(380, 78);
			this->btnFriends->Margin = System::Windows::Forms::Padding(4);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(109, 40);
			this->btnFriends->TabIndex = 2;
			this->btnFriends->UseVisualStyleBackColor = false;
			this->btnFriends->Click += gcnew System::EventHandler(this, &NewMessage::btnFriends_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(111, 154);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(378, 376);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(38, 74);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 37);
			this->label2->TabIndex = 10;
			this->label2->Text = L"To.";
			// 
			// btnSend
			// 
			this->btnSend->BackColor = System::Drawing::Color::Transparent;
			this->btnSend->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSend.BackgroundImage")));
			this->btnSend->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSend->FlatAppearance->BorderSize = 0;
			this->btnSend->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSend->Location = System::Drawing::Point(148, 576);
			this->btnSend->Margin = System::Windows::Forms::Padding(4);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(133, 45);
			this->btnSend->TabIndex = 2;
			this->btnSend->UseVisualStyleBackColor = false;
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(354, 575);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(135, 49);
			this->btnClose->TabIndex = 2;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &NewMessage::btnClose_Click);
			// 
			// NewMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(598, 682);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->textBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"NewMessage";
			this->Text = L"NewMessage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {
	if (friendlistForm == nullptr || friendlistForm->IsDisposed) {
		friendlistForm = gcnew FriendList;
		friendlistForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		friendlistForm->Activate();
	}
}
};
}

