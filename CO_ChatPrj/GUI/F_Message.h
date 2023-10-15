#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// F_Message에 대한 요약입니다.
	/// </summary>
	public ref class F_Message : public System::Windows::Forms::Form
	{
	public:
		F_Message(void)
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
		~F_Message()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(86, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 53);
			this->button1->TabIndex = 0;
			this->button1->Text = L"New";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(95, 130);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(145, 52);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Sent";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(86, 198);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 39);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Message Box";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// F_Message
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(666, 615);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"F_Message";
			this->Text = L"Message";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
