#pragma once
#include "FriendList.h"
#include "UsageClient.h"
#include <msclr/marshal_cppstd.h>
#include <string>
extern std::string Recv_str;
extern SOCKET client_sock;
namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// NewMessage에 대한 요약입니다.
	/// </summary>
	public ref class NewMessage : public System::Windows::Forms::Form
	{



	private:
		FriendList^ friendlistForm = nullptr;
	public:
		NewMessage(void)
		{
			InitializeComponent();

			// 자식 폼 생성

			// 자식 폼의 이벤트 핸들러 구독
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
	private: System::Void ChildForm_MyEvent(System::Object^ sender, System::EventArgs^ e)
	{
		System::String^ clrString = msclr::interop::marshal_as<System::String^>(frListPickup);
		txtBoxNickname->Text = clrString;
		frListPickup = "";
	}

	private: void childForm_MessageSent(std::string message)
	{
		// 부모 폼에서 이벤트를 처리하고 메시지를 받음
		// 이 부분에서 부모 폼의 컨트롤에 메시지를 표시하거나 다른 작업을 수행할 수 있음
	}



	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~NewMessage()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ txtBoxNickname;
	protected:

	protected:

	protected:

	private: System::Windows::Forms::Button^ btnFriends;
	private: System::Windows::Forms::TextBox^ txtBoxMsg;




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnSend;

	private: System::Windows::Forms::Button^ btnClose;


	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NewMessage::typeid));
			this->txtBoxNickname = (gcnew System::Windows::Forms::TextBox());
			this->btnFriends = (gcnew System::Windows::Forms::Button());
			this->txtBoxMsg = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxNickname
			// 
			this->txtBoxNickname->Location = System::Drawing::Point(111, 83);
			this->txtBoxNickname->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtBoxNickname->Name = L"txtBoxNickname";
			this->txtBoxNickname->Size = System::Drawing::Size(232, 28);
			this->txtBoxNickname->TabIndex = 1;
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
			this->btnFriends->Location = System::Drawing::Point(380, 78);
			this->btnFriends->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnFriends->Name = L"btnFriends";
			this->btnFriends->Size = System::Drawing::Size(109, 40);
			this->btnFriends->TabIndex = 2;
			this->btnFriends->UseVisualStyleBackColor = false;
			this->btnFriends->Click += gcnew System::EventHandler(this, &NewMessage::btnFriends_Click);
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(111, 154);
			this->txtBoxMsg->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(378, 376);
			this->txtBoxMsg->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(38, 74);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 37);
			this->label2->TabIndex = 10;
			this->label2->Text = L"To.";
			// 
			// btnSend
			// 
			this->btnSend->BackColor = System::Drawing::Color::Transparent;
			this->btnSend->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSend.BackgroundImage")));
			this->btnSend->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSend->FlatAppearance->BorderSize = 0;
			this->btnSend->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSend->Location = System::Drawing::Point(148, 576);
			this->btnSend->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(132, 46);
			this->btnSend->TabIndex = 2;
			this->btnSend->UseVisualStyleBackColor = false;
			this->btnSend->Click += gcnew System::EventHandler(this, &NewMessage::btnSend_Click);
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
			this->btnClose->Location = System::Drawing::Point(354, 575);
			this->btnClose->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(135, 49);
			this->btnClose->TabIndex = 2;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &NewMessage::btnClose_Click);
			// 
			// NewMessage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(598, 682);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->btnFriends);
			this->Controls->Add(this->txtBoxNickname);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"NewMessage";
			this->Text = L"NewMessage";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnFriends_Click(System::Object^ sender, System::EventArgs^ e) {
	if (friendlistForm == nullptr || friendlistForm->IsDisposed) {
		friendlistForm = gcnew FriendList;
		friendlistForm->Owner = this;
		friendlistForm->Show();
		friendlistForm->MyEvent += gcnew EventHandler(this, &NewMessage::ChildForm_MyEvent);


		//txtBoxNickname->Controls->Add(friendlistForm);
	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		friendlistForm->Activate();
	}
}
public: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {

	//테두리 없애기
	btnSend->NotifyDefault(false);

	// 텍스트 상자에서 텍스트 가져오기
	String^ tmptxt_1 = txtBoxNickname->Text; // textBox는 해당 텍스트 상자의 이름입니다.
	String^ tmptxt_2 = txtBoxMsg->Text; // textBox는 해당 텍스트 상자의 이름입니다.


	// ID와 PW의 문자열이 채워져있다면
	if (!String::IsNullOrEmpty(tmptxt_1)&& !String::IsNullOrEmpty(tmptxt_2)) {



		// Server에 ID / PW를 보내기함수
		int time_limit = 0;

		std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
		std::string tmptxt_2_ = msclr::interop::marshal_as<std::string>(tmptxt_2);
		std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_Send));
		std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_+ "\n " + tmptxt_2_;
		const char* buffer = _Index_Str_Result.c_str();
		send(client_sock, buffer, strlen(buffer), 0);


		while (1)
		{
			if (Recv_str == "true")// server 에서 오케이받는 함수
			{
				System::Windows::Forms::MessageBox::Show("성공했습니다..", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				return;
			}
			else if (Recv_str == "false") //  server에서 다른값보내면
			{
				System::Windows::Forms::MessageBox::Show("아이디가 일치하지 않습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				return;
			}
			else
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
	// 입력값이 없다면,
	else {
		System::Windows::Forms::MessageBox::Show("보낼사람과 내용을 입력해주세요 ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}


}

};
}

