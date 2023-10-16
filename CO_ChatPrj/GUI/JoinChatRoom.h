#pragma once
#include "ServerChat.h"
#include "GeneralChatIndex.h"
namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// JoinChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class JoinChatRoom : public System::Windows::Forms::Form
	{
	private:
		ServerChat^ serverchatForm = nullptr;
		GeneralChatIndex^ generalchatindexForm = nullptr;
	public:
		JoinChatRoom(void)
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
		~JoinChatRoom()
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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(114, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(271, 117);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Server";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &JoinChatRoom::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(92, 185);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(271, 117);
			this->button2->TabIndex = 1;
			this->button2->Text = L"General";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &JoinChatRoom::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(396, 305);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 62);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Close";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &JoinChatRoom::button3_Click);
			// 
			// JoinChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(573, 400);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"JoinChatRoom";
			this->Text = L"JoinChatRoom";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serverchatForm == nullptr || serverchatForm->IsDisposed) {
			serverchatForm = gcnew ServerChat;
			serverchatForm->Show();

		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			serverchatForm->Activate();
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		if (generalchatindexForm == nullptr || generalchatindexForm->IsDisposed) {
			generalchatindexForm = gcnew GeneralChatIndex;
			generalchatindexForm->Show();

		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			generalchatindexForm->Activate();
		}
	}
};
}
