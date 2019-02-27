#include"../datos/DB.h"

#ifndef EMPLEADO_H
#define EMPLEADO_H


class Empleado {
	struct datos{
		string nombre;
		string apellido;
		string tipo_id;
		int num_id;
		char sexo;
		int celular;
		int telefono;
		string email;
		string fecha_naci;
		int edad; // calcular a partir de la fecha
		string ciudad_naci;
		string pais_naci;
		string ciudad;
		string direccion;
		string barrio;
		string actividad_lab;
		char tiene_hijos;
		int num_hijos;
		string nom_sucursal;

		int sigNombre;
		int sigApellido;

		int sigTipo_id;
		int sigNum_id;

		int sigSexo;

		int sigEmail;
		int sigFecha_naci;
		int sigEdad;
		int sigCiudad_naci;
		int sigPais_naci;
		int sigCiudad;
		int sigBarrio;

		int sigActividad;

		int sigTiene_hijos;
		int sigNum_hijos;
		int hijos;

		int sigSucursal;
	};

	/*
	Cabezas

	Nombre
	[0] nombre
	[1] apellido

	Tipo id
	[0] CC
	[1] CE
	[2] TI
	[3] identificacion

	Sexo
	[0] Masculino
	[1] Femenino
	
	Informacion
	[0] email
	[1] fecha_nacimiento
	[2] edad
	[3] ciudad_nacimiento
	[4] pais_nacimiento
	[5] ciudad
	[6] barrio

	Actividad laboral
	[0] Ingenieria
	[1] Ciencias
	[2] Artes
	[3] Otros
	
	Hijos
	[0] Con hijos
	[1] Sin hijos
	[2] Numero de hijos
	[3] Hijos
	
	Sucursales
	[0] Sucursal 1 
	[1] Sucursal 2
	[2] Sucursal 3
	[3] Sucursal 4
	[4] Sucursal 5
	[5] Sucursal 6
	[6] Sucursal 7
	[7] Sucursal 8
	[8] Sucursal 9
	[9] Sucursal 10
	*/
 
	int *cabezaNombre;
	int *cabezaId;
	int *cabezaSexo;
	int *cabezaInformacion;
	int *cabezaActividad;
	int *cabezaHijos;
	int *cabezaSucursales;

	datos **arregloSucursales;

	int tam;
	int posAct;
	

	DB db;

	public:
		Empleado();
		~Empleado();
		
		void insertarNombre(string);
		void insertarDireccion(string);
		void insertarBarrio(string);
		void insertarNombre_gerente(string);

		bool insertarEmpleado(string*);
		void borrarEmpleado(int);
		bool vacia();
		bool llena();
		string* obtenerRegistro(int);

		string** getDatos();

		int* llenarCabezas(int *arreglo, int tam){
			for(int i=0; i<tam; i++)
				arreglo[i] = 0;

			return arreglo;
		}

		void imprimir(){
			for(int i=0; i<posAct; i++){
				cout << i << " ";
				cout << arregloSucursales[i]->nombre << " ";
				cout << arregloSucursales[i]->direccion << " ";
				cout << arregloSucursales[i]->barrio << " ";
				cout << arregloSucursales[i]->nombre_gerente << " ";
				cout << arregloSucursales[i]->sigNombre << " ";
				cout << arregloSucursales[i]->sigDireccion << " ";
				cout << arregloSucursales[i]->sigBarrio << " ";
				cout << arregloSucursales[i]->sigNombre_gerente << " ";
				cout << endl;
			}
		}
};

Empleado::Empleado(){
	db.setArchivo("Empleados.txt");
	string **datosArchivo = db.leer_todo(); //Se obtienen los datos del archivo Sucursales.txt

	tam = db.getNumLineas() * 2; // el tamaño del arreglo es igual a el numero de lineas del archivo * 2

	arregloEmpleados = new datos*[tam];  // Se instancia el arreglo
	posAct = 0;

	// Instanciacion de las cabezas
	cabezaNombre = new int[2];
	cabezaNombre = llenarCabezas(cabezaNombre, 2);
	cabezaId = new int[4];
	cabezaId = llenarCabezas(cabezaId, 4);
	cabezaSexo = new int[2];
	cabezaSexo = llenarCabezas(cabezaSexo, 2);
	cabezaInformacion = new int[7];
	cabezaInformacion = llenarCabezas(cabezaInformacion, 7);
	cabezaActividad = new int[4];
	cabezaActividad = llenarCabezas(cabezaActividad, 4);
	cabezaHijos = new int[4];
	cabezaHijos = llenarCabezas(cabezaHijos, 4);
	cabezaSucursales = new int[10];
	cabezaSucursales = llenarCabezas(cabezaSucursales, 10);


	// Creacion nodo de control
	datos *cabecera = new datos; // nodo de control
	// Se llena el nodo(datos) con datos de control para la insercion posterior
	cabecera->nombre = "zz";
	cabecera->apellido = "zz";
	cabecera->tipo_id = "CC";
	cabecera->num_id = 0;
	cabecera->sexo = "M";
	cabecera->email = "zz";
	cabecera->fecha_naci = "00/00/0000";
	cabecera->edad = 0;
	cabecera->ciudad_naci = "zz";
	cabecera->pais_naci = "zz";
	cabecera->ciudad = "zz";
	cabecera->barrio = "zz";
	cabecera->actividad_lab = "zz";
	cabecera->tiene_hijos = 'N';
	cabecera->num_hijos = 0;
	cabecera->nom_sucursal = "zz";

	cabecera->sigNombre = -1;
	cabecera->sigApellido = -1;
	cabecera->sigTipo_id = -1;
	cabecera->sigNum_id = -1;
	cabecera->sigSexo = -1;
	cabecera->sigEmail = -1;
	cabecera->sigFecha_naci = -1;
	cabecera->sigEdad = -1;
	cabecera->sigCiudad_naci = -1;
	cabecera->sigPais_naci = -1;
	cabecera->sigCiudad = -1;
	cabecera->sigBarrio = -1;
	cabecera->sigActividad = -1;
	cabecera->sigTiene_hijos = -1;
	cabecera->sigNum_hijos = -1;
	cabecera->hijos = 0;
	cabecera->sigSucursal = -1;
	cabecera->sigNombre_gerente = -1;
	
	arregloEmpleados[0] = cabecera; // se inserta en el arreglo
	
	posAct = 1; // inicia en 1 para empezar a insertar despues de la pos de control

	
	// Se guardan los datos del archivo en la estructura
	for(int i=0; i<db.getNumLineas(); i++){
		//llamar funcion insertar
	}
}

Empleado::~Empleado(){}

string** Empleado::getDatos(){
	return db.leer_todo();
}

// Pasar arreglo de tam 4
bool Empleado::insertarEmpleado(string *registro){
	datos *nuevo = new datos;
	nuevo->nombre = registro[0];
	nuevo->direccion = registro[1];
	nuevo->barrio = registro[2];
	nuevo->nombre_gerente = registro[3];

	if(!llena()){

		arregloSucursales[posAct] = new datos;
		arregloSucursales[posAct] = nuevo;

		insertarNombre(nuevo->nombre);
		insertarDireccion(nuevo->direccion);
		insertarBarrio(nuevo->barrio);
		insertarNombre_gerente(nuevo->nombre_gerente);

		posAct++;
		return true;
	}

	return false;
}

void Empleado::insertarNombre(string nombre){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[0]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(nombre > arregloSucursales[sig]->nombre){
		ant = sig;
		sig = arregloSucursales[sig]->sigNombre;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigNombre = sig;
	
	if(pri){		
		arregloCabezas[0] = posAct;
	}else{
		arregloSucursales[ant]->sigNombre = posAct;
	}
}

void Empleado::insertarDireccion(string direccion){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[1]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(direccion > arregloSucursales[sig]->direccion){
		ant = sig;
		sig = arregloSucursales[sig]->sigDireccion;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigDireccion = sig;
	
	if(pri){		
		arregloCabezas[1] = posAct;
	}else{
		arregloSucursales[ant]->sigDireccion = posAct;
	}
}

void Empleado::insertarBarrio(string barrio){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[2]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(barrio > arregloSucursales[sig]->barrio){
		ant = sig;
		sig = arregloSucursales[sig]->sigBarrio;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigBarrio = sig;
	
	if(pri){		
		arregloCabezas[2] = posAct;
	}else{
		arregloSucursales[ant]->sigBarrio = posAct;
	}
}

void Empleado::insertarNombre_gerente(string nombre_gerente){
	int ant = 0; // posicion anterior a la nueva
	int sig = arregloCabezas[3]; // posicion siguiente a la nueva
	bool pri = true; 
	
	while(nombre_gerente > arregloSucursales[sig]->nombre_gerente){
		ant = sig;
		sig = arregloSucursales[sig]->sigNombre_gerente;
		pri = false;
	}
	
	arregloSucursales[posAct]->sigNombre_gerente = sig;
	
	if(pri){		
		arregloCabezas[3] = posAct;
	}else{
		arregloSucursales[ant]->sigNombre_gerente = posAct;
	}
}

void Empleado::borrarEmpleado(int pos){

}

bool Empleado::vacia(){
	return posAct == 0;
}

bool Empleado::llena(){
	return posAct == tam;
}

#endif