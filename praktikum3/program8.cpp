// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int alas = 4;
  int tinggi = 5;
  float sisi_miring;

  /*
    Rumus pythagoras: a^2 + b^2 = c^2
  */
  sisi_miring = sqrt(pow(alas, 2) + pow(tinggi, 2));

  cout << "MENGHITUNG SISI MIRING SEGITIGA" << endl;
  cout << "Alas \t: " << alas << " cm" << endl;
  cout << "Tinggi \t: " << tinggi << " cm" << endl;
  cout << setprecision(4);
  cout << "Sisi Miring \t: " << sisi_miring << " cm" << endl;

  return 0;
}