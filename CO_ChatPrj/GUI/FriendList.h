#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// FriendList에 대한 요약입니다.
	/// </summary>
	public ref class FriendList : public System::Windows::Forms::Form
	{
	public:
		FriendList(void)
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
		~FriendList()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^ listView1;
	protected:


	private: System::Windows::Forms::Button^ btnNickNameduplicateChk;
	private: System::Windows::Forms::Button^ btnClose;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FriendList::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->btnNickNameduplicateChk = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(68, 107);
			this->listView1->Margin = System::Windows::Forms::Padding(4);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(402, 421);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// btnNickNameduplicateChk
			// 
			this->btnNickNameduplicateChk->BackColor = System::Drawing::Color::Transparent;
			this->btnNickNameduplicateChk->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNickNameduplicateChk.BackgroundImage")));
			this->btnNickNameduplicateChk->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnNickNameduplicateChk->FlatAppearance->BorderSize = 0;
			this->btnNickNameduplicateChk->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnNickNameduplicateChk->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnNickNameduplicateChk->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnNickNameduplicateChk->Location = System::Drawing::Point(68, 559);
			this->btnNickNameduplicateChk->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnNickNameduplicateChk->Name = L"btnNickNameduplicateChk";
			this->btnNickNameduplicateChk->Size = System::Drawing::Size(168, 55);
			this->btnNickNameduplicateChk->TabIndex = 33;
			this->btnNickNameduplicateChk->UseVisualStyleBackColor = false;
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
			this->btnClose->Location = System::Drawing::Point(291, 559);
			this->btnClose->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(179, 51);
			this->btnClose->TabIndex = 47;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &FriendList::btnClose_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15));
			this->label1->ForeColor = System::Drawing::Color::Cornsilk;
			this->label1->Location = System::Drawing::Point(62, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(68, 34);
			this->label1->TabIndex = 48;
			this->label1->Text = L"List";
			// 
			// FriendList
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(534, 670);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnNickNameduplicateChk);
			this->Controls->Add(this->listView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"FriendList";
			this->Text = L"FriendList";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
