#pragma once

#include "enum.h"
#include "MyFunction.h"

namespace MyClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// SignupForm에 대한 요약입니다.
	/// </summary>
	public ref class SignupForm : public System::Windows::Forms::Form
	{
	public:
		SignupForm(void)
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
		~SignupForm()
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
			this->SuspendLayout();
			// 
			// SignupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(712, 632);
			this->Name = L"SignupForm";
			this->Text = L"SignupForm";
			this->ResumeLayout(false);

		}
#pragma endregion





	public: void SetMyFunction(MyFunction^ my)
	{
		_my = my;
		_my->MyEvent += gcnew Action<String^>(this, &SignupForm::MyEventHandler);
	}

	public: void MyEventHandler(String^ message)
	{
		//MessageBox::Show(message);
		// 이벤트가 트리거될 때 실행할 작업을 수행합니다.
	}
	private: MyFunction^ _my;

	};
}
