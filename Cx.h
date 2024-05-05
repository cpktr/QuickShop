#pragma once

#include <iostream>
#include <string> // Cambio aquí
#include "Persona.h"

using namespace std;

ref class Cx : public Persona
{
private:
    string^ username;
    string^ type;
    string^ cui;

public:
    Cx(string^ username, string^ type, string^ cui, string^ name, string^ lastname, string^ address, string^ phonenumb, string^ email, string^ password)
        : Persona(name, lastname, address, phonenumb, email, password) {
        this->username = username;
        this->type = type;
        this->cui = cui;
    }

    Cx^ get_usuario() {
        return this;
    }
};
