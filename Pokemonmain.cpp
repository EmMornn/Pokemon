#include <iostream>
#include "Pokemon.h" // Aca estoy invocando por decir asi a un archivo que esta dentro de esta misma carpeta en este caso el pokemon.h
#include <cstdlib>
#include <ctime>
// Importante recordar que para que funcione el archivo donde construi el pokemon no debe tener al final el .cpp

using namespace std;

int main() {
    
    
    Pokemon torchic("Torchic", "Fuego", 60, 17, 10, 15);
    Pokemon treecko("Treecko", "Planta", 60, 14, 12, 20);
    Pokemon mudkip("Mudkip", "Agua", 65, 15, 15, 10);

Pokemon catalogoEnemigos[10] = {
    Pokemon("Wurmple", "Bicho", 35, 8, 5, 10),
    Pokemon("Poochyena", "Siniestro", 40, 12, 8, 15),
    Pokemon("Zigzagoon", "Normal", 45, 10, 10, 18),
    Pokemon("Taillow", "Volador", 45, 15, 8, 25),
    Pokemon("Wingull", "Agua", 50, 12, 10, 20),
    Pokemon("Ralts", "Psíquico", 40, 18, 5, 15),
    Pokemon("Shroomish", "Planta", 60, 12, 15, 8),
    Pokemon("Whismur", "Normal", 65, 14, 10, 10),
    Pokemon("Slakoth", "Normal", 70, 18, 15, 5),
    Pokemon("Makuhita", "Lucha", 80, 16, 15, 10)
    };

    Pokemon liderNosepass("Nosepass", "Roca", 150, 25, 30, 10);

    /* Esto es para comprobar que los datos sean correctos, el pokemon.nombre esta declarado 
    en pokemon.h en la parte de abajo que dice nombre = _nombre por eso lo dejare comentado, 
    si quieren probarlo solo quiten el asterico y la pleca.
    cout << "Sistemas en linea." << endl;
    cout << "Recluta 1 listo: " << torchic.nombre << " (Atk: " << torchic.ataque << ")" << " (Def: " << torchic.defensa << ")" << " (Ps: " << torchic.vidaMax << ")"  << endl;
    cout << "Recluta 2 listo: " << treecko.nombre << " (Atk: " << treecko.ataque << ")" << " (Def: " << treecko.defensa << ")" << " (Ps: " << treecko.vidaMax << ")"  << endl;
    cout << "Recluta 3 listo: " << mudkip.nombre << " (Atk: " << mudkip.ataque << ")" << " (Def: " << mudkip.defensa << ")" << " (Ps: " << mudkip.vidaMax << ")"  << endl;
*/
    return 0;
}