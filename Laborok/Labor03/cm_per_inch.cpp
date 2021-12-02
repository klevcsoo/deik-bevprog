#include "iostream"

using namespace std;

int main() {
  const double CM_PER_INCH = 2.54;
  double length; char unit;

  cout << "Enter a length folowed by a unit ( c / i )" << endl;
  cin >> length >> unit;

  // if (unit == 'i') {
  //   cout << length << " in = " << length * CM_PER_INCH << " cm" << endl;
  // } else if (unit == 'c') {
  //   cout << length << " cm = " << length / CM_PER_INCH << " in" << endl;
  // } else {
  //   cout << "\033[1;31mInvalid character\033[0m" << endl;
  // }

  switch (unit) {
    case 'i': {
      cout << length << " in = " << length * CM_PER_INCH << " cm" << endl;
      break;
    } case 'c': {
      cout << length << " cm = " << length / CM_PER_INCH << " in" << endl;
      break;
    } default: {
      cout << "\033[1;31mInvalid character\033[0m" << endl;
      break;
    }
  }
  
  return 0;
}
