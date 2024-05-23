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
ref class Inventario
{
	public:
		int id_product;
		String^ name;
		int stock;
	public:
		Inventario() {
			this->id_product = 0;
			this->name = "";
			this->stock = 0;
		}

		Inventario(int id, String^ name, int stock) {
			this->id_product = id;
			this->name = name;
			this->stock = stock;
		}

		void deleteStock(int quantity) {
			this->stock -= quantity;
		}
};

