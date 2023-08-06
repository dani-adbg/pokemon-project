// Incluimos las librerías necesarias
#include <iostream>
#include <string>
// Librerías para la función sleep
#include <thread>
#include <chrono>

using namespace std;

// Clase Pokemon
class Pokemon {
private:
  string nombre;
  string tipo;
  int salud;
  int ataque;
  int defensa;
public:
  Pokemon(const string nombre, const string tipo, int salud, int ataque, int defensa) : nombre(nombre), tipo(tipo), salud(salud), ataque(ataque), defensa(defensa) {}

  string getNombre() const {
    return nombre;
  }

  string getTipo() const {
    return tipo;
  }

  int getSalud() const {
    return salud;
  }

  int getAtaque() const {
    return ataque;
  }
  int getDefensa() const {
    return defensa;
  }
};

// Declaramos variables
int numPokemon; // Será para saber que pokemón vamos a seleccionar

// Funcion para esperar 1 segundo
void sleep(int sec) {
  int milliseconds = sec * 1000;
  this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

// Funcion para mostrar los datos del pokemon
void showData(const Pokemon& pokemon) {
  cout << "Procesando datos";

  // Bucle que agregara puntos 3 puntos a la linea anterior por cada segundo
  for (int i = 0; i < 3; i++) {
    cout << ".";  
    sleep(1);  
  }

  cout << endl;

  cout << "Datos del Pokemon" << endl;

  cout << "Nombre: " << pokemon.getNombre() << endl;
  cout << "Tipo: " << pokemon.getTipo() << endl;
  cout << "Salud: " << pokemon.getSalud() << endl;
  cout << "Ataque: " << pokemon.getAtaque() << endl;
  cout << "Defensa: " << pokemon.getDefensa() << endl;

}

// Funcion para seleccionar pokemon
Pokemon selectPokemon() {
  cout << "Ingrese el número del Pokemón que quieres escoger" << endl;
  cout << "1. Charmander" << endl;
  cout << "2. Bulbasaur" << endl;
  cout << "3. Squirtle" << endl;

  cin >> numPokemon;

  switch (numPokemon) {
    case 1: {
      Pokemon charmander("Charmander", "Fuego", 39, 52, 43);
      return charmander;
    }
    break;
    case 2: {
      Pokemon bulbasaur("Bulbasaur", "Planta", 45, 49, 49);
      return bulbasaur;
    }
    break;
    case 3: {
      Pokemon squirtle("Squirtle", "Agua", 44, 48, 65);
      return squirtle;
    }
    break;
    default: {
      Pokemon charmander("Charmander", "Fuego", 39, 52, 43);
      return charmander;
    }
    break;
  }
}

// Función MAIN
int main() {
  
  // Define una constante para luego pasarselo a la función showData
  Pokemon pokemon = selectPokemon();
  // Se le pasa la constante a la función
  showData(pokemon);
  return 0;
}