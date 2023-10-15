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
	private: System::Windows::Forms::Button^ button3;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox2;



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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(316, 148);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(153, 31);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Request Response";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(316, 206);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(153, 31);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Delete Friend";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(316, 91);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(153, 31);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Add Friend";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Friends list";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 15;
			this->listBox2->Location = System::Drawing::Point(44, 91);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(237, 259);
			this->listBox2->TabIndex = 3;
			// 
			// Friends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(799, 518);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox2);
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
