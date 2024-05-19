#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "Clients.h"
#include "Product.h"
#include "PurchaseProduct.h"
#include "Payments.h"

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
	private: cli::array<Payments^>^ cartShopList = gcnew cli::array<Payments^>(100);
	private: cli::array<Payments^>^ localData = gcnew cli::array<Payments^>(100);
	public:
		Pagos(void)
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ code;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ user;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ total;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ iva;
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->user = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->total = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->iva = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->panel1->Location = System::Drawing::Point(15, 55);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(667, 369);
			this->panel1->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id, this->code,
					this->user, this->type, this->total, this->iva
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(667, 369);
			this->dataGridView1->TabIndex = 0;
			// 
			// id
			// 
			this->id->HeaderText = L"ID";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			// 
			// code
			// 
			this->code->HeaderText = L"Código de Pago";
			this->code->Name = L"code";
			this->code->ReadOnly = true;
			// 
			// user
			// 
			this->user->HeaderText = L"Usuario";
			this->user->Name = L"user";
			this->user->ReadOnly = true;
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
			// iva
			// 
			this->iva->HeaderText = L"IVA";
			this->iva->Name = L"iva";
			this->iva->ReadOnly = true;
			// 
			// Pagos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Pagos";
			this->Text = L"Pagos";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
