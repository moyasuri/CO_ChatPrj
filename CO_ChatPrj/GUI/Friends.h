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
	private:
		AddFriend^ addfriendform = nullptr;
	private: System::Windows::Forms::Button^ btnClose;

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
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ btnDelete;
	protected:

	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBoxFriends;




	protected:


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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBoxFriends = (gcnew System::Windows::Forms::ListBox());
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(316, 148);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(153, 31);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Request Response";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Friends::button3_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->Location = System::Drawing::Point(316, 206);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(153, 31);
			this->btnDelete->TabIndex = 6;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = true;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Friends::btnDelete_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(316, 91);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(153, 31);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Add Friend";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Friends::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 58);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 15);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Friends list";
			// 
			// listBoxFriends
			// 
			this->listBoxFriends->FormattingEnabled = true;
			this->listBoxFriends->ItemHeight = 15;
			this->listBoxFriends->Location = System::Drawing::Point(44, 91);
			this->listBoxFriends->Name = L"listBoxFriends";
			this->listBoxFriends->Size = System::Drawing::Size(237, 259);
			this->listBoxFriends->TabIndex = 3;
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(316, 453);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(153, 31);
			this->btnClose->TabIndex = 8;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &Friends::btnClose_Click);
			// 
			// Friends
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(533, 518);
			this->Controls->Add(this->btnClose);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBoxFriends);
			this->Name = L"Friends";
			this->Text = L"Friends";
			this->Activated += gcnew System::EventHandler(this, &Friends::Friends_Visible);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	if (addfriendform == nullptr || addfriendform->IsDisposed) {
		addfriendform = gcnew AddFriend;
		addfriendform->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		addfriendform->Activate();
	}
}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

	if (friendresponseform == nullptr|| friendresponseform->IsDisposed) {
		friendresponseform = gcnew FriendResponse;
		friendresponseform->Show();

	}
	// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.
	else {
		friendresponseform->Activate();
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
	
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

};
}
