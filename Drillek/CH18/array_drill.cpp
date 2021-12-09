#include <iostream>

using namespace std;

int* ga = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(int a[], int n) {
  int la[10] = {};
  for (int i = 0; i < n; i++) {
    if (n <= 10) {
      la[i] = a[i];
    } else {
      cout << "\"Index out of range\" error prevented" << endl;
    }
  }

  for (int i = 0; i < 10; i++) cout << la[i] << " ";
  cout << endl;

  int* p = new int[n];
  for (int i = 0; i < n; i++) p[i] = a[i];
  for (int i = 0; i < n; i++) cout << p << " ";
  cout << endl;

  delete[] p;
}

int main() {
  f(ga, 10);

  int aa[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
  f(aa, 10);

  return 0;
}
