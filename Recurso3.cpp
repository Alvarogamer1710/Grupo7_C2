#include <iostream>
#include <cmath>

class Calculadora {
public:
    double sumar(double a, double b) { return a + b; }
    double restar(double a, double b) { return a - b; }
    double multiplicar(double a, double b) { return a * b; }
    double dividir(double a, double b) {
        if (b == 0) {
            std::cerr << "Error: división por cero." << std::endl;
            return 0;
        }
        return a / b;
    }

    void sumarMatriz(double A[10][10], double B[10][10], double R[10][10], int f, int c) {
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                R[i][j] = A[i][j] + B[i][j];
    }

    void restarMatriz(double A[10][10], double B[10][10], double R[10][10], int f, int c) {
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                R[i][j] = A[i][j] - B[i][j];
    }

    void multiplicarMatriz(double A[10][10], double B[10][10], double R[10][10], int f1, int c1, int c2) {
        for (int i = 0; i < f1; ++i)
            for (int j = 0; j < c2; ++j) {
                R[i][j] = 0;
                for (int k = 0; k < c1; ++k)
                    R[i][j] += A[i][k] * B[k][j];
            }
    }

    void dividirMatriz(double A[10][10], double B[10][10], double R[10][10], int f, int c) {
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                R[i][j] = (B[i][j] == 0) ? 0 : A[i][j] / B[i][j];
    }

    void traspuesta(double A[10][10], double T[10][10], int f, int c) {
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < c; ++j)
                T[j][i] = A[i][j];
    }

    double determinante(double A[10][10], int n) {
        if (n == 1) return A[0][0];
        if (n == 2) return A[0][0]*A[1][1] - A[0][1]*A[1][0];
        double det = 0;
        double sub[10][10];
        for (int p = 0; p < n; ++p) {
            int subi = 0;
            for (int i = 1; i < n; ++i) {
                int subj = 0;
                for (int j = 0; j < n; ++j) {
                    if (j == p) continue;
                    sub[subi][subj] = A[i][j];
                    subj++;
                }
                subi++;
            }
            det += (p % 2 == 0 ? 1 : -1) * A[0][p] * determinante(sub, n - 1);
        }
        return det;
    }

    void mostrarMatriz(double A[10][10], int f, int c) {
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j)
                std::cout << A[i][j] << "\t";
            std::cout << std::endl;
        }
    }
};

void menuCalculadora() {
    Calculadora calc;
    int opcion;
    do {
        std::cout << "\n--- CALCULADORA AVANZADA ---" << std::endl;
        std::cout << "1. Operaciones básicas" << std::endl;
        std::cout << "2. Operaciones con matrices" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                double a, b;
                char op;
                std::cout << "Ingrese operación (ejemplo: 5 + 3): ";
                std::cin >> a >> op >> b;
                double res;
                switch (op) {
                    case '+': res = calc.sumar(a,b); break;
                    case '-': res = calc.restar(a,b); break;
                    case '*': res = calc.multiplicar(a,b); break;
                    case '/': res = calc.dividir(a,b); break;
                    default: std::cout << "Operador no válido."; continue;
                }
                std::cout << "Resultado: " << res << std::endl;
                break;
            }
            case 2: {
                int f, c;
                std::cout << "Filas y columnas de la matriz: ";
                std::cin >> f >> c;
                double A[10][10], B[10][10], R[10][10];
                std::cout << "Ingrese matriz A:" << std::endl;
                for (int i = 0; i < f; ++i)
                    for (int j = 0; j < c; ++j)
                        std::cin >> A[i][j];
                std::cout << "Ingrese matriz B:" << std::endl;
                for (int i = 0; i < f; ++i)
                    for (int j = 0; j < c; ++j)
                        std::cin >> B[i][j];
                int opM;
                std::cout << "1.Sumar 2.Restar 3.Multiplicar 4.Dividir 5.Traspuesta(A) 6.Det(A): ";
                std::cin >> opM;
                switch (opM) {
                    case 1: calc.sumarMatriz(A,B,R,f,c); calc.mostrarMatriz(R,f,c); break;
                    case 2: calc.restarMatriz(A,B,R,f,c); calc.mostrarMatriz(R,f,c); break;
                    case 3: calc.multiplicarMatriz(A,B,R,f,c,c); calc.mostrarMatriz(R,f,c); break;
                    case 4: calc.dividirMatriz(A,B,R,f,c); calc.mostrarMatriz(R,f,c); break;
                    case 5: calc.traspuesta(A,R,f,c); calc.mostrarMatriz(R,c,f); break;
                    case 6: std::cout << "Determinante: " << calc.determinante(A,f) << std::endl; break;
                    default: std::cout << "Opción inválida."; break;
                }
                break;
            }
            case 3:
                std::cout << "Saliendo de la calculadora..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida." << std::endl;
        }
    } while (opcion != 3);
}

/*
int main() {
    menuCalculadora();
    return 0;
}
*/
