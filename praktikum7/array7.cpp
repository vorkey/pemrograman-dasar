// Ambadaya Gaman - C020324001 - Elektronika 1A
// Program Array 7

#include <stdio.h>

int main() {
  int A[5];
  int i;

  printf("Input 5 bilangan: \n\n");

  for (i = 0; i < 5; i++) {
    printf("Bil %i: ", (i + 1));
    scanf("%i", &A[i]);
  }

  for (i = 0; i < 5; i++) {
    printf("%4i", A[i]);
  }

  return 0;
}