﻿#pragma once
#include "enum.h"
#include "MyFunction.h"

namespace SocketPrj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MessageSent에 대한 요약입니다.
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
		MessageSent(MyFunction^ my)
		{
			InitializeComponent();
			this->_my = my;
			this->_my->MyEvent += gcnew Action<String^>(this, &MessageSent::ReceivedMsg);

		}
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::TextBox^ txtBoxMsg;
	private: System::Windows::Forms::DataGridView^ ViewDataSent;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfSentMsg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ To;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;

	private: MyFunction^ _my;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->txtBoxMsg = (gcnew System::Windows::Forms::TextBox());
			this->ViewDataSent = (gcnew System::Windows::Forms::DataGridView());
			this->NumOfSentMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->To = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataSent))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->label1->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label1->Location = System::Drawing::Point(30, 18);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 46);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Sent";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->label2->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label2->Location = System::Drawing::Point(30, 374);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(194, 46);
			this->label2->TabIndex = 17;
			this->label2->Text = L"Message";
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
			this->btnClose->Location = System::Drawing::Point(710, 778);
			this->btnClose->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(184, 60);
			this->btnClose->TabIndex = 14;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MessageSent::btnClose_Click);
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
			this->btnDelete->Location = System::Drawing::Point(710, 344);
			this->btnDelete->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(184, 60);
			this->btnDelete->TabIndex = 15;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &MessageSent::btnDelete_Click);
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(38, 438);
			this->txtBoxMsg->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->ReadOnly = true;
			this->txtBoxMsg->Size = System::Drawing::Size(855, 315);
			this->txtBoxMsg->TabIndex = 13;
			// 
			// ViewDataSent
			// 
			this->ViewDataSent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewDataSent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->NumOfSentMsg,
					this->To, this->Date, this->Status
			});
			this->ViewDataSent->Location = System::Drawing::Point(38, 82);
			this->ViewDataSent->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ViewDataSent->MultiSelect = false;
			this->ViewDataSent->Name = L"ViewDataSent";
			this->ViewDataSent->ReadOnly = true;
			this->ViewDataSent->RowHeadersWidth = 51;
			this->ViewDataSent->RowTemplate->Height = 27;
			this->ViewDataSent->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewDataSent->Size = System::Drawing::Size(856, 240);
			this->ViewDataSent->TabIndex = 12;
			// 
			// NumOfSentMsg
			// 
			this->NumOfSentMsg->HeaderText = L"#";
			this->NumOfSentMsg->MinimumWidth = 6;
			this->NumOfSentMsg->Name = L"NumOfSentMsg";
			this->NumOfSentMsg->ReadOnly = true;
			this->NumOfSentMsg->Width = 50;
			// 
			// To
			// 
			this->To->HeaderText = L"To";
			this->To->MinimumWidth = 6;
			this->To->Name = L"To";
			this->To->ReadOnly = true;
			this->To->Width = 125;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Date";
			this->Date->MinimumWidth = 6;
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			this->Date->Width = 125;
			// 
			// Status
			// 
			this->Status->HeaderText = L"Status";
			this->Status->MinimumWidth = 8;
			this->Status->Name = L"Status";
			this->Status->ReadOnly = true;
			this->Status->Width = 150;
			// 
			// MessageSent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(990, 845);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->ViewDataSent);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MessageSent";
			this->Text = L"MessageSent";
			this->Activated += gcnew System::EventHandler(this, &MessageSent::MessageSent_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MessageSent::MessageSent_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataSent))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	public: void SendMessageForm(int index)
			{

				switch (index)
				{
				case e_message_Delete:
				{
					String^ tmptxt_1="";

					if (ViewDataSent->SelectedRows->Count > 0) {
						// 선택한 행의 인덱스를 가져옵니다.
						int selectedRowIndex = ViewDataSent->SelectedRows[0]->Index;

						// 1열, 2열, 3열의 데이터를 가져옵니다.
						System::Object^ column1ValueObj = ViewDataSent->Rows[selectedRowIndex]->Cells["NumOfSentMsg"]->Value;
						System::Object^ column2ValueObj = ViewDataSent->Rows[selectedRowIndex]->Cells["To"]->Value;
						System::Object^ column3ValueObj = ViewDataSent->Rows[selectedRowIndex]->Cells["Date"]->Value;

						// null 체크
						if (column1ValueObj != nullptr && column2ValueObj != nullptr && column3ValueObj != nullptr) {
							System::String^ column1Value = column1ValueObj->ToString();
							System::String^ column2Value = column2ValueObj->ToString();
							System::String^ column3Value = column3ValueObj->ToString();

							tmptxt_1 =column2Value + " " + column3Value;
						}
						else {
							// 선택한 행의 하나 이상의 열이 null일 때 처리할 내용
							// 예를 들어, 오류 메시지 출력 또는 다른 작업을 수행할 수 있습니다.
							return;
						}
					}
					else {
						// 선택한 행이 없을 때 처리할 내용
						// 예를 들어, 오류 메시지 출력 또는 다른 작업을 수행할 수 있습니다.
						return;
					}


					if (!String::IsNullOrEmpty(tmptxt_1))
					{
						int t_index = e_id_find_ID;
						String^ buffer = t_index.ToString() + " " + tmptxt_1;
						_my->SendMessage(buffer);
					}
					else
					{
						// 비어 있다면 할 행동
						//MessageBox::Show("input ID / PW", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}
					break;
				}



				}

			}

	public: void UpdateMessage()
	{ 
		return;
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
		case e_message_Sent_list:
		{
			if (isTrue == "true")
			{
				
				ViewDataSent->Invoke(gcnew Action(this, &MessageSent::UpdateMessage));

				//while (std::getline(iss, line, '\n')) {
				//	size_t idStart = line.find("*/");
				//	size_t idEnd = line.find(' ', idStart + 2);
				//	size_t indexStart = idEnd;
				//	size_t indexEnd = line.find(' ', indexStart + 1);
				//	size_t messageStart = indexEnd;

				//	if (idStart != std::string::npos && idEnd != std::string::npos &&
				//		indexStart != std::string::npos && indexEnd != std::string::npos) {
				//		ids.push_back(line.substr(idStart + 2, idEnd - idStart - 2));
				//		indexes.push_back(std::stoi(line.substr(indexStart, indexEnd - indexStart)));
				//		messages.push_back(line.substr(messageStart + 1));

				//	}
				//}
			}
			else
			{
				// nothing to do
			}
			break;
		}
		case e_message_Delete:
		{
			if (isTrue == "true")
			{
				String^ msg = "PW : " + subString[2];
				System::Windows::Forms::MessageBox::Show(msg, "find pw", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("wrong information.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}

		}

	}

	private: System::Void MessageSent_Activated(System::Object^ sender, System::EventArgs^ e) {
		
		ViewDataSent->Rows->Clear();

		int t_index = e_message_Sent_list;
		String^ buffer = t_index.ToString();
		_my->SendMessage(buffer);

	}
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {

		SendMessageForm(e_message_Sent_msg_delete);
	}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void MessageSent_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Show();
	this->Owner->Activate();
}
};
}