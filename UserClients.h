#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Clients.h"
#include "User.h"

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
	/// Resumen de UserClients
	/// </summary>
	public ref class UserClients : public System::Windows::Forms::Form
	{
	private: cli::array<Clients^>^ localData = gcnew cli::array<Clients^>(100);
	private: System::Windows::Forms::Button^ btn_uploadCSV;
	private: System::Windows::Forms::Button^ btn_exportarCSV;
	private: User^ userSess;
	private: bool editableData;
	public:
		UserClients(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->getUsersdata();
		}
		UserClients(User^ userSession)
		{
			InitializeComponent();
			if (this->userSess != nullptr) {
				MessageBox::Show(this->userSess->operador.ToString());
				if (this->userSess->operador == true) {
					this->btn_uploadCSV->Visible = false;
				}
			}
			this->getUsersdata();
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
	private: System::Windows::Forms::TextBox^ txt_lastName;


	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ txt_name;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ txt_password;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ btn_saveClient;
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
		void getUsersdata() {
			this->dgv_table->Rows->Clear();
			this->editableData = false;
			this->localData = gcnew cli::array<Clients^>(100);
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

						localData[limit] = newUser;
						this->dgv_table->Rows->Add(localData[limit]->code, localData[limit]->name, localData[limit]->lastName, localData[limit]->address, localData[limit]->phoneNum, localData[limit]->email);
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

			for (int i = 0; i < localData->Length; i++) {
				if (localData[0] == nullptr) {
					this->txt_id->Text = "1";
				}
				else {
					if (localData[i] == nullptr) {
						this->txt_id->Text = (localData[i - 1]->code+1).ToString();
						break;
					}
				}
			}


		}
		void InitializeComponent(void)
		{
			this->titlePage = (gcnew System::Windows::Forms::Label());
			this->formContainer = (gcnew System::Windows::Forms::Panel());
			this->btn_exportarCSV = (gcnew System::Windows::Forms::Button());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->btn_saveClient = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->txt_password = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->txt_email = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->txt_phoneNumber = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->txt_address = (gcnew System::Windows::Forms::TextBox());
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
			this->address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phoneNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->email = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btn_uploadCSV = (gcnew System::Windows::Forms::Button());
			this->formContainer->SuspendLayout();
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
			this->titlePage->Size = System::Drawing::Size(113, 31);
			this->titlePage->TabIndex = 0;
			this->titlePage->Text = L"Clientes";
			// 
			// formContainer
			// 
			this->formContainer->Controls->Add(this->btn_exportarCSV);
			this->formContainer->Controls->Add(this->btn_cancel);
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
			this->btn_exportarCSV->Click += gcnew System::EventHandler(this, &UserClients::btn_exportarCSV_Click);
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
			this->btn_cancel->Click += gcnew System::EventHandler(this, &UserClients::btn_cancel_Click);
			// 
			// btn_saveClient
			// 
			this->btn_saveClient->BackColor = System::Drawing::Color::Teal;
			this->btn_saveClient->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_saveClient->FlatAppearance->BorderSize = 0;
			this->btn_saveClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_saveClient->ForeColor = System::Drawing::Color::White;
			this->btn_saveClient->Location = System::Drawing::Point(185, 363);
			this->btn_saveClient->Name = L"btn_saveClient";
			this->btn_saveClient->Size = System::Drawing::Size(75, 23);
			this->btn_saveClient->TabIndex = 4;
			this->btn_saveClient->Text = L"Guardar";
			this->btn_saveClient->UseVisualStyleBackColor = false;
			this->btn_saveClient->Click += gcnew System::EventHandler(this, &UserClients::btn_saveClient_Click);
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->txt_password);
			this->panel7->Controls->Add(this->label7);
			this->panel7->Location = System::Drawing::Point(3, 219);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(261, 30);
			this->panel7->TabIndex = 3;
			// 
			// txt_password
			// 
			this->txt_password->Location = System::Drawing::Point(158, 4);
			this->txt_password->Name = L"txt_password";
			this->txt_password->PasswordChar = '*';
			this->txt_password->Size = System::Drawing::Size(100, 20);
			this->txt_password->TabIndex = 1;
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
			// panel6
			// 
			this->panel6->Controls->Add(this->txt_email);
			this->panel6->Controls->Add(this->label6);
			this->panel6->Location = System::Drawing::Point(3, 183);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(261, 30);
			this->panel6->TabIndex = 2;
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
			// panel5
			// 
			this->panel5->Controls->Add(this->txt_phoneNumber);
			this->panel5->Controls->Add(this->label5);
			this->panel5->Location = System::Drawing::Point(3, 147);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(261, 30);
			this->panel5->TabIndex = 2;
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
			// panel4
			// 
			this->panel4->Controls->Add(this->txt_address);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Location = System::Drawing::Point(3, 111);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(261, 30);
			this->panel4->TabIndex = 2;
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
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código";
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
			this->dgv_table->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgv_table->Size = System::Drawing::Size(389, 389);
			this->dgv_table->TabIndex = 0;
			this->dgv_table->DoubleClick += gcnew System::EventHandler(this, &UserClients::EditarCliente);
			this->dgv_table->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UserClients::deleteRowClient);
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
			this->btn_uploadCSV->TabIndex = 5;
			this->btn_uploadCSV->Text = L"Cargar";
			this->btn_uploadCSV->UseVisualStyleBackColor = false;
			this->btn_uploadCSV->Click += gcnew System::EventHandler(this, &UserClients::btn_uploadCSV_Click);
			// 
			// UserClients
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(694, 462);
			this->Controls->Add(this->btn_uploadCSV);
			this->Controls->Add(this->panel_table);
			this->Controls->Add(this->formContainer);
			this->Controls->Add(this->titlePage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"UserClients";
			this->Text = L"UserClients";
			this->formContainer->ResumeLayout(false);
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
	private: void clearTxt() {
		this->txt_id->Clear();
		this->txt_name->Clear();
		this->txt_lastName->Clear();
		this->txt_phoneNumber->Clear();
		this->txt_email->Clear();
		this->txt_address->Clear();
		this->txt_password->Clear();
	}
	private: bool CamposNoVacios()
	{
		return !(String::IsNullOrEmpty(this->txt_id->Text) ||
			String::IsNullOrEmpty(this->txt_name->Text) ||
			String::IsNullOrEmpty(this->txt_phoneNumber->Text) ||
			String::IsNullOrEmpty(this->txt_email->Text) ||
			String::IsNullOrEmpty(this->txt_address->Text) ||
			String::IsNullOrEmpty(this->txt_password->Text));
	}
	private: bool validateExistData() {
		String^ newId = gcnew String(this->txt_id->Text);
		String^ newEmail = gcnew String(this->txt_email->Text);

		for (int i = 0; i < localData->Length; i++) {
			if (localData[i] != nullptr) {
				if (!editableData && localData[i]->code.ToString() == newId) {
					MessageBox::Show("El ID del usuario ya existe en registros anteriores", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false; // El id_customer ya existe en otro registro, no se puede agregar
				}
				if (localData[i]->email == newEmail && localData[i]->code.ToString() != newId) {
					MessageBox::Show("El correo electrónico ya está en uso", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return false; // El email ya existe en otro registro, no se puede agregar
				}
			}
		}
		return true;
	}
	private: System::Void btn_saveClient_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->editableData) {
			if (validateExistData()) {
				DataGridViewRow^ filaSeleccionada = this->dgv_table->SelectedRows[0];
				for (int i = 0; i < localData->Length; i++) {
					if (filaSeleccionada->Cells[0]->Value->ToString() == localData[i]->code.ToString()) {
						Clients^ newUser = gcnew Clients();
						System::String^ strId = filaSeleccionada->Cells[0]->Value->ToString();
						int id = System::Convert::ToInt32(strId);
						newUser->code = id;
						newUser->name = gcnew String(this->txt_name->Text);
						newUser->lastName = gcnew String(this->txt_lastName->Text);
						newUser->phoneNum = gcnew String(this->txt_phoneNumber->Text);
						newUser->email = gcnew String(this->txt_email->Text);
						newUser->address = gcnew String(this->txt_address->Text);
						newUser->password = gcnew String(this->txt_password->Text);
						this->localData[i] = newUser;

						StreamWriter^ writer = gcnew StreamWriter("clients.csv");
						for (int i = 0; i < localData->Length; i++) {

							if (localData[i] != nullptr) {
								String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
									localData[i]->code, localData[i]->name, localData[i]->lastName,
									localData[i]->phoneNum, localData[i]->email, localData[i]->address, localData[i]->password);
								writer->WriteLine(message);
							}

						}
						writer->Close();
						this->clearTxt();
						this->getUsersdata();
						this->editableData = false;
						this->btn_cancel->Visible = false;
						MessageBox::Show("El cliente se actualizó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
						break;
					}
				}
			}
		}
		else {
			Clients^ newUser = gcnew Clients();
			int indice = -1;
			for (int i = 0; i < localData->Length; i++) {
				if (localData[i] == nullptr) {
					indice = i;
					break;
				}
			}
			if (indice != -1) {
				if (CamposNoVacios()) {
					System::String^ strId = this->txt_id->Text;
					int id = System::Convert::ToInt32(strId);
					newUser->code = id;
					newUser->name = gcnew String(this->txt_name->Text);
					newUser->lastName = gcnew String(this->txt_lastName->Text);
					newUser->phoneNum = gcnew String(this->txt_phoneNumber->Text);
					newUser->email = gcnew String(this->txt_email->Text);
					newUser->address = gcnew String(this->txt_address->Text);
					newUser->password = gcnew String(this->txt_password->Text);

					this->localData[indice] = newUser;
					StreamWriter^ writer = gcnew StreamWriter("clients.csv");
					for (int i = 0; i < localData->Length; i++) {

						if (localData[i] != nullptr) {
							String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
								localData[i]->code, localData[i]->name, localData[i]->lastName,
								localData[i]->phoneNum, localData[i]->email, localData[i]->address, localData[i]->password);
							writer->WriteLine(message);
						}

					}
					writer->Close();
					this->clearTxt();
					this->getUsersdata();
					MessageBox::Show("El usuario se agregó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				else {
					MessageBox::Show("Por favor, completa todos los campos antes de agregar un nuevo usuario.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				MessageBox::Show("No hay espacio disponible para agregar más clientes.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->clearTxt();
		this->editableData = false;
		this->btn_cancel->Visible = false;
		this->getUsersdata();
	}
	private: System::Void EditarCliente(System::Object^ sender, System::EventArgs^ e) {
		DataGridViewRow^ filaSeleccionada = this->dgv_table->SelectedRows[0];
		this->txt_id->Text = Convert::ToString(filaSeleccionada->Cells[0]->Value);
		this->txt_name->Text = Convert::ToString(filaSeleccionada->Cells[1]->Value);
		this->txt_lastName->Text = Convert::ToString(filaSeleccionada->Cells[2]->Value);
		this->txt_address->Text = Convert::ToString(filaSeleccionada->Cells[3]->Value);
		this->txt_phoneNumber->Text = Convert::ToString(filaSeleccionada->Cells[4]->Value);
		this->txt_email->Text = Convert::ToString(filaSeleccionada->Cells[5]->Value);
		
		for (int i = 0; i < localData->Length; i++) {
			if (filaSeleccionada->Cells[0]->Value->ToString() == localData[i]->code.ToString()) {
				this->txt_password->Text = Convert::ToString(localData[i]->password);
				break;
			}
		}
		this->editableData = true;
		this->btn_cancel->Visible = true;
	}
	private: System::Void deleteRowClient(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Delete) {
			DataGridViewRow^ filaSeleccionada = this->dgv_table->SelectedRows[0];
			System::Windows::Forms::DialogResult result = MessageBox::Show("¿Estás seguro de querer eliminar estos datos?", "Eliminar Usuario", MessageBoxButtons::OKCancel, MessageBoxIcon::Warning);
			if (result == System::Windows::Forms::DialogResult::OK) {
				cli::array<Clients^>^ nuevoLocalData = gcnew cli::array<Clients^>(localData->Length);

				for (int i = 0; i < localData->Length; i++) {
					if (localData[i] != nullptr) {
						if (localData[i]->code.ToString() != filaSeleccionada->Cells[0]->Value->ToString()) {
							nuevoLocalData[i] = localData[i];
						}
					}
				}
				localData = nuevoLocalData;
				StreamWriter^ writer = gcnew StreamWriter("clients.csv");
				for (int i = 0; i < localData->Length; i++) {

					if (localData[i] != nullptr) {
						String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
							localData[i]->code, localData[i]->name, localData[i]->lastName,
							localData[i]->phoneNum, localData[i]->email, localData[i]->address, localData[i]->password);
						writer->WriteLine(message);
					}

				}
				writer->Close();
				this->clearTxt();
				this->getUsersdata();
				MessageBox::Show("Registro eliminado correctamente", "Completado", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
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
		cli::array<Clients^>^ newImport = gcnew cli::array<Clients^>(100);
		String^ id_new = gcnew String(this->txt_id->Text);
		string message;
		for (int i = 0; i < numRows; i++) {
			message.clear();
			Clients^ newUser = gcnew Clients();
			cli::array<String^>^ row = csvData[i];
			for each (String ^ field in row) {
				for (int i = 0; i < field->Length; i++) {
					message.push_back(static_cast<char>(field[i]));
				}
			}
			string id;
			string name;
			string lastname;
			string address;
			string phonenumb;
			string email;
			string password;

			stringstream ss(message);
			getline(ss, id, ';');
			getline(ss, name, ';');
			getline(ss, lastname, ';');
			getline(ss, address, ';');
			getline(ss, phonenumb, ';');
			getline(ss, email, ';');
			getline(ss, password, ';');
			newUser->code = std::stoi(id);;
			newUser->name = gcnew String(name.c_str());
			newUser->lastName = gcnew String(lastname.c_str());
			newUser->phoneNum = gcnew String(phonenumb.c_str());
			newUser->email = gcnew String(email.c_str());
			newUser->address = gcnew String(address.c_str());
			newUser->password = gcnew String(password.c_str());
			id_new = (Convert::ToInt32(id_new) + 1).ToString();
			newImport[i] = newUser;

		}
		cli::array<Clients^>^ tempArray = gcnew cli::array<Clients^>(localData->Length);
		Array::Copy(localData, tempArray, localData->Length);
		Array::Resize(localData, localData->Length + newImport->Length);
		Array::Copy(tempArray, localData, tempArray->Length);
		Array::Copy(newImport, 0, localData, tempArray->Length, newImport->Length);

		StreamWriter^ writer = gcnew StreamWriter("clients.csv");
		for (int i = 0; i < localData->Length; i++) {

			if (localData[i] != nullptr) {
				String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6}",
					localData[i]->code, localData[i]->name, localData[i]->lastName,
					localData[i]->phoneNum, localData[i]->email, localData[i]->address, localData[i]->password);
				writer->WriteLine(message);
			}

		}
		writer->Close();
		this->clearTxt();
		this->getUsersdata();
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
		saveFileDialog->FileName = "ReporteClientes" + dateString;
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			String^ filePath = saveFileDialog->FileName;

			StreamWriter^ sw = gcnew StreamWriter(filePath);
			for (int i = 0; i < this->dgv_table->Columns->Count; i++) {
				sw->Write(this->dgv_table->Columns[i]->HeaderText);
				if (i < this->dgv_table->Columns->Count - 1) {
					sw->Write(";");
				}
			}
			sw->WriteLine();

			for (int i = 0; i < this->dgv_table->Rows->Count; i++) {
				for (int j = 0; j < this->dgv_table->Columns->Count; j++) {
					sw->Write(this->dgv_table->Rows[i]->Cells[j]->Value->ToString());
					if (j < this->dgv_table->Columns->Count - 1) {
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
};
}
