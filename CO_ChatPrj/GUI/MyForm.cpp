﻿#pragma comment(lib, "ws2_32.lib")
#include "MyForm.h"



using namespace System;
using namespace System::Windows::Forms;


[STAThread]


void main(array<String^>^ args) {
			
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GUI::MyForm form;
	Application::Run(% form);





}