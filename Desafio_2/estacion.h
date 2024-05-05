#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include <string>

using namespace std;

class Estacion
{
private:
    string nombreEstacion;
    string nombreLinea;
    bool esTransicion;
    int tiempoAnterior;
    int tiempoSiguiente;

    int longitudArray;
    int numLineas;
    string *lineas; //solo será modificada cuando es de transición

public:

    //Constructor
    Estacion(string);

    //destructor
    ~Estacion();

    //getters
    string getNombreEstacion() const;
    int getTiempoAnterior() const;
    int getTiempoSiguiente() const;

    //Setters
    void setEstacionTransicion();
    void setTiempoAnterior(int);
    void setTiempoSiguiente(int);

    //Metodos

    //Me permite mostrar los tiempos respectos a sus estaciones vecinas
    void mostrarTiempoAnterior(string,string);
    void mostrarTiempoSiguiente(string, string);

    void lineasDePertenencia(const string &nombreLinea);
};

#endif // ESTACION_H
