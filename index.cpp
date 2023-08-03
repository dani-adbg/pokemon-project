// Incluimos las librerías necesarias
#include <iostream>
#include <string>

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

// Función MAIN
int main() {
  
  cout << "Ingrese el número del Pokemón que quieres escoger" << endl;
  cout << "1. Charmander" << endl;
  cout << "2. Bulbasaur" << endl;
  cout << "3. Squirtle" << endl;

  cin >> numPokemon;

  switch (numPokemon) { // Creamos la condición
    case 1: {
      // Se agregan los parámetros a la clase
      Pokemon charmander("Charmander", "Fuego", 39, 52, 43);
      // Se muestran los datos
      cout << "Nombre: " << charmander.getNombre() << endl;
      cout << "Tipo: " << charmander.getTipo() << endl;
      cout << "Salud: " << charmander.getSalud() << endl;
      cout << "Ataque: " << charmander.getAtaque() << endl;
      cout << "Defensa: " << charmander.getDefensa() << endl;
    }
    break;
    case 2: {
      Pokemon bulbasaur("Bulbasaur", "Planta", 45, 49, 49);
      cout << "Nombre: " << bulbasaur.getNombre() << endl;
      cout << "Tipo: " << bulbasaur.getTipo() << endl;
      cout << "Salud: " << bulbasaur.getSalud() << endl;
      cout << "Ataque: " << bulbasaur.getAtaque() << endl;
      cout << "Defensa: " << bulbasaur.getDefensa() << endl;
    }
    break;
    case 3: {
      Pokemon squirtle("Squirtle", "Agua", 44, 48, 65);
      cout << "Nombre: " << squirtle.getNombre() << endl;
      cout << "Tipo: " << squirtle.getTipo() << endl;
      cout << "Salud: " << squirtle.getSalud() << endl;
      cout << "Ataque: " << squirtle.getAtaque() << endl;
      cout << "Defensa: " << squirtle.getDefensa() << endl;
    }
    break;

    default: {
      Pokemon charmander("Charmander", "Fuego", 39, 52, 43);
      cout << "Nombre: " << charmander.getNombre() << endl;
      cout << "Tipo: " << charmander.getTipo() << endl;
      cout << "Salud: " << charmander.getSalud() << endl;
      cout << "Ataque: " << charmander.getAtaque() << endl;
      cout << "Defensa: " << charmander.getDefensa() << endl;
    }
  };

  return 0;
}