#pragma once

#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>
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
	/// SentMessage에 대한 요약입니다.
	/// </summary>
	public ref class MessageSent : public System::Windows::Forms::Form
	{
	public:
		MessageSent(void)
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
		~MessageSent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ViewDataSent;
	private: System::Windows::Forms::TextBox^ txtBoxMsg;
	protected:

	protected:



	private: System::Windows::Forms::Button^ btnDelete;



	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NufOfSentMsg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ To;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageSent::typeid));
			this->ViewDataSent = (gcnew System::Windows::Forms::DataGridView());
			this->txtBoxMsg = (gcnew System::Windows::Forms::TextBox());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->NufOfSentMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->To = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataSent))->BeginInit();
			this->SuspendLayout();
			// 
			// ViewDataSent
			// 
			this->ViewDataSent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewDataSent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NufOfSentMsg,
					this->To, this->Date
			});
			this->ViewDataSent->Location = System::Drawing::Point(50, 65);
			this->ViewDataSent->Name = L"ViewDataSent";
			this->ViewDataSent->RowHeadersWidth = 51;
			this->ViewDataSent->RowTemplate->Height = 27;
			this->ViewDataSent->Size = System::Drawing::Size(474, 200);
			this->ViewDataSent->TabIndex = 3;
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(50, 362);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(474, 263);
			this->txtBoxMsg->TabIndex = 9;
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::Transparent;
			this->btnDelete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDelete.BackgroundImage")));
			this->btnDelete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnDelete->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Location = System::Drawing::Point(377, 278);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(147, 50);
			this->btnDelete->TabIndex = 10;
			this->btnDelete->UseVisualStyleBackColor = false;
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
			this->btnClose->Location = System::Drawing::Point(377, 642);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(147, 50);
			this->btnClose->TabIndex = 10;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MessageSent::btnClose_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->label2->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label2->Location = System::Drawing::Point(44, 309);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(162, 39);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Message";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->label1->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label1->Location = System::Drawing::Point(44, 12);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 39);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Sent";
			// 
			// NufOfSentMsg
			// 
			this->NufOfSentMsg->HeaderText = L"#";
			this->NufOfSentMsg->MinimumWidth = 6;
			this->NufOfSentMsg->Name = L"NufOfSentMsg";
			this->NufOfSentMsg->ReadOnly = true;
			this->NufOfSentMsg->Width = 50;
			// 
			// To
			// 
			this->To->HeaderText = L"To";
			this->To->MinimumWidth = 6;
			this->To->Name = L"To";
			this->To->Width = 125;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Date";
			this->Date->MinimumWidth = 6;
			this->Date->Name = L"Date";
			this->Date->Width = 125;
			// 
			// MessageSent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(586, 707);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->ViewDataSent);
			this->Name = L"MessageSent";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"SentMessage";
			this->Activated += gcnew System::EventHandler(this, &MessageSent::MessageSent_Activated);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataSent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void MessageSent_Activated(System::Object^ sender, System::EventArgs^ e) {

	IniMsg();
	int time_limit = 0;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_Sent));
	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStr(Recv_str, svrMsg);
	ViewDataSent->Rows->Clear();


	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{


		/////

		std::string msg = svrMsg;
		std::vector<std::pair<std::string, std::string>> messages;

		size_t startPos = 0;
		size_t delimiterPos;

		while ((delimiterPos = msg.find("*/", startPos)) != std::string::npos) {
			size_t nickStart = delimiterPos + 2;
			size_t nickEnd = msg.find(' ', nickStart);
			if (nickEnd == std::string::npos) {
				nickEnd = msg.length();
			}
			size_t messageStart = nickEnd + 1;
			//
					// Find the end of the message
			size_t nextDelimiterPos = msg.find("*/", messageStart);
			size_t messageEnd;
			//
			if (nextDelimiterPos != std::string::npos) {
				messageEnd = nextDelimiterPos - 1;
			}
			else {
				messageEnd = msg.length();
			}

			std::string id = msg.substr(nickStart, nickEnd - nickStart);
			std::string message = msg.substr(messageStart, messageEnd - messageStart);

			messages.push_back(std::make_pair(id, message));

			// Move the start position to the end of the current message
			startPos = messageEnd + 1;
		}
		// Output the parsed messages
		int count = 0;
		for (const auto& message : messages) {

			ViewDataSent->Rows->Add();
			ViewDataSent->Rows[count]->Cells["NufOfSentMsg"]->Value = System::Convert::ToString(count);
			System::String^ tempwho = msclr::interop::marshal_as<System::String^>(message.first);
			ViewDataSent->Rows[count]->Cells["To"]->Value = tempwho;
			System::String^ tempmsg = msclr::interop::marshal_as<System::String^>(message.second);
			ViewDataSent->Rows[count]->Cells["Date"]->Value = tempmsg;
			count++;
		}

	}
}
};
}
