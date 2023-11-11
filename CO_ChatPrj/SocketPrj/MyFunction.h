#pragma once
#pragma comment(lib, "ws2_32.lib")

#include <winsock2.h>
#include <ws2tcpip.h>




namespace SocketPrj {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Net;
	using namespace System::Net::Sockets;
	using namespace System::Text;

	
	
	ref class MyForm;
	ref class MyFunction
	{

	public:
		IPEndPoint^ serverEndPoint;
		Socket^ clientSocket;
		System::Threading::Thread^ messageReceiveThread;

		// 이벤트를 선언합니다.
		event Action<String^>^ MyEvent; 



	public:
		void SendMessage(String^ message)
		{

			if (!String::IsNullOrEmpty(message))
			{
				//array<Byte>^ buffer = Encoding::UTF8->GetBytes(message);
				array<Byte>^ buffer = Encoding::GetEncoding("EUC-KR")->GetBytes(message);
				clientSocket->Send(buffer);

			}
		}
		
		

		void ReceiveMessages()
		{
			while (true)
			{
				try
				{
					array<Byte>^ buffer = gcnew array<Byte>(1024);
					int bytesRead = clientSocket->Receive(buffer);
					String^ message = Encoding::GetEncoding("UTF-8")->GetString(buffer, 0, bytesRead);
					if (!String::IsNullOrEmpty(message))
					{
							MyEvent(message);
						
					}
					//AppendMessageToUI("상대방: " + message);
				}
				catch (SocketException^ se)
				{
					// 서버와의 연결이 끊겼을 때 SocketException을 처리합니다.
					// 예외 처리 코드 추가, 예를 들면:
					// 
					MessageBox::Show("Server disconnected");
					break; // 스레드 종료 또는 다른 조치를 취할 수 있음
				}
			}
		}





		void disposed()
		{
			// 소켓 해제
			clientSocket->Close();
			if (messageReceiveThread != nullptr)
			{
				messageReceiveThread->Abort();
			}
		}


		void Connect()
		{
			while (1)
			{
				try
				{
					// 서버에 연결
					clientSocket->Connect(serverEndPoint);

					// 연결 성공시 쓰레드를 시작하여 메시지 수신 대기
					messageReceiveThread = gcnew System::Threading::Thread(gcnew System::Threading::ThreadStart(this, &MyFunction::ReceiveMessages));
					messageReceiveThread->Start();
					break;
				}
				catch (Exception^ e)
				{
					MessageBox::Show("server connection failed","error" + e->Message);

				}

				Sleep(3000);

			}


		}


		void init()
		{

			System::Threading::Thread^ messageReceiveThread = nullptr;


			WSADATA wsaData;
			if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
			{
				MessageBox::Show("소켓 초기화에 실패했습니다.");
				Application::Exit();
			}
			// 서버 주소 설정 (서버 IP 주소와 포트를 적절히 수정)
			serverEndPoint = gcnew IPEndPoint(IPAddress::Parse("127.0.0.1"), 7777);

			// 클라이언트 소켓 생성
			clientSocket = gcnew Socket(AddressFamily::InterNetwork, SocketType::Stream, ProtocolType::Tcp);
		}

		
		
		
		String^ s_(int _enum)
		{
			String^ string = _enum.ToString();

			return string;
		}
		 





	};

}

