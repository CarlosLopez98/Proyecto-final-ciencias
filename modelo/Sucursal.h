#include"../datos/DB.h"

class Sucursal {
	struct datos{
		string nombre;
		string direccion;
		string barrio;
		string nombre_gerente;

		int sigNombre;
		int sigDireccion;
		int sigBarrio;
		int sigNombre_gerente;
	};

	/*
	Cabezas
	[0] nombre
	[1] direccion
	[2] barrio
	[3] nombre gerente
	*/

	int *arregloCabezas;
	datos **arregloSucursales;

	int tam;
	int posAct;
	

	DB db;

	public:
		Sucursal();
		~Sucursal();
		
		void insertarNombre(string);
		void insertarDireccion(string);
		void insertarBarrio(string);
		void insertarNombre_gerente(string);

		bool insertarSucursal(string*);
		void borrarElemento(int);
		bool vacia();
		bool llena();
		char* obtenerElemento(int, int);
};

Sucursal::Sucursal(){
	db.setArchivo("Sucursales.txt");
	string **datosArchivo = db.leer_todo(); //Se obtienen los datos del archivo Sucursales.txt

	tam = db.getNumLineas() * 2; // el tamaño del arreglo es igual a el numero de lineas del archivo * 2

	arregloSucursales = new datos*[tam];  // Se instancia el arreglo
	posAct = 0;

	arregloCabezas = new int[4];
	for(int i=0; i<4; i++){
		arregloCabezas[i] = 0; // Se llena el arreglo de las cabezas con ceros
	}

	// Creacion nodo de control
	datos *cabecera = new datos; // nodo de control
	// Se llena el nodo(datos) con datos de control para la insercion posterior
	cabecera->nombre = "zz";
	cabecera->direccion = "zz";
	cabecera->barrio = "zz";
	cabecera->nombre_gerente = "zz";
	cabecera->sigNombre = -1;
	cabecera->sigDireccion = -1;
	cabecera->sigBarrio = -1;
	cabecera->sigNombre_gerente = -1;
	
	arregloSucursales[0] = cabecera; // se inserta en el arreglo
	
	posAct = 1; // inicia en 1 para empezar a insertar despues de la pos de control

	
	// Se guardan los datos del archivo en la estructura
	for(int i=0; i<db.getNumLineas; i++){
		//llamar funcion insertar
	}
}

Sucursal::~Sucursal(){}

// Pasar arreglo de tam 4
bool Sucursal::insertarSucursal(string *registro){
	datos *nuevo = new datos;
	nuevo->nombre = registro[0];
	nuevo->direccion = registro[1];
	nuevo->barrio = registro[2];
	nuevo->nombre_gerente = registro[3];

	if(!llena()){

		arregloSucursales[posAct] = new Datos;
		arregloSucursales[posAct] = nuevo;

	}
}

bool Sucursal::vacia(){
	return posAct == 0;
}

bool Sucursal::llena(){
	return posAct == tam;
}