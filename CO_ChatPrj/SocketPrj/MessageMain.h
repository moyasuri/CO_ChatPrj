#pragma once

#include "MyFunction.h"
#include "enum.h"
#include "MsgBox.h"
#include "MessageSent.h"
#include "NewMessage.h"

namespace MyClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MessageMain에 대한 요약입니다.
	/// </summary>
	public ref class MessageMain : public System::Windows::Forms::Form
	{
	public:
		MessageMain(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		MessageMain(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			
		}
	private: System::Windows::Forms::Button^ btnClose;
	public:
	private: System::Windows::Forms::Button^ btnMsgBox;
	private: System::Windows::Forms::Button^ btnSent;
	private: System::Windows::Forms::Button^ btnNew;
	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MessageMain()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageMain::typeid));
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnMsgBox = (gcnew System::Windows::Forms::Button());
			this->btnSent = (gcnew System::Windows::Forms::Button());
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
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
			this->btnClose->Location = System::Drawing::Point(268, 497);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(180, 54);
			this->btnClose->TabIndex = 1;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MessageMain::btnClose_Click);
			// 
			// btnMsgBox
			// 
			this->btnMsgBox->BackColor = System::Drawing::Color::Transparent;
			this->btnMsgBox->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMsgBox.BackgroundImage")));
			this->btnMsgBox->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnMsgBox->FlatAppearance->BorderSize = 0;
			this->btnMsgBox->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnMsgBox->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnMsgBox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMsgBox->Location = System::Drawing::Point(88, 304);
			this->btnMsgBox->Name = L"btnMsgBox";
			this->btnMsgBox->Size = System::Drawing::Size(266, 80);
			this->btnMsgBox->TabIndex = 2;
			this->btnMsgBox->UseVisualStyleBackColor = false;
			this->btnMsgBox->Click += gcnew System::EventHandler(this, &MessageMain::btnMsgBox_Click);
			// 
			// btnSent
			// 
			this->btnSent->BackColor = System::Drawing::Color::Transparent;
			this->btnSent->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSent.BackgroundImage")));
			this->btnSent->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSent->FlatAppearance->BorderSize = 0;
			this->btnSent->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSent->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSent->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSent->Location = System::Drawing::Point(88, 193);
			this->btnSent->Name = L"btnSent";
			this->btnSent->Size = System::Drawing::Size(266, 80);
			this->btnSent->TabIndex = 3;
			this->btnSent->UseVisualStyleBackColor = false;
			this->btnSent->Click += gcnew System::EventHandler(this, &MessageMain::btnSent_Click);
			// 
			// btnNew
			// 
			this->btnNew->BackColor = System::Drawing::Color::Transparent;
			this->btnNew->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNew.BackgroundImage")));
			this->btnNew->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNew->FlatAppearance->BorderSize = 0;
			this->btnNew->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnNew->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnNew->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNew->Location = System::Drawing::Point(88, 84);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(266, 80);
			this->btnNew->TabIndex = 4;
			this->btnNew->UseVisualStyleBackColor = false;
			this->btnNew->Click += gcnew System::EventHandler(this, &MessageMain::btnNew_Click);
			// 
			// MessageMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(481, 595);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnMsgBox);
			this->Controls->Add(this->btnSent);
			this->Controls->Add(this->btnNew);
			this->Name = L"MessageMain";
			this->Text = L"MessageMain";
			this->ResumeLayout(false);

		}
#pragma endregion

		NewMessage^ newMessage = nullptr;
		MessageSent^ messageSent = nullptr;
		MsgBox^ msgBox = nullptr;


	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnNew_Click(System::Object^ sender, System::EventArgs^ e) {
	if (newMessage == nullptr || newMessage->IsDisposed) {
		newMessage = gcnew NewMessage(_my);
		newMessage->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		newMessage->Show();
	}
}
private: System::Void btnSent_Click(System::Object^ sender, System::EventArgs^ e) {
	if (messageSent == nullptr || messageSent->IsDisposed) {
		messageSent = gcnew MessageSent(_my);
		messageSent->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		messageSent->Show();
	}
}
private: System::Void btnMsgBox_Click(System::Object^ sender, System::EventArgs^ e) {
	if (msgBox == nullptr || msgBox->IsDisposed) {
		msgBox = gcnew MsgBox(_my);
		msgBox->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		msgBox->Show();
	}
}
};
}
