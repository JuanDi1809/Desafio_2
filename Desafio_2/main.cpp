#include <iostream>
#include <string>
#include "menu.h"
#include "red.h"

using namespace std;

int main()
{
    while(true){
        Menu menu1;
        menu1.menuRed();

        int opcionesRed[] = {1, 2, 3};
        int opcionRed = menu1.validarOpcion(opcionesRed, 3);

        cout << endl;

        if(opcionRed == 1){
            string nombreRed;
            cout << "Ingresa el nombre de la red: ";

            getline(cin,nombreRed);
            red r1(nombreRed);

            while(true){

                Menu menu2;

                menu2.menuLinea();

                int opcionesLinea[] = {1, 2, 3, 4, 5, 6};
                int opcionLinea = menu2.validarOpcion(opcionesLinea, 6);

                if(opcionLinea == 1){ //Agregar linea

                    string nombreLinea;
                    bool valido;

                    do{
                        try{
                            cout << "Ingresa el nombre de la linea: ";
                            getline(cin, nombreLinea);

                            valido = r1.verificarLinea(nombreLinea);

                            if(valido) throw invalid_argument("esta estacion ya existe");

                        }catch(const exception& ex){
                            cerr << "Error: " << ex.what() << endl;
                        }
                    }while(valido);

                    r1.apmliarLineasRed();
                    r1.agregarLinea(nombreLinea);

                }
                else if(opcionLinea == 2){ //Eliminar linea

                    if(r1.getLineasRed() == 0){
                        cout << "ADVERTENCIA: No hay lineas creadas en la red. Ingrese primeros las lineas y sus respectivas estaciones" << endl;
                        cout << endl;
                    }
                    else{
                        //Toca verificar que la linea que escogio para eliminar no tenga estaciones de transicion
                        cout << "Proceso para eliminar linea";
                    }
                }
                else if(opcionLinea == 3){ //Cantidad de lineas
                    cout <<"Hay "<< r1.getLineasRed() << " lineas en la red " << r1.getNombre() << endl;
                    cout << endl;
                }
                else if(opcionLinea == 4){ //Cantidad de estaciones
                    cout << "Cantidad de estaciones en la red";
                }
                else if(opcionLinea == 5){
                    while(true){
                        Menu menu3;

                        menu3.menuEstaciones();

                        int opcionesEstacion[] = {1, 2, 3, 4};
                        int opcionEstacion = menu3.validarOpcion(opcionesEstacion, 4);

                        if(opcionEstacion == 1){ //Agregar estacion de una linea
                            if(r1.getLineasRed() == 0){
                                cout << "ADVERTENCIA: No hay lineas creadas en la red. Ingrese primeros las lineas y sus respectivas estaciones" << endl;
                                cout << endl;
                            }
                            else{
                                cout << "En que linea deseas agregar la estacion: " << endl;
                                r1.listarLineas();
                            }
                        }
                        else if(opcionEstacion == 2){ //Elimina estacion de una linea
                            if(r1.getLineasRed() == 0){
                                cout << "ADVERTENCIA: No hay lineas creadas en la red. Ingrese primeros las lineas y sus respectivas estaciones" << endl;
                                cout << endl;
                            }
                            else{
                                cout << "Proceso para eliminar estacion de una linea";
                            }
                        }
                        else if(opcionEstacion == 3){ //cantidad de estaciones de una linea
                            if(r1.getLineasRed() == 0){
                                cout << "ADVERTENCIA: No hay lineas creadas en la red. Ingrese primeros las lineas y sus respectivas estaciones" << endl;
                                cout << endl;
                            }
                            else{
                                cout << "Proceso para cantidad de estaciones de una linea ";
                            }
                        }
                        else{ //Vulve al menu de linea
                            break;
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
        else if(opcionRed == 2){
            cout << "De momenot no hay lineas, ni estaciones creadas" << endl ; //cuando se hacen verificaciones, este es el mensaje a mostrar
        }
        else{
            break;
        }
    }
    return 0;
}
