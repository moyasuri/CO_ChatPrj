#pragma once

#include <msclr/marshal_cppstd.h>
#include <string>
#include "UsageClient.h"
#include "ServerChat.h"
extern std::string Recv_str;
extern std::string isTrue;
extern std::string svrMsg;
extern SOCKET client_sock;


namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// CreateRoom에 대한 요약입니다.
	/// </summary>
	public ref class CreateChatRoom : public System::Windows::Forms::Form
	{
	private:
		ServerChat^ serverchatForm = nullptr;
	public:
		CreateChatRoom(void)
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
		~CreateChatRoom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxRoomTitle;
	protected:

	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::TextBox^ txtBoxPW;
	private: System::Windows::Forms::CheckBox^ chkBox;

	protected:





	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateChatRoom::typeid));
			this->txtBoxRoomTitle = (gcnew System::Windows::Forms::TextBox());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->chkBox = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtBoxRoomTitle
			// 
			this->txtBoxRoomTitle->Location = System::Drawing::Point(235, 66);
			this->txtBoxRoomTitle->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxRoomTitle->Name = L"txtBoxRoomTitle";
			this->txtBoxRoomTitle->Size = System::Drawing::Size(249, 28);
			this->txtBoxRoomTitle->TabIndex = 0;
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
			this->btnConfirm->Location = System::Drawing::Point(23, 406);
			this->btnConfirm->Margin = System::Windows::Forms::Padding(4);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(210, 61);
			this->btnConfirm->TabIndex = 1;
			this->btnConfirm->UseVisualStyleBackColor = false;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &CreateChatRoom::btnConfirm_Click);
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(235, 164);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->Size = System::Drawing::Size(249, 28);
			this->txtBoxPW->TabIndex = 3;
			// 
			// chkBox
			// 
			this->chkBox->AutoSize = true;
			this->chkBox->Location = System::Drawing::Point(525, 68);
			this->chkBox->Margin = System::Windows::Forms::Padding(4);
			this->chkBox->Name = L"chkBox";
			this->chkBox->Size = System::Drawing::Size(22, 21);
			this->chkBox->TabIndex = 5;
			this->chkBox->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(520, 406);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(212, 61);
			this->button2->TabIndex = 6;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &CreateChatRoom::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label4->ForeColor = System::Drawing::Color::Cyan;
			this->label4->Location = System::Drawing::Point(25, 59);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(174, 37);
			this->label4->TabIndex = 12;
			this->label4->Text = L"RoomTitle";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(25, 158);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 37);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->label2->ForeColor = System::Drawing::Color::DeepPink;
			this->label2->Location = System::Drawing::Point(547, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(79, 23);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Private";
			// 
			// CreateChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(745, 496);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->chkBox);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->btnConfirm);
			this->Controls->Add(this->txtBoxRoomTitle);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"CreateChatRoom";
			this->Text = L"CreateRoom";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {

	btnConfirm->NotifyDefault(false);
	IniMsg();
	std::string tmptxt_1_;
	String^ tmptxt_3 = txtBoxRoomTitle->Text; // textBox는 해당 텍스트 상자의 이름입니다.
	String^ tmptxt_2 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.


	// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.

	// 룸타이틀은 잇어야되요

	if (String::IsNullOrEmpty(tmptxt_3))
	{
		System::Windows::Forms::MessageBox::Show("방제목을 입력해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if(chkBox->Checked && String::IsNullOrEmpty(tmptxt_2))
	{
		System::Windows::Forms::MessageBox::Show("비밀번호를 입력해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
		
	// roomtype chk->3 아니면 2
	// roompw -없으면 "0", 잇으면 문자열들어가고
	// roomtitle
	if (chkBox->Checked)
	{
		tmptxt_1_ = "3";
	}
	else
	{
		tmptxt_1_ = "2";
	}



		int time_limit = 0;
		
		std::string tmptxt_2_ = msclr::interop::marshal_as<std::string>(tmptxt_2);
		if (tmptxt_1_ == "3" || String::IsNullOrEmpty(tmptxt_2))
		{
			tmptxt_2_ = "0";

		}
		std::string tmptxt_3_ = msclr::interop::marshal_as<std::string>(tmptxt_3);
		std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_Create));
		std::string _Index_Str_Result = _Index_Str + delim + tmptxt_1_ + delim + tmptxt_2_ + delim + tmptxt_3_;
		const char* buffer = _Index_Str_Result.c_str();

		send(client_sock, buffer, strlen(buffer), 0);
		Sleep(100);
		DivStr(Recv_str, svrMsg);


		while (1)
		{
			if (isTrue == trueStr)// server 에서 오케이받는 함수
			{



				if (serverchatForm == nullptr || serverchatForm->IsDisposed) {
					serverchatForm = gcnew ServerChat;
					serverchatForm->Show();
				}

				/*svrMsg = "ID :  " + svrMsg;*/
				this->Close();

				//server방입장

				return;
			}
			else if (isTrue == falseStr) //  server에서 다른값보내면
			{
				System::Windows::Forms::MessageBox::Show("아이디랑 이메일이 일치하지 않습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
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
