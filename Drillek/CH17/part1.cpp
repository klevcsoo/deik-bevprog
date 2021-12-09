#include <iostream>
#include <vector>

using namespace std;

void print_array10(ostream &os, int *a) {
  for (int i = 0; i < 10; i++) os << a[i] << endl;
}

void print_array(ostream &os, int *a, int n) {
  for (int i = 0; i < n; i++) os << a[i] << endl;
}

void print_vector(ostream &os, vector<int> &v) {
  for (int &element : v) os << element << endl;
}

int main() {
  int *arr10 = new int[10];
  print_array10(cout, arr10);
  delete[] arr10;

  int *arr11 = new int[11] {101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111};
  print_array(cout, arr11, 11);
  delete[] arr11;

  vector<int> v = {5, 6, 8};
  print_vector(cout, v);

  return 0;
}
