#pragma once

using namespace System;

public ref class User {
	public:
		String^ name;
		String^ email;
		bool operador = false;
		bool admin = false;
		bool user = false;
		User(String^ name, String^ email, bool operador, bool admin, bool user) {
			this->name = name;
			this->email = email;
			this->operador = operador;
			this->admin = admin;
			this->user = user;
		}
};