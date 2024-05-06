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
		String^ id_customer;
		String^ username;
		String^ type;
		String^ cui;

	public:
		Cstomer() {
			this->id_customer = "0";
			this->username = "";
			this->type = "type";
			this->cui = "cui";
		};
		Cstomer(String^ id, String^ username, String^ type, String^ cui, String^ name, String^ lastname, String^ address, String^ phonenumb, String^ email, String^ password)
			: Persona(name, lastname, address, phonenumb, email, password) {
			this->id_customer = id;
			this->username = username;
			this->type = type;
			this->cui = cui;
		}

		Cstomer^ get_usuario() {
			return this;
		}

		String^ getUsername() {
			return username;
		}
		String^ getPassword() {
			return password;
		}
		String^ getType() {
			return type;
		}

};

