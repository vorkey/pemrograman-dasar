// Ambadaya Gaman - C020324001 - Elektronika 1A
// Rizlan Riyadi - C020324017 - Elektronika 1A

#include <iostream>

using namespace std;

int main() {
  string input;
  int ukuran;

  cout << endl << "====== Program Menggambar Persegi ======" << endl;

  cout << "Ukuran persegi yang akan digambar: ";
  cin >> input;

  try {
    ukuran = stoi(input);
  } catch (exception e) {
    cout << "Ukuran salah. Mohon berikan bilangan bulat" << endl;
    return 0;
  }

  cout << endl;

  for (int i = 0; i < ukuran; i++) {
    for (int j = 0; j < ukuran; j++) {
      cout << " * ";
    }
    cout << endl;
  }
  return 0;
}