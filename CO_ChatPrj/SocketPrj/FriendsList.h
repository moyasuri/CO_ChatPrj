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
	/// FriendsList에 대한 요약입니다.
	/// </summary>
	public ref class FriendsList : public System::Windows::Forms::Form
	{
	public:
		FriendsList(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}
		FriendsList(MyFunction^ my)
		{
			InitializeComponent();
			this->_my = my;
			this->_my->MyEvent += gcnew Action<String^>(this, &FriendsList::ReceivedMsg);

		}
		
	private: MyFunction^ _my;
	public: event Action<String^>^ MyEvent_;
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~FriendsList()
		{
			if (_my != nullptr) {
				// MyEvent 이벤트 핸들러를 해제
				_my->MyEvent -= gcnew Action<String^>(this, &FriendsList::ReceivedMsg);

				// _my를 삭제
				delete _my;
				_my = nullptr;  // nullptr로 설정하여 dangling pointer를 방지
			}
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBoxFriends;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnConfirm;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FriendsList::typeid));
			this->listBoxFriends = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listBoxFriends
			// 
			this->listBoxFriends->FormattingEnabled = true;
			this->listBoxFriends->ItemHeight = 15;
			this->listBoxFriends->Location = System::Drawing::Point(87, 88);
			this->listBoxFriends->Margin = System::Windows::Forms::Padding(2);
			this->listBoxFriends->Name = L"listBoxFriends";
			this->listBoxFriends->Size = System::Drawing::Size(303, 334);
			this->listBoxFriends->TabIndex = 53;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(83, 34);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 29);
			this->label1->TabIndex = 52;
			this->label1->Text = L"List";
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
			this->btnClose->Location = System::Drawing::Point(266, 458);
			this->btnClose->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(143, 42);
			this->btnClose->TabIndex = 51;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &FriendsList::btnClose_Click);
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
			this->btnConfirm->Location = System::Drawing::Point(87, 458);
			this->btnConfirm->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(134, 46);
			this->btnConfirm->TabIndex = 50;
			this->btnConfirm->UseVisualStyleBackColor = false;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &FriendsList::btnConfirm_Click);
			// 
			// FriendsList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(506, 560);
			this->Controls->Add(this->listBoxFriends);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnConfirm);
			this->Name = L"FriendsList";
			this->Text = L"FriendsList";
			this->Activated += gcnew System::EventHandler(this, &FriendsList::FriendsList_Activated);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: void SendMessageForm(int index)
	{

		switch (index)
		{
			case e_friends_List:
			{

				int t_index = e_friends_List;
				String^ buffer = t_index.ToString();
				_my->SendMessage(buffer);

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
		case e_friends_List:
		{
			if (isTrue == "true")
			{
				for (int i = 2; i < subString->Length;i++)
				{
					listBoxFriends->Items->Add(gcnew String(subString[i]));
				}
			}
			break;
		}


		}
	}

	private: System::Void FriendsList_Activated(System::Object^ sender, System::EventArgs^ e) {

		listBoxFriends->Items->Clear();
		int t_index = e_friends_List;
		String^ buffer = _my->s_(t_index);
		_my->SendMessage(buffer);
	}

	private: System::Void btnConfirm_Click(System::Object^ sender, System::EventArgs^ e) {
		if (listBoxFriends->SelectedItem == nullptr) {
			System::Windows::Forms::MessageBox::Show("Select the ID", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ tmptxt_1 = listBoxFriends->SelectedItem->ToString();
		MyEvent_(tmptxt_1);
		this->Close();
	}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}

