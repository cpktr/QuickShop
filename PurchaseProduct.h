#pragma once
#include <iostream>
#include <string>
#include "Product.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing;
using namespace System::IO;
using namespace std;


ref class PurchaseProduct
{
	public:
		int id_purchase;
		String^ user;
		cli::array<Product^>^ products = gcnew cli::array<Product^>(100);
		float discount;
		float subtotal;
		float iva;

		PurchaseProduct() {
			this->id_purchase = 0;
			this->user = "";
			this->products = gcnew cli::array<Product^>(100);
			this->discount = 0;
			this->subtotal = 0;
			this->iva = 0;
		}

		PurchaseProduct(int id, String^ user, cli::array<Product^>^ products, float discount, float subtotal, float iva) {
			this->id_purchase = id;
			this->user = user;
			this->products = products;
			this->discount = discount;
			this->subtotal = subtotal;
			this->iva = iva;
		}

		void editProductsList(cli::array<Product^>^ products) {
			this->products = products;
		}



};

