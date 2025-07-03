#include <iostream>
#include <vector>
#include <algorithm>
#include "Paciente.h"

int main() {
    std::vector<Paciente> pacientes;
    int llegada = 1;
    std::string nombre, gravedad;
    char opcion;

    do {
        std::cout << "Nombre del paciente: ";
        std::getline(std::cin, nombre);
        std::cout << "Grado de emergencia (Verde, Amarillo, Naranja, Rojo): ";
        std::getline(std::cin, gravedad);

        pacientes.emplace_back(nombre, gravedad, llegada++);
        std::cout << "¿Registrar otro paciente? (s/n): ";
        std::cin >> opcion;
        std::cin.ignore();
    } while (opcion == 's' || opcion == 'S');

    // Ordenar por prioridad y llegada
    std::sort(pacientes.begin(), pacientes.end(), [](const Paciente& a, const Paciente& b) {
        if (a.getPrioridad() != b.getPrioridad())
            return a.getPrioridad() > b.getPrioridad();
        return a.getLlegada() < b.getLlegada();
    });

    std::cout << "\nOrden de atención:\n";
    for (const auto& p : pacientes) {
        std::cout << p.getNombre() << " - " << p.getGravedad() << " (Llegada: " << p.getLlegada() << ")\n";
    }

    return 0;
}