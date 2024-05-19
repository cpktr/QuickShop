#pragma once

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
	private: System::Windows::Forms::Panel^ panel_cont;

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
			this->navbar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->sidebar = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel_cont = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// navbar
			// 
			this->navbar->Dock = System::Windows::Forms::DockStyle::Top;
			this->navbar->Location = System::Drawing::Point(0, 0);
			this->navbar->Name = L"navbar";
			this->navbar->Size = System::Drawing::Size(1978, 100);
			this->navbar->TabIndex = 0;
			// 
			// sidebar
			// 
			this->sidebar->Dock = System::Windows::Forms::DockStyle::Left;
			this->sidebar->Location = System::Drawing::Point(0, 100);
			this->sidebar->Name = L"sidebar";
			this->sidebar->Size = System::Drawing::Size(200, 960);
			this->sidebar->TabIndex = 1;
			// 
			// panel_cont
			// 
			this->panel_cont->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_cont->Location = System::Drawing::Point(200, 100);
			this->panel_cont->Name = L"panel_cont";
			this->panel_cont->Size = System::Drawing::Size(1778, 960);
			this->panel_cont->TabIndex = 2;
			// 
			// vistacx
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(16, 31);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1978, 1060);
			this->Controls->Add(this->panel_cont);
			this->Controls->Add(this->sidebar);
			this->Controls->Add(this->navbar);
			this->Name = L"vistacx";
			this->Text = L"vistacx";
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
