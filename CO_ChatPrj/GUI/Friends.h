#pragma once
#pragma once
#include "AddFriend.h"
#include "FriendResponse.h"
#include <msclr/marshal_cppstd.h>
#include <string>
#include <cliext/vector>
#include <sstream>
#include "UsageClient.h"


extern SOCKET client_sock;
extern std::string Recv_str;


namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Friends에 대한 요약입니다.
	/// </summary>
	public ref class Friends : public System::Windows::Forms::Form
	{
	private:AddFriend^ addfriendform = nullptr;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

		   FriendResponse^ friendresponseform = nullptr;
	public:
		Friends(void)
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
		~Friends()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::ListBox^ listBoxFriends;
	protected:

	protected:

	private: System::Windows::Forms::Button^ btnResponse;
	private: System::Windows::Forms::Button^ btnDelete;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Friends::typeid));
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->listBoxFriends = (gcnew System::Windows::Forms::ListBox());
			this->btnResponse = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnAdd
			// 
			this->btnAdd->BackColor = System::Drawing::Color::Transparent;
			this->btnAdd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdd.BackgroundImage")));
			this->btnAdd->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnAdd->FlatAppearance->BorderSize = 0;
			this->btnAdd->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnAdd->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnAdd->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnAdd->Location = System::Drawing::Point(384, 120);
			this->btnAdd->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(194, 55);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->UseVisualStyleBackColor = false;
			this->btnAdd->Click += gcnew System::EventHandler(this, &Friends::btnAdd_Click);
			// 
			// listBoxFriends
			// 
			this->listBoxFriends->FormattingEnabled = true;
			this->listBoxFriends->ItemHeight = 15;
			this->listBoxFriends->Location = System::Drawing::Point(45, 108);
			this->listBoxFriends->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->listBoxFriends->Name = L"listBoxFriends";
			this->listBoxFriends->Size = System::Drawing::Size(316, 394);
			this->listBoxFriends->TabIndex = 1;
			// 
			// btnResponse
			// 
			this->btnResponse->BackColor = System::Drawing::Color::Transparent;
			this->btnResponse->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnResponse.BackgroundImage")));
			this->btnResponse->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnResponse->FlatAppearance->BorderSize = 0;
			this->btnResponse->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnResponse->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnResponse->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnResponse->Location = System::Drawing::Point(384, 210);
			this->btnResponse->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnResponse->Name = L"btnResponse";
			this->btnResponse->Size = System::Drawing::Size(194, 55);
			this->btnResponse->TabIndex = 0;
			this->btnResponse->UseVisualStyleBackColor = false;
			this->btnResponse->Click += gcnew System::EventHandler(this, &Friends::btnResponse_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::Color::Transparent;
			this->btnDelete->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDelete.BackgroundImage")));
			this->btnDelete->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btnDelete->FlatAppearance->BorderSize = 0;
			this->btnDelete->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->btnDelete->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->btnDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDelete->Location = System::Drawing::Point(384, 310);
			this->btnDelete->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(194, 55);
			this->btnDelete->TabIndex = 0;
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Friends::btnDelete_Click);
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
			this->btnClose->Location = System::Drawing::Point(384, 447);
			this->btnClose->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(194, 55);
			this->btnClose->TabIndex = 0;
			this->btnClose->UseVisualStyleBackColor = false;
			this->btnClose->Click += gcnew System::EventHandler(this, &Friends::btnClose_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24));
			this->label2->ForeColor = System::Drawing::Color::SlateGray;
			this->label2->Location = System::Drawing::Point(37, 38);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(227, 46);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Friend List";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(589, -17);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(751, 581);
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// Friends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->BackColor = System::Drawing::Color::FloralWhite;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(950, 561);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->listBoxFriends);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnResponse);
			this->Controls->Add(this->btnAdd);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Friends";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Friends";
			this->Activated += gcnew System::EventHandler(this, &Friends::Friends_Visible);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		if (addfriendform == nullptr || addfriendform->IsDisposed) {
			addfriendform = gcnew AddFriend;
			addfriendform->Owner = this;
			addfriendform->Show();

		}
		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
		else {
			addfriendform->Activate();
		}
	}
private: System::Void Friends_Visible(System::Object^ sender, System::EventArgs^ e) {
	listBoxFriends->Items->Clear();
	//String^ tmptxt_1; // textBox는 해당 텍스트 상자의 이름입니다.
	// std::string tmptxt_7_ = msclr::interop::marshal_as<std::string>(tmptxt_7);

	std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_List));

	std::string _Index_Str_Result = _Index_Str;
	const char* buffer = _Index_Str_Result.c_str();
	send(client_sock, buffer, strlen(buffer), 0);
	// std::stringstream ss(Recv_str);
	//ss >> _Index;
	//server_msg.push_back(_Contents);
	//_Contents = string(buf + 3);
	//server_msg.push_back(_Contents);


	// std::string inputString = "true emilie jiwon suwan sibaaal";


	// C++/CLI CLI 배열
	// cli::array<System::Object^>^ arr = gcnew cli::array<System::Object^>(1);

	// 공백으로 문자열 분할
	std::istringstream iss(Recv_str); // 살짝 문제가 있을거 같기도..
	std::string token;
	int count = 0;

	while (iss >> token) {
		if (count == 0 && token == "true") {
			// 첫 번째 단어가 "true"인 경우 넘어감
			count++;
			continue;
		}
		//System::String^ str = marshal_as<String^>(token);
		listBoxFriends->Items->Add(gcnew String(token.c_str()));
	}

	// List Box에 추가
	// listBoxFriends->Items->AddRange(vect);



	if (Recv_str == "true")// server 에서 오케이받는 함수
	{


		return;
	}
	else
	{
		return;
	}
}
private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	btnDelete->NotifyDefault(false);

	if (listBoxFriends->SelectedItem == nullptr) {
		System::Windows::Forms::MessageBox::Show("삭제하실 아이디를 선택해주세요", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	System::Windows::Forms::DialogResult result =
		System::Windows::Forms::MessageBox::Show("진짜 삭제할거야?", "경고", \
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning);


	if (result == System::Windows::Forms::DialogResult::Yes) {
		// Yes 버튼을 클릭한 경우에 실행할 코드
		// 여기에 Yes 버튼을 클릭했을 때 수행할 동작을 추가하세요.

				//// Server에 ID / PW를 보내기함수
		int time_limit = 0;
		std::string tmptxt_1_;
		std::string _Index_Str = msclr::interop::marshal_as<std::string>(Convert::ToString(e_friends_Delete));

		String^ tmptxt_1 = listBoxFriends->SelectedItem->ToString();
		tmptxt_1_ = msclr::interop::marshal_as<std::string>(tmptxt_1);
		std::string _Index_Str_Result = _Index_Str + " " + tmptxt_1_;

		const char* buffer = _Index_Str_Result.c_str();
		send(client_sock, buffer, strlen(buffer), 0);

		while (1)
		{
			//if (Recv_str == "true")// server 에서 오케이받는 함수
			if (1)// server 에서 오케이받는 함수
			{
				Friends_Visible(sender, e);
				System::Windows::Forms::MessageBox::Show("그분은 당신을 아직 친구라고 생각하고있어요.", "친구삭제", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			else if (Recv_str == "false") //  server에서 다른값보내면
			{
				System::Windows::Forms::MessageBox::Show("다른값을 보냈다고?", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);

				return;
			}
			else // 무한반복되는건데 시간타이밍 주면 좋을거같음
			{
				Sleep(1000);
				if (time_limit > 1)
				{
					System::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
				else
				{
					time_limit++;
				}
			}
		}

	}
	else {
		// No 버튼을 클릭한 경우에 실행할 코드
		// 여기에 No 버튼을 클릭했을 때 수행할 동작을 추가하세요.
		return;
	}
}
private: System::Void btnResponse_Click(System::Object^ sender, System::EventArgs^ e) {
	if (friendresponseform == nullptr || friendresponseform->IsDisposed) {
		friendresponseform = gcnew FriendResponse;
		friendresponseform->Owner = this;
		friendresponseform->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		friendresponseform->Activate();
	}
}
private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Owner->Activate();
	this->Close();

}
};
}
