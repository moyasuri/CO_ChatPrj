#pragma once
#include "MyFunction.h"
#include "enum.h"


namespace MyClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// JoinChatRoom에 대한 요약입니다.
	/// </summary>
	public ref class JoinChatRoom : public System::Windows::Forms::Form
	{
	public:
		JoinChatRoom(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

		JoinChatRoom(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &JoinChatRoom::ReceivedMsg);
		}
	private: MyFunction^ _my;

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~JoinChatRoom()
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
			// JoinChatRoom
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 382);
			this->Name = L"JoinChatRoom";
			this->Text = L"JoinChatRoom";
			this->ResumeLayout(false);

		}
#pragma endregion

	public: void SendMessageForm(int index)
	{

		switch (index)
		{
		case e_signup_IDchk:
		{
			String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.

			if (!String::IsNullOrEmpty(tmptxt_1))
			{
				int t_index = e_signup_IDchk;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
				_my->SendMessage(buffer);
			}
			else
			{
				MessageBox::Show("Please fill the ID", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			break;
		}

		case e_signup_NickNamechk:
		{
			String^ tmptxt_1 = txtBoxNickName->Text;


			if (!String::IsNullOrEmpty(tmptxt_1))
			{
				int t_index = e_signup_NickNamechk;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1;
				_my->SendMessage(buffer);
			}
			else
			{
				MessageBox::Show("Please fill the nickname", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}

			break;
		}

		case e_signup_Submit:
		{
			if (!isChkIDDup)
			{
				System::Windows::Forms::MessageBox::Show("Please ID duplicate check", "warming", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			if (!isChkNickNameDup)
			{
				System::Windows::Forms::MessageBox::Show("Please Nickname duplicate check", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
			if (txtBoxPW->Text != txtBoxRechk->Text)
			{

				System::Windows::Forms::MessageBox::Show("Please check the PW", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}


			String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_2 = txtBoxEmail->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_3 = txtBoxPhone->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_4 = txtBoxBirth->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_5 = txtBoxNickName->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_6 = combBoxCha->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_7 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_8 = txtBoxName->Text; // textBox는 해당 텍스트 상자의 이름입니다.

			// ID와 PW의 문자열이 채워져있다면
			if (!String::IsNullOrEmpty(tmptxt_1) && !String::IsNullOrEmpty(tmptxt_2) && !String::IsNullOrEmpty(tmptxt_2)\
				&& !String::IsNullOrEmpty(tmptxt_3) && !String::IsNullOrEmpty(tmptxt_4) && !String::IsNullOrEmpty(tmptxt_5)\
				&& !String::IsNullOrEmpty(tmptxt_6) && !String::IsNullOrEmpty(tmptxt_7) && !String::IsNullOrEmpty(tmptxt_8)) {

				if (1) // 나중에 고치자
				{
					tmptxt_6 = _my->s_(e_character_izuna);
				}
				/*else if (tmptxt_6_ == "아리스")
				{
					tmptxt_6_ = _my->s_(e_character_alice);
				}*/

				int t_index = e_signup_NickNamechk;
				String^ buffer = _my->s_(t_index) + " " + tmptxt_1 + " " + tmptxt_2 + " " + tmptxt_3 + " " + tmptxt_4\
					+ " " + tmptxt_5 + " " + tmptxt_6 + " " + tmptxt_7 + " " + tmptxt_8;
				_my->SendMessage(buffer);
			}
			// 입력값이 없다면,
			else {
				System::Windows::Forms::MessageBox::Show("please fill the blank.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
		}

		}

	}

	private: System::Void UpdateTextBoxID()
	{
		txtBoxID->Enabled = false;
	}


	private: System::Void UpdateTextBoxNickname()
	{
		txtBoxNickName->Enabled = false;
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
		case e_signup_IDchk:
		{

			if (isTrue == "true")
			{
				//txtBoxNickName->Invoke(gcnew Action<String^>(this, &YourFormName::UpdateTextBox), newText);
				txtBoxID->Invoke(gcnew Action(this, &SignupForm::UpdateTextBoxID));
				isChkIDDup = true;
				System::Windows::Forms::MessageBox::Show("You can use this ID", "id check", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{

				System::Windows::Forms::MessageBox::Show("The ID already exists", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}
		case e_signup_NickNamechk:
		{
			if (isTrue == "true")
			{
				txtBoxNickName->Invoke(gcnew Action(this, &SignupForm::UpdateTextBoxNickname));
				isChkNickNameDup = true;
				System::Windows::Forms::MessageBox::Show("You can use this Nickname", "nickname check", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("The nickname already exists.", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}
		case e_signup_Submit:
		{
			if (isTrue == "true")
			{
				System::Windows::Forms::MessageBox::Show("Thank you for signup", "nickname check", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				System::Windows::Forms::MessageBox::Show("something wrong..", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			}
			break;
		}

		}

	}
	};
}
