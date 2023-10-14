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
		


	private: System::Windows::Forms::TextBox^ textBox; // 텍스트 상자를 멤버 변수로 추가
	private: System::Windows::Forms::TextBox^ txtBoxPW;
		   // 텍스트 상자를 멤버 변수로 추가
	private: System::Windows::Forms::Form^ newForm;
	private: System::Windows::Forms::Button^ btnFindAccount;
	private: System::Windows::Forms::PictureBox^ PicBoxIntro;
	private: System::Windows::Forms::Timer^ timerDeletePicBoxIntro;





	private: System::Windows::Forms::PictureBox^ pictureBox1;




	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
						// sound 추가해보기
			SoundPlayer^ sound = gcnew SoundPlayer;
			System::String^ currentDirectory = System::IO::Directory::GetCurrentDirectory();
			// System::String을 C++ 문자열로 변환합니다.
			std::string currentDirectoryStr = msclr::interop::marshal_as<std::string>(currentDirectory);

			// 상위 폴더의 경로를 얻기 위해 역슬래시를 찾아서 잘라냅니다.
			size_t pos = currentDirectoryStr.find_last_of("\\");
			
			std::string parentDirectoryStr = currentDirectoryStr.substr(0, pos);
			System::String^ parentDirectory = gcnew System::String(parentDirectoryStr.c_str());


			// intro
			timerDeletePicBoxIntro = gcnew System::Windows::Forms::Timer();
			timerDeletePicBoxIntro->Interval = 20000; // 3초 (3000 밀리초)
			timerDeletePicBoxIntro->Tick += gcnew System::EventHandler(this, &MyForm::timerDeletePicBoxIntro_Tick);
			timerDeletePicBoxIntro->Start();
		
			
			

		
		 

		 	// MessageBox::Show(currentDirectoryStr, "caption", MessageBoxButtons::OK, MessageBoxIcon::Information);

			sound->SoundLocation = parentDirectory+"\\Media\\shootingstar.wav"; // SoundLocation에 CLI 문자열을 설정
			sound->Load();
			sound->Play();


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

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnSignup;




		   // private: System::Windows::Forms::TextBox^ textBox2;




	private: System::Windows::Forms::Button^ button3;
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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnFindAccount = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->PicBoxIntro = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxIntro))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSignin
			// 
			this->btnSignin->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnSignin->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnSignin->Location = System::Drawing::Point(584, 527);
			this->btnSignin->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignin->Name = L"btnSignin";
			this->btnSignin->Size = System::Drawing::Size(171, 41);
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
			this->label2->Location = System::Drawing::Point(322, 500);
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
			this->label3->Location = System::Drawing::Point(322, 567);
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
			this->txtBoxID->Location = System::Drawing::Point(327, 535);
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
			this->txtBoxPW->Location = System::Drawing::Point(327, 601);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(201, 23);
			this->txtBoxPW->TabIndex = 10;
			// 
			// btnExit
			// 
			this->btnExit->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnExit->ForeColor = System::Drawing::Color::Firebrick;
			this->btnExit->Location = System::Drawing::Point(584, 592);
			this->btnExit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(171, 41);
			this->btnExit->TabIndex = 11;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = false;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// btnSignup
			// 
			this->btnSignup->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnSignup->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnSignup->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnSignup->Location = System::Drawing::Point(859, 527);
			this->btnSignup->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignup->Name = L"btnSignup";
			this->btnSignup->Size = System::Drawing::Size(171, 41);
			this->btnSignup->TabIndex = 12;
			this->btnSignup->Text = L"Sign up";
			this->btnSignup->UseVisualStyleBackColor = false;
			this->btnSignup->Click += gcnew System::EventHandler(this, &MyForm::btn_signup_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(550, 218);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(338, 112);
			this->button3->TabIndex = 13;
			this->button3->Text = L"test";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// btnFindAccount
			// 
			this->btnFindAccount->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->btnFindAccount->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnFindAccount->ForeColor = System::Drawing::Color::DarkBlue;
			this->btnFindAccount->Location = System::Drawing::Point(859, 592);
			this->btnFindAccount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnFindAccount->Name = L"btnFindAccount";
			this->btnFindAccount->Size = System::Drawing::Size(171, 41);
			this->btnFindAccount->TabIndex = 14;
			this->btnFindAccount->Text = L"Find Account";
			this->btnFindAccount->UseVisualStyleBackColor = false;
			this->btnFindAccount->Click += gcnew System::EventHandler(this, &MyForm::btnFindAccount_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(20, 487);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(246, 147);
			this->pictureBox1->TabIndex = 15;
			this->pictureBox1->TabStop = false;
			// 
			// PicBoxIntro
			// 
			this->PicBoxIntro->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PicBoxIntro.Image")));
			this->PicBoxIntro->Location = System::Drawing::Point(-6, -5);
			this->PicBoxIntro->Margin = System::Windows::Forms::Padding(2);
			this->PicBoxIntro->Name = L"PicBoxIntro";
			this->PicBoxIntro->Size = System::Drawing::Size(1118, 653);
			this->PicBoxIntro->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PicBoxIntro->TabIndex = 16;
			this->PicBoxIntro->TabStop = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1109, 646);
			this->Controls->Add(this->PicBoxIntro);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnFindAccount);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnSignup);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->txtBoxID);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnSignin);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PicBoxIntro))->EndInit();
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







	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {



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
		confirmButton->Click += gcnew System::EventHandler(this, &MyForm::confirmButton_Click);
		newForm->Controls->Add(confirmButton);

		// 새로운 폼을 표시
		newForm->Show();



	}

	private: System::Void confirmButton_Click(System::Object^ sender, System::EventArgs^ e) {


		String^ inputText = textBox->Text;


		std::string nick = msclr::interop::marshal_as<std::string>(inputText);

		// my_nick에 값 할당
		my_nick = nick;
		// 이곳에서 inputText를 사용하거나 저장할 수 있습니다.

		// 새로운 폼 종료
		newForm->Close();
	}




		   // Signin button : database 에서 ID : password  일치하는지 확인하는 함수
		   // ID PW 가 일치하지 않을때는 : ID 또는 PW가 일치하지 않습니다는 메세지를 송출
		   // 없으면 없다고 하기

	private: System::Void btnSignin_Click(System::Object^ sender, System::EventArgs^ e) {

		//// 텍스트 상자에서 텍스트 가져오기
		//String^ textBoxText = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.

		//if (!String::IsNullOrEmpty(textBoxText)) {
		//	// 텍스트 상자에 텍스트가 비어 있지 않으면 Message Box로 출력
		//	MessageBox::Show(textBoxText, "텍스트 상자 내용", MessageBoxButtons::OK, MessageBoxIcon::Information);
		//}
		//else {
		//	// 텍스트 상자가 비어 있을 때 메시지를 출력할 수 있습니다.
		//	MessageBox::Show("텍스트 상자가 비어 있습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		//}

		//textBoxText = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.

		//if (!String::IsNullOrEmpty(textBoxText)) {
		//	// 텍스트 상자에 텍스트가 비어 있지 않으면 Message Box로 출력
		//	MessageBox::Show(textBoxText, "텍스트 상자 내용", MessageBoxButtons::OK, MessageBoxIcon::Information);
		//}
		//else {
		//	// 텍스트 상자가 비어 있을 때 메시지를 출력할 수 있습니다.
		//	MessageBox::Show("텍스트 상자가 비어 있습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		//}

	
			
		if (mainForm == nullptr || mainForm->IsDisposed) {
			mainForm = gcnew MainForm();
			mainForm->Owner = this;
			this->Hide(); 
			mainForm->Show();
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
	   }



};
}
