#include <iostream>
#include <vector>

using namespace std;

void print_array(ostream& os, int* a, int n) {
  os << "The memory address " << a << " has the value { ";
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  os << "}." << endl;
}

int main() {
  int x = 7;
  int* p1 = &x;
  cout << "The memory address " << p1 << " has the value " << *p1 << "." << endl;

  int* p2 = new int[7] {1, 2, 4, 8, 16, 32, 64};
  print_array(cout, p2, 7);

  int* p3 = p2;
  p2 = p1;
  p2 = p3;
  cout << "The memory address " << p1 << " has the value " << *p1 << "." << endl;
  print_array(cout, p2, 7);
  delete[] p2;

  p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  p2 = new int[10];
  for (int i = 0; i < 10; i++) p2[i] = p1[i];
  print_array(cout, p2, 10);

  vector<int> v1 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
  vector<int> v2; v2 = v1;
  for (int element : v2) cout << element << endl;

  return 0;
}
