[1mdiff --git a/CO_ChatPrj/CO_ChatPrj/main.cpp b/CO_ChatPrj/CO_ChatPrj/main.cpp[m
[1mindex 6c3ae13..2e1646a 100644[m
[1m--- a/CO_ChatPrj/CO_ChatPrj/main.cpp[m
[1m+++ b/CO_ChatPrj/CO_ChatPrj/main.cpp[m
[36m@@ -144,7 +144,6 @@[m [mvoid recv_msg(int idx) {[m
             //msg = sck_list[idx].user + " : " + buf;[m
             [m
             msg = buf;[m
[31m-[m
             cout << buf << endl;[m
             if (msg == "cd")[m
             {[m
[1mdiff --git a/CO_ChatPrj/GUI/Friends.h b/CO_ChatPrj/GUI/Friends.h[m
[1mindex 54f714d..3526827 100644[m
[1m--- a/CO_ChatPrj/GUI/Friends.h[m
[1m+++ b/CO_ChatPrj/GUI/Friends.h[m
[36m@@ -178,7 +178,7 @@[m [mprivate: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e[m
 	}[m
 [m
 }[m
[31m-private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {[m
[32m+[m[32mpublic: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {[m
 	this->Close();[m
 }[m
 };[m
[1mdiff --git a/CO_ChatPrj/GUI/GUI.vcxproj b/CO_ChatPrj/GUI/GUI.vcxproj[m
[1mindex cdd7f6b..3327dd1 100644[m
[1m--- a/CO_ChatPrj/GUI/GUI.vcxproj[m
[1m+++ b/CO_ChatPrj/GUI/GUI.vcxproj[m
[36m@@ -188,6 +188,7 @@[m
     <ClInclude Include="MyForm.h">[m
       <FileType>CppForm</FileType>[m
     </ClInclude>[m
[32m+[m[32m    <ClInclude Include="MyFunc.h" />[m
     <ClInclude Include="NewMessage.h">[m
       <FileType>CppForm</FileType>[m
     </ClInclude>[m
[1mdiff --git a/CO_ChatPrj/GUI/GUI.vcxproj.filters b/CO_ChatPrj/GUI/GUI.vcxproj.filters[m
[1mindex 805536f..eb8b6f3 100644[m
[1m--- a/CO_ChatPrj/GUI/GUI.vcxproj.filters[m
[1m+++ b/CO_ChatPrj/GUI/GUI.vcxproj.filters[m
[36m@@ -155,5 +155,8 @@[m
     <ClInclude Include="GeneralChatIndex.h">[m
       <Filter>헤더 파일</Filter>[m
     </ClInclude>[m
[32m+[m[32m    <ClInclude Include="MyFunc.h">[m
[32m+[m[32m      <Filter>소스 파일</Filter>[m
[32m+[m[32m    </ClInclude>[m
   </ItemGroup>[m
 </Project>[m
\ No newline at end of file[m
[1mdiff --git a/CO_ChatPrj/GUI/MyForm.cpp b/CO_ChatPrj/GUI/MyForm.cpp[m
[1mindex 3c7b423..41f8940 100644[m
[1m--- a/CO_ChatPrj/GUI/MyForm.cpp[m
[1m+++ b/CO_ChatPrj/GUI/MyForm.cpp[m
[36m@@ -7,6 +7,7 @@[m
 #include <iostream>[m
 #include <thread>[m
 [m
[32m+[m
 #include "MyForm.h"[m
 #include "MainForm.h"[m
 [m
[36m@@ -33,7 +34,7 @@[m [mint chat_recv() {[m
         ZeroMemory(&buf, MAX_SIZE);[m
         if (recv(client_sock, buf, MAX_SIZE, 0) > 0) {[m
             msg = buf;[m
[31m-            temp_socket = msg;[m
[32m+[m[32m            Recv_str = msg;[m
             // std::stringstream ss(msg);  // 문자열을 스트림화[m
             string user;[m
             // ss >> user; // 스트림을 통해, 문자열을 공백 분리해 변수에 할당. 보낸 사람의 이름만 user에 저장됨.[m
[1mdiff --git a/CO_ChatPrj/GUI/MyForm.h b/CO_ChatPrj/GUI/MyForm.h[m
[1mindex 4483061..eacbec9 100644[m
[1m--- a/CO_ChatPrj/GUI/MyForm.h[m
[1m+++ b/CO_ChatPrj/GUI/MyForm.h[m
[36m@@ -4,14 +4,14 @@[m
 #include "FindAccount.h"[m
 #include <msclr/marshal_cppstd.h>[m
 #include <string>[m
[31m-[m
[32m+[m[32m// #include "MyFunc.h"[m
 [m
 static std::string my_nick;[m
 static SOCKET client_sock;[m
 static bool enterServer;[m
 static bool isExit;[m
 static int Temp_socket;[m
[31m-static std::string temp_socket;[m
[32m+[m[32mstatic std::string Recv_str;[m
 [m
 [m
 namespace GUI {[m
[36m@@ -36,7 +36,8 @@[m [mnamespace GUI {[m
 	private:[m
 		SignUp^ signupForm = nullptr;[m
 		FindAccount^ findaccountForm = nullptr;[m
[31m-		MainForm^ mainForm =nullptr;[m
[32m+[m		[32mMainForm^ mainForm = nullptr;[m
[32m+[m[41m		[m
 	private: bool isFirstActivation = true;[m
 [m
 	[m
[36m@@ -65,12 +66,15 @@[m [mnamespace GUI {[m
 			//TODO: 생성자 코드를 여기에 추가합니다.[m
 			//[m
 [m
[31m-			// Image 추가[m
[32m+[m
[32m+[m			[32m// sound 추가[m
[32m+[m
 			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\constantmoderato.wav");[m
 			IntroImageSound->SoundLocation = relativePath; // SoundLocation에 CLI 문자열을 설정[m
 			IntroImageSound->Load();[m
 			IntroImageSound->Play();[m
[31m-			[m
[32m+[m
[32m+[m			[32m// Image 추가[m[41m			[m
 			relativePath = System::IO::Path::Combine(currentDirectory, "..\\Media\\HomeIntro.gif");[m
 			PicBoxIntro->ImageLocation = relativePath;[m
 [m
[36m@@ -98,8 +102,6 @@[m [mnamespace GUI {[m
 			// 이미지 추가 끝[m
 [m
 [m
[31m-			// sound 추가[m
[31m-						[m
 [m
 [m
 [m
[36m@@ -184,6 +186,7 @@[m [mnamespace GUI {[m
 			this->btnSignin->Name = L"btnSignin";[m
 			this->btnSignin->Size = System::Drawing::Size(250, 120);[m
 			this->btnSignin->TabIndex = 1;[m
[32m+[m			[32mthis->btnSignin->TabStop = false;[m
 			this->btnSignin->Text = L"Sign in";[m
 			this->btnSignin->UseVisualStyleBackColor = false;[m
 			this->btnSignin->Click += gcnew System::EventHandler(this, &MyForm::btnSignin_Click);[m
[36m@@ -251,6 +254,7 @@[m [mnamespace GUI {[m
 			this->btnExit->Name = L"btnExit";[m
 			this->btnExit->Size = System::Drawing::Size(250, 120);[m
 			this->btnExit->TabIndex = 11;[m
[32m+[m			[32mthis->btnExit->TabStop = false;[m
 			this->btnExit->Text = L"Exit";[m
 			this->btnExit->UseVisualStyleBackColor = false;[m
 			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);[m
[36m@@ -270,6 +274,7 @@[m [mnamespace GUI {[m
 			this->btnSignup->Name = L"btnSignup";[m
 			this->btnSignup->Size = System::Drawing::Size(307, 120);[m
 			this->btnSignup->TabIndex = 12;[m
[32m+[m			[32mthis->btnSignup->TabStop = false;[m
 			this->btnSignup->Text = L"Sign up";[m
 			this->btnSignup->UseVisualStyleBackColor = false;[m
 			this->btnSignup->Click += gcnew System::EventHandler(this, &MyForm::btn_signup_Click);[m
[36m@@ -289,6 +294,7 @@[m [mnamespace GUI {[m
 			this->btnFindAccount->Name = L"btnFindAccount";[m
 			this->btnFindAccount->Size = System::Drawing::Size(322, 120);[m
 			this->btnFindAccount->TabIndex = 14;[m
[32m+[m			[32mthis->btnFindAccount->TabStop = false;[m
 			this->btnFindAccount->Text = L"Find Account";[m
 			this->btnFindAccount->UseVisualStyleBackColor = false;[m
 			this->btnFindAccount->Click += gcnew System::EventHandler(this, &MyForm::btnFindAccount_Click);[m
[36m@@ -332,7 +338,7 @@[m [mnamespace GUI {[m
 			// [m
 			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);[m
 			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;[m
[31m-			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage"))); // 나중에 경로 지정하자[m
[32m+[m			[32mthis->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));[m
 			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;[m
 			this->ClientSize = System::Drawing::Size(1109, 646);[m
 			this->Controls->Add(this->btnSignup);[m
[36m@@ -364,9 +370,12 @@[m [mnamespace GUI {[m
 [m
 		// sign up form을 띄우기.[m
 	private: System::Void btn_signup_Click(System::Object^ sender, System::EventArgs^ e) {[m
[32m+[m[41m		[m
[32m+[m		[32mbtnSignup->NotifyDefault(false);[m
 		// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.[m
 		if (signupForm == nullptr || signupForm->IsDisposed) {[m
 			signupForm = gcnew SignUp;[m
[32m+[m			[32msignupForm->Owner = this;[m
 			signupForm->Show();[m
 		}[m
 		// 이미 생성된 폼이 열려 있는 경우, 해당 폼을 활성화시킵니다.[m
[36m@@ -385,12 +394,13 @@[m [mnamespace GUI {[m
 [m
 	private: System::Void btnSignin_Click(System::Object^ sender, System::EventArgs^ e) {[m
 [m
[31m-[m
[31m-[m
[32m+[m		[32m//테두리 없애기[m
[32m+[m		[32mbtnSignin->NotifyDefault(false);[m
[32m+[m[41m		[m
 		// 텍스트 상자에서 텍스트 가져오기[m
 		String^ textID_ = txtBoxID->Text; // textBox는 해당 텍스트 상자의 이름입니다.[m
 		String^ textPW_ = txtBoxPW->Text; // textBox는 해당 텍스트 상자의 이름입니다.[m
[31m-		std::string stdString = msclr::interop::marshal_as<std::string>(textID_);[m
[32m+[m[41m		[m
 [m
 		// ID와 PW의 문자열이 채워져있다면[m
 		if (!String::IsNullOrEmpty(textID_)&& !String::IsNullOrEmpty(textPW_)) {[m
[36m@@ -398,11 +408,14 @@[m [mnamespace GUI {[m
 			// Server에 ID / PW를 보내기함수[m
 			int time_limit = 0;[m
 			[m
[31m-			const char* buffer = stdString.c_str(); // string형을 char* 타입으로 변환[m
[31m-			send(client_sock, buffer, strlen(buffer), 0);[m
[32m+[m			[32m//const char* buffer = MyFunc::ConvertStr(textID_).c_str(); // string형을 char* 타입으로 변환후 buffer에 집어넣기[m
[32m+[m			[32m//send(client_sock, buffer, strlen(buffer), 0);[m
[32m+[m
[32m+[m
[32m+[m[41m			[m
 			while(1)[m
 			{[m
[31m-				if (temp_socket=="3")// server 에서 오케이받는 함수[m
[32m+[m				[32mif (Recv_str=="3")// server 에서 오케이받는 함수[m
 				{[m
 [m
 					// Hide 할때의 동작			[m
[36m@@ -413,7 +426,6 @@[m [mnamespace GUI {[m
 						this->HomeImageSound->Stop();[m
 						mainForm->Show();[m
 					}[m
[31m-[m
 					return;[m
 				}[m
 				else if(0) //  server에서 다른값보내면[m
[36m@@ -426,6 +438,7 @@[m [mnamespace GUI {[m
 					Sleep(1000);[m
 					if (time_limit > 1)[m
 					{[m
[32m+[m						[32mSystem::Windows::Forms::MessageBox::Show("서버가 응답하지 않습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);[m
 						return;[m
 					}[m
 					else[m
[36m@@ -440,17 +453,16 @@[m [mnamespace GUI {[m
 			System::Windows::Forms::MessageBox::Show("ID / PW 를 다시입력해주세요. ", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);[m
 		}[m
 [m
[31m-[m
 	}[m
 [m
 	private: System::Void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {[m
[31m-		[m
[32m+[m		[32mbtnExit->NotifyDefault(false);[m
 		this->Close();[m
 	}[m
 [m
 [m
 	private: System::Void btnFindAccount_Click(System::Object^ sender, System::EventArgs^ e) {[m
[31m-	[m
[32m+[m		[32mbtnFindAccount->NotifyDefault(false);[m
 		// 이미 생성된 SignUp 폼이 없는 경우에만 새로운 폼을 생성하고 엽니다.[m
 		if (findaccountForm == nullptr || findaccountForm->IsDisposed) {[m
 			findaccountForm = gcnew FindAccount;[m
[36m@@ -483,8 +495,9 @@[m [mnamespace GUI {[m
 [m
 		HomeImageSound->Play();[m
 	}[m
[32m+[m[41m		   [m
 [m
[31m-[m
[32m+[m[41m		   [m
 [m
 };[m
 }[m
[1mdiff --git a/CO_ChatPrj/GUI/SignUp.h b/CO_ChatPrj/GUI/SignUp.h[m
[1mindex 2ea9f07..ad47da7 100644[m
[1m--- a/CO_ChatPrj/GUI/SignUp.h[m
[1m+++ b/CO_ChatPrj/GUI/SignUp.h[m
[36m@@ -1,5 +1,5 @@[m
 ﻿#pragma once[m
[31m-[m
[32m+[m[32m#include "MyFunc.h"[m
 [m
 namespace GUI {[m
 [m
[36m@@ -435,11 +435,12 @@[m [mnamespace GUI {[m
 [m
 		if (!String::IsNullOrEmpty(textBoxText)) {[m
 			// 텍스트 상자에 텍스트가 비어 있지 않으면 Message Box로 출력[m
[31m-			MessageBox::Show(textBoxText, "텍스트 상자 내용", MessageBoxButtons::OK, MessageBoxIcon::Information);[m
[32m+[m			[32mSystem::Windows::Forms::MessageBox::Show(textBoxText, "텍스트 상자 내용", MessageBoxButtons::OK, MessageBoxIcon::Information);[m
 		}[m
 		else {[m
 			// 텍스트 상자가 비어 있을 때 메시지를 출력할 수 있습니다.[m
[31m-			MessageBox::Show("텍스트 상자가 비어 있습니다.", "경고", MessageBoxButtons::OK, MessageBoxIcon::Warning);[m
[32m+[m			[32mSystem::Windows::Forms::MessageBox::Show("text가 비어있습니다", "경고", MessageBoxButtons::OK, MessageBoxIcon::Information);[m
[32m+[m
 		}[m
 [m
 [m
[36m@@ -452,7 +453,8 @@[m [mnamespace GUI {[m
 	private: System::Void btnIDduplicateChk_Click(System::Object^ sender, System::EventArgs^ e) {[m
 [m
 		// DB의 ID랑 중복되는지 확인[m
[31m-		txtBoxID->Text;[m
[32m+[m		[32m// UI::MyForm::ConvertStr(txtBoxID->Text);[m
[32m+[m[41m			[m
 [m
 	}[m
 		    [m
