#include "red.h"
#include "linea.h"

Red::Red(string const& _nombreRed): nombreRed(_nombreRed), listaLineas(nullptr), cantLineas(0) {}

Red::~Red(){
    for(int i = 0; i < cantLineas; i++){
        delete listaLineas[i];
    }
    delete[] listaLineas;
}

string Red::getNombreRed() const{
    return nombreRed;
}

int Red::getCantLineas() const{
    return cantLineas;
}

Linea* Red::getObjetoLinea(const string& nombreLinea){
    for(int i = 0; i < cantLineas; i++){
        if(listaLineas[i]->getNombreLinea() == nombreLinea){
            return listaLineas[i];
        }
    }
}

string Red::getPrimeraLinea() const{
    return listaLineas[0]->getNombreLinea();
}

string Red::verificarLinea(){
    string nombreLinea;

    while(true){
        try{
            cout << "Ingresa el nombre de la linea: ";
            getline(cin, nombreLinea);

            for (int i = 0; i < cantLineas; i++) {
                if (listaLineas[i]->getNombreLinea()== nombreLinea) {
                    throw invalid_argument("esta estacion ya existe");
                }
            }
            break;
        }
        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
    }

    return nombreLinea;
}

string Red::verificarLinea2(){
    string nombreLinea;
    bool valido = true;

    while(valido){
        try{
            cout << "Ingresa el nombre de la linea: ";
            getline(cin, nombreLinea);

            int i;
            for (i = 0; i < cantLineas; i++) {
                if (listaLineas[i]->getNombreLinea() == nombreLinea) {
                    valido = false;
                    break;
                }
            }
            if(i == cantLineas) throw invalid_argument("esta estacion no existe");
        }
        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
    }

    return nombreLinea;
}


void Red::agregarLinea(const string& nombreLinea){
    int nuevaCapacidad = cantLineas + 1 ;
    Linea** nuevasLineas = new Linea*[nuevaCapacidad];

    //Copiamos las estaciones existentes al nuevo arreglo
    for(int i = 0; i < cantLineas; i++){
        nuevasLineas[i] = listaLineas[i];
    }

    //Liberamos la memoria del antiguo arreglo de punteros
    delete[] listaLineas;

    //Actualizamos los punteros
    listaLineas = nuevasLineas;

    listaLineas[cantLineas] = new Linea(nombreLinea);

    cantLineas++;
}


bool Red::verificarEstacionesLinea(){
    if(cantLineas == 0){
        return true;
    }
    else if(listaLineas[cantLineas - 1]->getCantEstaciones() == 0){
        return false;
    }
    else{
        return true;
    }
}

void Red::listarLineas(){
    for(int i = 0; i < cantLineas; i++ ){
        cout << i + 1 << ". " << listaLineas[i]->getNombreLinea() << endl;
    }
}

void Red::listarLineas2(const string& nombreLinea){
    for(int i = 0; i < cantLineas; i++){
        if(listaLineas[i]->getNombreLinea() != nombreLinea){
            cout << i + 1 << ". " << listaLineas[i]->getNombreLinea() << endl;
        }
    }
}


