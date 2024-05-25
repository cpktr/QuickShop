#pragma once
#include <fstream>
#include <string>
#include <sstream>
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
	/// Resumen de Inventary
	/// </summary>
	public ref class Inventary : public System::Windows::Forms::Form
	{
	private: int warningProducts = 0;
	private: cli::array<Inventario^>^ localData = gcnew cli::array<Inventario^>(100);
	private: cli::array<Catalogo^>^ localDataCatalogo = gcnew cli::array<Catalogo^>(100);
	private: System::Windows::Forms::Panel^ panel_warning;

	private: System::Windows::Forms::Label^ txt_warningStock;

	private: bool editableData = false;
	public:
		Inventary(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->getDataProducts();
			this->getDataCatalog();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Inventary()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titlePage;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::DataGridView^ dgv_inventary;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ stock;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txt_id;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ txt_name;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel4;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ txt_stock;

	private: System::Windows::Forms::Button^ btn_SaveIventary;
	private: System::Windows::Forms::Button^ btn_cancelar;





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
			this->dgv_inventary->Rows->Clear();
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


						localData[limit] = newUser;
						this->dgv_inventary->Rows->Add(localData[limit]->id_product, localData[limit]->name, localData[limit]->stock);
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

			for (int i = 0; i < localData->Length; i++) {
				if (localData[0] == nullptr) {
					this->txt_id->Text = "1";
				}
				else {
					if (localData[i] == nullptr) {
						this->txt_id->Text = (localData[i - 1]->id_product + 1).ToString();
						break;
					}
				}
			}

			for (int i = 0; i < localData->Length; i++) {
				if (localData[i] != nullptr) {
					if (localData[i]->stock < 5) {
						this->warningProducts++;
					}
				}
			}
			if (warningProducts > 0) {
				this->panel_warning->Visible = true;
				if (warningProducts == 1) {
					this->txt_warningStock->Text = "Advertencia: Hay " + warningProducts.ToString() + " producto por agotarse";
				}
				else {
					this->txt_warningStock->Text = "Advertencia: Hay " + warningProducts.ToString() + " productos por agotarse";
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


						localDataCatalogo[limit] = newProduct;
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
			this->titlePage = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->btn_SaveIventary = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txt_stock = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dgv_inventary = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_warning = (gcnew System::Windows::Forms::Panel());
			this->txt_warningStock = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txt_stock))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_inventary))->BeginInit();
			this->panel_warning->SuspendLayout();
			this->SuspendLayout();
			// 
			// titlePage
			// 
			this->titlePage->AutoSize = true;
			this->titlePage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->titlePage->Location = System::Drawing::Point(9, 9);
			this->titlePage->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->titlePage->Name = L"titlePage";
			this->titlePage->Size = System::Drawing::Size(134, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Inventario";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btn_cancelar);
			this->panel1->Controls->Add(this->btn_SaveIventary);
			this->panel1->Controls->Add(this->panel5);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Location = System::Drawing::Point(12, 47);
			this->panel1->Margin = System::Windows::Forms::Padding(1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(267, 389);
			this->panel1->TabIndex = 1;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::Transparent;
			this->btn_cancelar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->ForeColor = System::Drawing::Color::Teal;
			this->btn_cancelar->Location = System::Drawing::Point(104, 363);
			this->btn_cancelar->Margin = System::Windows::Forms::Padding(1);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(75, 23);
			this->btn_cancelar->TabIndex = 4;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			this->btn_cancelar->Visible = false;
			this->btn_cancelar->Click += gcnew System::EventHandler(this, &Inventary::btn_cancelar_Click);
			// 
			// btn_SaveIventary
			// 
			this->btn_SaveIventary->BackColor = System::Drawing::Color::Teal;
			this->btn_SaveIventary->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_SaveIventary->FlatAppearance->BorderSize = 0;
			this->btn_SaveIventary->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_SaveIventary->ForeColor = System::Drawing::Color::White;
			this->btn_SaveIventary->Location = System::Drawing::Point(185, 363);
			this->btn_SaveIventary->Margin = System::Windows::Forms::Padding(1);
			this->btn_SaveIventary->Name = L"btn_SaveIventary";
			this->btn_SaveIventary->Size = System::Drawing::Size(75, 23);
			this->btn_SaveIventary->TabIndex = 3;
			this->btn_SaveIventary->Text = L"Guardar";
			this->btn_SaveIventary->UseVisualStyleBackColor = false;
			this->btn_SaveIventary->Click += gcnew System::EventHandler(this, &Inventary::btn_SaveIventary_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->txt_name);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Location = System::Drawing::Point(3, 36);
			this->panel5->Margin = System::Windows::Forms::Padding(1);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(261, 30);
			this->panel5->TabIndex = 2;
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(158, 4);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(100, 20);
			this->txt_name->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 7);
			this->label3->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Nombre";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->txt_stock);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Location = System::Drawing::Point(3, 68);
			this->panel4->Margin = System::Windows::Forms::Padding(1);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(261, 30);
			this->panel4->TabIndex = 2;
			// 
			// txt_stock
			// 
			this->txt_stock->Location = System::Drawing::Point(158, 4);
			this->txt_stock->Margin = System::Windows::Forms::Padding(1);
			this->txt_stock->Name = L"txt_stock";
			this->txt_stock->Size = System::Drawing::Size(98, 20);
			this->txt_stock->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 7);
			this->label2->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Cantidad de Stock";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->txt_id);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Margin = System::Windows::Forms::Padding(1);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(261, 30);
			this->panel3->TabIndex = 0;
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(158, 4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->ReadOnly = true;
			this->txt_id->Size = System::Drawing::Size(100, 20);
			this->txt_id->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 7);
			this->label1->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dgv_inventary);
			this->panel2->Location = System::Drawing::Point(285, 47);
			this->panel2->Margin = System::Windows::Forms::Padding(1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(389, 389);
			this->panel2->TabIndex = 2;
			// 
			// dgv_inventary
			// 
			this->dgv_inventary->AllowUserToAddRows = false;
			this->dgv_inventary->AllowUserToDeleteRows = false;
			this->dgv_inventary->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_inventary->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->id, this->name,
					this->stock
			});
			this->dgv_inventary->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv_inventary->Location = System::Drawing::Point(0, 0);
			this->dgv_inventary->Margin = System::Windows::Forms::Padding(1);
			this->dgv_inventary->Name = L"dgv_inventary";
			this->dgv_inventary->ReadOnly = true;
			this->dgv_inventary->RowHeadersVisible = false;
			this->dgv_inventary->RowHeadersWidth = 102;
			this->dgv_inventary->RowTemplate->Height = 40;
			this->dgv_inventary->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_inventary->Size = System::Drawing::Size(389, 389);
			this->dgv_inventary->TabIndex = 0;
			this->dgv_inventary->DoubleClick += gcnew System::EventHandler(this, &Inventary::editProduct);
			this->dgv_inventary->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Inventary::deleteRowProduct);
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
			// stock
			// 
			this->stock->HeaderText = L"Cantidad de Stock";
			this->stock->MinimumWidth = 12;
			this->stock->Name = L"stock";
			this->stock->ReadOnly = true;
			this->stock->Width = 250;
			// 
			// panel_warning
			// 
			this->panel_warning->BackColor = System::Drawing::Color::PapayaWhip;
			this->panel_warning->Controls->Add(this->txt_warningStock);
			this->panel_warning->Location = System::Drawing::Point(285, 13);
			this->panel_warning->Name = L"panel_warning";
			this->panel_warning->Size = System::Drawing::Size(389, 30);
			this->panel_warning->TabIndex = 3;
			this->panel_warning->Visible = false;
			// 
			// txt_warningStock
			// 
			this->txt_warningStock->AutoSize = true;
			this->txt_warningStock->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->txt_warningStock->ForeColor = System::Drawing::Color::SaddleBrown;
			this->txt_warningStock->Location = System::Drawing::Point(3, 9);
			this->txt_warningStock->Name = L"txt_warningStock";
			this->txt_warningStock->Size = System::Drawing::Size(70, 13);
			this->txt_warningStock->TabIndex = 0;
			this->txt_warningStock->Text = L"Advertencia: ";
			// 
			// Inventary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(694, 461);
			this->Controls->Add(this->panel_warning);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(1);
			this->Name = L"Inventary";
			this->Text = L"Inventary";
			this->panel1->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txt_stock))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_inventary))->EndInit();
			this->panel_warning->ResumeLayout(false);
			this->panel_warning->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: bool CamposNoVacios() {
			return !(String::IsNullOrEmpty(this->txt_id->Text) ||
				String::IsNullOrEmpty(this->txt_name->Text) ||
				String::IsNullOrEmpty(this->txt_stock->Text));
		}
	private: bool validateExistData() {
		String^ newId = gcnew String(this->txt_id->Text);
		String^ newName = gcnew String(this->txt_name->Text);
		String^ newStock = gcnew String(this->txt_stock->Text);


		for (int i = 0; i < localData->Length; i++) {
			if (localData[i] != nullptr) {
				if (!editableData && localData[i]->id_product.ToString() == newId) {
					MessageBox::Show("El ID del producto ya existe en registros anteriores", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				if (System::Convert::ToInt32(newStock) < 0) {
					MessageBox::Show("El stock no puede ser negativo", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
				if (localData[i]->name == newName && localData[i]->id_product.ToString() != newId) {
					MessageBox::Show("El producto ya existe", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false;
				}
			}
		}
		return true;
	}
	private: void clearInputs() {
		this->txt_id->Clear();
		this->txt_name->Clear();
		this->txt_stock->Text = "0";
	}
	private: System::Void btn_SaveIventary_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->editableData) {
			if (validateExistData()) {
				if (CamposNoVacios()) {
					DataGridViewRow^ filaSeleccionada = this->dgv_inventary->SelectedRows[0];
					for (int i = 0; i < localData->Length; i++) {
						if (localData[i] != nullptr) {
							if (filaSeleccionada->Cells[0]->Value->ToString() == localData[i]->id_product.ToString()) {
								Inventario^ newProduct = gcnew Inventario();
								System::String^ strId = this->txt_id->Text;
								System::String^ strStock = this->txt_stock->Text;
								int id = System::Convert::ToInt32(strId);
								int stock = System::Convert::ToInt32(strStock);
								newProduct->id_product = id;
								newProduct->name = gcnew String(this->txt_name->Text);
								newProduct->stock = stock;
								this->localData[i] = newProduct;
								StreamWriter^ writer = gcnew StreamWriter("inventary.csv");
								for (int i = 0; i < localData->Length; i++) {
									if (localData[i] != nullptr) {
										String^ message = String::Format("{0},{1},{2}",
											localData[i]->id_product, localData[i]->name, localData[i]->stock);
										writer->WriteLine(message);
									}
								}
								writer->Close();
								this->clearInputs();
								this->getDataProducts();
								this->editableData = false;
								this->btn_cancelar->Visible = false;
								for (int i = 0; i < localData->Length; i++) {
									if (localData[i] != nullptr) {
										for (int j = 0; j < localDataCatalogo->Length; j++) {
											if (localDataCatalogo[j] != nullptr) {
												if (localData[i]->id_product == localDataCatalogo[j]->id_product) {
													localDataCatalogo[j]->stock = localData[i]->stock;
												}
											}
										}
									}
								}
								StreamWriter^ writerCatalogo = gcnew StreamWriter("product.csv");
								for (int i = 0; i < localDataCatalogo->Length; i++) {

									if (localDataCatalogo[i] != nullptr) {
										String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
											localDataCatalogo[i]->id_product, localDataCatalogo[i]->name, localDataCatalogo[i]->catego,
											localDataCatalogo[i]->brand, localDataCatalogo[i]->descrip, localDataCatalogo[i]->price,
											localDataCatalogo[i]->stock);
										writerCatalogo->WriteLine(message);
									}
								}
								writerCatalogo->Close();
								this->clearInputs();
								this->getDataProducts();
								this->editableData = false;
								this->btn_cancelar->Visible = false;
								MessageBox::Show("El producto se agregó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
							}
						}
					}
				}
			}
		}
		else {
			Inventario^ newProduct = gcnew Inventario();
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
							System::String^ strStock = this->txt_stock->Text;
							int id = System::Convert::ToInt32(strId);
							int stock = System::Convert::ToInt32(strStock);
							newProduct->id_product = id;
							newProduct->name = gcnew String(this->txt_name->Text);
							newProduct->stock = stock;
							this->localData[indice] = newProduct;
							StreamWriter^ writer = gcnew StreamWriter("inventary.csv");
							for (int i = 0; i < localData->Length; i++) {

								if (localData[i] != nullptr) {
									String^ message = String::Format("{0},{1},{2}",
										localData[i]->id_product, localData[i]->name, localData[i]->stock);
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
			}
		}
	}

	private: System::Void editProduct(System::Object^ sender, System::EventArgs^ e) {
		try {
			DataGridViewRow^ filaSeleccionada = this->dgv_inventary->SelectedRows[0];
			this->txt_id->Text = Convert::ToString(filaSeleccionada->Cells[0]->Value);
			this->txt_name->Text = Convert::ToString(filaSeleccionada->Cells[1]->Value);
			this->txt_stock->Text = Convert::ToString(filaSeleccionada->Cells[2]->Value);
			this->editableData = true;
			this->btn_cancelar->Visible = true;
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al obtener un producto : " + ex->Message, "Error", MessageBoxButtons::OK);
		}
	}
	private: System::Void btn_cancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->clearInputs();
		this->editableData = false;
		this->btn_cancelar->Visible = false;
		this->getDataProducts();
	}
	private: System::Void deleteRowProduct(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			DataGridViewRow^ filaSeleccionada = this->dgv_inventary->SelectedRows[0];
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Estás seguro de querer eliminar estos datos?", "Eliminar Usuario", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::OK) {
				cli::array<Inventario^>^ nuevoLocalData = gcnew cli::array<Inventario^>(localData->Length);
				for (int i = 0; i < localData->Length; i++) {
					if (localData[i] != nullptr) {
						if (localData[i]->id_product.ToString() != filaSeleccionada->Cells[0]->Value->ToString()) {
							nuevoLocalData[i] = localData[i];
						}
					}
				}
				localData = nuevoLocalData;
				StreamWriter^ writer = gcnew StreamWriter("inventary.csv");
				for (int i = 0; i < localData->Length; i++) {
					if (localData[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2}",
							localData[i]->id_product, localData[i]->name, localData[i]->stock);
						writer->WriteLine(message);
					}
				}
				writer->Close();
				this->clearInputs();
				this->getDataProducts();

				//Eliminar de catalogo
				cli::array<Catalogo^>^ nuevoLocalDataCatalogo = gcnew cli::array<Catalogo^>(localDataCatalogo->Length);
				for (int i = 0; i < localDataCatalogo->Length; i++) {
					if (localDataCatalogo[i] != nullptr) {
						if (localDataCatalogo[i]->id_product.ToString() != filaSeleccionada->Cells[0]->Value->ToString()) {
							nuevoLocalDataCatalogo[i] = localDataCatalogo[i];
						}
					}
				}

				localDataCatalogo = nuevoLocalDataCatalogo;
				StreamWriter^ writerCatalogo = gcnew StreamWriter("product.csv");
				for (int i = 0; i < localDataCatalogo->Length; i++) {

					if (localDataCatalogo[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
							localDataCatalogo[i]->id_product, localDataCatalogo[i]->name, localDataCatalogo[i]->catego,
							localDataCatalogo[i]->brand, localDataCatalogo[i]->descrip, localDataCatalogo[i]->price,
							localDataCatalogo[i]->stock);
						writerCatalogo->WriteLine(message);
					}
				}
				writerCatalogo->Close();
				MessageBox::Show("Registro eliminado correctamente", "Completado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
		}
	}
};
}
