// Ambadaya Gaman - C020324001 - Elektronika 1A
// Program Array 4

#include <stdio.h>

int main() {
  int A[6] = {7, 3, 9, 15, 12, 17};
  //    ^ Error karena jumlah elemen lebih dari 5
  //    untuk diperbaiki diganti dengan 6
  int i;
  for (i = 0; i < 6; i++) {
    printf("%4i", A[i]);
  }
  return 0;
}