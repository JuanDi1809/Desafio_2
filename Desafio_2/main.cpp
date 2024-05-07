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
                                    int tiempoSiguiente;
                                    cout << "Establece el tiempo de la estacion " << nombreEstacion << " a " << estacionAmodificar->getNombreEstacion();
                                    cin >> tiempoSiguiente;

                                    //actualizar tiempos de manera simultanea
                                    linea->ampliarListaEstaciones();
                                    linea->agregarEstacionInicio(nombreEstacion, false, 0, tiempoSiguiente);

                                    //se cambia el tiempo anterior de la estacion que se modifica a el tiempo siguiente
                                    estacionAmodificar->setTanterior(tiempoSiguiente);
                                    cout << "los tiempos se modificaron exitosamente"<<endl;

                                    /*
                                    Estacion *prueba = linea->getObjetoEstacion(nombreEstacion);
                                    cout << estacionAmodificar->getNombreEstacion() << " tiempo anterior: " << estacionAmodificar->getAnterior() << endl;
                                    cout << prueba->getNombreEstacion() << " tiempo siguiente: " << prueba->getSiguiente()<< endl;
                                    cout << prueba->getNombreEstacion() << " tiempo anterior: " << prueba->getAnterior()<< endl;
                                    cout << estacionAmodificar->getNombreEstacion() << "tiempo siguiente: " << estacionAmodificar->getSiguiente() <<endl;*/
                                    break;
                                }
                                else if(opcionMenuUbicaion == 2){
                                    string nuevaEstacion;
                                    int tAnterior;
                                    cout << "Ingresa el nombre de la estacion a agregar: ";cin>>nuevaEstacion;

                                    //se piden los tiempos y luego se el pasan al metodo agregar estacion
                                    string estacionFinal = linea->getEstacionFinal();
                                    Estacion *estacionModificar = linea->getObjetoEstacion(estacionFinal);

                                    cout << "ingresa el tiempo de la estacion " << estacionModificar->getNombreEstacion() << " a " << nuevaEstacion; cin >> tAnterior;
                                    estacionModificar->setTsiguiente(tAnterior);

                                    linea->ampliarListaEstaciones();
                                    linea->agregarEstacionInicio(nombreEstacion, false, tAnterior, 0);
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
