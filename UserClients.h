#pragma once

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de UserClients
	/// </summary>
	public ref class UserClients : public System::Windows::Forms::Form
	{
	public:
		UserClients(void)
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
		~UserClients()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ titlePage;
	private: System::Windows::Forms::Panel^ formContainer;
	private: System::Windows::Forms::Panel^ panel_table;



	private: System::Windows::Forms::DataGridView^ dgv_table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ lastName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ address;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ phoneNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ email;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ txt_email;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::TextBox^ txt_phoneNumber;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ txt_address;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txt_lastaName;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txt_name;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ txtPassword;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btn_saveClient;





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
			this->formContainer = (gcnew System::Windows::Forms::Panel());
			this->panel_table = (gcnew System::Windows::Forms::Panel());
			this->dgv_table = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phoneNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->email = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txt_lastaName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txt_address = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txt_phoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txt_email = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->btn_saveClient = (gcnew System::Windows::Forms::Button());
			this->formContainer->SuspendLayout();
			this->panel_table->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_table))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->SuspendLayout();
			// 
			// titlePage
			// 
			this->titlePage->AutoSize = true;
			this->titlePage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->titlePage->Location = System::Drawing::Point(9, 9);
			this->titlePage->Name = L"titlePage";
			this->titlePage->Size = System::Drawing::Size(113, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Clientes";
			// 
			// formContainer
			// 
			this->formContainer->Controls->Add(this->btn_saveClient);
			this->formContainer->Controls->Add(this->panel7);
			this->formContainer->Controls->Add(this->panel6);
			this->formContainer->Controls->Add(this->panel5);
			this->formContainer->Controls->Add(this->panel4);
			this->formContainer->Controls->Add(this->panel3);
			this->formContainer->Controls->Add(this->panel2);
			this->formContainer->Controls->Add(this->panel1);
			this->formContainer->Location = System::Drawing::Point(12, 47);
			this->formContainer->Name = L"formContainer";
			this->formContainer->Size = System::Drawing::Size(267, 389);
			this->formContainer->TabIndex = 1;
			// 
			// panel_table
			// 
			this->panel_table->Controls->Add(this->dgv_table);
			this->panel_table->Location = System::Drawing::Point(285, 47);
			this->panel_table->Name = L"panel_table";
			this->panel_table->Size = System::Drawing::Size(389, 389);
			this->panel_table->TabIndex = 2;
			// 
			// dgv_table
			// 
			this->dgv_table->AllowUserToAddRows = false;
			this->dgv_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->id, this->name,
					this->lastName, this->address, this->phoneNumber, this->email
			});
			this->dgv_table->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgv_table->Location = System::Drawing::Point(0, 0);
			this->dgv_table->Name = L"dgv_table";
			this->dgv_table->ReadOnly = true;
			this->dgv_table->RowHeadersVisible = false;
			this->dgv_table->Size = System::Drawing::Size(389, 389);
			this->dgv_table->TabIndex = 0;
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
			// lastName
			// 
			this->lastName->HeaderText = L"Apellido";
			this->lastName->Name = L"lastName";
			this->lastName->ReadOnly = true;
			// 
			// address
			// 
			this->address->HeaderText = L"Dirección";
			this->address->Name = L"address";
			this->address->ReadOnly = true;
			// 
			// phoneNumber
			// 
			this->phoneNumber->HeaderText = L"Número de Teléfono";
			this->phoneNumber->Name = L"phoneNumber";
			this->phoneNumber->ReadOnly = true;
			// 
			// email
			// 
			this->email->HeaderText = L"Correo Electrónico";
			this->email->Name = L"email";
			this->email->ReadOnly = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->txt_id);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(261, 30);
			this->panel1->TabIndex = 0;
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
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(158, 4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->Size = System::Drawing::Size(100, 20);
			this->txt_id->TabIndex = 1;
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(158, 4);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(100, 20);
			this->txt_name->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Nombre";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->txt_name);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(3, 39);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(261, 30);
			this->panel2->TabIndex = 2;
			// 
			// txt_lastaName
			// 
			this->txt_lastaName->Location = System::Drawing::Point(158, 4);
			this->txt_lastaName->Name = L"txt_lastaName";
			this->txt_lastaName->Size = System::Drawing::Size(100, 20);
			this->txt_lastaName->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(44, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Apellido";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->txt_lastaName);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(3, 75);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(261, 30);
			this->panel3->TabIndex = 2;
			// 
			// txt_address
			// 
			this->txt_address->Location = System::Drawing::Point(158, 4);
			this->txt_address->Name = L"txt_address";
			this->txt_address->Size = System::Drawing::Size(100, 20);
			this->txt_address->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Dirección";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->txt_address);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(3, 111);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(261, 30);
			this->panel4->TabIndex = 2;
			// 
			// txt_phoneNumber
			// 
			this->txt_phoneNumber->Location = System::Drawing::Point(158, 4);
			this->txt_phoneNumber->Name = L"txt_phoneNumber";
			this->txt_phoneNumber->Size = System::Drawing::Size(100, 20);
			this->txt_phoneNumber->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Número de Teléfono";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->txt_phoneNumber);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Location = System::Drawing::Point(3, 147);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(261, 30);
			this->panel5->TabIndex = 2;
			// 
			// txt_email
			// 
			this->txt_email->Location = System::Drawing::Point(158, 4);
			this->txt_email->Name = L"txt_email";
			this->txt_email->Size = System::Drawing::Size(100, 20);
			this->txt_email->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(94, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Correo Electrónico";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->txt_email);
			this->panel6->Controls->Add(this->label6);
			this->panel6->Location = System::Drawing::Point(3, 183);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(261, 30);
			this->panel6->TabIndex = 2;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->txtPassword);
			this->panel7->Controls->Add(this->label7);
			this->panel7->Location = System::Drawing::Point(3, 219);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(261, 30);
			this->panel7->TabIndex = 3;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(158, 4);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(100, 20);
			this->txtPassword->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 7);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(61, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Contraseña";
			// 
			// btn_saveClient
			// 
			this->btn_saveClient->Location = System::Drawing::Point(185, 363);
			this->btn_saveClient->Name = L"btn_saveClient";
			this->btn_saveClient->Size = System::Drawing::Size(75, 23);
			this->btn_saveClient->TabIndex = 4;
			this->btn_saveClient->Text = L"Guardar";
			this->btn_saveClient->UseVisualStyleBackColor = true;
			// 
			// UserClients
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->panel_table);
			this->Controls->Add(this->formContainer);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"UserClients";
			this->Text = L"UserClients";
			this->formContainer->ResumeLayout(false);
			this->panel_table->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_table))->EndInit();
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
