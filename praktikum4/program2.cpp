// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <iostream>
using namespace std;

int main() {
  string password;

  cout << "======== Login ========" << endl;
  cout << "Masukkan password: ";
  cin >> password;

  // Percabangan if/else
  if (password == "pass") {
    cout << "Selamat datang di aplikasi kami!" << endl;
  } else {
    cout << "Password salah, coba lagi!" << endl;
  }

  cout << "Terimakasih telah menggunakan aplikasi kami!" << endl;
  return 0;
}