#include <iostream>
#include <string>  // Para std::string
// cstring ya no es necesario

class Estudiante {
public:
    std::string nombre;
    std::string apellido;
    float notas[10];
    int numNotas;

    // El constructor ahora usa std::string
    Estudiante(std::string n, std::string a) {
        nombre = n;
        apellido = a;
        numNotas = 0;
    }

    void agregarNota(float nota) {
        if (numNotas < 10) {
            notas[numNotas++] = nota;
        }
    }

    void mostrarInformacion() const {
        std::cout << "  - Alumno: " << nombre << " " << apellido << std::endl;
        std::cout << "    Notas: ";
        if (numNotas == 0) {
            std::cout << "(Sin notas)";
        }
        for (int i = 0; i < numNotas; ++i) {
            std::cout << notas[i] << " | ";
        }
        std::cout << std::endl;
    }
};

class NodoEstudiante {
public:
    Estudiante* datos;
    NodoEstudiante* siguiente;

    NodoEstudiante(Estudiante* e) {
        datos = e;
        siguiente = nullptr;
    }
};

class Clase {
public:
    NodoEstudiante* inicio;
    int numInscritos;

    Clase() {
        inicio = nullptr;
        numInscritos = 0;
    }

    ~Clase() {
        NodoEstudiante* actual = inicio;
        while (actual != nullptr) {
            NodoEstudiante* aBorrar = actual;
            actual = actual->siguiente;
            delete aBorrar->datos;
            delete aBorrar;
        }
    }

    // Acepta std::string
    void almacenarEstudiante(std::string n, std::string a) {
        Estudiante* nuevoEst = new Estudiante(n, a);
        NodoEstudiante* nuevoNodo = new NodoEstudiante(nuevoEst);
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
        numInscritos++;
    }

    void visualizarDatos() {
        std::cout << "\n--- Datos de la Clase ---" << std::endl;
        std::cout << "Numero de inscritos: " << numInscritos << std::endl;
        std::cout << "Listado de estudiantes:" << std::endl;

        NodoEstudiante* actual = inicio;
        while (actual != nullptr) {
            actual->datos->mostrarInformacion();
            actual = actual->siguiente;
        }
    }

    // Acepta std::string y usa el operador ==
    Estudiante* buscarEstudiante(std::string nombre) {
        NodoEstudiante* actual = inicio;
        while (actual != nullptr) {
            if (actual->datos->nombre == nombre) {
                return actual->datos;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }
};

class Profesor {
public:
    std::string nombre;
    Clase miClase;

    Profesor(std::string nombre) {
        this->nombre = nombre;
    }

    void anadirEstudiante() {
        // Usa std::string para leer la entrada
        std::string nombre;
        std::string apellido;
        std::cout << "Introduce el nombre del estudiante: ";
        std::cin >> nombre;
        std::cout << "Introduce el apellido del estudiante: ";
        std::cin >> apellido;
        miClase.almacenarEstudiante(nombre, apellido);
        std::cout << "Estudiante " << nombre << " almacenado." << std::endl;
    }

    void verClase() {
        miClase.visualizarDatos();
    }

    void anadirNota() {
        // Usa std::string para leer la entrada
        std::string nombre;
        float nota;
        std::cout << "Nombre del estudiante para anadir nota: ";
        std::cin >> nombre;

        Estudiante* estudiante = miClase.buscarEstudiante(nombre);
        if (estudiante != nullptr) {
            std::cout << "Introduce la nota: ";
            std::cin >> nota;
            estudiante->agregarNota(nota);
            std::cout << "Nota agregada." << std::endl;
        } else {
            std::cout << "Estudiante no encontrado." << std::endl;
        }
    }
};

void menuProfesor(Profesor* prof) {
    int opcion = 0;
    do {
        std::cout << "\n--- MENU PROFESOR: " << prof->nombre << " ---" << std::endl;
        std::cout << "1. Almacenar nuevo estudiante" << std::endl;
        std::cout << "2. Visualizar datos de la clase" << std::endl;
        std::cout << "3. Agregar nota a estudiante" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                prof->anadirEstudiante();
                break;
            case 2:
                prof->verClase();
                break;
            case 3:
                prof->anadirNota();
                break;
            case 4:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    } while (opcion != 4);
}
/*
int main() {
    Profesor* prof = new Profesor("Jorge Garcia");

    menuProfesor(prof);

    delete prof;
    prof = nullptr;

    return 0;
}*/