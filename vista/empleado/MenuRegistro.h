#include"../general/Header.h"

#ifndef MENUREGISTRO_H
#define MENUREGISTRO_H

using namespace std;

class MenuRegistro {

	public:
		MenuRegistro();
		~MenuRegistro();

		void mostrar();
}

MenuRegistro::MenuRegistro();
MenuRegistro::~MenuRegistro();

void MenuRegistro::mostrar(){
	Header::mostrar();

	cout << "Formulario de registro\n" << endl;

	cout << "Nombre: ";
	string nombre;
	cin >> nombre;

}

#endif