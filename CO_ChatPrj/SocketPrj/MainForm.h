#pragma once
#include "enum.h"
#include "MyFunction.h"
#include "Friends.h"
#include "MessageMain.h"
#include "JoinChatRoom.h"
#include "CreateChatRoom.h"
#include "DeleteRoom.h"
#include "EditProfile.h"

namespace MyClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MainForm에 대한 요약입니다.
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		MainForm(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &MainForm::ReceivedMsg);
		}

	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnDelChatRoom;
	protected:
	private: System::Windows::Forms::Button^ btnJoinChatRoom;
	private: System::Windows::Forms::Button^ btnEditProfile;
	private: System::Windows::Forms::Button^ btnCreateChatRoom;
	private: System::Windows::Forms::Button^ btnFriends;
	private: System::Windows::Forms::Button^ btnMessage;
	private: System::Windows::Forms::Button^ btnSignOut;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ NumMessage;
	private: System::Windows::Forms::Panel^ panel1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btnDelChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnJoinChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnEditProfile = (gcnew System::Windows::Forms::Button());
			this->btnCreateChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnFriends = (gcnew System::Windows::Forms::Button());
			this->btnMessage = (gcnew System::Windows::Forms::Button());
			this->btnSignOut = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->NumMessage = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnDelChatRoom
			// 
			this->btnDelChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDelChatRoom.BackgroundImage")));
			this->btnDelChatRoom->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDelChatRoom->FlatAppearance->BorderSize = 0;
			this->btnDelChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelChatRoom->Location = System::Drawing::Point(264, 346);
			this->btnDelChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnDelChatRoom->Name = L"btnDelChatRoom";
			this->btnDelChatRoom->Size = System::Drawing::Size(492, 119);
			this->btnDelChatRoom->TabIndex = 15;
			this->btnDelChatRoom->UseVisualStyleBackColor = false;
			this->btnDelChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnDelChatRoom_Click);
			// 
			// btnJoinChatRoom
			// 
			this->btnJoinChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJoinChatRoom.BackgroundImage")));
			this->btnJoinChatRoom->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnJoinChatRoom->FlatAppearance->BorderSize = 0;
			this->btnJoinChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJoinChatRoom->Location = System::Drawing::Point(258, 64);
			this->btnJoinChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnJoinChatRoom->Name = L"btnJoinChatRoom";
			this->btnJoinChatRoom->Size = System::Drawing::Size(498, 127);
			this->btnJoinChatRoom->TabIndex = 16;
			this->btnJoinChatRoom->UseVisualStyleBackColor = false;
			this->btnJoinChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnJoinChatRoom_Click);
			// 
			// btnEditProfile
			// 
			this->btnEditProfile->BackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnEditProfile.BackgroundImage")));
			this->btnEditProfile->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnEditProfile->FlatAppearance->BorderSize = 0;
			this->btnEditProfile->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEditProfile->Location = System::Drawing::Point(212, 540);
			this->btnEditProfile->Margin = System::Windows::Forms::Padding(4);
			this->btnEditProfile->Name = L"btnEditProfile";
			this->btnEditProfile->Size = System::Drawing::Size(145, 178);
			this->btnEditProfile->TabIndex = 17;
			this->btnEditProfile->UseVisualStyleBackColor = false;
			this->btnEditProfile->Click += gcnew System::EventHandler(this, &MainForm::btnEditProfile_Click);
			// 
			// btnCreateChatRoom
			// 
			this->btnCreateChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreateChatRoom.BackgroundImage")));
			this->btnCreateChatRoom->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCreateChatRoom->FlatAppearance->BorderSize = 0;
			this->btnCreateChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreateChatRoom->Location = System::Drawing::Point(264, 205);
			this->btnCreateChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnCreateChatRoom->Name = L"btnCreateChatRoom";
			this->btnCreateChatRoom->Size = System::Drawing::Size(492, 122);
			this->btnCreateChatRoom->TabIndex = 18;
			this->btnCreateChatRoom->UseVisualStyleBackColor = false;
			this->btnCreateChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnCreateChatRoom_Click);
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
			this->btnFriends->Location = System::Drawing::Point(434, 537);
			this->btnFriends->Margin = System::Windows::Forms::Padding(4);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(152, 186);
			this->btnFriends->TabIndex = 19;
			this->btnFriends->UseVisualStyleBackColor = false;
			this->btnFriends->Click += gcnew System::EventHandler(this, &MainForm::btnFriends_Click);
			// 
			// btnMessage
			// 
			this->btnMessage->BackColor = System::Drawing::Color::Transparent;
			this->btnMessage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMessage.BackgroundImage")));
			this->btnMessage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnMessage->FlatAppearance->BorderSize = 0;
			this->btnMessage->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnMessage->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnMessage->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMessage->Location = System::Drawing::Point(669, 549);
			this->btnMessage->Margin = System::Windows::Forms::Padding(4);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(150, 180);
			this->btnMessage->TabIndex = 20;
			this->btnMessage->UseVisualStyleBackColor = false;
			this->btnMessage->Click += gcnew System::EventHandler(this, &MainForm::btnMessage_Click);
			// 
			// btnSignOut
			// 
			this->btnSignOut->BackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSignOut.BackgroundImage")));
			this->btnSignOut->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignOut->FlatAppearance->BorderSize = 0;
			this->btnSignOut->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignOut->Font = (gcnew System::Drawing::Font(L"Georgia", 10));
			this->btnSignOut->Location = System::Drawing::Point(598, 833);
			this->btnSignOut->Margin = System::Windows::Forms::Padding(4);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(233, 66);
			this->btnSignOut->TabIndex = 21;
			this->btnSignOut->UseVisualStyleBackColor = false;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label4->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label4->Location = System::Drawing::Point(187, 755);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(188, 37);
			this->label4->TabIndex = 24;
			this->label4->Text = L"Edit Profile";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label5->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label5->Location = System::Drawing::Point(447, 754);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 37);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Friends";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label6->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label6->Location = System::Drawing::Point(661, 755);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(155, 37);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Message";
			// 
			// NumMessage
			// 
			this->NumMessage->AutoSize = true;
			this->NumMessage->BackColor = System::Drawing::Color::Transparent;
			this->NumMessage->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->NumMessage->ForeColor = System::Drawing::Color::SeaShell;
			this->NumMessage->Location = System::Drawing::Point(24, 10);
			this->NumMessage->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->NumMessage->Name = L"NumMessage";
			this->NumMessage->Size = System::Drawing::Size(36, 37);
			this->NumMessage->TabIndex = 13;
			this->NumMessage->Text = L"1";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel1.BackgroundImage")));
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->NumMessage);
			this->panel1->Location = System::Drawing::Point(786, 487);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(79, 72);
			this->panel1->TabIndex = 25;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1314, 1022);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->btnMessage);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->btnCreateChatRoom);
			this->Controls->Add(this->btnEditProfile);
			this->Controls->Add(this->btnJoinChatRoom);
			this->Controls->Add(this->btnDelChatRoom);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Activated += gcnew System::EventHandler(this, &MainForm::MainForm_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			String^ numMsg;
			EditProfile^ editProfile = nullptr;
			Friends^ friends = nullptr;
			MessageMain^ messageMain = nullptr;	
			CreateChatRoom^ createchatRoom = nullptr;
			JoinChatRoom^ joinchatRoom = nullptr;
			DeleteRoom^ deleteRoom = nullptr;




		public: void SendMessageForm(int index)
		{

			switch (index)
			{
			case e_message_Cnt:
				{

					int t_index = e_message_Cnt;
					String^ buffer = _my->s_(t_index);
					_my->SendMessage(buffer);
					break;
				}
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
		case e_message_Cnt:
			{

				if (isTrue == "true")
				{
					//txtBoxNickName->Invoke(gcnew Action<String^>(this, &YourFormName::UpdateTextBox), newText);
					numMsg = subString[2];
					NumMessage->Invoke(gcnew Action(this, &MainForm::UpdateMessageCnt));
				}
				break;
			}


		}

	}
		private: void UpdateMessageCnt()
		{
			NumMessage->Text = "";
			NumMessage->Text = numMsg;
		}


	private: System::Void btnSignOut_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Activate();
}
private: System::Void MainForm_Activated(System::Object^ sender, System::EventArgs^ e) {
		SendMessageForm(e_message_Cnt);
}
private: System::Void btnEditProfile_Click(System::Object^ sender, System::EventArgs^ e) {
	if (editProfile == nullptr || editProfile->IsDisposed) {
		editProfile = gcnew EditProfile(_my);
		editProfile->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		editProfile->Show();
	}
}
private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {
	if (friends == nullptr || friends->IsDisposed) {
		friends = gcnew Friends(_my);
		friends->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		friends->Show();
	}
}
private: System::Void btnMessage_Click(System::Object^ sender, System::EventArgs^ e) {
	if (messageMain == nullptr || messageMain->IsDisposed) {
		messageMain = gcnew MessageMain(_my);
		messageMain->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		messageMain->Show();
	}
}
private: System::Void btnJoinChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {
	if (joinchatRoom == nullptr || joinchatRoom->IsDisposed) {
		joinchatRoom = gcnew JoinChatRoom(_my);
		joinchatRoom->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		joinchatRoom->Show();
	}
}
private: System::Void btnCreateChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {
	if (createchatRoom == nullptr || createchatRoom->IsDisposed) {
		createchatRoom = gcnew CreateChatRoom(_my);
		createchatRoom->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		createchatRoom->Show();
	}
}
private: System::Void btnDelChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {
	if (deleteRoom == nullptr || deleteRoom->IsDisposed) {
		deleteRoom = gcnew DeleteRoom(_my);
		deleteRoom->Owner = this; // Owner를 설정해야 가능
		this->Hide();
		//this->HomeImageSound->Stop();
		deleteRoom->Show();
	}
}
};
}
