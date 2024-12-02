// Ambadaya Gaman - C020324001 - Elektronika 1A
// Program Array 6

#include <stdio.h>

int main() {
  int A[5];
  int i;
  A[0] = 7;
  A[1] = 3;
  A[2] = 9;
  A[3] = 15;
  A[4] = 12;
  for (i = 0; i < 5; i++) {
    printf("%4i", A[i]);
  }
  return 0;
}