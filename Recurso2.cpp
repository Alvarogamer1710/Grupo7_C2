#include <iostream>
#include <fstream>
#include <string>

class Documento {
public:
    std::string nombre;
    std::string contenido;
    
    Documento(std::string n) {
        nombre = n;
        contenido = "";
    }
    
    // lee el archivo del disco
    bool cargar() {
        std::ifstream f(nombre);
        if (!f.is_open()) {
            std::cout << "No se pudo abrir el archivo" << std::endl;
            return false;
        }
        
        std::string linea;
        while (std::getline(f, linea)) {
            contenido += linea + "\n";
        }
        f.close();
        return true;
    }
    
    void mostrar() {
        std::cout << "\n--- " << nombre << " ---" << std::endl;
        std::cout << contenido << std::endl;
    }
};

// nodo de la lista de documentos
class Nodo {
public:
    Documento* doc;
    Nodo* sig;
    
    Nodo(Documento* d) {
        doc = d;
        sig = nullptr;
    }
};

class Mochila {
public:
    Nodo* primero;
    int total;
    
    Mochila() {
        primero = nullptr;
        total = 0;
    }
    
    // destructor pa limpiar memoria
    ~Mochila() {
        Nodo* actual = primero;
        while (actual != nullptr) {
            Nodo* temp = actual;
            actual = actual->sig;
            delete temp->doc;
            delete temp;
        }
    }
    
    void agregar() {
        std::string nom;
        std::cout << "Nombre del archivo: ";
        std::cin >> nom;
        
        Documento* d = new Documento(nom);
        
        if (d->cargar()) {
            Nodo* n = new Nodo(d);
            n->sig = primero;
            primero = n;
            total++;
            std::cout << "Archivo cargado" << std::endl;
        } else {
            delete d;
        }
    }
    
    void listar() {
        if (total == 0) {
            std::cout << "Mochila vacia" << std::endl;
            return;
        }
        
        std::cout << "\nArchivos (" << total << "):" << std::endl;
        Nodo* actual = primero;
        int i = 1;
        while (actual != nullptr) {
            std::cout << i << ". " << actual->doc->nombre << std::endl;
            actual = actual->sig;
            i++;
        }
    }
    
    void ver() {
        std::string nom;
        std::cout << "Archivo a ver: ";
        std::cin >> nom;
        
        Nodo* actual = primero;
        while (actual != nullptr) {
            if (actual->doc->nombre == nom) {
                actual->doc->mostrar();
                return;
            }
            actual = actual->sig;
        }
        std::cout << "No existe ese archivo" << std::endl;
    }
};

void menuEstudiante() {
    Mochila m;
    int op;
    
    do {
        std::cout << "\n--- MOCHILA ---" << std::endl;
        std::cout << "1. Cargar archivo" << std::endl;
        std::cout << "2. Ver archivos" << std::endl;
        std::cout << "3. Abrir archivo" << std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Opcion: ";
        std::cin >> op;
        
        switch (op) {
            case 1:
                m.agregar();
                break;
            case 2:
                m.listar();
                break;
            case 3:
                m.ver();
                break;
            case 4:
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
        }
    } while (op != 4);
}

/*
int main() {
    menuEstudiante();
    return 0;
}
*/