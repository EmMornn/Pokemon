#include <iostream>
#include "Pokemon.h" // Aca estoy invocando por decir asi a un archivo que esta dentro de esta misma carpeta en este caso el pokemon.h
#include <cstdlib>
#include <ctime>
#include <chrono>  // controlara el tiempo
#include <thread>  // permite hacer pausas
#include <fstream> // lo usaremos para guardar las victorias en un .txt
// Importante recordar que para que funcione el archivo donde construi el pokemon no debe tener al final el .cpp

// Lo sacamos de nuestra libreria y lo usamos como una funcion
void subirNivel(Pokemon &p)
{
    p.vidaMax += 10;
    p.vidaActual = p.vidaMax;
    p.ataque += 5;
    p.defensa += 4;
};

void escalarStats(Pokemon &p, int victorias)
{
    p.vidaMax += (victorias * 7);
    p.vidaActual = p.vidaMax;
    p.ataque += (victorias * 4);
    p.defensa += (victorias * 2);
};

int mostrarMenu();
void ejecutarBatalla(Pokemon &jugador, Pokemon &enemigo, int &pociones, int &superPociones);

void textoAnimado(string texto, int velocidad)
{
    for (char letra : texto)
    {
        cout << letra;
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(velocidad));
    }
}

using namespace std;

int main()
{

    srand(time(0));

    // -- VARIABLES O VICTORIAS QUE GUARDAMOS GLOBALMENTE --
    int totalesVictorias = 0;
    int totalesJefes = 0;
    int anteriorVictorias = 0;
    int anteriorJefes = 0;

    // -- VARIABLES DE LA SESIÓN ACTUAL --
    int actualVictorias = 0;
    int actualJefes = 0;

    // -- CONTROL Y RESET DE PARTIDA --
    int victorias = 0;       // Iniciamos las victorias en 0 pero despues aumentan
    bool jugadorVivo = true; // Esto nos sirve para cuando estemos en el bucle de batalla y perdamos, cambiara a falso y termina el bucle
    int pociones = 15;       // Tambien tenemos cura y declaramos que inicialmente empiezan con 15, o podemos cambiarlo luego
    int superPociones = 5;

    int opbattle; // esto va a ser para atacar o curarse
    int opMenu;

    ifstream archivoLectura("guardado.txt");
    if (archivoLectura.is_open())
    {
        archivoLectura >> totalesVictorias;
        archivoLectura >> totalesJefes;
        archivoLectura >> anteriorVictorias;
        archivoLectura >> anteriorJefes;
        archivoLectura.close();
    }

    Pokemon torchic = {"Torchic", "Fuego", 60, 60, 17, 10, 15};
    Pokemon treecko = {"Treecko", "Planta", 60, 60, 14, 12, 20};
    Pokemon mudkip = {"Mudkip", "Agua", 65, 65, 15, 15, 10};

    Pokemon miPokemon = torchic;
    // Supuestamente debemos declarar o generar un pokemon por defecto pero
    // esto no importa porque despues el jugador lo elige ya en la aventura

    Pokemon catalogoEnemigos[20] = {
        // TIER 1: (ENCUENTROS INICIALES)
        {"Wurmple", "Bicho", 35, 35, 8, 5, 10},
        {"Azurill", "Normal", 50, 50, 9, 10, 11},
        {"Lotad", "Agua", 45, 45, 10, 11, 12},
        {"Seedot", "Planta", 45, 45, 11, 14, 10},

        // TIER 2: (VELOCIDAD Y ESTADO)
        {"Poochyena", "Siniestro", 40, 40, 12, 8, 15},
        {"Surskit", "Agua", 45, 45, 11, 9, 20},
        {"Zigzagoon", "Normal", 45, 45, 10, 10, 18},
        {"Nincada", "Bicho", 40, 40, 13, 18, 12},

        // TIER 3: (PELIGRO DE DAÑO REAL)
        {"Zubat", "Volador", 45, 45, 14, 10, 24},
        {"Ralts", "Psiquico", 40, 40, 19, 5, 16},
        {"Electrike", "Electrico", 45, 45, 15, 11, 25},
        {"Wingull", "Agua", 50, 50, 12, 10, 20},

        // --- TIER 4: (PESOS MEDIOS)
        {"Goldeen", "Agua", 50, 50, 14, 12, 16},
        {"Skitty", "Normal", 55, 55, 11, 11, 18},
        {"Whismur", "Normal", 65, 65, 14, 10, 10},
        {"Taillow", "Volador", 45, 45, 18, 8, 26},

        // TIER 5: (PRE-JEFE)
        {"Shroomish", "Planta", 60, 60, 12, 15, 8},
        {"Aron", "Acero", 70, 70, 17, 26, 9},
        {"Slakoth", "Normal", 70, 70, 22, 16, 6},
        {"Makuhita", "Lucha", 80, 80, 16, 16, 11}};

    Pokemon liderNosepass{"Nosepass", "Roca", 150, 150, 33, 35, 30};
    // Proximo a ampliar para ser mas variada y emocionante la aventura (piensen ideas porfa)

    /* Esto es para comprobar que los datos sean correctos, el pokemon.nombre esta declaradoen pokemon.h en la parte
     de abajo que dice nombre = _nombre por eso lo dejare comentado, si quieren probarlo solo quiten el asterico y la pleca.
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
            // Reiniciamos todo para cuando se vuelva a querer jugar con el programa abierto
            victorias = 0;
            jugadorVivo = true;
            pociones = 15;
            superPociones = 5;

            liderNosepass = {"Nosepass", "Roca", 150, 150, 33, 35, 30}; // Reseteamos al jefe ya que las estadisticas ya habian aumentado en el

            std::system("cls");

            // --- ESCENA 1 ---
            textoAnimado("Recientemente, en un mundo lejano...", 60);
            // Pausa dramática de 2 segundos
            std::system("cls"); // Desaparece el texto

            // --- ESCENA 2 ---
            textoAnimado("Existe un lugar increible, donde humanos y pokemon conviven juntos...", 60);
            this_thread::sleep_for(chrono::seconds(2));
            std::system("cls");

            // --- ESCENA 3 (Llegada del profesor) ---
            textoAnimado("Un camion parece acercarse!\n", 40);
            textoAnimado("Vaya! El conductor frena en seco frente a ti...\n\n", 50);
            this_thread::sleep_for(chrono::seconds(1));

            textoAnimado(" x? :Hola, seguro eres nuevo aqui!\n", 40);
            textoAnimado(" x?: Mi nombre es Profesor Guayaba, veo que estas interesado en una aventura!\n\n", 50);
            this_thread::sleep_for(chrono::seconds(1));

            int seleccionInicial;

            cout << "El profesor Guayaba te ofrece a tu companero de Aventura!" << endl;
            cout << "Selecciona uno de los pokemon iniciales. A quien eliges?: " << endl;
            cout << "1. Treeko (Planta)" << endl;
            cout << "2. Mudkip (Agua)" << endl;
            cout << "3. Torchic (Fuego)" << endl; // La verdad esta es la mejor eleccion de las 3. Atte: Emiliano
            cout << "Pokemon: ";
            cin >> seleccionInicial;
            cout << endl;

            if (seleccionInicial == 1)
                miPokemon = treecko;
            else if (seleccionInicial == 2)
                miPokemon = mudkip;
            else if (seleccionInicial == 3)
                miPokemon = torchic;
            else
            {
                cout << "Opcion invalida. El Profesor te da a el vegano por defecto." << endl;
                miPokemon = treecko;
            }
            cout << "Has elegido a " << miPokemon.nombre << "!" << endl;

            textoAnimado("Derrota a tus oponentes para enfrentar al lider de gimnasio\n", 40);
            textoAnimado("Buena suerte y... Que comienze tu aventura!\n\n", 50);
            this_thread::sleep_for(chrono::seconds(1));

            while (jugadorVivo == true && victorias < 10)
            {

                int indiceAleatorio = rand() % 20; // Generamos un enemigo
                Pokemon rivalActual = catalogoEnemigos[indiceAleatorio];

                escalarStats(rivalActual, victorias); // Aumentamos stats por cada combate

                ejecutarBatalla(miPokemon, rivalActual, pociones, superPociones); // Empieza la batalla

                if (miPokemon.vidaActual > 0)
                { // Al terminar la batalla, evaluamos qué pasa:

                    victorias++;           // Controla el sistema de batalla y el momento en que nos enfrentamos al jefe
                    actualVictorias++;     // Suma al record de la sesion actual
                    totalesVictorias++;    // Suma al récord global de la pc y graba al txt
                    subirNivel(miPokemon); // Nuestro Pokémon se vuelve más fuerte
                    cout << "[ Progreso: " << victorias << " / 10 victorias ]" << endl;

                    system("pause"); // Pausa para que el jugador pueda respirar antes de la siguiente pelea
                }
                else
                { // Si tu vida bajó a 0, perdiste
                    jugadorVivo = false;
                }
            }
            if (jugadorVivo == true && victorias == 10)
            {
                cout << endl;
                cout << "============================================================" << endl;
                cout << "                EL LIDER NOSEPASS TE DESAFIA                " << endl;
                cout << "============================================================" << endl;

                escalarStats(liderNosepass, 5);
                ejecutarBatalla(miPokemon, liderNosepass, pociones, superPociones);

                if (miPokemon.vidaActual > 0)
                {
                    cout << "\nFELICIDADES, HAS GANADO EL JUEGO!\n"
                         << endl;
                    actualJefes++;  // Vencist2e a un jefe en esta sesión
                    totalesJefes++; // Se acumula a tu historial global de jefes derrotados
                }
            }
            cout << endl;

            break;
        case 2:
            cout << endl;
            cout << "==============================================================" << endl;
            cout << "               RECORD HISTORICO (GLOBAL)                 " << endl;
            cout << "==============================================================" << endl;
            cout << " Total de Pokemon derrotados: " << totalesVictorias << endl;
            cout << " Total de Jefes superados:    " << totalesJefes << endl;
            cout << "==============================================================" << endl;
            cout << "               SESION ANTERIOR                           " << endl;
            cout << "==============================================================" << endl;
            cout << " Pokemon derrotados:          " << anteriorVictorias << endl;
            cout << " Jefes superados:             " << anteriorJefes << endl;
            cout << "==============================================================" << endl;
            cout << "               SESION ACTUAL                             " << endl;
            cout << "==============================================================" << endl;
            cout << " Pokemon derrotados hoy:      " << actualVictorias << endl;
            cout << " Jefes superados hoy:         " << actualJefes << endl;
            cout << "==============================================================\n"
                 << endl;
            system("pause");
            break;
        case 3:
            cout << endl;
            cout << "Juego creado por:  " << endl;
            cout << " Emiliano Moran " << endl;
            cout << " Isai Umana " << endl;
            cout << " Josue De Paz " << endl;
            cout << " Amilcar Varela " << endl
                 << endl;
            cout << " Agradecimientos especiales a... " << endl;
            cout << endl;
            break;
        case 4:
        {
            cout << endl;
            cout << "Guardando historial en la tarjeta de memoria..." << endl;

            // --- ESCRITURA EN EL ARCHIVO ---
            ofstream archivoEscritura("guardado.txt");
            if (archivoEscritura.is_open())
            {
                archivoEscritura << totalesVictorias << "\n";
                archivoEscritura << totalesJefes << "\n";
                archivoEscritura << actualVictorias << "\n"; // Se guarda para ser la partida anterior en el próximo inicio
                archivoEscritura << actualJefes << "\n";
                archivoEscritura.close();
                cout << "Historial guardado con exito!" << endl;
            }

            cout << "Cerrando el juego..." << endl
                 << endl;
        }
        break;
        default:
            cout << endl;
            cout << "Opcion no reconocida, vuelva a intentarlo" << endl
                 << endl;
        }
    } while (opMenu != 4);

    return 0;
}

int mostrarMenu()
{
    int seleccion;
    cout << endl
         << endl;
    cout << "===============================================================" << endl;
    cout << "                    AVENTURA POKEMON FDP C1                    " << endl;
    cout << "===============================================================" << endl;
    cout << endl;
    cout << "1. JUGAR" << endl;
    cout << "2. HISTORIAL DE VICTORIAS" << endl;
    cout << "3. CREDITOS Y AGRADECIMIENTOS" << endl;
    cout << "4. SALIR " << endl;
    cout << " Selecciona una opcion: ";

    cin >> seleccion;
    return seleccion;
}

// --- EL ENGRANAJE MENOR (LA BATALLA) ---
void ejecutarBatalla(Pokemon &jugador, Pokemon &enemigo, int &pociones, int &superPociones)
{
    cout << "\n================================================" << endl;
    cout << "     Comienza la pelea contra " << enemigo.nombre << "!" << endl;
    cout << "=================================================\n"
         << endl;

    // 1. Usamos vidaActual para verificar si ambos siguen vivos
    while (jugador.vidaActual > 0 && enemigo.vidaActual > 0)
    {

        bool jugadorVaPrimero = true;

        // 2. Evaluamos usando tu variable 'velocidad'
        if (enemigo.velocidad > jugador.velocidad)
        {
            jugadorVaPrimero = false;
        }

        if (jugadorVaPrimero)
        {
            // --- TURNO 1: JUGADOR ---
            int accion;
            cout << "\n[ PS " << jugador.nombre << ": " << jugador.vidaActual << " | PS " << enemigo.nombre << ": " << enemigo.vidaActual << " ]";
            cout << "\nTu turno. 1. Atacar | 2. Abrir Mochila: ";
            cin >> accion;

            if (accion == 1)
            {
                // Eligió atacar, abrimos el moveset
                int mov;
                cout << "\n--- MOVIMIENTOS ---" << endl;
                cout << "1. Aranazo (Danio normal)" << endl;
                if (jugador.tipo == "Fuego")
                    cout << "2. Ascuas (Ataque Especial)" << endl;
                else if (jugador.tipo == "Agua")
                    cout << "2. Pistola Agua (Ataque Especial)" << endl;
                else
                    cout << "2. Hoja Afilada (Ataque Especial)" << endl;
                cout << "3. Grunido (Bajar Defensa rival)" << endl;
                cout << "4. Afilagarras (Subir tu Ataque)" << endl;
                cout << "Elige un movimiento (1-4): ";
                cin >> mov;
                cout << endl;

                if (mov == 1)
                {
                    int danio = jugador.ataque - (enemigo.defensa / 2);
                    if (danio < 1)
                        danio = 1;
                    enemigo.vidaActual -= danio;
                    cout << "-> " << jugador.nombre << " usa Aranazo y causa " << danio << " de danio!" << endl;
                }
                else if (mov == 2)
                {
                    int danio = (jugador.ataque + 5) - (enemigo.defensa / 2);
                    if (danio < 1)
                        danio = 1;
                    enemigo.vidaActual -= danio;
                    cout << "-> " << jugador.nombre << " usa su Ataque Especial y causa " << danio << " de danio!" << endl;
                }
                else if (mov == 3)
                {
                    enemigo.defensa -= 2;
                    if (enemigo.defensa < 1)
                        enemigo.defensa = 1;
                    cout << "-> " << jugador.nombre << " usa Grunido! La defensa del rival ha bajado." << endl;
                }
                else if (mov == 4)
                {
                    jugador.ataque += 3;
                    cout << "-> " << jugador.nombre << " usa Afilagarras! Su ataque ha subido." << endl;
                }
                else
                {
                    cout << "-> " << jugador.nombre << " no sabe ese movimiento, aparentemente se confundio y pierde turno. :(  " << endl;
                }
            }
            else
            {
                // Eligió curarse: Abrimos la mochila de opciones
                int tipoCura;
                cout << "\n--- MOCHILA DE OBJETOS ---" << endl;
                cout << "1. Pocion (Cura 30 PS) [" << pociones << " restantes]" << endl;
                cout << "2. Superpocion (Cura 50 PS) [" << superPociones << " restantes]" << endl;
                cout << "Elige que objeto usar (1-2): ";
                cin >> tipoCura;

                if (tipoCura == 1)
                {
                    if (pociones > 0)
                    {
                        jugador.vidaActual += 30; // Cura 30 de vida, para balancear (considerar cambio)
                        pociones--;
                        if (jugador.vidaActual > jugador.vidaMax)
                            jugador.vidaActual = jugador.vidaMax;
                        cout << "-> ¡Has usado una Pocion! Recuperas 30 PS." << endl;
                    }
                    else
                    {
                        cout << "-> Oh no! No te quedan Pociones normales. Pierdes el turno buscando en el fondo de la mochila..." << endl;
                    }
                }
                else if (tipoCura == 2)
                {
                    if (superPociones > 0)
                    {
                        jugador.vidaActual += 50; // Cura 50 se usa para los jefe, o a deccision del jugador
                        superPociones--;
                        if (jugador.vidaActual > jugador.vidaMax)
                            jugador.vidaActual = jugador.vidaMax;
                        cout << "-> ¡Has usado una Superpocion! Recuperas 50 PS." << endl;
                    }
                    else
                    {
                        cout << "-> Oh no! No te quedan Superpociones. Pierdes el turno buscando en el fondo de la mochila..." << endl;
                    }
                }
                else
                {
                    cout << "-> Te confundiste de boton al abrir la mochila, entras en panico y pierdes el turno... :(" << endl;
                }
            }

            if (enemigo.vidaActual <= 0)
                break;

            // --- TURNO 2: ENEMIGO ---
            int danioEnemigo = enemigo.ataque - (jugador.defensa / 2);
            if (danioEnemigo < 1)
                danioEnemigo = 1;
            jugador.vidaActual -= danioEnemigo;
            cout << "-> " << enemigo.nombre << " contraataca y causa " << danioEnemigo << " de danio!" << endl;
        }
        else
        {
            // --- TURNO 1: ENEMIGO (Es más rápido) ---
            int danioEnemigo = enemigo.ataque - (jugador.defensa / 2);
            if (danioEnemigo < 1)
                danioEnemigo = 1;
            jugador.vidaActual -= danioEnemigo;
            cout << "\n-> " << enemigo.nombre << " es mas rapido y ataca! Causa " << danioEnemigo << " de danio." << endl;

            if (jugador.vidaActual <= 0)
                break;

            // --- TURNO 2: JUGADOR ---
            int accion;
            cout << "\n[ PS " << jugador.nombre << ": " << jugador.vidaActual << " | PS " << enemigo.nombre << ": " << enemigo.vidaActual << " ]";
            cout << "\nTu turno. 1. Atacar | 2. Abrir Mochila: ";
            cin >> accion;

            if (accion == 1)
            {
                int mov; // Este es el movepool de los pokemon,
                         // en si los por defecto son aranazo, y los 2 de stats, y dependiendo el inicial el at. esp
                cout << "\n--- MOVIMIENTOS ---" << endl;
                cout << "1. Aranazo (Danio normal)" << endl;
                if (jugador.tipo == "Fuego")
                    cout << "2. Ascuas (Ataque Especial)" << endl;
                else if (jugador.tipo == "Agua")
                    cout << "2. Pistola Agua (Ataque Especial)" << endl;
                else
                    cout << "2. Hoja Afilada (Ataque Especial)" << endl;
                cout << "3. Grunido (Bajar Defensa rival)" << endl;
                cout << "4. Afilagarras (Subir tu Ataque)" << endl;
                cout << "Elige un movimiento (1-4): ";
                cin >> mov;
                cout << endl;

                if (mov == 1)
                {
                    int danio = jugador.ataque - (enemigo.defensa / 2);
                    if (danio < 1)
                        danio = 1;
                    enemigo.vidaActual -= danio;
                    cout << "-> " << jugador.nombre << " usa Aranazo y causa " << danio << " de danio!" << endl;
                }
                else if (mov == 2)
                {
                    int danio = (jugador.ataque + 5) - (enemigo.defensa / 2);
                    if (danio < 1)
                        danio = 1;
                    enemigo.vidaActual -= danio;
                    cout << "-> " << jugador.nombre << " usa su Ataque Especial y causa " << danio << " de danio!" << endl;
                }
                else if (mov == 3)
                {
                    enemigo.defensa -= 2;
                    if (enemigo.defensa < 1)
                        enemigo.defensa = 1;
                    cout << "-> " << jugador.nombre << " usa Grunido! La defensa del rival ha bajado." << endl;
                }
                else if (mov == 4)
                {
                    jugador.ataque += 3;
                    cout << "-> " << jugador.nombre << " usa Afilagarras! Su ataque ha subido." << endl;
                }
                else
                {
                    cout << "-> " << jugador.nombre << " no sabe ese movimiento, aparentemente se confundio y pierde turno. :(  " << endl;
                }
            }
            else
            {
                // Eligió curarse: Abrimos la mochila de opciones
                int tipoCura;
                cout << "\n--- MOCHILA DE OBJETOS ---" << endl;
                cout << "1. Pocion (Cura 30 PS) [" << pociones << " restantes]" << endl;
                cout << "2. Superpocion (Cura 50 PS) [" << superPociones << " restantes]" << endl;
                cout << "Elige que objeto usar (1-2): ";
                cin >> tipoCura;

                if (tipoCura == 1)
                {
                    if (pociones > 0)
                    {
                        jugador.vidaActual += 30; // Cura 30 de vida (considerar a cambiar)
                        pociones--;
                        if (jugador.vidaActual > jugador.vidaMax)
                            jugador.vidaActual = jugador.vidaMax;
                        cout << "-> ¡Has usado una Pocion! Recuperas 30 PS." << endl;
                    }
                    else
                    {
                        cout << "-> Oh no! No te quedan Pociones normales. Pierdes el turno buscando en el fondo de la mochila..." << endl;
                    }
                }
                else if (tipoCura == 2)
                {
                    if (superPociones > 0)
                    {
                        jugador.vidaActual += 50; // Cura 50 se usa principalmente para jefes
                        superPociones--;
                        if (jugador.vidaActual > jugador.vidaMax)
                            jugador.vidaActual = jugador.vidaMax;
                        cout << "-> ¡Has usado una Superpocion! Recuperas 50 PS." << endl;
                    }
                    else
                    {
                        cout << "-> Oh no! No te quedan Superpociones. Pierdes el turno buscando en el fondo de la mochila..." << endl;
                    }
                }
                else
                {
                    cout << "-> Te confundiste de boton al abrir la mochila, entras en panico y pierdes el turno... :(" << endl;
                }
            }
        }
    }

    if (jugador.vidaActual <= 0)
    {
        cout << "\nHas perdido la batalla...\n";
    }
    else
    {
        cout << "\nHas ganado la batalla!\n";
    }
}