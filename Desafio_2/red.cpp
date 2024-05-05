#include "red.h"
#include <iostream>
using namespace std;

red::red(string _nombre): nombre(_nombre), tamLineasRed(0) {}

red::~red(){

    for (int i = 0; i < tamLineasRed; ++i) {
        delete lineasRed[i]; // Liberar cada objeto del arreglo
    }
    delete[] lineasRed; // Liberar el arreglo en sí
}

int red::getLineasRed() const{
    return tamLineasRed;
}

string red::getNombre() const{
    return nombre;
}

bool red::verificarLinea(string& nombre){

    //Recorrido por los nombres de las lineas para verificar si ya existe
    for(int i = 0; i < tamLineasRed; i++ ){
        if(lineasRed[i]->obtenerNombre() == nombre){
            return true;
        }
    }
    return false;
}

void red::apmliarLineasRed(){
    int nuevaFila = tamLineasRed + 1;
    linea** nuevaLineasRed = new linea*[nuevaFila];

    //Copiar los punteros existentes de la matriz original a la nueva matriz
    //Se verifica que sea diferente de cero porque si no, generaria un problema de indexacion
    if(tamLineasRed != 0){
        for (int i = 0; i < nuevaFila; ++i) {
            nuevaLineasRed[i] = lineasRed[i]; // Copia los punteros existentes (si los hay)
        }
    }

    //Hago la copia de el nuevo arreglo
    lineasRed = nuevaLineasRed;
    tamLineasRed++;
}

void red::agregarLinea(string& name){
    lineasRed[tamLineasRed - 1] = new linea(name);
}
