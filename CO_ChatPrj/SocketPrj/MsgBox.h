#pragma once

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
	/// MsgBox에 대한 요약입니다.
	/// </summary>
	public ref class MsgBox : public System::Windows::Forms::Form
	{
	public:
		MsgBox(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		MsgBox(MyFunction^ my)
		{
			InitializeComponent();
			this->_my = my;
			
			this->_my->MyEvent += gcnew Action<String^>(this, &MsgBox::ReceivedMsg);
			

		}
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnDelete_R;
	private: System::Windows::Forms::Button^ btnDelete_U;
	private: System::Windows::Forms::Button^ btnRead;
	private: System::Windows::Forms::TextBox^ txtBoxMsg;
	private: System::Windows::Forms::DataGridView^ ViewRead;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfRead;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ R_From;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ R_Date;
	private: System::Windows::Forms::DataGridView^ ViewUnread;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfUnread;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ U_From;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ U_Date;

	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MsgBox()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MsgBox::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnDelete_R = (gcnew System::Windows::Forms::Button());
			this->btnDelete_U = (gcnew System::Windows::Forms::Button());
			this->btnRead = (gcnew System::Windows::Forms::Button());
			this->txtBoxMsg = (gcnew System::Windows::Forms::TextBox());
			this->ViewRead = (gcnew System::Windows::Forms::DataGridView());
			this->NumOfRead = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->R_From = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->R_Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ViewUnread = (gcnew System::Windows::Forms::DataGridView());
			this->NumOfUnread = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->U_From = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->U_Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRead))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewUnread))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(28, 442);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 55);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Read";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(28, 40);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(198, 55);
			this->label3->TabIndex = 20;
			this->label3->Text = L"Unread";
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
			this->btnClose->Location = System::Drawing::Point(969, 766);
			this->btnClose->Margin = System::Windows::Forms::Padding(2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(182, 48);
			this->btnClose->TabIndex = 15;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MsgBox::btnClose_Click);
			// 
			// btnDelete_R
			// 
			this->btnDelete_R->BackColor = System::Drawing::Color::Transparent;
			this->btnDelete_R->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDelete_R.BackgroundImage")));
			this->btnDelete_R->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDelete_R->FlatAppearance->BorderSize = 0;
			this->btnDelete_R->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnDelete_R->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnDelete_R->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete_R->Location = System::Drawing::Point(414, 752);
			this->btnDelete_R->Margin = System::Windows::Forms::Padding(2);
			this->btnDelete_R->Name = L"btnDelete_R";
			this->btnDelete_R->Size = System::Drawing::Size(136, 46);
			this->btnDelete_R->TabIndex = 16;
			this->btnDelete_R->UseVisualStyleBackColor = false;
			// 
			// btnDelete_U
			// 
			this->btnDelete_U->BackColor = System::Drawing::Color::Transparent;
			this->btnDelete_U->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDelete_U.BackgroundImage")));
			this->btnDelete_U->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDelete_U->FlatAppearance->BorderSize = 0;
			this->btnDelete_U->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnDelete_U->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnDelete_U->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete_U->Location = System::Drawing::Point(424, 374);
			this->btnDelete_U->Margin = System::Windows::Forms::Padding(2);
			this->btnDelete_U->Name = L"btnDelete_U";
			this->btnDelete_U->Size = System::Drawing::Size(136, 46);
			this->btnDelete_U->TabIndex = 17;
			this->btnDelete_U->UseVisualStyleBackColor = false;
			// 
			// btnRead
			// 
			this->btnRead->BackColor = System::Drawing::Color::Transparent;
			this->btnRead->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRead.BackgroundImage")));
			this->btnRead->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnRead->FlatAppearance->BorderSize = 0;
			this->btnRead->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnRead->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnRead->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRead->Location = System::Drawing::Point(268, 372);
			this->btnRead->Margin = System::Windows::Forms::Padding(2);
			this->btnRead->Name = L"btnRead";
			this->btnRead->Size = System::Drawing::Size(136, 53);
			this->btnRead->TabIndex = 18;
			this->btnRead->UseVisualStyleBackColor = false;
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(634, 104);
			this->txtBoxMsg->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(516, 641);
			this->txtBoxMsg->TabIndex = 14;
			// 
			// ViewRead
			// 
			this->ViewRead->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewRead->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NumOfRead, this->R_From,
					this->R_Date
			});
			this->ViewRead->Location = System::Drawing::Point(38, 500);
			this->ViewRead->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ViewRead->MultiSelect = false;
			this->ViewRead->Name = L"ViewRead";
			this->ViewRead->ReadOnly = true;
			this->ViewRead->RowHeadersWidth = 51;
			this->ViewRead->RowTemplate->Height = 27;
			this->ViewRead->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewRead->Size = System::Drawing::Size(522, 245);
			this->ViewRead->TabIndex = 13;
			// 
			// NumOfRead
			// 
			this->NumOfRead->HeaderText = L"#";
			this->NumOfRead->MinimumWidth = 6;
			this->NumOfRead->Name = L"NumOfRead";
			this->NumOfRead->ReadOnly = true;
			this->NumOfRead->Width = 125;
			// 
			// R_From
			// 
			this->R_From->HeaderText = L"From";
			this->R_From->MinimumWidth = 6;
			this->R_From->Name = L"R_From";
			this->R_From->ReadOnly = true;
			this->R_From->Width = 125;
			// 
			// R_Date
			// 
			this->R_Date->HeaderText = L"Date";
			this->R_Date->MinimumWidth = 6;
			this->R_Date->Name = L"R_Date";
			this->R_Date->ReadOnly = true;
			this->R_Date->Width = 125;
			// 
			// ViewUnread
			// 
			this->ViewUnread->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewUnread->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NumOfUnread,
					this->U_From, this->U_Date
			});
			this->ViewUnread->Location = System::Drawing::Point(38, 104);
			this->ViewUnread->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->ViewUnread->MultiSelect = false;
			this->ViewUnread->Name = L"ViewUnread";
			this->ViewUnread->ReadOnly = true;
			this->ViewUnread->RowHeadersWidth = 51;
			this->ViewUnread->RowTemplate->Height = 27;
			this->ViewUnread->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewUnread->Size = System::Drawing::Size(522, 245);
			this->ViewUnread->TabIndex = 12;
			// 
			// NumOfUnread
			// 
			this->NumOfUnread->HeaderText = L"#";
			this->NumOfUnread->MinimumWidth = 6;
			this->NumOfUnread->Name = L"NumOfUnread";
			this->NumOfUnread->ReadOnly = true;
			this->NumOfUnread->Width = 125;
			// 
			// U_From
			// 
			this->U_From->HeaderText = L"From";
			this->U_From->MinimumWidth = 6;
			this->U_From->Name = L"U_From";
			this->U_From->ReadOnly = true;
			this->U_From->Width = 125;
			// 
			// U_Date
			// 
			this->U_Date->HeaderText = L"Date";
			this->U_Date->MinimumWidth = 6;
			this->U_Date->Name = L"U_Date";
			this->U_Date->ReadOnly = true;
			this->U_Date->Width = 125;
			// 
			// MsgBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1275, 869);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete_R);
			this->Controls->Add(this->btnDelete_U);
			this->Controls->Add(this->btnRead);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->ViewRead);
			this->Controls->Add(this->ViewUnread);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"MsgBox";
			this->Text = L"MsgBox";
			this->Activated += gcnew System::EventHandler(this, &MsgBox::MsgBox_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MsgBox::MsgBox_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRead))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewUnread))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MsgBox_Activated(System::Object^ sender, System::EventArgs^ e) {

		ViewRead->Rows->Clear();
		ViewUnread->Rows->Clear();

		String^ buffer = _my->s_(e_message_UGiven_list);
		_my->SendMessage(buffer);
		
		Sleep(100);
		
		buffer = _my->s_(e_message_RGiven_list);
		_my->SendMessage(buffer);

	}

	public: String^ temp;


	public: void SendMessageForm(int index)
		{

			switch (index)
			{
				// 나중에 이름 바꾸자
			case e_message_UGiven_list:
			{
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
		case e_message_UGiven_list:
		{
			if (isTrue == "true")
			{
				this->Invoke(gcnew Action<String^>(this, &MsgBox::UpdateUnread), message);
				
			}
			else
			{
				// 못했을 경우
			}
			break;

		}
		case e_message_RGiven_list:
		{
			if (isTrue == "true")
			{
				this->Invoke(gcnew Action<String^>(this, &MsgBox::UpdateRead), message);
			}
			else
			{
			}
			break;
		}
		case e_edit_Confirm:
		{
			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("Update Profile Success", "Edit Porofile", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}

		}

	}

	public: System::Void UpdateUnread(String^ message)
	{
		// msg가 어떻게 오는지 확인해야돼
		
		//std::string msg = svrMsg;
		//std::vector<std::pair<std::string, std::string>> messagesR;

		//size_t startPos = 0;
		//size_t delimiterPos;

		//while ((delimiterPos = msg.find("*/", startPos)) != std::string::npos) {
		//	size_t nickStart = delimiterPos + 2;
		//	size_t nickEnd = msg.find(' ', nickStart);
		//	if (nickEnd == std::string::npos) {
		//		nickEnd = msg.length();
		//	}
		//	size_t messageStart = nickEnd + 1;
		//	//
		//			// Find the end of the message
		//	size_t nextDelimiterPos = msg.find("*/", messageStart);
		//	size_t messageEnd;
		//	//
		//	if (nextDelimiterPos != std::string::npos) {
		//		messageEnd = nextDelimiterPos - 1;
		//	}
		//	else {
		//		messageEnd = msg.length();
		//	}

		//	std::string id = msg.substr(nickStart, nickEnd - nickStart);
		//	std::string message = msg.substr(messageStart, messageEnd - messageStart);

		//	messagesR.push_back(std::make_pair(id, message));

		//	// Move the start position to the end of the current message
		//	startPos = messageEnd + 1;
		//}
		//// Output the parsed messages
		//int count = 0;
		//for (const auto& message : messagesR) {

		//	ViewUnread->Rows->Add();
		//	ViewUnread->Rows[count]->Cells["NumOfUnread"]->Value = System::Convert::ToString(count);
		//	System::String^ tempwho = msclr::interop::marshal_as<System::String^>(message.first);
		//	ViewUnread->Rows[count]->Cells["U_From"]->Value = tempwho;
		//	System::String^ tempmsg = msclr::interop::marshal_as<System::String^>(message.second);
		//	ViewUnread->Rows[count]->Cells["U_Date"]->Value = tempmsg;
		//	count++;
		//}

	}

	private: System::Void UpdateRead(String^ message)
	{
	
		//// 어떻게 메세지가 오는지 집에서 확인해야돼.

		//std::string msg = svrMsg;
		//std::vector<std::pair<std::string, std::string>> messagesR;

		//size_t startPos = 0;
		//size_t delimiterPos;

		//while ((delimiterPos = msg.find("*/", startPos)) != std::string::npos) {
		//	size_t nickStart = delimiterPos + 2;
		//	size_t nickEnd = msg.find(' ', nickStart);
		//	if (nickEnd == std::string::npos) {
		//		nickEnd = msg.length();
		//	}
		//	size_t messageStart = nickEnd + 1;
		//	//
		//			// Find the end of the message
		//	size_t nextDelimiterPos = msg.find("*/", messageStart);
		//	size_t messageEnd;
		//	//
		//	if (nextDelimiterPos != std::string::npos) {
		//		messageEnd = nextDelimiterPos - 1;
		//	}
		//	else {
		//		messageEnd = msg.length();
		//	}

		//	std::string id = msg.substr(nickStart, nickEnd - nickStart);
		//	std::string message = msg.substr(messageStart, messageEnd - messageStart);

		//	messagesR.push_back(std::make_pair(id, message));

		//	// Move the start position to the end of the current message
		//	startPos = messageEnd + 1;
		//}
		//// Output the parsed messages
		//int count = 0;
		//for (const auto& message : messagesR) {

		//	ViewRead->Rows->Add();
		//	ViewRead->Rows[count]->Cells["NumOfRead"]->Value = System::Convert::ToString(count);
		//	System::String^ tempwho = msclr::interop::marshal_as<System::String^>(message.first);
		//	ViewRead->Rows[count]->Cells["R_From"]->Value = tempwho;
		//	System::String^ tempmsg = msclr::interop::marshal_as<System::String^>(message.second);
		//	ViewRead->Rows[count]->Cells["R_Date"]->Value = tempmsg;
		//	count++;
		//}

	}






	
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void MsgBox_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Show();
	this->Owner->Activate();
}
};
}
