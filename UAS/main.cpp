// Ambadaya Gaman - C020324001 - Elektronika 1A
// Jhonly Ardianto - C020324008 - Elektronika 1B

#include <iostream>
#include <string>
using namespace std;

const int MAX_BARANG = 50; // Maksimum jumlah barang

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
  cout << "\n=========== MENU ==========\n";
  cout << "1. Tambah Data Barang\n";
  cout << "2. Tampilkan Semua Data Barang\n";
  cout << "3. Cari Barang Berdasarkan Nama\n";
  cout << "4. Hitung Total Stok Barang\n";
  cout << "5. Hitung Total Nilai Gudang\n";
  cout << "6. Keluar\n";
  cout << "Pilih Menu: \n";
}

int main() {
  string namaBarang[MAX_BARANG];
  int stokBarang[MAX_BARANG];
  float hargaBarang[MAX_BARANG];
  char kategoriBarang[MAX_BARANG]; // Kategori: A = Elektronik, B = Furniture, C
                                   // = Alat Tulis
  int jumlahBarang = 0;
  int pilihan;

  do {
    tampilkanMenu();
    cin >> pilihan;
    switch (pilihan) {
    case 1: // Tambah Data Barang
      if (jumlahBarang < MAX_BARANG) {
        cout << "Masukkan nama barang : ";
        cin.ignore();
        getline(cin, namaBarang[jumlahBarang]);
        cout << "Masukkan jumlah stok barang: ";
        cin >> stokBarang[jumlahBarang];
        cout << "Masukkan harga barang (per unit): ";
        cin >> hargaBarang[jumlahBarang];
        cout << "Masukkan kategori barang (A = Elektronik, B = Furniture, C = "
                "Alat Tulis): ";
        cin >> kategoriBarang[jumlahBarang];
        jumlahBarang++;
        cout << "Data barang berhasil ditambahkan!\n";
      } else {
        cout << "Gudang penuh, tidak dapat menambahkan barang lagi.\n";
      }
      break;
    case 2: // Tampilkan Semua Data Barang
      if (jumlahBarang == 0) {
        cout << "Belum ada data barang di gudang.\n";
      } else {
        cout << "\n=== Data Barang ===\n";
        for (int i = 0; i < jumlahBarang; i++) {
          cout << i + 1 << ". " << namaBarang[i]
               << " - Stok: " << stokBarang[i];
        }
      }
    }
  } while ();

  return 0;
}