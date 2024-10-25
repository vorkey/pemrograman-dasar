// Ambadaya Gaman - C020324001 - Elektronika 1A
// Rizlan Riyadi - C020324017 - Elektronika 1A

#include <cctype>
#include <exception>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  int tahun;

  cout << endl << "======Program Menghitung Tahun Kabisat======" << endl;
  cout << "----inputkan x untuk keluar dari program----" << endl << endl;
  while (true) {
    cout << "Inputkan Tahun:";
    cin >> input;

    if (input == "x" || input == "X") {
      break;
    }

    try {
      tahun = stoi(input);
    } catch (exception e) {
      cout << "Input salah. Mohon inputkan bilangan bulat sebagai tahun yang "
              "akan dihitung."
           << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }

    if ((tahun % 4 == 0 && tahun % 100 != 0) || tahun % 400 == 0) {
      cout << "Tahun " << tahun << " adalah tahun kabisat." << endl;
    } else {
      cout << "Tahun " << tahun << " bukan tahun kabisat." << endl;
    }
  }

  return 0;
}