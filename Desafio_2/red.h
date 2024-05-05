#ifndef RED_H
#define RED_H

#include <string>
#include "linea.h"
using namespace std;

class red
{
private:
    string nombre;
    linea** lineasRed; //Arreglo de punteros
    int tamLineasRed; //Tamaño inicial con que inicia la red

public:
    red(string); // constructor
    ~red(); //Destructor


    //getter
    int getLineasRed() const;
    string getNombre() const;

     //metodos
    bool verificarLinea(string&);
    void apmliarLineasRed();
    void agregarLinea(string&);

};

#endif // RED_H
