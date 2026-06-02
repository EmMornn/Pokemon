#include <iostream>
#include <string>

using namespace std;
class Pokemon {
public:
    string nombre;
    string tipo;
    int vidaMax;
    int vidaActual;
    int ataque;
    int defensa;
    int velocidad;

   
    Pokemon(string _nombre, string _tipo, int _vida, int _ataque, int _defensa, int _velocidad) {
        nombre = _nombre;
        tipo = _tipo;
        vidaMax = _vida;
        vidaActual = _vida;
        ataque = _ataque;
        defensa = _defensa;
        velocidad = _velocidad;

       
    }
     void subirNivel() {
        vidaMax += 9;
        vidaActual = vidaMax;
        ataque += 2;
        defensa += 3;
        cout << nombre << " ha subido de nivel!." << endl;
}; 

        void escalarStats(int victorias) {
        vidaMax += (victorias * 7); 
        vidaActual = vidaMax;
        ataque += (victorias * 4);  
    };
};