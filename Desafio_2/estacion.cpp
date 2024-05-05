#include "estacion.h"
#include <iostream>
#include <string>

using namespace std;

Estacion::Estacion(string _nombreEstacion):nombreEstacion(_nombreEstacion), tiempoAnterior(0), tiempoSiguiente(0), esTransicion(false), longitudArray(0), numLineas(0){}

Estacion::~Estacion(){
    delete[] lineas;
}

string Estacion::getNombreEstacion() const{
    return nombreEstacion;
}

int Estacion::getTiempoAnterior() const{
    return tiempoAnterior;
}

int Estacion::getTiempoSiguiente() const{
    return tiempoSiguiente;
}


void Estacion::setTiempoAnterior(int nuevoTiempo){
    tiempoAnterior = nuevoTiempo;
}

void Estacion::setTiempoSiguiente(int nuevoTiempo){
    tiempoSiguiente = nuevoTiempo;
}

void Estacion::setEstacionTransicion(){
    estacionTransicion = true;
}

void Estacion::mostrarTiempoAnterior(string anterior, string actual ){
    cout << "El tiempo de la estacion " << actual << " a la estacion " << anterior << " es " << tiempoAnterior;
}

void Estacion::mostrarTiempoSiguiente(string actual, string siguiente){
    cout << "El tiempo de la estacion " << actual << " a la estacion " << siguiente << " es " << tiempoSiguiente;
}

void Estacion::lineasDePertenencia(const string &nombreLinea){
    longitudArray += 1;
    string *tempArray = new string[longitudArray];

    for (int i = 0; i < numLineas; ++i) {
        tempArray[i] = lineas[i];
    }

    delete[] lineas;
    lineas = tempArray;

    numLineas++;
    lineas[numLineas - 1] = nombreLinea;
}
