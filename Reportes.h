#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "Cstomer.h"
#include "Clients.h"
#include "Product.h"
#include "PurchaseProduct.h"
#include "Payments.h"
#include "User.h"

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;
	using namespace System::IO;
	using namespace std;

	/// <summary>
	/// Resumen de Reportes
	/// </summary>
	public ref class Reportes : public System::Windows::Forms::Form
	{
	private: User^ userSess;
	private: cli::array<Cstomer^>^ localData = gcnew cli::array<Cstomer^>(100);
	private: cli::array<Clients^>^ localDataClient = gcnew cli::array<Clients^>(100);
	private: cli::array<Product^>^ localDataProducts = gcnew cli::array<Product^>(100);
	private: cli::array<PurchaseProduct^>^ localDataPurchases = gcnew cli::array<PurchaseProduct^>(100);
	private: cli::array<Payments^>^ localDataPayments = gcnew cli::array<Payments^>(100);
	private: System::Windows::Forms::Button^ btn_inventary;
	private: System::Windows::Forms::Button^ btn_users;

	public:
		Reportes(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}
		Reportes(User^ userSession)
		{
			this->userSess = userSession;
			InitializeComponent();
			if (this->userSess != nullptr) {
				if (this->userSess->operador == true) {
					this->btn_inventary->Visible = false;
					this->btn_users->Visible = false;
					this->btn_inventary->Name = L"Reportes";
				}
			}
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Reportes()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titlePage;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel_buttons;

	


	private: System::Windows::Forms::Button^ btn_payments;

	private: System::Windows::Forms::Button^ btn_purchases;

	private: System::Windows::Forms::Button^ btn_products;


	private: System::Windows::Forms::Button^ btn_clients;
	
	private: System::Windows::Forms::Panel^ panel_table;
	private: System::Windows::Forms::DataGridView^ dgv_report;

	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->titlePage = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel_buttons = (gcnew System::Windows::Forms::Panel());
			this->btn_users = (gcnew System::Windows::Forms::Button());
			this->btn_inventary = (gcnew System::Windows::Forms::Button());
			this->btn_payments = (gcnew System::Windows::Forms::Button());
			this->btn_purchases = (gcnew System::Windows::Forms::Button());
			this->btn_products = (gcnew System::Windows::Forms::Button());
			this->btn_clients = (gcnew System::Windows::Forms::Button());
			this->panel_table = (gcnew System::Windows::Forms::Panel());
			this->dgv_report = (gcnew System::Windows::Forms::DataGridView());
			this->panel_buttons->SuspendLayout();
			this->panel_table->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_report))->BeginInit();
			this->SuspendLayout();
			// 
			// titlePage
			// 
			this->titlePage->AutoSize = true;
			this->titlePage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->titlePage->Location = System::Drawing::Point(9, 9);
			this->titlePage->Name = L"titlePage";
			this->titlePage->Size = System::Drawing::Size(125, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Reportes";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Generar reporte de:";
			// 
			// panel_buttons
			// 
			this->panel_buttons->Controls->Add(this->btn_users);
			this->panel_buttons->Controls->Add(this->btn_inventary);
			this->panel_buttons->Controls->Add(this->btn_payments);
			this->panel_buttons->Controls->Add(this->btn_purchases);
			this->panel_buttons->Controls->Add(this->btn_products);
			this->panel_buttons->Controls->Add(this->btn_clients);
			this->panel_buttons->Location = System::Drawing::Point(16, 70);
			this->panel_buttons->Name = L"panel_buttons";
			this->panel_buttons->Size = System::Drawing::Size(666, 33);
			this->panel_buttons->TabIndex = 2;
			// 
			// btn_users
			// 
			this->btn_users->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_users->Location = System::Drawing::Point(405, 4);
			this->btn_users->Name = L"btn_users";
			this->btn_users->Size = System::Drawing::Size(75, 23);
			this->btn_users->TabIndex = 5;
			this->btn_users->Text = L"Usuarios";
			this->btn_users->UseVisualStyleBackColor = true;
			this->btn_users->Click += gcnew System::EventHandler(this, &Reportes::showUsersReport);
			// 
			// btn_inventary
			// 
			this->btn_inventary->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_inventary->Location = System::Drawing::Point(324, 4);
			this->btn_inventary->Name = L"btn_inventary";
			this->btn_inventary->Size = System::Drawing::Size(75, 23);
			this->btn_inventary->TabIndex = 4;
			this->btn_inventary->Text = L"Inventario";
			this->btn_inventary->UseVisualStyleBackColor = true;
			this->btn_inventary->Click += gcnew System::EventHandler(this, &Reportes::btn_inventary_Click);
			// 
			// btn_payments
			// 
			this->btn_payments->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_payments->Location = System::Drawing::Point(243, 4);
			this->btn_payments->Name = L"btn_payments";
			this->btn_payments->Size = System::Drawing::Size(75, 23);
			this->btn_payments->TabIndex = 3;
			this->btn_payments->Text = L"Pagos";
			this->btn_payments->UseVisualStyleBackColor = true;
			this->btn_payments->Click += gcnew System::EventHandler(this, &Reportes::btn_payments_Click);
			// 
			// btn_purchases
			// 
			this->btn_purchases->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_purchases->Location = System::Drawing::Point(162, 4);
			this->btn_purchases->Name = L"btn_purchases";
			this->btn_purchases->Size = System::Drawing::Size(75, 23);
			this->btn_purchases->TabIndex = 2;
			this->btn_purchases->Text = L"Compras";
			this->btn_purchases->UseVisualStyleBackColor = true;
			this->btn_purchases->Click += gcnew System::EventHandler(this, &Reportes::btn_purchases_Click);
			// 
			// btn_products
			// 
			this->btn_products->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_products->Location = System::Drawing::Point(81, 4);
			this->btn_products->Name = L"btn_products";
			this->btn_products->Size = System::Drawing::Size(75, 23);
			this->btn_products->TabIndex = 1;
			this->btn_products->Text = L"Catalogo";
			this->btn_products->UseVisualStyleBackColor = true;
			// 
			// btn_clients
			// 
			this->btn_clients->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_clients->Location = System::Drawing::Point(0, 4);
			this->btn_clients->Name = L"btn_clients";
			this->btn_clients->Size = System::Drawing::Size(75, 23);
			this->btn_clients->TabIndex = 0;
			this->btn_clients->Text = L"Clientes";
			this->btn_clients->UseVisualStyleBackColor = true;
			this->btn_clients->Click += gcnew System::EventHandler(this, &Reportes::btn_clients_Click);
			// 
			// panel_table
			// 
			this->panel_table->Controls->Add(this->dgv_report);
			this->panel_table->Location = System::Drawing::Point(16, 110);
			this->panel_table->Name = L"panel_table";
			this->panel_table->Size = System::Drawing::Size(666, 322);
			this->panel_table->TabIndex = 3;
			// 
			// dgv_report
			// 
			this->dgv_report->AllowUserToAddRows = false;
			this->dgv_report->AllowUserToDeleteRows = false;
			this->dgv_report->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_report->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv_report->Location = System::Drawing::Point(0, 0);
			this->dgv_report->Name = L"dgv_report";
			this->dgv_report->ReadOnly = true;
			this->dgv_report->Size = System::Drawing::Size(666, 322);
			this->dgv_report->TabIndex = 0;
			// 
			// Reportes
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->panel_table);
			this->Controls->Add(this->panel_buttons);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Reportes";
			this->Text = L"Reportes";
			this->panel_buttons->ResumeLayout(false);
			this->panel_table->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_report))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
			

		}
#pragma endregion
	private: System::Void showUsersReport(System::Object^ sender, System::EventArgs^ e) {
		this->dgv_report->Rows->Clear();
		this->dgv_report->Columns->Clear();
		this->dgv_report->Columns->Add("id_customer", "ID");
		this->dgv_report->Columns->Add("name", "Nombre");
		this->dgv_report->Columns->Add("lastName", "Apellido");
		this->dgv_report->Columns->Add("user", "Usuario");
		this->dgv_report->Columns->Add("typeUser", "Tipo de Usuario");
		this->dgv_report->Columns->Add("cui", "CUI / Pasaporte");
		this->dgv_report->Columns->Add("phoneNum", "N�mero de Tel�fono");
		this->dgv_report->Columns->Add("email", "Correo Electr�nico");
		this->dgv_report->Columns->Add("address", "Direcci�n Domiciliar");

		ifstream usuaa("users.csv");

		if (!usuaa.is_open()) {
			MessageBox::Show("Error al abrir el archivo");
		}
		else {
			string line;
			int limit = 0;
			while (getline(usuaa, line)) {
				Cstomer^ newUser = gcnew Cstomer();
				string id;
				string username;
				string type;
				string cui;
				string name;
				string lastname;
				string address;
				string phonenumb;
				string email;
				string password;

				stringstream ss(line);
				getline(ss, id, ',');
				getline(ss, name, ',');
				getline(ss, lastname, ',');
				getline(ss, username, ',');
				getline(ss, type, ',');
				getline(ss, cui, ',');
				getline(ss, phonenumb, ',');
				getline(ss, email, ',');
				getline(ss, address, ',');
				getline(ss, password, ',');
				newUser->id_customer = gcnew String(id.c_str());
				newUser->name = gcnew String(name.c_str());
				newUser->lastName = gcnew String(lastname.c_str());
				newUser->username = gcnew String(username.c_str());
				newUser->type = gcnew String(type.c_str());
				newUser->cui = gcnew String(cui.c_str());
				newUser->phoneNum = gcnew String(phonenumb.c_str());
				newUser->email = gcnew String(email.c_str());
				newUser->address = gcnew String(address.c_str());
				newUser->password = gcnew String(password.c_str());

				localData[limit] = newUser;
				this->dgv_report->Rows->Add(localData[limit]->id_customer, localData[limit]->name, localData[limit]->lastName, localData[limit]->username, localData[limit]->type, localData[limit]->cui, localData[limit]->phoneNum, localData[limit]->email, localData[limit]->address);
				limit++;
			}
		}
	}
	private: System::Void btn_clients_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dgv_report->Rows->Clear();
		this->dgv_report->Columns->Clear();
		this->dgv_report->Columns->Add("code", "ID");
		this->dgv_report->Columns->Add("name", "Nombre");
		this->dgv_report->Columns->Add("lastName", "Apellido");
		this->dgv_report->Columns->Add("phoneNum", "N�mero de Tel�fono");
		this->dgv_report->Columns->Add("email", "Correo Electr�nico");
		this->dgv_report->Columns->Add("address", "Direcci�n Domiciliar");

		ifstream usuaa("clients.csv");

		if (!usuaa.is_open()) {
			MessageBox::Show("Error al abrir el archivo");
		}
		else {
			string line;
			int limit = 0;
			while (getline(usuaa, line)) {
				try {
					Clients^ newUser = gcnew Clients();
					string id;
					string name;
					string lastname;
					string address;
					string phonenumb;
					string email;
					string password;

					stringstream ss(line);
					getline(ss, id, ',');
					getline(ss, name, ',');
					getline(ss, lastname, ',');
					getline(ss, phonenumb, ',');
					getline(ss, email, ',');
					getline(ss, address, ',');
					getline(ss, password, ',');
					newUser->code = std::stoi(id);;
					newUser->name = gcnew String(name.c_str());
					newUser->lastName = gcnew String(lastname.c_str());
					newUser->phoneNum = gcnew String(phonenumb.c_str());
					newUser->email = gcnew String(email.c_str());
					newUser->address = gcnew String(address.c_str());
					newUser->password = gcnew String(password.c_str());

					localDataClient[limit] = newUser;
					this->dgv_report->Rows->Add(localDataClient[limit]->code, localDataClient[limit]->name, localDataClient[limit]->lastName, localDataClient[limit]->address, localDataClient[limit]->phoneNum, localDataClient[limit]->email);
					limit++;
				}
				catch (const std::exception& e) {
					std::cerr << "Excepci�n capturada: " << e.what() << std::endl;
				}
				catch (...) {
					std::cerr << "Excepci�n desconocida capturada" << std::endl;
				}
			}
		}
	}
	private: System::Void btn_inventary_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dgv_report->Rows->Clear();
		this->dgv_report->Columns->Clear();
		this->dgv_report->Columns->Add("id_product", "C�digo");
		this->dgv_report->Columns->Add("name", "Nombre");
		this->dgv_report->Columns->Add("category", "Categor�a");
		this->dgv_report->Columns->Add("brand", "Marca");
		this->dgv_report->Columns->Add("description", "Descripci�n");
		this->dgv_report->Columns->Add("price", "Precio");
		this->dgv_report->Columns->Add("stock", "Cantidad de Stock");
		ifstream products("product.csv");

		if (!products.is_open()) {
			MessageBox::Show("Error al abrir el archivo");
		}
		else {
			string line;
			int limit = 0;
			try {
				while (getline(products, line)) {
					Product^ newUser = gcnew Product();
					string id;
					string name;
					string catego;
					string brand;
					string descrip;
					string price;
					string stock;


					stringstream ss(line);
					getline(ss, id, ',');
					getline(ss, name, ',');
					getline(ss, catego, ',');
					getline(ss, brand, ',');
					getline(ss, descrip, ',');
					getline(ss, price, ',');
					getline(ss, stock, ',');
					newUser->id_product = std::stoi(id);
					newUser->name = gcnew String(name.c_str());
					newUser->catego = gcnew String(catego.c_str());
					newUser->brand = gcnew String(brand.c_str());
					newUser->descrip = gcnew String(descrip.c_str());
					newUser->price = std::stof(price);
					newUser->stock = std::stoi(stock);


					localDataProducts[limit] = newUser;
					this->dgv_report->Rows->Add(localDataProducts[limit]->id_product, localDataProducts[limit]->name, localDataProducts[limit]->catego, localDataProducts[limit]->brand, localDataProducts[limit]->descrip, localDataProducts[limit]->price, localDataProducts[limit]->stock);
					limit++;
				}
			}
			catch (const std::exception& e) {
				std::cerr << "Excepci�n capturada: " << e.what() << std::endl;
			}
			catch (...) {
				std::cerr << "Excepci�n desconocida capturada" << std::endl;
			}
		}
	}
	private: System::Void btn_purchases_Click(System::Object^ sender, System::EventArgs^ e) {
			this->dgv_report->Rows->Clear();
			this->dgv_report->Columns->Clear();
			this->dgv_report->Columns->Add("id_purchase", "ID");
			this->dgv_report->Columns->Add("user", "Usuario");
			this->dgv_report->Columns->Add("products", "Productos");
			this->dgv_report->Columns->Add("iva", "IVA");
			this->dgv_report->Columns->Add("subtotal", "Subtotal");
			this->dgv_report->Columns->Add("discount", "Descuento");
			this->dgv_report->Columns->Add("total", "Total");
			ifstream purchases("purchases.csv");
			if (!purchases.is_open()) {
				MessageBox::Show("Error al abrir el archivo");
			}
			else {
				string line;
				int limit = 0;

				while (getline(purchases, line)) {
					try {
						PurchaseProduct^ newPurchase = gcnew PurchaseProduct();
						string id;
						string user;
						string productList;
						string discount;
						string subtotal;
						string iva;
						string total;

						stringstream ss(line);
						getline(ss, id, ',');
						getline(ss, user, ',');
						getline(ss, productList, ',');
						getline(ss, iva, ',');
						getline(ss, subtotal, ',');
						getline(ss, discount, ',');
						getline(ss, total, ',');
						newPurchase->id_purchase = std::stoi(id);
						newPurchase->user = gcnew String(user.c_str());
						newPurchase->productList = gcnew String(productList.c_str());
						newPurchase->discount = std::stof(discount);
						newPurchase->subtotal = std::stof(subtotal);
						newPurchase->iva = std::stof(iva);
						newPurchase->total = std::stof(total);


						localDataPurchases[limit] = newPurchase;

						this->dgv_report->Rows->Add(localDataPurchases[limit]->id_purchase, localDataPurchases[limit]->user, localDataPurchases[limit]->productList, localDataPurchases[limit]->iva, localDataPurchases[limit]->subtotal, localDataPurchases[limit]->discount, localDataPurchases[limit]->total);

						limit++;
					}
					catch (const std::exception& e) {
						std::cerr << "Excepci�n capturada: " << e.what() << std::endl;
					}
					catch (...) {
						std::cerr << "Excepci�n desconocida capturada" << std::endl;
					}
				}
			}
	}
	private: System::Void btn_payments_Click(System::Object^ sender, System::EventArgs^ e) {
		this->dgv_report->Rows->Clear();
		this->dgv_report->Columns->Clear();
		this->dgv_report->Columns->Add("id_payment", "ID");
		this->dgv_report->Columns->Add("code", "C�digo de compra");
		this->dgv_report->Columns->Add("user", "Usuario");
		this->dgv_report->Columns->Add("products", "Productos");
		this->dgv_report->Columns->Add("type_payment", "Tipo de Pago");
		this->dgv_report->Columns->Add("total", "Total");
		this->dgv_report->Columns->Add("card", "Tarjeta");
		this->dgv_report->Columns->Add("amountBill", "Monto de Cambio");
		this->dgv_report->Columns->Add("address", "Direcci�n");
		this->dgv_report->Columns->Add("phone", "N�mero de contacto");
		ifstream purchases("payments.csv");
		if (!purchases.is_open()) {
			MessageBox::Show("Error al abrir el archivo");
		}
		else {
			string line;
			int limit = 0;

			while (getline(purchases, line)) {
				try {
					Payments^ newPayment = gcnew Payments();
					string id;
					string code;
					string user;
					string products;
					string type;
					string total;
					string card;
					string changeBill;
					string address;
					string phone;

					stringstream ss(line);
					getline(ss, id, ',');
					getline(ss, code, ',');
					getline(ss, user, ',');
					getline(ss, products, ',');
					getline(ss, type, ',');
					getline(ss, total, ',');
					getline(ss, card, ',');
					getline(ss, changeBill, ',');
					getline(ss, address, ',');
					getline(ss, phone, ',');
					newPayment->id_payment = std::stoi(id);
					newPayment->code_payment = gcnew String(code.c_str());
					newPayment->usuario = gcnew String(user.c_str());
					newPayment->productos = gcnew String(products.c_str());
					newPayment->type_payment = gcnew String(type.c_str());
					newPayment->total = std::stof(total);
					newPayment->card = gcnew String(card.c_str());
					newPayment->amountBill = gcnew String(changeBill.c_str());
					newPayment->address = gcnew String(address.c_str());
					newPayment->phoneNumb = gcnew String(phone.c_str());


					localDataPayments[limit] = newPayment;

					this->dgv_report->Rows->Add(localDataPayments[limit]->id_payment, localDataPayments[limit]->code_payment, localDataPayments[limit]->usuario, localDataPayments[limit]->productos, localDataPayments[limit]->type_payment, localDataPayments[limit]->total, localDataPayments[limit]->card, localDataPayments[limit]->amountBill, localDataPayments[limit]->address, localDataPayments[limit]->phoneNumb);

					limit++;
				}
				catch (const std::exception& e) {
					std::cerr << "Excepci�n capturada: " << e.what() << std::endl;
				}
				catch (...) {
					std::cerr << "Excepci�n desconocida capturada" << std::endl;
				}
			}
		}
	}
};
}
