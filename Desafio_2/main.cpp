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
                        r1.listarLineas();
                        string nombreEliminar;
                        cout << "Escribe la linea que deseas eliminar: ";
                        cin >> nombreEliminar;

                        //se busca la linea usando el nombre
                        Linea *linea = r1.getObjetoLinea(nombreEliminar);

                        //tomando el nombre de la estacion
                        if(linea->getEstacionTransicion()){
                            cout << "Advertencia: la linea tiene una estacion de transicion, no se puede eliminar."<<endl;
                            break;
                        }else{
                            r1.eliminarLinea(nombreEliminar);
                            r1.listarLineas();
                            cout << "La linea se elimino exitosamente\n";
                        }


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

                            cout << "Estacion agregada con exito\n";
                        }
                        else{
                            string nombreEstacion = linea->verificarEstacion1();

                            while(true){
                                Menu menu4;

                                cout << "Como quieres agregar la estacion?\n";
                                menu4.menuUbicacion();
                                int opcionMenuUbicaion = menu4.validarOpcion(3);

                                if(opcionMenuUbicaion == 1 ){
                                    int tiempoSiguiente;

                                    //se llama el objeto estacion xd
                                    string estacionInicial = linea->getEstacionInicial();
                                    Estacion *estacionAmodificar = linea->getObjetoEstacion(estacionInicial);

                                    cout << "Establece el tiempo de la estacion " << nombreEstacion << " a " << estacionAmodificar->getNombreEstacion() << ": ";
                                    cin >> tiempoSiguiente;

                                    //actualizar tiempos de manera simultanea
                                    linea->ampliarListaEstaciones();
                                    linea->agregarEstacionInicio(nombreEstacion, false, 0, tiempoSiguiente);

                                    //se cambia el tiempo anterior de la estacion que se modifica a el tiempo siguiente
                                    estacionAmodificar->setTanterior(tiempoSiguiente);
                                    cout << "La estacion se agrego exitosamente"<<endl;

                                    /*
                                    Estacion *prueba = linea->getObjetoEstacion(nombreEstacion);
                                    cout << estacionAmodificar->getNombreEstacion() << " tiempo anterior: " << estacionAmodificar->getAnterior() << endl;
                                    cout << prueba->getNombreEstacion() << " tiempo siguiente: " << prueba->getSiguiente()<< endl;
                                    cout << prueba->getNombreEstacion() << " tiempo anterior: " << prueba->getAnterior()<< endl;
                                    cout << estacionAmodificar->getNombreEstacion() << "tiempo siguiente: " << estacionAmodificar->getSiguiente() <<endl;*/
                                    break;
                                }
                                else if(opcionMenuUbicaion == 2){
                                    int tAnterior;

                                    //se llama al objeto estacion
                                    string estacionFinal = linea->getEstacionFinal();
                                    Estacion *estacionModificar = linea->getObjetoEstacion(estacionFinal);

                                    cout << "ingresa el tiempo de la estacion " << estacionModificar->getNombreEstacion() << " a " << nombreEstacion << ": ";
                                    cin >> tAnterior;

                                    linea->ampliarListaEstaciones();
                                    linea->agregarEstacionFinal(nombreEstacion, false, tAnterior, 0);

                                    estacionModificar->setTsiguiente(tAnterior);
                                    cout << "la estacion se agrego exitosamente";
                                    break;
                                }
                                else{
                                    if(linea->getCantEstaciones() >= 2){
                                        Menu m;
                                        int tAnterior, tSiguiente;

                                        cout << "Seleccion en medio de que estaciones quieres agregar la estacion\n";
                                        linea->listarEstaciones2();

                                        int opcionEstaciones = m.validarOpcion(linea->getCantEstaciones() - 1);

                                        Estacion* estacionAnterior = linea->getObjetoEstacion2(opcionEstaciones);
                                        Estacion* estacionSiguiente = linea->getObjetoEstacion2(opcionEstaciones + 1);

                                        cout << "Ingrese el tiempo de la estacion " << estacionAnterior->getNombreEstacion() << " a " << nombreEstacion;
                                        cin >> tAnterior;

                                        cout << "Ingrese el timepo de la estacion " << nombreEstacion << " a " << estacionSiguiente->getNombreEstacion();
                                        cin >> tSiguiente;

                                        //Actualizo los tiempos de las estaciones
                                        estacionAnterior->setTsiguiente(tAnterior);
                                        estacionSiguiente->setTanterior(tSiguiente);

                                        //Arego la estacion
                                        linea->ampliarListaEstaciones();
                                        linea->agregarEstacionMedio(nombreEstacion, false, tAnterior, tSiguiente, estacionAnterior->getNombreEstacion());

                                        cout << "La estacion se agrego exitosamente\n";
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
                            cout << "Selecciona linea con la que se conecta " << linea->getNombreLinea() << endl;
                            r1.listarLineas2(nombreLinea);

                            string nombreLineaConexion = r1.verificarLinea2();

                            Linea* lineaConexion = r1.getObjetoLinea(nombreLineaConexion);

                            cout << "Seleciona la estacion que va a conectar la linea\n";
                            lineaConexion->listarEstaciones();
                            string nombreEstacionConexion = lineaConexion->verificarEstacion2();

                            Estacion *estacionAgregada = lineaConexion-> getObjetoEstacion(nombreEstacionConexion);

                            if(estacionAgregada->getEsTransicion()){
                                linea->ampliarListaEstaciones();
                                linea->agregarEstacionInicio(nombreEstacionConexion, true, 0, 0);
                            }else{
                                estacionAgregada->setEsTransicion();
                                linea->ampliarListaEstaciones();
                                linea->agregarEstacionInicio(nombreEstacionConexion, true, 0, 0);
                            }
                        }
                        else{
                            string nombreEstacion = linea->verificarEstacion1() ;

                            while(true){
                                Menu menu4;

                                cout << "Como quieres agregar la estacion?\n";
                                menu4.menuUbicacion();
                                int opcionMenuUbicaion = menu4.validarOpcion(3);

                                //se llama el objeto estacion
                                string estacionInicial = linea->getEstacionInicial();
                                Estacion *estacionAmodificar = linea->getObjetoEstacion(estacionInicial);

                                if(opcionMenuUbicaion == 1 ){
                                    int tiempoSiguiente;
                                    cout << "Establece el tiempo de la estacion " << nombreEstacion << " a " << estacionAmodificar->getNombreEstacion() << ": ";
                                    cin >> tiempoSiguiente;

                                    //actualizar tiempos de manera simultanea
                                    linea->ampliarListaEstaciones();
                                    linea->agregarEstacionInicio(nombreEstacion, false, 0, tiempoSiguiente);

                                    //se cambia el tiempo anterior de la estacion que se modifica a el tiempo siguiente
                                    estacionAmodificar->setTanterior(tiempoSiguiente);
                                    cout << "La estacion se agrego exitosamente"<<endl;

                                    break;
                                }
                                else if(opcionMenuUbicaion == 2){
                                    int tAnterior;

                                    //se piden los tiempos y luego se el pasan al metodo agregar estacion
                                    string estacionFinal = linea->getEstacionFinal();
                                    Estacion *estacionModificar = linea->getObjetoEstacion(estacionFinal);

                                    cout << "ingresa el tiempo de la estacion " << estacionModificar->getNombreEstacion() << " a " << nombreEstacion << ": ";
                                    cin >> tAnterior;

                                    estacionModificar->setTsiguiente(tAnterior);

                                    linea->ampliarListaEstaciones();
                                    linea->agregarEstacionFinal(nombreEstacion, false, tAnterior, 0);

                                    cout << "la estacion se agrego exitosamente";
                                    break;
                                }
                                else{
                                    if(linea->getCantEstaciones() >= 2){
                                        Menu m;
                                        int tAnterior, tSiguiente;

                                        cout << "Seleccion en medio de que estaciones quieres agregar la estacion\n";
                                        linea->listarEstaciones2();

                                        int opcionEstaciones = m.validarOpcion(linea->getCantEstaciones() - 1);

                                        Estacion* estacionAnterior = linea->getObjetoEstacion2(opcionEstaciones);
                                        Estacion* estacionSiguiente = linea->getObjetoEstacion2(opcionEstaciones + 1);

                                        cout << "Ingrese el tiempo de la estacion " << estacionAnterior->getNombreEstacion() << " a " << nombreEstacion;
                                        cin >> tAnterior;

                                        cout << "Ingrese el timepo de la estacion " << nombreEstacion << " a " << estacionSiguiente->getNombreEstacion();
                                        cin >> tSiguiente;

                                        //Actualizo los tiempos de las estaciones
                                        estacionAnterior->setTsiguiente(tAnterior);
                                        estacionSiguiente->setTanterior(tSiguiente);

                                        //Arego la estacion
                                        linea->ampliarListaEstaciones();
                                        linea->agregarEstacionInicio(nombreEstacion, false, tAnterior, tSiguiente);

                                        cout << "La estacion se agrego exitosamente\n";

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
                else if(opcionMenuLinea == 2){//Elimnar estacion
                    cout << "Elminar estacion";
                }

                else if(opcionMenuLinea == 3){//Estaciones en una linea
                    cout << "Escoge la linea en donde desea saber su cantidad de estaciones:\n";
                    r1.listarLineas();

                    string nombreLinea = r1.verificarLinea2();
                    Linea* linea = r1.getObjetoLinea(nombreLinea);

                    cout << "La cantidad de estaciones que hay en la linea " << nombreLinea << " son " << linea->getCantEstaciones() << " estaciones\n";
                }
                else{
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
