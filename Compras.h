#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "Clients.h"
#include "Product.h"

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
	private: System::Windows::Forms::ComboBox^ cmb_products;
	private: cli::array<Product^>^ productsData = gcnew cli::array<Product^>(100);
	private: float totalCost = 0;
	public:
		Compras(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->getClientsData();
			this->getDataProducts();
			if (this->clientsData->Length > 0) {
				for (int i = 0; i < clientsData->Length; i++) {
					if (clientsData[i] != nullptr) {
						this->cmb_users->Items->Add(clientsData[i]->email);
					}
				}
			}
			if (this->productsData->Length > 0) {
				for (int i = 0; i < productsData->Length; i++) {
					if (productsData[i] != nullptr) {
						this->cmb_products->Items->Add(productsData[i]->name + " Q." + productsData[i]->price);
					}
				}
			}


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

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ user;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ products;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ iva;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ subtotal;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ discount;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txt_id;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel8;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel7;


	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ txt_iva;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ txt_subtotal;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ txt_descount;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btn_cancel;

	private: System::Windows::Forms::Button^ btn_savePurchase;
	private: System::Windows::Forms::ComboBox^ cmb_users;


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
						Product^ newProduct = gcnew Product();
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
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dgv_compras = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->user = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->products = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->iva = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->subtotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->discount = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->btn_savePurchase = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->cmb_users = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->cmb_products = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->txt_iva = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txt_subtotal = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txt_descount = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compras))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
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
			this->dgv_compras->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id, this->user,
					this->products, this->iva, this->subtotal, this->discount
			});
			this->dgv_compras->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv_compras->Location = System::Drawing::Point(0, 0);
			this->dgv_compras->Name = L"dgv_compras";
			this->dgv_compras->ReadOnly = true;
			this->dgv_compras->RowHeadersVisible = false;
			this->dgv_compras->Size = System::Drawing::Size(389, 389);
			this->dgv_compras->TabIndex = 0;
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
			// panel2
			// 
			this->panel2->Controls->Add(this->btn_cancel);
			this->panel2->Controls->Add(this->btn_savePurchase);
			this->panel2->Controls->Add(this->panel8);
			this->panel2->Controls->Add(this->panel7);
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Location = System::Drawing::Point(12, 47);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(267, 389);
			this->panel2->TabIndex = 2;
			// 
			// btn_cancel
			// 
			this->btn_cancel->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			this->btn_cancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancel->ForeColor = System::Drawing::Color::Teal;
			this->btn_cancel->Location = System::Drawing::Point(104, 363);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(75, 23);
			this->btn_cancel->TabIndex = 4;
			this->btn_cancel->Text = L"Cancelar";
			this->btn_cancel->UseVisualStyleBackColor = true;
			// 
			// btn_savePurchase
			// 
			this->btn_savePurchase->BackColor = System::Drawing::Color::Teal;
			this->btn_savePurchase->FlatAppearance->BorderSize = 0;
			this->btn_savePurchase->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_savePurchase->ForeColor = System::Drawing::Color::White;
			this->btn_savePurchase->Location = System::Drawing::Point(185, 363);
			this->btn_savePurchase->Name = L"btn_savePurchase";
			this->btn_savePurchase->Size = System::Drawing::Size(75, 23);
			this->btn_savePurchase->TabIndex = 3;
			this->btn_savePurchase->Text = L"Guardar";
			this->btn_savePurchase->UseVisualStyleBackColor = false;
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
			// panel7
			// 
			this->panel7->Controls->Add(this->cmb_products);
			this->panel7->Controls->Add(this->label6);
			this->panel7->Location = System::Drawing::Point(3, 75);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(261, 30);
			this->panel7->TabIndex = 2;
			// 
			// cmb_products
			// 
			this->cmb_products->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmb_products->FormattingEnabled = true;
			this->cmb_products->Location = System::Drawing::Point(158, 4);
			this->cmb_products->Name = L"cmb_products";
			this->cmb_products->Size = System::Drawing::Size(100, 21);
			this->cmb_products->TabIndex = 1;
			this->cmb_products->SelectedIndexChanged += gcnew System::EventHandler(this, &Compras::changeSelection);
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
			// panel6
			// 
			this->panel6->Controls->Add(this->txt_iva);
			this->panel6->Controls->Add(this->label5);
			this->panel6->Location = System::Drawing::Point(3, 111);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(261, 30);
			this->panel6->TabIndex = 2;
			// 
			// txt_iva
			// 
			this->txt_iva->Location = System::Drawing::Point(158, 4);
			this->txt_iva->Name = L"txt_iva";
			this->txt_iva->ReadOnly = true;
			this->txt_iva->Size = System::Drawing::Size(100, 20);
			this->txt_iva->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(24, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"IVA";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->txt_subtotal);
			this->panel5->Controls->Add(this->label4);
			this->panel5->Location = System::Drawing::Point(3, 146);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(261, 30);
			this->panel5->TabIndex = 2;
			// 
			// txt_subtotal
			// 
			this->txt_subtotal->Location = System::Drawing::Point(158, 4);
			this->txt_subtotal->Name = L"txt_subtotal";
			this->txt_subtotal->Size = System::Drawing::Size(100, 20);
			this->txt_subtotal->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Subtotal";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->txt_descount);
			this->panel4->Controls->Add(this->label3);
			this->panel4->Location = System::Drawing::Point(3, 182);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(261, 30);
			this->panel4->TabIndex = 2;
			// 
			// txt_descount
			// 
			this->txt_descount->Location = System::Drawing::Point(158, 4);
			this->txt_descount->Name = L"txt_descount";
			this->txt_descount->Size = System::Drawing::Size(100, 20);
			this->txt_descount->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(59, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Descuento";
			this->label3->Click += gcnew System::EventHandler(this, &Compras::label3_Click);
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
			// Compras
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Compras";
			this->Text = L"Compras";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_compras))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void changeSelection(System::Object^ sender, System::EventArgs^ e) {
		
	}
};
}
