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
	private: System::Windows::Forms::Button^ button4;
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
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(270, 75);
			this->button1->TabIndex = 0;
			this->button1->Text = L"New";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &F_Message::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(86, 161);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(270, 77);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Sent";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &F_Message::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(86, 268);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(270, 72);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Message Box";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &F_Message::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(201, 412);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(155, 44);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Close";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &F_Message::button4_Click);
			// 
			// F_Message
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(466, 531);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"F_Message";
			this->Text = L"Message";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (newmessageForm == nullptr || newmessageForm->IsDisposed) {
			newmessageForm = gcnew NewMessage;
			newmessageForm->Show();

		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			newmessageForm->Activate();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		if (messagesentForm == nullptr || messagesentForm->IsDisposed) {
			messagesentForm = gcnew MessageSent;
			messagesentForm->Show();

		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			messagesentForm->Activate();
		}


	}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (messageboxForm == nullptr || messageboxForm->IsDisposed) {
		messageboxForm = gcnew MessageBox;
		messageboxForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		messageboxForm->Activate();
	}
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
