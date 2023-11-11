#include "MyForm.h"
#include "MyFunction.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace SocketPrj;






[STAThread]


void main(array<String^>^ args) {
	


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SocketPrj::MyFunction myfunc;
	myfunc.init();
	myfunc.Connect(); // 이거 자체는 버튼으로 처리하고싶긴해
	MyForm my(% myfunc);
	Application::Run(% my);



	
	myfunc.disposed();

}