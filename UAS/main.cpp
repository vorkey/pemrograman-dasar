// Ambadaya Gaman - C020324001 - Elektronika 1A
// Jhonly Ardianto - C020324008 - Elektronika 1B

#include <algorithm>
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
int halamanAkhir;
const string FILENAME = "data_barang.csv";

// Struktur data tiap barang
struct Barang {
  string nama;
  int stok;
  int harga;
  unsigned int kategori;
};

// Struktur data untuk menyimpan data barang
vector<Barang> gudang;

// Fungsi untuk membersihkan layar / terminal
void bersihkanLayar() {
#ifdef _WIN32
  system("cls"); // Windows
#else
  system("clear"); // Linux / macOS
#endif
}

// Fungsi untuk validasi integer
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
  halamanAkhir = totalHalaman;

  cout << left << setw(5) << "No" << setw(30) << "Nama Barang" << setw(10)
       << "Stok" << setw(15) << "Harga" << setw(20) << "Kategori" << endl;
  cout << string(80, '=') << endl;

  for (int i = start; i < end; ++i) {
    const Barang &b = barang[i];
    string namaPendek =
        b.nama.size() > 30 ? b.nama.substr(0, 27) + "..." : b.nama;
    cout << setw(5) << i + 1 << left << setw(30) << namaPendek << setw(10)
         << b.stok << setw(15) << formatRupiah(b.harga) << setw(20)
         << namaKategori[b.kategori] << endl;
    cout << string(80, '=') << endl;
  }

  cout << "\nHalaman ke-" << halaman << " dari " << totalHalaman << " halaman"
       << endl;
  cout << setw(66) << "[p] Sebelumnya" << "Berikutnya [n]" << endl;

  cout << right << setw(46) << " MENU UTAMA " << endl
       << "[1] Tambah Data Barang\n"
       << "[2] Update Data Barang\n"
       << "[3] Hapus Data Barang\n"
       << "[4] Cari Barang Berdasarkan Nama\n"
       << "[5] Sortir Barang\n"
       << "[6] Hitung Total Stok Barang\n"
       << "[7] Hitung Total Nilai Gudang\n"
       << "[8] Tentang aplikasi\n"
       << "[0] Keluar\n"
       << "(Tekan Ctrl + C untuk keluar program tanpa menyimpan data)\n"
       << "Pilihan: ";
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
    cout << "Data berhasil disimpan.\n";
  } else {
    cout << "Gagal membuka file.\n";
  }
}

// Fungsi untuk menambahkan data barang
void tambahBarang() {
  Barang b;
  cout << "Masukkan nama barang : ";
  getline(cin, b.nama);

  cout << "Masukkan stok barang: ";
  b.stok = inputInteger();
  if (b.stok < 0) {
    cout << "Stok tidak boleh negatif.\n";
    cin.get();
    return;
  }

  cout << "Masukkan harga barang: Rp";
  b.harga = inputInteger();
  if (b.harga < 0) {
    cout << "Harga barang tidak boleh negatif.\n";
    cin.get();
    return;
  }

  cout << "Masukkan kategori barang (0 = Elektronik, 1 = Furniture, 2 = "
          "Dekorasi): ";
  b.kategori = inputInteger();

  if (!(b.kategori < JUMLAH_KATEGORI)) {
    cout << "Kategori tidak valid, data barang tidak ditambahkan.\n";
    cin.get();
    return;
  }

  gudang.push_back(b);
  cout << "Data barang berhasil ditambahkan!\n";
  cin.get();
  simpanKeFile(FILENAME);
}

// Fungsi untuk memperbarui data barang
void updateBarang() {
  unsigned int index;
  cout << "Masukkan nomor barang yang ingin diupdate: ";
  index = inputInteger() - 1;

  if (index < gudang.size()) {
    cout << "Nama barang baru: ";
    cin.ignore();
    getline(cin, gudang[index].nama);

    cout << "Stok barang baru: ";
    gudang[index].stok = inputInteger();
    if (gudang[index].stok < 0) {
      cout << "Stok barang tidak boleh negatif.\n";
      cin.get();
      return;
    }

    cout << "Harga barang baru: Rp";
    gudang[index].harga = inputInteger();
    if (gudang[index].harga < 0) {
      cout << "Harga barang tidak boleh negatif.\n";
      cin.get();
      return;
    }

    cout << "Kategori barang baru (0 = Elektronik, 1 = Furniture, 2 = "
            "Dekorasi): ";
    gudang[index].kategori = inputInteger();
    if (!(gudang[index].kategori < JUMLAH_KATEGORI)) {
      cout << "Kategori tidak valid, data barang tidak diperbarui.\n";
      cin.get();
      return;
    }

    cout << "Barang berhasil diperbarui. \n";
    simpanKeFile(FILENAME);
    cin.get();
  } else {
    cout << "Nomor barang tidak valid.\n";
    cin.get();
  }
}

// Fungsi untuk menghapus data barang
void hapusBarang() {
  unsigned int index;
  cout << "Masukkan nomor barang yang ingin dihapus: ";
  index = inputInteger() - 1;

  if (index < gudang.size()) {
    gudang.erase(gudang.begin() + index);
    cout << "Barang berhasil dihapus. \n";
    simpanKeFile(FILENAME);
    cin.get();
  } else {
    cout << "Nomor barang tidak valid. \n";
    cin.get()
  }
}

// Fungsi untuk membuat file data baru jika file tidak ada
void buatFileJikaTidakAda(const string &filename) {
  ifstream checkFile(filename);
  if (!checkFile.good()) { // Jika file kosong atau baru dibuat
    ofstream file(filename);
    if (file.is_open()) {
      file << "Nama,Stok,Harga,Kategori\n"; // Header default
      cout << "File \"" << filename
           << "\" tidak ditemukan. File baru telah dibuat.\n";
      cin.get();
    }
    file.close();
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
      unsigned long pos = 0;
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
  } else {
    cout << "Gagal membuka file.\n";
  }
}

// Fungsi untuk membuat semua karakter dalam string menjadi huruf kecil
string lowercase(string input) {
  for (char &c : input) {
    c = tolower(c);
  }
  return input;
}

// Fungsi untuk mencari barang berdasarkan nama
void cariBarang() {
  string cariNama;
  cout << "Masukkan nama barang yang ingin dicari: ";
  getline(cin, cariNama);

  bool ditemukan = false;
  for (const auto &b : gudang) {
    if (lowercase(b.nama).find(lowercase(cariNama)) != string::npos) {
      cout << "Barang ditemukan: " << b.nama << " - Stok: " << b.stok
           << " - Harga: " << formatRupiah(b.harga)
           << " - Kategori: " << namaKategori[b.kategori] << "\n";
      ditemukan = true;
    }
  }

  if (!ditemukan) {
    cout << "Barang dengan nama \"" << cariNama << "\" tidak ditemukan.\n";
  }
}

// Fungsi untuk mengurutkan barang
void sortirBarang() {
  cout << "Sortir barang berdasarkan:\n"
       << "[1] Nama (a - z)\n"
       << "[2] Nama (z - a)\n"
       << "[3] Stok paling sedikit\n"
       << "[4] Stok paling banyak\n"
       << "[5] Harga termurah\n"
       << "[6] Harga termahal\n"
       << "Pilih: ";
  int pilihan = inputInteger();

  switch (pilihan) {
  case 1:
    sort(gudang.begin(), gudang.end(), [](Barang a, Barang b) {
      return lowercase(a.nama) < lowercase(b.nama);
    });
    cout << "Barang telah disortir berdasarkan nama sesuai abjad.\n";
    break;
  case 2:
    sort(gudang.begin(), gudang.end(), [](Barang a, Barang b) {
      return lowercase(a.nama) > lowercase(b.nama);
    });
    cout << "Barang telah disortir berdasarkan nama sesuai abjad dari "
            "belakang.\n";
    break;
  case 3:
    sort(gudang.begin(), gudang.end(),
         [](Barang a, Barang b) { return a.stok < b.stok; });
    cout << "Barang telah disortir berdasarkan stok paling sedikit.\n";
    break;
  case 4:
    sort(gudang.begin(), gudang.end(),
         [](Barang a, Barang b) { return a.stok > b.stok; });
    cout << "Barang telah disortir berdasarkan stok paling banyak.\n";
    break;
  case 5:
    sort(gudang.begin(), gudang.end(),
         [](Barang a, Barang b) { return a.harga < b.harga; });
    cout << "Barang telah disortir berdasarkan harga termurah.\n";
    break;
  case 6:
    sort(gudang.begin(), gudang.end(),
         [](Barang a, Barang b) { return a.harga > b.harga; });
    cout << "Barang telah disortir berdasarkan harga termahal.\n";
    break;
  default:
    cout << "Pilihan tidak valid.\n";
  }
  simpanKeFile(FILENAME);
  cin.get();
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
  int halaman = 1;
  buatFileJikaTidakAda(FILENAME);

  do {
    bacaDariFile(FILENAME);
    tampilkanMenu(gudang, halaman);
    cin >> pilihan;
    cin.ignore(1000, '\n');

    switch (pilihan) {
    case 'p':
      if (halaman - 1 < 1) {
        cout << "Sudah berada pada halaman pertama" << endl;
        cin.get();
      } else {
        halaman--;
      }
      break;
    case 'n':
      if (halaman + 1 > halamanAkhir) {
        cout << "Sudah berada pada halaman terakhir" << endl;
        cin.get();
      } else {
        halaman++;
      }
      break;
    case '1':
      tambahBarang();
      cin.get();
      break;
    case '2':
      updateBarang();
      cin.get();
      break;
    case '3':
      hapusBarang();
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
      bersihkanLayar();
      cout << right << setw(48) << "TENTANG APLIKASI" << endl
           << "\n"
           << "    Aplikasi ini berfungsi sebagai sistem pengelolaan data "
              "barang dalam suatu"
           << endl
           << "gudang, data yang bisa disimpan mencakup nama barang, stok "
              "barang, harga"
           << endl
           << "barang, serta kategori barang, tema yang diambil yaitu toko "
              "yang menjual"
           << endl
           << "barang-barang perabotan rumah tangga contohnya sofa, TV, serta "
              "dekorasi"
           << endl
           << "misalnya wallpaper dinding atau lukisan, ya intinya toko "
              "perabotan seperti itu."
           << endl
           << "\n"
           << "    Aplikasi ini dibuat sebagai salah satu syarat dalam Ujian "
              "Akhir Semester 1"
           << endl
           << "mata kuliah Pemrograman Dasar pada program studi D3 "
              "Elektronika di Politeknik"
           << endl
           << "Negeri Banjarmasin tahun akademik 2024-2025.\n"
           << endl;

      cout << "Anggota Kelompok (Nama - NIM):" << endl
           << "    - Ambadaya Gaman - C020324001" << endl
           << "    - Jhonly Ardianto - C020324008" << endl;
      cin.get();
      break;
    case '0':
      cout << "Terima kasih telah menggunakan aplikasi ini.\n";
      simpanKeFile(FILENAME);
      break;
    default:
      cout << "Pilihan tidak valid, silakan coba lagi.\n";
      cin.get();
    }
  } while (pilihan != '0');

  return 0;
}
