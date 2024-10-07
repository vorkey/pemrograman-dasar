// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <stdio.h>
#include <string.h>

int main() {
  char nim[10];
  char nama[30];
  int kehadiran, tugas, uts, uas;
  float nilai_akhir;

  strcpy(nim, "020324001");
  strcpy(nama, "Ambadaya Gaman");
  kehadiran = 10; // nilai kehadiran
  tugas = 100;    // nilai tugas
  uts = 80;       // nilai uts
  uas = 80;       // nilai uas

  /*
  Perhitungan nilai akhir sesuai peraturan di UBL
  */
  nilai_akhir = (0.1 * kehadiran) + (0.2 * tugas) + (0.3 * uts) + (0.4 * uas);

  // tampilkan data
  printf("NIM \t \t: %s", nim);
  printf("\nNAMA \t \t: %s", nama);
  printf("\nKEHADIRAN \t: %i", kehadiran);
  printf("\nTUGAS \t \t: %i", tugas);
  printf("\nUTS \t \t: %i", uts);
  printf("\nUAS \t \t: %i", uas);
  printf("\nNILAI AKHIR \t: %.2f \n", nilai_akhir);

  return 0;
}