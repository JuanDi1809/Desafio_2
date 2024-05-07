#include "estacion.h"
#include <string>

Estacion::Estacion(const string& _nombreEstacion,bool _esTransicion, int _tAnterior,int _tSiguiente): nombreEstacion(_nombreEstacion), esTransicion(_esTransicion), tAnterior(_tAnterior), tSiguiente(_tSiguiente) {}

Estacion::~Estacion(){}

string Estacion::getNombreEstacion() const{
    return nombreEstacion;
}

bool Estacion:: getEsTransicion() const{
    return esTransicion;
}

int Estacion::getAnterior() const{
    return tAnterior;
}

int Estacion::getSiguiente() const{
    return tSiguiente;
}

void Estacion::setEsTransicion(){
    esTransicion = true;
}
void Estacion::setTanterior(int tiempo){
    tAnterior = tiempo;
}
void Estacion::setTsiguiente(int tiempo){
    tSiguiente = tiempo;
}
