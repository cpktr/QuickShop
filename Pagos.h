#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Clients.h"
#include "Product.h"
#include "PurchaseProduct.h"
#include "Payments.h"
#include "Product.h"
#include "Inventario.h"
#include "Catalogo.h"

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
	/// Resumen de Pagos
	/// </summary>
	public ref class Pagos : public System::Windows::Forms::Form
	{
	private: cli::array<Inventario^>^ localDataInventary = gcnew cli::array<Inventario^>(100);
	private: cli::array<PurchaseProduct^>^ cartShopList = gcnew cli::array<PurchaseProduct^>(100);
	private: cli::array<Catalogo^>^ productsData = gcnew cli::array<Catalogo^>(100);
	private: cli::array<Payments^>^ localData = gcnew cli::array<Payments^>(100);
	private: bool editableData = false;
	private: String^ newProductlist = "";
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txt_id;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;

	private: System::Windows::Forms::Label^ label2;



	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ txt_total;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ComboBox^ cmb_purchase;





	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::ComboBox^ cmb_typePayment;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel6;






	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ txt_code;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel_formsConts;
	private: System::Windows::Forms::Panel^ form_tarjeta;



	private: System::Windows::Forms::TextBox^ txt_cardCVV;

	private: System::Windows::Forms::TextBox^ txt_cardDate;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txt_cardNumber;
	private: System::Windows::Forms::Panel^ form_efectivo;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ txt_changeBill;






	private: System::Windows::Forms::Panel^ form_direction;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::TextBox^ txt_phoneNumber;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txt_direction;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ code;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ user;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ products;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ total;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cardNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ amountBill;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ address;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ phoneNumb;
	private: System::Windows::Forms::Button^ btn_cancelar;









	private: System::Windows::Forms::Button^ btn_guardar;
	public:
		Pagos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->getPaymentsHistory();
			this->setComboBoxPurchases();
			this->getDataProducts();
			this->getDataCatalog();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Pagos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titlePage;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;






	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void getDataProducts() {
			ifstream products("inventary.csv");

			if (!products.is_open()) {
				MessageBox::Show("Error al abrir el archivo");
			}
			else {
				string line;
				int limit = 0;
				try {
					while (getline(products, line)) {
						Inventario^ newUser = gcnew Inventario();
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
						getline(ss, stock, ',');
						newUser->id_product = std::stoi(id);
						newUser->name = gcnew String(name.c_str());
						newUser->stock = std::stoi(stock);


						localDataInventary[limit] = newUser;
						limit++;
					}
				}
				catch (const std::exception& e) {
					std::cerr << "Excepción capturada: " << e.what() << std::endl;
				}
				catch (...) {
					std::cerr << "Excepción desconocida capturada" << std::endl;
				}
			}
		}
		void getDataCatalog() {
			ifstream products("product.csv");

			if (!products.is_open()) {
				MessageBox::Show("Error al abrir el archivo");
			}
			else {
				string line;
				int limit = 0;
				try {
					while (getline(products, line)) {
						Catalogo^ newProduct = gcnew Catalogo();
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
						newProduct->id_product = std::stoi(id);
						newProduct->name = gcnew String(name.c_str());
						newProduct->catego = gcnew String(catego.c_str());
						newProduct->brand = gcnew String(brand.c_str());
						newProduct->descrip = gcnew String(descrip.c_str());
						newProduct->price = std::stof(price);
						newProduct->stock = std::stoi(stock);


						productsData[limit] = newProduct;
						limit++;
					}
				}
				catch (const std::exception& e) {
					std::cerr << "Excepción capturada: " << e.what() << std::endl;
				}
				catch (...) {
					std::cerr << "Excepción desconocida capturada" << std::endl;
				}
			}
		}
		void validateStock() {
			try {
				for (int i = 0; i < localDataInventary->Length; i++) {
					if (localDataInventary[i] != nullptr) {
						for (int j = 0; j < productsData->Length; j++) {
							if (productsData[j] != nullptr) {
								if (localDataInventary[i]->id_product == productsData[j]->id_product) {
									productsData[j]->stock = localDataInventary[i]->stock;
								}
							}
						}
					}
				}
				StreamWriter^ writer = gcnew StreamWriter("product.csv");
				for (int i = 0; i < productsData->Length; i++) {

					if (productsData[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
							productsData[i]->id_product, productsData[i]->name, productsData[i]->catego,
							productsData[i]->brand, productsData[i]->descrip, productsData[i]->price,
							productsData[i]->stock);
						writer->WriteLine(message);
					}
				}
				writer->Close();
			}
			catch (const std::exception& e) {
				std::cerr << "Excepción capturada: " << e.what() << std::endl;
			}
			catch (...) {
				std::cerr << "Excepción desconocida capturada" << std::endl;
			}
		}
		void setComboBoxPurchases() {
			this->cmb_purchase->Items->Clear();
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


						cartShopList[limit] = newPurchase;
						this->cmb_purchase->Items->Add(newPurchase->user);
						limit++;
					}
					catch (const std::exception& e) {
						std::cerr << "Excepción capturada: " << e.what() << std::endl;
					}
					catch (...) {
						std::cerr << "Excepción desconocida capturada" << std::endl;
					}
				}
			}
		}
		void getPaymentsHistory() {
			this->dataGridView1->Rows->Clear();
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


						localData[limit] = newPayment;

						this->dataGridView1->Rows->Add(localData[limit]->id_payment, localData[limit]->code_payment, localData[limit]->usuario, localData[limit]->productos, localData[limit]->type_payment, localData[limit]->total, localData[limit]->card, localData[limit]->amountBill, localData[limit]->address, localData[limit]->phoneNumb);

						limit++;
					}
					catch (const std::exception& e) {
						std::cerr << "Excepción capturada: " << e.what() << std::endl;
					}
					catch (...) {
						std::cerr << "Excepción desconocida capturada" << std::endl;
					}
				}
			}

			for (int i = 0; i < localData->Length; i++) {
				if (localData[0] == nullptr) {
					this->txt_id->Text = "1";
				}
				else {
					if (localData[i] == nullptr) {
						this->txt_id->Text = (localData[i - 1]->id_payment + 1).ToString();

						time_t now = time(0);
						tm* ltm = localtime(&now);

						int month = ltm->tm_mon;
						char* monthAbbreviations[] = { "EN", "FE", "MZ", "AB", "MY", "JN", "JL", "AG", "SP", "OC", "NV", "DC" };
						std::string monthAbbr = monthAbbreviations[month];
						int day = ltm->tm_mday;
						int year = 1900 + ltm->tm_year;
						std::ostringstream oss;
						oss << monthAbbr<< std::setw(2) << std::setfill('0')<< year;
						
						this->txt_code->Text = this->txt_id->Text+(gcnew String(oss.str().c_str()));
						break;
					}
				}
			}



			

		}
		void InitializeComponent(void)
		{
			this->titlePage = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->user = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->products = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->total = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cardNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->amountBill = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phoneNumb = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_code = (gcnew System::Windows::Forms::TextBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->cmb_purchase = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txt_total = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel_formsConts = (gcnew System::Windows::Forms::Panel());
			this->form_direction = (gcnew System::Windows::Forms::Panel());
			this->txt_phoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_direction = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->form_efectivo = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->txt_changeBill = (gcnew System::Windows::Forms::TextBox());
			this->form_tarjeta = (gcnew System::Windows::Forms::Panel());
			this->txt_cardCVV = (gcnew System::Windows::Forms::TextBox());
			this->txt_cardDate = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_cardNumber = (gcnew System::Windows::Forms::TextBox());
			this->cmb_typePayment = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->btn_guardar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel_formsConts->SuspendLayout();
			this->form_direction->SuspendLayout();
			this->form_efectivo->SuspendLayout();
			this->form_tarjeta->SuspendLayout();
			this->panel6->SuspendLayout();
			this->SuspendLayout();
			// 
			// titlePage
			// 
			this->titlePage->AutoSize = true;
			this->titlePage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->titlePage->Location = System::Drawing::Point(9, 9);
			this->titlePage->Name = L"titlePage";
			this->titlePage->Size = System::Drawing::Size(91, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Pagos";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Location = System::Drawing::Point(285, 47);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(389, 389);
			this->panel1->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(10) {
				this->id, this->code,
					this->user, this->products, this->type, this->total, this->cardNum, this->amountBill, this->address, this->phoneNumb
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(389, 389);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::deleteRowProduct);
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			// 
			// code
			// 
			this->code->HeaderText = L"Código de compra";
			this->code->Name = L"code";
			this->code->ReadOnly = true;
			// 
			// user
			// 
			this->user->HeaderText = L"Usuario";
			this->user->Name = L"user";
			this->user->ReadOnly = true;
			// 
			// products
			// 
			this->products->HeaderText = L"Productos";
			this->products->Name = L"products";
			this->products->ReadOnly = true;
			// 
			// type
			// 
			this->type->HeaderText = L"Tipo de Pago";
			this->type->Name = L"type";
			this->type->ReadOnly = true;
			// 
			// total
			// 
			this->total->HeaderText = L"Total";
			this->total->Name = L"total";
			this->total->ReadOnly = true;
			// 
			// cardNum
			// 
			this->cardNum->HeaderText = L"Tarjeta";
			this->cardNum->Name = L"cardNum";
			this->cardNum->ReadOnly = true;
			// 
			// amountBill
			// 
			this->amountBill->HeaderText = L"Monto de Cambio";
			this->amountBill->Name = L"amountBill";
			this->amountBill->ReadOnly = true;
			// 
			// address
			// 
			this->address->HeaderText = L"Dirección";
			this->address->Name = L"address";
			this->address->ReadOnly = true;
			// 
			// phoneNumb
			// 
			this->phoneNumb->HeaderText = L"Número de contacto";
			this->phoneNumb->Name = L"phoneNumb";
			this->phoneNumb->ReadOnly = true;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->panel7);
			this->flowLayoutPanel1->Controls->Add(this->panel2);
			this->flowLayoutPanel1->Controls->Add(this->panel3);
			this->flowLayoutPanel1->Controls->Add(this->panel5);
			this->flowLayoutPanel1->Controls->Add(this->panel4);
			this->flowLayoutPanel1->Controls->Add(this->panel6);
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 47);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(267, 389);
			this->flowLayoutPanel1->TabIndex = 2;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->txt_id);
			this->panel7->Controls->Add(this->label5);
			this->panel7->Location = System::Drawing::Point(3, 3);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(261, 30);
			this->panel7->TabIndex = 4;
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(158, 4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->ReadOnly = true;
			this->txt_id->Size = System::Drawing::Size(100, 20);
			this->txt_id->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"ID";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->txt_code);
			this->panel2->Location = System::Drawing::Point(3, 39);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(261, 30);
			this->panel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código de compra";
			// 
			// txt_code
			// 
			this->txt_code->Location = System::Drawing::Point(158, 4);
			this->txt_code->Name = L"txt_code";
			this->txt_code->Size = System::Drawing::Size(100, 20);
			this->txt_code->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->cmb_purchase);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(3, 75);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(261, 30);
			this->panel3->TabIndex = 2;
			// 
			// cmb_purchase
			// 
			this->cmb_purchase->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb_purchase->FormattingEnabled = true;
			this->cmb_purchase->Location = System::Drawing::Point(158, 4);
			this->cmb_purchase->Name = L"cmb_purchase";
			this->cmb_purchase->Size = System::Drawing::Size(100, 21);
			this->cmb_purchase->TabIndex = 1;
			this->cmb_purchase->SelectedIndexChanged += gcnew System::EventHandler(this, &Pagos::changeUser);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Usuario";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->txt_total);
			this->panel5->Controls->Add(this->label4);
			this->panel5->Location = System::Drawing::Point(3, 111);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(261, 30);
			this->panel5->TabIndex = 2;
			// 
			// txt_total
			// 
			this->txt_total->Location = System::Drawing::Point(158, 4);
			this->txt_total->Name = L"txt_total";
			this->txt_total->ReadOnly = true;
			this->txt_total->Size = System::Drawing::Size(100, 20);
			this->txt_total->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Total";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel_formsConts);
			this->panel4->Controls->Add(this->cmb_typePayment);
			this->panel4->Controls->Add(this->label3);
			this->panel4->Location = System::Drawing::Point(3, 147);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(261, 201);
			this->panel4->TabIndex = 3;
			// 
			// panel_formsConts
			// 
			this->panel_formsConts->Controls->Add(this->form_direction);
			this->panel_formsConts->Controls->Add(this->form_efectivo);
			this->panel_formsConts->Controls->Add(this->form_tarjeta);
			this->panel_formsConts->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_formsConts->Location = System::Drawing::Point(0, 34);
			this->panel_formsConts->Name = L"panel_formsConts";
			this->panel_formsConts->Size = System::Drawing::Size(261, 167);
			this->panel_formsConts->TabIndex = 2;
			// 
			// form_direction
			// 
			this->form_direction->Controls->Add(this->txt_phoneNumber);
			this->form_direction->Controls->Add(this->label10);
			this->form_direction->Controls->Add(this->txt_direction);
			this->form_direction->Controls->Add(this->label9);
			this->form_direction->Location = System::Drawing::Point(3, 108);
			this->form_direction->Name = L"form_direction";
			this->form_direction->Size = System::Drawing::Size(255, 56);
			this->form_direction->TabIndex = 2;
			this->form_direction->Visible = false;
			// 
			// txt_phoneNumber
			// 
			this->txt_phoneNumber->Location = System::Drawing::Point(148, 25);
			this->txt_phoneNumber->Name = L"txt_phoneNumber";
			this->txt_phoneNumber->Size = System::Drawing::Size(103, 20);
			this->txt_phoneNumber->TabIndex = 3;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(147, 9);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(104, 13);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Número de contacto";
			// 
			// txt_direction
			// 
			this->txt_direction->Location = System::Drawing::Point(5, 25);
			this->txt_direction->Name = L"txt_direction";
			this->txt_direction->Size = System::Drawing::Size(137, 20);
			this->txt_direction->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(52, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Dirección";
			// 
			// form_efectivo
			// 
			this->form_efectivo->Controls->Add(this->label11);
			this->form_efectivo->Controls->Add(this->txt_changeBill);
			this->form_efectivo->Location = System::Drawing::Point(3, 3);
			this->form_efectivo->Name = L"form_efectivo";
			this->form_efectivo->Size = System::Drawing::Size(255, 99);
			this->form_efectivo->TabIndex = 1;
			this->form_efectivo->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(175, 13);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Ingrese monto para calcular cambio";
			// 
			// txt_changeBill
			// 
			this->txt_changeBill->Location = System::Drawing::Point(3, 25);
			this->txt_changeBill->Name = L"txt_changeBill";
			this->txt_changeBill->Size = System::Drawing::Size(248, 20);
			this->txt_changeBill->TabIndex = 0;
			this->txt_changeBill->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateAmountExist);
			this->txt_changeBill->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateAmountExist);
			// 
			// form_tarjeta
			// 
			this->form_tarjeta->Controls->Add(this->txt_cardCVV);
			this->form_tarjeta->Controls->Add(this->txt_cardDate);
			this->form_tarjeta->Controls->Add(this->label8);
			this->form_tarjeta->Controls->Add(this->label7);
			this->form_tarjeta->Controls->Add(this->label6);
			this->form_tarjeta->Controls->Add(this->txt_cardNumber);
			this->form_tarjeta->Location = System::Drawing::Point(3, 3);
			this->form_tarjeta->Name = L"form_tarjeta";
			this->form_tarjeta->Size = System::Drawing::Size(255, 99);
			this->form_tarjeta->TabIndex = 0;
			this->form_tarjeta->Visible = false;
			// 
			// txt_cardCVV
			// 
			this->txt_cardCVV->Location = System::Drawing::Point(143, 64);
			this->txt_cardCVV->MaxLength = 3;
			this->txt_cardCVV->Name = L"txt_cardCVV";
			this->txt_cardCVV->Size = System::Drawing::Size(108, 20);
			this->txt_cardCVV->TabIndex = 5;
			this->txt_cardCVV->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateCVVCard);
			this->txt_cardCVV->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateCVVCard);
			// 
			// txt_cardDate
			// 
			this->txt_cardDate->Location = System::Drawing::Point(4, 65);
			this->txt_cardDate->MaxLength = 5;
			this->txt_cardDate->Name = L"txt_cardDate";
			this->txt_cardDate->Size = System::Drawing::Size(108, 20);
			this->txt_cardDate->TabIndex = 4;
			this->txt_cardDate->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateDateCard);
			this->txt_cardDate->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateDateCard);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(140, 48);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(28, 13);
			this->label8->TabIndex = 3;
			this->label8->Text = L"CVV";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 48);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Fecha";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(91, 13);
			this->label6->TabIndex = 1;
			this->label6->Text = L"Número de tarjeta";
			// 
			// txt_cardNumber
			// 
			this->txt_cardNumber->Location = System::Drawing::Point(3, 25);
			this->txt_cardNumber->MaxLength = 19;
			this->txt_cardNumber->Name = L"txt_cardNumber";
			this->txt_cardNumber->Size = System::Drawing::Size(248, 20);
			this->txt_cardNumber->TabIndex = 0;
			this->txt_cardNumber->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateNumberCard);
			this->txt_cardNumber->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Pagos::validateNumberCard);
			// 
			// cmb_typePayment
			// 
			this->cmb_typePayment->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb_typePayment->FormattingEnabled = true;
			this->cmb_typePayment->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Efectivo", L"Tarjeta" });
			this->cmb_typePayment->Location = System::Drawing::Point(158, 4);
			this->cmb_typePayment->Name = L"cmb_typePayment";
			this->cmb_typePayment->Size = System::Drawing::Size(100, 21);
			this->cmb_typePayment->TabIndex = 1;
			this->cmb_typePayment->SelectedIndexChanged += gcnew System::EventHandler(this, &Pagos::changeTypePayment);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(71, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Tipo de Pago";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->btn_cancelar);
			this->panel6->Controls->Add(this->btn_guardar);
			this->panel6->Location = System::Drawing::Point(3, 354);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(261, 30);
			this->panel6->TabIndex = 3;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::Transparent;
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->ForeColor = System::Drawing::Color::Teal;
			this->btn_cancelar->Location = System::Drawing::Point(106, 3);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(75, 23);
			this->btn_cancelar->TabIndex = 1;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Pagos::btn_cancelar_Click);
			// 
			// btn_guardar
			// 
			this->btn_guardar->BackColor = System::Drawing::Color::Teal;
			this->btn_guardar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_guardar->FlatAppearance->BorderSize = 0;
			this->btn_guardar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_guardar->ForeColor = System::Drawing::Color::White;
			this->btn_guardar->Location = System::Drawing::Point(183, 3);
			this->btn_guardar->Name = L"btn_guardar";
			this->btn_guardar->Size = System::Drawing::Size(75, 23);
			this->btn_guardar->TabIndex = 0;
			this->btn_guardar->Text = L"Guardar";
			this->btn_guardar->UseVisualStyleBackColor = false;
			this->btn_guardar->Click += gcnew System::EventHandler(this, &Pagos::savePayment);
			// 
			// Pagos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Pagos";
			this->Text = L"Pagos";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel_formsConts->ResumeLayout(false);
			this->form_direction->ResumeLayout(false);
			this->form_direction->PerformLayout();
			this->form_efectivo->ResumeLayout(false);
			this->form_efectivo->PerformLayout();
			this->form_tarjeta->ResumeLayout(false);
			this->form_tarjeta->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:System::Void validateNumberCard(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int cursorPosition = this->txt_cardNumber->SelectionStart;
		String^ text = this->txt_cardNumber->Text;
		String^ cleanedText = text->Replace("-", "");
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		for (int i = 0; i < cleanedText->Length; i++) {
			if (i > 0 && i % 4 == 0) {
				sb->Append("-");
			}
			sb->Append(cleanedText[i]);
		}

		this->txt_cardNumber->Text = sb->ToString();

		if (cursorPosition > 0 && cursorPosition < this->txt_cardNumber->Text->Length && this->txt_cardNumber->Text[cursorPosition - 1] == '-') {
			cursorPosition++;
		}
		this->txt_cardNumber->SelectionStart = cursorPosition;
		validateCardExist();
	}
	private:System::Void validateCVVCard(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		validateCardExist();
	}
	private:System::Void validateDateCard(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		int cursorPosition = txt_cardDate->SelectionStart;
		String^ text = txt_cardDate->Text;
		String^ cleanedText = text->Replace("/", "");
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		for (int i = 0; i < cleanedText->Length; i++) {
			if (i == 2) {
				sb->Append("/");
			}
			sb->Append(cleanedText[i]);
		}
		txt_cardDate->Text = sb->ToString();
		if (cursorPosition > 0 && cursorPosition < txt_cardDate->Text->Length && txt_cardDate->Text[cursorPosition - 1] == '/') {
			cursorPosition++;
		}
		txt_cardDate->SelectionStart = cursorPosition;
		validateCardExist();
	}
	private: void validateCardExist() {
		if (this->txt_cardNumber->Text->Length == 19 && this->txt_cardDate->Text->Length == 5 && this->txt_cardCVV->Text->Length == 3) {
			this->form_direction->Visible = true;
		}
		else {
			this->form_direction->Visible = false;
			this->txt_direction->Clear();
			this->txt_phoneNumber->Clear();
		}
	}
	private: System::Void validateAmountExist(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (this->txt_changeBill->Text->Length >= 1) {
			this->form_direction->Visible = true;
		}
		else {
			this->form_direction->Visible = false;
			this->txt_direction->Clear();
			this->txt_phoneNumber->Clear();
		}
	}

	private: bool CamposNoVacios() {
		return !(String::IsNullOrEmpty(this->txt_id->Text) ||
			(this->cmb_purchase->SelectedIndex == -1) ||
			String::IsNullOrEmpty(this->txt_total->Text) || 
			(this->cmb_typePayment->SelectedIndex == -1) ||
			String::IsNullOrEmpty(this->txt_direction->Text) ||
			String::IsNullOrEmpty(this->txt_phoneNumber->Text));
	}
	private: bool validateExistData() {
		String^ newId = gcnew String(this->txt_id->Text);
		String^ newCode = gcnew String(this->txt_code->Text);


		for (int i = 0; i < localData->Length; i++) {
			if (localData[i] != nullptr) {
				if (!editableData && localData[i]->id_payment.ToString() == newId) {
					MessageBox::Show("El ID de la compra ya existe en registros anteriores", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				if (localData[i]->usuario == newCode && localData[i]->id_payment.ToString() != newId) {
					MessageBox::Show("El Usuario ya posee un carrito", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
			}
		}
		return true;
	}
	private: void clearTxt() {
		this->txt_id->Clear();
		this->txt_code->Clear();
		this->cmb_purchase->SelectedIndex = -1;
		this->cmb_typePayment->SelectedIndex = -1;
		this->txt_total->Clear();
		this->txt_direction->Clear();
		this->txt_phoneNumber->Clear();
		this->txt_changeBill->Clear();
		this->txt_cardNumber->Clear();
		this->txt_cardCVV->Clear();
		this->txt_cardDate->Clear();
		
	}
	private: String^ CifrarNumero(String^ numero) {
		int length = numero->Length;
		using namespace System::Runtime::InteropServices;
		const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(numero)).ToPointer();
		std::string stdNumero = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		string first;
		string second;
		string third;
		string forth;
		stringstream ss(stdNumero);
		getline(ss, first, '-');
		getline(ss, second, '-');
		getline(ss, third, '-');
		getline(ss, forth, '-');
		String^ message = "####-####-####-" + gcnew String(forth.c_str());
		

		return message;
	}
	private: System::Void savePayment(System::Object^ sender, System::EventArgs^ e) {
		Payments^ newProduct = gcnew Payments();
		int indice = -1;
		for (int i = 0; i < localData->Length; i++) {
			if (localData[i] == nullptr) {
				indice = i;
				break;
			}
		}
		if (indice != -1) {
			if (CamposNoVacios()) {
				if (validateExistData()) {
					try {
						bool existStock = true;
						System::String^ strId = this->txt_id->Text;
						int id = System::Convert::ToInt32(strId);
						System::String^ strTotal = this->txt_total->Text;
						newProduct->id_payment = id;
						newProduct->code_payment = gcnew String(this->txt_code->Text);
						newProduct->usuario = gcnew String(this->cmb_purchase->Text);
						newProduct->type_payment = gcnew String(this->cmb_typePayment->Text);
						newProduct->productos = newProductlist;
						newProduct->total = System::Convert::ToSingle(strTotal);
						String^ cardNumber = gcnew String(this->txt_cardNumber->Text);
						String^ cardNumberCifrado = CifrarNumero(cardNumber);
						this->txt_cardNumber->Text->Length > 0 ? newProduct->card = cardNumberCifrado : "N/A";
						this->txt_changeBill->Text->Length > 0 ? newProduct->amountBill = gcnew String(this->txt_changeBill->Text) : "N/A";
						newProduct->address = gcnew String(this->txt_direction->Text);
						newProduct->phoneNumb = gcnew String(this->txt_phoneNumber->Text);
						this->localData[indice] = newProduct;

						//Validar Stock
						System::String^ dataProductsCli = Convert::ToString(newProduct->productos);
						string dataProducts;
						for (int i = 0; i < dataProductsCli->Length; i++) {
							dataProducts += (char)dataProductsCli[i];
						}
						string item;
						stringstream ss(dataProducts);
						while (std::getline(ss, item, '|')) {
							if (!item.empty()) {
								size_t pos = item.find('*');
								if (pos != std::string::npos) {
									std::string productName = item.substr(0, pos);
									int quantity = std::stoi(item.substr(pos + 1));
									for (int i = 0; i < localDataInventary->Length; i++) {
										if (localDataInventary[i] != nullptr) {
											if (localDataInventary[i]->name == gcnew String(productName.c_str())) {
												if (localDataInventary[i]->stock < quantity) {
													existStock = false;
													break;
												}
											}
										}
									}
									if (!existStock) {
										break;
									}
								}
							}
						}

						if (!existStock) {
							MessageBox::Show("No hay stock suficiente");
						}
						else {
							deleteProducts(newProduct->productos);
							StreamWriter^ writer = gcnew StreamWriter("payments.csv");
							for (int i = 0; i < localData->Length; i++) {
								if (localData[i] != nullptr) {
									String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6},{7},{8},{9}",
										localData[i]->id_payment, localData[i]->code_payment, localData[i]->usuario,
										localData[i]->productos, localData[i]->type_payment, localData[i]->total,
										localData[i]->card, localData[i]->amountBill, localData[i]->address, localData[i]->phoneNumb);
									writer->WriteLine(message);
								}
							}
							writer->Close();
							this->deletePurchase(gcnew String(this->cmb_purchase->Text));
							this->getPaymentsHistory();
							this->clearTxt();
							this->form_direction->Visible = false;
							this->form_efectivo->Visible = false;
							this->form_tarjeta->Visible = false;
							MessageBox::Show("El pago se realizó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
						}
				
					}
					catch (const std::exception& e) {
						std::cerr << "Excepción capturada: " << e.what() << std::endl;
					}
					catch (...) {
						std::cerr << "Excepción desconocida capturada" << std::endl;
					}
				}

			}
			else {
				MessageBox::Show("Por favor, completa todos los campos antes de agregar un nuevo usuario.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("No hay espacio disponible para agregar más productos.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void changeUser(System::Object^ sender, System::EventArgs^ e) {
		try {
			for (int i = 0; i < cartShopList->Length; i++) {
				if (cartShopList[i] != nullptr) {
					if (cartShopList[i]->user == this->cmb_purchase->Text) {
						this->newProductlist = cartShopList[i]->productList;
						this->txt_total->Text = cartShopList[i]->total.ToString();
					}
				}
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Excepción capturada: " << e.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Excepción desconocida capturada" << std::endl;
		}
	}
	private: System::Void changeTypePayment(System::Object^ sender, System::EventArgs^ e) {
		try {
			this->form_direction->Visible = false;
			this->txt_direction->Clear();
			this->txt_phoneNumber->Clear();
			if (this->cmb_typePayment->Text == "Efectivo") {
				this->form_efectivo->Visible = true;
				this->form_tarjeta->Visible = false;
				this->txt_cardNumber->Clear();
				this->txt_cardCVV->Clear();
				this->txt_cardDate->Clear();
			}
			else if (this->cmb_typePayment->Text == "Tarjeta") {
				this->form_tarjeta->Visible = true;
				this->form_efectivo->Visible = false;
				this->txt_changeBill->Clear();
			}
		}
		catch (const std::exception& e) {
			std::cerr << "Excepción capturada: " << e.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Excepción desconocida capturada" << std::endl;
		}
	}

	private: System::Void deletePurchase(String^ email) {
		cli::array<PurchaseProduct^>^ nuevoCarritList = gcnew cli::array<PurchaseProduct^>(cartShopList->Length);
		for (int i = 0; i < cartShopList->Length; i++) {
			if (cartShopList[i] != nullptr) {
				if (cartShopList[i]->user != email) {
					nuevoCarritList[i] = cartShopList[i];
				}
			}
		}
		cartShopList = nuevoCarritList;
		
		StreamWriter^ writer = gcnew StreamWriter("purchases.csv");
		for (int i = 0; i < cartShopList->Length; i++) {
			if (cartShopList[i] != nullptr) {
				String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
					cartShopList[i]->id_purchase, cartShopList[i]->user, cartShopList[i]->productList,
					cartShopList[i]->iva, cartShopList[i]->subtotal, cartShopList[i]->discount,
					cartShopList[i]->total);
				writer->WriteLine(message);
			}
		}
		writer->Close();
		this->setComboBoxPurchases();
	}

	private: System::Void deleteProducts(String^ productsText) {
		
		System::String^ dataProductsCli = Convert::ToString(productsText);
		string dataProducts;
		for (int i = 0; i < dataProductsCli->Length; i++) {
			dataProducts += (char)dataProductsCli[i];
		}
		string item;
		stringstream ss(dataProducts);
		while (std::getline(ss, item, '|')) {
			if (!item.empty()) {
				size_t pos = item.find('*');
				if (pos != std::string::npos) {
					std::string productName = item.substr(0, pos);
					int quantity = std::stoi(item.substr(pos + 1));
					for (int i = 0; i < localDataInventary->Length; i++) {
						if (localDataInventary[i] != nullptr) {
							if (localDataInventary[i]->name == gcnew String(productName.c_str())) {
								localDataInventary[i]->deleteStock(quantity);
							}
						}
					}
				}
			}
		}
		StreamWriter^ writer = gcnew StreamWriter("inventary.csv");
		for (int i = 0; i < localDataInventary->Length; i++) {
			if (localDataInventary[i] != nullptr) {
				String^ message = String::Format("{0},{1},{2}",
					localDataInventary[i]->id_product, localDataInventary[i]->name, localDataInventary[i]->stock);
				writer->WriteLine(message);
			}
		}
		writer->Close();
		this->validateStock();
	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->cmb_purchase->SelectedIndex = -1;
		this->cmb_typePayment->SelectedIndex = -1;
		this->txt_total->Clear();
		this->txt_direction->Clear();
		this->txt_phoneNumber->Clear();
		this->txt_changeBill->Clear();
		this->txt_cardNumber->Clear();
		this->txt_cardCVV->Clear();
		this->txt_cardDate->Clear();
		this->form_direction->Visible = false;
		this->form_efectivo->Visible = false;
		this->form_tarjeta->Visible = false;
	}

	private: System::Void deleteRowProduct(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			DataGridViewRow^ filaSeleccionada = this->dataGridView1->SelectedRows[0];
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Estás seguro de querer eliminar estos datos?", "Eliminar Usuario", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::OK) {
				cli::array<Payments^>^ nuevoLocalData = gcnew cli::array<Payments^>(localData->Length);
				for (int i = 0; i < localData->Length; i++) {
					if (localData[i] != nullptr) {
						if (localData[i]->id_payment.ToString() != filaSeleccionada->Cells[0]->Value->ToString()) {
							nuevoLocalData[i] = localData[i];
						}
					}
				}
				localData = nuevoLocalData;
				StreamWriter^ writer = gcnew StreamWriter("payments.csv");
				for (int i = 0; i < localData->Length; i++) {
					if (localData[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6},{7},{8},{9}",
							localData[i]->id_payment, localData[i]->code_payment, localData[i]->usuario,
							localData[i]->productos, localData[i]->type_payment, localData[i]->total,
							localData[i]->card, localData[i]->amountBill, localData[i]->address, localData[i]->phoneNumb);
						writer->WriteLine(message);
					}
				}
				writer->Close();
				this->clearTxt();
				this->getPaymentsHistory();
				MessageBox::Show("Registro eliminado correctamente", "Completado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
	}

};
}
