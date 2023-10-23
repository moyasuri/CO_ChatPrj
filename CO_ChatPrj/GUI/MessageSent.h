#pragma once

#include <vector>
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
			ViewDataSent->ClearSelection();
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfSentMsg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ To;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Status;












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
			this->NumOfSentMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->To = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewDataSent))->BeginInit();
			this->SuspendLayout();
			// 
			// ViewDataSent
			// 
			this->ViewDataSent->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewDataSent->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->NumOfSentMsg,
					this->To, this->Date, this->Status
			});
			this->ViewDataSent->Location = System::Drawing::Point(60, 78);
			this->ViewDataSent->Margin = System::Windows::Forms::Padding(4);
			this->ViewDataSent->MultiSelect = false;
			this->ViewDataSent->Name = L"ViewDataSent";
			this->ViewDataSent->RowHeadersWidth = 51;
			this->ViewDataSent->RowTemplate->Height = 27;
			this->ViewDataSent->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewDataSent->Size = System::Drawing::Size(569, 240);
			this->ViewDataSent->TabIndex = 3;
			this->ViewDataSent->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MessageSent::ViewDataSent_CellClick);
			// 
			// txtBoxMsg
			// 
			this->txtBoxMsg->Location = System::Drawing::Point(60, 434);
			this->txtBoxMsg->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxMsg->Multiline = true;
			this->txtBoxMsg->Name = L"txtBoxMsg";
			this->txtBoxMsg->Size = System::Drawing::Size(568, 315);
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
			this->btnDelete->Location = System::Drawing::Point(452, 334);
			this->btnDelete->Margin = System::Windows::Forms::Padding(4);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(176, 60);
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
			this->btnClose->Location = System::Drawing::Point(452, 770);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(176, 60);
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
			this->label2->Location = System::Drawing::Point(53, 371);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(194, 46);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Message";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->label1->ForeColor = System::Drawing::Color::DarkSlateGray;
			this->label1->Location = System::Drawing::Point(53, 14);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 46);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Sent";
			// 
			// NumOfSentMsg
			// 
			this->NumOfSentMsg->HeaderText = L"#";
			this->NumOfSentMsg->MinimumWidth = 6;
			this->NumOfSentMsg->Name = L"NumOfSentMsg";
			this->NumOfSentMsg->Width = 50;
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
			this->AutoScaleDimensions = System::Drawing::SizeF(144, 144);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(703, 848);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->txtBoxMsg);
			this->Controls->Add(this->ViewDataSent);
			this->Margin = System::Windows::Forms::Padding(4);
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

		std::vector<std::string> ids;
		std::vector<int> indexes;
		std::vector<std::string> messages;




		std::istringstream iss(svrMsg);
		std::string line;

		while (std::getline(iss, line, '\n')) {
			size_t idStart = line.find("*/");
			size_t idEnd = line.find(' ', idStart + 2);
			size_t indexStart = idEnd;
			size_t indexEnd = line.find(' ', indexStart + 1);
			size_t messageStart = indexEnd;

			if (idStart != std::string::npos && idEnd != std::string::npos &&
				indexStart != std::string::npos && indexEnd != std::string::npos) {
				ids.push_back(line.substr(idStart + 2, idEnd - idStart - 2));
				indexes.push_back( std::stoi(line.substr(indexStart, indexEnd - indexStart)));
				messages.push_back(line.substr(messageStart + 1));

			}
		}



		for (size_t i = 0; i < ids.size(); ++i)
		{

		
			ViewDataSent->Rows->Add();
			ViewDataSent->Rows[i]->Cells["NumOfSentMsg"]->Value = System::Convert::ToString(i);

			System::String^ tempwho = msclr::interop::marshal_as<System::String^>(ids[i]);
			ViewDataSent->Rows[i]->Cells["To"]->Value = tempwho;

			System::String^ tempmsg = msclr::interop::marshal_as<System::String^>(messages[i]);
			ViewDataSent->Rows[i]->Cells["Date"]->Value = tempmsg;

			System::String^ tempsts;
			if (indexes[i] == 0 || indexes[i] == 2)
			{
				tempsts = msclr::interop::marshal_as < System::String^>("Unread");
			}
			else
			{
				tempsts = msclr::interop::marshal_as < System::String^>("Read");
			}
			ViewDataSent->Rows[i]->Cells["Status"]->Value = tempsts;
		}

	}
}
private: System::Void ViewDataSent_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	IniMsg();
	int time_limit = 0;
	std::string tmptxt_1_;

	

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


	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_message_Sent_msg));
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
		return;
		
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


};
}
