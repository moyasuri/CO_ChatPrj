#pragma once

#include "MyFunction.h"
#include "enum.h"

namespace SocketPrj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// AddFriends에 대한 요약입니다.
	/// </summary>
	public ref class AddFriends : public System::Windows::Forms::Form
	{
	public:
		AddFriends(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		AddFriends(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &AddFriends::ReceivedMsg);
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~AddFriends()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ txtBoxReqMsg;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnSendReq;
	private: System::Windows::Forms::TextBox^ txtBoxNickname;
	private: MyFunction^ _my;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddFriends::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtBoxReqMsg = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnSendReq = (gcnew System::Windows::Forms::Button());
			this->txtBoxNickname = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(77, 117);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(198, 32);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Req Message.";
			// 
			// txtBoxReqMsg
			// 
			this->txtBoxReqMsg->Location = System::Drawing::Point(83, 159);
			this->txtBoxReqMsg->Margin = System::Windows::Forms::Padding(2);
			this->txtBoxReqMsg->Multiline = true;
			this->txtBoxReqMsg->Name = L"txtBoxReqMsg";
			this->txtBoxReqMsg->Size = System::Drawing::Size(398, 83);
			this->txtBoxReqMsg->TabIndex = 18;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(77, 52);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 32);
			this->label2->TabIndex = 17;
			this->label2->Text = L"To.";
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
			this->btnClose->Location = System::Drawing::Point(331, 266);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(150, 44);
			this->btnClose->TabIndex = 15;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &AddFriends::btnClose_Click);
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
			this->btnSendReq->Location = System::Drawing::Point(64, 260);
			this->btnSendReq->Name = L"btnSendReq";
			this->btnSendReq->Size = System::Drawing::Size(233, 50);
			this->btnSendReq->TabIndex = 16;
			this->btnSendReq->UseVisualStyleBackColor = false;
			this->btnSendReq->Click += gcnew System::EventHandler(this, &AddFriends::btnSendReq_Click);
			// 
			// txtBoxNickname
			// 
			this->txtBoxNickname->Location = System::Drawing::Point(148, 59);
			this->txtBoxNickname->Name = L"txtBoxNickname";
			this->txtBoxNickname->Size = System::Drawing::Size(215, 25);
			this->txtBoxNickname->TabIndex = 14;
			// 
			// AddFriends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(612, 414);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxReqMsg);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSendReq);
			this->Controls->Add(this->txtBoxNickname);
			this->Name = L"AddFriends";
			this->Text = L"AddFriends";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


 

				public: void SendMessageForm(int index)
				{

					switch (index)
					{
						case e_friends_Request:
						{
							String^ tmptxt_1 = txtBoxNickname->Text; // textBox는 해당 텍스트 상자의 이름입니다.
							String^ tmptxt_2 = txtBoxReqMsg->Text; // textBox는 해당 텍스트 상자의 이름입니다.
						
							if (!String::IsNullOrEmpty(tmptxt_1)) 
							{
								int t_index = e_friends_Request;
								String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2;
								_my->SendMessage(buffer);
							}
							else
							{
								return;
							}

							break;
						}

					}

				}

	public: void ReceivedMsg(String^ message)
	{
		String^ inputString = message;


		array<String^>^ subString = inputString->Split(' ');


		String^ index_s = subString[0];
		String^ isTrue = subString[1];
		int index = Int32::Parse(index_s);


		switch (index)
		{
		case e_friends_Request:
		{
			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("Request sent", "Request", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else if(isTrue == "else")
			{
				System::Windows::Forms::MessageBox::Show("Already Sent", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("No ID found", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			break;
		}
		}

	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void btnSendReq_Click(System::Object^ sender, System::EventArgs^ e) {
	SendMessageForm(e_friends_Request);
}
};
}
