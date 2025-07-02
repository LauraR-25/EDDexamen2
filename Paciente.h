#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string>

class Paciente {
public:
    Paciente(); // Constructor por defecto
    Paciente(const std::string& nombre, const std::string& gravedad, int llegada);
    std::string getNombre() const;
    std::string getGravedad() const;
    int getLlegada() const;
    int getPrioridad() const;
private:
    std::string nombre;
    std::string gravedad;
    int llegada;
};

int prioridadGravedad(const std::string& gravedad);

#endif