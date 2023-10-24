#pragma once
#include <msclr/marshal_cppstd.h>
#include "UsageClient.h"
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <regex>

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
	/// DeleteRoom에 대한 요약입니다.
	/// </summary>
	public ref class DeleteRoom : public System::Windows::Forms::Form
	{
	public:
		DeleteRoom(void)
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
		~DeleteRoom()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ ViewRoomList;
	protected:

	protected:



	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PrivateCheck;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CreatedDate;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteRoom::typeid));
			this->ViewRoomList = (gcnew System::Windows::Forms::DataGridView());
			this->RoomIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RoomName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PrivateCheck = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CreatedDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->BeginInit();
			this->SuspendLayout();
			// 
			// ViewRoomList
			// 
			this->ViewRoomList->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->ViewRoomList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->RoomIndex,
					this->RoomName, this->PrivateCheck, this->CreatedDate
			});
			this->ViewRoomList->Location = System::Drawing::Point(78, 99);
			this->ViewRoomList->Name = L"ViewRoomList";
			this->ViewRoomList->RowHeadersWidth = 62;
			this->ViewRoomList->RowTemplate->Height = 30;
			this->ViewRoomList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewRoomList->Size = System::Drawing::Size(597, 475);
			this->ViewRoomList->TabIndex = 0;
			// 
			// RoomIndex
			// 
			this->RoomIndex->HeaderText = L"#Index";
			this->RoomIndex->MinimumWidth = 8;
			this->RoomIndex->Name = L"RoomIndex";
			this->RoomIndex->ReadOnly = true;
			this->RoomIndex->Width = 150;
			// 
			// RoomName
			// 
			this->RoomName->HeaderText = L"Name";
			this->RoomName->MinimumWidth = 8;
			this->RoomName->Name = L"RoomName";
			this->RoomName->ReadOnly = true;
			this->RoomName->Width = 150;
			// 
			// PrivateCheck
			// 
			this->PrivateCheck->HeaderText = L"Private";
			this->PrivateCheck->MinimumWidth = 8;
			this->PrivateCheck->Name = L"PrivateCheck";
			this->PrivateCheck->Width = 150;
			// 
			// CreatedDate
			// 
			this->CreatedDate->HeaderText = L"CreatedDate";
			this->CreatedDate->MinimumWidth = 8;
			this->CreatedDate->Name = L"CreatedDate";
			this->CreatedDate->ReadOnly = true;
			this->CreatedDate->Width = 150;
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
			this->btnClose->Location = System::Drawing::Point(711, 488);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(176, 60);
			this->btnClose->TabIndex = 11;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &DeleteRoom::btnClose_Click);
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
			this->btnDelete->Location = System::Drawing::Point(711, 242);
			this->btnDelete->Margin = System::Windows::Forms::Padding(4);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(176, 60);
			this->btnDelete->TabIndex = 12;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &DeleteRoom::btnDelete_Click);
			// 
			// DeleteRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1320, 813);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->ViewRoomList);
			this->Name = L"DeleteRoom";
			this->Text = L"DeleteRoom";
			this->Activated += gcnew System::EventHandler(this, &DeleteRoom::DeleteRoom_Activated);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {

		this->Close();
	}
private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {


	IniMsg();
	int time_limit = 0;
	std::string tmptxt_1_;



	if (ViewRoomList->SelectedRows->Count > 0) {
		// 선택한 행의 인덱스를 가져옵니다.
		int selectedRowIndex = ViewRoomList->SelectedRows[0]->Index;

		// 1열, 2열, 3열의 데이터를 가져옵니다.


		System::Object^ column1ValueObj = ViewRoomList->Rows[selectedRowIndex]->Cells["RoomIndex"]->Value;

		// null 체크
		if (column1ValueObj != nullptr) {
			System::String^ column1Value = column1ValueObj->ToString();

			tmptxt_1_ = msclr::interop::marshal_as<std::string>(column1Value);

		}
		else {
			return;
		}
	}
	else {
		return;
	}


	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_Delete));
	std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;
	const char* buffer = _Index_Str_Result.c_str();


	send(client_sock, buffer, strlen(buffer), 0);
	Sleep(100);
	DivStrMsg(Recv_str, svrMsg);

	if (isTrue == trueStr)// server 에서 오케이받는 함수
	{

		//System::Windows::Forms::MessageBox::Show("삭제가 완료되었습니다", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;

	}

	else if (isTrue == falseStr) //  server에서 다른값보내면 그럴리없겟지만
	{
		//System::Windows::Forms::MessageBox::Show("삭제 실패", "warning", MessageBoxButtons::OK, MessageBoxIcon::Information);

		return;
	}
	else // 무한반복되는건데 시간타이밍 주면 좋을거같음
	{
		Sleep(1000);
		if (time_limit > 1)
		{
			//System::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		else
		{
			time_limit++;
		}
	}


}
private: System::Void DeleteRoom_Activated(System::Object^ sender, System::EventArgs^ e) {



	IniMsg();
	int time_limit = 0;
	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_myList));
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
