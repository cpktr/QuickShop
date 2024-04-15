#pragma once
#include "User.h"


namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

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
	private: Int64 typeLogIn;


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
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 30));
			this->label1->ForeColor = System::Drawing::Color::Teal;
			this->label1->Location = System::Drawing::Point(155, 49);
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
			this->label2->Location = System::Drawing::Point(106, 183);
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
			this->label3->Location = System::Drawing::Point(106, 244);
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
			this->textBox1->Location = System::Drawing::Point(109, 199);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(287, 19);
			this->textBox1->TabIndex = 3;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Teal;
			this->panel1->Location = System::Drawing::Point(109, 281);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(287, 2);
			this->panel1->TabIndex = 6;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::Control;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.25F));
			this->textBox2->Location = System::Drawing::Point(109, 260);
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
			this->label4->Location = System::Drawing::Point(171, 114);
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
			this->button1->Location = System::Drawing::Point(267, 320);
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
			this->button2->Location = System::Drawing::Point(109, 320);
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
			this->panel2->Location = System::Drawing::Point(109, 220);
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
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(501, 492);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(517, 531);
			this->Name = L"MyForm";
			this->Text = L"Login";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	public: User^ user = nullptr;
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ email = this->textBox1->Text;
		String^ password = this->textBox2->Text;
		//Validación de LOGIN
		switch (typeLogIn) {
			case 1:
				//LOGIN de Administrador
				if (email != "" || password != "") {
					if (email == "admin" && password == "123") {
						MessageBox::Show("Sesión iniciada.", "Success", MessageBoxButtons::OK);
						return;
					}
					else {
						MessageBox::Show("Usuario o contraseña Incorrectos.", "Error", MessageBoxButtons::OK);
						return;
					}
				}
				else {
					MessageBox::Show("Porfavor Ingresa un usuario y contraseña válidos." + email + password, "Error", MessageBoxButtons::OK);
					return;
				}
			case 2:
				//LOGIN de Operador
			default:
				break;
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
	}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->typeLogIn = 2;
		this->label4->Text = L"Inicia Sesión como Operador";
		this->label4->Location = System::Drawing::Point(180, 114);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
