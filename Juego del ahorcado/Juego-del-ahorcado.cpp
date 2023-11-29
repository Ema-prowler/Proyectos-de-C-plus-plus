#include <iostream>
#include <string>
using namespace std;

void mostrarEstadoJuego(const string &palabraOculta, int intentosRestantes) {
  cout << "Palabra: " << palabraOculta << endl;

  cout << "Intentos restantes: " << intentosRestantes << endl;
}
int main() {
  // Paso 1: Ingresar la palabra a adivinar
  string palabraAdivinar;
  char letraAdivinada;
  int intentosRestantes = 6;
  cout << "Bienvenido al Juego del ahorcado. " << endl;
  cout << "Jugador 1, Por favor ingrese la palabra a adivinar: ";
  cin >> palabraAdivinar;
  system("cls");
  // paso 2: Mostrar la palabra a adivinar (esto es olo para verificar que la
  // entrada funciono)
  cout << "La palabra a adivinar es: " << palabraAdivinar << endl;
  string palabraOculta(palabraAdivinar.length(), '_');
  cout << "Palabra Oculta: " << palabraOculta << endl;
  while (intentosRestantes > 0) {
    mostrarEstadoJuego(palabraOculta, intentosRestantes);
    cout << "jugador 2 por favor ingrese una letra: ";
    cin >> letraAdivinada;
    bool letraEncontrada = false;
    for (int i = 0; i < palabraAdivinar.length(); i++) {
      if (palabraAdivinar[i] == letraAdivinada) {
        palabraOculta[i] = letraAdivinada;
        letraEncontrada = true;
      }
    }
    if (letraEncontrada) {
      system("cls");
      cout << "Correcto la letra esta en la palabra." << endl;
    } else {
      system("cls");
      cout << "Incorrecto madafakaa no esta la letra jaja" << endl;
      intentosRestantes--;
    }
    if (palabraOculta == palabraAdivinar) {
      mostrarEstadoJuego(palabraOculta, intentosRestantes);
      cout << "felicidades flaco lo lograste adivinaste la palabra." << endl;
      break;
    }
  }
  if (intentosRestantes == 0) {
    mostrarEstadoJuego(palabraOculta, intentosRestantes);
    cout << "lo siento fracasaste ya era: " << endl;
  }
  return 0;
}