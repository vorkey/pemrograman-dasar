// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <stdio.h>
#include <string.h>

int main() {
  char nim[10];  // membuat variable nim dengan tipe data char dengan panjang 10
                 // karakter
  char nama[30]; // membuat variable nama dengan tipe data char dengan panjang
                 // 30 karakter
  int nilai;     // membuat variable nilai dengan tipe data integer

  strcpy(nim, "020324001");
  strcpy(nama, "Ambadaya Gaman");
  nilai = 100;

  printf("NIM : %s \n", nim);
  printf("NAMA : %s \n", nama);
  printf("NILAI : %i \n", nilai);
  return 0;
}