#pragma once
#include <fstream>
#include <string>
#include <iostream>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;

ref class Product
{


public:
	int id_product;
	String^ name;
	String^ catego;
	String^ brand;
	String^ descrip;
	float price;
	int stock;//se puede operar asi que utilizamos int 

public:
	Product() {
		this->id_product = 0;
		this->name = "";
		this->catego = "";
		this->brand = "";
		this->descrip = "";
		this->price = 0;
		this->stock = 0;
		

	};
	Product(int id, String^ name, String^ catego, String^ brand, String^ descrip, float price, int stock)
		 {
		this->id_product = id;
		this->name = name;
		this->catego = catego;
		this->brand = brand;
		this->descrip = descrip;
		this->price = price;
		this->stock = stock;

	}
};

