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
	/// CreateChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class CreateChatRoom : public System::Windows::Forms::Form
	{
	public:
		CreateChatRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		CreateChatRoom(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &CreateChatRoom::ReceivedMsg);
		}
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ btnClose;

	private: System::Windows::Forms::CheckBox^ chkBox;
	private: System::Windows::Forms::TextBox^ txtBoxPW;
	private: System::Windows::Forms::Button^ btnConfirm;
	private: System::Windows::Forms::TextBox^ txtBoxRoomTitle;
	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~CreateChatRoom()
		{

			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &CreateChatRoom::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CreateChatRoom::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->chkBox = (gcnew System::Windows::Forms::CheckBox());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->txtBoxRoomTitle = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(33, 166);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(145, 32);
			this->label1->TabIndex = 18;
			this->label1->Text = L"Password";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 10));
			this->label2->ForeColor = System::Drawing::Color::DeepPink;
			this->label2->Location = System::Drawing::Point(451, 89);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 20);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Private";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16));
			this->label4->ForeColor = System::Drawing::Color::Cyan;
			this->label4->Location = System::Drawing::Point(33, 83);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(146, 32);
			this->label4->TabIndex = 20;
			this->label4->Text = L"RoomTitle";
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
			this->btnClose->Location = System::Drawing::Point(429, 372);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(170, 51);
			this->btnClose->TabIndex = 17;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &CreateChatRoom::btnClose_Click);
			// 
			// chkBox
			// 
			this->chkBox->AutoSize = true;
			this->chkBox->Location = System::Drawing::Point(433, 91);
			this->chkBox->Name = L"chkBox";
			this->chkBox->Size = System::Drawing::Size(18, 17);
			this->chkBox->TabIndex = 16;
			this->chkBox->UseVisualStyleBackColor = true;
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(201, 171);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->Size = System::Drawing::Size(200, 25);
			this->txtBoxPW->TabIndex = 15;
			// 
			// btnConfirm
			// 
			this->btnConfirm->BackColor = System::Drawing::Color::Transparent;
			this->btnConfirm->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnConfirm.BackgroundImage")));
			this->btnConfirm->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnConfirm->FlatAppearance->BorderSize = 0;
			this->btnConfirm->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnConfirm->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnConfirm->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnConfirm->Location = System::Drawing::Point(31, 372);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(168, 51);
			this->btnConfirm->TabIndex = 14;
			this->btnConfirm->UseVisualStyleBackColor = false;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &CreateChatRoom::btnConfirm_Click);
			// 
			// txtBoxRoomTitle
			// 
			this->txtBoxRoomTitle->Location = System::Drawing::Point(201, 89);
			this->txtBoxRoomTitle->Name = L"txtBoxRoomTitle";
			this->txtBoxRoomTitle->Size = System::Drawing::Size(200, 25);
			this->txtBoxRoomTitle->TabIndex = 13;
			// 
			// CreateChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(617, 674);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->chkBox);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->btnConfirm);
			this->Controls->Add(this->txtBoxRoomTitle);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"CreateChatRoom";
			this->Text = L"CreateChatRoom";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CreateChatRoom::CreateChatRoom_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: void SendMessageForm(int index)
		{

			switch (index)
			{
				case e_room_Create:
				{
					String^ tmptxt_1;
					String^ tmptxt_3 = txtBoxRoomTitle->Text; // textBox는 해당 텍스트 상자의 이름입니다.
					String^ tmptxt_2 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
					if (chkBox->Checked)
					{
						tmptxt_1 = "3";
					}
					else
					{
						tmptxt_1 = "2";
					}
					if (chkBox->Checked && String::IsNullOrEmpty(tmptxt_2))
					{
						System::Windows::Forms::MessageBox::Show("Please enter your password", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}
					if (!String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_2))
					{
						int t_index = e_room_Create;
						String^ buffer = t_index.ToString() + " " + tmptxt_1 + " " + tmptxt_2 + " " + tmptxt_3;
						_my->SendMessage(buffer);
					}
					else
					{
						MessageBox::Show("Input RoomTitle", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					}

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
		case e_room_Create:
		{
			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("Room Created","warning", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("The room title already exists", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}
		}

	}

	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		btnConfirm->NotifyDefault(false);
		SendMessageForm(e_room_Create);
	}

private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void CreateChatRoom_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Show();
	this->Owner->Activate();
}
};
}
