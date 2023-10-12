#pragma once
#include "SignUp.h"
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


	private: System::Windows::Forms::TextBox^ textBox; // 텍스트 상자를 멤버 변수로 추가
	private: System::Windows::Forms::TextBox^ txtBoxPW;
		   // 텍스트 상자를 멤버 변수로 추가
	private: System::Windows::Forms::Form^ newForm;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
						// sound 추가해보기
			SoundPlayer^ sound = gcnew SoundPlayer;
			sound->SoundLocation = "C:\\Data\\02.Code\\CO_ChatPrj\\CO_ChatPrj\\Media\\shootingstar.wav";
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
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSignin;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txtBoxID;
	private: System::Windows::Forms::Button^ btnExit;
	private: System::Windows::Forms::Button^ btnSignup;




	// private: System::Windows::Forms::TextBox^ textBox2;




	private: System::Windows::Forms::Button^ button3;







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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSignin = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txtBoxID = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxPW = (gcnew System::Windows::Forms::TextBox());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->btnSignup = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Georgia", 24));
			this->label1->Location = System::Drawing::Point(101, 488);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(144, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Sign in";
			// 
			// btnSignin
			// 
			this->btnSignin->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnSignin->Location = System::Drawing::Point(527, 527);
			this->btnSignin->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignin->Name = L"btnSignin";
			this->btnSignin->Size = System::Drawing::Size(171, 41);
			this->btnSignin->TabIndex = 1;
			this->btnSignin->Text = L"Sign in";
			this->btnSignin->UseVisualStyleBackColor = true;
			this->btnSignin->Click += gcnew System::EventHandler(this, &MyForm::btnSignin_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Georgia", 12));
			this->label2->Location = System::Drawing::Point(272, 500);
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
			this->label3->Location = System::Drawing::Point(272, 567);
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
			this->txtBoxID->Location = System::Drawing::Point(277, 535);
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
			this->txtBoxPW->Location = System::Drawing::Point(277, 601);
			this->txtBoxPW->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBoxPW->MaxLength = 16;
			this->txtBoxPW->Name = L"txtBoxPW";
			this->txtBoxPW->PasswordChar = '*';
			this->txtBoxPW->Size = System::Drawing::Size(201, 23);
			this->txtBoxPW->TabIndex = 10;
			// 
			// btnExit
			// 
			this->btnExit->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnExit->ForeColor = System::Drawing::Color::DarkSlateBlue;
			this->btnExit->Location = System::Drawing::Point(527, 592);
			this->btnExit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(171, 41);
			this->btnExit->TabIndex = 11;
			this->btnExit->Text = L"Exit";
			this->btnExit->UseVisualStyleBackColor = true;
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// btnSignup
			// 
			this->btnSignup->Font = (gcnew System::Drawing::Font(L"Georgia", 14));
			this->btnSignup->ForeColor = System::Drawing::SystemColors::Highlight;
			this->btnSignup->Location = System::Drawing::Point(888, 529);
			this->btnSignup->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSignup->Name = L"btnSignup";
			this->btnSignup->Size = System::Drawing::Size(171, 41);
			this->btnSignup->TabIndex = 12;
			this->btnSignup->Text = L"Sign up";
			this->btnSignup->UseVisualStyleBackColor = true;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1109, 646);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnSignup);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->txtBoxPW);
			this->Controls->Add(this->txtBoxID);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btnSignin);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	// sign up form을 띄우기.
	private: System::Void btn_signup_Click(System::Object^ sender, System::EventArgs^ e) {
		SignUp^ signupForm = gcnew SignUp;
		signupForm->Show();
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
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

		// 텍스트 상자에서 텍스트 가져오기
		String^ textBoxText = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.

		if (!String::IsNullOrEmpty(textBoxText)) {
			// 텍스트 상자에 텍스트가 비어 있지 않으면 Message Box로 출력
			MessageBox::Show(textBoxText, "텍스트 상자 내용", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			// 텍스트 상자가 비어 있을 때 메시지를 출력할 수 있습니다.
			MessageBox::Show("텍스트 상자가 비어 있습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

		textBoxText = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.

		if (!String::IsNullOrEmpty(textBoxText)) {
			// 텍스트 상자에 텍스트가 비어 있지 않으면 Message Box로 출력
			MessageBox::Show(textBoxText, "텍스트 상자 내용", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			// 텍스트 상자가 비어 있을 때 메시지를 출력할 수 있습니다.
			MessageBox::Show("텍스트 상자가 비어 있습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}

	}
};
}
