#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Product.h"
#include "Catalogo.h"
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
	/// Resumen de Productos
	/// </summary>
	public ref class Productos : public System::Windows::Forms::Form
	{
	private: cli::array<Inventario^>^ localDataIventary = gcnew cli::array<Inventario^>(100);
	private: cli::array<Catalogo^>^ localDataCatalogo = gcnew cli::array<Catalogo^>(100);
	private: cli::array<Product^>^ localData = gcnew cli::array<Product^>(100);
	private: System::Windows::Forms::ComboBox^ cmb_inventary;
	private: System::Windows::Forms::Button^ btn_exportarCSV;
	private: System::Windows::Forms::Button^ btn_uploadCSV;


	private: bool editableData;
	
	public:
		Productos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->getDataProducts();
			this->setComboInventary();
			this->validateStock();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Productos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titlePage;
	private: System::Windows::Forms::Panel^ panel_table;








	private: System::Windows::Forms::Panel^ formContainer;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ txt_stock;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ txt_price;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txt_description;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txt_brand;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txt_category;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txt_name;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ inputContainer;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txt_id;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_saveProduct;
	private: System::Windows::Forms::DataGridView^ dataGrid_Products;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ category;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ brand;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ description;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ stock;
	private: System::Windows::Forms::Button^ btn_cancel;



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
		void setComboInventary() {
			this->cmb_inventary->Items->Clear();
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
						this->cmb_inventary->Items->Add(localDataIventary[limit]->name);
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
		void getDataProducts() {
			this->dataGrid_Products->Rows->Clear();
			ifstream products("product.csv");
			localDataCatalogo = gcnew cli::array<Catalogo^>(100);
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


						localDataCatalogo[limit] = newProduct;
						this->dataGrid_Products->Rows->Add(localDataCatalogo[limit]->id_product, localDataCatalogo[limit]->name, localDataCatalogo[limit]->catego, localDataCatalogo[limit]->brand, localDataCatalogo[limit]->descrip, localDataCatalogo[limit]->price, localDataCatalogo[limit]->stock);
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
				this->dataGrid_Products->Rows->Clear();
				for (int i = 0; i < localDataIventary->Length; i++) {
					if (localDataIventary[i] != nullptr) {
						for (int j = 0; j < localDataCatalogo->Length; j++) {
							if (localDataCatalogo[j] != nullptr) {
								if (localDataIventary[i]->id_product == localDataCatalogo[j]->id_product) {
									localDataCatalogo[j]->stock = localDataIventary[i]->stock;	
								}
							}
						}
					}
				}
				StreamWriter^ writer = gcnew StreamWriter("product.csv");
				for (int i = 0; i < localDataCatalogo->Length; i++) {

					if (localDataCatalogo[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
							localDataCatalogo[i]->id_product, localDataCatalogo[i]->name, localDataCatalogo[i]->catego,
							localDataCatalogo[i]->brand, localDataCatalogo[i]->descrip, localDataCatalogo[i]->price,
							localDataCatalogo[i]->stock);
						writer->WriteLine(message);
					}
				}
				writer->Close();
				for (int limit = 0; limit < localDataCatalogo->Length; limit++) {
					if (localDataCatalogo[limit] != nullptr) {
						this->dataGrid_Products->Rows->Add(localDataCatalogo[limit]->id_product, localDataCatalogo[limit]->name, localDataCatalogo[limit]->catego, localDataCatalogo[limit]->brand, localDataCatalogo[limit]->descrip, localDataCatalogo[limit]->price, localDataCatalogo[limit]->stock);
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
		void InitializeComponent(void)
		{
			this->titlePage = (gcnew System::Windows::Forms::Label());
			this->panel_table = (gcnew System::Windows::Forms::Panel());
			this->dataGrid_Products = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->brand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->formContainer = (gcnew System::Windows::Forms::Panel());
			this->btn_exportarCSV = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->btn_saveProduct = (gcnew System::Windows::Forms::Button());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txt_stock = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txt_price = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_description = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txt_brand = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txt_category = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->inputContainer = (gcnew System::Windows::Forms::Panel());
			this->cmb_inventary = (gcnew System::Windows::Forms::ComboBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_uploadCSV = (gcnew System::Windows::Forms::Button());
			this->panel_table->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_Products))->BeginInit();
			this->formContainer->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->inputContainer->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// titlePage
			// 
			this->titlePage->AutoSize = true;
			this->titlePage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->titlePage->Location = System::Drawing::Point(9, 9);
			this->titlePage->Name = L"titlePage";
			this->titlePage->Size = System::Drawing::Size(290, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Catálago de Productos";
			// 
			// panel_table
			// 
			this->panel_table->Controls->Add(this->dataGrid_Products);
			this->panel_table->Location = System::Drawing::Point(285, 47);
			this->panel_table->Name = L"panel_table";
			this->panel_table->Size = System::Drawing::Size(389, 389);
			this->panel_table->TabIndex = 1;
			// 
			// dataGrid_Products
			// 
			this->dataGrid_Products->AllowUserToAddRows = false;
			this->dataGrid_Products->AllowUserToDeleteRows = false;
			this->dataGrid_Products->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_Products->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id,
					this->name, this->category, this->brand, this->description, this->price, this->stock
			});
			this->dataGrid_Products->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGrid_Products->Location = System::Drawing::Point(0, 0);
			this->dataGrid_Products->Name = L"dataGrid_Products";
			this->dataGrid_Products->ReadOnly = true;
			this->dataGrid_Products->RowHeadersVisible = false;
			this->dataGrid_Products->RowHeadersWidth = 102;
			this->dataGrid_Products->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGrid_Products->Size = System::Drawing::Size(389, 389);
			this->dataGrid_Products->TabIndex = 0;
			this->dataGrid_Products->DoubleClick += gcnew System::EventHandler(this, &Productos::EditarProducto);
			this->dataGrid_Products->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Productos::deleteRowProduct);
			// 
			// id
			// 
			this->id->HeaderText = L"Código";
			this->id->MinimumWidth = 12;
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 250;
			// 
			// name
			// 
			this->name->HeaderText = L"Nombre";
			this->name->MinimumWidth = 12;
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Width = 250;
			// 
			// category
			// 
			this->category->HeaderText = L"Categoría";
			this->category->MinimumWidth = 12;
			this->category->Name = L"category";
			this->category->ReadOnly = true;
			this->category->Width = 250;
			// 
			// brand
			// 
			this->brand->HeaderText = L"Marca";
			this->brand->MinimumWidth = 12;
			this->brand->Name = L"brand";
			this->brand->ReadOnly = true;
			this->brand->Width = 250;
			// 
			// description
			// 
			this->description->HeaderText = L"Descripción";
			this->description->MinimumWidth = 12;
			this->description->Name = L"description";
			this->description->ReadOnly = true;
			this->description->Width = 250;
			// 
			// price
			// 
			this->price->HeaderText = L"Precio";
			this->price->MinimumWidth = 12;
			this->price->Name = L"price";
			this->price->ReadOnly = true;
			this->price->Width = 250;
			// 
			// stock
			// 
			this->stock->HeaderText = L"Cantidad de Stock";
			this->stock->MinimumWidth = 12;
			this->stock->Name = L"stock";
			this->stock->ReadOnly = true;
			this->stock->Width = 250;
			// 
			// formContainer
			// 
			this->formContainer->Controls->Add(this->btn_exportarCSV);
			this->formContainer->Controls->Add(this->btn_cancel);
			this->formContainer->Controls->Add(this->btn_saveProduct);
			this->formContainer->Controls->Add(this->panel12);
			this->formContainer->Controls->Add(this->panel10);
			this->formContainer->Controls->Add(this->panel8);
			this->formContainer->Controls->Add(this->panel6);
			this->formContainer->Controls->Add(this->panel4);
			this->formContainer->Controls->Add(this->panel2);
			this->formContainer->Controls->Add(this->inputContainer);
			this->formContainer->Location = System::Drawing::Point(12, 47);
			this->formContainer->Name = L"formContainer";
			this->formContainer->Size = System::Drawing::Size(267, 389);
			this->formContainer->TabIndex = 2;
			// 
			// btn_exportarCSV
			// 
			this->btn_exportarCSV->BackColor = System::Drawing::Color::Teal;
			this->btn_exportarCSV->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_exportarCSV->FlatAppearance->BorderSize = 0;
			this->btn_exportarCSV->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_exportarCSV->ForeColor = System::Drawing::Color::White;
			this->btn_exportarCSV->Location = System::Drawing::Point(23, 363);
			this->btn_exportarCSV->Name = L"btn_exportarCSV";
			this->btn_exportarCSV->Size = System::Drawing::Size(75, 23);
			this->btn_exportarCSV->TabIndex = 6;
			this->btn_exportarCSV->Text = L"Descargar";
			this->btn_exportarCSV->UseVisualStyleBackColor = false;
			this->btn_exportarCSV->Click += gcnew System::EventHandler(this, &Productos::btn_exportarCSV_Click);
			// 
			// btn_cancel
			// 
			this->btn_cancel->BackColor = System::Drawing::Color::Transparent;
			this->btn_cancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancel->ForeColor = System::Drawing::Color::Teal;
			this->btn_cancel->Location = System::Drawing::Point(104, 363);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(75, 23);
			this->btn_cancel->TabIndex = 5;
			this->btn_cancel->Text = L"Cancelar";
			this->btn_cancel->UseVisualStyleBackColor = false;
			this->btn_cancel->Visible = false;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &Productos::btn_cancel_Click);
			// 
			// btn_saveProduct
			// 
			this->btn_saveProduct->BackColor = System::Drawing::Color::Teal;
			this->btn_saveProduct->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_saveProduct->FlatAppearance->BorderSize = 0;
			this->btn_saveProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_saveProduct->ForeColor = System::Drawing::Color::White;
			this->btn_saveProduct->Location = System::Drawing::Point(185, 363);
			this->btn_saveProduct->Name = L"btn_saveProduct";
			this->btn_saveProduct->Size = System::Drawing::Size(75, 23);
			this->btn_saveProduct->TabIndex = 4;
			this->btn_saveProduct->Text = L"Guardar";
			this->btn_saveProduct->UseVisualStyleBackColor = false;
			this->btn_saveProduct->Click += gcnew System::EventHandler(this, &Productos::SaveProduct);
			// 
			// panel12
			// 
			this->panel12->Controls->Add(this->panel13);
			this->panel12->Controls->Add(this->txt_stock);
			this->panel12->Controls->Add(this->label13);
			this->panel12->Location = System::Drawing::Point(3, 201);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(261, 30);
			this->panel12->TabIndex = 3;
			// 
			// panel13
			// 
			this->panel13->Controls->Add(this->textBox14);
			this->panel13->Controls->Add(this->label14);
			this->panel13->Location = System::Drawing::Point(0, 30);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(261, 30);
			this->panel13->TabIndex = 2;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(158, 4);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(100, 20);
			this->textBox14->TabIndex = 1;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(3, 7);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(40, 13);
			this->label14->TabIndex = 0;
			this->label14->Text = L"Código";
			// 
			// txt_stock
			// 
			this->txt_stock->Location = System::Drawing::Point(158, 4);
			this->txt_stock->Name = L"txt_stock";
			this->txt_stock->ReadOnly = true;
			this->txt_stock->Size = System::Drawing::Size(100, 20);
			this->txt_stock->TabIndex = 1;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(3, 7);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(80, 13);
			this->label13->TabIndex = 0;
			this->label13->Text = L"Cantidad Stock";
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->panel11);
			this->panel10->Controls->Add(this->txt_price);
			this->panel10->Controls->Add(this->label11);
			this->panel10->Location = System::Drawing::Point(3, 168);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(261, 30);
			this->panel10->TabIndex = 3;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->textBox12);
			this->panel11->Controls->Add(this->label12);
			this->panel11->Location = System::Drawing::Point(0, 30);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(261, 30);
			this->panel11->TabIndex = 2;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(158, 4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(100, 20);
			this->textBox12->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(3, 7);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(40, 13);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Código";
			// 
			// txt_price
			// 
			this->txt_price->Location = System::Drawing::Point(158, 4);
			this->txt_price->Name = L"txt_price";
			this->txt_price->Size = System::Drawing::Size(100, 20);
			this->txt_price->TabIndex = 1;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(3, 7);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(37, 13);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Precio";
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Controls->Add(this->txt_description);
			this->panel8->Controls->Add(this->label9);
			this->panel8->Location = System::Drawing::Point(3, 135);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(261, 30);
			this->panel8->TabIndex = 3;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->textBox10);
			this->panel9->Controls->Add(this->label10);
			this->panel9->Location = System::Drawing::Point(0, 30);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(261, 30);
			this->panel9->TabIndex = 2;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(158, 4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(100, 20);
			this->textBox10->TabIndex = 1;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 7);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(40, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Código";
			// 
			// txt_description
			// 
			this->txt_description->Location = System::Drawing::Point(158, 4);
			this->txt_description->Name = L"txt_description";
			this->txt_description->Size = System::Drawing::Size(100, 20);
			this->txt_description->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 7);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(63, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Descripción";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Controls->Add(this->txt_brand);
			this->panel6->Controls->Add(this->label7);
			this->panel6->Location = System::Drawing::Point(3, 102);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(261, 30);
			this->panel6->TabIndex = 3;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->textBox8);
			this->panel7->Controls->Add(this->label8);
			this->panel7->Location = System::Drawing::Point(0, 30);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(261, 30);
			this->panel7->TabIndex = 2;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(158, 4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(100, 20);
			this->textBox8->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 7);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(40, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Código";
			// 
			// txt_brand
			// 
			this->txt_brand->Location = System::Drawing::Point(158, 4);
			this->txt_brand->Name = L"txt_brand";
			this->txt_brand->Size = System::Drawing::Size(100, 20);
			this->txt_brand->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 7);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Marca";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->txt_category);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Location = System::Drawing::Point(3, 69);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(261, 30);
			this->panel4->TabIndex = 3;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->textBox6);
			this->panel5->Controls->Add(this->label6);
			this->panel5->Location = System::Drawing::Point(0, 30);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(261, 30);
			this->panel5->TabIndex = 2;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(158, 4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(100, 20);
			this->textBox6->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(40, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Código";
			// 
			// txt_category
			// 
			this->txt_category->Location = System::Drawing::Point(158, 4);
			this->txt_category->Name = L"txt_category";
			this->txt_category->Size = System::Drawing::Size(100, 20);
			this->txt_category->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(54, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Categoría";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->txt_name);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(3, 36);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(261, 30);
			this->panel2->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->textBox4);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(0, 30);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(261, 30);
			this->panel3->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(158, 4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(40, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Código";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(158, 4);
			this->txt_name->Name = L"txt_name";
			this->txt_name->ReadOnly = true;
			this->txt_name->Size = System::Drawing::Size(100, 20);
			this->txt_name->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Nombre";
			// 
			// inputContainer
			// 
			this->inputContainer->Controls->Add(this->cmb_inventary);
			this->inputContainer->Controls->Add(this->panel1);
			this->inputContainer->Controls->Add(this->txt_id);
			this->inputContainer->Controls->Add(this->label1);
			this->inputContainer->Location = System::Drawing::Point(3, 3);
			this->inputContainer->Name = L"inputContainer";
			this->inputContainer->Size = System::Drawing::Size(261, 30);
			this->inputContainer->TabIndex = 0;
			// 
			// cmb_inventary
			// 
			this->cmb_inventary->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb_inventary->FormattingEnabled = true;
			this->cmb_inventary->Location = System::Drawing::Point(158, 4);
			this->cmb_inventary->Margin = System::Windows::Forms::Padding(1);
			this->cmb_inventary->Name = L"cmb_inventary";
			this->cmb_inventary->Size = System::Drawing::Size(100, 21);
			this->cmb_inventary->TabIndex = 3;
			this->cmb_inventary->SelectedIndexChanged += gcnew System::EventHandler(this, &Productos::seleccionProducto);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(0, 30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(261, 30);
			this->panel1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(158, 4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(40, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Código";
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(60, 4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->ReadOnly = true;
			this->txt_id->Size = System::Drawing::Size(100, 20);
			this->txt_id->TabIndex = 1;
			this->txt_id->Visible = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(50, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Producto";
			// 
			// btn_uploadCSV
			// 
			this->btn_uploadCSV->BackColor = System::Drawing::Color::Teal;
			this->btn_uploadCSV->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_uploadCSV->FlatAppearance->BorderSize = 0;
			this->btn_uploadCSV->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_uploadCSV->ForeColor = System::Drawing::Color::White;
			this->btn_uploadCSV->Location = System::Drawing::Point(599, 17);
			this->btn_uploadCSV->Name = L"btn_uploadCSV";
			this->btn_uploadCSV->Size = System::Drawing::Size(75, 23);
			this->btn_uploadCSV->TabIndex = 7;
			this->btn_uploadCSV->Text = L"Cargar";
			this->btn_uploadCSV->UseVisualStyleBackColor = false;
			this->btn_uploadCSV->Click += gcnew System::EventHandler(this, &Productos::btn_uploadCSV_Click);
			// 
			// Productos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 461);
			this->Controls->Add(this->btn_uploadCSV);
			this->Controls->Add(this->formContainer);
			this->Controls->Add(this->panel_table);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Productos";
			this->Text = L"Productos";
			this->panel_table->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_Products))->EndInit();
			this->formContainer->ResumeLayout(false);
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->inputContainer->ResumeLayout(false);
			this->inputContainer->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: void clearInputs() {
		this->txt_id->Clear();
		this->txt_name->Clear();
		this->txt_brand->Clear();
		this->txt_category->Clear();
		this->txt_description->Clear();
		this->txt_price->Clear();
		this->txt_stock->Clear();
		this->cmb_inventary->SelectedIndex = -1;
	}

	private: bool CamposNoVacios(){
		return !(String::IsNullOrEmpty(this->txt_id->Text) ||
				String::IsNullOrEmpty(this->txt_name->Text) ||
				String::IsNullOrEmpty(this->txt_category->Text) ||
				String::IsNullOrEmpty(this->txt_brand->Text) ||
				String::IsNullOrEmpty(this->txt_description->Text) ||
				String::IsNullOrEmpty(this->txt_price->Text) ||
				String::IsNullOrEmpty(this->txt_stock->Text));
	}
	private: bool validateExistData() {
		String^ newId = gcnew String(this->txt_id->Text);
		String^ newName = gcnew String(this->txt_name->Text);
		String^ newPrice = gcnew String(this->txt_price->Text);
		String^ newStock = gcnew String(this->txt_stock->Text);


		for (int i = 0; i < localDataCatalogo->Length; i++) {
			if (localDataCatalogo[i] != nullptr) {
				if (!editableData && localDataCatalogo[i]->id_product.ToString() == newId) {
					MessageBox::Show("El ID del producto ya existe en registros anteriores", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				if (System::Convert::ToInt32(newStock) < 0) {
					MessageBox::Show("El stock no puede ser negativo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				if (localDataCatalogo[i]->name == newName && localDataCatalogo[i]->id_product.ToString() != newId) {
					MessageBox::Show("El producto ya existe", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				if (System::Convert::ToSingle(newPrice) < 0) {
					MessageBox::Show("El precio no puede ser negativo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
			}
		}
		return true;
	}
	private: System::Void SaveProduct(System::Object^ sender, System::EventArgs^ e) {
		if (this->editableData) {
			if (validateExistData()) {
				if (CamposNoVacios()) {
					DataGridViewRow^ filaSeleccionada = this->dataGrid_Products->SelectedRows[0];
					for (int i = 0; i < localDataCatalogo->Length; i++) {
						if (localDataCatalogo[i] != nullptr) {
							if (filaSeleccionada->Cells[0]->Value->ToString() == localDataCatalogo[i]->id_product.ToString()) {
								Catalogo^ newProduct = gcnew Catalogo();
								System::String^ strId = this->txt_id->Text;
								System::String^ strStock = this->txt_stock->Text;
								System::String^ strPrice = this->txt_price->Text;
								float price = System::Convert::ToSingle(strPrice);
								int id = System::Convert::ToInt32(strId);
								int stock = System::Convert::ToInt32(strStock);
								newProduct->id_product = id;
								newProduct->name = gcnew String(this->txt_name->Text);
								newProduct->catego = gcnew String(this->txt_category->Text);
								newProduct->brand = gcnew String(this->txt_brand->Text);
								newProduct->descrip = gcnew String(this->txt_description->Text);
								newProduct->price = price;
								newProduct->stock = stock;
								this->localDataCatalogo[i] = newProduct;
								StreamWriter^ writer = gcnew StreamWriter("product.csv");
								for (int i = 0; i < localDataCatalogo->Length; i++) {

									if (localDataCatalogo[i] != nullptr) {
										String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
											localDataCatalogo[i]->id_product, localDataCatalogo[i]->name, localDataCatalogo[i]->catego,
											localDataCatalogo[i]->brand, localDataCatalogo[i]->descrip, localDataCatalogo[i]->price,
											localDataCatalogo[i]->stock);
										writer->WriteLine(message);
									}
								}
								writer->Close();
								this->clearInputs();
								this->getDataProducts();
								this->txt_id->ReadOnly = false;
								this->editableData = false;
								this->btn_cancel->Visible = false;
								MessageBox::Show("El producto se actualizó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
								break;
							}
						}
					}
				}
			}
		}
		else {
			Catalogo^ newProduct = gcnew Catalogo();
			int indice = -1;
			for (int i = 0; i < localDataCatalogo->Length; i++) {
				if (localDataCatalogo[i] == nullptr) {
					indice = i;
					break;
				}
			}
			if (indice != -1) {
				if (CamposNoVacios()) {
					if (validateExistData()) {
						try {
							System::String^ strId = this->txt_id->Text;
							System::String^ strStock = this->txt_stock->Text;
							System::String^ strPrice = this->txt_price->Text;
							float price = System::Convert::ToSingle(strPrice);
							int id = System::Convert::ToInt32(strId);
							int stock = System::Convert::ToInt32(strStock);
							newProduct->id_product = id;
							newProduct->name = gcnew String(this->txt_name->Text);
							newProduct->catego = gcnew String(this->txt_category->Text);
							newProduct->brand = gcnew String(this->txt_brand->Text);
							newProduct->descrip = gcnew String(this->txt_description->Text);
							newProduct->price = price;
							newProduct->stock = stock;
							this->localDataCatalogo[indice] = newProduct;

							StreamWriter^ writer = gcnew StreamWriter("product.csv");
							for (int i = 0; i < localDataCatalogo->Length; i++) {

								if (localDataCatalogo[i] != nullptr) {
									String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
										localDataCatalogo[i]->id_product, localDataCatalogo[i]->name, localDataCatalogo[i]->catego,
										localDataCatalogo[i]->brand, localDataCatalogo[i]->descrip, localDataCatalogo[i]->price,
										localDataCatalogo[i]->stock);
									writer->WriteLine(message);
								}
							}

							writer->Close();
							this->clearInputs();
							this->getDataProducts();
							MessageBox::Show("El producto se agregó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
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
	private: System::Void EditarProducto(System::Object^ sender, System::EventArgs^ e) {
		try {
			DataGridViewRow^ filaSeleccionada = this->dataGrid_Products->SelectedRows[0];
			this->txt_id->ReadOnly = true;
			this->txt_id->Text = Convert::ToString(filaSeleccionada->Cells[0]->Value);
			this->cmb_inventary->Text = Convert::ToString(filaSeleccionada->Cells[1]->Value);
			this->txt_name->Text = Convert::ToString(filaSeleccionada->Cells[1]->Value);
			this->txt_brand->Text = Convert::ToString(filaSeleccionada->Cells[2]->Value);
			this->txt_category->Text = Convert::ToString(filaSeleccionada->Cells[3]->Value);
			this->txt_description->Text = Convert::ToString(filaSeleccionada->Cells[4]->Value);
			this->txt_price->Text = Convert::ToString(filaSeleccionada->Cells[5]->Value);
			this->txt_stock->Text = Convert::ToString(filaSeleccionada->Cells[6]->Value);
			this->editableData = true;
			this->btn_cancel->Visible = true;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al obtener un producto : " + ex->Message, "Error", MessageBoxButtons::OK);
		}
		
	}
	private: System::Void btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->clearInputs();
		this->txt_id->ReadOnly = false;
		this->editableData = false;
		this->btn_cancel->Visible = false;
	}

	private: System::Void deleteRowProduct(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			DataGridViewRow^ filaSeleccionada = this->dataGrid_Products->SelectedRows[0];
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Estás seguro de querer eliminar estos datos?", "Eliminar Usuario", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::OK) {
				cli::array<Catalogo^>^ nuevoLocalData = gcnew cli::array<Catalogo^>(localDataCatalogo->Length);
				for (int i = 0; i < localDataCatalogo->Length; i++) {
					if (localDataCatalogo[i] != nullptr) {
						if (localDataCatalogo[i]->id_product.ToString() != filaSeleccionada->Cells[0]->Value->ToString()) {
							nuevoLocalData[i] = localDataCatalogo[i];
						}
					}
				}
				localDataCatalogo = nuevoLocalData;
				StreamWriter^ writer = gcnew StreamWriter("product.csv");
				for (int i = 0; i < localDataCatalogo->Length; i++) {

					if (localDataCatalogo[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
							localDataCatalogo[i]->id_product, localDataCatalogo[i]->name, localDataCatalogo[i]->catego,
							localDataCatalogo[i]->brand, localDataCatalogo[i]->descrip, localDataCatalogo[i]->price,
							localDataCatalogo[i]->stock);
						writer->WriteLine(message);
					}
				}
				writer->Close();
				this->getDataProducts();
				this->clearInputs();
				MessageBox::Show("Registro eliminado correctamente", "Completado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
	}
	private: System::Void seleccionProducto(System::Object^ sender, System::EventArgs^ e) {
		for (int i = 0; i < localDataIventary->Length; i++) {
			if (localDataIventary[i] != nullptr) {
				if (localDataIventary[i]->name == this->cmb_inventary->Text) {
					this->txt_name->Text = localDataIventary[i]->name;
					this->txt_stock->Text = localDataIventary[i]->stock.ToString();
					this->txt_id->Text = localDataIventary[i]->id_product.ToString();
				}
			}
		}
	}
		   std::string getCurrentDateTime() {
			   std::time_t now = std::time(nullptr);
			   std::tm* localTime = std::localtime(&now);

			   std::ostringstream dateTimeStream;
			   dateTimeStream << std::put_time(localTime, "%d/%m/%Y %H:%M");

			   return dateTimeStream.str();
		   }
		   std::string getCurrentDate() {
			   std::time_t now = std::time(nullptr);
			   std::tm* localTime = std::localtime(&now);

			   std::ostringstream dateTimeStream;
			   dateTimeStream << std::put_time(localTime, "%d-%m-%Y-%H-%M");

			   return dateTimeStream.str();
		   }
private: System::Void btn_exportarCSV_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		std::string dateTime = getCurrentDateTime();
		std::string dateNow = getCurrentDate();
		String^ dateTimeString = gcnew String(dateTime.c_str());
		String^ dateString = gcnew String(dateNow.c_str());
		SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
		saveFileDialog->Filter = "CSV Files (*.csv)|*.csv";
		saveFileDialog->Title = "Guardar reporte como CSV";
		saveFileDialog->FileName = "ReporteCatalogo" + dateString;
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = saveFileDialog->FileName;

			StreamWriter^ sw = gcnew StreamWriter(filePath);
			for (int i = 0; i < this->dataGrid_Products->Columns->Count; i++) {
				sw->Write(this->dataGrid_Products->Columns[i]->HeaderText);
				if (i < this->dataGrid_Products->Columns->Count - 1) {
					sw->Write(";");
				}
			}
			sw->WriteLine();

			for (int i = 0; i < this->dataGrid_Products->Rows->Count; i++) {
				for (int j = 0; j < this->dataGrid_Products->Columns->Count; j++) {
					sw->Write(this->dataGrid_Products->Rows[i]->Cells[j]->Value->ToString());
					if (j < this->dataGrid_Products->Columns->Count - 1) {
						sw->Write(";");
					}
				}
				sw->WriteLine();
			}

			sw->Close();
			MessageBox::Show("Exportación a CSV completada con éxito", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
	private: System::Void btn_uploadCSV_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
		openFileDialog->Filter = "CSV files (*.csv)|*.csv|All files (*.*)|*.*";
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = openFileDialog->FileName;
			ReadCSV(filePath);
		}
	}

	private: System::Void ReadCSV(String^ filePath) {
		try {
			StreamReader^ sr = gcnew StreamReader(filePath);
			String^ line;
			bool isFirstLine = true;
			cli::array<String^>^ headers = nullptr;

			int maxRows = 100;
			cli::array<cli::array<String^>^>^ csvData = gcnew cli::array<cli::array<String^>^>(maxRows);
			int rowIndex = 0;

			while ((line = sr->ReadLine()) != nullptr) {
				cli::array<String^>^ fields = line->Split(',');
				if (isFirstLine) {
					headers = fields;
					isFirstLine = false;
				}
				else {
					csvData[rowIndex] = fields;
					rowIndex++;
					if (rowIndex >= maxRows) break;
				}
			}
			sr->Close();

			DisplayData(csvData, headers, rowIndex);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al leer el archivo CSV: " + ex->Message);
		}
	}

	private: System::Void DisplayData(cli::array<cli::array<String^>^>^ csvData, cli::array<String^>^ headers, int numRows) {
		try {
			cli::array<Catalogo^>^ newImport = gcnew cli::array<Catalogo^>(100);
			String^ id_new = gcnew String(this->txt_id->Text);
			string message;
			for (int i = 0; i < numRows; i++) {
				message.clear();
				Catalogo^ newUser = gcnew Catalogo();
				cli::array<String^>^ row = csvData[i];
				for each (String ^ field in row) {
					for (int i = 0; i < field->Length; i++) {
						message.push_back(static_cast<char>(field[i]));
					}
				}

				stringstream ss(message);
				string id;
				string name;
				string catego;
				string brand;
				string descrip;
				string price;
				string stock;

				getline(ss, id, ';');
				getline(ss, name, ';');
				getline(ss, catego, ';');
				getline(ss, brand, ';');
				getline(ss, descrip, ';');
				getline(ss, price, ';');
				getline(ss, stock, ';');
				newUser->id_product = std::stoi(id);
				newUser->name = gcnew String(name.c_str());
				newUser->catego = gcnew String(catego.c_str());
				newUser->brand = gcnew String(brand.c_str());
				newUser->descrip = gcnew String(descrip.c_str());
				newUser->price = std::stof(price);
				newUser->stock = std::stoi(stock);

				newImport[i] = newUser;

			}
			cli::array<Catalogo^>^ tempArray = gcnew cli::array<Catalogo^>(localDataCatalogo->Length);
			Array::Copy(localDataCatalogo, tempArray, localDataCatalogo->Length);
			Array::Resize(localDataCatalogo, localDataCatalogo->Length + newImport->Length);
			Array::Copy(tempArray, localDataCatalogo, tempArray->Length);
			Array::Copy(newImport, 0, localDataCatalogo, tempArray->Length, newImport->Length);


			StreamWriter^ writer = gcnew StreamWriter("product.csv");
			for (int i = 0; i < localDataCatalogo->Length; i++) {

				if (localDataCatalogo[i] != nullptr) {
					String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
						localDataCatalogo[i]->id_product, localDataCatalogo[i]->name, localDataCatalogo[i]->catego,
						localDataCatalogo[i]->brand, localDataCatalogo[i]->descrip, localDataCatalogo[i]->price,
						localDataCatalogo[i]->stock);
					writer->WriteLine(message);
				}
			}

			writer->Close();
			this->clearInputs();
			this->getDataProducts();
		}
		catch (const std::exception& e) {
			std::cerr << "Excepción capturada: " << e.what() << std::endl;
		}
		catch (...) {
			std::cerr << "Excepción desconocida capturada" << std::endl;
		}
	}
};
}
