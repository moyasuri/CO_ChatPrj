#pragma once
#include "SignUp.h"
#include "MainForm.h"
#include "FindAccount.h"
#include <msclr/marshal_cppstd.h>
#include <string>


static std::string my_nick;
static SOCKET client_sock;
static bool enterServer;
static bool isExit;


namespace GUI {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;
	



	/// <summary>
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		// MyForm 클래스 내에서 사용할 sub 폼의 인스턴스를 생성합니다.
	private:
		SignUp^ signupForm = nullptr;
		FindAccount^ findaccountForm = nullptr;
		MainForm^ mainForm =nullptr;
	private: bool isFirstActivation = true;

	
	
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::Button^ btnFindAccount;
	private: System::Windows::Forms::Timer^ timerDeletePicBoxIntro;
	private: System::Windows::Forms::PictureBox^ PicBoxIntro;
	private: SoundPlayer^ IntroImageSound = gcnew SoundPlayer;
	private: SoundPlayer^ HomeImageSound = gcnew SoundPlayer;
	private: System::String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
	private: System::Windows::Forms::PictureBox^ PicBoxHomeLogo;
	private: System::Windows::Forms::PictureBox^ PicBoxNagareboshi;

	private: System::String^ relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\HomeIntro.gif");
		   


	public:
		MyForm(void)
		{


			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//

			// Image 추가
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\constantmoderato.wav");
			
			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\HomeIntro.gif");
			PicBoxIntro->ImageLocation = relativePath;

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\Trinity_Logo.gif");
			PicBoxHomeLogo->ImageLocation = relativePath;

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\shootingstar.wav");
			HomeImageSound->SoundLocation = relativePath;

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\nagareboshi2.gif");
			PicBoxNagareboshi->ImageLocation = relativePath;

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\nagareboshi2.gif");
			PicBoxNagareboshi->ImageLocation = relativePath;


			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\Blue_menu.png");
			btnFindAccount->BackgroundImage = Image::FromFile(relativePath);
			btnExit->BackgroundImage = Image::FromFile(relativePath);
			btnSignin->BackgroundImage = Image::FromFile(relativePath);

			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\temp\\Yellow_menu.png");
			btnSignup->BackgroundImage = Image::FromFile(relativePath);

			// 이미지 추가 끝


			// sound 추가
						
			IntroImageSound->SoundLocation = relativePath; // SoundLocation에 CLI 문자열을 설정
			IntroImageSound->Load();
			IntroImageSound->Play();


			// intro 삭제 타이머
			
			timerDeletePicBoxIntro = gcnew System::Windows::Forms::Timer();
			timerDeletePicBoxIntro->Interval = 6000; 
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &MyForm::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();





		}




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
		}

	private: System::Windows::Forms::Button^ btnSignin;
    private: System::Windows::Forms::TextBox^ txtBoxPW;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnSignup;


	private: System::ComponentModel::IContainer^ components;



	protected:

	private:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnSignin = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnSignup = (gcnew System::Windows::Forms::Button());
			this->btnFindAccount = (gcnew System::Windows::Forms::Button());
			this->PicBoxIntro = (gcnew System::Windows::Forms::PictureBox());
			this->PicBoxHomeLogo = (gcnew System::Windows::Forms::PictureBox());
			this->PicBoxNagareboshi = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxIntro))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxHomeLogo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxNagareboshi))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSignin
			// 
			this->btnSignin->BackColor = System::Drawing::Color::Transparent;
			this->btnSignin->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignin->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->btnSignin->FlatAppearance->BorderSize = 0;
			this->btnSignin->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignin->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignin->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnSignin->Location = System::Drawing::Point(575, 451);
			this->btnSignin->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignin->Name = L"btnSignin";
			this->btnSignin->Size = System::Drawing::Size(250, 120);
			this->btnSignin->TabIndex = 1;
			this->btnSignin->Text = L"Sign in";
			this->btnSignin->UseVisualStyleBackColor = false;
			this->btnSignin->Click += gcnew System::EventHandler(this, &MyForm::btnSignin_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label2->Location = System::Drawing::Point(322, 468);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"ID";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label3->Location = System::Drawing::Point(322, 552);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(95, 24);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Password";
			// 
			// txtBoxID
			// 
			this->txtBoxID->BackColor = System::Drawing::Color::MintCream;
			this->txtBoxID->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxID->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->txtBoxID->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxID->Location = System::Drawing::Point(327, 503);
			this->txtBoxID->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxID->Name = L"txtBoxID";
			this->txtBoxID->Size = System::Drawing::Size(201, 23);
			this->txtBoxID->TabIndex = 7;
			// 
			// txtBoxPW
			// 
			this->txtBoxPW->BackColor = System::Drawing::Color::MintCream;
			this->txtBoxPW->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->txtBoxPW->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->txtBoxPW->ForeColor = System::Drawing::SystemColors::WindowFrame;
			this->txtBoxPW->Location = System::Drawing::Point(327, 586);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(201, 23);
			this->txtBoxPW->TabIndex = 10;
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::Color::Transparent;
			this->btnExit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnExit->FlatAppearance->BorderSize = 0;
			this->btnExit->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnExit->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnExit->ForeColor = System::Drawing::Color::Firebrick;
			this->btnExit->Location = System::Drawing::Point(571, 540);
			this->btnExit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(250, 120);
			this->btnExit->TabIndex = 11;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// btnSignup
			// 
			this->btnSignup->BackColor = System::Drawing::Color::Transparent;
			this->btnSignup->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnSignup->FlatAppearance->BorderSize = 0;
			this->btnSignup->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnSignup->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnSignup->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignup->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnSignup->ForeColor = System::Drawing::SystemColors::Desktop;
			this->btnSignup->Location = System::Drawing::Point(792, 451);
			this->btnSignup->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignup->Name = L"btnSignup";
			this->btnSignup->Size = System::Drawing::Size(307, 120);
			this->btnSignup->TabIndex = 12;
			this->btnSignup->Text = L"Sign up";
			this->btnSignup->UseVisualStyleBackColor = false;
			this->btnSignup->Click += gcnew System::EventHandler(this, &MyForm::btn_signup_Click);
			// 
			// btnFindAccount
			// 
			this->btnFindAccount->BackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnFindAccount->FlatAppearance->BorderSize = 0;
			this->btnFindAccount->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnFindAccount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnFindAccount->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnFindAccount->ForeColor = System::Drawing::Color::Black;
			this->btnFindAccount->Location = System::Drawing::Point(781, 540);
			this->btnFindAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnFindAccount->Name = L"btnFindAccount";
			this->btnFindAccount->Size = System::Drawing::Size(322, 120);
			this->btnFindAccount->TabIndex = 14;
			this->btnFindAccount->Text = L"Find Account";
			this->btnFindAccount->UseVisualStyleBackColor = false;
			this->btnFindAccount->Click += gcnew System::EventHandler(this, &MyForm::btnFindAccount_Click);
			// 
			// PicBoxIntro
			// 
			this->PicBoxIntro->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->PicBoxIntro->Location = System::Drawing::Point(-17, -5);
			this->PicBoxIntro->Margin = System::Windows::Forms::Padding(2);
			this->PicBoxIntro->Name = L"PicBoxIntro";
			this->PicBoxIntro->Size = System::Drawing::Size(1144, 655);
			this->PicBoxIntro->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PicBoxIntro->TabIndex = 16;
			this->PicBoxIntro->TabStop = false;
			this->PicBoxIntro->WaitOnLoad = true;
			// 
			// PicBoxHomeLogo
			// 
			this->PicBoxHomeLogo->BackColor = System::Drawing::Color::Transparent;
			this->PicBoxHomeLogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->PicBoxHomeLogo->Location = System::Drawing::Point(76, 428);
			this->PicBoxHomeLogo->Margin = System::Windows::Forms::Padding(2);
			this->PicBoxHomeLogo->Name = L"PicBoxHomeLogo";
			this->PicBoxHomeLogo->Size = System::Drawing::Size(200, 208);
			this->PicBoxHomeLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PicBoxHomeLogo->TabIndex = 17;
			this->PicBoxHomeLogo->TabStop = false;
			// 
			// PicBoxNagareboshi
			// 
			this->PicBoxNagareboshi->BackColor = System::Drawing::Color::Transparent;
			this->PicBoxNagareboshi->Location = System::Drawing::Point(-37, -46);
			this->PicBoxNagareboshi->Margin = System::Windows::Forms::Padding(2);
			this->PicBoxNagareboshi->Name = L"PicBoxNagareboshi";
			this->PicBoxNagareboshi->Size = System::Drawing::Size(1183, 720);
			this->PicBoxNagareboshi->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PicBoxNagareboshi->TabIndex = 18;
			this->PicBoxNagareboshi->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1109, 646);
			this->Controls->Add(this->btnSignup);
			this->Controls->Add(this->btnSignin);
			this->Controls->Add(this->PicBoxHomeLogo);
			this->Controls->Add(this->btnFindAccount);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->txtBoxID);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->PicBoxNagareboshi);
			this->Controls->Add(this->PicBoxIntro);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->VisibleChanged += gcnew System::EventHandler(this, &MyForm::MyForm_Visible);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxIntro))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxHomeLogo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxNagareboshi))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



		// sign up form을 띄우기.
	private: System::Void btn_signup_Click(System::Object^ sender, System::EventArgs^ e) {
		// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.
		if (signupForm == nullptr || signupForm->IsDisposed) {
			signupForm = gcnew SignUp;
			signupForm->Show();
		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			signupForm->Activate();
		}
	}





		   // Signin button : database 에서 ID : password  일치하는지 확인하는 함수
		   // ID PW 가 일치하지 않을때는 : ID 또는 PW가 일치하지 않습니다는 메세지를 송출
		   // 없으면 없다고 하기

	private: System::Void btnSignin_Click(System::Object^ sender, System::EventArgs^ e) {



		// 텍스트 상자에서 텍스트 가져오기
		String^ textID_ = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		String^ textPW_ = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.
		

		// ID와 PW의 문자열이 채워져있다면
		if (!String::IsNullOrEmpty(textID_)&& !String::IsNullOrEmpty(textPW_)) {

			// Server에 ID / PW를 보내기함수


			while(1)
			{
				if (1)// server 에서 오케이
				{

					return;
				}
				else if(1) //  server에서 다른값보내면
				{

					return;
				}
				else // 무한반복되는건데 시간타이밍 주면 좋을거같음
				{

				}
			}
		}
		// 입력값이 없다면,
		else {
			System::Windows::Forms::MessageBox::Show("ID / PW 를 다시입력해주세요. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}


	}

	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->Close();
	}


	private: System::Void btnFindAccount_Click(System::Object^ sender, System::EventArgs^ e) {
	
		// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.
		if (findaccountForm == nullptr || findaccountForm->IsDisposed) {
			findaccountForm = gcnew FindAccount;
			findaccountForm->Show();
		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			findaccountForm->Activate();
		}
	}

	// intro 삭제
    private: System::Void timerDeletePicBoxIntro_Tick(System::Object^ sender, System::EventArgs^ e) {
    
	    this->Controls->Remove(PicBoxIntro); // 컨트롤을 폼에서 제거
	    delete PicBoxIntro; // 메모리에서 해제
	    // Timer를 중지합니다.
	    timerDeletePicBoxIntro->Stop();
		IntroImageSound->Stop();
		HomeImageSound->Play();


    }
	private: System::Void MyForm_Visible(System::Object^ sender, System::EventArgs^ e) {
		// 이 폼이 활성화될 때 수행하고자 하는 동작을 여기에 추가합니다.
		if (isFirstActivation) {
			isFirstActivation = false;
			return; // 처음 활성화 시 함수 실행을 건너뛰기
		}

		HomeImageSound->Play();
	}

};
}
