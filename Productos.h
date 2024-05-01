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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ category;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ brand;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ description;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ price;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ stock;
	private: System::Windows::Forms::Panel^ formContainer;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ inputContainer;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;


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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->category = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->brand = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->price = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->formContainer = (gcnew System::Windows::Forms::Panel());
			this->inputContainer = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel_table->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->formContainer->SuspendLayout();
			this->inputContainer->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel12->SuspendLayout();
			this->panel13->SuspendLayout();
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
			this->panel_table->Controls->Add(this->dataGridView1);
			this->panel_table->Location = System::Drawing::Point(285, 47);
			this->panel_table->Name = L"panel_table";
			this->panel_table->Size = System::Drawing::Size(389, 389);
			this->panel_table->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->id, this->name,
					this->category, this->brand, this->description, this->price, this->stock
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(389, 389);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->ColumnAdded += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &Productos::dataGridView1_ColumnAdded);
			// 
			// id
			// 
			this->id->HeaderText = L"Código";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			// 
			// name
			// 
			this->name->HeaderText = L"Nombre";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			// 
			// category
			// 
			this->category->HeaderText = L"Categoría";
			this->category->Name = L"category";
			this->category->ReadOnly = true;
			// 
			// brand
			// 
			this->brand->HeaderText = L"Marca";
			this->brand->Name = L"brand";
			this->brand->ReadOnly = true;
			// 
			// description
			// 
			this->description->HeaderText = L"Descripción";
			this->description->Name = L"description";
			this->description->ReadOnly = true;
			// 
			// price
			// 
			this->price->HeaderText = L"Precio";
			this->price->Name = L"price";
			this->price->ReadOnly = true;
			// 
			// stock
			// 
			this->stock->HeaderText = L"Cantidad en Stock";
			this->stock->Name = L"stock";
			this->stock->ReadOnly = true;
			// 
			// formContainer
			// 
			this->formContainer->Controls->Add(this->button1);
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
			// inputContainer
			// 
			this->inputContainer->Controls->Add(this->panel1);
			this->inputContainer->Controls->Add(this->textBox1);
			this->inputContainer->Controls->Add(this->label1);
			this->inputContainer->Location = System::Drawing::Point(3, 3);
			this->inputContainer->Name = L"inputContainer";
			this->inputContainer->Size = System::Drawing::Size(261, 30);
			this->inputContainer->TabIndex = 0;
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
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(158, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 1;
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
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(158, 4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 20);
			this->textBox3->TabIndex = 1;
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
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->textBox3);
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
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(158, 4);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 1;
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
			// panel4
			// 
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->textBox5);
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
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(158, 4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(100, 20);
			this->textBox7->TabIndex = 1;
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
			// panel6
			// 
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Controls->Add(this->textBox7);
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
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(158, 4);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(100, 20);
			this->textBox9->TabIndex = 1;
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
			// panel8
			// 
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Controls->Add(this->textBox9);
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
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(158, 4);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(100, 20);
			this->textBox11->TabIndex = 1;
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
			// panel10
			// 
			this->panel10->Controls->Add(this->panel11);
			this->panel10->Controls->Add(this->textBox11);
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
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(158, 4);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(100, 20);
			this->textBox13->TabIndex = 1;
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
			// panel12
			// 
			this->panel12->Controls->Add(this->panel13);
			this->panel12->Controls->Add(this->textBox13);
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(185, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->formContainer->ResumeLayout(false);
			this->inputContainer->ResumeLayout(false);
			this->inputContainer->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel12->ResumeLayout(false);
			this->panel12->PerformLayout();
			this->panel13->ResumeLayout(false);
			this->panel13->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void dataGridView1_ColumnAdded(System::Object^ sender, System::Windows::Forms::DataGridViewColumnEventArgs^ e) {
		MessageBox::Show(e->Column->ToString(), "Error", MessageBoxButtons::OK);
	}


};
}
