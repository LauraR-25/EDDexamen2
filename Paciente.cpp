#include "Paciente.h"

// Constructor por defecto
Paciente::Paciente() : nombre(""), gravedad(""), llegada(0) {}

// Constructor con parámetros
Paciente::Paciente(const std::string& nombre, const std::string& gravedad, int llegada)
    : nombre(nombre), gravedad(gravedad), llegada(llegada) {}

// Métodos getters
std::string Paciente::getNombre() const {
    return nombre;
}

std::string Paciente::getGravedad() const {
    return gravedad;
}

int Paciente::getLlegada() const {
    return llegada;
}

int Paciente::getPrioridad() const {
    return prioridadGravedad(gravedad);
}

// Función para obtener la prioridad según la gravedad
int prioridadGravedad(const std::string& gravedad) {
    if (gravedad == "Alta") return 3;
    if (gravedad == "Media") return 2;
    if (gravedad == "Baja") return 1;
    return 0; // Por defecto
}