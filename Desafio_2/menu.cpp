#include <iostream>
#include "menu.h"
#include <string>
#include <limits>

using namespace std;

void Menu::menuPrincipal(){
    cout << "MENU PRINCIPAL:\n";
    cout << "1. Menu red\n";
    cout << "2. Menu linea\n";
    cout << "3. Salir\n";
}

void Menu::menuRed(){
    cout << "MENU RED:\n";
    cout << "1. Agregar una linea a la red Metro\n";
    cout << "2. Eliminar una linea de la red Metro\n";
    cout << "3. Saber cuantas lineas tiene la red Metro\n";
    cout << "4. Saber cuantas estaciones tiene la red Metro\n";
    cout << "5. Volver al menu principal\n";
}

void Menu::menuLinea(){
    cout << "MENU LINEA:\n";
    cout << "1. Agregar una estacion a una linea\n";
    cout << "2. Eliminar una estacion de una linea\n";
    cout << "3. Saber cuantas estaciones tiene una linea\n";
    cout << "4. Volver al menu principal\n";
}

void Menu::menuUbicacion(){
    cout << "1. Al inicio\n";
    cout << "2. Al final\n";
    cout << "3. En medio de dos estaciones\n";
}
int Menu::validarOpcion( int tam){
    while(true){
        try{
            string opcionAux; //El datos es de tipo a string porque asi el usuario cuando ingrese datos que no son, no me generen problemas, la verificaion es despues

            cout << "Ingresa una opcion: ";
            getline(cin, opcionAux);

            //Limpiar el búfer de entrada antes de usar getline nuevamente
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if(opcionAux.size() > 1) throw out_of_range("debe ser solo un caracter");


            int opcion = stoi(opcionAux);

            for(int i = 1; i <= tam; i++){
                if(i == opcion){
                    return opcion;
                }
            }

            throw invalid_argument("no se encuentra en las opciones permitidas");
        }

        catch(const exception& ex){
            cerr << "Error: " << ex.what() << endl;
        }
    }
}

