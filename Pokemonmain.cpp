#include <iostream>
#include "Pokemon.h" // Aca estoy invocando por decir asi a un archivo que esta dentro de esta misma carpeta en este caso el pokemon.h
#include <cstdlib>
#include <ctime>
// Importante recordar que para que funcione el archivo donde construi el pokemon no debe tener al final el .cpp

// Lo sacamos de nuestra libreria y lo usamos como una funcion
void subirNivel(Pokemon &p) {
p.vidaMax += 10;
p.vidaActual = p.vidaMax;
p.ataque += 5;
p.defensa += 4;
};

void escalarStats(Pokemon &p, int victorias) {
p.vidaMax += (victorias * 7); 
p.vidaActual = p.vidaMax ;
p.ataque += (victorias * 4);  
p.defensa += (victorias * 2);
};

int mostrarMenu();
void ejecutarBatalla(Pokemon &jugador, Pokemon &enemigo, int &pociones);

using namespace std;



int main() {

    srand(time(0));

int victoriastotales = 0;

int victorias = 0; // Iniciamos las victorias en 0 pero despues aumentan
bool jugadorVivo = true; // Esto nos sirve para cuando estemos en el bucle de batalla y perdamos, cambiara a falso y termina el bucle
int pociones = 15; // Tambien tenemos cura y declaramos que inicialmente empiezan con 15, o podemos cambiarlo luego
int opbattle; // esto va a ser para atacar o curarse
int opMenu;
    
    Pokemon torchic = {"Torchic", "Fuego", 60, 60, 17, 10, 15};
    Pokemon treecko = {"Treecko", "Planta", 60, 60,  14, 12, 20};
    Pokemon mudkip= {"Mudkip", "Agua", 65, 65, 15, 15, 10};

    Pokemon miPokemon = torchic; 
    // Supuestamente debemos declarar o generar un pokemon por defecto pero 
    //esto no importa porque despues el jugador lo elige ya en la aventura

Pokemon catalogoEnemigos[10] = {
{"Wurmple", "Bicho", 35, 35, 8, 5, 10},
{"Poochyena", "Siniestro", 40, 40, 12, 8, 15},
{"Zigzagoon", "Normal", 45, 45, 10, 10, 18},
{"Taillow", "Volador", 45, 45, 15, 8, 25},
{"Wingull", "Agua", 50, 50, 12, 10, 20},
{"Ralts", "Psíquico", 40, 40, 18, 5, 15},
{"Shroomish", "Planta", 60, 60, 12, 15, 8},
{"Whismur", "Normal", 65, 65, 14, 10, 10},
{"Slakoth", "Normal", 70, 70, 18, 15, 5},
{"Makuhita", "Lucha", 80, 80, 14, 15, 10}
};

Pokemon liderNosepass{"Nosepass", "Roca", 150, 150, 40, 40, 30};

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
// Reiniciamos todo por si quieres volver a darle "1. Jugar" en el menú
    victorias = 0;
    jugadorVivo = true;
    pociones = 15; 

        cout << endl;
        cout << "Empezando la Aventura..." << endl;

    int seleccionInicial;

    cout << "El profesor Guayaba te ofrece a tu companero de Aventura!" << endl;
    cout << "Selecciona uno de los pokemon iniciales. A quien eliges?: " << endl;
    cout << "1. Treeko (Planta)" << endl;
    cout << "2. Mudkip (Agua)" << endl;
    cout << "3. Torchic (Fuego)" << endl; // La verdad esta es la mejor eleccion de las 3. Atte: Emiliano
    cout << "Pokemon: ";
    cin >> seleccionInicial;
    cout << endl;

    if (seleccionInicial == 1) miPokemon = treecko;
    else if (seleccionInicial == 2) miPokemon = mudkip;
    else if (seleccionInicial == 3) miPokemon = torchic;
    else{ cout << "Opcion invalida. El Profesor te da a el vegano por defecto." << endl;
        miPokemon = treecko;}
    cout << "Has elegido a " << miPokemon.nombre << "!" << endl;
    cout << "Que comience tu aventura!" << endl << endl;



cout << "Derrota a tus oponentes para enfrentar al lider de Gimnasio" << endl;
cout << "Buena suerte!" << endl; 

while (jugadorVivo == true && victorias < 10) {
                
    int indiceAleatorio = rand() % 10; // Generamos un enemigo
    Pokemon rivalActual = catalogoEnemigos[indiceAleatorio];
                
    escalarStats(rivalActual, victorias); // Aumentamos stats por cada combate

    ejecutarBatalla(miPokemon, rivalActual, pociones); // Empieza la batalla
                
    if (miPokemon.vidaActual > 0) { // Al terminar la batalla, evaluamos qué pasa:
                    
    victorias++; // Si sigues vivo, ganaste esta ronda
    victoriastotales++;
    subirNivel(miPokemon); // Nuestro Pokémon se vuelve más fuerte
    cout << "[ Progreso: " << victorias << " / 10 victorias ]" << endl;
                    
    system("pause"); // Pausa para que el jugador pueda respirar antes de la siguiente pelea

    } else { // Si tu vida bajó a 0, perdiste
    jugadorVivo = false; }
    }  
    if (jugadorVivo == true && victorias == 10) {
        cout << endl;
        cout << "=========================================================" << endl;
        cout << "              EL LIDER NOSEPASS TE DESAFIA               " << endl;
        cout << "=========================================================" << endl;
        
        escalarStats(liderNosepass, 12);
        ejecutarBatalla(miPokemon, liderNosepass, pociones);
        
        if (miPokemon.vidaActual > 0) {
            cout << "\n¡FELICIDADES! ¡HAS GANADO EL JUEGO!\n" << endl;
        }
    }     

     cout << endl;

        break;
   case 2:
        cout << endl;
        cout << "=============================================================" << endl;
        cout << "                ESTADISTICAS DE LA SESION                " << endl;
        cout << "=============================================================" << endl << endl;
        cout << " Victorias en la ultima partida: " << victorias << endl;
        cout << " Total de victorias acumuladas:  " << victoriastotales << endl;
        cout << "=============================================================\n" << endl;
        break;
    case 3:
        cout << endl;
        cout << "Juego creado por:  " << endl;
        cout << " Emiliano Moran " << endl;
        cout << " Isai Umana " << endl;
        cout << " Josue De Paz " << endl;
        cout << " El otro " << endl << endl;
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
cout << endl << endl;
cout << "===============================================================" << endl;
cout << "                    AVENTURA POKEMON FDP C1                    " << endl;
cout << "===============================================================" << endl;
cout << endl;
cout << "1. JUGAR" << endl;
cout << "2. HISTORIAL DE VICTORIAS" << endl;
cout << "3. CREDITOS Y AGRADECIMIENTOS"<< endl;
cout << "4. SALIR " << endl;
cout << " Selecciona una opcion: ";

cin >> seleccion;
return seleccion;
}

// --- EL ENGRANAJE MENOR (LA BATALLA) ---
void ejecutarBatalla(Pokemon &jugador, Pokemon &enemigo, int &pociones) {
    cout << "\n===========================================" << endl;
    cout << "     Comienza la pelea contra " << enemigo.nombre << "!" << endl;
    cout << "===========================================\n" << endl;

    // 1. Usamos vidaActual para verificar si ambos siguen vivos
    while (jugador.vidaActual > 0 && enemigo.vidaActual > 0) {
        
    bool jugadorVaPrimero = true;

        // 2. Evaluamos usando tu variable 'velocidad'
    if (enemigo.velocidad > jugador.velocidad) {
        jugadorVaPrimero = false; }

    if (jugadorVaPrimero) {
        // --- TURNO 1: JUGADOR ---
        int accion;
        cout << "\n[ PS " << jugador.nombre << ": " << jugador.vidaActual << " | PS " << enemigo.nombre << ": " << enemigo.vidaActual << " ]";
        cout << "\nTu turno. 1. Atacar | 2. Usar Pocion (" << pociones << " restantes): ";
        cin >> accion;
            
    if (accion == 1) {
        // Eligió atacar, abrimos el moveset
        int mov;
        cout << "\n--- MOVIMIENTOS ---" << endl;
        cout << "1. Aranazo (Danio normal)" << endl;
        if (jugador.tipo == "Fuego") cout << "2. Ascuas (Ataque Especial)" << endl;
        else if (jugador.tipo == "Agua") cout << "2. Pistola Agua (Ataque Especial)" << endl;
        else cout << "2. Hoja Afilada (Ataque Especial)" << endl;
        cout << "3. Grunido (Bajar Defensa rival)" << endl;
        cout << "4. Afilagarras (Subir tu Ataque)" << endl;
        cout << "Elige un movimiento (1-4): ";
        cin >> mov;
        cout << endl;

        if (mov == 1) {
            int danio = jugador.ataque - (enemigo.defensa / 2);
        if (danio < 1) danio = 1;
            enemigo.vidaActual -= danio;
            cout << "-> " << jugador.nombre << " usa Aranazo y causa " << danio << " de danio!" << endl;
        } else if (mov == 2) {
            int danio = (jugador.ataque + 5) - (enemigo.defensa / 2);
        if (danio < 1) danio = 1;
            enemigo.vidaActual -= danio;
            cout << "-> " << jugador.nombre << " usa su Ataque Especial y causa " << danio << " de danio!" << endl;
        } else if (mov == 3) {
            enemigo.defensa -= 2;
        if (enemigo.defensa < 1) enemigo.defensa = 1;
            cout << "-> " << jugador.nombre << " usa Grunido! La defensa del rival ha bajado." << endl;
        } else if (mov == 4) {
            jugador.ataque += 3;
            cout << "-> " << jugador.nombre << " usa Afilagarras! Su ataque ha subido." << endl; }
        else {
            cout << "-> " << jugador.nombre << " no sabe ese movimiento, aparentemente se confundio y pierde turno. :(  " << endl; }
            } else {
                // Eligió curarse
                if (pociones > 0) {
                    jugador.vidaActual += 35;
                    pociones--;
                    if (jugador.vidaActual > jugador.vidaMax) jugador.vidaActual = jugador.vidaMax;
                    cout << "-> Has usado una pocion! Recuperas 35 PS. Te quedan " << pociones << " pociones." << endl;
                } else {
                    cout << "-> Oh no! No te quedan pociones. Pierdes el turno buscando en la mochila vacia..." << endl;
                }
            }

            if (enemigo.vidaActual <= 0) break;

            // --- TURNO 2: ENEMIGO ---
            int danioEnemigo = enemigo.ataque - (jugador.defensa / 2);
            if (danioEnemigo < 1) danioEnemigo = 1;
            jugador.vidaActual -= danioEnemigo;
            cout << "-> " << enemigo.nombre << " contraataca y causa " << danioEnemigo << " de danio!" << endl;

        } else {
            // --- TURNO 1: ENEMIGO (Es más rápido) ---
            int danioEnemigo = enemigo.ataque - (jugador.defensa / 2);
            if (danioEnemigo < 1) danioEnemigo = 1;
            jugador.vidaActual -= danioEnemigo;
            cout << "\n-> " << enemigo.nombre << " es mas rapido y ataca! Causa " << danioEnemigo << " de danio." << endl;

            if (jugador.vidaActual <= 0) break;

            // --- TURNO 2: JUGADOR ---
            int accion;
            cout << "\n[ PS " << jugador.nombre << ": " << jugador.vidaActual << " | PS " << enemigo.nombre << ": " << enemigo.vidaActual << " ]";
            cout << "\nTu turno. 1. Atacar | 2. Usar Pocion (" << pociones << " restantes): ";
            cin >> accion;
            
            if (accion == 1) {
                int mov; // Este es el movepool de los pokemon, 
                            // en si los por defecto son aranazo, y los 2 de stats, y dependiendo el inicial el at. esp
                cout << "\n--- MOVIMIENTOS ---" << endl;
                cout << "1. Aranazo (Danio normal)" << endl;
                if (jugador.tipo == "Fuego") cout << "2. Ascuas (Ataque Especial)" << endl;
                else if (jugador.tipo == "Agua") cout << "2. Pistola Agua (Ataque Especial)" << endl;
                else cout << "2. Hoja Afilada (Ataque Especial)" << endl;
                cout << "3. Grunido (Bajar Defensa rival)" << endl;
                cout << "4. Afilagarras (Subir tu Ataque)" << endl;
                cout << "Elige un movimiento (1-4): ";
                cin >> mov;
                cout << endl;

                if (mov == 1) {
                    int danio = jugador.ataque - (enemigo.defensa / 2);
                    if (danio < 1) danio = 1;
                    enemigo.vidaActual -= danio;
                    cout << "-> " << jugador.nombre << " usa Aranazo y causa " << danio << " de danio!" << endl;
                } else if (mov == 2) {
                    int danio = (jugador.ataque + 5) - (enemigo.defensa / 2);
                    if (danio < 1) danio = 1;
                    enemigo.vidaActual -= danio;
                    cout << "-> " << jugador.nombre << " usa su Ataque Especial y causa " << danio << " de danio!" << endl;
                } else if (mov == 3) {
                    enemigo.defensa -= 2;
                    if (enemigo.defensa < 1) enemigo.defensa = 1;
                    cout << "-> " << jugador.nombre << " usa Grunido! La defensa del rival ha bajado." << endl;
                } else if (mov == 4) {
                    jugador.ataque += 3;
                    cout << "-> " << jugador.nombre << " usa Afilagarras! Su ataque ha subido." << endl;
                }
                 else {
            cout << "-> " << jugador.nombre << " no sabe ese movimiento, aparentemente se confundio y pierde turno. :(  " << endl; }
            } else {
                if (pociones > 0) {
                    jugador.vidaActual += 10;
                    pociones--;
                    if (jugador.vidaActual > jugador.vidaMax) jugador.vidaActual = jugador.vidaMax;
                    cout << "-> Has usado una pocion! Recuperas 35 PS. Te quedan " << pociones << " pociones." << endl;
                } else {
                    cout << "-> Oh no! No te quedan pociones. Pierdes el turno buscando en la mochila vacia..." << endl;
                }
            }
        }
    }

    if (jugador.vidaActual <= 0) {
        cout << "\nHas perdido la batalla...\n";
    } else {
        cout << "\nHas ganado la batalla!\n";
    }
}