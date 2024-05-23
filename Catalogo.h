#pragma once
#include <iostream>
#include <string>
#include "Inventario.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;
ref class Catalogo :
    public Inventario
{
    public:
		String^ catego;
		String^ brand;
		String^ descrip;
		float price;
	public:
		Catalogo() : Inventario() {
			this->id_product = 0;
			this->name = "";
			this->catego = "";
			this->brand = "";
			this->descrip = "";
			this->price = 0;
			this->stock = 0;


		};
		Catalogo(int id, String^ name, String^ catego, String^ brand, String^ descrip, float price, int stock)
			:Inventario(id, name, stock)
		{
			this->catego = catego;
			this->brand = brand;
			this->descrip = descrip;
			this->price = price;
		}
};

