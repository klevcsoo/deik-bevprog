#include "iostream"

using namespace std;

int main() {
  const double CM_PER_INCH = 2.54;
  double length = 1;

  while (length != 0) {
    cout << "Please enter a distance in inches" << endl;
    cin >> length;
    cout << "Length in centimeters: " << length * CM_PER_INCH << endl;
  }

  return 0;
}
