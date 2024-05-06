#include "MyForm.h"
#include "Dashboard.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	QuickShop::MyForm form;
	QuickShop::Dashboard dashboardForm;
	//dashboardForm.ShowDialog();
	//Application::Run(% form);
	form.ShowDialog();
	User^ user = form.user;

	if (user != nullptr) {
		MessageBox::Show("Succesfully", "Success", MessageBoxButtons::OK);
	}
	else {
		//MessageBox::Show("Error", "Error", MessageBoxButtons::OK);
	}
}
