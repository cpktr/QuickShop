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
	form.ShowDialog();
	//dashboardForm.ShowDialog();

	User^ user = form.userLogin;
	if (user != nullptr) {
		QuickShop::Dashboard dashboardForm(user);
		dashboardForm.ShowDialog();
		//MessageBox::Show("Succesfully", "Success", MessageBoxButtons::OK);
	}
	else {
		//MessageBox::Show("Error", "Error", MessageBoxButtons::OK);
	}
}
