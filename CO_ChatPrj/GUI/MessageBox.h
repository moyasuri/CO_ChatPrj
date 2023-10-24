#pragma once

#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "UsageClient.h"
#include <vector>
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
	/// Message_Box에 대한 요약입니다.
	/// </summary>
	public ref class MessageBox : public System::Windows::Forms::Form
	{
	public:
		MessageBox(void)
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
		~MessageBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ViewUnread;
	private: System::Windows::Forms::DataGridView^ ViewRead;
	protected:

	protected:

	protected:








	private: System::Windows::Forms::TextBox^ txtBoxMsg;





	private: System::Windows::Forms::Button^ btnRead;
	private: System::Windows::Forms::Button^ btnDelete_U;
	private: System::Windows::Forms::Button^ btnDelete_R;



	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfUnread;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ U_From;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ U_Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfRead;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ R_From;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ R_Date;














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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MessageBox::typeid));
			this->ViewUnread = (gcnew System::Windows::Forms::DataGridView());
			this->NumOfUnread = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->U_From = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->U_Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ViewRead = (gcnew System::Windows::Forms::DataGridView());
			this->NumOfRead = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->R_From = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->R_Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtBoxMsg = (gcnew System::Windows::Forms::TextBox());
			this->btnRead = (gcnew System::Windows::Forms::Button());
			this->btnDelete_U = (gcnew System::Windows::Forms::Button());
			this->btnDelete_R = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewUnread))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRead))->BeginInit();
			this->SuspendLayout();
			// 
			// ViewUnread
			// 
			this->ViewUnread->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewUnread->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NumOfUnread,
					this->U_From, this->U_Date
			});
			this->ViewUnread->Location = System::Drawing::Point(56, 89);
			this->ViewUnread->MultiSelect = false;
			this->ViewUnread->Name = L"ViewUnread";
			this->ViewUnread->ReadOnly = true;
			this->ViewUnread->RowHeadersWidth = 51;
			this->ViewUnread->RowTemplate->Height = 27;
			this->ViewUnread->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewUnread->Size = System::Drawing::Size(418, 204);
			this->ViewUnread->TabIndex = 2;
			this->ViewUnread->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MessageBox::ViewUnread_CellClick);
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
			// ViewRead
			// 
			this->ViewRead->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewRead->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NumOfRead, this->R_From,
					this->R_Date
			});
			this->ViewRead->Location = System::Drawing::Point(56, 419);
			this->ViewRead->MultiSelect = false;
			this->ViewRead->Name = L"ViewRead";
			this->ViewRead->ReadOnly = true;
			this->ViewRead->RowHeadersWidth = 51;
			this->ViewRead->RowTemplate->Height = 27;
			this->ViewRead->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewRead->Size = System::Drawing::Size(418, 204);
			this->ViewRead->TabIndex = 4;
			this->ViewRead->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MessageBox::ViewRead_CellClick);
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
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(533, 89);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(414, 535);
			this->txtBoxMsg->TabIndex = 8;
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
			this->btnRead->Location = System::Drawing::Point(240, 312);
			this->btnRead->Margin = System::Windows::Forms::Padding(2);
			this->btnRead->Name = L"btnRead";
			this->btnRead->Size = System::Drawing::Size(109, 44);
			this->btnRead->TabIndex = 9;
			this->btnRead->UseVisualStyleBackColor = false;
			this->btnRead->Click += gcnew System::EventHandler(this, &MessageBox::btnRead_Click);
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
			this->btnDelete_U->Location = System::Drawing::Point(365, 314);
			this->btnDelete_U->Margin = System::Windows::Forms::Padding(2);
			this->btnDelete_U->Name = L"btnDelete_U";
			this->btnDelete_U->Size = System::Drawing::Size(109, 38);
			this->btnDelete_U->TabIndex = 9;
			this->btnDelete_U->UseVisualStyleBackColor = false;
			this->btnDelete_U->Click += gcnew System::EventHandler(this, &MessageBox::btnDelete_U_Click);
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
			this->btnDelete_R->Location = System::Drawing::Point(357, 629);
			this->btnDelete_R->Margin = System::Windows::Forms::Padding(2);
			this->btnDelete_R->Name = L"btnDelete_R";
			this->btnDelete_R->Size = System::Drawing::Size(109, 38);
			this->btnDelete_R->TabIndex = 9;
			this->btnDelete_R->UseVisualStyleBackColor = false;
			this->btnDelete_R->Click += gcnew System::EventHandler(this, &MessageBox::btnDelete_R_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(48, 35);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(198, 55);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Unread";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->label1->Location = System::Drawing::Point(48, 370);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 55);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Read";
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
			this->btnClose->Location = System::Drawing::Point(801, 640);
			this->btnClose->Margin = System::Windows::Forms::Padding(2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(146, 40);
			this->btnClose->TabIndex = 9;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &MessageBox::btnClose_Click);
			// 
			// MessageBox
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(982, 696);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete_R);
			this->Controls->Add(this->btnDelete_U);
			this->Controls->Add(this->btnRead);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->ViewRead);
			this->Controls->Add(this->ViewUnread);
			this->DoubleBuffered = true;
			this->Name = L"MessageBox";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Message_Box";
			this->Activated += gcnew System::EventHandler(this, &MessageBox::MessageBox_Activated);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewUnread))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRead))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Owner->Activate();
	this->Close();

}
private: System::Void MessageBox_Activated(System::Object^ sender, System::EventArgs^ e) {



	IniMsg();
	ViewRead->Rows->Clear();
	ViewUnread->Rows->Clear();

	int time_limit = 0;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_UGiven_list));
	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();




	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStr(Recv_str, svrMsg);
	


	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{


		std::string msg = svrMsg;
		std::vector<std::pair<std::string, std::string>> messagesR;

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

			messagesR.push_back(std::make_pair(id, message));

			// Move the start position to the end of the current message
			startPos = messageEnd + 1;
		}
		// Output the parsed messages
		int count = 0;
		for (const auto& message : messagesR) {

			ViewUnread->Rows->Add();
			ViewUnread->Rows[count]->Cells["NumOfUnread"]->Value = System::Convert::ToString(count);
			System::String^ tempwho = msclr::interop::marshal_as<System::String^>(message.first);
			ViewUnread->Rows[count]->Cells["U_From"]->Value = tempwho;
			System::String^ tempmsg = msclr::interop::marshal_as<System::String^>(message.second);
			ViewUnread->Rows[count]->Cells["U_Date"]->Value = tempmsg;
			count++;
		}

	}

	IniMsg();

	_Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_RGiven_list));
	_Index_Str_Result = _Index_Str;
	buffer = _Index_Str_Result.c_str();

	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStr(Recv_str, svrMsg);
	
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{


		std::string msg = svrMsg;
		std::vector<std::pair<std::string, std::string>> messagesR;

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

			messagesR.push_back(std::make_pair(id, message));

			// Move the start position to the end of the current message
			startPos = messageEnd + 1;
		}
		// Output the parsed messages
		int count = 0;
		for (const auto& message : messagesR) {

			ViewRead->Rows->Add();
			ViewRead->Rows[count]->Cells["NumOfRead"]->Value = System::Convert::ToString(count);
			System::String^ tempwho = msclr::interop::marshal_as<System::String^>(message.first);
			ViewRead->Rows[count]->Cells["R_From"]->Value = tempwho;
			System::String^ tempmsg = msclr::interop::marshal_as<System::String^>(message.second);
			ViewRead->Rows[count]->Cells["R_Date"]->Value = tempmsg;
			count++;
		}

	}


}
private: System::Void ViewUnread_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

	IniMsg();
	int time_limit = 0;
	std::string tmptxt_1_;



	if (ViewUnread->SelectedRows->Count > 0) {
		// 선택한 행의 인덱스를 가져옵니다.
		int selectedRowIndex = ViewUnread->SelectedRows[0]->Index;

		// 1열, 2열, 3열의 데이터를 가져옵니다.
		System::Object^ column1ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["NumOfUnread"]->Value;
		System::Object^ column2ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["U_From"]->Value;
		System::Object^ column3ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["U_Date"]->Value;

		// null 체크
		if (column1ValueObj != nullptr && column2ValueObj != nullptr && column3ValueObj != nullptr) {
			System::String^ column1Value = column1ValueObj->ToString();
			System::String^ column2Value = column2ValueObj->ToString();
			System::String^ column3Value = column3ValueObj->ToString();

			tmptxt_1_ = msclr::interop::marshal_as<std::string>(column2Value) + delim + msclr::interop::marshal_as<std::string>(column3Value);
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


	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_UGiven_msg));
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);
	txtBoxMsg->Clear();

	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{

		System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
		txtBoxMsg->Text = clrString;

	}

	else if (isTrue == falseStr) //  server에서 다른값보내면 그럴리없겟지만
	{
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
private: System::Void ViewRead_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	IniMsg();
	int time_limit = 0;
	std::string tmptxt_1_;



	if (ViewRead->SelectedRows->Count > 0) {
		// 선택한 행의 인덱스를 가져옵니다.
		int selectedRowIndex = ViewRead->SelectedRows[0]->Index;

		// 1열, 2열, 3열의 데이터를 가져옵니다.
		System::Object^ column1ValueObj = ViewRead->Rows[selectedRowIndex]->Cells["NumOfRead"]->Value;
		System::Object^ column2ValueObj = ViewRead->Rows[selectedRowIndex]->Cells["R_From"]->Value;
		System::Object^ column3ValueObj = ViewRead->Rows[selectedRowIndex]->Cells["R_Date"]->Value;

		// null 체크
		if (column1ValueObj != nullptr && column2ValueObj != nullptr && column3ValueObj != nullptr) {
			System::String^ column1Value = column1ValueObj->ToString();
			System::String^ column2Value = column2ValueObj->ToString();
			System::String^ column3Value = column3ValueObj->ToString();

			tmptxt_1_ = msclr::interop::marshal_as<std::string>(column2Value) + delim + msclr::interop::marshal_as<std::string>(column3Value);
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


	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_RGiven_msg));
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);
	txtBoxMsg->Clear();

	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{

		System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
		txtBoxMsg->Text = clrString;

	}

	else if (isTrue == falseStr) //  server에서 다른값보내면 그럴리없겟지만
	{
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
private: System::Void btnDelete_U_Click(System::Object^ sender, System::EventArgs^ e) {
	IniMsg();
	int time_limit = 0;
	std::string tmptxt_1_;



	if (ViewUnread->SelectedRows->Count > 0) {
		// 선택한 행의 인덱스를 가져옵니다.
		int selectedRowIndex = ViewUnread->SelectedRows[0]->Index;

		// 1열, 2열, 3열의 데이터를 가져옵니다.
		System::Object^ column1ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["NumOfUnread"]->Value;
		System::Object^ column2ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["U_From"]->Value;
		System::Object^ column3ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["U_Date"]->Value;

		// null 체크
		if (column1ValueObj != nullptr && column2ValueObj != nullptr && column3ValueObj != nullptr) {
			System::String^ column1Value = column1ValueObj->ToString();
			System::String^ column2Value = column2ValueObj->ToString();
			System::String^ column3Value = column3ValueObj->ToString();

			tmptxt_1_ = msclr::interop::marshal_as<std::string>(column2Value) + delim + msclr::interop::marshal_as<std::string>(column3Value);
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


	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_UGiven_msg_delete));
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_ + "\n";
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);
	txtBoxMsg->Clear();

	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{

		System::Windows::Forms::MessageBox::Show("삭제가 완료되었습니다", "삭제", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	else if (isTrue == falseStr) //  server에서 다른값보내면 그럴리없겟지만
	{
		System::Windows::Forms::MessageBox::Show("삭제 실패", "경고", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
private: System::Void btnRead_Click(System::Object^ sender, System::EventArgs^ e) {

	IniMsg();
	int time_limit = 0;
	std::string tmptxt_1_;



	if (ViewUnread->SelectedRows->Count > 0) {
		// 선택한 행의 인덱스를 가져옵니다.
		int selectedRowIndex = ViewUnread->SelectedRows[0]->Index;

		// 1열, 2열, 3열의 데이터를 가져옵니다.
		System::Object^ column1ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["NumOfUnread"]->Value;
		System::Object^ column2ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["U_From"]->Value;
		System::Object^ column3ValueObj = ViewUnread->Rows[selectedRowIndex]->Cells["U_Date"]->Value;

		// null 체크
		if (column1ValueObj != nullptr && column2ValueObj != nullptr && column3ValueObj != nullptr) {
			System::String^ column1Value = column1ValueObj->ToString();
			System::String^ column2Value = column2ValueObj->ToString();
			System::String^ column3Value = column3ValueObj->ToString();

			tmptxt_1_ = msclr::interop::marshal_as<std::string>(column2Value) + delim + msclr::interop::marshal_as<std::string>(column3Value);
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


	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_UGiven_Read));
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_ + "\n";
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);
	txtBoxMsg->Clear();

	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{

		System::Windows::Forms::MessageBox::Show("읽음 처리되었습니다", "메세지 읽기", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	else if (isTrue == falseStr) //  server에서 다른값보내면 그럴리없겟지만
	{
		System::Windows::Forms::MessageBox::Show("삭제 실패", "경고", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
private: System::Void btnDelete_R_Click(System::Object^ sender, System::EventArgs^ e) {
	IniMsg();
	int time_limit = 0;
	std::string tmptxt_1_;



	if (ViewRead->SelectedRows->Count > 0) {
		// 선택한 행의 인덱스를 가져옵니다.
		int selectedRowIndex = ViewRead->SelectedRows[0]->Index;

		// 1열, 2열, 3열의 데이터를 가져옵니다.
		System::Object^ column1ValueObj = ViewRead->Rows[selectedRowIndex]->Cells["NumOfRead"]->Value;
		System::Object^ column2ValueObj = ViewRead->Rows[selectedRowIndex]->Cells["R_From"]->Value;
		System::Object^ column3ValueObj = ViewRead->Rows[selectedRowIndex]->Cells["R_Date"]->Value;

		// null 체크
		if (column1ValueObj != nullptr && column2ValueObj != nullptr && column3ValueObj != nullptr) {
			System::String^ column1Value = column1ValueObj->ToString();
			System::String^ column2Value = column2ValueObj->ToString();
			System::String^ column3Value = column3ValueObj->ToString();

			tmptxt_1_ = msclr::interop::marshal_as<std::string>(column2Value) + delim + msclr::interop::marshal_as<std::string>(column3Value);
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


	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_RGiven_msg_delete));
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_ + "\n";
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);
	txtBoxMsg->Clear();

	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{

		System::Windows::Forms::MessageBox::Show("삭제가 완료되었습니다", "삭제", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}
	else if (isTrue == falseStr) //  server에서 다른값보내면 그럴리없겟지만
	{
		System::Windows::Forms::MessageBox::Show("삭제 실패", "경고", MessageBoxButtons::OK, MessageBoxIcon::Information);
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

};
}
