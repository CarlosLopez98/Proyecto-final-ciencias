#include<fstream>

using namespace std;

class Archivo {

	private:
		string nombre;
		ofstream escritura;
		ifstream lectura;

	public:
		Archivo(string);
		~Archivo();

		int escribir(string);
		string leer();
};

Archivo::Archivo(string nombre){
	this->nombre = nombre;
}

Archivo::~Archivo(){}

int Archivo::escribir(string linea){
	this->escritura.open(this->nombre.c_str(), ios::out);

	if(this->escritura.fail()){
		return 0;
	}

	this->escritura << linea;

	this->escritura.close();

	return 1;
}

const char** Archivo::leer(){
	string linea;

	this->lectura.open(this->nombre.c_str(), ios::in);

	if(this->lectura.fail()){
		return "0";
	}

	while(!this->lectura.eof()){
		getline(this->lectura, linea);
	}
}