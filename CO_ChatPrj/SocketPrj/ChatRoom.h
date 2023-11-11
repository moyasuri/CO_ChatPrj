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
		}
	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~ChatRoom()
		{
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
	private: System::Windows::Forms::TextBox^ txtBoxChatWindow;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ChatRoom::typeid));
			this->picBoxImojiYou = (gcnew System::Windows::Forms::PictureBox());
			this->picBoxImojiMy = (gcnew System::Windows::Forms::PictureBox());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->txtBoxMyChat = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxChatWindow = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->BeginInit();
			this->SuspendLayout();
			// 
			// picBoxImojiYou
			// 
			this->picBoxImojiYou->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiYou->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picBoxImojiYou->Location = System::Drawing::Point(671, 13);
			this->picBoxImojiYou->Margin = System::Windows::Forms::Padding(2);
			this->picBoxImojiYou->Name = L"picBoxImojiYou";
			this->picBoxImojiYou->Size = System::Drawing::Size(135, 154);
			this->picBoxImojiYou->TabIndex = 12;
			this->picBoxImojiYou->TabStop = false;
			// 
			// picBoxImojiMy
			// 
			this->picBoxImojiMy->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiMy->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picBoxImojiMy->Location = System::Drawing::Point(106, 13);
			this->picBoxImojiMy->Margin = System::Windows::Forms::Padding(2);
			this->picBoxImojiMy->Name = L"picBoxImojiMy";
			this->picBoxImojiMy->Size = System::Drawing::Size(135, 154);
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
			this->btnClose->Location = System::Drawing::Point(608, 551);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(199, 61);
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
			this->btnSend->Location = System::Drawing::Point(111, 551);
			this->btnSend->Margin = System::Windows::Forms::Padding(4);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(196, 61);
			this->btnSend->TabIndex = 9;
			this->btnSend->UseVisualStyleBackColor = false;
			// 
			// txtBoxMyChat
			// 
			this->txtBoxMyChat->Location = System::Drawing::Point(106, 467);
			this->txtBoxMyChat->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxMyChat->Name = L"txtBoxMyChat";
			this->txtBoxMyChat->Size = System::Drawing::Size(700, 28);
			this->txtBoxMyChat->TabIndex = 8;
			// 
			// txtBoxChatWindow
			// 
			this->txtBoxChatWindow->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->txtBoxChatWindow->Location = System::Drawing::Point(106, 13);
			this->txtBoxChatWindow->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxChatWindow->Multiline = true;
			this->txtBoxChatWindow->Name = L"txtBoxChatWindow";
			this->txtBoxChatWindow->ReadOnly = true;
			this->txtBoxChatWindow->Size = System::Drawing::Size(700, 417);
			this->txtBoxChatWindow->TabIndex = 7;
			// 
			// ChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(914, 625);
			this->Controls->Add(this->picBoxImojiYou);
			this->Controls->Add(this->picBoxImojiMy);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtBoxMyChat);
			this->Controls->Add(this->txtBoxChatWindow);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ChatRoom";
			this->Text = L"ChatRoom";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ChatRoom::ChatRoom_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->EndInit();
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
			case e_edit_PWchk:
			{
				if (isTrue == "true")
				{
					//txtBoxNickName->Invoke(gcnew Action<String^>(this, &YourFormName::UpdateTextBox), newText);
					//Invoke(gcnew Action(this, &EditProfile::UpdateTextBox));
					System::Windows::Forms::MessageBox::Show("Password matches username.", "PW check", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else
				{
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

	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();

	}
private: System::Void ChatRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Show();
	this->Owner->Activate();
}
};
}
