#include <iostream>
#include "Paciente.h"
using namespace std;

const int MAX_PACIENTES = 100;

int main(){
    Paciente pacientes[MAX_PACIENTES];
    int llegada = 1;
    int numPacientes = 0;
    string nombre, gravedad;
    char opcion;

    do {
        if (numPacientes >= MAX_PACIENTES) {
            cout << "Se alcanzó el número máximo de pacientes.\n";
            break;
        }
        cout << "Nombre del paciente: ";
        getline(cin, nombre);
        cout << "Grado de emergencia (verde, amarillo, naranja, rojo): ";
        getline(cin, gravedad);

        pacientes[numPacientes++] = Paciente(nombre, gravedad, llegada++);
        cout << "Registrar otro paciente?(s/n): ";
        cin >> opcion;
        cin.ignore();
    } while (opcion == 's' || opcion == 'S');

    if(numPacientes == 0) {
        cout << "No hay pacientes registrados.\n";
        return 0;
    }

    // Ordenar por prioridad y llegada (burbuja)
    for (int i = 0; i < numPacientes - 1; ++i) {
        for (int j = 0; j < numPacientes - i - 1; ++j) {
            if (pacientes[j].getPrioridad() < pacientes[j+1].getPrioridad() ||
                (pacientes[j].getPrioridad() == pacientes[j+1].getPrioridad() &&
                 pacientes[j].getLlegada() > pacientes[j+1].getLlegada())) {
                Paciente temp = pacientes[j];
                pacientes[j] = pacientes[j+1];
                pacientes[j+1] = temp;
            }
        }
    }

    cout << "\n Orden de atención:\n";
    for (int i = 0; i < numPacientes; ++i) {
        cout << pacientes[i].getNombre() << " - " << pacientes[i].getGravedad()
             << " (Llegada: " << pacientes[i].getLlegada() << ")\n";
    }

    return 0;
}