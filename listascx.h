#pragma once

namespace QuickShop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de listascx
	/// </summary>
	public ref class listascx : public System::Windows::Forms::Form
	{
	public:
		listascx(void)
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
		~listascx()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ formContainer;
	private: System::Windows::Forms::Button^ btn_cancel;
	private: System::Windows::Forms::Button^ btn_saveProduct;






	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::TextBox^ txt_price;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::TextBox^ txt_description;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txt_brand;
	private: System::Windows::Forms::Label^ label7;






	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txt_name;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ inputContainer;
	private: System::Windows::Forms::Panel^ panel14;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txt_id;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->formContainer = (gcnew System::Windows::Forms::Panel());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->btn_saveProduct = (gcnew System::Windows::Forms::Button());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->txt_price = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txt_description = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txt_brand = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txt_name = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->inputContainer = (gcnew System::Windows::Forms::Panel());
			this->panel14 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txt_id = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->formContainer->SuspendLayout();
			this->panel10->SuspendLayout();
			this->panel11->SuspendLayout();
			this->panel8->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel7->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->inputContainer->SuspendLayout();
			this->panel14->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->formContainer);
			this->panel1->Location = System::Drawing::Point(31, 25);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(791, 435);
			this->panel1->TabIndex = 0;
			// 
			// formContainer
			// 
			this->formContainer->Controls->Add(this->btn_cancel);
			this->formContainer->Controls->Add(this->btn_saveProduct);
			this->formContainer->Controls->Add(this->panel10);
			this->formContainer->Controls->Add(this->panel8);
			this->formContainer->Controls->Add(this->panel6);
			this->formContainer->Controls->Add(this->panel2);
			this->formContainer->Controls->Add(this->inputContainer);
			this->formContainer->Location = System::Drawing::Point(4, 49);
			this->formContainer->Margin = System::Windows::Forms::Padding(4);
			this->formContainer->Name = L"formContainer";
			this->formContainer->Size = System::Drawing::Size(356, 382);
			this->formContainer->TabIndex = 3;
			// 
			// btn_cancel
			// 
			this->btn_cancel->BackColor = System::Drawing::Color::Transparent;
			this->btn_cancel->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_cancel->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_cancel->ForeColor = System::Drawing::Color::Teal;
			this->btn_cancel->Location = System::Drawing::Point(95, 329);
			this->btn_cancel->Margin = System::Windows::Forms::Padding(4);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(100, 28);
			this->btn_cancel->TabIndex = 5;
			this->btn_cancel->Text = L"Cancelar";
			this->btn_cancel->UseVisualStyleBackColor = false;
			this->btn_cancel->Visible = false;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &listascx::btn_cancel_Click);
			// 
			// btn_saveProduct
			// 
			this->btn_saveProduct->BackColor = System::Drawing::Color::Teal;
			this->btn_saveProduct->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_saveProduct->FlatAppearance->BorderSize = 0;
			this->btn_saveProduct->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_saveProduct->ForeColor = System::Drawing::Color::White;
			this->btn_saveProduct->Location = System::Drawing::Point(215, 329);
			this->btn_saveProduct->Margin = System::Windows::Forms::Padding(4);
			this->btn_saveProduct->Name = L"btn_saveProduct";
			this->btn_saveProduct->Size = System::Drawing::Size(100, 28);
			this->btn_saveProduct->TabIndex = 4;
			this->btn_saveProduct->Text = L"Guardar";
			this->btn_saveProduct->UseVisualStyleBackColor = false;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->panel11);
			this->panel10->Controls->Add(this->txt_price);
			this->panel10->Controls->Add(this->label11);
			this->panel10->Location = System::Drawing::Point(4, 178);
			this->panel10->Margin = System::Windows::Forms::Padding(4);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(348, 37);
			this->panel10->TabIndex = 3;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->textBox12);
			this->panel11->Controls->Add(this->label12);
			this->panel11->Location = System::Drawing::Point(0, 37);
			this->panel11->Margin = System::Windows::Forms::Padding(4);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(348, 37);
			this->panel11->TabIndex = 2;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(211, 5);
			this->textBox12->Margin = System::Windows::Forms::Padding(4);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(132, 22);
			this->textBox12->TabIndex = 1;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(4, 9);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(51, 16);
			this->label12->TabIndex = 0;
			this->label12->Text = L"Código";
			// 
			// txt_price
			// 
			this->txt_price->Location = System::Drawing::Point(211, 5);
			this->txt_price->Margin = System::Windows::Forms::Padding(4);
			this->txt_price->Name = L"txt_price";
			this->txt_price->Size = System::Drawing::Size(132, 22);
			this->txt_price->TabIndex = 1;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(4, 9);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(46, 16);
			this->label11->TabIndex = 0;
			this->label11->Text = L"Precio";
			// 
			// panel8
			// 
			this->panel8->Controls->Add(this->panel9);
			this->panel8->Controls->Add(this->txt_description);
			this->panel8->Controls->Add(this->label9);
			this->panel8->Location = System::Drawing::Point(4, 132);
			this->panel8->Margin = System::Windows::Forms::Padding(4);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(348, 37);
			this->panel8->TabIndex = 3;
			// 
			// panel9
			// 
			this->panel9->Controls->Add(this->textBox10);
			this->panel9->Controls->Add(this->label10);
			this->panel9->Location = System::Drawing::Point(0, 37);
			this->panel9->Margin = System::Windows::Forms::Padding(4);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(348, 37);
			this->panel9->TabIndex = 2;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(211, 5);
			this->textBox10->Margin = System::Windows::Forms::Padding(4);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(132, 22);
			this->textBox10->TabIndex = 1;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(4, 9);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(51, 16);
			this->label10->TabIndex = 0;
			this->label10->Text = L"Código";
			// 
			// txt_description
			// 
			this->txt_description->Location = System::Drawing::Point(211, 5);
			this->txt_description->Margin = System::Windows::Forms::Padding(4);
			this->txt_description->Name = L"txt_description";
			this->txt_description->Size = System::Drawing::Size(132, 22);
			this->txt_description->TabIndex = 1;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(4, 9);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(79, 16);
			this->label9->TabIndex = 0;
			this->label9->Text = L"Descripción";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->panel7);
			this->panel6->Controls->Add(this->txt_brand);
			this->panel6->Controls->Add(this->label7);
			this->panel6->Location = System::Drawing::Point(4, 86);
			this->panel6->Margin = System::Windows::Forms::Padding(4);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(348, 37);
			this->panel6->TabIndex = 3;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->textBox8);
			this->panel7->Controls->Add(this->label8);
			this->panel7->Location = System::Drawing::Point(0, 37);
			this->panel7->Margin = System::Windows::Forms::Padding(4);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(348, 37);
			this->panel7->TabIndex = 2;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(211, 5);
			this->textBox8->Margin = System::Windows::Forms::Padding(4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(132, 22);
			this->textBox8->TabIndex = 1;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(4, 9);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(51, 16);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Código";
			// 
			// txt_brand
			// 
			this->txt_brand->Location = System::Drawing::Point(211, 5);
			this->txt_brand->Margin = System::Windows::Forms::Padding(4);
			this->txt_brand->Name = L"txt_brand";
			this->txt_brand->Size = System::Drawing::Size(132, 22);
			this->txt_brand->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(4, 9);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(45, 16);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Marca";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->txt_name);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(4, 44);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(348, 37);
			this->panel2->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->textBox4);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Location = System::Drawing::Point(0, 37);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(348, 37);
			this->panel3->TabIndex = 2;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(211, 5);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(132, 22);
			this->textBox4->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 9);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(51, 16);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Código";
			// 
			// txt_name
			// 
			this->txt_name->Location = System::Drawing::Point(211, 5);
			this->txt_name->Margin = System::Windows::Forms::Padding(4);
			this->txt_name->Name = L"txt_name";
			this->txt_name->Size = System::Drawing::Size(132, 22);
			this->txt_name->TabIndex = 1;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(4, 9);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Nombre";
			// 
			// inputContainer
			// 
			this->inputContainer->Controls->Add(this->panel14);
			this->inputContainer->Controls->Add(this->txt_id);
			this->inputContainer->Controls->Add(this->label1);
			this->inputContainer->Location = System::Drawing::Point(4, 4);
			this->inputContainer->Margin = System::Windows::Forms::Padding(4);
			this->inputContainer->Name = L"inputContainer";
			this->inputContainer->Size = System::Drawing::Size(348, 37);
			this->inputContainer->TabIndex = 0;
			// 
			// panel14
			// 
			this->panel14->Controls->Add(this->textBox2);
			this->panel14->Controls->Add(this->label2);
			this->panel14->Location = System::Drawing::Point(0, 37);
			this->panel14->Margin = System::Windows::Forms::Padding(4);
			this->panel14->Name = L"panel14";
			this->panel14->Size = System::Drawing::Size(348, 37);
			this->panel14->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(211, 5);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 22);
			this->textBox2->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 9);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(51, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Código";
			// 
			// txt_id
			// 
			this->txt_id->Location = System::Drawing::Point(211, 5);
			this->txt_id->Margin = System::Windows::Forms::Padding(4);
			this->txt_id->Name = L"txt_id";
			this->txt_id->Size = System::Drawing::Size(132, 22);
			this->txt_id->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 9);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(51, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Código";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 16.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(9, 13);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(96, 32);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Listas";
			// 
			// listascx
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(862, 493);
			this->ControlBox = false;
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"listascx";
			this->ShowIcon = false;
			this->Text = L"listascx";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->formContainer->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->inputContainer->ResumeLayout(false);
			this->inputContainer->PerformLayout();
			this->panel14->ResumeLayout(false);
			this->panel14->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
