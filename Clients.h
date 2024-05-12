#pragma once
#include <iostream>
#include <string>
#include "Persona.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;

ref class Clients :
    public Persona
{

    public:
        int code;
    public:
        Clients() : Persona() {
            this->code = 0;
        }

        Clients(int code, String^ name, String^ lastname, String^ address, String^ phonenumb, String^ email, String^ password)
            : Persona(name, lastname, address, phonenumb, email, password) {
            this->code = code;
        }

        Clients^ get_client() {
            return this;
        }
};

