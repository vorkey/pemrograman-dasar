// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <iostream>

using namespace std;

int main() {
  bool a = true;  // 1
  bool b = false; // 0
  bool hasil;

  hasil = a && a;
  cout << "Hasil dari a && a : " << hasil << endl;

  hasil = a && b;
  cout << "Hasil dari a && b : " << hasil << endl;

  hasil = a || b;
  cout << "Hasil dari a || b : " << hasil << endl;

  hasil = b || b;
  cout << "Hasil dari b || b : " << hasil << endl;

  hasil = !a;
  cout << "Hasil dari !a : " << hasil << endl;

  hasil = !b;
  cout << "Hasil dari !b : " << hasil << endl;

  return 0;
}