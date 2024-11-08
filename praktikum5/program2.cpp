// Ambadaya Gaman - C020324001 - Elektronika 1A
// Rizlan Riyadi - C020324017 - Elektronika 1A

#include <cmath>
#include <exception>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string input;
  double berat, tinggi, bmi;

  cout << endl
       << "=======Program Menghitung BMI/IMT(Indeks Massa Tubuh)======="
       << endl;

  cout << "Inputkan berat badan anda dalam kilogram (contoh: 49.5): ";
  cin >> input;

  try {
    berat = stod(input);
  } catch (exception) {
    cout << "Input salah. Mohon inputkan bilangan bulat/pecahan saja." << endl;
    return 0;
  }
  cin.clear();
  cin.ignore(1000, '\n');

  cout << "Inputkan tinggi badan anda dalam sentimeter (contoh: 158.5): ";
  cin >> input;

  try {
    tinggi = stod(input);
  } catch (exception) {
    cout << "Input salah. Mohon inputkan bilangan bulat/pecahan saja." << endl;
    return 0;
  }

  bmi = berat / pow(tinggi / 100, 2);
  cout << "BMI/IMT anda adalah: " << bmi << endl;

  if (bmi >= 30) {
    cout << "Anda obesitas" << endl;
  } else if (bmi >= 23 && bmi < 30) {
    cout << "Berat badan anda berlebih (overweight)." << endl;
  } else if (bmi >= 18.5 && bmi < 23) {
    cout << "Berat badan anda normal/ideal" << endl;
  } else {
    cout << "Berat badan anda kurang (underweight)." << endl;
  }
  return 0;
}