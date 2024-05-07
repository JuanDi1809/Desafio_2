#include <iostream>
#include <string>
#include "red.h"
#include "menu.h"
#include "linea.h"
#include "estacion.h"


using namespace std;

int main(){

    string nombreRed;

    cout << "Bienvenido a la simulacion de una red metro\n";
    cout << "Escribe el nombre de la red: ";
    getline(cin,nombreRed);

    Red r1(nombreRed);

    while(true){
        Menu menu1;

        menu1.menuPrincipal();
        int opcionMenuPrincipal = menu1.validarOpcion(3);

        if(opcionMenuPrincipal == 1){

            while(true){
                Menu menu2;

                menu2.menuRed();
                int opcionMenuRed = menu2.validarOpcion(5);

                if(opcionMenuRed == 1){//Agregar linea
                    if(r1.verificarEstacionesLinea()){
                        string nombreLinea =r1.verificarLinea();
                        r1.agregarLinea(nombreLinea);
                    }
                    else{
                        cout << "ADVERTENCIA: no puedes crear otra linea sin que la linea que creaste anteriormente tenga estaciones\n";
                    }
                }
                else if(opcionMenuRed == 2){//Eliminar linea
                    if(r1.getCantLineas() == 0){
                        cout << "ADVERTENCIA: aun no hay lineas creadas";
                    }
                    else{
                        cout << "Proceso para eliminar";
                    }
                }
                else if(opcionMenuRed == 3){//Lineas en la red
                    cout << "En la red " << r1.getNombreRed() << " hay " << r1.getCantLineas() << " lineas\n";
                }
                else if(opcionMenuRed == 4){//Estaciones en la red
                    if(r1.getCantLineas() == 0){
                        cout << "ADVERTENCIA: aun no hay lineas creadas";
                    }
                    else{
                        //Hay que tener cuidado con las estaciones de transicion
                        cout << "Estaciones en la red";
                    }
                }
                else{
                    break;
                }
            }
        }
        else if(opcionMenuPrincipal == 2){

            while(true){
                Menu menu3;

                menu3.menuLinea();
                int opcionMenuLinea = menu3.validarOpcion(4);

                if(opcionMenuLinea == 1){//Agregar estacion
                    cout << "Escoge la linea a donde va a pertencer la estacion\n";
                    r1.listarLineas();

                    string nombreLinea = r1.verificarLinea2();

                    Linea* linea = r1.getObjetoLinea(nombreLinea);


                    if(r1.getPrimeraLinea() == linea->getNombreLinea()){
                        if(linea->getCantEstaciones() == 0){
                            string nombreEstacion;

                            cout << "Ingrese el nombre de la estacion: ";
                            getline(cin,nombreEstacion);


                            linea->ampliarListaEstaciones();
                            linea->agregarEstacionInicio(nombreEstacion, false, 0, 0);
                        }
                        else{
                            string nombreEstacion = linea->verificarEstacion1();

                            while(true){
                                Menu menu4;

                                cout << "Como quieres agregar la estacion?\n";
                                menu4.menuUbicacion();
                                int opcionMenuUbicaion = menu4.validarOpcion(3);

                                //se llama el objeto estacion xd
                                string estacionInicial = linea->getEstacionInicial();
                                Estacion *estacionAmodificar = linea->getObjetoEstacion(estacionInicial);

                                if(opcionMenuUbicaion == 1 ){
                                    cout << "Agregar al inicio";
                                    break;
                                }
                                else if(opcionMenuUbicaion == 2){
                                    cout << "Al final";
                                    break;
                                }
                                else{
                                    if(linea->getCantEstaciones() >= 2){
                                        cout << "En medio de dos estaciones";
                                        break;
                                    }
                                    else{
                                        cout << "ADVERTENCIA: no hay mas de dos estaciones creadas en la linea " << linea->getNombreLinea() << endl;
                                    }
                                }
                            }
                        }
                    }
                    else{
                        if(linea->getCantEstaciones() == 0){
                            cout << "Seleccina linea con la que se conecta " << linea->getNombreLinea() << endl;
                            r1.listarLineas2(nombreLinea);

                            string nombreLineaConexion = r1.verificarLinea2();

                            Linea* lineaConexion = r1.getObjetoLinea(nombreLineaConexion);

                            lineaConexion->listarEstaciones();
                            string nombreEstacionConexion = lineaConexion->verificarEstacion2();

                            Estacion *estacionAgregada = lineaConexion-> getObjetoEstacion(nombreEstacionConexion);

                            if(estacionAgregada->getEsTransicion()){
                                lineaConexion->ampliarListaEstaciones();
                                lineaConexion->agregarEstacionInicio(nombreEstacionConexion, true, 0, 0);
                            }else{
                                estacionAgregada->setEsTransicion();
                            }
                        }
                        else{
                            cout << "Nombre estacion";
                            while(true){
                                Menu menu4;

                                menu4.menuUbicacion();
                                int opcionMenuUbicaion = menu4.validarOpcion(3);

                                if(opcionMenuUbicaion == 1 ){
                                    cout << "Agregar al inicio";
                                    break;
                                }
                                else if(opcionMenuUbicaion == 2){
                                    cout << "Al final";
                                    break;
                                }
                                else{
                                    if(linea->getCantEstaciones() >= 2){
                                        cout << "En medio de dos estaciones";
                                        break;
                                    }
                                    else{
                                        cout << "ADVERTENCIA: no hay mas de dos estaciones creadas\n";
                                    }
                                }
                            }
                        }
                    }
                }
                else if(opcionMenuLinea == 4){
                    break;
                }

            }
        }
        else{
            break;
        }
    }

    return 0;
}
