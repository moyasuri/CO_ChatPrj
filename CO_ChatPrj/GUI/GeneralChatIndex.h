#pragma once
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>
#include "UsageClient.h"
#include <regex>
extern SOCKET client_sock;
extern std::string Recv_str;
#include "ServerChat.h"

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GeneralChatIndex에 대한 요약입니다.
	/// </summary>
	/// 

	public ref class GeneralChatIndex : public System::Windows::Forms::Form
	{
	private: System::Data::DataTable^ table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PrivateCheck;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CreatedDate;
		   ServerChat^ serverchatForm = nullptr;














	ref class RoomData
	{
	public:
		property System::String^ RoomName;
		property System::String^ PrivateCheck;
	};


	public: System::ComponentModel::BindingList<RoomData^>^ bindingList;

	public:
		GeneralChatIndex(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			//InitializeDataGridView();

			// BindingList를 사용하여 DataGridView 초기화
	/*		ViewRoomList->Rows->Add();
			ViewRoomList->Rows[0]->Cells["NumOfRoom"]->Value = 1;
			ViewRoomList->Rows[0]->Cells["RoomName"]->Value = "불타는 금요일 !";
			ViewRoomList->Rows[0]->Cells["PrivateCheck"]->Value = "Private";
			ViewRoomList->Rows->Add();

			ViewRoomList->Rows[1]->Cells["NumOfRoom"]->Value = 2;
			ViewRoomList->Rows[1]->Cells["RoomName"]->Value = "개발자 연봉상담";
			ViewRoomList->Rows[1]->Cells["PrivateCheck"]->Value = "Public";*/

		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~GeneralChatIndex()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxPW;
	protected:

	private: System::Windows::Forms::DataGridView^ ViewRoomList;
	private: System::Windows::Forms::Button^ btnJoin;
	private: System::Windows::Forms::Button^ btnClose;
	protected:















	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GeneralChatIndex::typeid));
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->ViewRoomList = (gcnew System::Windows::Forms::DataGridView());
			this->RoomIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RoomName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PrivateCheck = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CreatedDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnJoin = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->BeginInit();
			this->SuspendLayout();
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(822, 45);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(199, 28);
			this->txtBoxPW->TabIndex = 1;
			// 
			// ViewRoomList
			// 
			this->ViewRoomList->AllowUserToAddRows = false;
			this->ViewRoomList->AllowUserToDeleteRows = false;
			this->ViewRoomList->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ViewRoomList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewRoomList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->RoomIndex,
					this->RoomName, this->PrivateCheck, this->CreatedDate
			});
			this->ViewRoomList->Location = System::Drawing::Point(-15, 106);
			this->ViewRoomList->Margin = System::Windows::Forms::Padding(4);
			this->ViewRoomList->MultiSelect = false;
			this->ViewRoomList->Name = L"ViewRoomList";
			this->ViewRoomList->ReadOnly = true;
			this->ViewRoomList->RowHeadersWidth = 51;
			this->ViewRoomList->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->ViewRoomList->RowTemplate->Height = 27;
			this->ViewRoomList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewRoomList->Size = System::Drawing::Size(1808, 510);
			this->ViewRoomList->TabIndex = 3;
			// 
			// RoomIndex
			// 
			this->RoomIndex->Frozen = true;
			this->RoomIndex->HeaderText = L"#Index";
			this->RoomIndex->MinimumWidth = 8;
			this->RoomIndex->Name = L"RoomIndex";
			this->RoomIndex->ReadOnly = true;
			this->RoomIndex->Width = 150;
			// 
			// RoomName
			// 
			this->RoomName->Frozen = true;
			this->RoomName->HeaderText = L"Name";
			this->RoomName->MinimumWidth = 6;
			this->RoomName->Name = L"RoomName";
			this->RoomName->ReadOnly = true;
			this->RoomName->Width = 580;
			// 
			// PrivateCheck
			// 
			this->PrivateCheck->Frozen = true;
			this->PrivateCheck->HeaderText = L"Private";
			this->PrivateCheck->MinimumWidth = 6;
			this->PrivateCheck->Name = L"PrivateCheck";
			this->PrivateCheck->ReadOnly = true;
			this->PrivateCheck->Width = 150;
			// 
			// CreatedDate
			// 
			this->CreatedDate->Frozen = true;
			this->CreatedDate->HeaderText = L"CreatedDate";
			this->CreatedDate->MinimumWidth = 8;
			this->CreatedDate->Name = L"CreatedDate";
			this->CreatedDate->ReadOnly = true;
			this->CreatedDate->Width = 150;
			// 
			// btnJoin
			// 
			this->btnJoin->BackColor = System::Drawing::Color::Transparent;
			this->btnJoin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJoin.BackgroundImage")));
			this->btnJoin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnJoin->FlatAppearance->BorderSize = 0;
			this->btnJoin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJoin->Location = System::Drawing::Point(742, 656);
			this->btnJoin->Name = L"btnJoin";
			this->btnJoin->Size = System::Drawing::Size(193, 57);
			this->btnJoin->TabIndex = 7;
			this->btnJoin->UseVisualStyleBackColor = false;
			this->btnJoin->Click += gcnew System::EventHandler(this, &GeneralChatIndex::btnJoin_Click);
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(991, 656);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(193, 57);
			this->btnClose->TabIndex = 8;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &GeneralChatIndex::btnClose_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(53, 39);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(170, 37);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Room List";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(628, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 37);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Password";
			// 
			// GeneralChatIndex
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(2009, 756);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnJoin);
			this->Controls->Add(this->ViewRoomList);
			this->Controls->Add(this->txtBoxPW);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"GeneralChatIndex";
			this->Text = L"GeneralChatIndex";
			this->Activated += gcnew System::EventHandler(this, &GeneralChatIndex::GeneralChatIndex_Activated);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	
		this->Owner->Show();
		this->Close();
	}
	private: System::Void btnJoin_Click(System::Object^ sender, System::EventArgs^ e) {

		IniMsg();


		System::String^ column1Value;
		System::String^ column2Value;
		System::String^ column3Value;
		System::String^ tmpValue;

		if (ViewRoomList->SelectedRows->Count > 0) {
			// 선택한 행의 인덱스를 가져옵니다.
			int selectedRowIndex = ViewRoomList->SelectedRows[0]->Index;

			// 1열, 2열, 3열의 데이터를 가져옵니다.
			System::Object^ column1ValueObj = ViewRoomList->Rows[selectedRowIndex]->Cells["RoomIndex"]->Value;
			System::Object^ column2ValueObj = ViewRoomList->Rows[selectedRowIndex]->Cells["PrivateCheck"]->Value;

	
			// null 체크
			if (column1ValueObj != nullptr && column2ValueObj != nullptr) {
				column1Value = column1ValueObj->ToString();
				column2Value = column2ValueObj->ToString();
				
				
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

		std::string tmptxt_2_ = msclr::interop::marshal_as<std::string>(column2Value);
		tmpValue = this->txtBoxPW->Text;

		if ((tmptxt_2_ == "Private") && String::IsNullOrEmpty(tmpValue))
		{
			System::Windows::Forms::MessageBox::Show("비밀번호를 입력해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if ((tmptxt_2_ == "Private"))
		{
			tmptxt_2_ = "3";
		}
		else
		{
			tmptxt_2_ = "2";
		}



		if (!String::IsNullOrEmpty(column1Value)) {


			
			int time_limit = 0;
			std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(column1Value);
			std::string tmptxt_3_ = msclr::interop::marshal_as<std::string>(tmpValue);
			std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_Enter));
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

						this->Close();
					}



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
		else {
			System::Windows::Forms::MessageBox::Show("방을 선택해주세요. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	








	}


	


	




// 방 리스트를 가져와야한다.
private: System::Void GeneralChatIndex_Activated(System::Object^ sender, System::EventArgs^ e) {

	IniMsg();
	int time_limit = 0;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_List));
	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);
	ViewRoomList->Rows->Clear();


	/*System::String^ clrString = msclr::interop::marshal_as<System::String^>(svrMsg);
	System::Windows::Forms::MessageBox::Show(clrString, "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);*/
	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{


		std::vector<std::string> Room_Index;
		std::vector<std::string> Room_Type;
		std::vector<std::string> Room_Title;
		std::vector<std::string> Room_Date;
		std::vector<std::string> Room_time;


		std::string _tmp;
		

		std::stringstream _svrmsg(svrMsg);




		std::regex pattern(R"((\d+)\s(\d+)\s\*/(.*?)\*/\s(\d{4}-\d{2}-\d{2}\s\d{2}:\d{2}:\d{2}))");

		std::smatch match;

		auto text = svrMsg.cbegin();
		auto end = svrMsg.cend();
		while (std::regex_search(text, end, match, pattern)) {
			
			Room_Index.push_back(match[1]);
			Room_Type.push_back(match[2]);
			Room_Title.push_back(match[3]);
			Room_Date.push_back(match[4]);
			text = match.suffix().first;
		}

		// 결과 출력

		for (size_t i = 0; i < Room_Index.size(); ++i)
		{


			ViewRoomList->Rows->Add();
			System::String^ tempRoomIndex = msclr::interop::marshal_as<System::String^>(Room_Index[i]);
			ViewRoomList->Rows[i]->Cells["RoomIndex"]->Value = tempRoomIndex;

			std::string R_T;
			if (Room_Type[i] == "2")
			{
				R_T = "Public";
			}
			else
			{
				R_T = "Private";
			}
			System::String^ tempRoomType = msclr::interop::marshal_as<System::String^>(R_T);
			ViewRoomList->Rows[i]->Cells["PrivateCheck"]->Value = tempRoomType;

			System::String^ tempRoomTitle = msclr::interop::marshal_as<System::String^>(Room_Title[i]);
			ViewRoomList->Rows[i]->Cells["RoomName"]->Value = tempRoomTitle;


			System::String^ tempRoomTime = msclr::interop::marshal_as<System::String^>(Room_Date[i]);
			ViewRoomList->Rows[i]->Cells["CreatedDate"]->Value = tempRoomTime;

		}
	}

}
};
}
