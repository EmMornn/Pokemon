#include <iostream>
#include "Pokemon.h" // Aca estoy invocando por decir asi a un archivo que esta dentro de esta misma carpeta en este caso el pokemon.h
// Importante recordar que para que funcione el archivo donde construi el pokemon no debe tener al final el .cpp
using namespace std;

int main() {
    
    
    Pokemon torchic("Torchic", "Fuego", 60, 17, 10, 15);
    Pokemon treecko("Treecko", "Planta", 60, 14, 12, 20);
    Pokemon mudkip("Mudkip", "Agua", 65, 15, 15, 10);

    // Esto es para comprobar que los datos sean correctos, el pokemon.nombre esta declarado en pokemon.h en la parte de abajo que dice nombre = _nombre
    cout << "Sistemas en linea." << endl;
    cout << "Recluta 1 listo: " << torchic.nombre << " (Atk: " << torchic.ataque << ")" << " (Def: " << torchic.defensa << ")" << " (Ps: " << torchic.vidaMax << ")"  << endl;
    cout << "Recluta 2 listo: " << treecko.nombre << " (Atk: " << treecko.ataque << ")" << " (Def: " << treecko.defensa << ")" << " (Ps: " << treecko.vidaMax << ")"  << endl;
    cout << "Recluta 3 listo: " << mudkip.nombre << " (Atk: " << mudkip.ataque << ")" << " (Def: " << mudkip.defensa << ")" << " (Ps: " << mudkip.vidaMax << ")"  << endl;

    return 0;
}