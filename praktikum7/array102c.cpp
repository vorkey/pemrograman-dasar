// Ambadaya Gaman - C020324001 - Elektronika 1A
// Jhonly Ardianto - C020324008 - Elektronika 1B

#include <stdio.h>
#define n 10

int main() {
  int A[n];
  int i, total;
  double ratarata;
  printf("Input %i bilangan:\n\n", n);
  for (int i = 0; i < n; i++) {
    printf("Bil %i: ", (i + 1));
    scanf("%i", &A[i]);
  }
  total = 0;
  for (i = 0; i < n; i++) {
    total += A[i];
  }
  ratarata = total / 10.0;
  printf("Rata-rata = %.2f \n", ratarata);
  return 0;
}