#include <QCoreApplication>
#include <string>
#include "Menu.h"

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
            while(true){
                Menu menu2;
                menu2.menuLinea();

                int opcionesLinea[] = {1, 2, 3, 4, 5, 6};

                int opcionLinea = menu2.validarOpcion(opcionesLinea, 6);
            }
        }
        else if(opcionRed == 2){
            cout << "De momenot no hay lineas, ni estaciones creadas" << endl ; //cuando se hacen verificaciones, este es ek mensaje a mostrar
        }
        else{
            break;
        }

    }

    return 0;
}
