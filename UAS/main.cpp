// Ambadaya Gaman - C020324001 - Elektronika 1A
// Jhonly Ardianto - C020324008 - Elektronika 1B

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

// fungsi update barang dan hapus belum ada

using namespace std;

const int MAX_BARANG = 500; // Maksimum jumlah barang
const string namaKategori[] = {"Elektronik", "Furniture",
                               "Peralatan Rumah Tangga"};
const int JUMLAH_KATEGORI =
    sizeof(namaKategori) /
    sizeof(namaKategori[0]); // Panjang Array namaKategori

// Fungsi untuk membersihkan layar / terminal
void bersihkanLayar() {
#ifdef _WIN32
  system("cls"); // Windows
#else
  system("clear"); // Linux / macOS
#endif
}

// Fungsi untuk validasi angka
int inputInteger() {
  int value;
  while (!(cin >> value)) {
    cout << "Input tidak valid. Masukkan angka: ";
    cin.clear();            // Reset status error pada cin
    cin.ignore(1000, '\n'); // Abaikan input yang salah
  }
  return value;
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
  bersihkanLayar();
  cout << "\n=========== MENU ==========\n";
  cout << "1. Tambah Data Barang\n";
  cout << "2. Tampilkan Semua Data Barang\n";
  cout << "3. Cari Barang Berdasarkan Nama\n";
  cout << "4. Hitung Total Stok Barang\n";
  cout << "5. Hitung Total Nilai Gudang\n";
  cout << "6. Keluar\n";
  cout << "Pilih Menu: ";
}

// Fungsi untuk mengubah kategori menjadi Nama
string tampilkanNamaKategori(int kategori) { return namaKategori[kategori]; }

// Fungsi untuk validasi kategori
int validasiKategori(char kategoriInput) {
  kategoriInput = toupper(kategoriInput);

  int kategoriIndex = kategoriInput - 'A';
  if (kategoriIndex >= 0 && kategoriIndex < JUMLAH_KATEGORI) {
    return kategoriIndex; // Kategori valid
  }
  return -1; // Kategori tidak valid
}

// Fungsi untuk menambahkan data barang
void tambahBarang(string namaBarang[], int stokBarang[], float hargaBarang[],
                  int kategoriBarang[], int &jumlahBarang) {
  if (jumlahBarang < MAX_BARANG) {
    cout << "Masukkan nama barang : ";
    cin.ignore();
    getline(cin, namaBarang[jumlahBarang]);

    cout << "Masukkan jumlah stok barang: ";
    stokBarang[jumlahBarang] = inputInteger();
    if (stokBarang[jumlahBarang] < 0) {
      cout << "Stok tidak boleh negatif.\n";
      return;
    }

    cout << "Masukkan harga barang (per unit): ";
    hargaBarang[jumlahBarang] = inputInteger();
    if (hargaBarang[jumlahBarang] < 0) {
      cout << "Harga barang tidak boleh negatif.\n";
      return;
    }

    char kategoriInput;
    cout << "Masukkan kategori barang (A = Elektronik, B = Furniture, C = "
            "Peralatan Rumah Tangga): ";
    cin >> kategoriInput;

    int kategoriIndex = validasiKategori(kategoriInput);
    if (kategoriIndex != -1) {
      kategoriBarang[jumlahBarang] = kategoriIndex;
      jumlahBarang++;
      cout << "Data barang berhasil ditambahkan!\n";
    } else {
      cout << "Kategori tidak valid, data barang tidak ditambahkan.\n";
    }
  } else {
    cout << "Gudang penuh, tidak dapat menambahkan barang lagi.\n";
  }
}

// Fungsi untuk menampilkan data semua barang
void tampilkanSemuaBarang(string namaBarang[], int stokBarang[],
                          float hargaBarang[], int kategoriBarang[],
                          int &jumlahBarang) {
  if (jumlahBarang == 0) {
    cout << "Belum ada data barang di gudang.\n";
  } else {
    cout << "\n======= Data Barang =======\n";
    for (int i = 0; i < jumlahBarang; i++) {
      cout << i + 1 << ". " << namaBarang[i] << " - Stok: " << stokBarang[i]
           << " - Harga: Rp. " << fixed << setprecision(2) << hargaBarang[i]
           << " - Kategori: " << tampilkanNamaKategori(kategoriBarang[i])
           << "\n";
    }
  }
}

// Fungsi untuk mencocokkan string
bool samakanString(string &a, string &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (int i = 0; i < a.size(); ++i) {
    if (tolower(a[i]) != tolower(b[i])) {
      return false;
    }
  }
  return true;
}

// Fungsi untuk mencari barang berdasarkan nama
void cariBarang(string namaBarang[], int stokBarang[], float hargaBarang[],
                int kategoriBarang[], int &jumlahBarang) {
  if (jumlahBarang == 0) {
    cout << "Belum ada data barang di gudang.\n";
  } else {
    string cariNama;
    cout << "Masukkan nama barang yang akan dicari: ";
    cin.ignore();
    getline(cin, cariNama);

    bool ditemukan = false;
    for (int i = 0; i < jumlahBarang; i++) {
      if (samakanString(namaBarang[i], cariNama)) {
        cout << "Barang ditemukan: " << namaBarang[i]
             << " - Stok: " << stokBarang[i] << " - Harga: Rp. " << fixed
             << setprecision(2) << hargaBarang[i]
             << " - Kategori: " << tampilkanNamaKategori(kategoriBarang[i])
             << "\n";
        ditemukan = true;
        break;
      }
    }
    if (!ditemukan) {
      cout << "Barang dengan nama \"" << cariNama << "\" tidak ditemukan.\n";
    }
  }
}

// Fungsi untuk menghitung total stok barang
void hitungTotalStok(int stokBarang[], int jumlahBarang) {
  if (jumlahBarang == 0) {
    cout << "Belum ada data barang di gudang.\n";
  } else {
    int totalStok = 0;
    for (int i = 0; i < jumlahBarang; i++) {
      totalStok += stokBarang[i];
    }
    cout << "Total stok semua barang: " << totalStok << "\n";
  }
}

// Fungsi untuk menghitung total nilai gudang
void hitungNilaiGudang(int stokBarang[], float hargaBarang[],
                       int jumlahBarang) {
  if (jumlahBarang == 0) {
    cout << "Belum ada data barang di gudang.\n";
  } else {
    unsigned long long totalNilai = 0;
    for (int i = 0; i < jumlahBarang; i++) {
      totalNilai += stokBarang[i] * hargaBarang[i];
    }
    cout << "Total nilai gudang: Rp. " << totalNilai << "\n";
  }
}

int main() {
  string namaBarang[MAX_BARANG];
  int stokBarang[MAX_BARANG];
  float hargaBarang[MAX_BARANG];
  int kategoriBarang[MAX_BARANG];
  int jumlahBarang = 0;
  int pilihan;

  do {
    tampilkanMenu();
    cin >> pilihan;

    if (cin.fail()) { // Validasi input yang salah
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Input tidak valid, silakan masukkan angka.\n";
      continue;
    }

    switch (pilihan) {
    case 1: // Tambah Data Barang
      tambahBarang(namaBarang, stokBarang, hargaBarang, kategoriBarang,
                   jumlahBarang);
      break;
    case 2: // Tampilkan Semua Data Barang
      tampilkanSemuaBarang(namaBarang, stokBarang, hargaBarang, kategoriBarang,
                           jumlahBarang);
      break;
    case 3: // Cari Barang Berdasarkan Nama
      cariBarang(namaBarang, stokBarang, hargaBarang, kategoriBarang,
                 jumlahBarang);
      break;
    case 4: // Hitung Total Stok Barang
      hitungTotalStok(stokBarang, jumlahBarang);
      break;
    case 5: // Hitung Total Nilai Gudang
      hitungNilaiGudang(stokBarang, hargaBarang, jumlahBarang);
      break;
    case 6: // Keluar
      cout << "Terima kasih telah menggunakan aplikasi ini.\n";
      break;
    default:
      cout << "Pilihan tidak valid, silakan coba lagi.\n";
      break;
    }
    if (pilihan != 6) {
      cout << "\nTekan Enter untuk kembali ke menu...";
      cin.ignore();
      cin.get();
    }
  } while (pilihan != 6);

  return 0;
}