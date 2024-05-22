#pragma once

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ paneldepago;
	protected:
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ Tarjeta;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label6;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

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
			this->paneldepago = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Tarjeta = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->paneldepago->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// paneldepago
			// 
			this->paneldepago->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->paneldepago->Controls->Add(this->panel3);
			this->paneldepago->Controls->Add(this->panel2);
			this->paneldepago->Location = System::Drawing::Point(28, 22);
			this->paneldepago->Name = L"paneldepago";
			this->paneldepago->Size = System::Drawing::Size(943, 463);
			this->paneldepago->TabIndex = 0;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel3->Controls->Add(this->button2);
			this->panel3->Controls->Add(this->textBox5);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Location = System::Drawing::Point(22, 255);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(784, 139);
			this->panel3->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Tan;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::BurlyWood;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button2->Location = System::Drawing::Point(633, 74);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 30);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Pagar";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(213, 54);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(117, 22);
			this->textBox5->TabIndex = 5;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Transparent;
			this->label6->Location = System::Drawing::Point(15, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(120, 17);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Ingresar monto";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(15, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(67, 17);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Efectivo";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm1::label5_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->textBox4);
			this->panel2->Controls->Add(this->label4);
			this->panel2->Controls->Add(this->textBox3);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->textBox2);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->Tarjeta);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(22, 28);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(784, 203);
			this->panel2->TabIndex = 0;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm1::panel2_Paint);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Tan;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::SystemColors::InactiveCaption;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::BurlyWood;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(633, 151);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 30);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Pagar";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(590, 109);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(117, 22);
			this->textBox4->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(366, 111);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 17);
			this->label4->TabIndex = 7;
			this->label4->Text = L"CVV";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(458, 55);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(249, 22);
			this->textBox3->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(366, 58);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Titular";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm1::label3_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(213, 106);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(117, 22);
			this->textBox2->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(15, 111);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(98, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Vencimiento";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(81, 58);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(249, 22);
			this->textBox1->TabIndex = 2;
			// 
			// Tarjeta
			// 
			this->Tarjeta->AutoSize = true;
			this->Tarjeta->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Tarjeta->ForeColor = System::Drawing::Color::Transparent;
			this->Tarjeta->Location = System::Drawing::Point(15, 60);
			this->Tarjeta->Name = L"Tarjeta";
			this->Tarjeta->Size = System::Drawing::Size(60, 17);
			this->Tarjeta->TabIndex = 1;
			this->Tarjeta->Text = L"Tarjeta";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(15, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(187, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tarjeta de crédito/debito";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm1::label1_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 493);
			this->ControlBox = false;
			this->Controls->Add(this->paneldepago);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm1";
			this->ShowIcon = false;
			this->Text = L"MyForm1";
			this->paneldepago->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
