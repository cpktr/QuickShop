#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include "User.h"
#include "Persona.h"
#include "Cstomer.h"
#include "Dashboard.h"

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
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: Cstomer dataUsers;
	private: System::Windows::Forms::Panel^ panelContainerFirst;
	private: List<Cstomer^>^ usersPlatform = gcnew List<Cstomer^>();
	public:
		MyForm(void)
		{
			InitializeComponent();

			ifstream usuaa("users.csv");

			if (!usuaa.is_open()) {
				MessageBox::Show("Error al abrir el archivo");
			}
			else {
				string line;
				while (getline(usuaa, line)) {
					string id;
					string username;
					string type;
					string cui;
					string name; 
					string lastname; 
					string address; 
					string phonenumb; 
					string email; 
					string password;

					stringstream ss(line);
					getline(ss, (id), ';');
					getline(ss, (name), ';');
					getline(ss, (lastname), ';');
					getline(ss, (username), ';');
					getline(ss, (type), ';');
					getline(ss, (address), ';');
					getline(ss, (cui), ';');
					getline(ss, (phonenumb), ';');
					getline(ss, (email), ';');
					getline(ss, (password), ';');

					usersPlatform->Add(gcnew Cstomer(gcnew String(id.c_str()), gcnew String(username.c_str()), gcnew String(type.c_str()), gcnew String(cui.c_str()), gcnew String(name.c_str()), gcnew String(lastname.c_str()), gcnew String(address.c_str()), gcnew String(phonenumb.c_str()), gcnew String(email.c_str()), gcnew String(password.c_str())));
					
				}		
			}

			int screenWidth = Screen::PrimaryScreen->Bounds.Width;
			int screenHeight = Screen::PrimaryScreen->Bounds.Height;
			int formWidth = this->Width;
			int formHeight = this->Height;
			int posX = (screenWidth - formWidth) / 2;
			int posY = (screenHeight - formHeight) / 2;

			this->StartPosition = FormStartPosition::Manual;
			this->Location = System::Drawing::Point(posX, posY);

			//Gradient border
			Color color1 = Color::FromArgb(0x52, 0xCB, 0xD9);
			LinearGradientBrush^ gradientBrush = gcnew LinearGradientBrush(
				panel1->ClientRectangle, Color::Teal, color1, LinearGradientMode::Horizontal);

			panel1->BackgroundImage = gcnew Bitmap(panel1->Width, panel1->Height);
			Graphics^ g = Graphics::FromImage(panel1->BackgroundImage);
			g->FillRectangle(gradientBrush, panel1->ClientRectangle);

			LinearGradientBrush^ gradientBrush2 = gcnew LinearGradientBrush(
				panel2->ClientRectangle, Color::Teal, color1, LinearGradientMode::Horizontal);

			panel2->BackgroundImage = gcnew Bitmap(panel2->Width, panel2->Height);
			Graphics^ g2 = Graphics::FromImage(panel2->BackgroundImage);
			g2->FillRectangle(gradientBrush2, panel2->ClientRectangle);

			//boton redondeado


			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: Boolean menuOpen;
	private: int typeLogIn = 1;
	


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panelContainerFirst = (gcnew System::Windows::Forms::Panel());
			this->panelContainerFirst->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 30));
			this->label1->ForeColor = System::Drawing::Color::Teal;
			this->label1->Location = System::Drawing::Point(154, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(215, 54);
			this->label1->TabIndex = 0;
			this->label1->Text = L"QuickShop";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F));
			this->label2->ForeColor = System::Drawing::Color::Teal;
			this->label2->Location = System::Drawing::Point(106, 185);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Usuario";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F));
			this->label3->ForeColor = System::Drawing::Color::Teal;
			this->label3->Location = System::Drawing::Point(106, 240);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Contraseña";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->textBox1->Location = System::Drawing::Point(109, 201);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(287, 19);
			this->textBox1->TabIndex = 3;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Teal;
			this->panel1->Location = System::Drawing::Point(109, 277);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(287, 2);
			this->panel1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->textBox2->Location = System::Drawing::Point(109, 256);
			this->textBox2->Name = L"textBox2";
			this->textBox2->PasswordChar = '*';
			this->textBox2->Size = System::Drawing::Size(287, 19);
			this->textBox2->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
			this->label4->ForeColor = System::Drawing::Color::DarkGray;
			this->label4->Location = System::Drawing::Point(169, 112);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(178, 13);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Inicia Sesión como Administrador";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Teal;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(267, 316);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(129, 35);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Ingresar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			this->button1->MouseEnter += gcnew System::EventHandler(this, &MyForm::button1_HoverIn);
			this->button1->MouseLeave += gcnew System::EventHandler(this, &MyForm::button1_HoverOut);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->button2->ForeColor = System::Drawing::Color::Teal;
			this->button2->Location = System::Drawing::Point(109, 316);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 35);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			this->button2->MouseEnter += gcnew System::EventHandler(this, &MyForm::button2_HoverIn);
			this->button2->MouseLeave += gcnew System::EventHandler(this, &MyForm::button2_HoverOut);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Teal;
			this->panel2->Location = System::Drawing::Point(109, 222);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(287, 2);
			this->panel2->TabIndex = 10;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Transparent;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->button3->ForeColor = System::Drawing::Color::Teal;
			this->button3->Location = System::Drawing::Point(0, 0);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(36, 35);
			this->button3->TabIndex = 11;
			this->button3->Text = L"←";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Transparent;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->button4->ForeColor = System::Drawing::Color::Teal;
			this->button4->Location = System::Drawing::Point(-100, -100);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(129, 35);
			this->button4->TabIndex = 12;
			this->button4->Text = L"Administrador";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::Transparent;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Teal;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->button5->ForeColor = System::Drawing::Color::Teal;
			this->button5->Location = System::Drawing::Point(-100, -100);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(129, 35);
			this->button5->TabIndex = 13;
			this->button5->Text = L"Operador";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// panelContainerFirst
			// 
			this->panelContainerFirst->Controls->Add(this->button3);
			this->panelContainerFirst->Controls->Add(this->button4);
			this->panelContainerFirst->Controls->Add(this->button5);
			this->panelContainerFirst->Controls->Add(this->label1);
			this->panelContainerFirst->Controls->Add(this->label4);
			this->panelContainerFirst->Controls->Add(this->label2);
			this->panelContainerFirst->Controls->Add(this->button2);
			this->panelContainerFirst->Controls->Add(this->panel2);
			this->panelContainerFirst->Controls->Add(this->button1);
			this->panelContainerFirst->Controls->Add(this->panel1);
			this->panelContainerFirst->Controls->Add(this->textBox1);
			this->panelContainerFirst->Controls->Add(this->textBox2);
			this->panelContainerFirst->Controls->Add(this->label3);
			this->panelContainerFirst->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelContainerFirst->Location = System::Drawing::Point(0, 0);
			this->panelContainerFirst->Name = L"panelContainerFirst";
			this->panelContainerFirst->Size = System::Drawing::Size(485, 453);
			this->panelContainerFirst->TabIndex = 14;
			this->panelContainerFirst->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panelContainerFirst_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(485, 453);
			this->Controls->Add(this->panelContainerFirst);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"QuickShop";
			this->panelContainerFirst->ResumeLayout(false);
			this->panelContainerFirst->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	template<class T>
	void CambiarPanel(T formChild) {
		if (this->panelContainerFirst->Controls->Count > 0) {
			this->panelContainerFirst->Controls->RemoveAt(0);
			this->panelContainerFirst->Controls->Clear();
			formChild->TopLevel = false;
			formChild->Dock = DockStyle::Fill;
			QuickShop::Dashboard dashboardForm;
			this->panelContainerFirst->Controls->Add(formChild);
			this->panelContainerFirst->Tag = formChild;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			formChild->Show();
		}
		
	}
	private: bool LoginLogicAdmin(String^ email, String^ password) {
		for each (Cstomer ^ user in usersPlatform)
		{
			if (user->getUsername() == email && user->getPassword() == password)
			{
				if (user->getType() == "administrador") {
					return true;
				}
				else {
					return false;
				}
			}
		}
		return false;
	}
	private: bool LoginLogicOperator(String^ email, String^ password) {
		for each (Cstomer ^ user in usersPlatform)
		{
			if (user->getUsername() == email && user->getPassword() == password)
			{
				if (user->getType() == "operador") {
					return true;
				}
				else {
					return false;
				}
			}
		}
		return false;
	}
	public: User^ user = nullptr;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = this->textBox1->Text;
		String^ password = this->textBox2->Text;
		//Validación de LOGIN
		if (email != "" || password != "") {
			if (typeLogIn == 1) {//LOGIN ADMINISTRADOR
				if (this->LoginLogicAdmin(email, password)) {
					MessageBox::Show("Inicio de sesión exitoso", "¡Bienvenido!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					this->CambiarPanel(gcnew QuickShop::Dashboard);
				}
				else {
					MessageBox::Show("Error: Nombre de usuario o contraseña incorrectos" + typeLogIn, "Error de inicio de sesión", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else if (typeLogIn == 2) {//LOGIN OPERADOR
				if (this->LoginLogicOperator(email, password)) {
					MessageBox::Show("Inicio de sesión exitoso", "¡Bienvenido!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					this->CambiarPanel(gcnew QuickShop::Dashboard);
				}
				else {
					MessageBox::Show("Error: Nombre de usuario o contraseña incorrectos" + typeLogIn, "Error de inicio de sesión", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			else {
				return;
			}
		}
		
	}

	private: System::Void button1_HoverIn(System::Object^ sender, System::EventArgs^ e) {
		this->button1->Cursor = Cursors::Hand;
		this->button1->BackColor = System::Drawing::Color::Transparent;
		this->button1->ForeColor = System::Drawing::Color::Teal;
		this->button1->FlatAppearance->BorderSize = 1;
	}
	private: System::Void button1_HoverOut(System::Object^ sender, System::EventArgs^ e) {
		this->button1->Cursor = Cursors::Default;
		this->button1->BackColor = System::Drawing::Color::Teal;
		this->button1->ForeColor = System::Drawing::Color::White;
		this->button1->FlatAppearance->BorderSize = 0;
	}
	private: System::Void button2_HoverIn(System::Object^ sender, System::EventArgs^ e) {
		this->button2->Cursor = Cursors::Hand;
		this->button2->BackColor = System::Drawing::Color::Teal;
		this->button2->ForeColor = System::Drawing::Color::White;
		this->button2->FlatAppearance->BorderSize = 0;
	}
	private: System::Void button2_HoverOut(System::Object^ sender, System::EventArgs^ e) {
		this->button2->Cursor = Cursors::Default;
		this->button2->BackColor = System::Drawing::Color::Transparent;
		this->button2->ForeColor = System::Drawing::Color::Teal;
		this->button2->FlatAppearance->BorderSize = 1;
	}
	
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->menuOpen = !menuOpen;
		if (menuOpen) {
			this->button3->Location = System::Drawing::Point(129, 0);
			this->button3->Text = "X";
			this->button4->Location = System::Drawing::Point(0, 0);
			this->button5->Location = System::Drawing::Point(0, 35.5);
		}
		else {
			this->button3->Location = System::Drawing::Point(0, 0);
			this->button3->Text = L"←";
			this->button4->Location = System::Drawing::Point(-100, -100);
			this->button5->Location = System::Drawing::Point(-100, -100);
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->typeLogIn = 1;
		this->label4->Text = L"Inicia Sesión como Administrador";
		this->label4->Location = System::Drawing::Point(171, 114);
		this->textBox1->Clear();
		this->textBox2->Clear();
		this->button3->Location = System::Drawing::Point(0, 0);
		this->button3->Text = L"←";
		this->button4->Location = System::Drawing::Point(-100, -100);
		this->button5->Location = System::Drawing::Point(-100, -100);
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->typeLogIn = 2;
		this->label4->Text = L"Inicia Sesión como Operador";
		this->label4->Location = System::Drawing::Point(180, 114);
		this->textBox1->Clear();
		this->textBox2->Clear();
		this->button3->Location = System::Drawing::Point(0, 0);
		this->button3->Text = L"←";
		this->button4->Location = System::Drawing::Point(-100, -100);
		this->button5->Location = System::Drawing::Point(-100, -100);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void panelContainerFirst_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
