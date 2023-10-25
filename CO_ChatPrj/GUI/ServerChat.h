#pragma once

#include <msclr/marshal_cppstd.h>
#include <string>
#include <sstream>
#include "UsageClient.h"


extern SOCKET client_sock;
extern std::string Recv_str;
extern std::string srvchat;
extern std::string prevMessage;
extern std::string flag;
extern std::string newMessage;
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

	private: System::Windows::Forms::Timer^ timer2;
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

			timer2 = gcnew System::Windows::Forms::Timer();
			timer2->Interval = 300;  // 1000ms = 1초
			timer2->Tick += gcnew System::EventHandler(this, &ServerChat::timer2_Tick);
			timer2->Start();
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
	private: System::ComponentModel::IContainer^ components;



	public:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>


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
			this->txtBoxChatWindow->Location = System::Drawing::Point(45, 60);
			this->txtBoxChatWindow->Multiline = true;
			this->txtBoxChatWindow->Name = L"txtBoxChatWindow";
			this->txtBoxChatWindow->ReadOnly = true;
			this->txtBoxChatWindow->Size = System::Drawing::Size(561, 348);
			this->txtBoxChatWindow->TabIndex = 0;
			// 
			// txtBoxMyChat
			// 
			this->txtBoxMyChat->Location = System::Drawing::Point(45, 438);
			this->txtBoxMyChat->Name = L"txtBoxMyChat";
			this->txtBoxMyChat->Size = System::Drawing::Size(561, 25);
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
			this->btnSend->Location = System::Drawing::Point(49, 508);
			this->btnSend->Name = L"btnSend";
			this->btnSend->Size = System::Drawing::Size(157, 51);
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
			this->btnClose->Location = System::Drawing::Point(446, 508);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(159, 51);
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
			this->picBoxImojiMy->Location = System::Drawing::Point(45, 60);
			this->picBoxImojiMy->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picBoxImojiMy->Name = L"picBoxImojiMy";
			this->picBoxImojiMy->Size = System::Drawing::Size(108, 128);
			this->picBoxImojiMy->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBoxImojiMy->TabIndex = 5;
			this->picBoxImojiMy->TabStop = false;
			// 
			// picBoxImojiYou
			// 
			this->picBoxImojiYou->BackColor = System::Drawing::Color::Transparent;
			this->picBoxImojiYou->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->picBoxImojiYou->Location = System::Drawing::Point(497, 60);
			this->picBoxImojiYou->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->picBoxImojiYou->Name = L"picBoxImojiYou";
			this->picBoxImojiYou->Size = System::Drawing::Size(108, 128);
			this->picBoxImojiYou->TabIndex = 6;
			this->picBoxImojiYou->TabStop = false;
			// 
			// ServerChat
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(710, 612);
			this->Controls->Add(this->picBoxImojiYou);
			this->Controls->Add(this->picBoxImojiMy);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnSend);
			this->Controls->Add(this->txtBoxMyChat);
			this->Controls->Add(this->txtBoxChatWindow);
			this->Name = L"ServerChat";
			this->Text = L"Chat";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &ServerChat::ServerChat_FormClosing);
			this->Load += gcnew System::EventHandler(this, &ServerChat::ServerChat_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiMy))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoxImojiYou))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



	private: System::Void btnSend_Click(System::Object^ sender, System::EventArgs^ e) {
		btnSend->NotifyDefault(false);
		// server에게 메세지 보내기
		IniMsg();
		String^ tmptxt_1 = txtBoxMyChat->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		if (!String::IsNullOrEmpty(tmptxt_1))
		{
			int time_limit = 0;
			std::string tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
			std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_Chat));
			std::string _Index_Str_Result = _Index_Str + delim + tmptxt_1_;
			const char* buffer = _Index_Str_Result.c_str();
			send(client_sock, buffer, strlen(buffer), 0);
		}

		
		if (this->ContCha(tmptxt_1,"ㅇㅇ"))
		{
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Imoji\\icon_49.gif");
			picBoxImojiMy->ImageLocation = relativePath;
			this->picBoxImojiMy->Show();


			timerDeletePicBoxIntro->Interval = 3000;
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &ServerChat::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();


		}

		if (this->ContCha(tmptxt_1, "Null"))
		{
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Imoji\\icon_16.png");
			picBoxImojiMy->ImageLocation = relativePath;
			this->picBoxImojiMy->Show();


			timerDeletePicBoxIntro->Interval = 3000;
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &ServerChat::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();


		}

		if (this->ContCha(tmptxt_1, "~~"))
		{
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Imoji\\icon_1.gif");
			picBoxImojiMy->ImageLocation = relativePath;
			this->picBoxImojiMy->Show();


			timerDeletePicBoxIntro->Interval = 3000;
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &ServerChat::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();


		}

		if (this->ContCha(tmptxt_1, "쪼아"))
		{
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Imoji\\icon_35.gif");
			picBoxImojiMy->ImageLocation = relativePath;
			this->picBoxImojiMy->Show();


			timerDeletePicBoxIntro->Interval = 3000;
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &ServerChat::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();


		}
		if (this->ContCha(tmptxt_1, "ㅠㅠ"))
		{
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Imoji\\icon_3.gif");
			picBoxImojiMy->ImageLocation = relativePath;
			this->picBoxImojiMy->Show();


			timerDeletePicBoxIntro->Interval = 3000;
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &ServerChat::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();


		}
	
		txtBoxMyChat->Clear();
		




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

private: System::Void ServerChat_Load(System::Object^ sender, System::EventArgs^ e) {


	IniMsg();


		std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_room_show_whole_Text));
		std::string _Index_Str_Result = _Index_Str;
		const char* buffer = _Index_Str_Result.c_str();

		send(client_sock, buffer, strlen(buffer), 0);
		

}

private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	
	std::stringstream Chat(Recv_str);
	std::string token;


	//Chat >> flag;
	//if (flag == "true" || flag == "false")
	//{
	//	flag = "";
	//	return;
	//}
	// 서버에서 받은 메시지를 새로운 메시지로 저장합니다.
	newMessage= Recv_str;

	 //이전 메시지와 새로운 메시지를 비교하여 같으면 처리하지 않습니다.
	if (newMessage == prevMessage) {
		return;
	}
	else
	{
		while (getline(Chat, token)) {
			txtBoxChatWindow->AppendText(msclr::interop::marshal_as<System::String^>(token) + Environment::NewLine);
		}
		prevMessage = Recv_str;
	}
}
private: System::Void ServerChat_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {

	timer2->Stop();
}
};
}
