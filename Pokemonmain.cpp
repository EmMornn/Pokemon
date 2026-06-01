#include <iostream>
#include "Pokemon.h" // Aca estoy invocando por decir asi a un archivo que esta dentro de esta misma carpeta en este caso el pokemon.h
#include <cstdlib>
#include <ctime>
// Importante recordar que para que funcione el archivo donde construi el pokemon no debe tener al final el .cpp

int mostrarMenu();

using namespace std;

int main() {

    srand(time(0));

int victorias = 0; // Iniciamos las victorias en 0 pero despues aumentan
bool playerVivo = true; // Esto nos sirve para cuando estemos en el bucle de batalla y perdamos, cambiara a falso y termina el bucle
int pociones = 15; // Tambien tenemos cura y declaramos que inicialmente empiezan con 15, o podemos cambiarlo luego
int opbattle; // esto va a ser para atacar o curarse
int opMenu;
    
    Pokemon torchic("Torchic", "Fuego", 60, 17, 10, 15);
    Pokemon treecko("Treecko", "Planta", 60, 14, 12, 20);
    Pokemon mudkip("Mudkip", "Agua", 65, 15, 15, 10);

    Pokemon miPokemon = torchic; 
    // Supuestamente debemos declarar o generar un pokemon por defecto pero 
    //esto no importa porque despues el jugador lo elige ya en la aventura

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

do
{
    opMenu = mostrarMenu();

    switch (opMenu)
    {
    case 1:
        cout << endl;
        cout << "Empezando la Aventura...";
        cout << endl;

        break;
    case 2:
        cout << endl;
        cout << "Tu historial de victorias en esta sesion es: " << victorias << endl << endl;
        break;
    case 3:
        cout << endl;
        cout << "Juego creado por:  " << endl;
        cout << " Emiliano Moran " << endl;
        cout << " Isai... " << endl;
        cout << " Josue De Paz " << endl;
        cout << " Amilcar... " << endl << endl;
        cout << " Agradecimientos especiales a... " << endl;
        cout << endl;
        break;
    case 4:
        cout << endl;
        cout << "Cerrando el juego..." << endl << endl;
        break;
    default:
        cout << endl;
        cout << "Opcion no reconocida, vuelva a intentarlo" << endl << endl;
        break;
    }
} while (opMenu != 4);


    return 0;
}

int mostrarMenu(){
int seleccion;
cout << endl;
cout << "======================================================" << endl;
cout << "                AVENTURA POKEMON FDP C1               " << endl;
cout << "======================================================" << endl;
cout << endl;
cout << "1. JUGAR" << endl;
cout << "2. HISTORIAL DE VICTORIAS" << endl;
cout << "3. CREDITOS Y AGRADECIMIENTOS"<< endl;
cout << "4. SALIR " << endl;
cout << " Selecciona una opcion: ";

cin >> seleccion;
return seleccion;



}