#pragma once

#include <msclr/marshal_cppstd.h>
#include <string>
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
	private: System::String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
	private: System::Windows::Forms::PictureBox^ picBoxImojiMy;


	private: System::String^ relativePath;
	private: System::Windows::Forms::PictureBox^ picBoxImojiYou;

	private: System::Windows::Forms::Timer^ timerDeletePicBoxIntro;
	public:
		ServerChat(void)
		{
			
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
			this->picBoxImojiMy->Hide();
			this->picBoxImojiYou->Hide();
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\backroundServer.jpg");
			this->BackgroundImage = Image::FromFile(relativePath);
			timerDeletePicBoxIntro = gcnew System::Windows::Forms::Timer();
			
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\send.png");
			btnSend->BackgroundImage = Image::FromFile(relativePath);
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\close.png");
			btnClose->BackgroundImage = Image::FromFile(relativePath);
			
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

	private: System::Windows::Forms::TextBox^ txtBoxMyChat;
	private: System::Windows::Forms::Button^ btnSend;
	private: System::Windows::Forms::Button^ btnClose;
	


	public:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ServerChat::typeid));
			this->txtBoxChatWindow = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxMyChat = (gcnew System::Windows::Forms::TextBox());
			this->btnSend = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->picBoxImojiMy = (gcnew System::Windows::Forms::PictureBox());
			this->picBoxImojiYou = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->BeginInit();
			this->SuspendLayout();
			// 
			// txtBoxChatWindow
			// 
			this->txtBoxChatWindow->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->txtBoxChatWindow->Location = System::Drawing::Point(56, 72);
			this->txtBoxChatWindow->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxChatWindow->Multiline = true;
			this->txtBoxChatWindow->Name = L"txtBoxChatWindow";
			this->txtBoxChatWindow->ReadOnly = true;
			this->txtBoxChatWindow->Size = System::Drawing::Size(459, 417);
			this->txtBoxChatWindow->TabIndex = 0;
			// 
			// txtBoxMyChat
			// 
			this->txtBoxMyChat->Location = System::Drawing::Point(56, 525);
			this->txtBoxMyChat->Margin = System::Windows::Forms::Padding(4);
			this->txtBoxMyChat->Name = L"txtBoxMyChat";
			this->txtBoxMyChat->Size = System::Drawing::Size(459, 28);
			this->txtBoxMyChat->TabIndex = 2;
			this->txtBoxMyChat->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &ServerChat::txtBoxChat_KeyPress);
			// 
			// btnSend
			// 
			this->btnSend->BackColor = System::Drawing::Color::Transparent;
			this->btnSend->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSend.BackgroundImage")));
			this->btnSend->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSend->FlatAppearance->BorderSize = 0;
			this->btnSend->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSend->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSend->Location = System::Drawing::Point(61, 610);
			this->btnSend->Margin = System::Windows::Forms::Padding(4);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(196, 61);
			this->btnSend->TabIndex = 3;
			this->btnSend->UseVisualStyleBackColor = false;
			this->btnSend->Click += gcnew System::EventHandler(this, &ServerChat::btnSend_Click);
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
			this->btnClose->Location = System::Drawing::Point(316, 610);
			this->btnClose->Margin = System::Windows::Forms::Padding(4);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(199, 61);
			this->btnClose->TabIndex = 4;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &ServerChat::btnClose_Click);
			// 
			// picBoxImojiMy
			// 
			this->picBoxImojiMy->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiMy->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picBoxImojiMy->ErrorImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxImojiMy.ErrorImage")));
			this->picBoxImojiMy->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoxImojiMy.InitialImage")));
			this->picBoxImojiMy->Location = System::Drawing::Point(56, 72);
			this->picBoxImojiMy->Name = L"picBoxImojiMy";
			this->picBoxImojiMy->Size = System::Drawing::Size(135, 154);
			this->picBoxImojiMy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBoxImojiMy->TabIndex = 5;
			this->picBoxImojiMy->TabStop = false;
			// 
			// picBoxImojiYou
			// 
			this->picBoxImojiYou->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiYou->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picBoxImojiYou->Location = System::Drawing::Point(380, 72);
			this->picBoxImojiYou->Name = L"picBoxImojiYou";
			this->picBoxImojiYou->Size = System::Drawing::Size(135, 154);
			this->picBoxImojiYou->TabIndex = 6;
			this->picBoxImojiYou->TabStop = false;
			// 
			// ServerChat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(591, 735);
			this->Controls->Add(this->picBoxImojiYou);
			this->Controls->Add(this->picBoxImojiMy);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtBoxMyChat);
			this->Controls->Add(this->txtBoxChatWindow);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"ServerChat";
			this->Text = L"ServerChat";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
		btnSend->NotifyDefault(false);
		// server에게 메세지 보내기


		// 내꺼는 그냥 띄우면되고, 남에것만 가져오자.
		//-------------------임시-----------------//
				// Get the text from txtBoxMyChat
		String^ inputText = txtBoxMyChat->Text;

		// Append the text to txtBoxChatWindow
		txtBoxChatWindow->AppendText(inputText + Environment::NewLine);

		// Clear txtBoxMyChat
		txtBoxMyChat->Clear();
		//-------------------임시-----------------//

		
		if (this->ContCha(inputText,"ㅇㅇ"))
		{
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Imoji\\icon_49.gif");
			picBoxImojiMy->ImageLocation = relativePath;
			this->picBoxImojiMy->Show();


			timerDeletePicBoxIntro->Interval = 3000;
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &ServerChat::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();
		}
		else if(1)
		{
			return;
		}

		else
		{
			return;
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


	private: System::Void timerDeletePicBoxIntro_Tick(System::Object^ sender, System::EventArgs^ e) {

		this->picBoxImojiMy->Hide(); // 컨트롤을 폼에서 제거


	}

	private: bool ContCha(String^ str, const char* searchString) {
			   // .NET의 String을 C++/CLI의 문자열로 변환합니다.
			   std::string strCpp = msclr::interop::marshal_as<std::string>(str);

			   // C++ 스타일 문자열을 std::string으로 변환합니다.
			   std::string searchStringCpp = searchString;

			   // 문자열에서 부분 문자열의 포함 여부를 확인합니다.
			   return strCpp.find(searchStringCpp) != std::string::npos;
		   }
};
}
