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

ref class Cstomer :
    public Persona
{
	private:
		String^ username;
		String^ type;
		String^ cui;

	public:
		Cstomer() {};
		Cstomer(String^ username, String^ type, String^ cui, String^ name, String^ lastname, String^ address, String^ phonenumb, String^ email, String^ password)
			: Persona(name, lastname, address, phonenumb, email, password) {
			this->username = username;
			this->type = type;
			this->cui = cui;
		}

		Cstomer^ get_usuario() {
			return this;
		}
};

