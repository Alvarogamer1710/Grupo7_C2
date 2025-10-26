
#include <iostream>
#include <string>
#include <vector>

//Creamos clase usuario
class Usuario {
public:
	//Declaramos todas las variables
	int id;
	std::string nombre;
	std::string apellido;
	std::string numeroUsuario;
	bool esAdmin;

	//Creamos el constructor de la clase para inicializar todas las variables
	Usuario(int id_, const std::string& n, const std::string& a, const std::string& num, bool admin) {
		this->id = id_;
		this->nombre = n;
		this->apellido = a;
		this->numeroUsuario = num;
		this->esAdmin = admin;
	}
	//Creamos la funcion mostrar para mostrar los datos registrados de usuario
	void mostrar() const {
		std::cout << "------------------------------------\n";
		std::cout << " ID: " << id << "\n";
		std::cout << " Nombre y apellido: " << nombre << " " << apellido << "\n";
		std::cout << " NC:meroUsuario: " << numeroUsuario <<  "\n";
		std::cout << " Rol: " << (esAdmin ? "Administrador" : "Usuario ") << "\n";
		std::cout << "------------------------------------\n";
	}
};

//Creamos la clase SistemaUsuarios la cual se encarga de pedir los datos al usuario e inicializar los ID
class SistemaUsuarios {
public:
	//Creamos contador para llevar cuenta del numero total de usuarios, y el almacen en memoria
	int Contador;
	std::vector<Usuario> usuarios;
	//Inicializamos el contador
	SistemaUsuarios() {
		Contador = 0;
	}
	//Creamos la funcion que crea el objeto del usuario, pidiendo los datos por pantalla y asignando el ID
	Usuario crearUsuario() {
		std::string nombre, apellido, numero;
		bool esAdmin;
		std::cout << "Introduce el nombre: ";
		std::cin >> nombre;
		std::cout << "Introduce el apellido: ";
		std::cin >> apellido;
		std::cout << "Introduce el numero de usuario: ";
		std::cin >> numero;
		int rol;
		std::cout << "Introduce el rol (1 = Administrador, 0 = Usuario normal): ";
		std::cin >> rol;
		esAdmin = (rol == 1);
		Contador++; //Incrementa el contador para crear nuevo ID
		Usuario nuevo(Contador, nombre, apellido, numero, esAdmin);
		return nuevo;
	}
	//Creamos los usuarios, inicializando el objeto y introduciendolo en el vector
	void alta() {

		Usuario u = crearUsuario();
		usuarios.push_back(u);
	}
	//Creamos funcion que muestra si hay o no usuarios, y tambien muestra sus datos
	void listar() {
		if(usuarios.empty()) {
			std::cout << "\nNo hay usuarios todavia\n";
			return;
		}
		std::cout << "\n=== LISTA DE USUARIOS ===\n";
		for (const auto& u : usuarios) {
			u.mostrar();
		}
	}
	//Creamos funcion para dar eliminar del vector usuario con ID igual
	void baja() {
		int id;
		std::cout << "ID a eliminar: ";
		std::cin >> id;
		bool encontrado = false;
		for (size_t i = 0; i < usuarios.size(); ++i) {
			if (usuarios[i].id == id) {
				usuarios.erase(usuarios.begin() + i);
				std::cout << "Usuario eliminado.\n";
				encontrado = true;
				break;
			}
		}
	}

	void actualizar() {
		int id;
		std::cout << "ID a actualizar: ";
		std::cin >> id;
        bool encontrado = false;
        for (auto& u : usuarios) {
            if (u.id == id) {
                encontrado = true;
                std::cout << "Nuevo nombre: ";
                std::cin >> u.nombre;
                std::cout << "Nuevo apellido: ";
                std::cin >> u.apellido;
                std::cout << "Nuevo numero de usuario: ";
                std::cin >> u.numeroUsuario;
                int rol;
                std::cout << "Nuevo rol (1=Admin, 0=Usuario): ";
                std::cin >> rol;
                u.esAdmin = (rol == 1);
                std::cout << "Usuario actualizado correctamente.\n";
                break;
            }
        }
        if (!encontrado) std::cout << "No se encontró ese ID.\n";
	}

	//Creamos funcion para mostrar el menu: principal mediante un bucle con distintas opciones
	void menuEstudiante() {
		int opcion = 0;
		do {
			std::cout << "\n--- MENU ---\n";
			std::cout << "1) Alta de usuario\n";
			std::cout << "2) Listar usuarios\n";
			std::cout << "3) Eliminar usuarios\n";
			std::cout << "4) Actualizar usuarios\n";
			std::cout << "5) Salir\n\n";
			std::cout << "Elige opcion: ";
			std::cin >> opcion;

			switch(opcion) {
			case 1:
				this->alta();
				break;
			case 2:
				this->listar();
				break;
			case 3:
			    this->baja();
				break;
			case 4:
			    this->actualizar();
			    break;
			case 5:
			    break;
			default:
				std::cout << "Opcion invalida" << std::endl;
			}
		} while (opcion != 5);
	}
};

int main()
{
	//Creamos objeto del sistema para poder llamar a la funcion Menu:
	SistemaUsuarios sistema;
	sistema.menuEstudiante();
	return 0;
}