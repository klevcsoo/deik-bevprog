#include "iostream"

using namespace std;

int main() {
  int a = 20000;
  char c = a;
  int b = c;

  if (a != b) {
    cout << "a != b \t a = " << a << " | b = " << b << endl;
  }

  return 0;
}
