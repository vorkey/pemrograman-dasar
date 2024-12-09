// Ambadaya Gaman - C020324001 - Elektronika 1A

#include <iostream>

using namespace std;

int main() {
  int Mat_A[3][4] = {{3, 1, 6, 8}, {5, 2, 3, 4}, {6, 1, 2, 4}};
  int i, j;

  // Mencetak Elemen Matriks
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++)
      cout << Mat_A[i][j] << " ";
    cout << endl;
  }
  return 0;
}