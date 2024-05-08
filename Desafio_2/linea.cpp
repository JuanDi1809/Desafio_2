#include "linea.h"
#include "estacion.h"
#include <string>
#include <limits>

using namespace std;


Linea::Linea(const string& _nombreLinea): nombreLinea(_nombreLinea), listaEstaciones(nullptr), cantEstaciones(0) {}

/*
Linea::~Linea(){
    for(int i = 0; i < cantEstaciones; i++){
        delete listaEstaciones[i];
    }
    delete[] listaEstaciones;
}
*/

string Linea::getNombreLinea(){
    return nombreLinea;
}

int Linea::getCantEstaciones(){
    return cantEstaciones;
}

string Linea::verificarEstacion1(){
    string nombreEstacion;

    while(true){
        try{
            cout << "Ingresa el nombre de la Estacion: ";
            getline(cin, nombreEstacion);

            // Limpiar el búfer de entrada antes de usar getline nuevamente
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            for (int i = 0; i < cantEstaciones; i++) {
                if (listaEstaciones[i]->getNombreEstacion()== nombreEstacion) {
                    throw invalid_argument("esta estacion ya existe");
                }
            }
            break;
        }
        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
    }

    return nombreEstacion;
}

string Linea::verificarEstacion2(){
    string nombreEstacion;
    bool valido = true;

    while(valido){
        try{
            cout << "Ingresa el nombre de la estacion: ";
            getline(cin, nombreEstacion);

            // Limpiar el búfer de entrada antes de usar getline nuevamente
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int i;
            for (i = 0; i < cantEstaciones; i++) {
                if (listaEstaciones[i]->getNombreEstacion() == nombreEstacion) {
                    valido = false;
                    break;
                }
            }
            if(i == cantEstaciones) throw invalid_argument("esta estacion no existe");
        }
        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
    }

    return nombreEstacion;
}

void Linea::ampliarListaEstaciones(){
    int nuevaCapacidad = cantEstaciones + 1 ;
    Estacion** nuevasEstaciones = new Estacion*[nuevaCapacidad];

    //Copiamos las estaciones existentes al nuevo arreglo
    for(int i = 0; i < cantEstaciones; i++){
        nuevasEstaciones[i] = listaEstaciones[i];
    }

    //Liberamos la memoria del antiguo arreglo de punteros
    delete[] listaEstaciones;

    //Actualizamos los punteros
    listaEstaciones = nuevasEstaciones;

}

void Linea::agregarEstacionInicio(const string& nombreEstacion, bool esTransicion, int tAnterior, int tSiguiente){
    if(cantEstaciones == 0){
        listaEstaciones[cantEstaciones] = new Estacion(nombreEstacion, esTransicion, tAnterior, tSiguiente);
    }
    else{

        Estacion *temp = listaEstaciones[0];
        listaEstaciones[0] = new Estacion(nombreEstacion, esTransicion, tAnterior, tSiguiente);
        listaEstaciones[1] = temp;
    }
    cantEstaciones++;
}
void Linea::agregarEstacionFinal(const string& nombreEstacion, bool esTransicion, int tAnterior, int tSiguiente){
    listaEstaciones[cantEstaciones] = new Estacion(nombreEstacion, esTransicion, tAnterior, tSiguiente);
    cantEstaciones++;
}

/*
void Linea::agregarEstacionMedio(const string& nombreEstacion, bool esTransicion, int tAnterior, int tSiguiente, const string& nombreAnterior){
    for(int i = 0; i <= cantEstaciones; i++){
        if(listaEstaciones[i]->getNombreEstacion() == nombreAnterior){
            Estacion* temp = listaEstaciones[i + 1];
            listaEstaciones[i+1] = new Estacion(nombreEstacion,esTransicion, tAnterior, tSiguiente);
        }
    }
}
*/

void Linea::eliminarEstacion(){

}

void Linea::listarEstaciones(){
    for(int i = 0; i < cantEstaciones; i++){
        cout << i + 1 << ". "<< listaEstaciones[i]->getNombreEstacion()<< endl;
    }
}

void Linea::listarEstaciones2(){
    for(int i = 1; i < cantEstaciones; i++){
        cout << i << ". " << listaEstaciones[i - 1]->getNombreEstacion() << "-" << listaEstaciones[i]->getNombreEstacion() << endl;
    }

}

Estacion* Linea::getObjetoEstacion(const string& nombreEstacion){
    for(int i = 0; i < cantEstaciones; i++){
        if(listaEstaciones[i]->getNombreEstacion() == nombreEstacion){
            return listaEstaciones[i];
        }
    }
}

Estacion* Linea::getObjetoEstacion2(int opcion){
    return listaEstaciones[opcion - 1];
}

string Linea::getEstacionInicial(){
    return listaEstaciones[0]->getNombreEstacion();
}

string Linea::getEstacionFinal(){
    return listaEstaciones[cantEstaciones - 1]->getNombreEstacion();
}
bool Linea::getEstacionTransicion(){
    for(int i = 0; i < cantEstaciones; i++){
        if(listaEstaciones[i]->getEsTransicion()){
            return true;
        }
    }
    return false;
}

