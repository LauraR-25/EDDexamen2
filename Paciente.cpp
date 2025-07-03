#include <iostream>
#include "Paciente.h"
using namespace std;

Paciente::Paciente() : nombre(""), gravedad(""), llegada(0) {}

Paciente::Paciente(const string& nombre, const string& gravedad, int llegada)
    : nombre(nombre), gravedad(gravedad), llegada(llegada) {}

string Paciente::getNombre() const {
    return nombre;
}

string Paciente::getGravedad() const {
    return gravedad;
}

int Paciente::getLlegada() const {
    return llegada;
}

int Paciente::getPrioridad() const {
    return prioridadGravedad(gravedad);
}

int prioridadGravedad(const string& gravedad) {
    if (gravedad == "Rojo") return 4;
    if (gravedad == "Naranja") return 3;
    if (gravedad == "Amarillo") return 2;
    if (gravedad == "Verde") return 1;
    return 0;              // Por defecto
}