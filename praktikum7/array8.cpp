// Ambadaya Gaman - C020324001 - Elektronika 1A
// Program Array 9

#include <stdio.h>

int main() {
  int A[5];
  int i=0, X;

  printf("Input bilangan (akhiri penginputan dengan '999'): \n\n");

  while (true) {
    scanf("%i", &X);
    if (i >= 5) {
      printf("\nArray Penuh!");
      break;
    }
  }

  for (i = 0; i < 5; i++) {
    printf("Bil %i: ", (i + 1));
  }

  for (i = 0; i < 5; i += 2) {
    printf("%4i", A[i]);
  }

  return 0;
}