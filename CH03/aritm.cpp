#include "iostream"
#include "math.h"

using namespace std;

int main() {
  cout << "Please enter a real number" << endl;
  double n;

  cin >> n;
  cout << "This number is " << n << "." << endl
  << "\tn + 1 = " << n + 1 << endl
  << "\tn * 3 = " << n * 3 << endl
  << "\tn + n = " << n + n << endl
  << "\tn * n = " << n * n << endl
  << "\tn / 2 = " << n / 2 << endl
  << "\tsqrt(n) = " << sqrt(n) << endl;

  return 0;
}
