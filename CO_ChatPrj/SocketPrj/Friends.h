#pragma once
#include "MyFunction.h"
#include "enum.h"
#include "AddFriends.h"
#include "FriendResponse.h"


namespace SocketPrj {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Friends에 대한 요약입니다.
	/// </summary>
	public ref class Friends : public System::Windows::Forms::Form
	{
	public:
		Friends(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		Friends(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &Friends::ReceivedMsg);
		}
	private: System::Windows::Forms::Label^ label2;
	public:
	private: System::Windows::Forms::ListBox^ listBoxFriends;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnDelete;
	private: System::Windows::Forms::Button^ btnResponse;
	private: System::Windows::Forms::Button^ btnAdd;

	private: MyFunction^ _my;
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~Friends()
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Friends::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBoxFriends = (gcnew System::Windows::Forms::ListBox());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnResponse = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label2->ForeColor = System::Drawing::Color::SlateGray;
			this->label2->Location = System::Drawing::Point(36, 19);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(227, 46);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Friend List";
			// 
			// listBoxFriends
			// 
			this->listBoxFriends->FormattingEnabled = true;
			this->listBoxFriends->ItemHeight = 15;
			this->listBoxFriends->Location = System::Drawing::Point(44, 89);
			this->listBoxFriends->Margin = System::Windows::Forms::Padding(2);
			this->listBoxFriends->Name = L"listBoxFriends";
			this->listBoxFriends->Size = System::Drawing::Size(316, 394);
			this->listBoxFriends->TabIndex = 15;
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
			this->btnClose->Location = System::Drawing::Point(383, 428);
			this->btnClose->Margin = System::Windows::Forms::Padding(2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(194, 55);
			this->btnClose->TabIndex = 11;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &Friends::btnClose_Click);
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
			this->btnDelete->Location = System::Drawing::Point(383, 291);
			this->btnDelete->Margin = System::Windows::Forms::Padding(2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(194, 55);
			this->btnDelete->TabIndex = 12;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Friends::btnDelete_Click);
			// 
			// btnResponse
			// 
			this->btnResponse->BackColor = System::Drawing::Color::Transparent;
			this->btnResponse->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnResponse.BackgroundImage")));
			this->btnResponse->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnResponse->FlatAppearance->BorderSize = 0;
			this->btnResponse->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnResponse->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnResponse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnResponse->Location = System::Drawing::Point(383, 191);
			this->btnResponse->Margin = System::Windows::Forms::Padding(2);
			this->btnResponse->Name = L"btnResponse";
			this->btnResponse->Size = System::Drawing::Size(194, 55);
			this->btnResponse->TabIndex = 13;
			this->btnResponse->UseVisualStyleBackColor = false;
			this->btnResponse->Click += gcnew System::EventHandler(this, &Friends::btnResponse_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::Transparent;
			this->btnAdd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdd.BackgroundImage")));
			this->btnAdd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnAdd->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnAdd->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Location = System::Drawing::Point(383, 101);
			this->btnAdd->Margin = System::Windows::Forms::Padding(2);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(194, 55);
			this->btnAdd->TabIndex = 14;
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Friends::btnAdd_Click);
			// 
			// Friends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(790, 571);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBoxFriends);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnResponse);
			this->Controls->Add(this->btnAdd);
			this->Name = L"Friends";
			this->Text = L"Friends";
			this->Activated += gcnew System::EventHandler(this, &Friends::Friends_Activated);
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Friends::Friends_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			AddFriends^ addFriends = nullptr;
			FriendResponse^ friendResponse = nullptr;

	public: void SendMessageForm(int index, String^ tmptxt_1) 
	{

		switch (index)
		{
			case e_friends_Delete:
			{
				
					int t_index = e_friends_Delete;
					String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
					_my->SendMessage(buffer);

				break;
			}
		}
	}



	private: void UpdateFriendList(String^ message)
	{
		array<String^>^ subString = message->Split(' ');
		
		for (int i = 2; i < subString->Length; i++)
		{
			listBoxFriends->Items->Add(gcnew String(subString[i]));
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
		case e_friends_List:
			{

				if (isTrue == "true")
				{

					this->Invoke(gcnew Action<String^>(this, &Friends::UpdateFriendList), message);
				

				}
				else
				{
				}
				break;
			}
		case e_friends_Delete:
		{

			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("Friend deleted", "Edit Porofile", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;



		}
	

		}

	}

	private: System::Void Friends_Activated(System::Object^ sender, System::EventArgs^ e) {
		listBoxFriends->Items->Clear();
		int t_index = e_friends_List;
		String^ buffer = _my->s_(t_index);
		_my->SendMessage(buffer);
	}
private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {

	if (addFriends == nullptr || addFriends->IsDisposed) {
		addFriends = gcnew AddFriends(_my);
		addFriends->Owner = this; // Owner를 설정해야 가능
		//this->HomeImageSound->Stop();
		addFriends->Show();
	}


}
	private: System::Void btnResponse_Click(System::Object^ sender, System::EventArgs^ e) {
		if (friendResponse == nullptr || friendResponse->IsDisposed) {
			friendResponse = gcnew FriendResponse(_my);
			friendResponse->Owner = this; // Owner를 설정해야 가능
			//this->HomeImageSound->Stop();
			friendResponse->Show();


		}
	}
	private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ tmptxt_1;
		if (listBoxFriends->SelectedItem != nullptr)
		{
			tmptxt_1 = listBoxFriends->SelectedItem->ToString();
		}
		else
		{
			System::Windows::Forms::MessageBox::Show("Select ID to delete", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		MessageBoxButtons buttons = MessageBoxButtons::YesNo;

		// 메시지 박스를 표시하고 사용자의 선택을 저장합니다.
		System::Windows::Forms::DialogResult result = \
			MessageBox::Show("Do you really want to delete friend?", "confirm", buttons);

		// 사용자의 선택에 따라 분기합니다.
		if (result == System::Windows::Forms::DialogResult::Yes)
		{
			btnDelete->NotifyDefault(false);
			SendMessageForm(e_friends_Delete, tmptxt_1);
		}
		else if (result == System::Windows::Forms::DialogResult::No)
		{
			return;
		}
	}

private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}

private: System::Void Friends_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	this->Owner->Show();
	this->Owner->Activate();
}
};
}
