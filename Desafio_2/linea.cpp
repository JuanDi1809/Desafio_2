#include "linea.h"
#include <iostream>
#include <string>

using namespace std;

linea::linea(string _nombre): nombre(_nombre) {}

string linea::obtenerNombre() const {
    return nombre;
}
