#include <iostream>
#include "menu.h"
#include <string>

using namespace std;

void Menu::menuRed(){
    cout << "Menu red: " << endl;
    cout << "1. Crear red metro" << endl;
    cout << "2. Funcinamiento de la red" << endl;
    cout << "3. Salir del sistema" << endl;
}

void Menu::menuLinea(){
    cout << "Menu linea: " << endl;
    cout << "1. Agregar linea" << endl;
    cout << "2. Eliminar linea" << endl;
    cout << "3. Cantidad de lineas en la red" << endl;
    cout << "4. Cantidad de estaciones en la red" << endl;
    cout << "5. Menu estaciones" << endl;
    cout << "6. volver a menu red" << endl;
}

void Menu::menuEstaciones(){
    cout << "Menu estaciones: " << endl;
    cout << "1. Agregar estacion a una linea" << endl;
    cout << "2. Eliminar estacion de una linea" << endl;
    cout << "3. Saber  cantidad de estaciones de una linea" << endl;
    cout << "4. Volver a menu linea" << endl;
}


int Menu::validarOpcion(int opcionesValidas[], int tam){
    while(true){
        try{
            string opcionAux; //El datos es de tipo a string porque asi el usuario cuando ingrese datos que no son, no me generen problemas, la verificaion es despues

            cout << "Ingresa una opcion: ";
            getline(cin, opcionAux);

            if(opcionAux.size() > 1) throw out_of_range("debe ser solo un caracter");


            int opcion = stoi(opcionAux);

            for(int i = 0; i < tam; i++){
                if(opcionesValidas[i] == opcion){
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
