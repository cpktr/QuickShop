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
		String^ productList;
		float discount;
		float subtotal;
		float iva;
		float total;

		PurchaseProduct() {
			this->id_purchase = 0;
			this->user = "";
			this->products = gcnew cli::array<Product^>(100);
			this->productList = "";
			this->discount = 0;
			this->subtotal = 0;
			this->iva = 0;
			this->total = 0;
		}

		PurchaseProduct(int id, String^ user, cli::array<Product^>^ products, String^ productList, float discount, float subtotal, float iva, float total) {
			this->id_purchase = id;
			this->user = user;
			this->products = products;
			this->productList = productList;
			this->discount = discount;
			this->subtotal = subtotal;
			this->iva = iva;
			this->total = total;
		}

		void editProductsList(cli::array<Product^>^ products) {
			this->products = products;
		}



};

