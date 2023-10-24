﻿#pragma once
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
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Label^ NumMessage;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;





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
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\MomoTalk.png");
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
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->NumMessage = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			this->btnDelChatRoom->Location = System::Drawing::Point(124, 335);
			this->btnDelChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnDelChatRoom->Name = L"btnDelChatRoom";
			this->btnDelChatRoom->Size = System::Drawing::Size(492, 119);
			this->btnDelChatRoom->TabIndex = 0;
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
			this->btnJoinChatRoom->Location = System::Drawing::Point(118, 53);
			this->btnJoinChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnJoinChatRoom->Name = L"btnJoinChatRoom";
			this->btnJoinChatRoom->Size = System::Drawing::Size(498, 127);
			this->btnJoinChatRoom->TabIndex = 1;
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
			this->btnEditProfile->Location = System::Drawing::Point(72, 529);
			this->btnEditProfile->Margin = System::Windows::Forms::Padding(4);
			this->btnEditProfile->Name = L"btnEditProfile";
			this->btnEditProfile->Size = System::Drawing::Size(145, 178);
			this->btnEditProfile->TabIndex = 2;
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
			this->btnCreateChatRoom->Location = System::Drawing::Point(124, 194);
			this->btnCreateChatRoom->Margin = System::Windows::Forms::Padding(4);
			this->btnCreateChatRoom->Name = L"btnCreateChatRoom";
			this->btnCreateChatRoom->Size = System::Drawing::Size(492, 122);
			this->btnCreateChatRoom->TabIndex = 3;
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
			this->btnFriends->Location = System::Drawing::Point(294, 526);
			this->btnFriends->Margin = System::Windows::Forms::Padding(4);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(152, 186);
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
			this->btnMessage->Location = System::Drawing::Point(529, 538);
			this->btnMessage->Margin = System::Windows::Forms::Padding(4);
			this->btnMessage->Name = L"btnMessage";
			this->btnMessage->Size = System::Drawing::Size(150, 180);
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
			this->btnSignOut->Location = System::Drawing::Point(458, 822);
			this->btnSignOut->Margin = System::Windows::Forms::Padding(4);
			this->btnSignOut->Name = L"btnSignOut";
			this->btnSignOut->Size = System::Drawing::Size(233, 66);
			this->btnSignOut->TabIndex = 6;
			this->btnSignOut->UseVisualStyleBackColor = false;
			this->btnSignOut->Click += gcnew System::EventHandler(this, &MainForm::btnSignOut_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label4->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label4->Location = System::Drawing::Point(47, 744);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(188, 37);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Edit Profile";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label5->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label5->Location = System::Drawing::Point(307, 743);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(134, 37);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Friends";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label6->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->label6->Location = System::Drawing::Point(521, 744);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(155, 37);
			this->label6->TabIndex = 11;
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
			this->panel1->Location = System::Drawing::Point(646, 476);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(79, 72);
			this->panel1->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(630, 179);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 147);
			this->button1->TabIndex = 15;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(631, 352);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(93, 72);
			this->button2->TabIndex = 16;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(772, 919);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
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
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"MainForm";
			this->Activated += gcnew System::EventHandler(this, &MainForm::MainForm_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::MainForm_FormClosing);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {
		btnFriends->NotifyDefault(false);

		// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.
		if (friendsForm == nullptr || friendsForm->IsDisposed) {
			friendsForm = gcnew Friends;
			friendsForm->Owner = this;
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
		f_Message->Owner = this;
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
		joinchatroomForm->Owner=this;
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
		createchatroomForm->Owner = this;
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
		deletechatroomForm->Owner = this;
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
		editprofileForm->Owner = this;
		editprofileForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		editprofileForm->Activate();
	}
}

private: System::Void MainForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Activate();

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	IniMsg();
	/*String^ tmptxt_1 = txtBoxNickname->Text;
	String^ tmptxt_2 = txtBoxMsg->Text;

	if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2)) {*/

		//std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
		//std::string tmptxt_2_ = msclr::interop::marshal_as<std::string>(tmptxt_2);
		//std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_Send));
		//std::string _Index_Str_Result = _Index_Str + delim + tmptxt_1_ + delim + tmptxt_2_;
		//const char* buffer = _Index_Str_Result.c_str();

		//std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
		//std::string tmptxt_2_ = msclr::interop::marshal_as<std::string>(tmptxt_2);
		std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_Chat));
		std::string _Index_Str_Result = _Index_Str;/* + delim + tmptxt_1_ + delim + tmptxt_2_;*/
		const char* buffer = _Index_Str_Result.c_str();


		send(client_sock, buffer, strlen(buffer), 0);
		Sleep(100);
		//DivStr(Recv_str, svrMsg);

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	IniMsg();

	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_Enter));
	std::string _Index_Str_Result = _Index_Str;/* + delim + tmptxt_1_ + delim + tmptxt_2_;*/
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
}
private: System::Void MainForm_Activated(System::Object^ sender, System::EventArgs^ e) {



	IniMsg();
	int time_limit = 0;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_Cnt));
	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);
	NumMessage->Text = "";


	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{
		System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
		NumMessage->Text = clrString;

	}

}
};
}
