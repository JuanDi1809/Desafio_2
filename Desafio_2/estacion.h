#ifndef ESTACION_H
#define ESTACION_H

#include <iostream>
#include <string>

using namespace std;

class Estacion
{

private:
    string nombreEstacion;
    bool esTransicion;
    int tAnterior;
    int tSiguiente;

public:

    //Constructor
    Estacion(const string&, bool, int, int);

    //Destructor
    ~Estacion();

    //Getters
    string getNombreEstacion() const;
    bool getEsTransicion() const;
    int getAnterior() const;
    int getSiguiente() const;

    //setter
    void setEsTransicion();
    void setTanterior(int);
    void setTsiguiente(int);


};

#endif // ESTACION_H
