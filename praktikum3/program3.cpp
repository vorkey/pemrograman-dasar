// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <stdio.h>

int main() {
  int jari;
  float luas, keliling;
  jari = 7;

  luas = 3.14 * jari * jari;
  keliling = 2 * 3.14 * jari;

  printf("LUAS dan KELILING LINGKARAN");
  printf("\nJari-jari = %i", jari);
  printf("\nLUAS = %.3f", luas);
  printf("\nKELILING = %.2f", keliling);
  printf("\n");

  return 0;
}