// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <iostream>

using namespace std;

int main() {
  int a = 10;
  int b = 12;
  int hasil;

  hasil = a & a;
  cout << "Hasil dari a & a : " << hasil << endl;

  hasil = a | b;
  cout << "Hasil dari a | b : " << hasil << endl;

  hasil = a ^ b;
  cout << "Hasil dari a ^ b : " << hasil << endl;

  hasil = ~a;
  cout << "Hasil dari ~a : " << hasil << endl;

  hasil = a >> 1;
  cout << "Hasil dari a >> 1 : " << hasil << endl;

  hasil = b << 2;
  cout << "Hasil dari b << 2 : " << hasil << endl;

  return 0;
}