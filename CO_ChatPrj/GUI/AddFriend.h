﻿#pragma once
#include <msclr/marshal_cppstd.h>
#include <string>
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
	/// AddFriend에 대한 요약입니다.
	/// </summary>
	public ref class AddFriend : public System::Windows::Forms::Form
	{
	public:
		AddFriend(void)
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
		~AddFriend()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::Button^ btnSendReq;

	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Label^ label2;


	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddFriend::typeid));
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->btnSendReq = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtBoxID
			// 
			this->txtBoxID->Location = System::Drawing::Point(143, 100);
			this->txtBoxID->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(268, 28);
			this->txtBoxID->TabIndex = 2;
			// 
			// btnSendReq
			// 
			this->btnSendReq->BackColor = System::Drawing::Color::Transparent;
			this->btnSendReq->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSendReq.BackgroundImage")));
			this->btnSendReq->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSendReq->FlatAppearance->BorderSize = 0;
			this->btnSendReq->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSendReq->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSendReq->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSendReq->Location = System::Drawing::Point(143, 239);
			this->btnSendReq->Margin = System::Windows::Forms::Padding(4);
			this->btnSendReq->Name = L"btnSendReq";
			this->btnSendReq->Size = System::Drawing::Size(291, 60);
			this->btnSendReq->TabIndex = 4;
			this->btnSendReq->UseVisualStyleBackColor = false;
			this->btnSendReq->Click += gcnew System::EventHandler(this, &AddFriend::btnSend_Click);
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
			this->btnClose->Location = System::Drawing::Point(224, 329);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(187, 53);
			this->btnClose->TabIndex = 4;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &AddFriend::btnClose_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(57, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(66, 37);
			this->label2->TabIndex = 11;
			this->label2->Text = L"To.";
			// 
			// AddFriend
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(488, 507);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSendReq);
			this->Controls->Add(this->txtBoxID);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AddFriend";
			this->Text = L"AddFriend";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnSendReq_Click(System::Object^ sender, System::EventArgs^ e) {

		////테두리 없애기
		btnSendReq->NotifyDefault(false);

		String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.





		// ID와 PW의 문자열이 채워져있다면
		if (!String::IsNullOrEmpty(tmptxt_1)){

			//// Server에 ID / PW를 보내기함수
			int time_limit = 0;

			std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
			std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Request));
			std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
			const char* buffer = _Index_Str_Result.c_str();
			send(client_sock, buffer, strlen(buffer), 0);

			while (1)
			{
				if (Recv_str == "true")// server 에서 오케이받는 함수
				{
					System::Windows::Forms::MessageBox::Show("친구 요청이 완료되었습니다.", "친구요청", MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				else if (Recv_str == "false") //  server에서 다른값보내면
				{
					System::Windows::Forms::MessageBox::Show("존재하지 않는 아이디입니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

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
		// 입력값이 없다면,
		else {
			System::Windows::Forms::MessageBox::Show("아이디를 입력해주세요. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}


	}
	private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnClose_Click_1(System::Object^ sender, System::EventArgs^ e) {

	this->Close();
}
};
}
