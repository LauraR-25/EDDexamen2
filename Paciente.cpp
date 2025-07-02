#include "Paciente.h"

Paciente::Paciente(const std::string& nombre, const std::string& gravedad, int llegada)
    : nombre(nombre), gravedad(gravedad), llegada(llegada) {}

Paciente::Paciente() : nombre(""), gravedad("Verde"), llegada(0) {}

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

int prioridadGravedad(const std::string& gravedad) {
    if (gravedad == "Rojo") return 1;
    if (gravedad == "Naranja") return 2;
    if (gravedad == "Amarillo") return 3;
    return 4; // Verde
}