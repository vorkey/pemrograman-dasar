// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <iostream>
using namespace std;

int main() {
  cout << "=== Ambadaya Gaman - Praktikum 4 Percabangan ===" << endl;
  unsigned int total_belanja;

  cout << "Masukkan total belanja: ";
  cin >> total_belanja;

  // Menggunakan percabangan if
  if (total_belanja > 10000) {
    cout << "Selamat anda mendapatkan hadiah!" << endl;
  }

  cout << "Terima kasih telah berbelanja di toko kami!" << endl;
  return 0;
}