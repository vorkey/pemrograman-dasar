// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <iostream>

using namespace std;

int main() {
  int alas = 8;
  int tinggi = 5;
  float luas_segitiga;

  luas_segitiga = 0.5 * alas * tinggi;

  cout << "MENGHITUNG LUAS SEGITIGA" << endl;
  cout << "Alas \t: " << alas << " cm" << endl;
  cout << "Tinggi \t: " << tinggi << " cm" << endl;
  cout << "Luas segitiga \t: " << luas_segitiga << " cm^2" << endl;

  return 0;
}