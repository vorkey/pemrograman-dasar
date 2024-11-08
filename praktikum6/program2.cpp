// Ambadaya Gaman - C020324001 - Elektronika 1A
// Rizlan Riyadi - C020324017 - Elektronika 1A

#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
  // Seed untuk random generator
  srand((unsigned)time(NULL));

  int res = rand() % 11;
  int angka;
  string input;

  cout << endl << "=========== Program Tebak Angka ============" << endl;
  cout << "----inputkan x untuk keluar dari program----" << endl << endl;

  while (true) {
    cout << "Inputkan Angka dari 0-10: ";
    cin >> input;

    if (input == "x" || input == "X") {
      break;
    }

    try {
      angka = stoi(input);
    } catch (exception e) {
      cout << "Input salah. Mohon inputkan bilangan bulat." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }

    if (angka == res) {
      cout << "Selamat tebakan anda benar. Angka yang ditebak yaitu: " << res
           << endl;
      break;
    } else {
      cout << "Coba lagi" << endl;
    }
  }
  return 0;
}