// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <stdio.h>

int main() {
  char nim[10];  // membuat variable nim dengan tipe data char dengan panjang 10
                 // karakter
  char nama[30]; // membuat variable nama dengan tipe data char dengan panjang
                 // 30 karakter
  int nilai;     // membuat variable nilai dengan tipe data integer

  nim = "020324001";
  nama = "Ambadaya Gaman";
  nilai = 100;

  printf("NIM : %s \n", nim);
  printf("NAMA : %s \n", nama);
  printf("NILAI : %i \n", nilai);
  return 0;
}

/*
Error terjadi di line nomor 12 dan 13 karena tipe data char adalah 1
karakter, char[30] artinya array of char dengan 30 elemen, tetapi jika
melakukan assingment nilai dengan cara seperti ini tidak diperbolehkan karena
panjang nama dan nim yang diberikan lebih dari 1 karakter yaitu "Ambadaya
Gaman", dan "020324001"

jika misalkan ditulis nim = 'c' maka tidak akan terjadi error karena panjang
nim hanya 1 karakter
*/