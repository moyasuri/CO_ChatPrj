#include "MyForm.h"
#include "MyFunction.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MyClient;






[STAThread]


void main(array<String^>^ args) {
	


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	MyClient::MyFunction myfunc;
	MyClient::MyForm form;
	myfunc.init();
	myfunc.Connect(); // 이거 자체는 버튼으로 처리하고싶긴해
	form.SetMyFunction(% myfunc);
	Application::Run(% form);



	
	myfunc.disposed();

}