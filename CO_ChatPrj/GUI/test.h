#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// test에 대한 요약입니다.
	/// </summary>
	public ref class test : public System::Windows::Forms::Form
	{
	public:
		test(void)
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
		~test()
		{
			if (components)
			{
				delete components;
			}
		}
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(244, 118);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &test::button1_Click);
			// 
			// test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(446, 315);
			this->Controls->Add(this->button1);
			this->Name = L"test";
			this->Text = L"test";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// 새로운 텍스트 상자 (TextBox) 생성
		TextBox^ textBox = gcnew TextBox();

		// 텍스트 상자의 속성 설정
		textBox->Location = System::Drawing::Point(10, 10);  // 텍스트 상자의 위치 설정
		textBox->Size = System::Drawing::Size(200, 20);     // 텍스트 상자의 크기 설정

		// 텍스트 상자를 폼에 추가
		this->Controls->Add(textBox);
		// 텍스트 상자 이벤트 핸들러 설정 (예를 들어, 엔터 키를 누를 때 이벤트 처리)
		textBox->KeyPress += gcnew KeyPressEventHandler(this, &test::textBox_KeyPress);


	}
	private: System::Void textBox_KeyPress(System::Object^ sender, KeyPressEventArgs^ e) {
		// Enter 키를 누를 때 이벤트 처리
		if (e->KeyChar == (char)13) { // 13은 Enter 키의 ASCII 코드
			// 사용자가 입력한 텍스트 가져오기
			TextBox^ textBox = dynamic_cast<TextBox^>(sender);
			String^ enteredText = textBox->Text;

			// 여기에서 입력된 텍스트를 처리하거나 다른 작업을 수행할 수 있습니다.

			// 예를 들어, 텍스트 상자를 삭제할 수 있습니다.
			this->Controls->Remove(textBox);
		}
	}
	};
}
