#include <iostream>
#include <fstream>
#include <string>
#include "MyForm.h"
#include "Dashboard.h"

void CheckFileExistsOrCreate(const std::string& filePath) {
	std::ifstream file(filePath);
	if (file.good()) {
		file.close();
	}
	else {
		// El archivo no existe, se intenta crear
		std::ofstream createFile(filePath);
		if (createFile.is_open()) {
			createFile.close();
		}
		else {
			MessageBox::Show("Error al crear datos", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}


using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(cli::array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	std::string usersFile = "users.csv";
	std::string productFile = "product.csv";
	std::string purchasesFile = "purchases.csv";
	std::string clientsFile = "clients.csv";
	std::string paymentsFile = "payments.csv";

	CheckFileExistsOrCreate(usersFile);
	CheckFileExistsOrCreate(productFile);
	CheckFileExistsOrCreate(purchasesFile);
	CheckFileExistsOrCreate(clientsFile);
	CheckFileExistsOrCreate(paymentsFile);

	QuickShop::MyForm form;
	QuickShop::Dashboard dashboardForm;
	//ACTIVARform.ShowDialog();
	dashboardForm.ShowDialog();

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
