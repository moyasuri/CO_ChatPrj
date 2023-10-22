#pragma once

#include <msclr/marshal_cppstd.h>
#include <string>
#include <sstream>
#include "UsageClient.h"

extern SOCKET client_sock;
extern std::string Recv_str;

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FriendList에 대한 요약입니다.
	/// </summary>
	/// 
	/// 
	///

	
	public ref class FriendList : public System::Windows::Forms::Form
	{

	public:
		event EventHandler^ MyEvent;
		void RaiseEvent()
		{
			MyEvent(this, EventArgs::Empty);
		}
	
	public:
		FriendList(void)
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
		~FriendList()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ btnConfirm;
	protected:

	protected:



	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBoxFriends;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FriendList::typeid));
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBoxFriends = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// btnConfirm
			// 
			this->btnConfirm->BackColor = System::Drawing::Color::Transparent;
			this->btnConfirm->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnConfirm.BackgroundImage")));
			this->btnConfirm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnConfirm->FlatAppearance->BorderSize = 0;
			this->btnConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirm->Location = System::Drawing::Point(68, 559);
			this->btnConfirm->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(168, 55);
			this->btnConfirm->TabIndex = 33;
			this->btnConfirm->UseVisualStyleBackColor = false;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &FriendList::btnConfirm_Click);
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
			this->btnClose->Location = System::Drawing::Point(291, 559);
			this->btnClose->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(179, 51);
			this->btnClose->TabIndex = 47;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &FriendList::btnClose_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(62, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 34);
			this->label1->TabIndex = 48;
			this->label1->Text = L"List";
			// 
			// listBoxFriends
			// 
			this->listBoxFriends->FormattingEnabled = true;
			this->listBoxFriends->ItemHeight = 18;
			this->listBoxFriends->Location = System::Drawing::Point(68, 115);
			this->listBoxFriends->Name = L"listBoxFriends";
			this->listBoxFriends->Size = System::Drawing::Size(378, 400);
			this->listBoxFriends->TabIndex = 49;
			// 
			// FriendList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(534, 670);
			this->Controls->Add(this->listBoxFriends);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnConfirm);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FriendList";
			this->Text = L"FriendList";
			this->Activated += gcnew System::EventHandler(this, &FriendList::FriendList_Activated);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void FriendList_Activated(System::Object^ sender, System::EventArgs^ e) {
	IniMsg();
	listBoxFriends->Items->Clear();
	int time_limit = 0;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_List));
	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStr(Recv_str, svrMsg);

	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{
		std::istringstream iss(svrMsg);

		std::string token;
		while (iss >> token)
		{

			listBoxFriends->Items->Add(gcnew String(token.c_str()));
		}
		return;
	}



}
private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {

	btnConfirm->NotifyDefault(false);
	svrMsg.clear();


	if (listBoxFriends->SelectedItem == nullptr) {
		System::Windows::Forms::MessageBox::Show("쪽지를 보내실 아이디를 선택해주세요", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	String^ tmptxt_1 = listBoxFriends->SelectedItem->ToString();

	frListPickup = msclr::interop::marshal_as<std::string>(tmptxt_1);
	RaiseEvent();
	//dynamic_cast<NewMessage^>(this->Owner)->txtBoxNickname->Text = "설정할 텍스트";
	//System::Windows::Forms::MessageBox::Show(tmptxt_1, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);



}



};
}
