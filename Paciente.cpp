#include <iostream>
#include "Paciente.h"
using namespace std;

// Constructor por defecto
Paciente::Paciente() : nombre(""), gravedad(""), llegada(0) {}

// Constructor con parámetros
Paciente::Paciente(const string& nombre, const string& gravedad, int llegada)
    : nombre(nombre), gravedad(gravedad), llegada(llegada) {}

// Métodos getters
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

// Función para obtener la prioridad según la gravedad
int prioridadGravedad(const string& gravedad) {
    if (gravedad == "Rojo") return 4;
    if (gravedad == "Naranja") return 3;
    if (gravedad == "Amarillo") return 2;
    if (gravedad == "Verde") return 1;
    return 0; // Por defecto
}