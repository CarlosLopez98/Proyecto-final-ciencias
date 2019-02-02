#include<fstream>

using namespace std;

class Archivo {

	private:
		string nombre;
		ofstream fichero;

	public:
		Archivo(string);
		~Archivo();
};

Archivo::Archivo(string nombre){
	this->nombre = nombre;
	fichero.open("Empleados.txt", ios::out);

	if(archivo.fail()){
		cout << "No se pudo abrir el archivo" << endl;
		exit(1);
	}
}