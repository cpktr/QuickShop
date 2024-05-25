#include <iostream>
#include <fstream>
#include <string>
#include "MyForm.h"
#include "Dashboard.h"
#include "Reportes.h"

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

void existUser() {
	std::ifstream usuaa("users.csv");

	if (!usuaa.is_open()) {
		MessageBox::Show("Error al abrir el archivo");
	}
	else {
		std::string line;
		bool isEmpty = true;

		// Check if the file has any content
		if (getline(usuaa, line) && !line.empty()) {
			isEmpty = false;
		}
		usuaa.close();

		if (isEmpty) {
			StreamWriter^ writer = gcnew StreamWriter("users.csv");
			String^ message = String::Format("{0},{1},{2},{3},{4},{5},{6},{7},{8},{9}",
				"1", "admin", "admin",
				"quickSadmin", "Administrador", "0000000000000",
				"00000000", "admin@gmail.com", "Guatemala", "qs123");
			writer->WriteLine(message);
			writer->Close();
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
	std::string inventaryFile = "inventary.csv";

	CheckFileExistsOrCreate(usersFile);
	CheckFileExistsOrCreate(productFile);
	CheckFileExistsOrCreate(purchasesFile);
	CheckFileExistsOrCreate(clientsFile);
	CheckFileExistsOrCreate(paymentsFile);
	CheckFileExistsOrCreate(inventaryFile);

	existUser();

	QuickShop::MyForm form;
	QuickShop::Dashboard dashboardForm;
	form.ShowDialog();

	User^ user = form.userLogin;
	if (user != nullptr) {
		QuickShop::Dashboard dashboardForm(user);
		QuickShop::Reportes reportsForm(user);
		dashboardForm.ShowDialog();
		//MessageBox::Show("Succesfully", "Success", MessageBoxButtons::OK);
	}
	else {
		//MessageBox::Show("Error", "Error", MessageBoxButtons::OK);
	}
}
