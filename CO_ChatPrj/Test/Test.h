#pragma once

namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Test에 대한 요약입니다.
	/// </summary>
	public ref class Test : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::TextBox^ textBox; // 텍스트 상자를 멤버 변수로 추가
	private: System::Windows::Forms::Form^ newForm;
	public:
		Test(void)
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
		~Test()
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
		System::ComponentModel::Container^ components;

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
			this->button1->Location = System::Drawing::Point(130, 140);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Test::button1_Click);
			// 
			// Test
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(533, 350);
			this->Controls->Add(this->button1);
			this->Name = L"Test";
			this->Text = L"Test";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		// 새로운 폼 생성
		newForm = gcnew Form();
		newForm->Text = "새로운 폼";

		// 텍스트 상자 생성 및 초기화
		textBox = gcnew System::Windows::Forms::TextBox();
		textBox->Location = System::Drawing::Point(10, 10);
		textBox->Size = System::Drawing::Size(200, 20);
		newForm->Controls->Add(textBox);

		// 확인 버튼 생성
		Button^ confirmButton = gcnew Button();
		confirmButton->Location = System::Drawing::Point(10, 40);
		confirmButton->Size = System::Drawing::Size(75, 23);
		confirmButton->Text = "확인";
		confirmButton->Click += gcnew System::EventHandler(this, &Test::confirmButton_Click);
		newForm->Controls->Add(confirmButton);

		// 새로운 폼을 표시
		newForm->Show();
	}


	private: System::Void confirmButton_Click(System::Object^ sender, System::EventArgs^ e) {


		String^ inputText = textBox->Text;
		// 이곳에서 inputText를 사용하거나 저장할 수 있습니다.

		// 새로운 폼 종료
		newForm->Close();


	}







	};
}
