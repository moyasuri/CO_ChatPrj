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
	/// ChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class ChatRoom : public System::Windows::Forms::Form
	{
	public:
		ChatRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		ChatRoom(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &ChatRoom::ReceivedMsg);

			int t_index = e_room_show_whole_Text;
			String^ buffer = _my->s_(t_index);
			_my->SendMessage(buffer);
		}
	private: System::Windows::Forms::TextBox^ txtBoxMessage;
	public:
	private: System::Windows::Forms::TextBox^ txtBoxId;
	private: System::Windows::Forms::TextBox^ txtBoxDate;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ViewId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ViewMsg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Date;

	public:
	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~ChatRoom()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &ChatRoom::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picBoxImojiYou;
	protected:
	private: System::Windows::Forms::PictureBox^ picBoxImojiMy;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::TextBox^ txtBoxMyChat;


	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChatRoom::typeid));
			this->picBoxImojiYou = (gcnew System::Windows::Forms::PictureBox());
			this->picBoxImojiMy = (gcnew System::Windows::Forms::PictureBox());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->txtBoxMyChat = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxMessage = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxId = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxDate = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->ViewId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ViewMsg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Date = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// picBoxImojiYou
			// 
			this->picBoxImojiYou->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiYou->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picBoxImojiYou->Location = System::Drawing::Point(-4, 221);
			this->picBoxImojiYou->Margin = System::Windows::Forms::Padding(2);
			this->picBoxImojiYou->Name = L"picBoxImojiYou";
			this->picBoxImojiYou->Size = System::Drawing::Size(108, 128);
			this->picBoxImojiYou->TabIndex = 12;
			this->picBoxImojiYou->TabStop = false;
			// 
			// picBoxImojiMy
			// 
			this->picBoxImojiMy->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiMy->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picBoxImojiMy->Location = System::Drawing::Point(-28, 11);
			this->picBoxImojiMy->Margin = System::Windows::Forms::Padding(2);
			this->picBoxImojiMy->Name = L"picBoxImojiMy";
			this->picBoxImojiMy->Size = System::Drawing::Size(108, 128);
			this->picBoxImojiMy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBoxImojiMy->TabIndex = 11;
			this->picBoxImojiMy->TabStop = false;
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
			this->btnClose->Location = System::Drawing::Point(709, 458);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(159, 51);
			this->btnClose->TabIndex = 10;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &ChatRoom::btnClose_Click);
			// 
			// btnSend
			// 
			this->btnSend->BackColor = System::Drawing::Color::Transparent;
			this->btnSend->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSend.BackgroundImage")));
			this->btnSend->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSend->FlatAppearance->BorderSize = 0;
			this->btnSend->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSend->Location = System::Drawing::Point(307, 458);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(157, 51);
			this->btnSend->TabIndex = 9;
			this->btnSend->UseVisualStyleBackColor = false;
			this->btnSend->Click += gcnew System::EventHandler(this, &ChatRoom::btnSend_Click);
			// 
			// txtBoxMyChat
			// 
			this->txtBoxMyChat->Location = System::Drawing::Point(307, 390);
			this->txtBoxMyChat->Name = L"txtBoxMyChat";
			this->txtBoxMyChat->Size = System::Drawing::Size(273, 25);
			this->txtBoxMyChat->TabIndex = 8;
			this->txtBoxMyChat->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ChatRoom::txtBoxMyChat_KeyPress);
			// 
			// txtBoxMessage
			// 
			this->txtBoxMessage->Location = System::Drawing::Point(307, 41);
			this->txtBoxMessage->Multiline = true;
			this->txtBoxMessage->Name = L"txtBoxMessage";
			this->txtBoxMessage->ReadOnly = true;
			this->txtBoxMessage->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBoxMessage->Size = System::Drawing::Size(241, 317);
			this->txtBoxMessage->TabIndex = 13;
			// 
			// txtBoxId
			// 
			this->txtBoxId->Location = System::Drawing::Point(129, 41);
			this->txtBoxId->Multiline = true;
			this->txtBoxId->Name = L"txtBoxId";
			this->txtBoxId->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBoxId->Size = System::Drawing::Size(156, 317);
			this->txtBoxId->TabIndex = 14;
			// 
			// txtBoxDate
			// 
			this->txtBoxDate->Location = System::Drawing::Point(588, 41);
			this->txtBoxDate->Multiline = true;
			this->txtBoxDate->Name = L"txtBoxDate";
			this->txtBoxDate->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->txtBoxDate->Size = System::Drawing::Size(156, 317);
			this->txtBoxDate->TabIndex = 14;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->ViewId,
					this->ViewMsg, this->Date
			});
			this->dataGridView1->Location = System::Drawing::Point(828, 86);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 27;
			this->dataGridView1->Size = System::Drawing::Size(610, 262);
			this->dataGridView1->TabIndex = 15;
			// 
			// ViewId
			// 
			this->ViewId->HeaderText = L"Column1";
			this->ViewId->MinimumWidth = 6;
			this->ViewId->Name = L"ViewId";
			this->ViewId->ReadOnly = true;
			this->ViewId->Width = 125;
			// 
			// ViewMsg
			// 
			this->ViewMsg->HeaderText = L"Column1";
			this->ViewMsg->MinimumWidth = 6;
			this->ViewMsg->Name = L"ViewMsg";
			this->ViewMsg->ReadOnly = true;
			this->ViewMsg->Width = 125;
			// 
			// Date
			// 
			this->Date->HeaderText = L"Column1";
			this->Date->MinimumWidth = 6;
			this->Date->Name = L"Date";
			this->Date->ReadOnly = true;
			this->Date->Width = 125;
			// 
			// ChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1428, 648);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->txtBoxDate);
			this->Controls->Add(this->txtBoxId);
			this->Controls->Add(this->txtBoxMessage);
			this->Controls->Add(this->picBoxImojiYou);
			this->Controls->Add(this->picBoxImojiMy);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtBoxMyChat);
			this->Name = L"ChatRoom";
			this->Text = L"ChatRoom";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ChatRoom::ChatRoom_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void ReceivedMsg(String^ message)
	{
		String^ inputString = message;

		array<String^>^ subString = inputString->Split(' ');

		String^ index_s = subString[0];
		String^ isTrue = subString[1];
		int index = Int32::Parse(index_s);

		switch (index)
		{
		case e_room_Chat:
		{
			if (isTrue == "true")
			{
				this->Invoke(gcnew Action<String^>(this, &ChatRoom::UpdateMessage), message);
			}
			else 
			{
				System::Windows::Forms::MessageBox::Show("Password Wrong", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}
		case e_room_show_whole_Text:
		{
			if (isTrue == "true")
			{
				this->Invoke(gcnew Action<String^>(this, &ChatRoom::PreviousMsgShow), message);
			}
			else if (isTrue == "else")
			{
				this->Invoke(gcnew Action(this, &ChatRoom::PreviousMsgEndline));
			}
			break;
		}
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
	public: void PreviousMsgEndline()
	{
		txtBoxId->Text += Environment::NewLine;
		txtBoxMessage->Text += "-----------------previous--------------" + Environment::NewLine;
		txtBoxDate->Text += Environment::NewLine;
	}
	public: void PreviousMsgShow(String^ message)
	{
		String^ e_length = _my->s_(e_room_show_whole_Text);
		String^ msg = message->Substring(e_length->Length + 6);

		// 아이디 추출
		int idEndIndex = msg->IndexOf(' '); // 공백 이전까지가 아이디
		String^ id = msg->Substring(0, idEndIndex)->Trim();

		// 메시지 추출
		String^ messagePart = msg->Substring(idEndIndex)->Trim();

		// 날짜 추출
		int lastSpaceIndex = messagePart->LastIndexOf(' '); // 뒤에서부터 첫 번째 공백의 위치
		int dateEndIndex = messagePart->LastIndexOf(' ', lastSpaceIndex - 1); // 뒤에서부터 두 번째 공백의 위치
		String^ date = messagePart->Substring(dateEndIndex)->Trim();

		// 실제 메시지 추출 (날짜 이전의 부분)
		String^ messageText = messagePart->Substring(0, dateEndIndex)->Trim();

		// 각각의 텍스트 박스에 표시
		txtBoxId->Text += id + Environment::NewLine;
		txtBoxMessage->Text += messageText + Environment::NewLine;
		txtBoxDate->Text += date + Environment::NewLine;

	}

		   
	public: void UpdateMessage(String^ message)
	{
		String^ e_length = _my->s_(e_room_show_whole_Text);
		String^ msg = message->Substring(e_length->Length + 6);

		// 아이디 추출
		int idEndIndex = msg->IndexOf(' '); // 공백 이전까지가 아이디
		String^ id = msg->Substring(0, idEndIndex)->Trim();

		// 메시지 추출
		String^ messagePart = msg->Substring(idEndIndex)->Trim();

		// 날짜 추출
		int lastSpaceIndex = messagePart->LastIndexOf(' '); // 뒤에서부터 첫 번째 공백의 위치
		int dateEndIndex = messagePart->LastIndexOf(' ', lastSpaceIndex - 1); // 뒤에서부터 두 번째 공백의 위치
		String^ date = messagePart->Substring(dateEndIndex)->Trim();

		// 실제 메시지 추출 (날짜 이전의 부분)
		String^ messageText = messagePart->Substring(0, dateEndIndex)->Trim();

		// 각각의 텍스트 박스에 표시
		txtBoxId->Text += id + Environment::NewLine;
		txtBoxMessage->Text += messageText + Environment::NewLine;
		txtBoxDate->Text += date + Environment::NewLine;

		return;
	}

	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();

	}
	private: System::Void ChatRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

		String^ buffer = _my->s_(e_room_Exit);
		_my->SendMessage(buffer);
		this->Owner->Show();
		this->Owner->Activate();
		

	}
private: System::Void txtBoxMyChat_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// Check if Enter key (carriage return) was pressed
	if (e->KeyChar == (char)Keys::Enter) {
		// Trigger the "Send" button's click event
		btnSend_Click(sender, e);
	}
}
private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ tmptxt_1 = txtBoxMyChat->Text; // textBox는 해당 텍스트 상자의 이름입니다.
	if (!String::IsNullOrEmpty(tmptxt_1))
	{
		int t_index = e_room_Chat;
		String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
		_my->SendMessage(buffer);
		txtBoxMyChat->Text = "";
	}
}
};
}
