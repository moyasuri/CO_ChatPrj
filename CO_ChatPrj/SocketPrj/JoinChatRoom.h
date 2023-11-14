#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "ChatRoom.h"
#include "GeneralChatList.h"

namespace SocketPrj {

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
			this->_my->MyEvent += gcnew Action<String^>(this, &JoinChatRoom::ReceivedMsg);
		}
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnGeneral;

	private: System::Windows::Forms::Button^ btnServer;
	private: System::Windows::Forms::Button^ btnClose;


	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~JoinChatRoom()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &JoinChatRoom::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
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
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->label2->Location = System::Drawing::Point(339, 496);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 29);
			this->label2->TabIndex = 8;
			this->label2->Text = L"General";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->label1->Location = System::Drawing::Point(346, 232);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(96, 29);
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
			this->btnGeneral->Location = System::Drawing::Point(267, 278);
			this->btnGeneral->Margin = System::Windows::Forms::Padding(2);
			this->btnGeneral->Name = L"btnGeneral";
			this->btnGeneral->Size = System::Drawing::Size(243, 209);
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
			this->btnServer->Location = System::Drawing::Point(258, 43);
			this->btnServer->Margin = System::Windows::Forms::Padding(2);
			this->btnServer->Name = L"btnServer";
			this->btnServer->Size = System::Drawing::Size(269, 220);
			this->btnServer->TabIndex = 5;
			this->btnServer->UseVisualStyleBackColor = false;
			this->btnServer->Click += gcnew System::EventHandler(this, &JoinChatRoom::btnServer_Click);
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
			this->btnClose->Location = System::Drawing::Point(379, 543);
			this->btnClose->Margin = System::Windows::Forms::Padding(2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(158, 48);
			this->btnClose->TabIndex = 6;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &JoinChatRoom::btnClose_Click);
			// 
			// JoinChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(658, 641);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnGeneral);
			this->Controls->Add(this->btnServer);
			this->Controls->Add(this->btnClose);
			this->Name = L"JoinChatRoom";
			this->Text = L"JoinChatRoom";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &JoinChatRoom::JoinChatRoom_FormClosing);
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

	private: void JoinServerChat(String^ message)
	{
		if (chatRoom == nullptr || chatRoom->IsDisposed) {

			chatRoom = gcnew ChatRoom(_my);
			chatRoom->Owner = this; // Owner를 설정해야 가능
			chatRoom->Show();
			this->Hide();
		}	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			chatRoom->Activate();
		}
	}
	private: void ReceivedMsg(String^ message)
	{
		String^ inputString = message;

		array<String^>^ subString = inputString->Split(' ');

		String^ index_s = subString[0];
		String^ isTrue = subString[1];
		int index = Int32::Parse(index_s);

		switch (index)
		{
			case e_room_Enter:
			{
				if (isTrue == "true")
				{
					this->Invoke(gcnew Action<String^>(this, &JoinChatRoom::JoinServerChat), message);

				}
				else
				{
					// false 시에 할 행동
				}
				break;
			}

		}
	}


private: System::Void btnServer_Click(System::Object^ sender, System::EventArgs^ e) {

	SendMessageForm(e_room_Enter);
	
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
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	
	this->Close();
}
private: System::Void JoinChatRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Show();
	this->Owner->Activate();
}
};
}
