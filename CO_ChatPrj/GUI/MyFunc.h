#pragma once

#include <string>
#include <msclr/marshal_cppstd.h>
using namespace std;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


public ref class MyFunc
{
public:
    static string ConvertStr(String^ str)
    {
        return msclr::interop::marshal_as<std::string>(str);
    }
};