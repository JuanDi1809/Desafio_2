#ifndef RED_H
#define RED_H

#include "linea.h"
#include <string>

using namespace std;

class Red
{

private:
    string nombreRed;
    Linea** listaLineas; //Arreglo de punteros
    int cantLineas;
public:
    //Constructor
    Red(const string&);

    //Destructor
    ~Red();

    //Getters
    string getNombreRed() const;
    int getCantLineas() const;
    string getPrimeraLinea() const;

    //Getter paro objeto
    Linea* getObjetoLinea(const string&);

    //Metodo para verificar que la linea no exista
    string verificarLinea();

    //Metodo para verificar que la linea ya exista
    string verificarLinea2();

    //Metodo para ampliar la lista de lineas
    void agregarLinea(const string&);

    //Metodo para verificar si una linea tiene estaciones
    bool verificarEstacionesLinea();

    //Metodo para listar lineas
    void listarLineas();

    //Metodo par enlistar lineas con las que se puede conectar
    void listarLineas2(const string&);
};

#endif // RED_H
