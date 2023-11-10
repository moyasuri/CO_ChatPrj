#pragma once

#include "enum.h"
#include "MyFunction.h"
#include "FindAccountForm.h"
#include "SignupForm.h"
#include "MainForm.h"

namespace MyClient {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace System::Net;
	//using namespace System::Net::Sockets;
	//using namespace System::Text;



	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private:
		SignupForm^ signupForm = nullptr;
		FindAccountForm^ findaccountForm = nullptr;
		MainForm^ mainForm = nullptr;




	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

		}

		MyForm(MyFunction^ my)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			_my = my;
			_my->MyEvent += gcnew Action<String^>(this, &MyForm::ReceivedMsg);
		}

	public:
		//void RegisterMessageHandlerForNewTest(NewTest^ newTestForm);

	private: MyFunction^ _my;
	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}

			if (_my != nullptr)
			{
				_my->MyEvent -= gcnew Action<String^>(this, &MyForm::ReceivedMsg);
			}

		}




	//public:
	//	delegate void MessageReceivedHandler(String^ message);
	//	static event MessageReceivedHandler^ MessageReceived;



	private:
		TextBox^ messageTextBox;
		TextBox^ chatTextBox;

	private: System::Windows::Forms::Button^ btnSignin;


	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::TextBox^ txtBoxPW;

	private: System::Windows::Forms::Button^ btnduplicate;








	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btnSignUp;

	private: System::Windows::Forms::Button^ btnExit;

	private: System::Windows::Forms::Button^ btnFindAccount;



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
			this->btnSignin = (gcnew System::Windows::Forms::Button());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->btnduplicate = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnSignUp = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnFindAccount = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnSignin
			// 
			this->btnSignin->Location = System::Drawing::Point(865, 541);
			this->btnSignin->Margin = System::Windows::Forms::Padding(4);
			this->btnSignin->Name = L"btnSignin";
			this->btnSignin->Size = System::Drawing::Size(221, 80);
			this->btnSignin->TabIndex = 2;
			this->btnSignin->Text = L"signin";
			this->btnSignin->UseVisualStyleBackColor = true;
			this->btnSignin->Click += gcnew System::EventHandler(this, &MyForm::btnSignin_Click);
			// 
			// txtBoxID
			// 
			this->txtBoxID->Location = System::Drawing::Point(505, 632);
			this->txtBoxID->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(325, 28);
			this->txtBoxID->TabIndex = 3;
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->Location = System::Drawing::Point(505, 686);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->Size = System::Drawing::Size(325, 28);
			this->txtBoxPW->TabIndex = 3;
			// 
			// btnduplicate
			// 
			this->btnduplicate->BackColor = System::Drawing::Color::Transparent;
			this->btnduplicate->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnduplicate->FlatAppearance->BorderSize = 0;
			this->btnduplicate->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnduplicate->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnduplicate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnduplicate->Location = System::Drawing::Point(1103, 53);
			this->btnduplicate->Margin = System::Windows::Forms::Padding(4);
			this->btnduplicate->Name = L"btnduplicate";
			this->btnduplicate->Size = System::Drawing::Size(195, 90);
			this->btnduplicate->TabIndex = 4;
			this->btnduplicate->UseVisualStyleBackColor = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(359, 618);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 18);
			this->label1->TabIndex = 5;
			this->label1->Text = L"ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(359, 684);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 18);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Password";
			// 
			// btnSignUp
			// 
			this->btnSignUp->BackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignUp->FlatAppearance->BorderSize = 0;
			this->btnSignUp->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignUp->Location = System::Drawing::Point(1120, 536);
			this->btnSignUp->Margin = System::Windows::Forms::Padding(4);
			this->btnSignUp->Name = L"btnSignUp";
			this->btnSignUp->Size = System::Drawing::Size(195, 90);
			this->btnSignUp->TabIndex = 4;
			this->btnSignUp->Text = L"signup";
			this->btnSignUp->UseVisualStyleBackColor = false;
			this->btnSignUp->Click += gcnew System::EventHandler(this, &MyForm::btnSignUp_Click);
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::Transparent;
			this->btnExit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnExit->FlatAppearance->BorderSize = 0;
			this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->Location = System::Drawing::Point(1120, 653);
			this->btnExit->Margin = System::Windows::Forms::Padding(4);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(195, 90);
			this->btnExit->TabIndex = 4;
			this->btnExit->Text = L"exit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// btnFindAccount
			// 
			this->btnFindAccount->BackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnFindAccount->FlatAppearance->BorderSize = 0;
			this->btnFindAccount->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFindAccount->Location = System::Drawing::Point(880, 653);
			this->btnFindAccount->Margin = System::Windows::Forms::Padding(4);
			this->btnFindAccount->Name = L"btnFindAccount";
			this->btnFindAccount->Size = System::Drawing::Size(195, 90);
			this->btnFindAccount->TabIndex = 4;
			this->btnFindAccount->Text = L"findaccount";
			this->btnFindAccount->UseVisualStyleBackColor = false;
			this->btnFindAccount->Click += gcnew System::EventHandler(this, &MyForm::btnFindAccount_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1328, 804);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->btnSignUp);
			this->Controls->Add(this->btnFindAccount);
			this->Controls->Add(this->btnduplicate);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->txtBoxID);
			this->Controls->Add(this->btnSignin);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//// Enter 키를 누를 때 메시지 전송
		//void SendMessageOnEnter(Object^ sender, KeyPressEventArgs^ e)
		//{
		//	if (e->KeyChar == (Char)Keys::Enter)
		//	{
		//		SendMessage(String^  message);
		//	}
		//}

		// 메시지 전송


		// 서버로부터 메시지를 수신하고 UI 업데이트

		





	//public:	void MyForm::HandleMessage(String^ message);

	private: System::Void btnSignin_Click(System::Object^ sender, System::EventArgs^ e)
	{
		btnSignin->NotifyDefault(false);
		SendMessageForm(e_id_try_Signin);
	}


	public: void SendMessageForm(int index)
	{

		switch (index)
		{
		case e_id_try_Signin:
			String^ tmptxt_1 = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.
			String^ tmptxt_2 = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.

			int t_index = e_id_try_Signin;

			String^ buffer = t_index.ToString()+ " " + tmptxt_1 + " " + tmptxt_2;
			_my->SendMessage(buffer);
			break;
		}

	}

	//public: void SetMyFunction(MyFunction^ my)
	//{
	//	_my = my;
	//	_my->MyEvent += gcnew Action<String^>(this, &MyForm::ReceivedMsg);
	//}


	public: void ReceivedMsg(String^ message)
	{
		String^ inputString = message;

		array<String^>^ subString = inputString->Split(' ');

		String^ index_s = subString[0];
		String^ isTrue = subString[1];
		int index = Int32::Parse(index_s);

		switch (index)
		{
			// Hide 할때의 동작			

			case e_id_try_Signin:
			{

				if (isTrue == "true")
				{
					this->Invoke(gcnew MethodInvoker(this, &MyForm::MainFormShow));
			
				}
				else
				{
					System::Windows::Forms::MessageBox::Show("Check the ID and Password", "warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
				break;
			}
				
		}

	
	}

		  public: void MainFormShow()
		  {
			  if (mainForm == nullptr || mainForm->IsDisposed) {
				  mainForm = gcnew MainForm(_my);
				  mainForm->Owner = this; // Owner를 설정해야 가능
				  this->Hide();
				  //this->HomeImageSound->Stop();
				  mainForm->Show();
			  }
			  return;
		  }



private: System::Void btnFindAccount_Click(System::Object^ sender, System::EventArgs^ e) {
	btnFindAccount->NotifyDefault(false);

	if (findaccountForm == nullptr || findaccountForm->IsDisposed) {
		findaccountForm = gcnew FindAccountForm(_my);
		findaccountForm->Show();
	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		findaccountForm->Activate();
	}

}
private: System::Void btnSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
		btnSignUp->NotifyDefault(false);

	if (signupForm == nullptr || signupForm->IsDisposed) {
		signupForm = gcnew SignupForm(_my);
		signupForm->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		signupForm->Activate();
	}

}
private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
	
	this->Close();

}
};
}
