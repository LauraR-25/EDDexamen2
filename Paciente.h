#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <string>
using namespace std;

class Paciente {
public:
    Paciente();                         // Constructor por defecto
    Paciente(const string& nombre, const string& gravedad, int llegada);
    string getNombre() const;
    string getGravedad() const;
    int getLlegada() const;
    int getPrioridad() const;
private:
    string nombre;
    string gravedad;
    int llegada;
};

int prioridadGravedad(const string& gravedad);

#endif