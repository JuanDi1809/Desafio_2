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
    int tamLineasRed; //Cantidad de lineas en la red

public:
    red(string); // constructor
    ~red(); //Destructor


    //getter
    int getLineasRed() const;
    string getNombre() const;

    //metodos
    bool verificarLinea(string&);
    void apmliarLineasRed(); //Amplia el arreglo de punteros y actualiza el tamaño del arreglo
    void agregarLinea(string&);
    void listarLineas();

};

#endif // RED_H
