#include <iostream>
#include <string>
#include "Paciente.h"

// Estructura para nodo de la cola
struct NodoPaciente {
    Paciente paciente;
    NodoPaciente* siguiente;
    NodoPaciente(const Paciente& p) : paciente(p), siguiente(nullptr) {}
};

// Cola dinámica de pacientes
class ColaPacientes {
public:
    ColaPacientes() : frente(nullptr), fin(nullptr) {}
    ~ColaPacientes() {
        while (frente) {
            NodoPaciente* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }
    void encolar(const Paciente& p) {
        NodoPaciente* nuevo = new NodoPaciente(p);
        if (!fin) {
            frente = fin = nuevo;
        } else {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }
    // Para mostrar en orden de atención, copiamos a un arreglo dinámico temporal
    void mostrarOrdenAtencion() const {
        // Contar elementos
        int n = 0;
        for (NodoPaciente* aux = frente; aux; aux = aux->siguiente) n++;
        if (n == 0) {
            std::cout << "No hay pacientes registrados.\n";
            return;
        }
        // Copiar a arreglo
        Paciente* arr = new Paciente[n];
        int i = 0;
        for (NodoPaciente* aux = frente; aux; aux = aux->siguiente)
            arr[i++] = aux->paciente;
        // Ordenar por prioridad y llegada (burbuja)
        for (int j = 0; j < n-1; ++j) {
            for (int k = 0; k < n-j-1; ++k) {
                if (arr[k].getPrioridad() > arr[k+1].getPrioridad() ||
                   (arr[k].getPrioridad() == arr[k+1].getPrioridad() && arr[k].getLlegada() > arr[k+1].getLlegada())) {
                    Paciente tmp = arr[k];
                    arr[k] = arr[k+1];
                    arr[k+1] = tmp;
                }
            }
        }
        std::cout << "\nOrden de atención:\n";
        for (int j = 0; j < n; ++j)
            std::cout << (j+1) << ". " << arr[j].getNombre() << " - " << arr[j].getGravedad() << "\n";
        delete[] arr;
    }
private:
    NodoPaciente* frente;
    NodoPaciente* fin;
};

void mostrarMenu() {
    std::cout << "\n1. Registrar paciente\n";
    std::cout << "2. Mostrar orden de atención\n";
    std::cout << "3. Salir\n";
}

void registrarPaciente(ColaPacientes& cola, int& contadorLlegada) {
    std::string nombre, gravedad;
    int opcion;
    std::cout << "Nombre del paciente: ";
    std::getline(std::cin >> std::ws, nombre);
    std::cout << "Grado de emergencia (elige una opción):\n";
    std::cout << "1. Verde (leve)\n";
    std::cout << "2. Amarillo (bajo riesgo)\n";
    std::cout << "3. Naranja (alto riesgo)\n";
    std::cout << "4. Rojo (crítico)\n";
    std::cout << "Opción: ";
    std::cin >> opcion;
    switch (opcion) {
        case 1: gravedad = "Verde"; break;
        case 2: gravedad = "Amarillo"; break;
        case 3: gravedad = "Naranja"; break;
        case 4: gravedad = "Rojo"; break;
        default: std::cout << "Opción inválida.\n"; return;
    }
    Paciente p(nombre, gravedad, contadorLlegada++);
    cola.encolar(p);
    std::cout << "Paciente registrado.\n";
}

int main() {
    ColaPacientes cola;
    int contadorLlegada = 0;
    int opcion;
    while (true) {
        mostrarMenu();
        std::cout << "Elige una opción: ";
        std::cin >> opcion;
        std::cin.ignore();
        if (opcion == 1) {
            registrarPaciente(cola, contadorLlegada);
        } else if (opcion == 2) {
            cola.mostrarOrdenAtencion();
        } else if (opcion == 3) {
            std::cout << "Saliendo...\n";
            break;
        } else {
            std::cout << "Opción inválida.\n";
        }
    }
    return 0;
}