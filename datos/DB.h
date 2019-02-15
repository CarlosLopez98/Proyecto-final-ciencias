#include<fstream>

#ifndef DB_H
#define DB_H

using namespace std;

class DB {

	private:
		string nombre;
		ofstream escritura;
		ifstream lectura;

		int columnas;
		int filas;

	public:
		DB(string);
		~DB();

		bool escribir(string);
		string** leer_todo();
		string* leer(int);
		int getNumLineas();
		int getNumCampos();
};

DB::DB(string nombre){
	this->nombre = nombre;
	this->filas = this->getNumLineas();
	this->columnas = this->getNumCampos(); 
}

DB::~DB(){}

bool DB::escribir(string linea){
	this->escritura.open(this->nombre.c_str(), ios::app);

	if(this->escritura.fail()){
		return false;
	}

	this->escritura << linea;

	this->escritura.close();

	return true;
}

string** DB::leer_todo(){
	string campo;

	this->lectura.open(this->nombre.c_str(), ios::in);

	if(this->lectura.fail()){
		return NULL;
	}

	int campos_aux = 0;
	int lineas_aux = 0;

	string **datos = new string*[filas];
	for(int i=0; i<filas; i++) datos[i] = new string[columnas];
	
	while(!this->lectura.eof()){
		this->lectura >> campo;

		if(campo != "|"){
			if(campos_aux == columnas){
				lineas_aux++;
				campos_aux = 0;
			}

			datos[lineas_aux][campos_aux] = campo;

			if(campos_aux < columnas){
				campos_aux++;
			}
		}
	}

	this->lectura.close();

	return datos;
}

string* DB::leer(int fila=0){
	string linea;

	this->lectura.open(this->nombre.c_str(), ios::in);

	if(this->lectura.fail()){
		return NULL;
	}

	while(!this->lectura.eof()){
		getline(this->lectura, linea);
	}

	this->lectura.close();
}

int DB::getNumLineas(){
	string linea;

	this->lectura.open(this->nombre.c_str(), ios::in);

	if(this->lectura.fail()){
		return 0;
	}

	int lineas = 0;

	while(!this->lectura.eof()){
		getline(this->lectura, linea);
		lineas++;
	}

	this->lectura.close();

	return lineas;
}

int DB::getNumCampos(){
	string campo;

	this->lectura.open(this->nombre.c_str(), ios::in);

	if(this->lectura.fail()){
		return 0;
	}

	int campos = 0;

	while(!this->lectura.eof()){
		this->lectura >> campo;
		if(campo != "|"){
			campos++;
		}
	}

	this->lectura.close();

	return campos / this->filas;
}
#endif