#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "Clients.h"
#include "Product.h"
#include "Catalogo.h"
#include "PurchaseProduct.h"
#include "Inventario.h"
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
	/// Resumen de Compras
	/// </summary>
	public ref class Compras : public System::Windows::Forms::Form
	{
	private: cli::array<Clients^>^ clientsData = gcnew cli::array<Clients^>(100);
	private: cli::array<Catalogo^>^ productsData = gcnew cli::array<Catalogo^>(100);
	private: cli::array<PurchaseProduct^>^ localData = gcnew cli::array<PurchaseProduct^>(100);
	private: cli::array<Inventario^>^ localDataIventary = gcnew cli::array<Inventario^>(100);
	private: bool editableData = false;
	private: float aplicableDiscount = 0;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::Label^ label2;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::ComboBox^ cmb_users;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btn_savePurchase;
	private: System::Windows::Forms::Button^ btn_cancel;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel_productslist;

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Panel^ panel_discount;

	private: System::Windows::Forms::TextBox^ txt_discount;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ToolTip^ tooltip_discount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ user;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ products;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ iva;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ subtotal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ discount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ total;










	private: float totalCost = 0;
	public:
		Compras(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->getPurchasesData();
			this->getClientsData();
			this->getDataProducts();
			this->setComboInventary();
			if (this->clientsData->Length > 0) {
				for (int i = 0; i < clientsData->Length; i++) {
					if (clientsData[i] != nullptr) {
						this->cmb_users->Items->Add(clientsData[i]->email);
					}
				}
			}

			//Agregar los productos al panel
			this->validateStock();


		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Compras()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::DataGridView^ dgv_compras;
	private: System::ComponentModel::IContainer^ components;









	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void setComboInventary() {
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


						localDataIventary[limit] = newUser;
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
		void getPurchasesData() {
			this->dgv_compras->Rows->Clear();
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


						localData[limit] = newPurchase;

						this->dgv_compras->Rows->Add(localData[limit]->id_purchase, localData[limit]->user, localData[limit]->productList, localData[limit]->iva, localData[limit]->subtotal, localData[limit]->discount, localData[limit]->total);

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
		void getClientsData() {
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

						clientsData[limit] = newUser;
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
		void getDataProducts() {
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

		void generateListProduct() {
			int yOffset = 0;
			try {
				for (int i = 0; i < productsData->Length; i++) {
					System::Windows::Forms::Label^ nameLabel = gcnew System::Windows::Forms::Label();
					nameLabel->Text = productsData[i]->name;
					nameLabel->Location = System::Drawing::Point(10, yOffset);
					nameLabel->Size = System::Drawing::Size(65, 13);
					panel_productslist->Controls->Add(nameLabel);

					System::Windows::Forms::Label^ priceLabel = gcnew System::Windows::Forms::Label();
					priceLabel->Text = "Q." + productsData[i]->price;
					priceLabel->Location = System::Drawing::Point(75, yOffset);
					priceLabel->Size = System::Drawing::Size(55, 13);
					panel_productslist->Controls->Add(priceLabel);

					System::Windows::Forms::NumericUpDown^ quantityUpDown = gcnew System::Windows::Forms::NumericUpDown();
					quantityUpDown->Minimum = 0;
					quantityUpDown->Maximum = productsData[i]->stock;
					quantityUpDown->Value = 0;
					quantityUpDown->Size = System::Drawing::Size(100, 20);
					quantityUpDown->Location = System::Drawing::Point(158, yOffset);
					quantityUpDown->Name = "nud_" + productsData[i]->id_product.ToString();
					panel_productslist->Controls->Add(quantityUpDown);
					quantityUpDown->ValueChanged += gcnew System::EventHandler(this, &Compras::OnQuantityChanged);
					yOffset += 25;
				}
			}
			catch (...) {

			}
		}
		void validateStock() {
			try {
				for (int i = 0; i < localDataIventary->Length; i++) {
					if (localDataIventary[i] != nullptr) {
						for (int j = 0; j < productsData->Length; j++) {
							if (productsData[j] != nullptr) {
								if (localDataIventary[i]->id_product == productsData[j]->id_product) {
									productsData[j]->stock = localDataIventary[i]->stock;
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
				this->generateListProduct();
			}
			catch (const std::exception& e) {
				std::cerr << "Excepción capturada: " << e.what() << std::endl;
			}
			catch (...) {
				std::cerr << "Excepción desconocida capturada" << std::endl;
			}
		}
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dgv_compras = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->user = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->products = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->iva = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->subtotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->discount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->total = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->cmb_users = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btn_savePurchase = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel_productslist = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel_discount = (gcnew System::Windows::Forms::Panel());
			this->txt_discount = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->tooltip_discount = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compras))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel8->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel_discount->SuspendLayout();
			this->panel9->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(268, 31);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Proceso de Compras";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dgv_compras);
			this->panel1->Location = System::Drawing::Point(285, 47);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(389, 389);
			this->panel1->TabIndex = 1;
			// 
			// dgv_compras
			// 
			this->dgv_compras->AllowUserToAddRows = false;
			this->dgv_compras->AllowUserToDeleteRows = false;
			this->dgv_compras->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_compras->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id, this->user,
					this->products, this->iva, this->subtotal, this->discount, this->total
			});
			this->dgv_compras->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv_compras->Location = System::Drawing::Point(0, 0);
			this->dgv_compras->Name = L"dgv_compras";
			this->dgv_compras->ReadOnly = true;
			this->dgv_compras->RowHeadersVisible = false;
			this->dgv_compras->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_compras->Size = System::Drawing::Size(389, 389);
			this->dgv_compras->TabIndex = 0;
			this->dgv_compras->DoubleClick += gcnew System::EventHandler(this, &Compras::editData);
			this->dgv_compras->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Compras::deleteRowPurchase);
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
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
			this->products->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			// 
			// iva
			// 
			this->iva->HeaderText = L"IVA";
			this->iva->Name = L"iva";
			this->iva->ReadOnly = true;
			// 
			// subtotal
			// 
			this->subtotal->HeaderText = L"SubTotal";
			this->subtotal->Name = L"subtotal";
			this->subtotal->ReadOnly = true;
			// 
			// discount
			// 
			this->discount->HeaderText = L"Descuento";
			this->discount->Name = L"discount";
			this->discount->ReadOnly = true;
			// 
			// total
			// 
			this->total->HeaderText = L"Total";
			this->total->Name = L"total";
			this->total->ReadOnly = true;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->txt_id);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(261, 30);
			this->panel3->TabIndex = 0;
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(158, 4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->Size = System::Drawing::Size(100, 20);
			this->txt_id->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"ID";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(55, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Productos";
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->cmb_users);
			this->panel8->Controls->Add(this->label7);
			this->panel8->Location = System::Drawing::Point(3, 39);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(261, 30);
			this->panel8->TabIndex = 2;
			// 
			// cmb_users
			// 
			this->cmb_users->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb_users->FormattingEnabled = true;
			this->cmb_users->Location = System::Drawing::Point(158, 4);
			this->cmb_users->Name = L"cmb_users";
			this->cmb_users->Size = System::Drawing::Size(100, 21);
			this->cmb_users->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 7);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Usuarios";
			// 
			// btn_savePurchase
			// 
			this->btn_savePurchase->BackColor = System::Drawing::Color::Teal;
			this->btn_savePurchase->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_savePurchase->FlatAppearance->BorderSize = 0;
			this->btn_savePurchase->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_savePurchase->ForeColor = System::Drawing::Color::White;
			this->btn_savePurchase->Location = System::Drawing::Point(183, 3);
			this->btn_savePurchase->Name = L"btn_savePurchase";
			this->btn_savePurchase->Size = System::Drawing::Size(75, 23);
			this->btn_savePurchase->TabIndex = 3;
			this->btn_savePurchase->Text = L"Guardar";
			this->btn_savePurchase->UseVisualStyleBackColor = false;
			this->btn_savePurchase->Click += gcnew System::EventHandler(this, &Compras::btn_savePurchase_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancel->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			this->btn_cancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancel->ForeColor = System::Drawing::Color::Teal;
			this->btn_cancel->Location = System::Drawing::Point(102, 3);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(75, 23);
			this->btn_cancel->TabIndex = 4;
			this->btn_cancel->Text = L"Cancelar";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Visible = false;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &Compras::cancelButton);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->panel3);
			this->flowLayoutPanel1->Controls->Add(this->panel8);
			this->flowLayoutPanel1->Controls->Add(this->panel7);
			this->flowLayoutPanel1->Controls->Add(this->panel_discount);
			this->flowLayoutPanel1->Controls->Add(this->panel9);
			this->flowLayoutPanel1->Location = System::Drawing::Point(12, 47);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(267, 389);
			this->flowLayoutPanel1->TabIndex = 3;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->panel_productslist);
			this->panel7->Controls->Add(this->panel2);
			this->panel7->Location = System::Drawing::Point(3, 75);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(261, 234);
			this->panel7->TabIndex = 2;
			// 
			// panel_productslist
			// 
			this->panel_productslist->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_productslist->Location = System::Drawing::Point(0, 38);
			this->panel_productslist->Name = L"panel_productslist";
			this->panel_productslist->Size = System::Drawing::Size(261, 196);
			this->panel_productslist->TabIndex = 4;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label6);
			this->panel2->Location = System::Drawing::Point(0, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(261, 31);
			this->panel2->TabIndex = 3;
			// 
			// panel_discount
			// 
			this->panel_discount->Controls->Add(this->txt_discount);
			this->panel_discount->Controls->Add(this->label3);
			this->panel_discount->Location = System::Drawing::Point(3, 315);
			this->panel_discount->Name = L"panel_discount";
			this->panel_discount->Size = System::Drawing::Size(261, 30);
			this->panel_discount->TabIndex = 2;
			this->panel_discount->MouseHover += gcnew System::EventHandler(this, &Compras::OnPanelDiscountMouseHover);
			// 
			// txt_discount
			// 
			this->txt_discount->Location = System::Drawing::Point(158, 4);
			this->txt_discount->Name = L"txt_discount";
			this->txt_discount->Size = System::Drawing::Size(100, 20);
			this->txt_discount->TabIndex = 1;
			this->txt_discount->Text = L"1";
			this->tooltip_discount->SetToolTip(this->txt_discount, L"El descuento es en porcentaje y se aplica luego de Q.100.00 de compra");
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Descuento";
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->btn_cancel);
			this->panel9->Controls->Add(this->btn_savePurchase);
			this->panel9->Location = System::Drawing::Point(3, 351);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(261, 30);
			this->panel9->TabIndex = 5;
			// 
			// Compras
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Compras";
			this->Text = L"Compras";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compras))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel_discount->ResumeLayout(false);
			this->panel_discount->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void changeSelection(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void SetupToolTip() {
		tooltip_discount->AutoPopDelay = 5000; // Tiempo que el ToolTip permanece visible
		tooltip_discount->InitialDelay = 1000; // Tiempo antes de que aparezca el ToolTip
		tooltip_discount->ReshowDelay = 500;   // Tiempo antes de que se vuelva a mostrar el ToolTip
		tooltip_discount->SetToolTip(panel_discount, "El descuento es en porcentaje y se aplica luego de Q.100.00 de subtotal");
	}

	private: System::Void OnPanelDiscountMouseHover(System::Object^ sender, System::EventArgs^ e) {
		tooltip_discount->Show("El descuento es en porcentaje y se aplica luego de Q.100.00 de subtotal", panel_discount);
	}

	private: System::Void OnQuantityChanged(System::Object^ sender, System::EventArgs^ e) {
		int productIndex = 0;
		float subT1 = 0;
		float subT2 = 0;
		for each (Control ^ control in panel_productslist->Controls) {
			if (dynamic_cast<NumericUpDown^>(control) != nullptr) {

				System::Windows::Forms::NumericUpDown^ quantityUpDown = safe_cast<System::Windows::Forms::NumericUpDown^>(control);

				int quantity = static_cast<int>(quantityUpDown->Value);
				if (quantity != 0) {
					
					subT1 += productsData[productIndex]->price * quantity;
					
					productIndex++;
				}
			}
		}
		subT2 = subT1;
		System::String^ strDiscount = this->txt_discount->Text;
		float disccount = System::Convert::ToSingle(strDiscount);
		if (subT2 > 100) {
			//this->txt_discount->Text = Math::Round(subT2 * 0.01, 2).ToString();
			this->aplicableDiscount = Math::Round(subT2 * (disccount / 100), 2);
		}
		else {
			this->aplicableDiscount = 0;
		}
		
	}

	private: bool validateExistData() {
		String^ newId = gcnew String(this->txt_id->Text);
		String^ newName = gcnew String(this->cmb_users->Text);

		for (int i = 0; i < localData->Length; i++) {
			if (localData[i] != nullptr) {
				if (!editableData && localData[i]->id_purchase.ToString() == newId) {
					MessageBox::Show("El ID de la compra ya existe en registros anteriores", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				if (localData[i]->user == newName && localData[i]->id_purchase.ToString() != newId) {
					MessageBox::Show("El Usuario ya posee un carrito", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
			}
		}
		return true;
	}

	private: bool CamposNoVacios() {
		return !(String::IsNullOrEmpty(this->txt_id->Text) ||
			(this->cmb_users->SelectedIndex == -1));
	}

	private: void clearTxt() {
		this->txt_id->Clear();
		this->cmb_users->SelectedIndex = -1;
		this->txt_discount->Text = "1";
		for each (Control ^ control in panel_productslist->Controls) {
			if (dynamic_cast<System::Windows::Forms::NumericUpDown^>(control) != nullptr) {
				System::Windows::Forms::NumericUpDown^ quantityUpDown = safe_cast<System::Windows::Forms::NumericUpDown^>(control);
				quantityUpDown->Value = 0;
			}
		}
	}

	private: System::Void btn_savePurchase_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->editableData) {
			if (validateExistData()) {
				if (CamposNoVacios()) {
					DataGridViewRow^ filaSeleccionada = this->dgv_compras->SelectedRows[0];
					for (int i = 0; i < localData->Length; i++) {
						if (localData[i] != nullptr) {
							if (filaSeleccionada->Cells[0]->Value->ToString() == localData[i]->id_purchase.ToString()) {
								try {
									PurchaseProduct^ newProduct = gcnew PurchaseProduct();
									System::String^ strId = this->txt_id->Text;
									int id = System::Convert::ToInt32(strId);
									newProduct->id_purchase = id;
									newProduct->user = gcnew String(this->cmb_users->Text);
									//Agregar array de Productos
									int productIndex = 0;
									float subT1 = 0;
									float subT2 = 0;
									int quantityTotal = 0;
									String^ messageProducts;

									for each (Control ^ control in panel_productslist->Controls) {
										if (dynamic_cast<NumericUpDown^>(control) != nullptr) {

											System::Windows::Forms::NumericUpDown^ quantityUpDown = safe_cast<System::Windows::Forms::NumericUpDown^>(control);

											int quantity = static_cast<int>(quantityUpDown->Value);
											if (quantity > 0) {
												
												messageProducts += productsData[productIndex]->name + "*" + quantity + "|";
												subT1 += productsData[productIndex]->price * quantity;
												//newProductList[productIndex] = pr;
												
											}
											productIndex++;
										}
									}
									subT2 = subT1;

									newProduct->productList = messageProducts;
									newProduct->iva = Math::Round(subT2 * 0.12, 2);

									newProduct->discount = System::Convert::ToSingle(this->txt_discount->Text);
									newProduct->subtotal = Math::Round(subT2, 2);
									newProduct->total = Math::Round((subT2 - this->aplicableDiscount) + newProduct->iva, 2);
									this->localData[i] = newProduct;

									StreamWriter^ writer = gcnew StreamWriter("purchases.csv");
									for (int i = 0; i < localData->Length; i++) {

										if (localData[i] != nullptr) {
											String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
												localData[i]->id_purchase, localData[i]->user, localData[i]->productList,
												localData[i]->iva, localData[i]->subtotal, localData[i]->discount,
												localData[i]->total);
											writer->WriteLine(message);
										}
									}
									writer->Close();
									this->getPurchasesData();
									this->clearTxt();
									this->txt_id->ReadOnly = false;
									this->editableData = false;
									this->btn_cancel->Visible = false;
									MessageBox::Show("El producto se actualizó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
									break;
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
				}
			}
		}
		else {
			PurchaseProduct^ newProduct = gcnew PurchaseProduct();
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
							System::String^ strId = this->txt_id->Text;
							int id = System::Convert::ToInt32(strId);
							newProduct->id_purchase = id;
							newProduct->user = gcnew String(this->cmb_users->Text);

							int productIndex = 0;
							float subT1 = 0;
							float subT2 = 0;
							int quantityTotal = 0;
							String^ messageProducts = "";

							for each (Control ^ control in panel_productslist->Controls) {
								if (dynamic_cast<NumericUpDown^>(control) != nullptr) {
									System::Windows::Forms::NumericUpDown^ quantityUpDown = safe_cast<System::Windows::Forms::NumericUpDown^>(control);
									int quantity = static_cast<int>(quantityUpDown->Value);

									if (quantity > 0) {
										messageProducts += productsData[productIndex]->name + "*" + quantity + "|";
										subT1 += productsData[productIndex]->price * quantity;
									}

									productIndex++;
								}
							}
							subT2 = subT1;

							newProduct->productList = messageProducts;
							newProduct->iva = Math::Round(subT2 * 0.12, 2);

							newProduct->discount = System::Convert::ToSingle(this->txt_discount->Text);
							newProduct->subtotal = Math::Round(subT2, 2);
							newProduct->total = Math::Round((subT2 - this->aplicableDiscount) + newProduct->iva, 2);
							this->localData[indice] = newProduct;

							StreamWriter^ writer = gcnew StreamWriter("purchases.csv");
							for (int i = 0; i < localData->Length; i++) {
								if (localData[i] != nullptr) {
									String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
										localData[i]->id_purchase, localData[i]->user, localData[i]->productList,
										localData[i]->iva, localData[i]->subtotal, localData[i]->discount,
										localData[i]->total);
									writer->WriteLine(message);
								}
							}
							writer->Close();
							this->getPurchasesData();
							this->clearTxt();
							MessageBox::Show("El carrito se agregó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	}
	private: System::Void editData(System::Object^ sender, System::EventArgs^ e) {
		try {
			for each (Control ^ control in panel_productslist->Controls) {
				if (dynamic_cast<NumericUpDown^>(control) != nullptr) {
					NumericUpDown^ nud = dynamic_cast<NumericUpDown^>(control);
					nud->Value = 0;
				}
			}
			DataGridViewRow^ filaSeleccionada = this->dgv_compras->SelectedRows[0];
			this->txt_id->ReadOnly = true;
			this->txt_id->Text = Convert::ToString(filaSeleccionada->Cells[0]->Value);
			this->cmb_users->Text = Convert::ToString(filaSeleccionada->Cells[1]->Value);
			System::String^ dataProductsCli = Convert::ToString(filaSeleccionada->Cells[2]->Value);
			string dataProducts;
			for (int i = 0; i < dataProductsCli->Length; i++) {
				dataProducts += (char)dataProductsCli[i];
			}
			this->txt_discount->Text = Convert::ToString(filaSeleccionada->Cells[5]->Value);
			this->editableData = true;
			this->btn_cancel->Visible = true;

			string item;
			stringstream ss(dataProducts);
			while (std::getline(ss, item, '|')) {
				if (!item.empty()) {
					size_t pos = item.find('*');
					if (pos != std::string::npos) {
						std::string productName = item.substr(0, pos);
						int quantity = std::stoi(item.substr(pos + 1));

						for (int i = 0; i < productsData->Length; i++) {
							if (productsData[i] != nullptr && productsData[i]->name == gcnew String(productName.c_str())) {
								String^ nudName = "nud_" + productsData[i]->id_product.ToString();
								NumericUpDown^ nud = dynamic_cast<NumericUpDown^>(panel_productslist->Controls[nudName]);
								if (nud != nullptr) {
									nud->Value = quantity;
								}
								break;
							}
						}
					}
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al obtener un producto : " + ex->Message, "Error", MessageBoxButtons::OK);
		}
	}
	private: System::Void cancelButton(System::Object^ sender, System::EventArgs^ e) {
		this->clearTxt();
		this->btn_cancel->Visible = false;
		this->txt_id->ReadOnly = false;
		this->editableData = false;
	}

	private: System::Void deleteRowPurchase(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			DataGridViewRow^ filaSeleccionada = this->dgv_compras->SelectedRows[0];
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Estás seguro de querer eliminar estos datos?", "Eliminar Usuario", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::OK) {
				cli::array<PurchaseProduct^>^ nuevoLocalData = gcnew cli::array<PurchaseProduct^>(localData->Length);
				for (int i = 0; i < localData->Length; i++) {
					if (localData[i] != nullptr) {
						if (localData[i]->id_purchase.ToString() != filaSeleccionada->Cells[0]->Value->ToString()) {
							nuevoLocalData[i] = localData[i];
						}
					}
				}
				localData = nuevoLocalData;
				StreamWriter^ writer = gcnew StreamWriter("purchases.csv");
				for (int i = 0; i < localData->Length; i++) {

					if (localData[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
							localData[i]->id_purchase, localData[i]->user, localData[i]->productList,
							localData[i]->iva, localData[i]->subtotal, localData[i]->discount,
							localData[i]->total);
						writer->WriteLine(message);
					}
				}
				writer->Close();
				this->getPurchasesData();
				this->clearTxt();
				MessageBox::Show("Registro eliminado correctamente", "Completado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
	}
};
}
