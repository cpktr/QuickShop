#pragma once

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Usuarios
	/// </summary>
	public ref class Usuarios : public System::Windows::Forms::Form
	{
	public:
		Usuarios(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~Usuarios()
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ user;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ typeUser;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ cui;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ phoneNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ email;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ address;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::Button^ btn_saveUser;

	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::TextBox^ txt_password;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::TextBox^ txt_address;

	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ txt_email;

	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ txt_phoneNumber;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::TextBox^ txt_cui;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel5;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::TextBox^ txt_user;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ txt_lastName;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txt_name;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;


	protected:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			this->titlePage = (gcnew System::Windows::Forms::Label());
			this->formContainer = (gcnew System::Windows::Forms::Panel());
			this->btn_saveUser = (gcnew System::Windows::Forms::Button());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->txt_password = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->txt_address = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->txt_email = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->txt_phoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->txt_cui = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txt_user = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->txt_lastName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel_table = (gcnew System::Windows::Forms::Panel());
			this->dgv_table = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->lastName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->user = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->typeUser = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->cui = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phoneNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->email = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->formContainer->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel_table->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_table))->BeginInit();
			this->SuspendLayout();
			// 
			// titlePage
			// 
			this->titlePage->AutoSize = true;
			this->titlePage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->titlePage->Location = System::Drawing::Point(9, 9);
			this->titlePage->Name = L"titlePage";
			this->titlePage->Size = System::Drawing::Size(122, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Usuarios";
			// 
			// formContainer
			// 
			this->formContainer->Controls->Add(this->button1);
			this->formContainer->Controls->Add(this->btn_saveUser);
			this->formContainer->Controls->Add(this->panel10);
			this->formContainer->Controls->Add(this->panel9);
			this->formContainer->Controls->Add(this->panel8);
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
			// btn_saveUser
			// 
			this->btn_saveUser->BackColor = System::Drawing::Color::Teal;
			this->btn_saveUser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_saveUser->FlatAppearance->BorderSize = 0;
			this->btn_saveUser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_saveUser->ForeColor = System::Drawing::Color::White;
			this->btn_saveUser->Location = System::Drawing::Point(185, 363);
			this->btn_saveUser->Name = L"btn_saveUser";
			this->btn_saveUser->Size = System::Drawing::Size(75, 23);
			this->btn_saveUser->TabIndex = 4;
			this->btn_saveUser->Text = L"Guardar";
			this->btn_saveUser->UseVisualStyleBackColor = false;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->txt_password);
			this->panel10->Controls->Add(this->label10);
			this->panel10->Location = System::Drawing::Point(3, 327);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(261, 30);
			this->panel10->TabIndex = 3;
			// 
			// txt_password
			// 
			this->txt_password->Location = System::Drawing::Point(158, 4);
			this->txt_password->Name = L"txt_password";
			this->txt_password->PasswordChar = '*';
			this->txt_password->Size = System::Drawing::Size(100, 20);
			this->txt_password->TabIndex = 1;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(3, 7);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(61, 13);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Contrase�a";
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->txt_address);
			this->panel9->Controls->Add(this->label9);
			this->panel9->Location = System::Drawing::Point(3, 291);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(261, 30);
			this->panel9->TabIndex = 3;
			// 
			// txt_address
			// 
			this->txt_address->Location = System::Drawing::Point(158, 4);
			this->txt_address->Name = L"txt_address";
			this->txt_address->Size = System::Drawing::Size(100, 20);
			this->txt_address->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(3, 7);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(100, 13);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Direcci�n Domiciliar";
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->txt_email);
			this->panel8->Controls->Add(this->label8);
			this->panel8->Location = System::Drawing::Point(3, 255);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(261, 30);
			this->panel8->TabIndex = 2;
			// 
			// txt_email
			// 
			this->txt_email->Location = System::Drawing::Point(158, 4);
			this->txt_email->Name = L"txt_email";
			this->txt_email->Size = System::Drawing::Size(100, 20);
			this->txt_email->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(3, 7);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(94, 13);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Correo Electr�nico";
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->txt_phoneNumber);
			this->panel7->Controls->Add(this->label7);
			this->panel7->Location = System::Drawing::Point(3, 219);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(261, 30);
			this->panel7->TabIndex = 2;
			// 
			// txt_phoneNumber
			// 
			this->txt_phoneNumber->Location = System::Drawing::Point(158, 4);
			this->txt_phoneNumber->Name = L"txt_phoneNumber";
			this->txt_phoneNumber->Size = System::Drawing::Size(100, 20);
			this->txt_phoneNumber->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 7);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(104, 13);
			this->label7->TabIndex = 0;
			this->label7->Text = L"N�mero de Tel�fono";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->txt_cui);
			this->panel6->Controls->Add(this->label6);
			this->panel6->Location = System::Drawing::Point(3, 183);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(261, 30);
			this->panel6->TabIndex = 2;
			// 
			// txt_cui
			// 
			this->txt_cui->Location = System::Drawing::Point(158, 4);
			this->txt_cui->Name = L"txt_cui";
			this->txt_cui->Size = System::Drawing::Size(100, 20);
			this->txt_cui->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 7);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"CUI / Pasaporte";
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->comboBox1);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Location = System::Drawing::Point(3, 147);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(261, 30);
			this->panel5->TabIndex = 2;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Tipo de Usuario";
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->txt_user);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(3, 111);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(261, 30);
			this->panel4->TabIndex = 2;
			// 
			// txt_user
			// 
			this->txt_user->Location = System::Drawing::Point(158, 4);
			this->txt_user->Name = L"txt_user";
			this->txt_user->Size = System::Drawing::Size(100, 20);
			this->txt_user->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 7);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Usuario";
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->txt_lastName);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Location = System::Drawing::Point(3, 75);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(261, 30);
			this->panel3->TabIndex = 2;
			// 
			// txt_lastName
			// 
			this->txt_lastName->Location = System::Drawing::Point(158, 4);
			this->txt_lastName->Name = L"txt_lastName";
			this->txt_lastName->Size = System::Drawing::Size(100, 20);
			this->txt_lastName->TabIndex = 1;
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
			// panel2
			// 
			this->panel2->Controls->Add(this->txt_name);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(3, 39);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(261, 30);
			this->panel2->TabIndex = 2;
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
			// panel1
			// 
			this->panel1->Controls->Add(this->txt_id);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(261, 30);
			this->panel1->TabIndex = 0;
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
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
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
			this->dgv_table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->id, this->name,
					this->lastName, this->user, this->typeUser, this->cui, this->phoneNumber, this->email, this->address
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
			this->id->HeaderText = L"ID";
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
			// user
			// 
			this->user->HeaderText = L"Usuario";
			this->user->Name = L"user";
			this->user->ReadOnly = true;
			// 
			// typeUser
			// 
			this->typeUser->HeaderText = L"Tipo de Usuario";
			this->typeUser->Name = L"typeUser";
			this->typeUser->ReadOnly = true;
			// 
			// cui
			// 
			this->cui->HeaderText = L"CUI / Pasaporte";
			this->cui->Name = L"cui";
			this->cui->ReadOnly = true;
			// 
			// phoneNumber
			// 
			this->phoneNumber->HeaderText = L"N�mero de Tel�fono";
			this->phoneNumber->Name = L"phoneNumber";
			this->phoneNumber->ReadOnly = true;
			// 
			// email
			// 
			this->email->HeaderText = L"Correo Electr�nico";
			this->email->Name = L"email";
			this->email->ReadOnly = true;
			// 
			// address
			// 
			this->address->HeaderText = L"Direcci�n Domiciliar";
			this->address->Name = L"address";
			this->address->ReadOnly = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Teal;
			this->button1->Location = System::Drawing::Point(104, 363);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Cancelar";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Operador", L"Administrador" });
			this->comboBox1->Location = System::Drawing::Point(158, 4);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(100, 21);
			this->comboBox1->TabIndex = 1;
			// 
			// Usuarios
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->panel_table);
			this->Controls->Add(this->formContainer);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Usuarios";
			this->Text = L"Usuarios";
			this->formContainer->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
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
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel_table->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}