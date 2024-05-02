#pragma once

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Productos
	/// </summary>
	public ref class Productos : public System::Windows::Forms::Form
	{
	public:
		Productos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
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
			this->titlePage->Size = System::Drawing::Size(137, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Productos";
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
			this->dataGrid_Products->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGrid_Products->Size = System::Drawing::Size(389, 389);
			this->dataGrid_Products->TabIndex = 0;
			this->dataGrid_Products->DoubleClick += gcnew System::EventHandler(this, &Productos::EditarProducto);
			// 
			// id
			// 
			this->id->HeaderText = L"Código";
			this->id->Name = L"id";
			// 
			// name
			// 
			this->name->HeaderText = L"Nombre";
			this->name->Name = L"name";
			// 
			// category
			// 
			this->category->HeaderText = L"Categoría";
			this->category->Name = L"category";
			// 
			// brand
			// 
			this->brand->HeaderText = L"Marca";
			this->brand->Name = L"brand";
			// 
			// description
			// 
			this->description->HeaderText = L"Descripción";
			this->description->Name = L"description";
			// 
			// price
			// 
			this->price->HeaderText = L"Precio";
			this->price->Name = L"price";
			// 
			// stock
			// 
			this->stock->HeaderText = L"Cantidad de Stock";
			this->stock->Name = L"stock";
			// 
			// formContainer
			// 
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
			// btn_saveProduct
			// 
			this->btn_saveProduct->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_saveProduct->Location = System::Drawing::Point(185, 363);
			this->btn_saveProduct->Name = L"btn_saveProduct";
			this->btn_saveProduct->Size = System::Drawing::Size(75, 23);
			this->btn_saveProduct->TabIndex = 4;
			this->btn_saveProduct->Text = L"Guardar";
			this->btn_saveProduct->UseVisualStyleBackColor = true;
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
			this->inputContainer->Controls->Add(this->panel1);
			this->inputContainer->Controls->Add(this->txt_id);
			this->inputContainer->Controls->Add(this->label1);
			this->inputContainer->Location = System::Drawing::Point(3, 3);
			this->inputContainer->Name = L"inputContainer";
			this->inputContainer->Size = System::Drawing::Size(261, 30);
			this->inputContainer->TabIndex = 0;
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
			this->txt_id->Location = System::Drawing::Point(158, 4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->Size = System::Drawing::Size(100, 20);
			this->txt_id->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código";
			// 
			// Productos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
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

	private: System::Void SaveProduct(System::Object^ sender, System::EventArgs^ e) {
		if (txt_id->Text != "" && txt_name->Text != "" && txt_brand->Text != "" && txt_category->Text != "" && txt_description->Text != ""
			&& txt_price->Text != "" && txt_stock->Text != "") {
			this->dataGrid_Products->Rows->Add(txt_id->Text, txt_name->Text, txt_category->Text, txt_brand->Text, txt_description->Text, txt_price->Text, txt_stock->Text);
			this->txt_id->Text = "";
			this->txt_name->Text = "";
			this->txt_brand->Text = "";
			this->txt_category->Text = "";
			this->txt_description->Text = "";
			this->txt_price->Text = "";
			this->txt_stock->Text = "";
		}
		else {
			MessageBox::Show("Por favor Ingrese todos los datos.", "Error", MessageBoxButtons::OK);
		}
	}
	private: System::Void EditarProducto(System::Object^ sender, System::EventArgs^ e) {
		DataGridViewRow^ filaSeleccionada = this->dataGrid_Products->SelectedRows[0];
		this->txt_id->Text = Convert::ToString(filaSeleccionada->Cells[0]->Value);
		this->txt_name->Text = Convert::ToString(filaSeleccionada->Cells[1]->Value);
		this->txt_brand->Text = Convert::ToString(filaSeleccionada->Cells[2]->Value);
		this->txt_category->Text = Convert::ToString(filaSeleccionada->Cells[3]->Value);
		this->txt_description->Text = Convert::ToString(filaSeleccionada->Cells[4]->Value);
		this->txt_price->Text = Convert::ToString(filaSeleccionada->Cells[5]->Value);
		this->txt_stock->Text = Convert::ToString(filaSeleccionada->Cells[6]->Value);
	}
};
}
