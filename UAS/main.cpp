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

// fungsi update barang dan hapus belum ada

using namespace std;

const int MAX_BARANG = 500; // Maksimum jumlah barang
const string namaKategori[] = {"Elektronik", "Furniture",
                               "Peralatan Rumah Tangga"};
const int JUMLAH_KATEGORI =
    sizeof(namaKategori) /
    sizeof(namaKategori[0]); // Panjang Array namaKategori
const int BARANG_PER_HALAMAN = 10;

struct Barang {
  int id;
  string nama;
  int stok;
  float harga;
  int kategori;
  string tanggal;
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
void tampilkanTabel(const vector<Barang> &barang, int halaman) {
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

  cout << "\nHalaman " << halaman << " dari " << totalHalaman << endl;
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
  bersihkanLayar();
  cout << "\n"
       << string(37, '=') << " MENU " << string(37, '=') << "\n"
       << "1. Tambah Data Barang\n"
       << "2. Tampilkan Semua Data Barang\n"
       << "3. Cari Barang Berdasarkan Nama\n"
       << "4. Hitung Total Stok Barang\n"
       << "5. Hitung Total Nilai Gudang\n"
       << "7. Keluar\n"
       << "Pilih Menu: ";
}

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
void tambahBarang() {
  Barang b;
  cin.ignore();
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
          "Peralatan Rumah Tangga): ";
  b.kategori = inputInteger();

  if (b.kategori >= 0 && b.kategori < JUMLAH_KATEGORI) {
    gudang.push_back(b);
    cout << "Data barang berhasil ditambahkan!\n";
  } else {
    cout << "Kategori tidak valid, data barang tidak ditambahkan.\n";
  }
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
            "Peralatan Rumah Tangga): ";
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
             << " - Stok: " << stokBarang[i]
             << " - Harga: " << formatRupiah(hargaBarang[i])
             << " - Kategori: " << namaKategori[kategoriBarang[i]] << "\n";
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
    cout << "Total nilai gudang: " << formatRupiah(totalNilai) << "\n";
  }
}

int main() {
  int pilihan, jumlahBarang = 0, halaman = 1;

  do {
    tampilkanMenu();
    pilihan = inputInteger();

    if (cin.fail()) { // Validasi input yang salah
      cin.clear();
      cin.ignore(1000, '\n');
      cout << "Input tidak valid, silakan masukkan angka.\n";
      continue;
    }

    switch (pilihan) {
    case 1: // Tambah Data Barang
      tambahBarang();
      break;
    case 2: // Tampilkan Semua Data Barang
      tampilkanTabel(gudang, halaman);
      cout << "Pindah halaman (0: kembali): ";
      halaman = inputInteger();
      if (halaman < 1 ||
          halaman > (int)(gudang.size() + BARANG_PER_HALAMAN - 1) /
                        BARANG_PER_HALAMAN) {
        halaman = 1;
      }
      break;
    case 3: // Cari Barang Berdasarkan Nama
      // cariBarang(namaBarang, stokBarang, hargaBarang, kategoriBarang,
      //            jumlahBarang);
      updateBarang();
      break;
    case 4: // Hitung Total Stok Barang
      // hitungTotalStok(stokBarang, jumlahBarang);
      hapusBarang();
      break;
    case 5: // Hitung Total Nilai Gudang
      // hitungNilaiGudang(stokBarang, hargaBarang, jumlahBarang);
      simpanKeFile("data_barang.csv");
      break;
    case 6: // Keluar
      // cout << "Terima kasih telah menggunakan aplikasi ini.\n";
      bacaDariFile("data_barang.csv");
      break;
    case 7:
      cout << "Keluar dari program.\n";
      break;
    default:
      cout << "Pilihan tidak valid, silakan coba lagi.\n";
    }
    if (pilihan != 7) {
      cout << "\nTekan Enter untuk kembali ke menu...";
      cin.ignore();
      cin.get();
    }
  } while (pilihan != 7);

  return 0;
}