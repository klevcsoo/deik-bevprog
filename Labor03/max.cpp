#include "iostream"

using namespace std;

int main() {
  int a; int b;
  cout << "Enter two integer values" << endl;
  cin >> a >> b;

  if (a > b) {
    cout << "Max(" << a << ", " << b << ") is " << a << endl;
  } else {
    cout << "Max(" << a << ", " << b << ") is " << b << endl;
  }
  
  return 0;
}
