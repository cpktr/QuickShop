#pragma once

using namespace std;
#include "Home.h"
#include "Productos.h"
#include "Pagos.h"
#include "Reportes.h"
#include "Usuarios.h"
#include "UserClients.h"
#include "Compras.h"
#include "User.h"
#include "Inventary.h"

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	private: User^ userSess;
	private: System::Windows::Forms::Label^ sessionEmailLabel;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Button^ btn_inventary;

	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button8;
	public:
		bool sidebarExpand;
		Dashboard(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		Dashboard(User^ userSession) {
			this->userSess = userSession;
			InitializeComponent();
			if (this->userSess != nullptr) {
				this->sessionEmailLabel->Text = this->userSess->email;
				if (this->userSess->operador == true) {
					this->button_usuarios->Visible = false;
					this->panel_users->Visible = false;
				}
			}
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Dashboard()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel_users;
	private: System::Windows::Forms::Button^ button_usuarios;


	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel_contenedor;

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ button7;


	private: System::Windows::Forms::Panel^ fatherPanelDashboard;

	private: System::ComponentModel::IContainer^ components;

	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->sessionEmailLabel = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel_users = (gcnew System::Windows::Forms::Panel());
			this->button_usuarios = (gcnew System::Windows::Forms::Button());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->btn_inventary = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel_contenedor = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->fatherPanelDashboard = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel4->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel_users->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel_contenedor->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->fatherPanelDashboard->SuspendLayout();
			this->SuspendLayout();
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Teal;
			this->flowLayoutPanel1->Controls->Add(this->panel1);
			this->flowLayoutPanel1->Controls->Add(this->panel2);
			this->flowLayoutPanel1->Controls->Add(this->panel4);
			this->flowLayoutPanel1->Controls->Add(this->panel3);
			this->flowLayoutPanel1->Controls->Add(this->panel5);
			this->flowLayoutPanel1->Controls->Add(this->panel_users);
			this->flowLayoutPanel1->Controls->Add(this->panel7);
			this->flowLayoutPanel1->Controls->Add(this->panel8);
			this->flowLayoutPanel1->Controls->Add(this->panel9);
			this->flowLayoutPanel1->Controls->Add(this->panel6);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->MaximumSize = System::Drawing::Size(222, 462);
			this->flowLayoutPanel1->MinimumSize = System::Drawing::Size(50, 462);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(222, 462);
			this->flowLayoutPanel1->TabIndex = 1;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::flowLayoutPanel1_Paint);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->sessionEmailLabel);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(219, 55);
			this->panel1->TabIndex = 0;
			// 
			// sessionEmailLabel
			// 
			this->sessionEmailLabel->AutoSize = true;
			this->sessionEmailLabel->BackColor = System::Drawing::Color::Transparent;
			this->sessionEmailLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->sessionEmailLabel->ForeColor = System::Drawing::Color::White;
			this->sessionEmailLabel->Location = System::Drawing::Point(59, 17);
			this->sessionEmailLabel->Name = L"sessionEmailLabel";
			this->sessionEmailLabel->Size = System::Drawing::Size(42, 17);
			this->sessionEmailLabel->TabIndex = 2;
			this->sessionEmailLabel->Text = L"Email";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(124, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(95, 31);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(9, 9);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(21, 31);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Dashboard::menuButton_click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button1);
			this->panel2->Location = System::Drawing::Point(3, 64);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(219, 36);
			this->panel2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Teal;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(-12, -8);
			this->button1->Name = L"button1";
			this->button1->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button1->Size = System::Drawing::Size(241, 54);
			this->button1->TabIndex = 2;
			this->button1->Text = L"                           Home";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Dashboard::button1_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button3);
			this->panel4->Location = System::Drawing::Point(3, 106);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(219, 36);
			this->panel4->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::Teal;
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->Location = System::Drawing::Point(-12, -8);
			this->button3->Name = L"button3";
			this->button3->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button3->Size = System::Drawing::Size(241, 54);
			this->button3->TabIndex = 2;
			this->button3->Text = L"                          Clientes";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Dashboard::button3_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button2);
			this->panel3->Location = System::Drawing::Point(3, 148);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(219, 36);
			this->panel3->TabIndex = 3;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Teal;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->Location = System::Drawing::Point(-12, -8);
			this->button2->Name = L"button2";
			this->button2->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button2->Size = System::Drawing::Size(241, 54);
			this->button2->TabIndex = 2;
			this->button2->Text = L"                          Catalogo";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Dashboard::button2_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->button4);
			this->panel5->Location = System::Drawing::Point(3, 190);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(219, 36);
			this->panel5->TabIndex = 4;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::Teal;
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->Location = System::Drawing::Point(-12, -8);
			this->button4->Name = L"button4";
			this->button4->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button4->Size = System::Drawing::Size(241, 54);
			this->button4->TabIndex = 2;
			this->button4->Text = L"                           Pagos";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Dashboard::button4_Click);
			// 
			// panel_users
			// 
			this->panel_users->Controls->Add(this->button_usuarios);
			this->panel_users->Location = System::Drawing::Point(3, 232);
			this->panel_users->Name = L"panel_users";
			this->panel_users->Size = System::Drawing::Size(219, 36);
			this->panel_users->TabIndex = 5;
			// 
			// button_usuarios
			// 
			this->button_usuarios->BackColor = System::Drawing::Color::Teal;
			this->button_usuarios->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button_usuarios->ForeColor = System::Drawing::Color::White;
			this->button_usuarios->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_usuarios.Image")));
			this->button_usuarios->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_usuarios->Location = System::Drawing::Point(-12, -8);
			this->button_usuarios->Name = L"button_usuarios";
			this->button_usuarios->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button_usuarios->Size = System::Drawing::Size(241, 54);
			this->button_usuarios->TabIndex = 2;
			this->button_usuarios->Text = L"                          Usuarios";
			this->button_usuarios->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_usuarios->UseVisualStyleBackColor = false;
			this->button_usuarios->Click += gcnew System::EventHandler(this, &Dashboard::button5_Click);
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->button6);
			this->panel7->Location = System::Drawing::Point(3, 274);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(219, 36);
			this->panel7->TabIndex = 6;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::Teal;
			this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button6->ForeColor = System::Drawing::Color::White;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->Location = System::Drawing::Point(-12, -8);
			this->button6->Name = L"button6";
			this->button6->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button6->Size = System::Drawing::Size(241, 54);
			this->button6->TabIndex = 2;
			this->button6->Text = L"                          Reportes";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Dashboard::button6_Click);
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->button7);
			this->panel8->Location = System::Drawing::Point(3, 316);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(219, 36);
			this->panel8->TabIndex = 7;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Teal;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->ForeColor = System::Drawing::Color::White;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->Location = System::Drawing::Point(-12, -8);
			this->button7->Name = L"button7";
			this->button7->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button7->Size = System::Drawing::Size(241, 54);
			this->button7->TabIndex = 2;
			this->button7->Text = L"                          Compras";
			this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &Dashboard::button7_Click);
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->btn_inventary);
			this->panel9->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel9->Location = System::Drawing::Point(3, 358);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(219, 36);
			this->panel9->TabIndex = 8;
			// 
			// btn_inventary
			// 
			this->btn_inventary->BackColor = System::Drawing::Color::Teal;
			this->btn_inventary->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_inventary->ForeColor = System::Drawing::Color::White;
			this->btn_inventary->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_inventary.Image")));
			this->btn_inventary->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_inventary->Location = System::Drawing::Point(-12, -8);
			this->btn_inventary->Name = L"btn_inventary";
			this->btn_inventary->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->btn_inventary->Size = System::Drawing::Size(241, 54);
			this->btn_inventary->TabIndex = 3;
			this->btn_inventary->Text = L"                          Inventario";
			this->btn_inventary->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_inventary->UseVisualStyleBackColor = false;
			this->btn_inventary->Click += gcnew System::EventHandler(this, &Dashboard::btn_inventary_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->button8);
			this->panel6->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel6->Location = System::Drawing::Point(3, 400);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(219, 36);
			this->panel6->TabIndex = 9;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::Teal;
			this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button8->ForeColor = System::Drawing::Color::White;
			this->button8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button8.Image")));
			this->button8->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->Location = System::Drawing::Point(-12, -8);
			this->button8->Name = L"button8";
			this->button8->Padding = System::Windows::Forms::Padding(20, 0, 0, 0);
			this->button8->Size = System::Drawing::Size(241, 54);
			this->button8->TabIndex = 2;
			this->button8->Text = L"                             Salir";
			this->button8->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &Dashboard::button8_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &Dashboard::sidebarTimer_ticker);
			// 
			// panel_contenedor
			// 
			this->panel_contenedor->Controls->Add(this->pictureBox3);
			this->panel_contenedor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_contenedor->Location = System::Drawing::Point(222, 0);
			this->panel_contenedor->Name = L"panel_contenedor";
			this->panel_contenedor->Size = System::Drawing::Size(694, 462);
			this->panel_contenedor->TabIndex = 2;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(181, 182);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(405, 112);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 0;
			this->pictureBox3->TabStop = false;
			// 
			// fatherPanelDashboard
			// 
			this->fatherPanelDashboard->Controls->Add(this->panel_contenedor);
			this->fatherPanelDashboard->Controls->Add(this->flowLayoutPanel1);
			this->fatherPanelDashboard->Dock = System::Windows::Forms::DockStyle::Fill;
			this->fatherPanelDashboard->Location = System::Drawing::Point(0, 0);
			this->fatherPanelDashboard->Name = L"fatherPanelDashboard";
			this->fatherPanelDashboard->Size = System::Drawing::Size(916, 462);
			this->fatherPanelDashboard->TabIndex = 1;
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(916, 462);
			this->Controls->Add(this->fatherPanelDashboard);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Dashboard";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Dashboard";
			this->flowLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel_users->ResumeLayout(false);
			this->panel7->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel_contenedor->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->fatherPanelDashboard->ResumeLayout(false);
			this->ResumeLayout(false);

		}
		
		template<class T>
		void AbrirPanel(T formChild) {
			if (this->panel_contenedor->Controls->Count > 0) {
				this->panel_contenedor->Controls->RemoveAt(0);
			}
			formChild->TopLevel = false;
			formChild->Dock = DockStyle::Fill;
			this->panel_contenedor->Controls->Add(formChild);
			this->panel_contenedor->Tag = formChild;
			formChild->Show();
		}

#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::Home);
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::UserClients);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::Productos);
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void sidebarTimer_ticker(System::Object^ sender, System::EventArgs^ e) {
		if (sidebarExpand) {
			this->flowLayoutPanel1->Width -= 10;
			if (this->flowLayoutPanel1->Width == this->flowLayoutPanel1->MinimumSize.Width) {
				sidebarExpand = false;
				this->timer1->Stop();
			}
		}
		else {
			this->flowLayoutPanel1->Width += 10;
			if (this->flowLayoutPanel1->Width == this->flowLayoutPanel1->MaximumSize.Width) {
				sidebarExpand = true;
				this->timer1->Stop();
			}
		}
	}
	private: System::Void menuButton_click(System::Object^ sender, System::EventArgs^ e) {
		this->timer1->Start();
	}
	private: System::Void mouseHover_In(System::Object^ sender, System::EventArgs^ e) {
		this->pictureBox2->Cursor = Cursors::Hand;
		this->button1->Cursor = Cursors::Hand;
		this->button2->Cursor = Cursors::Hand;
		this->button3->Cursor = Cursors::Hand;
		this->button4->Cursor = Cursors::Hand;
		this->button_usuarios->Cursor = Cursors::Hand;
		this->button6->Cursor = Cursors::Hand;
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::Pagos);
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::Reportes(this->userSess));
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::Usuarios);
	}
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::Compras);
	}
	private: System::Void btn_inventary_Click(System::Object^ sender, System::EventArgs^ e) {
		this->AbrirPanel(gcnew QuickShop::Inventary);
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
