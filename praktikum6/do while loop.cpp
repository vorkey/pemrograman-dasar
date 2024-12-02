// Ambadaya Gaman - C020324001 - Elektronika 1A
// Rizlan Riyadi - C020324017 - Elektronika 1A

#include <iostream>

using namespace std;

int main() {
  int angka;
  char input;
  string input_angka;

  cout << endl << "======= Program Ganjil atau Genap =======" << endl;

  do {
    cout << "Inputkan angka: ";
    cin >> input_angka;

    try {
      angka = stoi(input_angka);
    } catch (exception e) {
      cout << "Input salah. Mohon berikan bilangan bulat" << endl;
      return 0;
    }

    if (angka % 2 == 0) {
      cout << angka << " adalah bilangan genap." << endl;
    } else {
      cout << angka << " adalah bilangan ganjil." << endl;
    }

    cout << endl
         << "Inputkan y jika anda ingin mengecek angka lainnya? (y/n): ";
    cin >> input;

  } while (input == 'y' || input == 'Y');

  cout << "Terima kasih telah menggunakan program ini." << endl;

  return 0;
}
