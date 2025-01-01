// Ambadaya Gaman - C020324001 - Elektronika 1A
// Jhonly Ardianto - C020324008 - Elektronika 1B

#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

string namaKategori[] = {"Elektronik", "Furniture", "Dekorasi"};
const int JUMLAH_KATEGORI =
    sizeof(namaKategori) /
    sizeof(namaKategori[0]); // Panjang Array namaKategori
const int BARANG_PER_HALAMAN = 10;

struct Barang {
  string nama;
  int stok;
  float harga;
  int kategori;
};

vector<Barang> gudang;

// Fungsi untuk membersihkan layar / terminal
void bersihkanLayar() {
#ifdef _WIN32
  system("cls"); // Windows
#else
  system("clear"); // Linux / macOS
#endif
}

// Fungsi untuk validasi integer & float
int inputInteger() {
  int value;
  while (!(cin >> value)) {
    cout << "Input tidak valid. Masukkan angka: ";
    cin.clear();            // Reset status error pada cin
    cin.ignore(1000, '\n'); // Abaikan input yang salah
  }
  return value;
}

// Fungsi untuk melakukan format angka ke rupiah
string formatRupiah(int angka) {
  string hasil = to_string(angka);

  string rupiah = "";
  int hitung = 0;
  for (int i = hasil.size() - 1; i >= 0; --i) {
    rupiah.insert(rupiah.begin(), hasil[i]);
    if (++hitung % 3 == 0 && i != 0) {
      rupiah.insert(rupiah.begin(), '.');
    }
  }
  return "Rp" + rupiah;
}

// Fungsi untuk menampilkan data barang dalam tabel
void tampilkanMenu(const vector<Barang> &barang, int halaman) {
  bersihkanLayar();
  int totalHalaman =
      (barang.size() + BARANG_PER_HALAMAN - 1) / BARANG_PER_HALAMAN;
  int start = (halaman - 1) * BARANG_PER_HALAMAN;
  int end = min((int)barang.size(), start + BARANG_PER_HALAMAN);

  cout << left << setw(5) << "No" << setw(30) << "Nama Barang" << setw(10)
       << "Stok" << setw(15) << "Harga" << setw(20) << "Kategori" << endl;
  cout << string(80, '=') << endl;

  for (int i = start; i < end; ++i) {
    const Barang &b = barang[i];
    string namaPendek =
        b.nama.size() > 25 ? b.nama.substr(0, 22) + "..." : b.nama;
    cout << left << setw(5) << i + 1 << setw(30) << namaPendek << setw(10)
         << b.stok << setw(15) << formatRupiah(b.harga) << setw(20)
         << namaKategori[b.kategori] << endl;
    cout << string(80, '=') << endl;
  }

  cout << "\nHalaman ke-" << halaman << " dari " << totalHalaman << " halaman"
       << endl;
  cout << setw(66) << "[p] Sebelumnya" << "Berikutnya [n]" << endl;

  cout << string(37, '=') << " MENU " << string(37, '=') << "\n"
       << "[1] Tambah Data Barang\n"
       << "[2] Update Data Barang\n"
       << "[3] Hapus Data Barang\n"
       << "[4] Cari Barang Berdasarkan Nama\n"
       << "[5] Sortir Barang\n"
       << "[6] Hitung Total Stok Barang\n"
       << "[7] Hitung Total Nilai Gudang\n"
       << "[8] Tentang aplikasi\n"
       << "[0] Keluar\n"
       << "Pilihan: ";
}

// Fungsi untuk menambahkan data barang
void tambahBarang() {
  bersihkanLayar();
  Barang b;
  cout << "Masukkan nama barang : ";
  getline(cin, b.nama);

  cout << "Masukkan stok barang: ";
  b.stok = inputInteger();
  if (b.stok < 0) {
    cout << "Stok tidak boleh negatif.\n";
    return;
  }

  cout << "Masukkan harga barang: Rp";
  b.harga = inputInteger();
  if (b.harga < 0) {
    cout << "Harga barang tidak boleh negatif.\n";
    return;
  }

  cout << "Masukkan kategori barang (0 = Elektronik, 1 = Furniture, 2 = "
          "Dekorasi): ";
  b.kategori = inputInteger();

  if (!(b.kategori >= 0 && b.kategori < JUMLAH_KATEGORI)) {
    cout << "Kategori tidak valid, data barang tidak ditambahkan.\n";
  }

  gudang.push_back(b);
  cout << "Data barang berhasil ditambahkan!\n";
}

// Fungsi untuk memperbarui data barang
void updateBarang() {
  int index;
  cout << "Masukkan nomor barang yang ingin diupdate: ";
  index = inputInteger() - 1;

  if (index >= 0 && index < gudang.size()) {
    cout << "Nama barang baru: ";
    cin.ignore();
    getline(cin, gudang[index].nama);
    cout << "Stok barang baru: ";
    gudang[index].stok = inputInteger();
    cout << "Harga barang baru: Rp";
    gudang[index].harga = inputInteger();
    cout << "Kategori barang baru (0 = Elektronik, 1 = Furniture, 2 = "
            "Dekorasi): ";
    gudang[index].kategori = inputInteger();
    cout << "Barang berhasil diperbarui. \n";
  } else {
    cout << "Nomor barang tidak valid.\n";
  }
}

// Fungsi untuk menghapus data barang
void hapusBarang() {
  int index;
  cout << "Masukkan nomor barang yang ingin dihapus: ";
  index = inputInteger() - 1;

  if (index >= 0 && index < gudang.size()) {
    gudang.erase(gudang.begin() + index);
    cout << "Barang berhasil dihapus. \n";
  } else {
    cout << "Nomor barang tidak valid. \n";
  }
}

// Fungsi untuk menyimpan data ke file CSV
void simpanKeFile(const string &filename) {
  ofstream file(filename);
  if (file.is_open()) {
    file << "Nama,Stok,Harga,Kategori\n";
    for (const auto &b : gudang) {
      file << b.nama << ',' << b.stok << ',' << b.harga << ','
           << namaKategori[b.kategori] << "\n";
    }
    file.close();
    cout << "Data berhasil disimpan ke file.\n";
  } else {
    cout << "Gagal membuka file.\n";
  }
}

// Fungsi untuk membaca data dari file CSV
void bacaDariFile(const string &filename) {
  ifstream file(filename);
  if (file.is_open()) {
    gudang.clear();
    string line;
    getline(file, line);
    while (getline(file, line)) {
      Barang b;
      size_t pos = 0;
      pos = line.find(',');
      b.nama = line.substr(0, pos);
      line.erase(0, pos + 1);

      pos = line.find(',');
      b.stok = stoi(line.substr(0, pos));
      line.erase(0, pos + 1);

      pos = line.find(',');
      b.harga = stof(line.substr(0, pos));
      line.erase(0, pos + 1);

      b.kategori = distance(namaKategori,
                            find(begin(namaKategori), end(namaKategori), line));
      gudang.push_back(b);
    }
    file.close();
    cout << "Data barang berhasil dibaca dari file.\n";
  } else {
    cout << "Gagal membuka file.\n";
  }
}

// Fungsi untuk mencocokkan string
bool samakanString(string &a, string &b) {
  if (a.size() != b.size()) {
    return false;
  }
  for (int i = 0; i < (int)a.size(); ++i) {
    if (tolower(a[i]) != tolower(b[i])) {
      return false;
    }
  }
  return true;
}

// Fungsi untuk mencari barang berdasarkan nama
void cariBarang() {
  string cariNama;
  cout << "Masukkan nama barang yang akan dicari: ";
  cin.ignore();
  getline(cin, cariNama);

  bool ditemukan = false;
  for (const auto &b : gudang) {
    if (b.nama.find(cariNama) != string::npos) {
      cout << "Barang ditemukan: " << b.nama << " - Stok: " << b.stok
           << " - Harga: " << formatRupiah(b.harga)
           << " - Kategori: " << namaKategori[b.kategori] << "\n";
      ditemukan = true;
      break;
    }
  }

  if (!ditemukan) {
    cout << "Barang dengan nama \"" << cariNama << "\" tidak ditemukan.\n";
  }
}

// Fungsi untuk mengurutkan barang
void sortirBarang() {
  bersihkanLayar();
  cout << "Sortir berdasarkan:\n"
       << "[1] Nama\n"
       << "[2] Stok\n"
       << "[3] Harga\n"
       << "Pilih: ";
  int pilihan = inputInteger();

  switch (pilihan) {
  case 1:
    sort(gudang.begin(), gudang.end(),
         [](Barang a, Barang b) { return a.nama < b.nama; });
    cout << "Barang telah disortir berdasarkan nama.\n";
    break;
  case 2:
    sort(gudang.begin(), gudang.end(),
         [](Barang a, Barang b) { return a.stok < b.stok; });
    cout << "Barang telah disortir berdasarkan stok.\n";
    break;
  case 3:
    sort(gudang.begin(), gudang.end(),
         [](Barang a, Barang b) { return a.harga < b.harga; });
    cout << "Barang telah disortir berdasarkan harga.\n";
    break;
  default:
    cout << "Pilihan tidak valid.\n";
  }
}

// Fungsi untuk menghitung total stok barang
void hitungTotalStok() {
  int totalStok = 0;
  for (const auto &b : gudang) {
    totalStok += b.stok;
  }
  cout << "Total stok semua barang: " << totalStok << "\n";
}

// Fungsi untuk menghitung total nilai gudang
void hitungNilaiGudang() {
  unsigned long long totalNilai = 0;
  for (const auto &b : gudang) {
    totalNilai += b.stok * b.harga;
  }
  cout << "Total nilai gudang: " << formatRupiah(totalNilai) << "\n";
}

int main() {
  char pilihan;
  int jumlahBarang = 0, halaman = 1;

  do {
    bacaDariFile("data_barang.csv");
    tampilkanMenu(gudang, halaman);
    cin >> pilihan;
    cin.ignore(1000, '\n');

    switch (pilihan) {
    case 'p':
      if (halaman - 1 < 1) {
        cout << "Sudah berada pada halaman pertama" << endl;
      } else {
        halaman--;
      }
      cin.get();
      break;
    case 'n':
      halaman++;
      cin.get();
      break;
    case '1':
      tambahBarang();
      simpanKeFile("data_barang.csv");
      cin.get();
      break;
    case '2':
      updateBarang();
      simpanKeFile("data_barang.csv");
      cin.get();
      break;
    case '3':
      hapusBarang();
      simpanKeFile("data_barang.csv");
      cin.get();
      break;
    case '4':
      cariBarang();
      cin.get();
      break;
    case '5':
      sortirBarang();
      cin.get();
      break;
    case '6':
      hitungTotalStok();
      cin.get();
      break;
    case '7':
      hitungNilaiGudang();
      cin.get();
      break;
    case '8':
      cout << "Aplikasi ini dibuat untuk...\n";
      cin.get();
      break;
    case '0':
      cout << "Terima kasih telah menggunakan aplikasi ini.\n";
      simpanKeFile("data_barang.csv");
      break;
    default:
      cout << "Pilihan tidak valid, silakan coba lagi.\n";
    }
  } while (pilihan != '0');

  return 0;
}