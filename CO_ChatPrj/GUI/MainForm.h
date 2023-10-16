#pragma once
#include "Friends.h"
#include "F_Message.h"
#include "JoinChatRoom.h"
#include "CreateChatRoom.h"
#include "DeleteChatRoom.h"
#include "EditProfile.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// MainForm에 대한 요약입니다.
	/// </summary>
	/// 
	///     public ref class Form2 : public Form1 {

	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		Friends^ friendsForm = nullptr;
		F_Message^ f_Message = nullptr;
		JoinChatRoom^ joinchatroomForm = nullptr;
		CreateChatRoom^ createchatroomForm = nullptr;
		DeleteChatRoom^ deletechatroomForm = nullptr;
		EditProfile^ editprofileForm = nullptr;
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;

			}
			this->Owner->Show();
		}
	private: System::Windows::Forms::Button^ btnDelChatRoom;
	private: System::Windows::Forms::Button^ btnJoinChatRoom;
	protected:


	private: System::Windows::Forms::Button^ btnEditProfile;

	private: System::Windows::Forms::Button^ btnCreateChatRoom;



	private: System::Windows::Forms::Button^ btnFriends;
	private: System::Windows::Forms::Button^ btnMessage;
	private: System::Windows::Forms::Button^ btnSignOut;




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
			this->SuspendLayout();
			// 
			// btnDelChatRoom
			// 
			this->btnDelChatRoom->Location = System::Drawing::Point(235, 313);
			this->btnDelChatRoom->Name = L"btnDelChatRoom";
			this->btnDelChatRoom->Size = System::Drawing::Size(266, 81);
			this->btnDelChatRoom->TabIndex = 0;
			this->btnDelChatRoom->Text = L"Delete Chat Room";
			this->btnDelChatRoom->UseVisualStyleBackColor = true;
			this->btnDelChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnDelChatRoom_Click);
			// 
			// btnJoinChatRoom
			// 
			this->btnJoinChatRoom->Location = System::Drawing::Point(235, 97);
			this->btnJoinChatRoom->Name = L"btnJoinChatRoom";
			this->btnJoinChatRoom->Size = System::Drawing::Size(266, 82);
			this->btnJoinChatRoom->TabIndex = 1;
			this->btnJoinChatRoom->Text = L"Join Chat Room";
			this->btnJoinChatRoom->UseVisualStyleBackColor = true;
			this->btnJoinChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnJoinChatRoom_Click);
			// 
			// btnEditProfile
			// 
			this->btnEditProfile->Location = System::Drawing::Point(39, 642);
			this->btnEditProfile->Name = L"btnEditProfile";
			this->btnEditProfile->Size = System::Drawing::Size(240, 41);
			this->btnEditProfile->TabIndex = 2;
			this->btnEditProfile->Text = L"Edit Profile";
			this->btnEditProfile->UseVisualStyleBackColor = true;
			this->btnEditProfile->Click += gcnew System::EventHandler(this, &MainForm::btnEditProfile_Click);
			// 
			// btnCreateChatRoom
			// 
			this->btnCreateChatRoom->Location = System::Drawing::Point(235, 204);
			this->btnCreateChatRoom->Name = L"btnCreateChatRoom";
			this->btnCreateChatRoom->Size = System::Drawing::Size(266, 83);
			this->btnCreateChatRoom->TabIndex = 3;
			this->btnCreateChatRoom->Text = L"Create Chat Room";
			this->btnCreateChatRoom->UseVisualStyleBackColor = true;
			this->btnCreateChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnCreateChatRoom_Click);
			// 
			// btnFriends
			// 
			this->btnFriends->Location = System::Drawing::Point(792, 627);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(206, 81);
			this->btnFriends->TabIndex = 4;
			this->btnFriends->Text = L"Friends";
			this->btnFriends->UseVisualStyleBackColor = true;
			this->btnFriends->Click += gcnew System::EventHandler(this, &MainForm::btnFriends_Click);
			// 
			// btnMessage
			// 
			this->btnMessage->Location = System::Drawing::Point(1083, 627);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(206, 81);
			this->btnMessage->TabIndex = 5;
			this->btnMessage->Text = L"Message";
			this->btnMessage->UseVisualStyleBackColor = true;
			this->btnMessage->Click += gcnew System::EventHandler(this, &MainForm::btnMessage_Click);
			// 
			// btnSignOut
			// 
			this->btnSignOut->Location = System::Drawing::Point(388, 642);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(113, 51);
			this->btnSignOut->TabIndex = 6;
			this->btnSignOut->Text = L"Sign Out";
			this->btnSignOut->UseVisualStyleBackColor = true;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1337, 720);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->btnMessage);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->btnCreateChatRoom);
			this->Controls->Add(this->btnEditProfile);
			this->Controls->Add(this->btnJoinChatRoom);
			this->Controls->Add(this->btnDelChatRoom);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {

		// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.
		if (friendsForm == nullptr || friendsForm->IsDisposed) {
			friendsForm = gcnew Friends;
			friendsForm->Show();
		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			friendsForm->Activate();
		}

	}
private: System::Void btnMessage_Click(System::Object^ sender, System::EventArgs^ e) {
	// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.
	if (f_Message == nullptr || f_Message->IsDisposed) {
		f_Message = gcnew F_Message;
		f_Message->Show();
	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		friendsForm->Activate();
	}
}

private: System::Void btnSignOut_Click(System::Object^ sender, System::EventArgs^ e) {
	// this->Owner->Show();
	this->Owner->Activate();
	this->Close();
}
private: System::Void btnJoinChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {

	if (joinchatroomForm == nullptr || joinchatroomForm->IsDisposed) {
		joinchatroomForm = gcnew JoinChatRoom;
		joinchatroomForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		joinchatroomForm->Activate();
	}
}



private: System::Void btnCreateChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {

	if (createchatroomForm == nullptr || createchatroomForm->IsDisposed) {
		createchatroomForm = gcnew CreateChatRoom;
		createchatroomForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		createchatroomForm->Activate();
	}
}
private: System::Void btnDelChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {

	if (deletechatroomForm == nullptr || deletechatroomForm->IsDisposed) {
		deletechatroomForm = gcnew DeleteChatRoom;
		deletechatroomForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		deletechatroomForm->Activate();
	}
}
private: System::Void btnEditProfile_Click(System::Object^ sender, System::EventArgs^ e) {
	if (editprofileForm == nullptr || editprofileForm->IsDisposed) {
		editprofileForm = gcnew EditProfile;
		editprofileForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		editprofileForm->Activate();
	}
}
};
}
