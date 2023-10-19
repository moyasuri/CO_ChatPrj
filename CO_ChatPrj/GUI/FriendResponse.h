#pragma once

#include <msclr/marshal_cppstd.h>
#include <string>
#include <cliext/vector>
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
	/// FriendResponse에 대한 요약입니다.
	/// </summary>
	public ref class FriendResponse : public System::Windows::Forms::Form
	{
	public:
		FriendResponse(void)
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
		~FriendResponse()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ListBox^ listBoxFriendsResponse;
	private: System::Windows::Forms::Button^ btnAccept;
	private: System::Windows::Forms::Button^ btnReject;

	protected:




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnClose;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FriendResponse::typeid));
			this->listBoxFriendsResponse = (gcnew System::Windows::Forms::ListBox());
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->btnReject = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBoxFriendsResponse
			// 
			this->listBoxFriendsResponse->FormattingEnabled = true;
			this->listBoxFriendsResponse->ItemHeight = 18;
			this->listBoxFriendsResponse->Location = System::Drawing::Point(91, 173);
			this->listBoxFriendsResponse->Margin = System::Windows::Forms::Padding(4);
			this->listBoxFriendsResponse->Name = L"listBoxFriendsResponse";
			this->listBoxFriendsResponse->Size = System::Drawing::Size(336, 382);
			this->listBoxFriendsResponse->TabIndex = 1;
			// 
			// btnAccept
			// 
			this->btnAccept->BackColor = System::Drawing::Color::Transparent;
			this->btnAccept->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAccept.BackgroundImage")));
			this->btnAccept->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAccept->FlatAppearance->BorderSize = 0;
			this->btnAccept->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnAccept->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnAccept->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAccept->Location = System::Drawing::Point(452, 166);
			this->btnAccept->Margin = System::Windows::Forms::Padding(4);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(184, 64);
			this->btnAccept->TabIndex = 2;
			this->btnAccept->UseVisualStyleBackColor = false;
			this->btnAccept->Click += gcnew System::EventHandler(this, &FriendResponse::btnAccept_Click);
			// 
			// btnReject
			// 
			this->btnReject->BackColor = System::Drawing::Color::Transparent;
			this->btnReject->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReject.BackgroundImage")));
			this->btnReject->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnReject->FlatAppearance->BorderSize = 0;
			this->btnReject->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnReject->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnReject->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnReject->Location = System::Drawing::Point(452, 258);
			this->btnReject->Margin = System::Windows::Forms::Padding(4);
			this->btnReject->Name = L"btnReject";
			this->btnReject->Size = System::Drawing::Size(184, 69);
			this->btnReject->TabIndex = 3;
			this->btnReject->UseVisualStyleBackColor = false;
			this->btnReject->Click += gcnew System::EventHandler(this, &FriendResponse::btnReject_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(84, 99);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 37);
			this->label2->TabIndex = 12;
			this->label2->Text = L"From.";
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
			this->btnClose->Location = System::Drawing::Point(452, 597);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(184, 60);
			this->btnClose->TabIndex = 13;
			this->btnClose->UseVisualStyleBackColor = false;
			// 
			// FriendResponse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(689, 748);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnReject);
			this->Controls->Add(this->btnAccept);
			this->Controls->Add(this->listBoxFriendsResponse);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FriendResponse";
			this->Text = L"FriendResponse";
			this->Activated += gcnew System::EventHandler(this, &FriendResponse::FriendResponse_Visible);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void FriendResponse_Visible(System::Object^ sender, System::EventArgs^ e) {

	listBoxFriendsResponse->Items->Clear();
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Response_List));
	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);

	// std::stringstream ss(Recv_str);
	//ss >> _Index;
	//server_msg.push_back(_Contents);
	//_Contents = string(buf + 3);
	//server_msg.push_back(_Contents);

	// C++/CLI CLI 배열
	// cli::array<System::Object^>^ arr = gcnew cli::array<System::Object^>(1);

	// 공백으로 문자열 분할
	std::istringstream iss(Recv_str); // 살짝 문제가 있을거 같기도..
	std::string token;
	int count = 0;

	while (iss >> token) {
		if (count == 0 && token == "true") {
			// 첫 번째 단어가 "true"인 경우 넘어감
			count++;
			continue;
		}
		//System::String^ str = marshal_as<String^>(token);
		listBoxFriendsResponse->Items->Add(gcnew String(token.c_str()));
	}

	// List Box에 추가
	// listBoxFriends->Items->AddRange(vect);



}
private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e) {

	btnAccept->NotifyDefault(false);
	int time_limit = 0;
	std::string tmptxt_1_;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Accept));
	if (listBoxFriendsResponse->SelectedItem == nullptr) {
		System::Windows::Forms::MessageBox::Show("추가하실 아이디를 선택해주세요.", "친구추가", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}


	String^ tmptxt_1 = listBoxFriendsResponse->SelectedItem->ToString();
	tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;

	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);

	while (1)
	{
		//if (Recv_str == "true")// server 에서 오케이받는 함수
		if (1)// test
		{
			FriendResponse_Visible(sender, e);
			System::Windows::Forms::MessageBox::Show("친구를 추가하였습니다.", "친구추가", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		else if (Recv_str == "false") //  server에서 다른값보내면
		{
			System::Windows::Forms::MessageBox::Show("다른값을 보냈다고?", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			return;
		}
		else // 무한반복되는건데 시간타이밍 주면 좋을거같음
		{
			Sleep(1000);
			if (time_limit > 1)
			{
				System::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			else
			{
				time_limit++;
			}
		}
	}


}
private: System::Void btnReject_Click(System::Object^ sender, System::EventArgs^ e) {

	btnAccept->NotifyDefault(false);
	int time_limit = 0;
	std::string tmptxt_1_;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Accept));
	if (listBoxFriendsResponse->SelectedItem == nullptr) {
		System::Windows::Forms::MessageBox::Show("추가하실 아이디를 선택해주세요.", "친구추가", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}


	String^ tmptxt_1 = listBoxFriendsResponse->SelectedItem->ToString();
	tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;

	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);

	while (1)
	{
		//if (Recv_str == "true")// server 에서 오케이받는 함수
		if (1)// test
		{
			FriendResponse_Visible(sender, e);
			System::Windows::Forms::MessageBox::Show("친구를 추가하였습니다.", "친구추가", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		else if (Recv_str == "false") //  server에서 다른값보내면
		{
			System::Windows::Forms::MessageBox::Show("다른값을 보냈다고?", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

			return;
		}
		else // 무한반복되는건데 시간타이밍 주면 좋을거같음
		{
			Sleep(1000);
			if (time_limit > 1)
			{
				System::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}
			else
			{
				time_limit++;
			}
		}
	}

}
};
}
