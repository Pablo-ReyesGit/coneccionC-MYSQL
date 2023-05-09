#pragma once
#include<iostream>
using namespace std;
class persona
{
protected:
	string nombre, apellido, direccion, fecha_nacimiento;
	int telefono=0;

protected:
	persona(){
	}
	persona(string nom, string ape, string dir, int tel, string fn) {
		nombre = nom;
		apellido = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
	}

	void mostrar() {

	}
};

