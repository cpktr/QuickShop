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
		String^ code_payment;
		String^ usuario;
		String^ productos;
		String^ type_payment;
		String^ card;
		String^ amountBill;
		String^ address;
		String^ phoneNumb;
		float total;

		Payments() {
			this->id_payment = 0;
			this->code_payment = "";
			this->usuario = "";
			this->productos = "";
			this->type_payment = "";
			this->card = "N/A";
			this->amountBill = "N/A";
			this->address = "";
			this->phoneNumb = "";
			this->total = 0;
		}

		Payments(int id, String^ code, String^ usuario, String^ productos, String^ type, float total, String^ card, String^ amount, String^ address, String^ phone) {
			this->id_payment = id;
			this->code_payment = code;
			this->usuario = usuario;
			this->productos = productos;
			this->type_payment = type;
			this->card = card;
			this->amountBill = amount;
			this->address = address;
			this->phoneNumb = phone;
			this->total = total;
		}
};

