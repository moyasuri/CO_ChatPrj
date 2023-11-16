#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "ChatRoom.h"
namespace SocketPrj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// GeneralChatList에 대한 요약입니다.
	/// </summary>
	public ref class GeneralChatList : public System::Windows::Forms::Form
	{
	public:
		GeneralChatList(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		GeneralChatList(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &GeneralChatList::ReceivedMsg);
		}

	private: MyFunction^ _my;
	private: ChatRoom^ chatRoom;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~GeneralChatList()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &GeneralChatList::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnJoin;
	private: System::Windows::Forms::DataGridView^ ViewRoomList;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomIndex;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ RoomName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PrivateCheck;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CreatedDate;
	private: System::Windows::Forms::TextBox^ txtBoxPW;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GeneralChatList::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnJoin = (gcnew System::Windows::Forms::Button());
			this->ViewRoomList = (gcnew System::Windows::Forms::DataGridView());
			this->RoomIndex = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->RoomName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PrivateCheck = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CreatedDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(552, 70);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 32);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label2->ForeColor = System::Drawing::Color::Cornsilk;
			this->label2->Location = System::Drawing::Point(92, 70);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 32);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Room List";
			// 
			// btnClose
			// 
			this->btnClose->BackColor = System::Drawing::Color::Transparent;
			this->btnClose->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnClose.BackgroundImage")));
			this->btnClose->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnClose->FlatAppearance->BorderSize = 0;
			this->btnClose->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClose->Location = System::Drawing::Point(842, 584);
			this->btnClose->Margin = System::Windows::Forms::Padding(2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(154, 48);
			this->btnClose->TabIndex = 14;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &GeneralChatList::btnClose_Click);
			// 
			// btnJoin
			// 
			this->btnJoin->BackColor = System::Drawing::Color::Transparent;
			this->btnJoin->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnJoin.BackgroundImage")));
			this->btnJoin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnJoin->FlatAppearance->BorderSize = 0;
			this->btnJoin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnJoin->Location = System::Drawing::Point(643, 584);
			this->btnJoin->Margin = System::Windows::Forms::Padding(2);
			this->btnJoin->Name = L"btnJoin";
			this->btnJoin->Size = System::Drawing::Size(154, 48);
			this->btnJoin->TabIndex = 13;
			this->btnJoin->UseVisualStyleBackColor = false;
			this->btnJoin->Click += gcnew System::EventHandler(this, &GeneralChatList::btnJoin_Click);
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
			this->ViewRoomList->Location = System::Drawing::Point(38, 126);
			this->ViewRoomList->MultiSelect = false;
			this->ViewRoomList->Name = L"ViewRoomList";
			this->ViewRoomList->ReadOnly = true;
			this->ViewRoomList->RowHeadersWidth = 51;
			this->ViewRoomList->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->ViewRoomList->RowTemplate->Height = 27;
			this->ViewRoomList->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->ViewRoomList->Size = System::Drawing::Size(1446, 425);
			this->ViewRoomList->TabIndex = 12;
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
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(707, 75);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(160, 25);
			this->txtBoxPW->TabIndex = 11;
			// 
			// GeneralChatList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1539, 700);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnJoin);
			this->Controls->Add(this->ViewRoomList);
			this->Controls->Add(this->txtBoxPW);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"GeneralChatList";
			this->Text = L"GeneralChatList";
			this->Activated += gcnew System::EventHandler(this, &GeneralChatList::GeneralChatList_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GeneralChatList::GeneralChatList_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ViewRoomList))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: void SendMessageForm(int index) // 무조건 여길 통하는 방법도 있었을텐데
		{
			switch (index)
			{
				case e_room_Enter:
				{
					if (!(ViewRoomList->SelectedRows->Count > 0)) {
						return;
					}


					// 선택한 행의 인덱스를 가져옵니다.
					int selectedRowIndex = ViewRoomList->SelectedRows[0]->Index;

					System::String^ RoomIndex;
					System::String^ PrivateCheck;
					System::String^ RoomPW = "";
					System::String^ RoomType = "";


					// 1열, 2열, 3열의 데이터를 가져옵니다.
					System::Object^ column1ValueObj = ViewRoomList->Rows[selectedRowIndex]->Cells["RoomIndex"]->Value;
					System::Object^ column2ValueObj = ViewRoomList->Rows[selectedRowIndex]->Cells["PrivateCheck"]->Value;


					// null 체크
					if (column1ValueObj != nullptr && column2ValueObj != nullptr) {
						RoomIndex = column1ValueObj->ToString();
						PrivateCheck = column2ValueObj->ToString();
					}
					else {
						// 선택한 행의 하나 이상의 열이 null일 때 처리할 내용
						// 예를 들어, 오류 메시지 출력 또는 다른 작업을 수행할 수 있습니다.
						return;
					}
					RoomPW = this->txtBoxPW->Text;

					if ((PrivateCheck == "Private") && String::IsNullOrEmpty(RoomPW))
					{
						System::Windows::Forms::MessageBox::Show("비밀번호를 입력해주세요.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}

					if ((PrivateCheck == "Private"))
					{
						RoomType = "3";
					}
					else
					{
						RoomType = "2";
					}

					String^ tmptxt_1 = RoomIndex + " " + RoomType + " " + RoomPW;
					int t_index = e_room_Enter;
					String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
					_my->SendMessage(buffer);
					break;
				}

			}

		}

		private: void ReceivedMsg(String^ message)
		{
			String^ inputString = message;

			array<String^>^ subString = inputString->Split(' ');

			String^ index_s = subString[0];
			String^ isTrue = subString[1];
			int index = Int32::Parse(index_s);

			switch (index)
			{
			case e_room_List:
			{
				if (isTrue == "true")
				{

					this->Invoke(gcnew Action<String^>(this, &GeneralChatList::UpdateRoomList), message);
				}
				else
				{
					// 
				}
				break;
			}
			case e_room_Enter:
			{
				if (isTrue == "true")
				{

					this->Invoke(gcnew Action<String^>(this, &GeneralChatList::JoinRoom), message);
				}
				else if (isTrue == "else")
				{
					// server방
					
				}
				else
				{
					// password 때매 거절당하는거겟지?
					System::Windows::Forms::MessageBox::Show("Password Wrong", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}

				break;
			}
			//case e_edit_NickNamechk:
			//{	
			//	if (isTrue == "true")
			//	{
			//		Invoke(gcnew Action(this, &EditProfile::UpdateTextBoxNickname));
			//		System::Windows::Forms::MessageBox::Show("You can use this Nickname", "nickname check", MessageBoxButtons::OK, MessageBoxIcon::Information);
			//	}
			//	else
			//	{
			//		System::Windows::Forms::MessageBox::Show("The nickname already exists.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			//	}
			//	break;
			//}
			//case e_edit_Confirm:
			//{
			//	if (isTrue == "true")
			//	{
			//		System::Windows::Forms::MessageBox::Show("Update Profile Success", "Edit Porofile", MessageBoxButtons::OK, MessageBoxIcon::Information);
			//	}
			//	else
			//	{
			//		System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			//	}
			//	break;
			//}

			}

		}
	private: System::Void GeneralChatList_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

		this->Owner->Show();
		this->Owner->Activate();

	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: Void UpdateRoomList(String^ message) {

		ViewRoomList->Rows->Clear();


			
	// 17*/2*/welcome my home*/20211012 3033\n

	array<String^>^ roomInfo = message->Split('\n');
	int rowNum = 0;
	array<String^>^ separators = gcnew array<String^> { "*/" };
		
	for (int i = 1; i < roomInfo->Length;i++)
	{
		//array<String^>^ myString = roomInfo[i]->Split('*/');
		array<String^>^ myString = roomInfo[i]->Split(separators, StringSplitOptions::None);
		ViewRoomList->Rows->Add();
		ViewRoomList->Rows[rowNum]->Cells["RoomIndex"]->Value = myString[0];


		if (myString[1] == "2")
		{
			ViewRoomList->Rows[rowNum]->Cells["PrivateCheck"]->Value = "Public";
		}
		else
		{
			ViewRoomList->Rows[rowNum]->Cells["PrivateCheck"]->Value = "Private";
		}

		ViewRoomList->Rows[rowNum]->Cells["RoomName"]->Value = myString[2];


		ViewRoomList->Rows[rowNum]->Cells["CreatedDate"]->Value = myString[3];

		rowNum++;
	}
}
	private: System::Void GeneralChatList_Activated(System::Object^ sender, System::EventArgs^ e) {

		String^ buffer = _my->s_(e_room_List);
		_my->SendMessage(buffer);




}
	private: System::Void btnJoin_Click(System::Object^ sender, System::EventArgs^ e) {
	SendMessageForm(e_room_Enter);
    }
	private: Void JoinRoom(String^ message) {

		if (chatRoom == nullptr || chatRoom->IsDisposed) {

			chatRoom = gcnew ChatRoom(_my);
			chatRoom->Owner = this; // Owner를 설정해야 가능
			chatRoom->Show();
			this->Hide();
		}	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			chatRoom->Activate();
		}

	}


};
}
