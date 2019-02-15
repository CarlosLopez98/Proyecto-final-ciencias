#include<cstdlib>
#include<iostream>

// Controladores
#include"controlador/EmpleadoControlador.h"
#include"controlador/SucursalControlador.h"
#include"controlador/ControladorGeneral.h"
#include"datos/DB.h"

using namespace std;

int main(int argc, char *argv[ ], char *envp[ ]){

	string controlador = "general";
	string accion = "menuPrincipal";

	while(controlador == "" && accion != ""){
		if(controlador == "general"){
			ControladorGeneral con;

			if(accion == "menuPrincipal") con.menuPrincipal(controlador, accion);
			else if(accion == "menuConsulta") con.menuConsulta(controlador, accion);
			else if(accion == "menuRegistro") con.menuRegistro(controlador, accion);
			else accion = "menuPrincipal";

		}else if(controlador == "empleado"){
			EmpleadoControlador con;

			if(accion == "menu") con.menu(controlador, accion);
			else if(accion == "registrar") con.menuRegistro(controlador, accion);
			else accion = "menu";

		}else if(controlador == "sucursal"){
			SucursalControlador con;
		}else{
			controlador = "general";
			accion = "menuPrincipal";
		}
	}


	DB empleados("datos/Sucursales.txt");
	string **datos = empleados.leer_todo();

	for(int i=0; i<empleados.getNumLineas(); i++){
		for(int j=0; j<empleados.getNumCampos(); j++){
			cout << datos[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}