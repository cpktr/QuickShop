#pragma once
#include <iostream>
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;

ref class Persona
{
	public:
		String^ name;
		String^ lastName;
		String^ address;
		String^ phoneNum;
		String^ email;
		String^ password;

	public: 
		Persona() {
			this->name = "name";
			this->lastName = "lastname";
			this->address = "address";
			this->phoneNum = "phonenumb";
			this->email = "email";
			this->password = "password";
		}
		Persona(String^ name, String^ lastname, String^ address, String^ phonenumb, String^ email, String^ password) {
			try
			{ 
			if (name != "" && lastname!=""&& address!=""&& phonenumb!=""&& email!=""&&password!="") {
			
				this->name = name;
				this->lastName = lastname;
				this->address = address;
				this->phoneNum = phonenumb;
				this->email = email;
				this->password = password;

			}
			else {
				throw ;
			}
			
				//si el dato es diferente de vacio entonces continua
			}
			catch (const std::exception& e)
			{
				cout << "Ha ocurrido un error: " << e.what() << endl;
			}
		}
	
};
