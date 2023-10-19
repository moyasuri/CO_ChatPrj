#pragma once
#include "NewMessage.h"
#include "MessageSent.h"
#include "MessageBox.h"
namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// F_Message에 대한 요약입니다.
	/// </summary>
	public ref class F_Message : public System::Windows::Forms::Form
	{
	private:

		NewMessage^ newmessageForm = nullptr;
		MessageSent^ messagesentForm = nullptr;

	private: System::Windows::Forms::Button^ btnNew;
	private: System::Windows::Forms::Button^ btnSent;
	private: System::Windows::Forms::Button^ btnMsgBox;
	private: System::Windows::Forms::Button^ btnClose;


		   MessageBox^ messageboxForm = nullptr;
	public:
		F_Message(void)
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
		~F_Message()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(F_Message::typeid));
			this->btnNew = (gcnew System::Windows::Forms::Button());
			this->btnSent = (gcnew System::Windows::Forms::Button());
			this->btnMsgBox = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
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
			this->btnNew->Location = System::Drawing::Point(100, 84);
			this->btnNew->Margin = System::Windows::Forms::Padding(4);
			this->btnNew->Name = L"btnNew";
			this->btnNew->Size = System::Drawing::Size(333, 96);
			this->btnNew->TabIndex = 0;
			this->btnNew->UseVisualStyleBackColor = false;
			this->btnNew->Click += gcnew System::EventHandler(this, &F_Message::btnNew_Click);
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
			this->btnSent->Location = System::Drawing::Point(100, 215);
			this->btnSent->Margin = System::Windows::Forms::Padding(4);
			this->btnSent->Name = L"btnSent";
			this->btnSent->Size = System::Drawing::Size(333, 96);
			this->btnSent->TabIndex = 0;
			this->btnSent->UseVisualStyleBackColor = false;
			this->btnSent->Click += gcnew System::EventHandler(this, &F_Message::btnSent_Click);
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
			this->btnMsgBox->Location = System::Drawing::Point(100, 348);
			this->btnMsgBox->Margin = System::Windows::Forms::Padding(4);
			this->btnMsgBox->Name = L"btnMsgBox";
			this->btnMsgBox->Size = System::Drawing::Size(333, 96);
			this->btnMsgBox->TabIndex = 0;
			this->btnMsgBox->UseVisualStyleBackColor = false;
			this->btnMsgBox->Click += gcnew System::EventHandler(this, &F_Message::btnMsgBox_Click);
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
			this->btnClose->Location = System::Drawing::Point(291, 661);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(225, 65);
			this->btnClose->TabIndex = 0;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &F_Message::btnClose_Click);
			// 
			// F_Message
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(529, 763);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnMsgBox);
			this->Controls->Add(this->btnSent);
			this->Controls->Add(this->btnNew);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"F_Message";
			this->Text = L"Message";
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void btnNew_Click(System::Object^ sender, System::EventArgs^ e) {
	if (newmessageForm == nullptr || newmessageForm->IsDisposed) {
		newmessageForm = gcnew NewMessage;
		newmessageForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		newmessageForm->Activate();
	}
}
private: System::Void btnSent_Click(System::Object^ sender, System::EventArgs^ e) {
	if (messagesentForm == nullptr || messagesentForm->IsDisposed) {
		messagesentForm = gcnew MessageSent;
		messagesentForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		messagesentForm->Activate();
	}
}
private: System::Void btnMsgBox_Click(System::Object^ sender, System::EventArgs^ e) {
	if (messageboxForm == nullptr || messageboxForm->IsDisposed) {
		messageboxForm = gcnew MessageBox;
		messageboxForm->Owner = this;
		messageboxForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		messageboxForm->Activate();
	}
}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Owner->Activate();
	this->Close();
}
};
}
