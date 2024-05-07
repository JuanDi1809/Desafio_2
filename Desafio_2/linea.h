#ifndef LINEA_H
#define LINEA_H

#include <string>
#include "estacion.h"
using namespace std;

class Linea
{
private:
    string nombreLinea;
    Estacion** listaEstaciones;
    int cantEstaciones;

public:
    Linea(const string&); //Constructor
    //~Linea(); //Destructor

    //Getters
    string getNombreLinea();
    int getCantEstaciones();

    //retorna el primer nombre de la estacion de la linea
    string getEstacionInicial();

    //getter que devuelve el objeto estacion
    Estacion* getObjetoEstacion(const string& nombreEstacion);

    //Metodo para verificar la existencia de la estacion
    string verificarEstacion1();

    //Metodo para verificar la no esxistencia de la estacion
    string verificarEstacion2();

    //Metodo para amliar la lista de estaciones
    void ampliarListaEstaciones();

    //Metodo para agregar la estacion al inicio, actualizar los tiempos
    void agregarEstacionInicio(const string&, bool, int, int);

    //Metodo para agregar la estacion al final y actualiza los tiempos
    void agregarEstacionFinal();

    //Metodo para agregar la estacion en medio de dos estaciones
    void agregarEstacionMedio();

    //Metodo para eliminar linea
    void eliminarEstacion(); //Toca verificar que no sea de transicion y actualizar tiempos

    //Metodo para listar estaciones
    void listarEstaciones();
};

#endif // LINEA_H
