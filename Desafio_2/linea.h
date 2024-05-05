#ifndef LINEA_H
#define LINEA_H

#include <string>
using namespace std;

class linea
{
private:
    string nombre;
public:
    //constructor
    linea(string);

    //getter
    string obtenerNombre() const;


};

#endif // LINEA_H
