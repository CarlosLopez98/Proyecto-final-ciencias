#include"../general/Header.h"

#ifndef MENUREGISTRO_H
#define MENUREGISTRO_H

using namespace std;

class MenuRegistro {

	public:
		MenuRegistro();
		~MenuRegistro();

		static void mostrar(string&, string&);
};

MenuRegistro::MenuRegistro(){}
MenuRegistro::~MenuRegistro(){}

void MenuRegistro::mostrar(string& controlador, string& accion){
	Header::mostrar();

	cout << "Formulario de registro\n" << endl;

	cout << "Nombre: ";
	string nombre;
	cin >> nombre;

	cout << "Apellido: ";
	string apellido;
	cin >> apellido;

	controlador = "general";
	accion = "menuRegistro";

}

#endif