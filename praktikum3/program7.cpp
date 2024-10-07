// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int diameter = 15;
  float jari_jari = diameter / 2.0;
  float volume_bola;

  /*
  Rumus Volume bola yaitu 4/3 * Phi * jari-jari^3
  */
  volume_bola = (4.0 / 3) * (22.0 / 7) * pow(jari_jari, 3);

  cout << "MENGHITUNG VOLUME BOLA" << endl;
  cout << "Diameter \t: " << diameter << " cm" << endl;
  cout << "Jari-jari \t: " << jari_jari << " cm" << endl;
  cout << "Volume bola \t: " << volume_bola << " cm^3" << endl;

  return 0;
}