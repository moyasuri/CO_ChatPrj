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

	private: System::String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::String^ relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\HomeIntro.gif");

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\BG_CS_PV4_074.jpg");
			this->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Others\\Img_Gacha_Char_SSR_Resume.png");
			btnFriends->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\MomoTalk.png.png");
			btnMessage->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\Document2.png");
			btnEditProfile->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\signout.png");
			btnSignOut->BackgroundImage = Image::FromFile(relativePath);
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnDelChatRoom
			// 
			this->btnDelChatRoom->Location = System::Drawing::Point(147, 320);
			this->btnDelChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnDelChatRoom->Name = L"btnDelChatRoom";
			this->btnDelChatRoom->Size = System::Drawing::Size(491, 97);
			this->btnDelChatRoom->TabIndex = 0;
			this->btnDelChatRoom->Text = L"Delete Chat Room";
			this->btnDelChatRoom->UseVisualStyleBackColor = true;
			this->btnDelChatRoom->Click += gcnew System::EventHandler(this, &MainForm::btnDelChatRoom_Click);
			// 
			// btnJoinChatRoom
			// 
			this->btnJoinChatRoom->Location = System::Drawing::Point(147, 49);
			this->btnJoinChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnJoinChatRoom->Name = L"btnJoinChatRoom";
			this->btnJoinChatRoom->Size = System::Drawing::Size(491, 98);
			this->btnJoinChatRoom->TabIndex = 1;
			this->btnJoinChatRoom->Text = L"Join Chat Room";
			this->btnJoinChatRoom->UseVisualStyleBackColor = true;
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
			this->btnEditProfile->Location = System::Drawing::Point(75, 529);
			this->btnEditProfile->Margin = System::Windows::Forms::Padding(4);
			this->btnEditProfile->Name = L"btnEditProfile";
			this->btnEditProfile->Size = System::Drawing::Size(151, 178);
			this->btnEditProfile->TabIndex = 2;
			this->btnEditProfile->UseVisualStyleBackColor = false;
			this->btnEditProfile->Click += gcnew System::EventHandler(this, &MainForm::btnEditProfile_Click);
			// 
			// btnCreateChatRoom
			// 
			this->btnCreateChatRoom->Location = System::Drawing::Point(147, 179);
			this->btnCreateChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnCreateChatRoom->Name = L"btnCreateChatRoom";
			this->btnCreateChatRoom->Size = System::Drawing::Size(491, 100);
			this->btnCreateChatRoom->TabIndex = 3;
			this->btnCreateChatRoom->Text = L"Create Chat Room";
			this->btnCreateChatRoom->UseVisualStyleBackColor = true;
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
			this->btnFriends->Location = System::Drawing::Point(307, 526);
			this->btnFriends->Margin = System::Windows::Forms::Padding(4);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(159, 186);
			this->btnFriends->TabIndex = 4;
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
			this->btnMessage->Location = System::Drawing::Point(552, 535);
			this->btnMessage->Margin = System::Windows::Forms::Padding(4);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(156, 180);
			this->btnMessage->TabIndex = 5;
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
			this->btnSignOut->Location = System::Drawing::Point(473, 820);
			this->btnSignOut->Margin = System::Windows::Forms::Padding(4);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(242, 66);
			this->btnSignOut->TabIndex = 6;
			this->btnSignOut->UseVisualStyleBackColor = false;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->label1->Location = System::Drawing::Point(69, 744);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 35);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Edit Profile";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->label2->Location = System::Drawing::Point(330, 744);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 35);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Friends";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 15));
			this->label3->Location = System::Drawing::Point(557, 746);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(129, 35);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Message";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(790, 919);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnSignOut);
			this->Controls->Add(this->btnMessage);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->btnCreateChatRoom);
			this->Controls->Add(this->btnEditProfile);
			this->Controls->Add(this->btnJoinChatRoom);
			this->Controls->Add(this->btnDelChatRoom);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {
		btnFriends->NotifyDefault(false);

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
	btnMessage->NotifyDefault(false);
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
	btnSignOut->NotifyDefault(false);
	this->Owner->Activate();
	this->Close();
}
private: System::Void btnJoinChatRoom_Click(System::Object^ sender, System::EventArgs^ e) {
	btnJoinChatRoom->NotifyDefault(false);
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
	btnCreateChatRoom->NotifyDefault(false);
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
	btnDelChatRoom->NotifyDefault(false);

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
	btnEditProfile->NotifyDefault(false);
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
