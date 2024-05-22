#pragma once

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Inventary
	/// </summary>
	public ref class Inventary : public System::Windows::Forms::Form
	{
	public:
		Inventary(void)
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
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel4;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
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
		void InitializeComponent(void)
		{
			this->titlePage = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dgv_inventary = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->stock = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->btn_SaveIventary = (gcnew System::Windows::Forms::Button());
			this->btn_cancelar = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_inventary))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// titlePage
			// 
			this->titlePage->AutoSize = true;
			this->titlePage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->titlePage->Location = System::Drawing::Point(24, 21);
			this->titlePage->Name = L"titlePage";
			this->titlePage->Size = System::Drawing::Size(325, 76);
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
			this->panel1->Location = System::Drawing::Point(32, 112);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(712, 928);
			this->panel1->TabIndex = 1;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->dgv_inventary);
			this->panel2->Location = System::Drawing::Point(760, 112);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1037, 928);
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
			this->dgv_inventary->Name = L"dgv_inventary";
			this->dgv_inventary->ReadOnly = true;
			this->dgv_inventary->RowHeadersVisible = false;
			this->dgv_inventary->RowHeadersWidth = 102;
			this->dgv_inventary->RowTemplate->Height = 40;
			this->dgv_inventary->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_inventary->Size = System::Drawing::Size(1037, 928);
			this->dgv_inventary->TabIndex = 0;
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
			// panel3
			// 
			this->panel3->Controls->Add(this->textBox1);
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(8, 7);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(696, 72);
			this->panel3->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(8, 17);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(421, 10);
			this->textBox1->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(260, 38);
			this->textBox1->TabIndex = 1;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->numericUpDown1);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Location = System::Drawing::Point(8, 163);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(696, 72);
			this->panel4->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(8, 17);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(246, 32);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Cantidad de Stock";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(421, 10);
			this->textBox3->Margin = System::Windows::Forms::Padding(8, 7, 8, 7);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(260, 38);
			this->textBox3->TabIndex = 1;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->textBox3);
			this->panel5->Controls->Add(this->label3);
			this->panel5->Location = System::Drawing::Point(8, 85);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(696, 72);
			this->panel5->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 17);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(114, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Nombre";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(421, 10);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(260, 38);
			this->numericUpDown1->TabIndex = 1;
			// 
			// btn_SaveIventary
			// 
			this->btn_SaveIventary->BackColor = System::Drawing::Color::Teal;
			this->btn_SaveIventary->FlatAppearance->BorderSize = 0;
			this->btn_SaveIventary->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_SaveIventary->ForeColor = System::Drawing::Color::White;
			this->btn_SaveIventary->Location = System::Drawing::Point(493, 866);
			this->btn_SaveIventary->Name = L"btn_SaveIventary";
			this->btn_SaveIventary->Size = System::Drawing::Size(200, 55);
			this->btn_SaveIventary->TabIndex = 3;
			this->btn_SaveIventary->Text = L"Guardar";
			this->btn_SaveIventary->UseVisualStyleBackColor = false;
			// 
			// btn_cancelar
			// 
			this->btn_cancelar->BackColor = System::Drawing::Color::Transparent;
			this->btn_cancelar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancelar->ForeColor = System::Drawing::Color::Teal;
			this->btn_cancelar->Location = System::Drawing::Point(277, 866);
			this->btn_cancelar->Name = L"btn_cancelar";
			this->btn_cancelar->Size = System::Drawing::Size(200, 55);
			this->btn_cancelar->TabIndex = 4;
			this->btn_cancelar->Text = L"Cancelar";
			this->btn_cancelar->UseVisualStyleBackColor = false;
			// 
			// Inventary
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1851, 1102);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Inventary";
			this->Text = L"Inventary";
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_inventary))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
