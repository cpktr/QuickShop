#pragma once

using namespace System;

public ref class User {
	public:
		String^ name;
		String^ email;
		bool operador = false;
		bool admin = false;
		bool user = false;
};