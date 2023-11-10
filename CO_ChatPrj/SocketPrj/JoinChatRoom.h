#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "ChatRoom.h"
#include "GeneralChatList.h"

namespace MyClient {

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
	public:
		JoinChatRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		JoinChatRoom(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
		}
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnGeneral;

	private: System::Windows::Forms::Button^ btnServer;

	private: System::Windows::Forms::Button^ button3;
	private: MyFunction^ _my;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(JoinChatRoom::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnGeneral = (gcnew System::Windows::Forms::Button());
			this->btnServer = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->label2->Location = System::Drawing::Point(424, 595);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 34);
			this->label2->TabIndex = 8;
			this->label2->Text = L"General";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->label1->Location = System::Drawing::Point(432, 278);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(113, 34);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Server";
			// 
			// btnGeneral
			// 
			this->btnGeneral->BackColor = System::Drawing::Color::Transparent;
			this->btnGeneral->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGeneral.BackgroundImage")));
			this->btnGeneral->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnGeneral->FlatAppearance->BorderSize = 0;
			this->btnGeneral->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnGeneral->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnGeneral->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnGeneral->Location = System::Drawing::Point(334, 334);
			this->btnGeneral->Margin = System::Windows::Forms::Padding(2);
			this->btnGeneral->Name = L"btnGeneral";
			this->btnGeneral->Size = System::Drawing::Size(304, 251);
			this->btnGeneral->TabIndex = 4;
			this->btnGeneral->UseVisualStyleBackColor = false;
			this->btnGeneral->Click += gcnew System::EventHandler(this, &JoinChatRoom::btnGeneral_Click);
			// 
			// btnServer
			// 
			this->btnServer->BackColor = System::Drawing::Color::Transparent;
			this->btnServer->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnServer.BackgroundImage")));
			this->btnServer->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnServer->FlatAppearance->BorderSize = 0;
			this->btnServer->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnServer->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnServer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnServer->Location = System::Drawing::Point(322, 52);
			this->btnServer->Margin = System::Windows::Forms::Padding(2);
			this->btnServer->Name = L"btnServer";
			this->btnServer->Size = System::Drawing::Size(336, 264);
			this->btnServer->TabIndex = 5;
			this->btnServer->UseVisualStyleBackColor = false;
			this->btnServer->Click += gcnew System::EventHandler(this, &JoinChatRoom::btnServer_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Location = System::Drawing::Point(474, 652);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(198, 58);
			this->button3->TabIndex = 6;
			this->button3->UseVisualStyleBackColor = false;
			// 
			// JoinChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(822, 769);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnGeneral);
			this->Controls->Add(this->btnServer);
			this->Controls->Add(this->button3);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"JoinChatRoom";
			this->Text = L"JoinChatRoom";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: ChatRoom^ chatRoom = nullptr; 
		public: GeneralChatList^ generalChatList = nullptr; 


	public: void SendMessageForm(int index)
	{

		switch (index)
		{
			case e_room_Enter:
			{

				int t_index = e_room_Enter;
				String^ buffer = _my->s_(e_room_Enter) + " " + "1" + " " + "1";
				_my->SendMessage(buffer);

				break;
			}

		}

	}






private: System::Void btnServer_Click(System::Object^ sender, System::EventArgs^ e) {
	if (chatRoom == nullptr || chatRoom->IsDisposed) {

		chatRoom = gcnew ChatRoom(_my);
		chatRoom->Show();

	}	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		chatRoom->Activate();
	}
}
private: System::Void btnGeneral_Click(System::Object^ sender, System::EventArgs^ e) {
	if (generalChatList == nullptr || generalChatList->IsDisposed) {
		generalChatList = gcnew GeneralChatList(_my);
		generalChatList->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		generalChatList->Show();
	}
}
};
}
