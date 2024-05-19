#pragma once
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

ref class Payments
{
	public:
		int id_payment;
		String^ usuario;
		String^ productos;
		String^ type_payment;
		float total;

		Payments() {
			this->id_payment = 0;
			this->usuario = "";
			this->productos = "";
			this->type_payment = "";
			this->total = 0;
		}

		Payments(int id, String^ usuario, String^ productos, String^ type, float total) {
			this->id_payment = id;
			this->usuario = usuario;
			this->productos = productos;
			this->type_payment = type;
			this->total = total;
		}
};

