using namespace std;

template<class T>
struct nodo{
	T dato;
	int izq;
	int der;
};

class Empleado {

	private:
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
		// lista de los hijos;
		string nom_sucursal;

	public:
		Empleado();
		~Empleado();

		// Persistencia
		bool guardar();
		bool obtener(int);

		// Getters y Setters
};

Empleado::Empleado(){

}

Empleado::~Empleado(){

}