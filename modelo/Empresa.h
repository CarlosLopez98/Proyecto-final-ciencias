#include"Sucursal.h"

#ifndef EMPRESA_H
#define EMPRESA_H

class Empresa {

	private:
		Lista<Sucursal> sucursales;

	public:
		Empresa();
		~Empresa();	

};

Empresa::Empresa(){
	sucursales = new Lista<Sucursal>;
}

#endif