#include <iostream>

using namespace std;

int mostrarMenu();
void jugar();
void verHistorial();

int victorias = 0;

int main(void)
{
    int opcion;

    do
    {
        opcion = mostrarMenu();

        switch (opcion)
        {
        case 1:
            jugar();
            break;
        case 2:
            verHistorial();
            break;
        case 3:
            cout << "Saliendo del juego..." << endl;
            break;
        default:
            cout << "Opcion no valida. Por favor, intenta de nuevo." << endl;
        }
        cout << endl;

    } while (opcion != 3);

    return 0;
}

int mostrarMenu()
{
    int seleccion;
    cout << "================================" << endl;
    cout << "MENU DE OPCIONES" << endl;
    cout << "================================" << endl;
    cout << "1. Jugar" << endl;
    cout << "2. Ver Historial de victorias" << endl;
    cout << "3. Salir" << endl;
    cout << "Elige una opcion: ";

    cin >> seleccion;
    return seleccion;
}

void jugar()
{
    cout << "\n--- Iniciando el juego ---" << endl;
    cout << "¡Excelente estrategia! Has ganado la partida." << endl;
    victorias++;
}

void verHistorial()
{
    cout << "\n================================" << endl;
    cout << "HISTORIAL DE VICTORIAS" << endl;
    cout << "================================" << endl;
    cout << "Total de partidas ganadas: " << victorias << endl;
}