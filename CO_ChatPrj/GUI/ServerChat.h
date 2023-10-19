#pragma once

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ServerChat에 대한 요약입니다.
	/// </summary>
	public ref class ServerChat : public System::Windows::Forms::Form
	{
	public:
		ServerChat(void)
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
		~ServerChat()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ txtBoxChatWindow;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txtBoxMyChat;

	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::Button^ btnClose;



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
			this->txtBoxChatWindow = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtBoxMyChat = (gcnew System::Windows::Forms::TextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxChatWindow
			// 
			this->txtBoxChatWindow->Location = System::Drawing::Point(118, 110);
			this->txtBoxChatWindow->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxChatWindow->Multiline = true;
			this->txtBoxChatWindow->Name = L"txtBoxChatWindow";
			this->txtBoxChatWindow->Size = System::Drawing::Size(702, 380);
			this->txtBoxChatWindow->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(55, 552);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 18);
			this->label1->TabIndex = 1;
			this->label1->Text = L"you";
			// 
			// txtBoxMyChat
			// 
			this->txtBoxMyChat->Location = System::Drawing::Point(118, 546);
			this->txtBoxMyChat->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxMyChat->Name = L"txtBoxMyChat";
			this->txtBoxMyChat->Size = System::Drawing::Size(702, 28);
			this->txtBoxMyChat->TabIndex = 2;
			this->txtBoxMyChat->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ServerChat::txtBoxChat_KeyPress);
			// 
			// btnSend
			// 
			this->btnSend->Location = System::Drawing::Point(242, 606);
			this->btnSend->Margin = System::Windows::Forms::Padding(4);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(186, 61);
			this->btnSend->TabIndex = 3;
			this->btnSend->Text = L"Send";
			this->btnSend->UseVisualStyleBackColor = true;
			this->btnSend->Click += gcnew System::EventHandler(this, &ServerChat::btnSend_Click);
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(521, 606);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(186, 61);
			this->btnClose->TabIndex = 4;
			this->btnClose->Text = L"Exit";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &ServerChat::btnClose_Click);
			// 
			// ServerChat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(940, 682);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtBoxMyChat);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxChatWindow);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ServerChat";
			this->Text = L"ServerChat";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
		
		// server에게 메세지 보내기


		//-------------------임시-----------------//
				// Get the text from txtBoxMyChat
		String^ inputText = txtBoxMyChat->Text;

		// Append the text to txtBoxChatWindow
		txtBoxChatWindow->AppendText(inputText + Environment::NewLine);

		// Clear txtBoxMyChat
		txtBoxMyChat->Clear();
		//-------------------임시-----------------//


		if (inputText == "ㅋㅋㅋ") {
			// Call your custom function (somefunction)
			
		}


	}
	
private: System::Void txtBoxChat_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		   // Check if Enter key (carriage return) was pressed
		   if (e->KeyChar == (char)Keys::Enter) {
			   // Trigger the "Send" button's click event
			   btnSend_Click(sender, e);
		   }
		   
	}

private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};
}
