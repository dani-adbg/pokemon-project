// POKEMON PROJECT
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <conio.h>
#include <sstream>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cctype>

using namespace std;

class Pokemon {
  private:
    string nombre;
    string tipo;
    int nivel;
    int salud;
    int ataque;
    int defensa;
    string debilidad;
    vector<pair<string, pair<int, string>>> movimientos;
    string img;
    string mimg;

  public: 
    Pokemon(const string nombre, const string tipo, int nivel, int salud, int ataque, int defensa, const string debilidad , const string img)
      : nombre(nombre), tipo(tipo), nivel(nivel), salud(salud), ataque(ataque), defensa(defensa), debilidad(debilidad), img(img) {}

    string getNombre() const {
      return nombre;
    }

    string getTipo() const {
      return tipo;
    }

    int getNivel() const {
      return nivel;
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

    string getDebilidad() const {
      return debilidad;
    }

    void AgregarMovimiento(const string& nombreMovimiento, int daño, const string& tipoMovimiento) {
      movimientos.push_back(make_pair(nombreMovimiento, make_pair(daño, tipoMovimiento)));
    }

    const vector<pair<string, pair<int, string>>>& ObtenerMovimientos() const {
      return movimientos;
    }

    void ActualizarSalud(int nuevaSalud) {
      salud = nuevaSalud;
    }

    string getImg() const {
      return img;
    }
};

int pC, poke, pR;

void sleep(int sec) {
  int milliseconds = sec * 1000;
  this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

// MOSTRAR DATOS
void showData(const Pokemon& pokemon) {

  cout << "Procesando datos";

  for (int i = 0; i < 3; i++) {
    cout << ".";
    cout.flush();  
    sleep(1);  
  }

  string espacio(20, ' '); 
  string espacioG(60, ' '); 

  istringstream iss(pokemon.getImg());
  vector<string> lineas;
  string linea;
  while (getline(iss, linea)) {
    lineas.push_back(linea);
  }
    
  cout << endl;
  cout << "Datos del pokemon" << endl;
  cout << "Nombre: " << pokemon.getNombre() << string(60 - (8 + pokemon.getNombre().length()), ' ') << lineas[0] << endl;
  cout << "Tipo: " << pokemon.getTipo() << string(60 - (6 + pokemon.getTipo().length()), ' ') << lineas[1] << endl;
  cout << "Nivel:" << pokemon.getNivel() << string(60 - 7, ' ') << lineas[2] << endl;
  cout << "Salud: " << pokemon.getSalud() << string(60 - 9, ' ') << lineas[3] << endl;
  cout << "Ataque: " << pokemon.getAtaque() << string(60 - 10, ' ') << lineas[4] << endl;
  cout << "Defensa: " << pokemon.getDefensa() << string(49, ' ') << lineas[5] << endl;
  cout << "Movimientos:" << string(60 - 12, ' ') << lineas[6] << endl;
  const vector<pair<string, pair<int, string>>>& movimientos = pokemon.ObtenerMovimientos();
  int numMovimientos = movimientos.size();
  for (int i = 0; i < numMovimientos; i++) {
    const auto& movimiento = movimientos[i];
    string line = " - " + movimiento.first + " (Daño: " + to_string(movimiento.second.first) + " - Tipo: " + movimiento.second.second + ")";
    espacio.resize(60 - line.length(), ' ');
    cout << line << espacio << lineas[i+6]<< endl;
  }
  for (int i = 11; i < lineas.size(); i++) {
    cout << espacioG << lineas[i] << endl;
  }
  
  cin.ignore();
  cin.get();
}

void bShowData(const Pokemon& pokemon, const Pokemon& rival) {
  system("cls");
  cout << endl;
  cout << string(30, ' ') << "TU POKEMON" << string(30, ' ') << "||" << string(30, ' ') << "POKEMON RIVAL" << endl; 
  istringstream iss(pokemon.getImg());
  vector<string> lines;
  string line;
  while (getline(iss, line)) {
    lines.push_back(line);
  }

  istringstream oss(rival.getImg());
  vector<string> rlines;
  string rline;
  while (getline(oss, rline)) {
    rlines.push_back(rline);
  }
  
  cout << string(70, ' ') << "||" << endl;
  cout << "Datos del pokemon" << string(53, ' ') << "|| Datos del pokemon" << endl;
  cout << "Nombre: " << pokemon.getNombre() << string(70 - (8 + pokemon.getNombre().length()), ' ') << "|| Nombre:" << rival.getNombre() << endl;
  cout << "Tipo: " << pokemon.getTipo() << string(70 - (6 + pokemon.getTipo().length()), ' ') << "|| Tipo:" << rival.getTipo() << endl;
  cout << "Nivel:" << pokemon.getNivel() << string(70 - 7, ' ') << "|| Nivel:" << rival.getNivel() << endl;
  cout << "Salud: " << pokemon.getSalud() << string(70 - 9, ' ') << "|| Salud:" << rival.getSalud() << endl;
  cout << "Ataque: " << pokemon.getAtaque() << string(70 - 10, ' ') << "|| Ataque:" << rival.getAtaque() << endl;
  cout << "Defensa: " << pokemon.getDefensa() << string(70 - 11, ' ') << "|| Defensa:" << rival.getDefensa() << endl;
  cout << "Movimientos:" << string(70 - 12, ' ') << "|| Movimientos:" << rival.getNombre() << endl;
  const vector<pair<string, pair<int, string>>>& pMovimientos = pokemon.ObtenerMovimientos();
  const vector<pair<string, pair<int, string>>>& rMovimientos = rival.ObtenerMovimientos();
  int numMovimientos = pMovimientos.size();
  for (int i = 0; i < numMovimientos; i++) {
    const auto& movimiento = pMovimientos[i];
    const auto& rMovimiento = rMovimientos[i];
    string mData = " - " + movimiento.first + " (Daño: )" + to_string(movimiento.second.first) + " - Tipo: " + movimiento.second.second + ")";
    string rData = " - " + rMovimiento.first + " (Daño: )" + to_string(rMovimiento.second.first) + " - Tipo: " + rMovimiento.second.second + ")";
    cout << mData << string(70 - mData.length(), ' ') << "|| " << rData << endl;
  }
  cout << string(70, ' ') << "||" << endl;
  for (int i = 0; i < 3; i++) {
    cout << ".";
    cout.flush();  
    sleep(1);  
  }
  system("cls");

  cout << string(70, ' ') << "||" << endl;

  int maxSize = max(lines.size(), rlines.size());

  for (int i = 0; i < maxSize; i++) {
    if (i < lines.size()) {
      cout << lines[i];
      cout << string(70 - lines[i].length(), ' ');
    } else {
      cout << string(70, ' ');
    }
    cout << "|| " << string(5, ' ');
    if (i < rlines.size()) {
      cout << rlines[i];
    }
    cout << endl;
  }

}

string charmanderImg = "              _.--\"\"`-..\n"
                 "            ,'          `.\n"
                 "          ,'          __  `.\n"
                 "         /|          \" __   \\\n"
                 "        , |           / |.   .\n"
                 "        |,'          !_.'|   |\n"
                 "      ,'             '   |   |\n"
                 "     /              |`--'|   |\n"
                 "    |                `---'   |\n"
                 "     .   ,                   |                       ,\".\n"
                 "      ._     '           _'  |                    , ' \\ `\n"
                 "  `.. `.`-...___,...---\"    |       __,.        ,`\"   L,|\n"
                 "  |, `- .`._        _,-,.'   .  __.-'-. /        .   ,    \\\n"
                 "-:..     `. `-..--_.,.<       `\"      / `.        `-/ |   .\n"
                 "  `,         \"\"\"\"'     `.              ,'         |   |  ',,\n"
                 "    `.      '            '            /          '    |'. |/\n"
                 "      `.   |              \\       _,-'           |       ''\n"
                 "        `._'               \\   '\"\\                .      |\n"
                 "           |                '     \\                `._  ,'\n"
                 "           |                 '     \\                 .'|\n"
                 "           |                 .      \\                | |\n"
                 "           |                 |       L              ,' |\n"
                 "           `                 |       |             /   '\n"
                 "            \\                |       |           ,'   /\n"
                 "          ,' \\               |  _.._ ,-..___,..-'    ,'\n"
                 "         /     .             .      `!             ,j'\n"
                 "        /       `.          /        .           .'/\n"
                 "       .          `.       /         |        _.'.'\n"
                 "        `.          7`'---'          |------\"'_.\n"
                 "       _,.`,_     _'                ,''-----\"\"\n"
                 "   _,-_    '       `.     .'      ,\\\n"
                 "   -\" /`.         _,'     | _  _  _.|\n"
                 "    \"\"--'---\"\"\"\"'        `' '! |! /\n"
                 "                            `\" \" -' ";

string squirtleImg = "               _,........__\n"
             "            ,-'            \"`-.\n"
             "          ,'                   `-.\n"
             "        ,'                        \\\n"
             "      ,'                           .\n"
             "      .\\               ,\"\".       `\n"
             "     ._.'|             / |  `       \\\n"
             "     |   |            `-.'  ||       `.\n"
             "     |   |            '-._,'||       | \\\n"
             "     .`.,'             `..,'.'       , |`-.\n"
             "     l                       .'`.  _/  |   `.\n"
             "     `-.._'-   ,          _ _'   -\" \\  .     `\n"
             "`.\"\"\"\"\"'-.`-...,---------','         `. `....__.\n"
             ".'        `\"-..___      __,'\\          \\  \\     \\\n"
             "\\_ .          |   `\"\"\"'    `.           . \\     \\\n"
             "  `.          |              `.          |  .     L\n"
             "    `.        |`--...________.'.        j   |     |\n"
             "      `._    .'      |          `.     .|   ,     |\n"
             "         `--,\\       .            `7\"\"' |  ,      |\n"
             "            ` `      `            /     |  |      |    _,-'\"\"\"`-.\n"
             "             \\ `.     .          /      |  '      |  ,'          `.\n"
             "              \\  v.__  .        '       .   \\    /| /              \\\n"
             "               \\/    `\"\"\"\"\"\"`.       \\   \\  /.''                |\n"
             "                `        .        `._ ___,j.  `/ .-       ,---.     |\n"
             "                ,`-.      \\         .\"     `.  |/        j     `    |\n"
             "               /    `.     \\       /         \\ /         |     /    j\n"
             "              |       `-.   7-.._ .          |\"          '         /\n"
             "              |          `./_    `|          |            .     _,'\n"
             "              `.           / `----|          |-............`---'\n"
             "                \\          \\      |          |\n"
             "               ,'           )     `.         |\n"
             "                7____,,..--'      /          |\n"
             "                                  `---.__,--.'";
                  
string bulbasaurImg = "                                            /\n"
             "                        _,.------....___,.' ',.-.\n"
             "                     ,-'          _,.--\"        |\n"
             "                   ,'         _.-'              .\n"
             "                  /   ,     ,'                   `\n"
             "                 .   /     /                     ``.\n"
             "                 |  |     .                       \\.\\\n"
             "       ____      |___._.  |       __               \\ `.\n"
             "     .'    `---\"       ``\"-.--\"'`  \\               .  \\\n"
             "    .  ,            __               `              |   .\n"
             "    `,'         ,-\"'  .               \\             |    L\n"
             "   ,'          '    _.'                -._          /    |\n"
             "  ,`-.    ,\".   `--'                      >.      ,'     |\n"
             " . .'\\'   `-'       __    ,  ,-.         /  `.__.-      ,'\n"
             " ||:, .           ,'  ;  /  / \\ `        `.    .      .'/\n"
             " j|:D  \\          `--'  ' ,'_  . .         `.__, \\   , /\n"
             "/ L:_  |                 .  \"' :_;                `.'.'\n"
             ".    \"\"'                  \"\"\"\"\"'                    V\n"
             " `.                                 .    `.   _,..  `\n"
             "   `,_   .    .                _,-'/    .. `,'   __  `\n"
             "    ) `._        ___....----\"'  ,'   .'  \\ |   '  \\  .\n"
             "   /   `. `-.--\"'         _,.' ,'     `---' |    `./  |\n"
             "  .     `.              .'     /              ,'     |\n"
             "  |       `-.          /      .              |      ,\n"
             "  .          `.       /       |              '    ,'\n"
             "   `.          7`'---'        |            /   ,'\n"
             "    `.      '   /         |          _,'   ,'\n"
             "      `._    `-'          |      _,-'    ,'\n"
             "         `--,,,-'            |  _,-'    ,'\n"
             "            `             _.:,'       ,'\n"
             "              '._        _,-'       ,'\n"
             "                 `-----'-------'--' ";

string trofeo = "     _ _        _ _ _ _ _ _ _ _         _ _ \n"
                "   /     \\     /                \\     /      \\ \n"
                "  |       \\ _ /                  \\ _ /        | \n"
                "   \\       |                         |       / \n"
                "    \\      |                         |      / \n"
                "     \\     |                         |     / \n"
                "      \\    |                         |    / \n"
                "       \\   |                         |   / \n"
                "        \\  |                         |  / \n"
                "         \\ |                         | / \n"
                "          \\|                         |/ \n"
                "            \\                       / \n"
                "             \\                     / \n"
                "              \\                   / \n"
                "               \\                 / \n"
                "                |               | \n"
                "                |               | \n"
                "                |               | \n"
                "               /                 \\ \n"
                "              /_ _ _ _ _ _ _ _ _ _\\ \n";

// SELECCION DE POKEMON
bool p = false;
bool r = false;
Pokemon selectPokemon(int pC, bool p, bool r) {
  int opcion = 1;
  bool a;
  a = true;
  while (a) {
    system("cls");
    if(r == true) {
      cout << "Elige el Pokemon contrincante" << endl;
    } else if(p == true) {
      cout << "Elige tu Pokemon" << endl;
    } else {
      cout << "Elije el Pokemon del que quieres obtener la información" << endl;
    }
    cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;
    cout << " | " << (opcion == 1 ? "> Charmander" + string (59, ' ') + "|" : "Charmander" + string (61, ' ') + "|") << endl;
    cout << " | " << (opcion == 2 ? "> Bulbasaur" + string (60, ' ') + "|" : "Bulbasaur" + string (62, ' ') + "|") << endl;
    cout << " | " << (opcion == 3 ? "> Squirtle" + string(61, ' ') + "|" : "Squirtle" + string (63, ' ') + "|") << endl;
    cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;

    char tecla = getch();

    if (tecla == 72) { 
        opcion = (opcion - 1 < 1) ? 3 : opcion - 1;
      } else if (tecla == 80) { 
        opcion = (opcion + 1 > 3) ? 1 : opcion + 1;
      } else if (tecla == 13) { 
        pC = opcion;
        a = false;
      }
  }

  switch (pC) {
    case 1: {
      Pokemon charmander("Charmander", "Fuego", 5, 39, 52, 43, "Agua", charmanderImg);
      charmander.AgregarMovimiento("Arañazo", 40, "Normal");
      charmander.AgregarMovimiento("Ascuas", 40, "Fuego");
      charmander.AgregarMovimiento("Lanzallamas", 90, "Fuego");
      charmander.AgregarMovimiento("Giro Fuego", 35, "Fuego");
      return charmander;
    }
    break;
    case 2: {
      Pokemon bulbasaur("Bulbasaur", "Planta", 5, 45, 49, 49, "Fuego", bulbasaurImg);
      bulbasaur.AgregarMovimiento("Tacleada", 40, "Normal");
      bulbasaur.AgregarMovimiento("Látigo Cepa", 45, "Planta");
      bulbasaur.AgregarMovimiento("Hoja Afilada", 55, "Planta");
      bulbasaur.AgregarMovimiento("Planta Feroz", 120, "Planta");
      return bulbasaur;
    }
    break;
    case 3: {
      Pokemon squirtle("Squirtle", "Agua", 5, 44, 48, 65, "Planta", squirtleImg);
      squirtle.AgregarMovimiento("Arañazo", 40, "Normal");
      squirtle.AgregarMovimiento("Pistola Agua", 40, "Agua");
      squirtle.AgregarMovimiento("Burbuja", 40, "Agua");
      squirtle.AgregarMovimiento("Hidrobomba", 110, "Agua");
      return squirtle;
    }
    break;
    default: {
      Pokemon charmander("Charmander", "Fuego", 5, 39, 52, 43, "Agua", charmanderImg);
      charmander.AgregarMovimiento("Arañazo", 40, "Normal");
      charmander.AgregarMovimiento("Ascuas", 40, "Fuego");
      charmander.AgregarMovimiento("Lanzallamas", 90, "Fuego");
      charmander.AgregarMovimiento("Giro Fuego", 35, "Fuego");
      return charmander;
    }
    break;
  }
}

int randomNumber(int min, int max) {
  random_device rd;
  mt19937 generador(rd());
  uniform_int_distribution<> distribucion(1, 2);
  return distribucion(generador);    
}

void win(Pokemon& poke) {
  system("cls");
  int spaces = (140 - poke.getNombre().length()) / 2;

  string nombreMayusculas = poke.getNombre();
  transform(nombreMayusculas.begin(), nombreMayusculas.end(), nombreMayusculas.begin(), ::toupper);

  cout << string(60, ' ') << "El Pokemon Ganador es: " << endl;
  cout << string(spaces, ' ') << nombreMayusculas << endl;

  istringstream iss(poke.getImg());
  vector<string> lineas;
  string linea;
  while (getline(iss, linea)) {
    lineas.push_back(linea);
  }
  istringstream oss(trofeo);
  vector<string> trofeos;
  string trofeo;
  while (getline(oss, trofeo)) {
    trofeos.push_back(trofeo);
  }

  int maxSize = max(lineas.size(), trofeos.size());

  for (int i = 0; i < maxSize; i++) {
    if (i < lineas.size()) {
      cout << lineas[i];
      cout << string(70 - lineas[i].length(), ' ');
    } else {
      cout << string(70, ' ');
    }
    cout << "|| " << string(5, ' ');
    if (i < trofeos.size()) {
      cout << trofeos[i];
    }
    cout << endl;
  }
  
  cout << "Presiona ENTER para cerrar" << endl;
}

void battle(Pokemon& pokemon, Pokemon& rival) {
  system("cls");

  while(pokemon.getSalud() > 0 && rival.getSalud() > 0) {
    const vector<pair<string, pair<int, string>>>&  movimientos1 = pokemon.ObtenerMovimientos();
    int movementSelect;
    int opcion = 1;
    bool a;
    a = true;
    while (a) {
      system("cls");
      cout << "Turno de tu pokemon " << pokemon.getNombre() << endl;
      cout << "Selecciona un movimiento" << endl;
      cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<< endl;
      cout << " |" << string(68, ' ') << "||" << string(75, ' ') << "|" << endl;
      cout << " | " << (opcion == 1 ? "> " + movimientos1[0].first + string (65 - movimientos1[0].first.length(), ' ') + "|| " : movimientos1[0].first + string (67 - movimientos1[0].first.length(), ' ') + "|| ") << (opcion == 2 ? "> " + movimientos1[1].first + string (72 - movimientos1[1].first.length(), ' ') + "|" : movimientos1[1].first + string (74 - movimientos1[1].first.length(), ' ') + '|') << endl;
      cout << " |" << string(68, ' ') << "||" << string(75, ' ') << "|" << endl;
      cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<< endl;
      cout << " |" << string(68, ' ') << "||" << string(75, ' ') << "|" << endl;
      cout << " | " << (opcion == 3 ? "> " + movimientos1[2].first + string (65 - movimientos1[2].first.length(), ' ') + "|| " : movimientos1[2].first + string (67 - movimientos1[2].first.length(), ' ') + "|| ") << (opcion == 4 ? "> " + movimientos1[3].first + string (72 - movimientos1[3].first.length(), ' ') + "|" : movimientos1[3].first + string (74 - movimientos1[3].first.length(), ' ') + '|') << endl;
      cout << " |" << string(68, ' ') << "||" << string(75, ' ') << "|" << endl;
      cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"<< endl;

      char tecla = getch();

      if (tecla == 72) { // arr
        opcion = (opcion - 2 < 0) ? 3 : (opcion - 2 == 0) ? 4 : opcion - 2;
      } else if (tecla == 75) { // izq
        opcion = (opcion - 1 < 1) ? 2 : (opcion - 1 == 2) ? 4 : opcion - 1;
      } else if (tecla == 77) { // der
        opcion = (opcion + 1 > 4) ? 3 : (opcion + 1 == 3) ? 1 : opcion + 1;
      } else if (tecla == 80) { // abj
        opcion = (opcion + 2 == 5) ? 1 : (opcion + 2 == 6) ? 2 : opcion + 2;
      } else if (tecla == 13) { 
        movementSelect = opcion;
        a = false;
      }
    }
      
    cout << endl;

    const pair<string, pair<int, string>>& movimiento1 = movimientos1[movementSelect - 1];

    int nivelPokemon = pokemon.getNivel();
    int ataquePokemon = pokemon.getAtaque();
    int defensaRival = rival.getDefensa();
    int dañoMovimiento = movimiento1.second.first;

    double dañoBase = ((2.0 * nivelPokemon / 5.0 + 2.0) * dañoMovimiento * ataquePokemon / defensaRival) / 50.0 + 2.0;

    double modificadorTipo = 1.0;
    string tipoMovimiento = movimiento1.second.second;
    string tipoRival = rival.getTipo();

    if (tipoMovimiento == "Planta" && tipoRival == "Agua") {
      modificadorTipo = 2.0; 
    } else if (tipoMovimiento == "Agua" && tipoRival == "Fuego") {
      modificadorTipo = 2.0; 
    } else if (tipoMovimiento == "Fuego" && tipoRival == "Planta") {
      modificadorTipo = 2.0; 
    }

    int dañoRealizado = static_cast<int>(dañoBase * modificadorTipo);

    cout << pokemon.getNombre() << " ha usado " << movimiento1.first << " con un daño de " << to_string(dañoRealizado) << endl;

    int nuevaSaludPokemon2 = rival.getSalud() - dañoRealizado;
    cout << "La salud  del pokemon rival ha pasado de " << to_string(rival.getSalud()) << " a " << to_string(nuevaSaludPokemon2 < 0 ? 0 : nuevaSaludPokemon2) << endl;
    rival.ActualizarSalud(nuevaSaludPokemon2);

    if(rival.getSalud() <= 0) {
      cout << rival.getNombre() << " se ha debilitado!" << endl;
      cout << pokemon.getNombre() << " ha ganado la batalla!!!" << endl;
      win(pokemon);
      break;
    }

    // cambio de turno
    cout << "Presiona ENTER para continuar con el turno del pokemon rival " << rival.getNombre() << endl;
    cin.ignore();

    cout << "Turno del pokemon rival " << rival.getNombre() << endl;
    const vector<pair<string, pair<int, string>>>&  movimientos2 = rival.ObtenerMovimientos();
    cin.ignore();
      
    movementSelect = randomNumber(1, 4);

    const pair<string, pair<int, string>>& movimiento2 = movimientos2[movementSelect - 1];

    int nivelRival = rival.getNivel();
    int ataqueRival = rival.getAtaque();
    int defensaPokemon = pokemon.getDefensa();
    int dañoMovimientoR = movimiento2.second.first;

    double dañoBaseR = ((2.0 * nivelRival / 5.0 + 2.0) * dañoMovimientoR * ataqueRival / defensaPokemon) / 50.0 + 2.0;

    double modificadorTipoR = 1.0;
    string tipoMovimientoR = movimiento2.second.second;
    string tipoPokemon = pokemon.getTipo();

    if (tipoMovimientoR == "Planta" && tipoPokemon == "Agua") {
      modificadorTipoR = 2.0; 
    } else if (tipoMovimientoR == "Agua" && tipoPokemon == "Fuego") {
      modificadorTipoR = 2.0; 
    } else if (tipoMovimientoR == "Fuego" && tipoPokemon == "Planta") {
      modificadorTipoR = 2.0; 
    }

    int dañoRealizadoR = static_cast<int>(dañoBaseR * modificadorTipoR);

    cout << rival.getNombre() << " ha usado " << movimiento2.first << " con daño de " << to_string(dañoRealizadoR) << endl;

    int nuevaSaludPokemon1 = pokemon.getSalud() - dañoRealizadoR;
    cout << "La salud de tu pokemon ha pasado de " << to_string(pokemon.getSalud()) << " a " << to_string(nuevaSaludPokemon1 < 0 ? 0 : nuevaSaludPokemon1) << endl;
    pokemon.ActualizarSalud(nuevaSaludPokemon1);

    if(pokemon.getSalud() <= 0) {
      cout << "Tu pokemon " << pokemon.getNombre() << " se ha debilitado!" << endl;
      cout << rival.getNombre() << " ha ganado la batalla!!!" << endl;
      win(rival);
      break;
    }

    cout << "Presiona ENTER para continuar con el turno de tu pokemon " << pokemon.getNombre() << endl;
    cin.ignore();
  }
}

// BATALLA
void battlePreview() {
  cout << "Antes de empezar la batalla, elige los pokemones que se enfrentaran." << endl;
  p = true;
  Pokemon pokemon = selectPokemon(pC, p, r);
  r = true;
  Pokemon rival = selectPokemon(pR, p, r);
  cout << "Cargando datos de batalla";
  for (int i = 0; i < 3; i++) {
    cout << ".";
    cout.flush();  
    sleep(1);  
  }
  
  bShowData(pokemon, rival);

  cout << endl;
  cout << "Empezando batalla";
  for (int i = 0; i < 3; i++) {
    cout << ".";
    cout.flush();  
    sleep(3);  
  }

  battle(pokemon, rival);
}

int mostrarMenu() {
  int opcion = 1;
  while (true) {
    system("cls");
    cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;
    cout << " |      _.----.        ____         ,'  _\\   ___    ___     ____         |" << endl;
    cout << " |  _,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`.   |" << endl;
    cout << " |  \\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  |  |" << endl;
    cout << " |   \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  |  |" << endl;
    cout << " |     \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  |  |" << endl;
    cout << " |      \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     |  |" << endl;
    cout << " |       \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    |  |" << endl;
    cout << " |        \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   |  |" << endl;
    cout << " |         \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   |  |" << endl;
    cout << " |          \\_.-'       |__|    `-._ |              '-.|     '-.| |   |  |" << endl;
    cout << " |                                  `'                            '-._|  |" << endl;
    cout << " | by dani_adbg                                                          |" << endl;
    cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;
    cout << endl;
    cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;
    cout << " |                    _ __ ___   ___ _ __  _   _                         | "<< endl;
    cout << " |                   | '_ ` _ \\ / _ \\ '_ \\| | | |                        | "<< endl;
    cout << " |                   | | | | | |  __/ | | | |_| |                        | "<< endl;
    cout << " |                   |_| |_| |_|\\___|_| |_|\\__,_|                        | "<< endl;
    cout << " |                                                                       | " << endl;
    // cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;
    cout << " |                                                                       |" << endl;
    cout << " |" << (opcion == 1 ? " > BATALLA                                                             |" : "  BATALLA                                                              |") << endl;
    cout << " |" << (opcion == 2 ? " > INFORMACION                                                         |" : " INFORMACION                                                           | ") << endl;
    cout << " |                                                                       |" << endl;
    cout << "  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - "<< endl;

    char tecla = getch();

    if (tecla == 72) { 
      opcion = (opcion - 1 < 1) ? 2 : opcion - 1;
    } else if (tecla == 80) {
      opcion = (opcion + 1 > 2) ? 1 : opcion + 1;
    } else if (tecla == 13) {
      return opcion;
    }
  }
}

// FUNCION MAIN
int main() {
  system("cls");
  int seleccion = mostrarMenu();

  switch (seleccion) {
    case 1:
      battlePreview();
      break;
    case 2:
      Pokemon pokemon = selectPokemon(pC, p, r);
      system("cls");
      showData(pokemon);
  }

  getch();
};
