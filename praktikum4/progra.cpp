// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <iostream>
#include <string>

// If 1 kondisi, if else 2 kondisi
// percabangan (decision) flowchart belah ketupat, jajar genjang untuk perintah,
// switch case tidak pakai flowchart?

using namespace std;

int main() {
  string password;
  cout << "" << endl;

  cin >> password;
  if (password == "yay") {
    cout << "Selamat datang di aplikasi kami" << endl;
  }
  cout << "Terimakasih telah menggunakan aplikasi kami!" << endl;
  return 0;
}