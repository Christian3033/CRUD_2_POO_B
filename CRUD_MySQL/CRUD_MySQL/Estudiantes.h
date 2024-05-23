#pragma once
#include <iostream>
using namespace std;
class Estudiantes{
protected: string codigo, nombres, apellidos, direccion, fecha_nacimiento;
		 int telefono = 0;
		 // costructor
public:
	Estudiantes() {

	}

	Estudiantes(string cod, string nom, string ape, string dir, int tel, string fn) {
	
		codigo = cod;
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
		fecha_nacimiento = fn;
	}

};

