// Ambadaya Gaman - C020324001 - Elektronika 1A
// Jhonly Ardianto - C020324008 - Elektronika 1B

#include <stdio.h>
#define n 10

int main() {
  int A[n];
  int i, max;
  printf("Input %i bilangan:\n\n", n);
  for (int i = 0; i < n; i++) {
    printf("Bil %i: ", (i + 1));
    scanf("%i", &A[i]);
  }
  max = A[0];
  for (i = 1; i < n; i++) {
    if (A[i] > max) {
      max = A[i];
    }
  }
  printf("Nilai terbesar = %i \n", max);
  return 0;
}