#include <iostream>
#include <cstring>
#include <string>

class Estudiante {
public:
    char nombre[50];
    char apellido[50];
    float notas[10];
    int numNotas;

    Estudiante(const char* n, const char* a) {
        strncpy(nombre, n, 49);
        nombre[49] = '\0';
        strncpy(apellido, a, 49);
        apellido[49] = '\0';
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

    void almacenarEstudiante(const char* n, const char* a) {
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

    Estudiante* buscarEstudiante(const char* nombre) {
        NodoEstudiante* actual = inicio;
        while (actual != nullptr) {
            if (strcmp(actual->datos->nombre, nombre) == 0) {
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

    Profesor(std::string n) {
        nombre = n;
    }

    void anadirEstudiante() {
        char nombre[50];
        char apellido[50];
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
        char nombre[50];
        float nota;
        std::cout << "Nombre del estudiante para anadir nota: ";
        std::cin >> nombre;

        Estudiante* est = miClase.buscarEstudiante(nombre);
        if (est != nullptr) {
            std::cout << "Introduce la nota: ";
            std::cin >> nota;
            est->agregarNota(nota);
            std::cout << "Nota agregada." << std::endl;
        } else {
            std::cout << "Estudiante no encontrado." << std::endl;
        }
    }
};

void menuProfesor(Profesor& prof) {
    int opcion = 0;
    do {
        std::cout << "\n--- MENU PROFESOR: " << prof.nombre << " ---" << std::endl;
        std::cout << "1. Almacenar nuevo estudiante" << std::endl;
        std::cout << "2. Visualizar datos de la clase" << std::endl;
        std::cout << "3. Agregar nota a estudiante" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                prof.anadirEstudiante();
                break;
            case 2:
                prof.verClase();
                break;
            case 3:
                prof.anadirNota();
                break;
            case 4:
                std::cout << "Saliendo..." << std::endl;
                break;
            default:
                std::cout << "Opcion no valida." << std::endl;
        }
    } while (opcion != 4);
}

int main() {
    Profesor prof("Jorge Garcia");
    menuProfesor(prof);
    return 0;
}