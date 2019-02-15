using namespace std;

class Sucursal {
	private:
		string nombre;
		string direccion;
		string barrio;
		string nombre_gerente;

	public:
		Sucursal();
		~Sucursal();

		// Getters y Setters
		string getNombre();
		void setNombre(string);
		
		string getDireccion();
		void setDireccion(string);

		string getBarrio();
		void setBarrio(string);

		string getNombre_gerente();
		void setNombre_gerente(string);	
};

Sucursal::Sucursal(){}

Sucursal::~Sucursal(){}

// Getters y Setters
string Sucursal::getNombre(){
	return this->nombre;
}

void Sucursal::setNombre(string nombre){
	this->nombre = nombre;
}

string Sucursal::getDireccion(){
	return this->direccion;
}

void Sucursal::setDireccion(string direccion){
	this->direccion = direccion;
}

string Sucursal::getBarrio(){
	return this->barrio;
}

void Sucursal::setBarrio(string barrio){
	this->barrio = barrio;
}

string Sucursal::getNombre_gerente(){
	return this->nombre_gerente;
}

void Sucursal::setNombre_gerente(string nombre_gerente){
	this->nombre_gerente = nombre_gerente;
}