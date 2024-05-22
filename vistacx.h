#pragma once
#include "pagoscx.h"


namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de vistacx
	/// </summary>
	public ref class vistacx : public System::Windows::Forms::Form
	{
	public:
		vistacx(void)
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
		~vistacx()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::FlowLayoutPanel^ navbar;
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^ sidebar;
	private: System::Windows::Forms::Panel^ panel_listado;

	private: System::Windows::Forms::Button^ btncarrito;
	private: System::Windows::Forms::Button^ btnlistado;
	private: System::Windows::Forms::Button^ btnpago;
	private: System::Windows::Forms::Button^ btnsalir;
	private: System::Windows::Forms::PictureBox^ pictureBox1;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(vistacx::typeid));
			this->navbar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->sidebar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel_listado = (gcnew System::Windows::Forms::Panel());
			this->btncarrito = (gcnew System::Windows::Forms::Button());
			this->btnlistado = (gcnew System::Windows::Forms::Button());
			this->btnpago = (gcnew System::Windows::Forms::Button());
			this->btnsalir = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->sidebar->SuspendLayout();
			this->panel_listado->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// navbar
			// 
			this->navbar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->navbar->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"navbar.BackgroundImage")));
			this->navbar->Cursor = System::Windows::Forms::Cursors::Hand;
			this->navbar->Dock = System::Windows::Forms::DockStyle::Top;
			this->navbar->Location = System::Drawing::Point(0, 0);
			this->navbar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->navbar->Name = L"navbar";
			this->navbar->Size = System::Drawing::Size(962, 52);
			this->navbar->TabIndex = 0;
			// 
			// sidebar
			// 
			this->sidebar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->sidebar->Controls->Add(this->btncarrito);
			this->sidebar->Controls->Add(this->btnlistado);
			this->sidebar->Controls->Add(this->btnpago);
			this->sidebar->Controls->Add(this->btnsalir);
			this->sidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->sidebar->Location = System::Drawing::Point(0, 52);
			this->sidebar->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->sidebar->Name = L"sidebar";
			this->sidebar->Size = System::Drawing::Size(100, 493);
			this->sidebar->TabIndex = 1;
			this->sidebar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &vistacx::sidebar_Paint);
			// 
			// panel_listado
			// 
			this->panel_listado->BackColor = System::Drawing::Color::White;
			this->panel_listado->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel_listado.BackgroundImage")));
			this->panel_listado->Controls->Add(this->pictureBox1);
			this->panel_listado->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_listado->Location = System::Drawing::Point(100, 52);
			this->panel_listado->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel_listado->Name = L"panel_listado";
			this->panel_listado->Size = System::Drawing::Size(862, 493);
			this->panel_listado->TabIndex = 2;
			this->panel_listado->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &vistacx::panel_cont_Paint);
			// 
			// btncarrito
			// 
			this->btncarrito->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btncarrito->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btncarrito->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btncarrito->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btncarrito->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btncarrito->ForeColor = System::Drawing::Color::Snow;
			this->btncarrito->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btncarrito.Image")));
			this->btncarrito->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btncarrito->Location = System::Drawing::Point(3, 3);
			this->btncarrito->Name = L"btncarrito";
			this->btncarrito->Size = System::Drawing::Size(118, 53);
			this->btncarrito->TabIndex = 0;
			this->btncarrito->Text = L"Carrito";
			this->btncarrito->UseVisualStyleBackColor = false;
			this->btncarrito->Click += gcnew System::EventHandler(this, &vistacx::btncarrito_Click);
			// 
			// btnlistado
			// 
			this->btnlistado->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnlistado->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnlistado->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnlistado->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnlistado->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnlistado->ForeColor = System::Drawing::Color::Snow;
			this->btnlistado->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnlistado.Image")));
			this->btnlistado->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnlistado->Location = System::Drawing::Point(3, 62);
			this->btnlistado->Name = L"btnlistado";
			this->btnlistado->Size = System::Drawing::Size(118, 50);
			this->btnlistado->TabIndex = 0;
			this->btnlistado->Text = L"Listado";
			this->btnlistado->UseVisualStyleBackColor = false;
			this->btnlistado->Click += gcnew System::EventHandler(this, &vistacx::btnlistado_Click);
			// 
			// btnpago
			// 
			this->btnpago->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnpago->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnpago->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->btnpago->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnpago->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 7.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnpago->ForeColor = System::Drawing::Color::Snow;
			this->btnpago->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnpago.Image")));
			this->btnpago->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnpago->Location = System::Drawing::Point(3, 118);
			this->btnpago->Name = L"btnpago";
			this->btnpago->Size = System::Drawing::Size(108, 50);
			this->btnpago->TabIndex = 1;
			this->btnpago->Text = L"Pago";
			this->btnpago->UseVisualStyleBackColor = false;
			this->btnpago->Click += gcnew System::EventHandler(this, &vistacx::button1_Click);
			// 
			// btnsalir
			// 
			this->btnsalir->BackColor = System::Drawing::Color::CornflowerBlue;
			this->btnsalir->FlatAppearance->BorderColor = System::Drawing::SystemColors::ActiveCaption;
			this->btnsalir->FlatAppearance->MouseOverBackColor = System::Drawing::Color::SkyBlue;
			this->btnsalir->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnsalir->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnsalir->ForeColor = System::Drawing::Color::Snow;
			this->btnsalir->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnsalir.Image")));
			this->btnsalir->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnsalir->Location = System::Drawing::Point(3, 174);
			this->btnsalir->Name = L"btnsalir";
			this->btnsalir->Size = System::Drawing::Size(93, 50);
			this->btnsalir->TabIndex = 2;
			this->btnsalir->Text = L"Salir";
			this->btnsalir->UseVisualStyleBackColor = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(237, 174);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(390, 102);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// vistacx
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(962, 545);
			this->Controls->Add(this->panel_listado);
			this->Controls->Add(this->sidebar);
			this->Controls->Add(this->navbar);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"vistacx";
			this->Text = L"vistacx";
			this->sidebar->ResumeLayout(false);
			this->panel_listado->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		template<class T>
		void AbrirPanel(T formChild) {
			if (this->panel_listado->Controls->Count > 0) {
				this->panel_listado->Controls->RemoveAt(0);
			}
			formChild->TopLevel = false;
			formChild->Dock = DockStyle::Fill;
			this->panel_listado->Controls->Add(formChild);
			this->panel_listado->Tag = formChild;
			formChild->Show();
		}
	private: System::Void sidebar_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	this->AbrirPanel(gcnew QuickShop::MyForm1);
}	
private: System::Void panel_cont_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void btnlistado_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btncarrito_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
