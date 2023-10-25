#pragma once
#include <cliext/vector>


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


	private: System::Windows::Forms::Button^ btnAccept;
	private: System::Windows::Forms::Button^ btnReject;

	protected:




	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::DataGridView^ ViewResponseList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NumOfList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FromWho;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ReqMsg;











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
			this->btnAccept = (gcnew System::Windows::Forms::Button());
			this->btnReject = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->ViewResponseList = (gcnew System::Windows::Forms::DataGridView());
			this->NumOfList = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FromWho = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ReqMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewResponseList))->BeginInit();
			this->SuspendLayout();
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
			this->btnAccept->Location = System::Drawing::Point(763, 116);
			this->btnAccept->Name = L"btnAccept";
			this->btnAccept->Size = System::Drawing::Size(147, 53);
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
			this->btnReject->Location = System::Drawing::Point(763, 193);
			this->btnReject->Name = L"btnReject";
			this->btnReject->Size = System::Drawing::Size(147, 58);
			this->btnReject->TabIndex = 3;
			this->btnReject->UseVisualStyleBackColor = false;
			this->btnReject->Click += gcnew System::EventHandler(this, &FriendResponse::btnReject_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 20));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(54, 54);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(115, 39);
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
			this->btnClose->Location = System::Drawing::Point(601, 531);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(147, 50);
			this->btnClose->TabIndex = 13;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &FriendResponse::btnClose_Click);
			// 
			// ViewResponseList
			// 
			this->ViewResponseList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewResponseList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->NumOfList,
					this->FromWho, this->ReqMsg
			});
			this->ViewResponseList->Location = System::Drawing::Point(61, 116);
			this->ViewResponseList->Name = L"ViewResponseList";
			this->ViewResponseList->RowHeadersWidth = 51;
			this->ViewResponseList->RowTemplate->Height = 27;
			this->ViewResponseList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewResponseList->Size = System::Drawing::Size(662, 343);
			this->ViewResponseList->TabIndex = 14;
			// 
			// NumOfList
			// 
			this->NumOfList->Frozen = true;
			this->NumOfList->HeaderText = L"#";
			this->NumOfList->MinimumWidth = 8;
			this->NumOfList->Name = L"NumOfList";
			this->NumOfList->ReadOnly = true;
			this->NumOfList->Width = 50;
			// 
			// FromWho
			// 
			this->FromWho->Frozen = true;
			this->FromWho->HeaderText = L"From.";
			this->FromWho->MinimumWidth = 6;
			this->FromWho->Name = L"FromWho";
			this->FromWho->ReadOnly = true;
			this->FromWho->Width = 125;
			// 
			// ReqMsg
			// 
			this->ReqMsg->Frozen = true;
			this->ReqMsg->HeaderText = L"Req Message";
			this->ReqMsg->MinimumWidth = 6;
			this->ReqMsg->Name = L"ReqMsg";
			this->ReqMsg->ReadOnly = true;
			this->ReqMsg->Width = 125;
			// 
			// FriendResponse
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(939, 623);
			this->Controls->Add(this->ViewResponseList);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnReject);
			this->Controls->Add(this->btnAccept);
			this->Name = L"FriendResponse";
			this->Text = L"FriendResponse";
			this->Activated += gcnew System::EventHandler(this, &FriendResponse::FriendResponse_Visible);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewResponseList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void FriendResponse_Visible(System::Object^ sender, System::EventArgs^ e) {
	
	IniMsg();
	int time_limit = 0;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Response_List));
	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();
	
	
	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStr(Recv_str, svrMsg);
	ViewResponseList->Rows->Clear();
	
	
	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{

		ViewResponseList->Rows->Clear();
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

			ViewResponseList->Rows->Add();
			ViewResponseList->Rows[count]->Cells["NumOfList"]->Value = System::Convert::ToString(count);
			System::String^ tempwho = msclr::interop::marshal_as<System::String^>(message.first);
			ViewResponseList->Rows[count]->Cells["FromWho"]->Value = tempwho;
			System::String^ tempmsg = msclr::interop::marshal_as<System::String^>(message.second);
			ViewResponseList->Rows[count]->Cells["ReqMsg"]->Value = tempmsg;
			count++;
		}

	}


}
private: System::Void btnAccept_Click(System::Object^ sender, System::EventArgs^ e) {

	btnAccept->NotifyDefault(false);
	IniMsg();

	String^ tmptxt_1;
	// 선택한 행의 정보를 저장할 DataGridViewRow 객체를 선언합니다.
	DataGridViewRow^ selectedRow = nullptr;

	if (ViewResponseList->SelectedRows->Count > 0) {
		// 하나 이상의 행이 선택되었을 때 첫 번째 선택된 행을 가져옵니다.
		selectedRow = ViewResponseList->SelectedRows[0];
		tmptxt_1 = safe_cast<String^>(selectedRow->Cells[1]->Value);
		// 선택한 행의 데이터를 처리합니다.
		// 예를 들어, 특정 열의 데이터를 얻기 위해 selectedRow->Cells[columnIndex]->Value를 사용할 수 있습니다.
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("친구신청을 허가할사람을 선택해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

		//// Server에 ID / PW를 보내기함수
		int time_limit = 0;


		std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
		std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Accept));

		std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
		const char* buffer = _Index_Str_Result.c_str();
		send(client_sock, buffer, strlen(buffer), 0);
		Sleep(100);
		DivStr(Recv_str, svrMsg);

		while (1)
		{
			if (isTrue == trueStr)// server 에서 오케이받는 함수
			{
				System::Windows::Forms::MessageBox::Show("친구 신청을 완료했습니다.", "친구신청", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			else if (isTrue == falseStr) //  server에서 다른값보내면
			{
				System::Windows::Forms::MessageBox::Show("에러가 발생했습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

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

	btnReject->NotifyDefault(false);
	IniMsg();

	String^ tmptxt_1;
	// 선택한 행의 정보를 저장할 DataGridViewRow 객체를 선언합니다.
	DataGridViewRow^ selectedRow = nullptr;

	if (ViewResponseList->SelectedRows->Count > 0) {
		// 하나 이상의 행이 선택되었을 때 첫 번째 선택된 행을 가져옵니다.
		selectedRow = ViewResponseList->SelectedRows[0];
		tmptxt_1 = safe_cast<String^>(selectedRow->Cells[1]->Value);
		// 선택한 행의 데이터를 처리합니다.
		// 예를 들어, 특정 열의 데이터를 얻기 위해 selectedRow->Cells[columnIndex]->Value를 사용할 수 있습니다.
	}
	else
	{
		System::Windows::Forms::MessageBox::Show("친구신청을 거절할 사람을 선택해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	//// Server에 ID / PW를 보내기함수
	int time_limit = 0;


	std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Request_Decline));

	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStr(Recv_str, svrMsg);

	while (1)
	{
		if (isTrue == trueStr)// server 에서 오케이받는 함수
		{
			System::Windows::Forms::MessageBox::Show("친구 신청을 거절하였습니다.", "친구신청", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}
		else if (isTrue == falseStr) //  server에서 다른값보내면
		{
			System::Windows::Forms::MessageBox::Show("에러가 발생했습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

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
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Owner->Activate();
	this->Close();
	
}
};
}
