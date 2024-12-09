// Ambadaya Gaman - C020324001 - Elektronika 1A
// Program Array 9

#include <stdio.h>

int main() {
  int A[5] = {0, 0, 0, 0, 0};
  int i = 0, X;

  printf("Input bilangan (akhiri penginputan dengan '999'): \n\n");

  while (true) {
    scanf("%i", &X);
    if (i >= 5) {
      printf("\nArray Penuh!");
      break;
    }
    if (X == 999) {
      printf("\nProgram Berakhir!");
      break;
    }
    if (X % 2 == 1) {
      A[i] = X;
      i++;
    }
  }

  for (i = 0; i < 5; i++) {
    printf("%4i", A[i]);
  }
  return 0;
}