#pragma once


namespace GUI {

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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	protected:


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(108, 120);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(327, 25);
			this->textBox1->TabIndex = 0;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Friends::textBox1_KeyPress);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 15;
			this->listBox1->Location = System::Drawing::Point(79, 204);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(388, 169);
			this->listBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(534, 156);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(194, 110);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// Friends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 518);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Friends";
			this->Text = L"Friends";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		// 이건 방목록에 해당하는 list를 서버가 주는거라고 생각하면 될거같아.
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	// 검색어를 입력할 때마다 호출됩니다.
	String^ searchTerm = textBox1->Text;
	listBox1->Items->Clear();



	// 여기에서 검색 대상 목록을 정의합니다.
	System::Collections::Generic::List<String^>^ items = gcnew System::Collections::Generic::List<String^>();
	items->Add("jiwon");
	items->Add("mila");
	items->Add("alice");

	// 검색어가 공백인 경우, 모든 항목을 표시하지 않습니다.
	if (searchTerm->Trim() == "") {
		return;
	}
	

	// 검색어와 일치하는 항목을 ListBox에 추가합니다.
	for each (String ^ item in items) {
		if (item->ToLower()->Contains(searchTerm->ToLower())) {
			listBox1->Items->Add(item);
		}
	}
}
};
}
