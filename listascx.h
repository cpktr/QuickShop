#pragma once
#include <fstream>
#include <string>
#include <sstream>
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
	/// Resumen de listascx
	/// </summary>
	public ref class listascx : public System::Windows::Forms::Form
	{
	private: cli::array<Product^>^ localData = gcnew cli::array<Product^>(100);
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ description;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ price;

	private: System::Windows::Forms::Button^ btn_saveProduct;
	private: System::Windows::Forms::Button^ button1;
	private: bool editableData;
	
	public:
		listascx(void)
		{
			InitializeComponent();
			this->getDataProducts();
			this->createComponent();
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~listascx()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panelproducto;
	protected:















































	private: System::Windows::Forms::DataGridView^ dataGrid_Products;




	private: System::Windows::Forms::FlowLayoutPanel^ panelitoproducto;








	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void getDataProducts() {
			this->dataGrid_Products->Rows->Clear();
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


						localData[limit] = newUser;
						
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
		void createComponent() {
			for (int i = 0; i < localData->Length; ++i) {
				if (localData[i] != nullptr) { 
					Panel^ productPanel = gcnew Panel();
					productPanel->AutoSize = true;
					productPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
					productPanel->Dock = DockStyle::Top;
					productPanel->Margin = System::Windows::Forms::Padding(0, 0, 0, 10);
					Label^ nameLabel = gcnew Label();
					nameLabel->Text = "Nombre: " + localData[i]->name;
					nameLabel->AutoSize = true;
					nameLabel->Location = System::Drawing::Point(10, 10);
					Label^ priceLabel = gcnew Label();
					priceLabel->Text = "Precio: $" + localData[i]->price.ToString("F2");
					priceLabel->AutoSize = true;
					priceLabel->Location = System::Drawing::Point(10, 30);

					// Crear el NumericUpDown
					NumericUpDown^ numericUpDown = gcnew NumericUpDown();
					numericUpDown->Minimum = 0;
					numericUpDown->Maximum = 1000;
					numericUpDown->Location = System::Drawing::Point(10, 50);

					// Agregar los controles al Panel
					productPanel->Controls->Add(nameLabel);
					productPanel->Controls->Add(priceLabel);
					productPanel->Controls->Add(numericUpDown);

					// Agregar el Panel al FlowLayoutPanel
					panelitoproducto->Controls->Add(productPanel);
				}

				
			}
		}
		void InitializeComponent(void)
		{
			this->panelproducto = (gcnew System::Windows::Forms::Panel());
			this->panelitoproducto = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->dataGrid_Products = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btn_saveProduct = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panelproducto->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_Products))->BeginInit();
			this->SuspendLayout();
			// 
			// panelproducto
			// 
			this->panelproducto->Controls->Add(this->button1);
			this->panelproducto->Controls->Add(this->btn_saveProduct);
			this->panelproducto->Controls->Add(this->panelitoproducto);
			this->panelproducto->Controls->Add(this->dataGrid_Products);
			this->panelproducto->Location = System::Drawing::Point(12, 24);
			this->panelproducto->Name = L"panelproducto";
			this->panelproducto->Size = System::Drawing::Size(827, 448);
			this->panelproducto->TabIndex = 0;
			// 
			// panelitoproducto
			// 
			this->panelitoproducto->Location = System::Drawing::Point(4, 49);
			this->panelitoproducto->Name = L"panelitoproducto";
			this->panelitoproducto->Size = System::Drawing::Size(356, 382);
			this->panelitoproducto->TabIndex = 6;
			// 
			// dataGrid_Products
			// 
			this->dataGrid_Products->AllowUserToAddRows = false;
			this->dataGrid_Products->AllowUserToDeleteRows = false;
			this->dataGrid_Products->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_Products->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->name,
					this->description, this->price
			});
			this->dataGrid_Products->Location = System::Drawing::Point(364, 49);
			this->dataGrid_Products->Margin = System::Windows::Forms::Padding(4);
			this->dataGrid_Products->Name = L"dataGrid_Products";
			this->dataGrid_Products->ReadOnly = true;
			this->dataGrid_Products->RowHeadersVisible = false;
			this->dataGrid_Products->RowHeadersWidth = 51;
			this->dataGrid_Products->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGrid_Products->Size = System::Drawing::Size(459, 342);
			this->dataGrid_Products->TabIndex = 5;
			// 
			// name
			// 
			this->name->HeaderText = L"Nombre";
			this->name->MinimumWidth = 6;
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Width = 125;
			// 
			// description
			// 
			this->description->HeaderText = L"Precio";
			this->description->MinimumWidth = 6;
			this->description->Name = L"description";
			this->description->ReadOnly = true;
			this->description->Width = 125;
			// 
			// price
			// 
			this->price->HeaderText = L"Cantidad";
			this->price->MinimumWidth = 6;
			this->price->Name = L"price";
			this->price->ReadOnly = true;
			this->price->Width = 125;
			// 
			// btn_saveProduct
			// 
			this->btn_saveProduct->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btn_saveProduct->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_saveProduct->FlatAppearance->BorderSize = 0;
			this->btn_saveProduct->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btn_saveProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_saveProduct->ForeColor = System::Drawing::Color::White;
			this->btn_saveProduct->Location = System::Drawing::Point(487, 403);
			this->btn_saveProduct->Margin = System::Windows::Forms::Padding(4);
			this->btn_saveProduct->Name = L"btn_saveProduct";
			this->btn_saveProduct->Size = System::Drawing::Size(100, 28);
			this->btn_saveProduct->TabIndex = 7;
			this->btn_saveProduct->Text = L"Agregar";
			this->btn_saveProduct->UseVisualStyleBackColor = false;
			this->btn_saveProduct->Click += gcnew System::EventHandler(this, &listascx::btn_saveProduct_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(379, 403);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// listascx
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 493);
			this->ControlBox = false;
			this->Controls->Add(this->panelproducto);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"listascx";
			this->ShowIcon = false;
			this->Text = L"listascx";
			this->panelproducto->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_Products))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_saveProduct_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btn_cancel_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
