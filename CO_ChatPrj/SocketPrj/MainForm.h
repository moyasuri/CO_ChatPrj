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

			//relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Button\\Img_Gacha_Char_SSR_Resume.png");
			//btnFriends->BackgroundImage = Image::FromFile(relativePath);


		}

	private: MyFunction^ _my;


	private:
		String^ numMsg;
		EditProfile^ editProfile = nullptr;
		Friends^ friends = nullptr;
		MessageMain^ messageMain = nullptr;
		CreateChatRoom^ createchatRoom = nullptr;
		JoinChatRoom^ joinchatRoom = nullptr;
	private: System::Windows::Forms::Button^ btnJoinChatRoom;
	private: System::Windows::Forms::Button^ btnCreateChatRoom;
	private: System::Windows::Forms::Button^ btnDelChatRoom;
	private: System::Windows::Forms::Button^ btnEditProfile;
	private: System::Windows::Forms::Button^ btnFriends;
	private: System::Windows::Forms::Button^ btnMessage;
	private: System::Windows::Forms::Button^ btnSignOut;
	private: System::Windows::Forms::Label^ NumMessage;
		   DeleteRoom^ deleteRoom = nullptr;

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
			this->btnJoinChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnCreateChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnDelChatRoom = (gcnew System::Windows::Forms::Button());
			this->btnEditProfile = (gcnew System::Windows::Forms::Button());
			this->btnFriends = (gcnew System::Windows::Forms::Button());
			this->btnMessage = (gcnew System::Windows::Forms::Button());
			this->btnSignOut = (gcnew System::Windows::Forms::Button());
			this->NumMessage = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnJoinChatRoom
			// 
			this->btnJoinChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJoinChatRoom.BackgroundImage")));
			this->btnJoinChatRoom->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnJoinChatRoom->CausesValidation = false;
			this->btnJoinChatRoom->FlatAppearance->BorderSize = 0;
			this->btnJoinChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnJoinChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJoinChatRoom->Location = System::Drawing::Point(532, 83);
			this->btnJoinChatRoom->Name = L"btnJoinChatRoom";
			this->btnJoinChatRoom->Size = System::Drawing::Size(158, 80);
			this->btnJoinChatRoom->TabIndex = 0;
			this->btnJoinChatRoom->Text = L"button1";
			this->btnJoinChatRoom->UseVisualStyleBackColor = false;
			this->btnJoinChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnJoinChatRoom_Click);
			// 
			// btnCreateChatRoom
			// 
			this->btnCreateChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnCreateChatRoom->CausesValidation = false;
			this->btnCreateChatRoom->FlatAppearance->BorderSize = 0;
			this->btnCreateChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnCreateChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreateChatRoom->Location = System::Drawing::Point(541, 213);
			this->btnCreateChatRoom->Name = L"btnCreateChatRoom";
			this->btnCreateChatRoom->Size = System::Drawing::Size(158, 80);
			this->btnCreateChatRoom->TabIndex = 0;
			this->btnCreateChatRoom->Text = L"button1";
			this->btnCreateChatRoom->UseVisualStyleBackColor = false;
			this->btnCreateChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnCreateChatRoom_Click);
			// 
			// btnDelChatRoom
			// 
			this->btnDelChatRoom->BackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDelChatRoom->CausesValidation = false;
			this->btnDelChatRoom->FlatAppearance->BorderSize = 0;
			this->btnDelChatRoom->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnDelChatRoom->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelChatRoom->Location = System::Drawing::Point(541, 349);
			this->btnDelChatRoom->Name = L"btnDelChatRoom";
			this->btnDelChatRoom->Size = System::Drawing::Size(158, 80);
			this->btnDelChatRoom->TabIndex = 0;
			this->btnDelChatRoom->Text = L"button1";
			this->btnDelChatRoom->UseVisualStyleBackColor = false;
			this->btnDelChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnDelChatRoom_Click);
			// 
			// btnEditProfile
			// 
			this->btnEditProfile->BackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnEditProfile->CausesValidation = false;
			this->btnEditProfile->FlatAppearance->BorderSize = 0;
			this->btnEditProfile->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnEditProfile->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnEditProfile->Location = System::Drawing::Point(251, 601);
			this->btnEditProfile->Name = L"btnEditProfile";
			this->btnEditProfile->Size = System::Drawing::Size(158, 80);
			this->btnEditProfile->TabIndex = 0;
			this->btnEditProfile->Text = L"button1";
			this->btnEditProfile->UseVisualStyleBackColor = false;
			this->btnEditProfile->Click += gcnew System::EventHandler(this, &MainForm::btnEditProfile_Click);
			// 
			// btnFriends
			// 
			this->btnFriends->BackColor = System::Drawing::Color::Transparent;
			this->btnFriends->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnFriends->CausesValidation = false;
			this->btnFriends->FlatAppearance->BorderSize = 0;
			this->btnFriends->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnFriends->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFriends->Location = System::Drawing::Point(579, 601);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(158, 80);
			this->btnFriends->TabIndex = 0;
			this->btnFriends->Text = L"button1";
			this->btnFriends->UseVisualStyleBackColor = false;
			this->btnFriends->Click += gcnew System::EventHandler(this, &MainForm::btnFriends_Click);
			// 
			// btnMessage
			// 
			this->btnMessage->BackColor = System::Drawing::Color::Transparent;
			this->btnMessage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnMessage->CausesValidation = false;
			this->btnMessage->FlatAppearance->BorderSize = 0;
			this->btnMessage->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnMessage->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnMessage->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnMessage->Location = System::Drawing::Point(929, 610);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(158, 80);
			this->btnMessage->TabIndex = 0;
			this->btnMessage->Text = L"button1";
			this->btnMessage->UseVisualStyleBackColor = false;
			this->btnMessage->Click += gcnew System::EventHandler(this, &MainForm::btnMessage_Click);
			// 
			// btnSignOut
			// 
			this->btnSignOut->BackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignOut->CausesValidation = false;
			this->btnSignOut->FlatAppearance->BorderSize = 0;
			this->btnSignOut->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignOut->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignOut->Location = System::Drawing::Point(972, 765);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(158, 80);
			this->btnSignOut->TabIndex = 0;
			this->btnSignOut->Text = L"button1";
			this->btnSignOut->UseVisualStyleBackColor = false;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
			// 
			// NumMessage
			// 
			this->NumMessage->AutoSize = true;
			this->NumMessage->Location = System::Drawing::Point(978, 506);
			this->NumMessage->Name = L"NumMessage";
			this->NumMessage->Size = System::Drawing::Size(54, 18);
			this->NumMessage->TabIndex = 1;
			this->NumMessage->Text = L"label1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1470, 902);
			this->Controls->Add(this->NumMessage);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->btnMessage);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->btnEditProfile);
			this->Controls->Add(this->btnDelChatRoom);
			this->Controls->Add(this->btnCreateChatRoom);
			this->Controls->Add(this->btnJoinChatRoom);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Activated += gcnew System::EventHandler(this, &MainForm::MainForm_Activated);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

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
